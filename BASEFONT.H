#ifndef _BASEFONT_H_
#define _BASEFONT_H_

#include "typedefs.h"
#include "operfont.h"

class BaseFont {
protected:
    int     _width, _height;    // ˆa¡,­A¡ Ça‹¡
    char    _fontname[13];      // ‹i©Ìa·© ·¡Ÿq
    void    *_data;             // ‹i©·i ¸á¸wÐi ¡A¡¡Ÿ¡
    void    **_addr;         // ‹i©· ¶áÃ¡
    int     _num;               // ‹i© ˆ•®
    size_t  _size;              // ‹i©Ðaa· Ça‹¡
    void    *_buffer;
    bool    _internal;
    int     _errorcode;
    const int FS16x16   =   32;
    const int FS8x16    =   16;
public:
    BaseFont(void *font, int n, bool internal, int w, int h);
    ~BaseFont();
    inline const char *fontname()   {   return _fontname;   }
    inline int width()  {   return _width;  }
    inline int height() {   return _height; }
    inline int size()   {   return _size;   }
    inline int num()    {   return _num;    }
    inline bool isinternal()  {   return _internal;   }
    inline int errorcode()  {   return _errorcode;  }
    void *getfont(unsigned int pos)
    {
        cpyfont(_buffer, _addr[pos], _size);
        return _buffer;
    }
    virtual void *combine(hancode_t code);
};

#endif
