// BMP-related data types based on Microsoft's own

#include <stdint.h>

// These data types are essentially aliases for C/C++ primitive data types.
// Adapted from http://msdn.microsoft.com/en-us/library/cc230309.aspx.
// See https://en.wikipedia.org/wiki/C_data_types#stdint.h for more on stdint.h.

//the below is the unsigned 8 bit integer
typedef uint8_t  BYTE;
//the below is the unsigned 32 bit integer
typedef uint32_t DWORD;
//the below is the signed 32 bit integer
typedef int32_t  LONG;
// the below is the unigned 16 bit integer
typedef uint16_t WORD;

// The BITMAPFILEHEADER structure contains information about the type, size,
// and layout of a file that contains a DIB [device-independent bitmap].
// Adapted from http://msdn.microsoft.com/en-us/library/dd183374(VS.85).aspx.
// BITMAPFILEHEADER - the type and size is mentioned below.

typedef struct
{
    WORD   bfType;
    DWORD  bfSize;
    WORD   bfReserved1;
    WORD   bfReserved2;
    DWORD  bfOffBits;
} __attribute__((__packed__))
BITMAPFILEHEADER;

// The BITMAPINFOHEADER structure contains information about the
// dimensions and color format of a DIB [device-independent bitmap].
// Adapted from http://msdn.microsoft.com/en-us/library/dd183376(VS.85).aspx.
// it contains information about the dimensions and color format.

typedef struct
{
    DWORD  biSize;
    LONG   biWidth;
    LONG   biHeight;
    WORD   biPlanes;
    WORD   biBitCount;
    DWORD  biCompression;
    DWORD  biSizeImage;
    LONG   biXPelsPerMeter;
    LONG   biYPelsPerMeter;
    DWORD  biClrUsed;
    DWORD  biClrImportant;
} __attribute__((__packed__))
BITMAPINFOHEADER;

// The RGBTRIPLE structure describes a color consisting of relative intensities of
// red, green, and blue. Adapted from http://msdn.microsoft.com/en-us/library/aa922590.aspx.

typedef struct
{
    BYTE  rgbtBlue;
    BYTE  rgbtGreen;
    BYTE  rgbtRed;
} __attribute__((__packed__))
RGBTRIPLE;
