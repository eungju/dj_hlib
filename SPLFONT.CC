#include <stdio.h>
#include <stdlib.h>
#include "splfont.h"
#include "operfont.h"

SpecialFont::SpecialFont(void *font, bool internal, int w, int h) :
    BaseFont(font, 1128, internal, w, h)
{
}

SpecialFont::~SpecialFont()
{
}

void *SpecialFont::combine(hancode_t code)
{
    int offset;
    static int sfot[7] = {0, 163, 351, 513, 701, 878, 1053};

    if (code.b.fst == 0xd4) offset = ((code.b.fst - 0xd4) << 8) | (code.b.snd - 0x81);
    else {
        if (code.b.snd > 0x7e) code.b.snd -= 0x12;
        code.b.snd -= 0x31;
        offset = sfot[code.b.fst - 0xd9] + code.b.snd + 125 - 1;
    }
    cpyfont(_buffer, _addr[offset], _size);
    return _buffer;
}
