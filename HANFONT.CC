#include <stdio.h>
#include <stdlib.h>
#include "hanfont.h"
#include "codeinx.h"
#include "operfont.h"

HanFont::HanFont(void *font, haninfo_t *hinfo, bool internal, int w, int h) :
    INITIALNUM(19 + hinfo->space),
    MEDIALNUM(21 + hinfo->space),
    FINALNUM(27 + hinfo->space),
    BaseFont(font, hinfo->initial * (19 + hinfo->space) + \
                   hinfo->medial * (21 + hinfo->space) + \
                   hinfo->final * (27 + hinfo->space),
                   internal, w, h)
{
    int ni, nm, nf;

    _hinfo = hinfo;
    ni = hinfo->initial * INITIALNUM;
    nm = hinfo->medial * MEDIALNUM;
    nf = hinfo->final * FINALNUM;

    _initialaddr = _addr;
    _medialaddr = _addr + ni;
    _finaladdr = _addr + ni + nm;
}

HanFont::~HanFont()
{
}

void *HanFont::combine(hancode_t code)
{
    int ip, mp, fp;
    int ib, mb, fb;
    int skip = _hinfo->space - 1;

    ip = _codeindex[INITIAL][code.p.initial];
    mp = _codeindex[MEDIAL][code.p.medial];
    fp = _codeindex[FINAL][code.p.final];

    fb = _hinfo->mid_index[0][mp];
    if (!fp) {
        mb = _hinfo->fst_index[0][ip];
        ib = _hinfo->mid_index[1][mp];
    } else {
        mb = _hinfo->fst_index[1][ip];
        ib = _hinfo->mid_index[2][mp];
    }
    //if (ip) cpyfont(_buffer, _initialaddr[ib * INITIALNUM + ip + skip], _size);
    //else    zerosetfont(_buffer, _size);
    //if (mp) orfont(_buffer, _medialaddr[mb * MEDIALNUM + mp + skip], _size);
    //if (fp) orfont(_buffer, _finaladdr[fb * FINALNUM + fp + skip], _size);
    if (ip) cpyfont(_buffer, _initialaddr[ib * INITIALNUM + ip + skip], _size);
    else    zerosetfont(_buffer, _size);
    if (mp) orfont(_buffer, _medialaddr[mb * MEDIALNUM + mp + skip], _size);
    if (fp) orfont(_buffer, _finaladdr[fb * FINALNUM + fp + skip], _size);
    return _buffer;
}
