#include <stdio.h>
#include <stdlib.h>
#include "engfont.h"
#include "operfont.h"

EngFont::EngFont(void *font, bool internal, int w, int h) :
    BaseFont(font, 256, internal, w, h)
{
}

EngFont::~EngFont()
{
}

void *EngFont::combine(hancode_t code)
{
    cpyfont(_buffer, _addr[code.b.snd], _size);
    return _buffer;
}
