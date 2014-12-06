/*
 *      File HANERROR.H
 *      Errors
 *      '91.2.5
 *      Written by Lim, I.K.
 */

#ifndef _HANERROR_H_
#define _HANERROR_H_

#ifndef _TYPEDEFS_H_
    #include "typedefs.h"
#endif


/** Macro constants ********************************************************/

#ifndef NOERROR
    #define NOERROR 0   /* No error occured      */
    #define ERROR (-1)  /* Generic error occured */
#endif


/** Type definition ********************************************************/

/* Errors */

typedef enum {
    ERR_NOTDETECTED  = -11,  /* Adapter not detected        */
    ERR_BGINOTLINKED = -12,  /* BGI driver not linked       */
    ERR_BGINOTFOUND  = -13,  /* BGI driver not found        */
    ERR_NOTENOUGHMEM = -14,  /* Super VGA memory not enough */

    ERR_OUTOFRANGE = -21,  /* Out of range    */
    ERR_OUTOFMEM   = -22,  /* Out of memory   */

    ERR_NOTFOUND   = -31,  /* File not found  */
    ERR_WRONGSIZE  = -32,  /* File size wrong */
    ERR_READERROR  = -33,  /* Reading error   */
    ERR_TOPOFSTACK = -34,  /* Top of stack    */
    ERR_STACKOVER  = -35,  /* Stack overflow  */
} error_t;


/** Function declarations **************************************************/

#ifdef __cplusplus
extern "C" {
#endif

/* Error handling */

/*int hgraphresult(void);
char *hgrapherrormsg(int errcode);

void printerr(int status, const char *format, ...);*/

#ifdef __cplusplus
}
#endif


/** External variables *****************************************************/

/* The last error number */

/*extern int _errorcode;*/

#endif
