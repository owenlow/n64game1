#include <libdragon.h>
#include <stdio.h>

int main(void)
{
    /* Initialize peripherals */
    display_init(RESOLUTION_320x240, DEPTH_32_BPP, 2, GAMMA_NONE, FILTERS_RESAMPLE);

    console_init();
    console_set_render_mode(RENDER_MANUAL);
    joypad_init();

    /* USB debug output (works great with the SC64's USB debug bridge) */
    debug_init_isviewer();
    debug_init_usblog();
    debugf("Hello from the N64 over USB!\n");

    int frame = 0;

    while (1)
    {
        console_clear();

        printf("Hello, World!\n");
        printf("Running on libdragon + SC64\n");
        printf("\n");
        printf("Frame: %d\n", frame++);

        console_render();
        /* Grab the next back-buffer */
        // surface_t *disp = display_get();

        // /* Clear to a dark blue */
        // graphics_fill_screen(disp, graphics_make_color(0x10, 0x20, 0x40, 0xFF));

        // /* Draw white text on transparent background */
        // graphics_set_color(graphics_make_color(0xFF, 0xFF, 0xFF, 0xFF),
        //                    graphics_make_color(0x00, 0x00, 0x00, 0x00));
        // graphics_draw_text(disp, 110, 112, "Hello, World!");
        // graphics_draw_text(disp, 80, 130, "Running on libdragon + SC64");

        // /* Optional: react to Start being pressed so we know input works */
        // joypad_poll();
        // joypad_buttons_t btn = joypad_get_buttons_pressed(JOYPAD_PORT_1);
        // if (btn.start)
        // {
        //     debugf("Start pressed!\n");
        // }

        // /* Flip the buffer */
        // display_show(disp);
    }
}
