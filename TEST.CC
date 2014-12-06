#include <stdio.h>
#include <stdlib.h>
#include "hdisp.h"
#include "hanfont.h"
#include "basefont.h"
#include "engfont.h"
#include "splfont.h"
#include "hjfont.h"
#include "pc.h"

void main(int argc, char *argv[])
{
    HDisplay HD(320,200);
    HanFont HF1("han111.fnt", &_haninfo1x1x1);
    HanFont HF2("han844d.fnt", &_haninfo8x4x4D);
    EngFont EF("eng.fnt");
    SpecialFont SF("spl.fnt");
    HanjaFont HJF("hanja.fnt");
    int i, j, c;
    hancode_t hc[5];

    /*if ((SF2.errorcode() != NOERROR) || (SF3.errorcode() != NOERROR)) {
        printf("\7\7\7\n");
        exit(1);
    }*/
    hc[0].code = 'Ðe';
    hc[1].code = 'A';
    hc[2].code = 'Ôƒ';
    hc[3].code = '÷Û';
    hc[4].code = '·w';
    HD.hclrscr(0,0,HD.width(), HD.height(), 15);

    HD.hputfont16x16(0,0, HF1.combine(hc[0]), 15, 1);
    HD.hputfont16x16(0,1, HF2.combine(hc[4]), 15, 1);
    HD.hputfont8x16(0,2, EF.combine(hc[1]), 15, 1);
    HD.hputfont16x16(0,3, SF.combine(hc[2]), 15, 1);
    HD.hputfont16x16(0,4, HJF.combine(hc[3]), 15, 1);
    getkey();
}

