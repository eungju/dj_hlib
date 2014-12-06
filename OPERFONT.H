#ifndef _OPERFONT_H_
#define _OPERFONT_H_

#include "typedefs.h"

void orfont16x16 (void *dst, void *src);
void cpyfont16x16 (void *dst, void *src);
void zeroset_font16x16 (void *dst);
void orfont8x16 (void *dst, void *src);
void cpyfont8x16 (void *dst, void *src);
void zerosetfont8x16 (void *dst);
void orfont (void *dst, void *src, size_t s);
void cpyfont (void *dst, void *src, size_t s);
void zerosetfont (void *dst, size_t s);

#endif
