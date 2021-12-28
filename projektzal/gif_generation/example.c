#include "gifenc.h"
#include <string.h>

int
main()
{
    int i, j;
    int w = 40, h = 40;

    /* draw some frames */
    /*
        0X00
        XX00
        0X00
        0000

        XX00
        XXX0
        XX00
        0000
    */
    uint8_t pixels_f[] = {
        2, 2, 2, 2,
        2, 0, 0, 0,
        2, 0, 0, 0,
        2, 2, 2, 0,
        2, 0, 0, 0,
        2, 0, 0, 0,
        2, 0, 0, 0
    };
    uint8_t pixels_g[] = {
        2, 2, 2, 2,
        2, 0, 0, 0,
        2, 0, 0, 0,
        2, 0, 2, 2,
        2, 0, 0, 2,
        2, 0, 0, 2,
        2, 2, 2, 2
    };
    ge_GIF *gif_from_array = ge_new_gif("F.gif", 4, 7, 
            (uint8_t []) {  /* palette */
            0x00, 0x00, 0x00, /* 0 -> black */
            0xFF, 0xFF, 0xFF, /* 1 -> red */
            0x00, 0xFF, 0x00, /* 2 -> green */
            0x00, 0x00, 0xFF, /* 3 -> blue */
        },
        2, -1, 0);
    gif_from_array->nframes=2; /*liczba kroków*/
    memcpy(gif_from_array->frame, pixels_f, sizeof(pixels_f));
    ge_add_frame(gif_from_array, 100); /*100 delay - zatrzyma się na obrazku na 1 sek.*/
    memcpy(gif_from_array->frame, pixels_g, sizeof(pixels_g));
    ge_add_frame(gif_from_array, 100);
    /* remember to close the GIF */
    ge_close_gif(gif_from_array);
    return 0;
}
