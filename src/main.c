#include <libdragon.h>
#include <GL/gl.h>
#include <GL/glu.h>
#include <GL/gl_integration.h>

void render_triangle(GLfloat r, GLfloat g, GLfloat b)
{
    // Begin OpenGL compatibility with the RDP
    gl_context_begin();

    // Set the camera's position
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    gluLookAt(
        0, -10.0, 0.0,
        0, 0, 0,
        0, 0, 1);

    // Draw the triangle
    glBegin(GL_TRIANGLES);
    glColor3f(r, g, b); // Red color
    glVertex3f(-1.0f, -1.0f, -1.0f);
    glVertex3f(-1.0f, -1.0f, 1.0f);
    glVertex3f(1.0f, -1.0f, 1.0f);
    glEnd();

    // Does nothing for now, but keep it in case
    gl_context_end();
}

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
    // Initialise the various systems
    display_init(RESOLUTION_640x480, DEPTH_16_BPP, 3, GAMMA_NONE, FILTERS_DISABLED);
    rdpq_init();
    gl_init();
    joypad_init();

    // Setup
    float aspect_ratio = (float)display_get_width() / (float)display_get_height();
    float near_plane = 1.0f;
    float far_plane = 50.0f;

    // Set the viewing area
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glFrustum(
        -near_plane * aspect_ratio,
        near_plane * aspect_ratio,
        -near_plane,
        near_plane,
        near_plane,
        far_plane);

    GLfloat r = 0.0f;
    GLfloat g = 0.0f;
    GLfloat b = 0.0f;

    // Main loop
    while (1)
    {

        joypad_poll();
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

        // Start a new frame
        // Get the frame buffer and z-buffer
        surface_t *disp = display_get();
        surface_t *zbuf = display_get_zbuf();
        // Attach the buffers to the RDP
        rdpq_attach_clear(disp, zbuf);

        // Fill the background with white
        rdpq_set_mode_fill(RGBA32(0xFF, 0xFF, 0xFF, 0));
        rdpq_fill_rectangle(0, 0, display_get_width(), display_get_height());

        // Render a triangle with OpenGL using the function above
        render_triangle(r, g, b);

        // Send frame buffer to display (TV)
        rdpq_detach_show();
    }
}