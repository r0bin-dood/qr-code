CC = gcc
CSTD = c99
INCLUDE_PATH = include/
SOURCE_PATH = src/
BIN_PATH = bin/

CFLAGS = -Wall -Wextra -O0 -std=$(CSTD) -I$(INCLUDE_PATH) 

cli : $(BIN_PATH)cli.o $(BIN_PATH)qrcode.o $(BIN_PATH)qrcode_jpeg.o $(BIN_PATH)qrcode_png.o $(BIN_PATH)qrcode_gif.o $(BIN_PATH)qrcode_tiff.o $(BIN_PATH)qrcode_bmp.o $(BIN_PATH)qrcode_pbm.o
	$(CC) -o $(BIN_PATH)$@ $^

cli.o : $(SOURCE_PATH)cli.c
	$(CC) $(CFLAGS) -o $(BIN_PATH)$@ -c $<

qrcode.o : $(SOURCE_PATH)qrcode.c
	$(CC) $(CFLAGS) -o $(BIN_PATH)$@ -c $<
qrcode_jpeg.o : $(SOURCE_PATH)qrcode_jpeg.c
	$(CC) $(CFLAGS) -o $(BIN_PATH)$@ -c $<
qrcode_png.o : $(SOURCE_PATH)qrcode_png.c
	$(CC) $(CFLAGS) -o $(BIN_PATH)$@ -c $<
qrcode_gif.o : $(SOURCE_PATH)qrcode_gif.c
	$(CC) $(CFLAGS) -o $(BIN_PATH)$@ -c $<
qrcode_tiff.o : $(SOURCE_PATH)qrcode_tiff.c
	$(CC) $(CFLAGS) -o $(BIN_PATH)$@ -c $<
qrcode_bmp.o : $(SOURCE_PATH)qrcode_bmp.c
	$(CC) $(CFLAGS) -o $(BIN_PATH)$@ -c $<
qrcode_pbm.o : $(SOURCE_PATH)qrcode_pbm.c
	$(CC) $(CFLAGS) -o $(BIN_PATH)$@ -c $<

