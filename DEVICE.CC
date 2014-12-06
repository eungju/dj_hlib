/*
 *  HANDEV.C
 *
 *  1995/12/11
 *  - written by Park Eung Ju.
 */
#include "hdisp.h"

void HDisplay::hputfont8x16(int x, int y, void *font, int fg, int bg)
{
    char *offset = vm_addr(x, y);
    char l;
    int i;

    outport(GAR, SRR, bg);
    *offset = 0xff;
    outport(GAR, SRR, fg);
    l = *offset;

    for (i = 0; i < 16; i++) {
        *offset = *((char *)font)++;
        offset += _bpsl;
    }
}

void HDisplay::hputfont16x16(int x, int y, void *font, int fg, int bg)
{
    char *offset = vm_addr(x, y);
    short l;
    int i;

    outport(GAR, SRR, bg);
    *(short *)offset = 0xffff;
    outport(GAR, SRR, fg);
    l = *(short *)offset;

    for (i = 0; i < 16; i++) {
        *(short *)offset = *((short *)font)++;
        offset += _bpsl;
    }
}

void HDisplay::hclrscr(int x, int y, int w, int h, int c)
{
    char *offset = vm_addr(x, y);
    char l;
    int nextline = _bpsl - w;
    int i,j;

    outport(GAR, SRR, c);
    *offset = 0xff;
    l = *offset;

    h <<= 4;
    for (i = 0; i < h; i++) {
        for (j = 0; j < w; j++) *offset++ = 0xff;
        offset += nextline;
    }
}

void HDisplay::hhline(int px, int py, int len, int c)
{
    char l;
    int xe = px + len;
    char *offset = _dispmem + py * _bpsl + (px >> 3);
    char t1 = 0xff >> (px % 8);
    char t2 = ~(0xff >> (xe % 8));
    int i;

    len = xe / 8  - 1 - (px / 8 + 1) + 1;
    outport(GAR, MDR, WM_MODE2);

    outport(GAR, BMR, t1);
    l = *offset;
    *offset++ = c;
    outport(GAR, BMR, 0xff);
    for (i = 0; i < len;i++) *offset++ = c;
    outport(GAR, BMR, t2);
    l = *offset;
    *offset = c;
    outport(GAR, MDR, WM_MODE3);
    outport(GAR, BMR, 0xff);
}

void HDisplay::hvline(int px, int py, int len, int c)
{
    char *offset = _dispmem + py * _bpsl + (px >> 3);
    char l;
    register char t = 0x80 >> (px % 8);

    outport(GAR, SRR, c);

    while(len--) {
        l = *offset;
        *offset = t;
        offset += _bpsl;
    }
}

void HDisplay::hputpixel(int px, int py, int c)
{
    char *offset = _dispmem + py * _bpsl + px / 8;
    char l;

    asm volatile ("
        movl    %0, %%edi       \n
        movl    $0x3ce, %%edx   \n
        movl    $0x0205, %%eax  \n
        outw    %%ax, %%dx      \n
        movb    $8, %%al        \n
        movb    $0x80, %%ah     \n
        movl    %1, %%ecx       \n
        andb    $7, %%ecx       \n
        shrb    %%cl, %%ah      \n
        outw    %%ax, %%dx      \n
        movb    %2, %%ah        \n
        xchgb   (%%edi), %%ah   \n
        movl    $0x0305, %%eax  \n
        outw    %%ax, %%dx      \n"
        :
        : "m" (offset), "g" (px), "g" (c)
        : "di", "si", "ax", "dx"
    );
    /*outport(GAR, MDR, WM_MODE2);
    outport(GAR, BMR, 0x80 >> (px % 8));
    l = *offset;
    *offset = c;
    outport(GAR, MDR, WM_MODE3);*/
}

int HDisplay::hgetpixel(int px, int py)
{
    char *offset = _dispmem + py * _bpsl + px / 8;
    char mask = 0x80 >> (px % 8);
    int plane = 4;
    int pixel = 0;

    while(--plane >= 0) {
        pixel <<= 1;
        outport(GAR, RMSR, plane);
        if (*offset & mask) pixel |= 1;
    }
    return pixel;
}

