#include <qrcode.h>

static const ulong GIF_M = 0x474946383961;

uint 
qr_code_gif(const char * filename, const char * data)
{
    uint i;
    for (i = 0; *(data + i); ++i)
        if ( (*(data + i) < 0x20) | (*(data + i) > 0x7F) ) // check for byte data larger than 0x7F and less than 0x20, see JIS and ASCII, printable chars only
            return 1;

}