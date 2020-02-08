#include <qrcode.h>

// TODO:
// Error codes
enum err_codes {
    NO_DATA       = 0,
    BAD_FLAG,
    BAD_STR_LEN
};

// TODO:
static const char * err_a[] = {
        "ERROR: No data to encode",
        "ERROR: Option not recognized",
        "ERROR: Data exceeded maximum length"
};

static const char * use_a =     "qr-code - Generate QR Codes fast in a variety of image formats"
                                "\nUsage: qr-code [options] <data>\n"
                                "Options:\n"
                                "\t-h\t"            "Displays this message"
                                "\t-o <filename>\t" "Save to <filename>"
                                "\t-j\t"            "Save symbol as a JPEG image (default)\n"
                                "\t-p\t"            "Save symbol as a PNG image\n"
                                "\t-g\t"            "Save symbol as a GIF image\n"
                                "\t-t\t"            "Save symbol as a TIFF image\n"
                                "\t-b\t"            "Save symbol as a BMP image\n"
                                "\t-P\t"            "Save symbol as a PBM image\n"
                                "\n"
                                "<data>\t"      "Must not exceed X characters in length\n"
                                "<filename>\t"  "Appending file extension no necessary";

static inline void
printuse(void)
{
    fprintf(stdout, "%s\n", use_a);
    exit(1);
}

static inline void
printerr(const uint index)
{
    fprintf(stderr, "%s\n", err_a[index]);
    printuse();
}

static uint strlen(const char *);

int
main(int argc, char ** argv)
{
    uint format = 0x00000000;

    // TODO:
    // Implement parsing of options
    if (argc == 1)
    {
        printerr(NO_DATA);
    }

    // For testing purposes only:
    generate_qr_code(argv[1], argv[2], format);
    
    return 0;
}

static uint
strlen(const char * s)
{
    uint n;
    for (n = 0; *(s + n); ++n);
    return n;
}