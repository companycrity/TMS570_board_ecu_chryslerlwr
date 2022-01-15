/*****************************************************************************
* Copyright 2010 Nexteer Automotive, All Rights Reserved.
* Nexteer Confidential
*
* Module File Name  : ResetCause.h
* Module Description: This file contains the definition of the ResetCause variable
* Product           : Gen II Plus EA3.0
* Author            : Lucas Wendling
*****************************************************************************/
/* Version Control:
 * Date Created:      Fri May 11 12:17:00 2012
 * %version:          5 %
 * %derived_by:       nz63rn %
 * %date_modified:    Thu Jun  6 16:27:34 2013 %
 *---------------------------------------------------------------------------------------------------------------------
 * Date      Rev      Author         Change Description                                                        SCR #
 * -------   -------  --------  ---------------------------------------------------------------------------  ----------
 * 06/09/12  1        LWW       Initial Version
 * 07/06/12  2        LWW       Updates for application reset causes
 * 11/13/12  3        LWW       Added MPU violation reset cause
 * 11/29/12  4        LWW       Added different Wdg Reset causes
 * 05/30/13	 5		  KMC		Added FPU exception reset causes
 */

#ifndef RESETCAUSE_H_
#define RESETCAUSE_H_

#include "Platform_Types.h"
#include "Compiler.h"

#define PWRONRESET 				0x0000FFFF
#define DEBUGRESET 				0x0001FFFE
#define CPURESET 				0x0002FFFD
#define SPPBISTFAILED 			0x0003FFFC
#define DPPBISTFAILED 			0x0004FFFB
#define EXTRESET 				0x0005FFFA
#define OSCFAIL 				0x0006FFF9
#define SWRESET 				0x0007FFF8
#define WDGFAIL 				0x0008FFF7
#define CCMSTEFFAILED 			0x0009FFF6
#define CCMSTFAILED 			0x000AFFF5
#define CCMEFFAILED 			0x000BFFF4
#define PBISTSCFAILED 			0x000CFFF3
#define STCSCFAILED 			0x000DFFF2
#define STCFAILED 				0x000EFFF1
#define ESM3NONZERO 			0x000FFFF0
#define EFCSTFAILED 			0x0010FFEF
#define EFCSTUCKZERO 			0x0011FFEE
#define EFCERROR 				0x0012FFED
#define FLSBUS2CORRFAILED 		0x0013FFEC
#define FLSBUS2ADDCAPFAILED 	0x0014FFEB
#define FLSBUS2MULBITDETFAILED 	0x0015FFEA
#define FLSBUS2SNGBITDETFAILED 	0x0016FFE9
#define VIMPARFLGFAILED			0x0017FFE8
#define VIMPARADDERRFAILED		0x0018FFE7
#define VIMPARESMFAILED			0x0019FFE6
#define DCAN1PARESMFAILED		0x001AFFE5
#define DCAN2PARESMFAILED		0x001BFFE4
#define DCAN3PARESMFAILED		0x001CFFE3
#define DMAPARESMFAILED			0x001DFFE2
#define MIBADC1PARESMFAILED		0x001EFFE1
#define MIBADC2PARESMFAILED		0x001FFFE0
#define MIBSPI1PARESMFAILED		0x0020FFDF
#define MIBSPI3PARESMFAILED		0x0021FFDE
#define MIBSPI5PARESMFAILED		0x0022FFDD
#define N2HET1PARESMFAILED		0x0023FFDC
#define N2HET1TUPARESMFAILED	0x0024FFDB
#define N2HET2PARESMFAILED		0x0025FFDA
#define N2HET2TUPARESMFAILED	0x0026FFD9
#define B0MULBITRAMECCDETFAILED	0x0027FFD8
#define B1MULBITRAMECCDETFAILED	0x0028FFD7
#define B0SNGBITRAMECCDETFAILED	0x0029FFD6
#define B1SNGBITRAMECCDETFAILED	0x002AFFD5
#define SNGBITFLSECCDETFAILED	0x002BFFD4
#define MULBITFLSECCDETFAILED	0x002CFFD3
#define LPOTRIMERROR			0x002DFFD2
#define DATAMULBITRAMECCFAILED	0x002EFFD1
#define DATAMULBITFLSECCFAILED	0x002FFFD0
#define CPUDATAABORT			0x0030FFCF
#define CPUPREFETCHABORT		0x0031FFCE
#define PRFTCMULBITRAMECCFAILED	0x0032FFCD
#define PRFTCMULBITFLSECCFAILED	0x0033FFCC
#define UNDEFINST				0x0034FFCB
#define CLOCKMONITOR			0x0035FFCA
#define CCMFAILED				0x0036FFC9
#define FMCUNCORRERR			0x0037FFC8
#define B0UNCORRERR				0x0038FFC7
#define B1UNCORRERR				0x0039FFC6
#define B0ADDPARERR				0x003AFFC5
#define B1ADDPARERR				0x003BFFC4
#define FLSECCLIVELOCK			0x003CFFC3
#define VIMMULTBITFLT			0x003DFFC2
#define VIMPARTHRSHFLT			0x003EFFC1
#define UNUSEDINTERRUPT			0x003FFFC0
#define STACKOVERWRITE			0x0040FFBF
#define MPUVIOLATION			0x0041FFBE
#define WDGALIVEMONFAIL			0x0042FFBD
#define WDGDEADLINEFAIL			0x0043FFBC
#define WDGPROGFLOWFAIL			0x0044FFBB
#define SWWDGFAIL				0x0045FFBA
#define FPUDZCEXCP				0x0046FFB9
#define FPUOFCEXCP				0x0047FFB8
#define FPUIOCEXCP				0x0048FFB7
#define FPUUNKNOWNEXCP			0x0049FFB6


typedef uint32 ENUM_ResetCause;
extern volatile VAR(ENUM_ResetCause, CD_RESETHANDLER_VAR_NOINIT) ResetCause_Cnt_Enum;

#endif /* RESETCAUSE_H_ */
