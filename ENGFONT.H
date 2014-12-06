#ifndef _ENGFONT_H_
#define _ENGFONT_H_

#include "typedefs.h"
#include "operfont.h"
#include "basefont.h"

class EngFont : BaseFont {
public:
    EngFont(void *font, bool internal = false, int w = 8, int h = 16);
    ~EngFont();
    void *getfont(unsigned int pos)
    {
        cpyfont(_buffer, _addr[pos], _size);
        return _buffer;
    }
    virtual void *combine(hancode_t code);
};

#endif
