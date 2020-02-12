#include <qrcode.h>

static const uint32_t JPEG_M = 0x4A464946;

/*
    SOI : Start of image    | EOI : End of image
    RST : Restart marker
    SOF : Start of frame
    Lf : Frame header length
    P : Sample precision
    Y : Number of lines 
    X : Number of samples per line
    Nf : Number of image components in frame
    C_i : Component identifier
    H_i : Horizontal sampling factor
    V_i : Vertical sampling factor
    Tq_i : Quantization table destination selector

    SOS : Start of scan marker
    Ls : Scan header length
    Ns : Number of image components in scan
    Cs_j : Scan component selector
    Td_j : DC entropy coding table destination selector
    Ta_j : AC entropy coding table destination selector
    Ss : Start of spectral or predictor selection
    Se : End of spectral selection
    Ah : Successive approximation bit position high
    Al : Successive approximation bit position low or point transform

    DQT : Define quantization table marker
    Lq : Quantization table definition length
    Pq : Quantization table element precision
    Tq : Quantization table destination identifier
    Q_k : Quantization table element

    DHT: Define Huffman table marker
    Lh : Huffman table definition length
    Tc : Table class
    Th : Huffman table destination identifier
    L_i : Number of Huffman codes of length i
    V_i,j : Value associated with each Huffman code

    DAC : Define arithmetic coding conditioning marker
    La : Arithmetic coding conditioning definition length
    Tc : Table class
    Tb : Arithmetic coding conditioning table destination identifier
    Cs : Conditioning table value

    DRI : Define restart interval marker
    Lr : Define restart interval segment length
    Ri : Restart interval

    APP_n : Application data marker
    Lp : Application data segment length
    Ap_i : Application data byte

    DNL : Define number of lines marker
    Ld : Define number of lines segment length
    NL : Number of lines

    EXP : Expand reference components marker 
    Le : Expand reference components segment length
    Eh : Expand horizontally
    Ev : Expand vertically

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
    uint8_t     ** RGB;
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