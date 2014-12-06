/*  HDISP.H
 *  ÉB¯aËa µA£IA·¡­e ‹aœÏ¢ Çiœ¯a.
 *  1995/12/29
 *   e—e·¡ : ¤b·wº (written by Park Eung Ju)
 *  µeœbÀá : ‰wq Àw¶¥¯¡ ¡w¬á•· 124-1¤å»¡ Tel (0551)88-9940
 */

#ifndef _HDISP_H_
#define _HDISP_H_

#include <stdlib.h>
#include "../contrib/libgrx/include/grdriver.h"
#include "../contrib/libgrx/include/grx.h"
#include "typedefs.h"
#include "egaregs.h"
#include "pc.h"

class HDisplay {
protected:
    int _width, _height;
    int _maxcolor;
    int _homex, _homey;
    int _maxx, _maxy;
    char *_dispmem;
    int _bpsl;
    int _graphmode;
    int _errorcode;
    void _exithandle();
    const SUPPORTEDCOLOR = 16;
    const int charspace = 8;
    const int linespace = 16;

    int lowsetmode(GR_graphics_modes mode, int w, int h, int c);
public:
    HDisplay();
    HDisplay(int w, int h);
    ~HDisplay();
    void setmode(GR_graphics_modes mode, int w, int h);
    inline outport(int port, int index, int val)
    {
        outportw(port, (val << 8) | index);
    }
    inline char *vm_addr(int x, int y)
    {
        return (_dispmem + (y << 4) * _bpsl + x);
    }
    inline bool isgraphmode();
    inline int width();     inline int width(int w);
    inline int height();    inline int height(int h);
    inline int maxcolor();  inline int maxcolor(int c);
    inline int homex();     inline int homex(int x);
    inline int homey();     inline int homey(int y);
    inline int maxx();      inline int maxx(int x);
    inline int maxy();      inline int maxy(int y);
    void hputfont8x16 (int x, int y, void *font, int fg, int bg);
    void hputfont16x16 (int x, int y, void *font, int fg, int bg);
    void hclrscr (int x, int y, int w, int h, int c);
    void hhline (int px, int py, int len, int c);
    void hvline (int px, int py, int len, int c);
    void hgetimage (int x, int y, int w, int h, void *buf);
    void hputimage (int x, int y, int w, int h, void *buf);
    void hscroll (int x, int y, int w, int h, int line);
    void hbackscroll (int x, int y, int w, int h, int line);
    void hputpixel(int px, int py, int c);
    int  hgetpixel(int px, int py);
    void hsolidbar (int px, int py, int width, int height, int color);
    void puterr(const char *message, int status = EXIT_FAILURE);
};

inline bool HDisplay::isgraphmode()
{
    return (_graphmode != false ? true : false);
}

inline int HDisplay::width()
{
    return _width;
}

inline int HDisplay::height()
{
    return _height;
}

inline int HDisplay::maxcolor()
{
    return _maxcolor;
}

inline int HDisplay::homex()
{
    return _homex;
}

inline int HDisplay::homey()
{
    return _homey;
}

inline int HDisplay::maxx()
{
    return _maxx;
}

inline int HDisplay::maxy()
{
    return _maxy;
}

inline int HDisplay::width(int w)
{
    return (_width = w);
}

inline int HDisplay::height(int h)
{
    return (_height = h);
}

inline int HDisplay::maxcolor(int c)
{
    return (_maxcolor = c);
}

inline int HDisplay::homex(int x)
{
    return (_homex = x);
}

inline int HDisplay::homey(int y)
{
    return (_homey = y);
}

inline int HDisplay::maxx(int x)
{
    return (_maxx = x);
}

inline int HDisplay::maxy(int y)
{
    return (_maxy = y);
}

#endif
