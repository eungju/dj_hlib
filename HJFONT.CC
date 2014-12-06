#include <stdio.h>
#include <stdlib.h>
#include "hjfont.h"
#include "operfont.h"

HanjaFont::HanjaFont(void *font, bool internal, int w, int h) :
    BaseFont(font, 4888, internal, w, h)
{
}

HanjaFont::~HanjaFont()
{
}

void *HanjaFont::combine(hancode_t code)
{
    int offset;

    code.b.fst -= 0xe0;
    if (code.b.snd > 0x7e) code.b.snd -= 0x12;
    code.b.snd -= 0x31;
    offset = code.b.fst * 188 + code.b.snd;
    cpyfont(_buffer, _addr[offset], _size);
    return _buffer;
}
