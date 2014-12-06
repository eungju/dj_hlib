/*
 *      File EGAREGS.H
 *      Define Registers and Their Fields of EGA
 *      '90.7.13
 *      '93.3.6
 *      Written by Lim, I.K.
 */


#ifndef _EGAREGS_H_
#define _EGAREGS_H_


/** General or External Registers(total 4) *********************************/

#define MOR_W      0x03c2  /* Miscellaneous Output Register (Write) */
#define MOR_R      0x03cc  /* Miscellaneous Output Register (Read)  */
#define FCR        0x03da  /* Feature Control Register (Write)      */
#define IS0R       0x03c2  /* Input Status #0 Register (Read)       */
#define IS1R_MONO  0x03ba  /* Input Status #1 Register (Read)       */
#define IS1R_COLOR 0x03da  /* Input Status #1 Register (Read)       */

/* Input/Output Address(IOA) field of Miscellaneous Output Register */

#define IOA_MASK  0x01  /* Mask for IOA field */
#define IOA_MONO  0x00  /* Monochrome emulation, CAR == CAR_MONO */
#define IOA_COLOR 0x01  /* Color emulation, CAR == CAR_COLOR     */


/** Sequencer Registers(total 5) *******************************************/

#define SAR 0x03c4  /* Sequencer Address Register */
#define SDR 0x03c5  /* Sequencer Data Register    */

#define RR   0x00  /* Reset Register                 */
#define CMR  0x01  /* Cloking Mode Register          */
#define MMR  0x02  /* Map Mask Register              */
#define CMSR 0x03  /* Character Map Select Register  */
#define MMDR 0x04  /* Memory Mode Resiter            */

/* Mask Memory Plane(EM0, EM1, EM2, EM3) fields of Map Mask Register */

#define EM_ALLPLANE 0x0f  /* (xxxx1111): EMs = enable all planes */


/** CRT Controller Registers(total 26 in EGA, 24 in VGA) *******************/

#define CAR_MONO  0x03b4  /* CRTC Address Register in monochrome mode */
#define CDR_MONO  0x03b5  /* CRTC Data Register                       */
#define CAR_COLOR 0x03d4  /* CRTC Address Register in color mode      */
#define CDR_COLOR 0x03d5  /* CRTC Data Register                       */

#define HTR  0x00  /* Horizontal Total Register          */
#define HDER 0x01  /* Horizontal Display End Register    */
#define SHBR 0x02  /* Start Horizontal Blanking Register */
#define EHBR 0x03  /* End Horizontal Blanking Register   */
#define SHRR 0x04  /* Start Horizontal Retrace Register  */
#define EHRR 0x05  /* End Horizontal Retrace Register    */
#define VTR  0x06  /* Vertical Total Register            */
#define OFR  0x07  /* Overflow Register                  */
#define PRS  0x08  /* Preset Row Scan Register           */
#define MSLR 0x09  /* Maximum Scan Line Register         */
#define CSR  0x0a  /* Cursor Start Register              */
#define CER  0x0b  /* Cursor End Register                */
#define SAHR 0x0c  /* Start Address High Register        */
#define SALR 0x0d  /* Start Address Low Register         */
#define CLHR 0x0e  /* Cursor Location High Register      */
#define CLLR 0x0f  /* Cursor Location Low Register       */
#define VRSR 0x10  /* Vertical Retrace Start Register    */
#define VRLR 0x11  /* Vertical Retrace End Register      */
#define LPHR 0x10  /* Light Pen High Register (EGA Only) */
#define LPLR 0x11  /* Light Pen Low Register (EGA Only)  */
#define VDER 0x12  /* Vertical Display End Register      */
#define OSR  0x13  /* Offset Register                    */
#define ULR  0x14  /* Underline Location Register        */
#define SVBL 0x15  /* Start Vertical Blank Register      */
#define EVBL 0x16  /* End Vertical Blank Register        */
#define MCR  0x17  /* Mode Control Register              */
#define LCR  0x18  /* Line Compare Register              */


/** Graphics Controller Registers(total 9) *********************************/

#define GAR 0x03ce  /* Graphics Address Register  */
#define GDR 0x03cf  /* Graphics Data Register     */

#define G1PR 0x03cc  /* Graphics #1 Position Register (EGA Only) */
#define G2PR 0x03ca  /* Graphics #2 Position Register (EGA Only) */

#define SRR  0x00  /* Set/Reset Register         */
#define ESRR 0x01  /* Enable Set/Reset Register  */
#define CCR  0x02  /* Color Compare Register     */
#define DRR  0x03  /* Data Rotate Register       */
#define RMSR 0x04  /* Read Map Select Register   */
#define MDR  0x05  /* Mode Register              */
#define MSR  0x06  /* Miscellaneous Register     */
#define CDCR 0x07  /* Color Don't Care Register  */
#define BMR  0x08  /* Bit Mask Register          */

