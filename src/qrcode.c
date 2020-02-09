#include <qrcode.h>

uint
generate_qr_code(const char * filename, uint format, const char * data)
{
    if (!(format & (uint)0xFFFFFFFF))
        format |= (uint)JPEG;
    
    uint (* generate[IMG_FMT_NUM])(char *, char*);

    uint i;
    for (i = 0; i < IMG_FMT_NUM; ++i)
        generate[i] = NULL;

    if (format & (uint)JPEG)
        generate[0] = &qr_code_jpeg;
    if (format & (uint)PNG)
        generate[1] = &qr_code_png;
    if (format & (uint)GIF)
        generate[2] = &qr_code_gif;
    if (format & (uint)TIFF)
        generate[3] = &qr_code_tiff;
    if (format & (uint)BMP)
        generate[4] = &qr_code_bmp;
    if (format & (uint)PBM)
        generate[5] = &qr_code_pbm;

    for (i = 0; i < IMG_FMT_NUM; ++i)
        if (generate[i])
            generate[i](filename, data);
}
