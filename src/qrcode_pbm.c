#include <qrcode.h>

static const uint PBM_M = 0x5001;

uint 
qr_code_pbm(const char * filename, const char * data)
{
    uint i;
    for (i = 0; *(data + i); ++i)
        if ( (*(data + i) < 0x20) | (*(data + i) > 0x7F) ) // check for byte data larger than 0x7F and less than 0x20, see JIS and ASCII, printable chars only
            return 1;

    printf("PBM");

    return 0;
}