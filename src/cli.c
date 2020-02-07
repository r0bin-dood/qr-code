#include <stdio.h>
#include <stdlib.h>

typedef unsigned int uint;

// Error codes
enum err_codes {
    NO_STRING       = 0,
    ILLEGAL_OPT,
    ILLEGAL_STR_L,   
    ILLEGAL_COMBO,  
    ILLEGAL_C_FMT,  
    ILLEGAL_F_FMT,  
    ILLEGAL_S_FMT,  
    NEG_RGB_VAL,  
    NEG_IMG_SIZE,    
    NAN_RGB_VAL,   
    NAN_IMG_SIZE,    
    BIG_RGB_VAL,   
    SMALL_IMG_SZ,    
    BIG_IMG_SZ      
};

static const char * err_a[] = {
        "ERROR: No string to encode",
        "ERROR: Option not recognized",
        "ERROR: String exceeded maximum length",
        "ERROR: Illegal combination of options",
        "ERROR: Illegal color format",
        "ERROR: Illegal filename format",
        "ERROR: Illegal size format",
        "ERROR: RGB values can't be negative",
        "ERROR: Image size values can't be negative",
        "ERROR: RGB values have to be numbers",
        "ERROR: Image size values have to be numbers",
        "ERROR: Image size too big",
        "ERROR: Image size too big"
};

static const char * use_a =   "\nUsage: qr-code-cli [options] <string>\n"
                                "Options:\n"
                                "\t-a\t\t\t"          "Print output in ASCII\n"
                                "\t-ar\t\t\t"         "Print output using random ASCII characters\n"
                                "\t-c <color>\t\t"    "Print output in a different color\n"
                                "\t-cr\t\t\t"         "Print output in random colors\n"
                                "\t-o <filename>\t\t" "Print output to a file\n"
                                "\t-oj <filename> <size>\t"    "Print output to a JPEG image\n"
                                "\n"
                                "<string>\t"    "must be between 1 and X characters long\n"
                                "<color>\t\t"   "R,G,B - where R, G, and B range from 0 to 255\n"
                                "<filename>\t"  "ASCII characters only path-to-file\n"
                                "<size>\t\t"    "WIDTH,HEIGHT - where WIDTH and HEIGHT are positive integers\n";

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
    // Check for arguments
    if (argc == 1)
    {
        printerr(NO_STRING);
    }
    
    
    return 0;
}

static uint
strlen(const char * restrict s)
{
    uint n;
    for (n = 0; *(s + n); ++n);
    return n;
}