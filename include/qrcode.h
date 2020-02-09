#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

typedef unsigned char   uchar;
typedef unsigned int    uint;
typedef unsigned long   ulong;

#define IMG_FMT_NUM     6
enum img_formats {
    JPEG    = 0xF0000000,
    PNG     = 0x0F000000,
    GIF     = 0x00F00000,
    TIFF    = 0x000F0000,
    BMP     = 0x0000F000,
    PBM     = 0x00000F00
};

uint generate_qr_code(const char *, uint, const char *);

uint qr_code_jpeg(const char *, const char *);
uint qr_code_png(const char *, const char *);
uint qr_code_gif(const char *, const char *);
uint qr_code_tiff(const char *, const char *);
uint qr_code_bmp(const char *, const char *);
uint qr_code_pbm(const char *, const char *);
