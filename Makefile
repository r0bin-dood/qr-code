CC = clang
CSTD = c99
INCLUDE_PATH = include/
SRC_DIR = src/
BIN_DIR = bin/
SOURCES	= 	$(SRC_DIR)cli.c \
			$(SRC_DIR)qrcode.c \
			$(SRC_DIR)qrcode_jpeg.c \
			$(SRC_DIR)qrcode_png.c \
			$(SRC_DIR)qrcode_gif.c \
			$(SRC_DIR)qrcode_tiff.c \
			$(SRC_DIR)qrcode_bmp.c \
			$(SRC_DIR)qrcode_pbm.c 

OBJ 	= 	$(BIN_DIR)cli.o \
			$(BIN_DIR)qrcode.o \
			$(BIN_DIR)qrcode_jpeg.o \
			$(BIN_DIR)qrcode_png.o \
			$(BIN_DIR)qrcode_gif.o \
			$(BIN_DIR)qrcode_tiff.o \
			$(BIN_DIR)qrcode_bmp.o \
			$(BIN_DIR)qrcode_pbm.o 

CFLAGS = -Wall -Wextra -O0 -std=$(CSTD) -I$(INCLUDE_PATH) 

qrcode : $(OBJ)
	$(CC) -o $@ $^

$(OBJ) : $(SOURCES)
	$(CC) $(CFLAGS) -o $@ -c $<

.PHONY : clean
clean : 
	rm bin/*
