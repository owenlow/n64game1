#include <libdragon.h>
#include <GL/gl.h>
#include <GL/glu.h>
#include <GL/gl_integration.h>

#include "objects/cube.h"
#include "input.h"
#include "game/camera.h"
#include "game/player.h"
#include "game/scene.h"
#include "game/object.h"

// TODO: didn't fix the "looping" color problem
GLfloat clamp_color(GLfloat value)
{
    if (value < 0.0f)
        return 0.0f;
    if (value > 1.0f)
        return 1.0f;
    return value;
}

int main(void)
{
    uint32_t frame_count = 0;
    Camera camera = {
        .position = {{0, -10, 0}},
        .pitch = 0,
        .yaw = 0};

    Player player = {
        .position = {{0, -10, 0}}};

    Scene scene;
    scene_init(&scene);

    // Initialise the various systems
    display_init(RESOLUTION_640x480, DEPTH_16_BPP, 3, GAMMA_NONE, FILTERS_DISABLED);
    rdpq_init();
    gl_init();
    joypad_init();
    console_init();

    // Setup
    float aspect_ratio = (float)display_get_width() / (float)display_get_height(); // 4/3
    float near_plane = 1.0f;
    float far_plane = 50.0f;
    // camera.position = {}

    // Set the viewing area
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glFrustum(
        -near_plane * aspect_ratio, // -1.33
        near_plane * aspect_ratio,  //
        -near_plane,
        near_plane,
        near_plane,
        far_plane);

    GLfloat r = 0.0f;
    GLfloat g = 0.0f;
    GLfloat b = 0.0f;

    Object *cube = init_cube(r, g, b);
    scene_add_object(&scene, cube);

    // glRotatef
    uint64_t last = timer_ticks();

    // while (running)
    // {
    //     input_update();

    //     game_update(dt);

    //     renderer_begin_frame();

    //     renderer_render_scene(&game.scene);

    //     renderer_end_frame();
    // }
    // Main loop
    while (1)
    {
        uint64_t now = timer_ticks();

        if (now - last < TICKS_PER_SECOND / 60)
            continue;

        last = now;
        // vi_wait_vblank();
        // printf("hello!\n");
        joypad_poll();
        handleInput(&camera, &player);
        joypad_buttons_t buttons = joypad_get_buttons(JOYPAD_PORT_1);
        if (buttons.a)
        {
            if (buttons.z)
                b -= 0.01f;

            else
                b += 0.01f;
        }
        if (buttons.b)
        {
            if (buttons.z)
                g -= 0.01f;

            else
                g += 0.01f;
        }
        if (buttons.start)
        {
            if (buttons.z)
                r -= 0.01f;

            else
                r += 0.01f;
        }
        clamp_color(r);
        clamp_color(g);
        clamp_color(b);

        // int x = joypad_get_axis_held(JOYPAD_PORT_1, JOYPAD_AXIS_STICK_X);
        // int y = joypad_get_axis_held(JOYPAD_PORT_1, JOYPAD_AXIS_STICK_Y);
        // if (y)
        // {
        //     gluLookAt()
        // }

        // Start a new frame
        // Get the frame buffer and z-buffer
        surface_t *disp = display_get();
        surface_t *zbuf = display_get_zbuf();
        // Attach the buffers to the RDP
        rdpq_attach_clear(disp, zbuf);

        // Fill the background with white
        rdpq_set_mode_fill(RGBA32(0xFF, 0xFF, 0xFF, 0));
        rdpq_fill_rectangle(0, 0, display_get_width(), display_get_height());

        // Begin OpenGL compatibility with the RDP
        gl_context_begin();

        fm_vec3_t pos = camera.position;
        fm_vec3_t center = calculateCenter(&camera);
        fm_vec3_t up = {{0.0f, 0.0f, 1.0f}};

        glMatrixMode(GL_MODELVIEW);
        glLoadIdentity();

        gluLookAt(
            pos.x, pos.y, pos.z,
            center.x, center.y, center.z,
            up.x, up.y, up.z);

        // Render a triangle with OpenGL using the function above
        scene_render(&scene);
        // render_cube(&camera, &player, r, g, b);

        // Does nothing for now, but keep it in case
        gl_context_end();

        // Send frame buffer to display (TV)
        rdpq_detach_show();
        frame_count++;
    }
}