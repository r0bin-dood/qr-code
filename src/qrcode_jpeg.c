#include <qrcode.h>

static const uint32_t JPEG_M = 0x4A464946;

/*
    SOI
    |- Table(s)
    |- DHP
        |- Table(s)
        |- EXP
        |- SOF
        |   |- Table(s)
        |   |- SOS
        |   |   |- ECS
        |   |   |- RST 
        |   |- ECS
        |- DNL
    EOI

                                   v------ (i=1 to Nf) --------|
    SOF - Lf -> P -> Y -> X -> Nf -> C_i -> H_i -> V_i -> Tq_i -/

                    v---- (i=1 to Ns) -----|
    SOS - Ls -> Ns -> CS_i -> Td_i -> Ta_i -> Ss -> Se -> Ah -> Al -/

                                   v------- (i=1 to Nf) -------|
    DHP - Lf -> P -> Y -> X -> Nf -> C_i -> H_i -> V_i -> Tq_i -/

    DNL - Ld -> NL -/

    EXP - Le -> Eh -> Ev -/

    Tables:
                    v-------------- (n times) --------------|
        DQT     Lq -> Pq -> Tq -> Q_0 -> Q_1 -> ... -> Q_63 -/

                         v----------------------- (n times) -------------------------|
         |-- DHT     Lh -> Tc -> Th -> L_1 -> ... -> L_16 -> V_1,1 -> ... -> V_16,16 -/
        -|
         |               v-- (n times) --|
         |-- DAC     La -> Tc -> Tb -> Cs -/
           |------------------------------^        

        DRI     Lr -> Ri -/ 
        COM     Lc -> ... -/
        APP_n   Lp -> Ap_1 ... Ap_(lp-2) -/
    
*/

// TODO: Re-order structs
typedef struct __attribute__ ((packed)) {
    uint16_t    Lh;
    struct {
        uint8_t     Tc__Th;
        uint8_t *   L_n;
        uint8_t *   V_nn;
    } * table_segment;   
} DHT;

typedef struct __attribute__ ((packed)) {
    uint16_t    Lp;
    uint8_t     id[5];
    uint16_t    V;
    uint8_t     U;
    uint16_t    Hd;
    uint16_t    Vd;
    uint8_t     Ht_a;
    uint8_t     Vt_a;
    uint8_t     ** RGB;
} APP_n;

typedef struct __attribute__ ((packed)) {
    EXP *   exp_marker;
    SOF *   frame_marker;
} DHP;

typedef struct __attribute__ ((packed)) {
    uint16_t    Le;
    uint8_t     Eh__Ev;
} EXP;

typedef struct __attribute__ ((packed)) {
    uint16_t    Lf;
    uint8_t     P;
    uint16_t    Y;
    uint16_t    X;
    uint8_t     Nf;
    struct {
        uint8_t     C_i;
        uint8_t     H_i__V_i;
        uint8_t     Tq_i;
    } * component_param;
    SOS *   scan_marker;
    struct {
        DNL *   num_lines;
        SOS *   scan_marker;
    } * scans;
} SOF;

typedef struct __attribute__ ((packed)) {
    uint16_t    Ls;
    uint8_t     Ns;
    struct {
        uint8_t     Cs_j;
        uint8_t     Td_j__Ta_j;
    } * component_param;
    uint8_t     Ss;
    uint8_t     Se;
    uint8_t     Ah__Al;
    ECS *       entropy_0;
    struct {
        RST *   reset;
        ECS *   entropy;
    } * body;
} SOS;

typedef struct __attribute__ ((packed)) {
} ECS; // raw huffman encoded data

typedef struct __attribute__ ((packed)) {
    uint8_t     blank;
} RST;

typedef struct __attribute__ ((packed)) {
    uint16_t    Ld;
    uint16_t    NL;
} DNL;


typedef struct __attribute__ ((packed)) {
    uint16_t    SOI;
    APP_n *     app_0;
    DHP *       segment;
    uint16_t    EOI;
} JPEGImage;

uint 
qr_code_jpeg(const char * filename, const char * data)
{
    uint i;
    for (i = 0; *(data + i); ++i)
        if ( (*(data + i) < 0x20) | (*(data + i) > 0x7F) ) // check for byte data larger than 0x7F and less than 0x20, see JIS and ASCII, printable chars only
            return 1;
    
    

    return 0;
}

// TODO: Huffman encoding implementation
static void
huffman_enc()
{

}
