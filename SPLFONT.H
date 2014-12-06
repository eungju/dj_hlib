#ifndef _SPLFONT_H_
#define _SPLFONT_H_

#include "typedefs.h"
#include "operfont.h"
#include "basefont.h"

class SpecialFont : BaseFont {
public:
    SpecialFont(void *font, bool internal = false, int w = 16, int h = 16);
    ~SpecialFont();
    void *getfont(unsigned int pos)
    {
        cpyfont(_buffer, _addr[pos], _size);
        return _buffer;
    }
    virtual void *combine(hancode_t code);
};

#endif
