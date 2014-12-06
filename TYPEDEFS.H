/*
 *      File TYPEDEFS.H
 *      Type Definitions
 *      '92.2.5
 *      Written by Lim, I.K.
 */


#ifndef _TYPEDEFS_H_
#define _TYPEDEFS_H_

#include <stddef.h>
#include <bool.h>
#include "hanerror.h"

/** Macro constants ********************************************************/

#ifndef NOERROR
    #define NOERROR 0     /* No error occured      */
    #define ERROR   (-1)  /* Generic error occured */
#endif

#ifndef NULL
    #define NULL 0
#endif


/** Type definitions *******************************************************/

typedef unsigned char byte;
typedef unsigned word;
typedef unsigned word32;
typedef unsigned short word16;
typedef unsigned short letter;

typedef struct {
        word final   : 5;
        word medial  : 5;
        word initial : 5;
        word flag    : 1;
} hanphoneme_t;

typedef struct {
        byte snd;
        byte fst;
} hanbyte_t;

typedef union {
    unsigned short code;
    hanphoneme_t p;
    hanbyte_t b;
} hancode_t;

#define LOBYTE(b) ((byte)(b))
#define HIBYTE(b) ((word)(b) >> 8)

/*#ifndef _SIZE_T
    #define _SIZE_T
    typedef unsigned size_t;
#endif*/

#endif
