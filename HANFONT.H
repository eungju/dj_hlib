#ifndef _HANFONT_H_
#define _HANFONT_H_

#include "typedefs.h"
#include "haninfo.h"
#include "operfont.h"
#include "basefont.h"

class HanFont : BaseFont {
protected:
    void    **_initialaddr;
    void    **_medialaddr;
    void    **_finaladdr;
    haninfo_t   *_hinfo;
    const int INITIAL = 0;
    const int MEDIAL  = 1;
    const int FINAL   = 2;
    const int INITIALNUM;
    const int MEDIALNUM;
    const int FINALNUM;
public:
    HanFont(void *font, haninfo_t *hinfo, bool internal = false, int w = 16, int h = 16);
    ~HanFont();
    void *getfont(unsigned int pos)
    {
        cpyfont(_buffer, _addr[pos], _size);
        return _buffer;
    }
    void *combine(hancode_t code);
};

#endif
