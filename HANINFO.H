#ifndef _HANINFO_H_
#define _HANINFO_H_

struct haninfo_t {
    int initial;
    int medial;
    int final;
    int space;
    int fst_index[2][20];
    int mid_index[3][22];
};

extern haninfo_t _haninfo8x4x4D;
extern haninfo_t _haninfo8x4x4;
extern haninfo_t _haninfo1x1x1;

#endif
