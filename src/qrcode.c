#include <qrcode.h>

enum img_magic {
    JPEG_M    = 0x4A464946,
    PNG_M     = 0x89504E47,
    GIF_M     = 0x474946383961,
    TIFF_M    = 0x4D4D0042,
    BMP_M     = 0x424D,
    PBM_M     = 0x5001
}

uint
generate_qr_code(const char * filename, const char * data, uint format)
{
    if (!(format & (uint)0xFFFFFFFF))
        format |= JPEG;
    
    uint (* generate[IMG_FMT_NUM])(char *, char*);

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

    for (;;)
    {
        if (generate[i](filename, data))
    }
}

uint 
qr_code_jpeg(char *, char *)
{

}

uint 
qr_code_png(char *, char *)
{

}

uint 
qr_code_gif(char *, char *)
{

}

uint 
qr_code_tiff(char *, char *)
{

}

uint 
qr_code_bmp(char *, char *)
{

}

uint 
qr_code_pbm(char *, char *)
{

}