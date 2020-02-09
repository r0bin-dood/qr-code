## qr-code

Generate QR Codes fast in a variety of image formats
<br>

Formats supported so far:

- JPEG

Not yet supported:

- PNG
- GIF
- TIFF
- BMP
- PBM

## About

This project started as an excuse for me to familiarize myself with image formats, especially JPEG. Since I wanted to re-invent the wheel by not using any existing image libraries, it also served as a challenging programming project. Understanding of this topic will help me in bigger, more ambitious projects; where not only do I plan on not using any existing code, but on creating my own image formats as well.
TODO:
(...)

## Installation

```
$ make
$ make install
```

## Usage Examples

```
$ qr-code https://duckduckgo.com
```

## Use the API in your C and Python programs

C:

```c
#include <qrcode.h>

int
main(int argc, char \*\* argv)
{
    qr_code_jpeg("qr_image_0", "https://github.com/gorhill/uBlock/");
    qr_code_png("qr_image_1", "https://decentraleyes.org/");
    generate_qr_code("qr_image_2", GIF | TIFF | BMP | PBM, "https://protonmail.com/");

    return 0;
}
```

Python:

```python
import qrcode

qr_code_jpeg("qr_image_0", b"https://www.whonix.org/")
qr_code_png("qr_image_1", "https://www.qubes-os.org/")
generate_qr_code("qr_image_2", qrcode.GIF | qrcode.TIFF | qrcode.BMP | qrcode.PBM, "https://tails.boum.org/")

```

## Manual Page

TODO:
(...)
