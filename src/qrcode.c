#include <qrcode.h>

uint
generate_qr_code(const char * filename, uint format, const char * data)
{
    if (format == 0x00000000U)
        format |= JPEG;
    
    uint (* generate[IMG_FMT_NUM])(const char *, const char*);

    uint i;
    for (i = 0; i < IMG_FMT_NUM; ++i)
        generate[i] = NULL;

    if (format & JPEG)
        generate[0] = &qr_code_jpeg;
    if (format & PNG)
        generate[1] = &qr_code_png;
    if (format & GIF)
        generate[2] = &qr_code_gif;
    if (format & TIFF)
        generate[3] = &qr_code_tiff;
    if (format & BMP)
        generate[4] = &qr_code_bmp;
    if (format & PBM)
        generate[5] = &qr_code_pbm;

    for (i = 0; i < IMG_FMT_NUM; ++i)
        if (generate[i])
            generate[i](filename, data);
}
