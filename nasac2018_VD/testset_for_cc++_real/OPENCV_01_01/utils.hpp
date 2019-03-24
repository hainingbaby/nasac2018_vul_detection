#ifndef _UTILS_H_
#define _UTILS_H_

typedef unsigned char uchar;

struct PaletteEntry
{
    unsigned char b, g, r, a;
};

#define WRITE_PIX( ptr, clr )       \
    (((uchar*)(ptr))[0] = (clr).b,  \
     ((uchar*)(ptr))[1] = (clr).g,  \
     ((uchar*)(ptr))[2] = (clr).r)

#define  descale(x,n)  (((x) + (1 << ((n)-1))) >> (n))
#define  saturate(x)   (uchar)(((x) & ~255) == 0 ? (x) : ~((x)>>31))

bool  IsColorPalette( PaletteEntry* palette, int bpp );

#endif