/* Enable Set Reset field of Enable Set/Reset Register */

#define ESR_BITPLANE 0x00  /* (xxxx0000): ESR = bit plane mode       */
                           /*                  (normal writing mode) */
#define ESR_RASTER   0x0f  /* (xxxx1111): ESR = raster mode          */
                           /*                  (Set/Reset mode)      */

/* Rotate Count field of Data Rorate Register */

#define RC_NOTROTATE 0x00  /* (xxxxx000): RC = not right-rotate */

/* Function Select field of Data Rorate Register */

#define FS_UNMOD 0x00  /* (xxx00xxx): FS = data unmodified */
#define FS_AND   0x08  /* (xxx01xxx): FS = AND operation   */
#define FS_OR    0x10  /* (xxx10xxx): FS = OR operation    */
#define FS_XOR   0x18  /* (xxx11xxx): FS = XOR operation   */

/* Read Map Select field of Read Map Select Register */

#define RMS_PLANE0 0x00  /* (xxxxxx00): RMS = bit plane 0 */
#define RMS_PLANE1 0x01  /* (xxxxxx01): RMS = bit plane 1 */
#define RMS_PLANE2 0x02  /* (xxxxxx10): RMS = bit plane 2 */
#define RMS_PLANE3 0x03  /* (xxxxxx11): RMS = bit plane 3 */

/* Write Mode field of Mode Register */

#define WM_MODE0 0x00  /* (xxxxxx00): WM = write mode 0            */
#define WM_MODE1 0x01  /* (xxxxxx01): WM = write mode 1            */
#define WM_MODE2 0x02  /* (xxxxxx10): WM = write mode 2            */
#define WM_MODE3 0x03  /* (xxxxxx11): WM = write mode 3 (VGA only) */

/* Read Mode field of Mode Register */

#define RM_MODE0 0x00  /* (xxxx0xxx): RM = read mode 0 */
#define RM_MODE1 0x08  /* (xxxx1xxx): RM = read mode 1 */

/* Memory Map field of Miscellaneous Register */

#define MM_MASK 0xf3  /* (11110011): Mask for MM field        */
#define MM_MAP0 0x00  /* (xxxx00xx): MM = memory map 0 (128K) */
#define MM_MAP1 0x04  /* (xxxx01xx): MM = memory map 1 (64K)  */

/* Color Don't Care field of Color Don't Care Register */

#define CDC_ALLPLANE 0x0f  /* (xxxx1111): CDC = consider all bits */


/** Attribute Controller Registers(total 20 in EGA, 21 in VGA) *************/

#define AAR   0x03c0  /* Attribute Address Register         */
#define ADR_W 0x03c0  /* Attribute Data Register (Write)    */
#define ADR_R 0x03c1  /* Attribute Data Register (Read)     */

#define PR0  0x00  /* Palette Register 0                */
#define PR1  0x01  /* Palette Register 1                */
#define PR2  0x02  /* Palette Register 2                */
#define PR3  0x03  /* Palette Register 3                */
#define PR4  0x04  /* Palette Register 4                */
#define PR5  0x05  /* Palette Register 5                */
#define PR6  0x06  /* Palette Register 6                */
#define PR7  0x07  /* Palette Register 7                */
#define PR8  0x08  /* Palette Register 8                */
#define PR9  0x09  /* Palette Register 9                */
#define PR10 0x0a  /* Palette Register 10               */
#define PR11 0x0b  /* Palette Register 11               */
#define PR12 0x0c  /* Palette Register 12               */
#define PR13 0x0d  /* Palette Register 13               */
#define PR14 0x0e  /* Palette Register 14               */
#define PR15 0x0f  /* Palette Register 15               */
#define MDCR 0x10  /* Mode Control Register             */
#define OCR  0x11  /* Overscan Color Register           */
#define CPER 0x12  /* Color Plane Enable Register       */
#define HPPR 0x13  /* Horizontal Pixel Panning Register */
#define CSLR 0x14  /* Color Select Register (VGA Only)  */

/* Palette Address Source(PAS) field of Attribute Address Register */

#define AAR_PAS 0x20


/** Color Registers(total 5 in VGA Only) ***********************************/

#define PAWMR 0x03c8  /* PEL Address Write Mode Register        */
#define PARMR 0x03c7  /* PEL Address Read Mode Register (Write) */
#define PDR   0x03c9  /* PEL Data Register                      */
#define DSR   0x03c7  /* DAC State Register (Read)              */
#define PMR   0x03c6  /* PEL Mask Register                      */

/** Function Declarations **************************************************/

/*inline outportw(int port, word val)
{
    __asm__ volatile (
        "outw %0, %1"
        :
        : "a" (val), "d"(port) );
}

inline outport(int port, int index, int val)
{
    __asm__ volatile (
       "outw %0, %1"
        :
        : "a" (val << 8 | index), "d" (port) );
}*/

#endif
