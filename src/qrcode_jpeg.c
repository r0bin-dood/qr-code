#include <qrcode.h>

static const uint32_t JPEG_M = 0x4A464946;

typedef struct {
    uint16_t    app_0;
    uint16_t    length;
    uint8_t     identifier[5];
    uint16_t    version;
    uint8_t     units;
    uint16_t    h_density;
    uint16_t    v_density;
    uint8_t     h_thumbnail_a;
    uint8_t     v_thumbnail_a;
} APP_0;

typedef struct {
    uint16_t    sof_0;
} Segment;

typedef struct {
    uint16_t    soi;
    APP_0       init_marker;
    Segment *   segment;
    uint16_t    eoi;
} JPEGImage;

uint 
qr_code_jpeg(const char * filename, const char * data)
{
    uint i;
    for (i = 0; *(data + i); ++i)
        if ( (*(data + i) < 0x20) | (*(data + i) > 0x7F) ) // check for byte data larger than 0x7F and less than 0x20, see JIS and ASCII, printable chars only
            return 1;
    
    printf("JPEG");

    return 0;
}