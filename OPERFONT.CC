#include "operfont.h"

void orfont16x16(void *dst, void *src)
{
    asm volatile
        ("  movl    %0, %%edi           \n
            movl    %1, %%esi           \n
            movl    $8, %%ecx           \n
         ORLOOP16x16:                   \n
            movl    (%%esi), %%eax      \n
            orl     %%eax, (%%edi)      \n
            addl    $4, %%esi           \n
            addl    $4, %%edi           \n
            loop    ORLOOP16x16         \n"
            :
            : "m"(dst), "m"(src)
            : "di", "si", "cx", "ax"
        );
    //int i;
    //for (i = 0; i < 8; i++) *((int *)dst)++ |= *((int *)src)++;
}

void cpyfont16x16(void *dst, void *src)
{
    asm volatile
        ("  movl    %0, %%edi   \n
            movl    %1, %%esi   \n
            movl    $8, %%ecx   \n
            rep                 \n
            movsl               \n"
            :
            : "m"(dst), "m"(src)
            : "di", "si", "cx"
        );
    //int i;
    //for (i = 0; i < 8; i++) *((int *)dst)++ = *((int *)src)++;
}

void zeroset_font16x16(void *dst)
{
    asm volatile
        ("  movl    %0, %%edi   \n
            movl    $0, %%eax   \n
            movl    $8, %%ecx   \n
            rep                 \n
            stosl               \n"
            :
            : "m"(dst)
            : "si", "cx", "ax"
        );
    //int i;
    //for (i = 0; i < 8; i++) *((int *)dst)++ = 0;
}

void orfont8x16(void *dst, void *src)
{
    asm volatile
        ("  movl    %0, %%edi           \n
            movl    %1, %%esi           \n
            movl    $4, %%ecx           \n
         ORLOOP8x16:                    \n
            movl    (%%esi), %%eax      \n
            orl     %%eax, (%%edi)      \n
            addl    $4, %%esi           \n
            addl    $4, %%edi           \n
            loop    ORLOOP8x16          \n"
            :
            : "m"(dst), "m"(src)
            : "di", "si", "cx", "ax"
        );
    //int i;
    //for (i = 0; i < 8; i++) *((int *)dst)++ |= *((int *)src)++;
}

void cpyfont8x16(void *dst, void *src)
{
    asm volatile
        ("  movl    %0, %%edi   \n
            movl    %1, %%esi   \n
            movl    $4, %%ecx   \n
            rep                 \n
            movsl               \n"
            :
            : "m"(dst), "m"(src)
            : "di", "si", "cx"
        );
    //int i;
    //for (i = 0; i < 4; i++) *((int *)dst)++ = *((int *)src)++;
}

void zerosetfont8x16(void *dst)
{
    asm volatile
        ("  movl    %0, %%edi   \n
            movl    $0, %%eax   \n
            movl    $4, %%ecx   \n
            rep                 \n
            stosl               \n"
            :
            : "m"(dst)
            : "si", "cx", "ax"
        );
    //int i;
    //for (i = 0; i < 4; i++) *((int *)dst)++ = 0;
}

void orfont(void *dst, void *src, size_t s)
{
    asm volatile
        ("  movl    %0, %%edi           \n
            movl    %1, %%esi           \n
            movl    %2, %%ecx           \n
         ORLOOP:                        \n
            movl    (%%esi), %%eax      \n
            orl     %%eax, (%%edi)      \n
            addl    $4, %%esi           \n
            addl    $4, %%edi           \n
            loop    ORLOOP              \n"
            :
            : "m"(dst), "m"(src), "g"(s >> 2)
            : "di", "si", "cx", "ax"
        );
    //int i;
    //for (i = 0; i < s / 4; i++) *((int *)dst)++ |= *((int *)src)++;
}

void cpyfont(void *dst, void *src, size_t s)
{
    asm volatile
        ("  movl    %0, %%edi   \n
            movl    %1, %%esi   \n
            movl    %2, %%ecx   \n
            rep                 \n
            movsl               \n"
            :
            : "m"(dst), "m"(src), "g"(s >> 2)
            : "di", "si", "cx"
        );
    //int i;
    //for (i = 0; i < s / 4; i++) *((int *)dst)++ = *((int *)src)++;
}

void zerosetfont(void *dst, size_t s)
{
    asm volatile
        ("  movl    %0, %%edi   \n
            movl    %1, %%ecx   \n
            movl    $0, %%eax   \n
            rep                 \n
            stosl               \n"
            :
            : "m"(dst),  "g"(s >> 2)
            : "si", "cx", "ax"
        );
    //int i;
    //for (i = 0; i < s / 4; i++) *((int *)dst)++ = 0;
}
