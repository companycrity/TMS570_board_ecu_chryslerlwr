/*****************************************************************************
* Copyright 2010 Nexteer Automotive, All Rights Reserved.
* Nexteer Confidential
*
* Module File Name  : htu_regs.h
* Module Description: HTU (High End Timer Transfer Unit) Peripheral Registers
* Product           : Gen II Plus - EA3.0
* Author            : Lucas Wendling
*****************************************************************************/
/*---------------------------------------------------------------------------
* Version Control:
* Date Created:      Tue May 31 09:10:25 2011 % 
* %version:          1 %
* %derived_by:       czgng4 %
* %date_modified:    Tue Jun  5 09:52:30 2012 % 
*---------------------------------------------------------------------------*/

#ifndef HTU_REGS_H
#define HTU_REGS_H

/*****************************************************************************
* Include files
*****************************************************************************/
#include "Std_Types.h"

typedef volatile struct htuctrlregs
{
    uint32 GC;					/* 0x00 */
    uint32 CPENA;				/* 0x04 */
    uint32 BUSY0;				/* 0x08 */
    uint32 BUSY1;				/* 0x0C */
    uint32 BUSY2;				/* 0x10 */
    uint32 BUSY3;				/* 0x14 */
	uint32 ACPE;				/* 0x18 */
    uint32 : 32;				/* 0x1C */
    uint32 RLBECTRL;			/* 0x20 */
    uint32 BFINTS;				/* 0x24 */
    uint32 BFINTC;				/* 0x28 */
    uint32 INTMAP;				/* 0x2C */
    uint32 : 32;				/* 0x30 */
    uint32 INTOFF0;				/* 0x34 */
    uint32 INTOFF1;				/* 0x38 */
    uint32 BIM;					/* 0x3C */
    uint32 RLOSTFL;				/* 0x40 */
    uint32 BFINTFL;				/* 0x44 */
    uint32 BERINTFL;			/* 0x48 */
    uint32 MP1S;				/* 0x4C */
    uint32 MP1E;				/* 0x50 */
    uint32 DCTRL;				/* 0x54 */
    uint32 WPR;					/* 0x58 */
    uint32 WMR;					/* 0x5C */
    uint32 ID;					/* 0x60 */
    uint32 PCR;					/* 0x64 */
    uint32 PAR;					/* 0x68 */
    uint32 : 32;				/* 0x6C */
    uint32 MPCS;				/* 0x70 */
    uint32 MP0S;				/* 0x74 */
    uint32 MP0E;				/* 0x78 */
} htuctrlregs_t;

typedef volatile struct htudcp
{
    uint32 IFADDRA;				/* 0x00 */
    uint32 IFADDRB;				/* 0x04 */
    uint32 IHADDRCT;			/* 0x08 */
    uint32 ITCOUNT;				/* 0x0C */
} htudcp_t;

typedef volatile struct htucdcp
{
    uint32 CFADDRA;				/* 0x100 */
    uint32 CFADDRB;				/* 0x104 */
    uint32 CFCOUNT;				/* 0x108 */
} htucdcp_t;

#define htuREG1   ((htuctrlregs_t *)0xFFF7A400U)
#define htuREG2   ((htuctrlregs_t *)0xFFF7A500U)

#define htuDCP1   ((htudcp_t *)0xFF4E0000U)
#define htuDCP2   ((htudcp_t *)0xFF4C0000U)

#define htuCDCP1   ((htucdcp_t *)0xFF4E0100U)
#define htuCDCP2   ((htucdcp_t *)0xFF4C0100U)

#endif
