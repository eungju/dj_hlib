/*
 *      File ASCII.H
 *      ASCII Control Codes
 *      '88.10.10
 *      '89.5.20
 *      '90.7.25
 *      '92.2.5
 *      '93.3.15
 *      Written by Lim, I.K.
 */


#ifndef _ASCII_H_
#define _ASCII_H_

#ifndef NUL
    #define NUL '\x00'
#endif
#define SOH '\x01'
#define STX '\x02'
#define ETX '\x03'
#define EOT '\x04'
#define ENQ '\x05'
#define ACK '\x06'
#define BEL '\x07'
#define BS  '\x08'
#define HT  '\x09'
#define LF  '\x0a'
#define VT  '\x0b'
#define FF  '\x0c'
#define CR  '\x0d'
#define SO  '\x0e'
#define SI  '\x0f'
#define DLE '\x10'
#define DC1 '\x11'
#define DC2 '\x12'
#define DC3 '\x13'
#define DC4 '\x14'
#define NAK '\x15'
#define SYN '\x16'
#define ETB '\x17'
#define CAN '\x18'
#define EM  '\x19'
#define SUB '\x1a'
#define ESC '\x1b'
#define FS  '\x1c'
#define GS  '\x1d'
#define RS  '\x1e'
#define US  '\x1f'
#define DEL '\x7f'

#define CTRL_A 0x01
#define CTRL_B 0x02
#define CTRL_C 0x03
#define CTRL_D 0x04
#define CTRL_E 0x05
#define CTRL_F 0x06
#define CTRL_G 0x07
#define CTRL_H 0x08
#define CTRL_I 0x09
#define CTRL_J 0x0a
#define CTRL_K 0x0b
#define CTRL_L 0x0c
#define CTRL_M 0x0d
#define CTRL_N 0x0e
#define CTRL_O 0x0f
#define CTRL_P 0x10
#define CTRL_Q 0x11
#define CTRL_R 0x12
#define CTRL_S 0x13
#define CTRL_T 0x14
#define CTRL_U 0x15
#define CTRL_V 0x16
#define CTRL_W 0x17
#define CTRL_X 0x18
#define CTRL_Y 0x19
#define CTRL_Z 0x1a

#define ENTER CR
#define TAB   HT

#endif
