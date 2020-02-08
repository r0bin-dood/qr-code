#include <stdio.h>
#include <stdlib.h>

typedef unsigned int uint;

#define IMG_FMT_NUM     6
enum img_formats {
    JPEG    = 0xF0000000,
    PNG     = 0x0F000000,
    GIF     = 0x00F00000,
    TIFF    = 0x000F0000,
    BMP     = 0x0000F000,
    PBM     = 0x00000F00
}

uint generate_qr_code(char *, char *, uint)

uint qr_code_jpeg(char *, char *);
uint qr_code_png(char *, char *);
uint qr_code_gif(char *, char *);
uint qr_code_tiff(char *, char *);
uint qr_code_bmp(char *, char *);
uint qr_code_pbm(char *, char *);
