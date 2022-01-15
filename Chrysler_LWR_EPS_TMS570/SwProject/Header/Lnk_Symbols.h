/*****************************************************************************
* Copyright 2010 Nexteer Automotive, All Rights Reserved.
* Nexteer Confidential
*
* Module File Name  : Lnk_Symbols.h
* Module Description: This file contains the declarations of Link Time Symbols
*                     used in the application.
* Product           : Gen II Plus - EA3.0
* Author            : Jeremy Warmbier
*****************************************************************************/
/* Version Control:
 * Date Created:      Wed Apr 13 12:17:00 2011
 * %version:          5 %
 * %derived_by:       jzh87w %
 * %date_modified:    Wed Jan 15 12:18:34 2014 %
 *---------------------------------------------------------------------------------------------------------------------
 * Date      Rev      Author         Change Description                                                        SCR #
 * -------   -------  --------  ---------------------------------------------------------------------------  ----------
 * 04/13/11  1        LWW       Initial K2xx Synergy Version
 * 09/24/11  2        LWW       Added program flash symbols
 * 12/16/11  3        LWW       Added TypeH symbols
 * 12/19/11  4        LWW       Added ECC symbols
 * 10/10/12	'3'		  SAH		Added BootRelNum_Addr
 * 10/10/12	'4'		  BWL		Removed calibration RAM linker symbols
 * 01/15/14	'5'		  SAH		Removed bootloader linker symbol
 */

#ifndef LNK_SYMBOLS_H
#define LNK_SYMBOLS_H

#include "Std_Types.h"
#include <crc_tbl.h>

extern CONST(uint16, AUTOMATIC) Lnk_FlsApiLoadStart;
extern CONST(uint16, AUTOMATIC) Lnk_FlsApiLen;
extern CONST(uint16, AUTOMATIC) Lnk_FlsApiRunStart;


extern CONST(CRC_TABLE, AUTOMATIC) Lnk_ApCrcTbl_Cnt_Str;
extern CONST(CRC_TABLE, AUTOMATIC) Lnk_VecCrcTbl_Cnt_Str;

extern CONST(uint32, AUTOMATIC) Lnk_PrgFlash_Start;
extern CONST(uint32, AUTOMATIC) Lnk_PrgFlashSeg_Length;
extern CONST(uint32, AUTOMATIC) Lnk_PrgFlash_Segments;

extern CONST(uint32, AUTOMATIC) Lnk_TypeH_Start;
extern CONST(uint32, AUTOMATIC) Lnk_TypeH_Size;

extern CONST(uint32, AUTOMATIC) Lnk_BSS_Start;
extern CONST(uint32, AUTOMATIC) Lnk_BSS_End;

#endif

