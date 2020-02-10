#include <qrcode.h>

#define CHECK_N_SET(x)  if (format & x)\
                            printerr(REP_FLAG);\
                        format |= x;\
                        break;\

// TODO:
// Error codes
enum err_codes {
    NO_DATA       = 0,
    FEW_ARGS,
    TOO_MANY_ARGS,
    BAD_FLAG,
    REP_FLAG,
    BAD_STR_LEN
};

// TODO:
static const char * err_a[] = {
        "ERROR: No data to encode",
        "ERROR: Too few arguments",
        "ERROR: Too many arguments"
        "ERROR: Option not recognized",
        "ERROR: Repeated flag",
        "ERROR: Data exceeded maximum length"
};

static const char * use_a =     "qr-code - Generate QR Codes fast in a variety of image formats"
                                "\nUsage: qr-code [options] <filename> <data>\n"
                                "Options:\n"
                                "\t-h\t"            "Displays this message"
                                "\t-j\t"            "Save symbol as a JPEG image (default)\n"
                                "\t-p\t"            "Save symbol as a PNG image\n"
                                "\t-g\t"            "Save symbol as a GIF image\n"
                                "\t-t\t"            "Save symbol as a TIFF image\n"
                                "\t-b\t"            "Save symbol as a BMP image\n"
                                "\t-m\t"            "Save symbol as a PBM image\n"
                                "\n"
                                "<data>\t"      "Must not exceed X characters in length\n"
                                "<filename>\t"  "Appending file extension not necessary";

static inline void
printuse(void)
{
    fprintf(stdout, "%s\n", use_a);
    exit(0);
}

static inline void
printerr(const uint index)
{
    fprintf(stderr, "%s\nUse option -h for help", err_a[index]);
    exit(1);
}

static uint strlen(const char *);

int
main(int argc, char ** argv)
{
    char * filename = NULL;
    uint format     = 0x00000000;
    uint i;

    switch (argc)
    {
        case 1:
            printerr(FEW_ARGS);
        case 2:
            if (strlen(argv[1]) < 2)
            {
                printerr(FEW_ARGS);
            }
            if (argv[1][0] == '-' && argv[1][1] == 'h')
            {
                printuse();
            } else {
                printerr(FEW_ARGS);
            }
        case 3:
            filename = argv[argc - 2];
            break;
        case 4:
            filename = argv[argc - 2];
            if ( (strlen(argv[1]) < 2) || (argv[1][0] != '-') )
                printerr(BAD_FLAG);
            for (i = 1; i < strlen(argv[1]); ++i)
                switch (argv[1][i])
                {
                    case 'h':
                        printuse();                    
                    case 'j':
                        CHECK_N_SET(JPEG);
                    case 'p':
                        CHECK_N_SET(PNG);
                    case 'g':
                        CHECK_N_SET(GIF);
                    case 't':
                        CHECK_N_SET(TIFF);
                    case 'b':
                        CHECK_N_SET(BMP);
                    case 'm':
                        CHECK_N_SET(PBM);
                    default:
                        printerr(BAD_FLAG);
                }
        default:
            printerr(TOO_MANY_ARGS);
    }
    
    // For testing purposes only:
    if ( generate_qr_code(filename, format, argv[argc - 1]) )
        printerr(NO_DATA);
    
    return 0;
}

static uint
strlen(const char * s)
{
    uint n;
    for (n = 0; *(s + n); ++n);
    return n;
}