/*  SETMODE.CC
 *
 *  1995/12/28
 *   e—e·¡ : ¤b·wº (written by Park Eung Ju)
 *  µeœbÀá : ‰wq Àw¶¥¯¡ ¡w¬á•· 124-1¤å»¡ Tel (0551)88-9940
 */
#include <dos.h>
#include <stdio.h>
#include <stdlib.h>
#include "hdisp.h"

#define video_service 0x10

int HDisplay::lowsetmode(GR_graphics_modes mode, int w, int h, int c)
{
    union REGS r;

    r.x.ax = (short)mode;
    r.h.ah = 0xff;
    r.x.cx = w;
    r.x.dx = h;
    r.x.bx = c;

    int86(video_service, &r, &r);

    _width = r.x.cx;
    _height = r.x.dx;
    return (int)(r.x.bx);
}

void HDisplay::setmode(GR_graphics_modes mode, int w, int h)
{
    int planesize;
    int flags;
    int planes;

    flags = lowsetmode(mode, w, h, SUPPORTEDCOLOR);

    if ((mode == GR_80_25_text) || (mode == GR_default_text) || \
        (mode == GR_width_height_text) || (mode == GR_biggest_text)) {
        _dispmem = (char *)0xE00B8000;
        _maxcolor = 16;
        _bpsl = _width * 2;
        _graphmode = false;
    } else {
        switch (flags & GRD_TYPE_MASK) {
            case GRD_VGA:
                _dispmem = (char *)0xD0000000;
                break;
            default:
                puterr("SetMode: unknown adapter type in driver\n");
        }
        switch (flags & GRD_PLANE_MASK) {
            case GRD_4_PLANES:
                _maxcolor = 16;
                _bpsl = _width / 8;
                outportw(0x3ce, 0x0305);    /* ·ª‹¡ ¡¡—a 0, ³a‹¡¡¡—a 3 */
                outportw(0x3ce, 0xff08);    /*  a¯aÇa A»¡¯aÈá */
                outportw(0x3ce, 0x0f01);    /* set reset enable regs */
                outportw(0x3ce, 0x0003);    /* function select regs */
                break;
            default:
                puterr("SetMode: support only 16 color mode\n");
        }
        _graphmode = true;
        //atexit(_exithandle);
    }
    _width /= charspace; _height /= linespace;
    _homex = 0; _homey = 0;
    _maxx = _width - 1; _maxy = _height - 1;
}

void HDisplay::_exithandle()
{
    lowsetmode(GR_default_text, 0, 0, 0);
}