void HDisplay::hgetimage(int x, int y, int w, int h, void *buf)
{
    char *vp, *p;
    int i, j, plane;
    int nextline;
    int cnt, remain;

    nextline = _bpsl - w;
    cnt = w >> 2;
    remain = w % sizeof(int);

    vp = vm_addr(x, y);
    outport(GAR, MDR, WM_MODE0);

    h <<= 4;
    for (plane = 0; plane < 4; plane++) {
        p = vp;
        outport(GAR, RMSR, plane);
        for (i = 0; i < h; i++) {
            for (j = 0; j < cnt; j++)
                *((int *)buf)++ = *((int *)p)++;
            for (j = 0; j < remain; j++)
                *((char *)buf)++ = *p++;
            p += nextline;
        }
    }
    outport(GAR, MDR, WM_MODE3);
}

void HDisplay::hputimage(int x, int y, int w, int h, void *buf)
{
    char *vp, *p;
    int i, j, plane;
    static char pd[4] = {0x01, 0x02, 0x04, 0x08};
    int nextline;
    int cnt, remain;

    nextline = _bpsl - w;
    cnt = w >> 2;
    remain = w % sizeof(int);

    vp = vm_addr(x, y);
    outport(GAR, MDR, WM_MODE0);
    outport(GAR, ESRR, 0x00);

    h <<= 4;
    for (plane = 0; plane < 4; plane++) {
        outport(SAR, MMR, pd[plane]);
        p = vp;
        for (i = 0; i < h; i++) {
           for (j = 0; j < cnt; j++)
               *((int *)p)++ = *((int *)buf)++;
           for (j = 0; j < remain; j++)
               *p++ = *((char *)buf)++;
           p += nextline;
        }
    }
    outport(GAR, ESRR, 0x0f);
    outport(GAR, MDR, WM_MODE3);
}

void HDisplay::hscroll(int x, int y, int w, int h, int line)
{
    char *sp, *dp;
    int i, j, nl;

    outport(GAR, MDR, WM_MODE1);     /* ·ª‹¡ ¡¡—a 0, ³a‹¡ ¡¡—a 1 */

    nl = _bpsl - w;
    h <<= 4;
    dp = vm_addr(x, y);
    sp = vm_addr(x, y + line);

    for (i = 0; i < h; i++) {
        for (j = 0; j < w; j++) *dp++ = *sp++;
            sp += nl;
            dp += nl;
    }
    outport(GAR, MDR, WM_MODE3);
}

void HDisplay::hbackscroll(int x, int y, int w, int h, int line)
{
    char *sp, *dp;
    int i, j, nl;

    outport(GAR, MDR, WM_MODE1);     /* ·ª‹¡ ¡¡—a 0, ³a‹¡ ¡¡—a 1 */

    nl = _bpsl + w;
    sp = vm_addr(x, y + w - line) - _bpsl;
    dp = vm_addr(x, y + w) - _bpsl;

    for (i = 0; i < h; i++) {
        for (j = 0; j < w; j++) *dp++ = *sp++;
        sp -= nl;
        dp -= nl;
    }

    outport(GAR, MDR, WM_MODE3);     /* ·ª‹¡ ¡¡—a 0, ³a‹¡ ¡¡—a 1 */
}


void HDisplay::hsolidbar(int px, int py, int width, int height, int color)
{
    int i, j;
    char l;
    char buf1, buf2;
    char *offset;
    int nextline;
    int cnt;

    offset = _dispmem + (py * _bpsl) + (px >> 3);
    cnt = (width >> 3) - 1;
    nextline = _bpsl - (width >> 3);

    outport(GAR, SRR, color);
    buf1 = 0xff >> (px & 7);
    buf2 = 0xff << 8 - (px & 7);
    for (i = 0; i < height; i++) {
        l = *offset;
        *offset++ = buf1;
        for (j = 0; j < cnt; j++) *offset++ = 0xff;
        l = *offset;
        *offset = buf2;
        offset += nextline;
    }
}
