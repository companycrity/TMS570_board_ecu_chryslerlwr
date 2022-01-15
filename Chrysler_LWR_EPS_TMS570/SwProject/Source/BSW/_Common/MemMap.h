/**********************************************************************************************************************
 *  COPYRIGHT
 *  -------------------------------------------------------------------------------------------------------------------
 *  \verbatim
 *  Copyright (c) 2007 by Vector Informatik GmbH.                                              All rights reserved.
 *
 *                Please note, that this file contains example configuration used by the 
 *                MICROSAR BSW. This code may influence the behaviour of the MICROSAR BSW
 *                in principle. Therefore, great care must be taken to verify
 *                the correctness of the implementation.
 *
 *                The contents of the originally delivered files are only examples resp. 
 *                implementation proposals. With regard to the fact that these functions
 *                are meant for demonstration purposes only, Vector Informatik's
 *                liability shall be expressly excluded in cases of ordinary negligence, 
 *                to the extent admissible by law or statute.
 *  \endverbatim
 *  -------------------------------------------------------------------------------------------------------------------
 *  FILE DESCRIPTION
 *  -------------------------------------------------------------------------------------------------------------------
 *         File:  _MemMap.h
 *    Component:  -
 *       Module:  -
 *    Generator:  -
 *
 *  Description:  This File is a template for the MemMap.h
 *                This file has to be extended with the memory section defines for all BSW modules
 *                which where used.
 *
 *  -------------------------------------------------------------------------------------------------------------------
 *  MISRA VIOLATIONS
 *  -------------------------------------------------------------------------------------------------------------------
 *
 *
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  AUTHOR IDENTITY
 *  -------------------------------------------------------------------------------------------------------------------
 *  Name                          Initials      Company
 *  -------------------------------------------------------------------------------------------------------------------
 *  Joachim Kalmbach              Jk            Vector Informatik
 *  -------------------------------------------------------------------------------------------------------------------
 *  REVISION HISTORY
 *  -------------------------------------------------------------------------------------------------------------------
 *  Version   Date        Author  Change Id     Description
 *  -------------------------------------------------------------------------------------------------------------------
 *  01.00.00  2007-08-01  Jk                    Initial creation
 *  01.01.00  2007-12-14  Jk                    Component spesific defines filtering added
 *  01.01.02  2008-11-04  Jk                    Component spesific defines filtering added
 *  01.01.03  2008-12-17  Ht                    Improve list of components  (Tp_AsrTpCan,Tp_AsrTpFr,DrvMcu,DrvIcu added)
 *  01.01.04  2009-04-27  Ht                    improve list of components  (Cp_XcpOnCanAsr, Il_AsrIpduM, If_VxFblDcm,
 *                                              If_VxFblVpm_Volvo_ab, DrvFls added)
 *  01.01.05  2009-04-24  Msr                   Renamed J1939_AsrBase as TpJ1939_AsrBase
 *  01.01.06  2009-06-03  Ht                    Improve list of components (Adc, Dio, Gpt, Pwm, Spi, Wdg, Fls, Port, Fim)
 *  01.02.00  2009-08-01  Ht                    Improve list of components (Fee_30_Inst2, Can, ...Sub)
 *                                              Support filtering for RTE
 *  01.02.01  2009-08-18  HH                    replaced C++ comment by C comment
 *  01.02.02  2009-09-02  Lo                    add external Flash driver support
 *  01.02.03  2009-09-12  Lo                    add DrvFls_Mcs12xFslftm01ExtVx
 *                        Ht                    Improve list of components (CanTrcv_30_Tja1040dio,
 *                                                Eth, EthTrcv, EthIf, SoAd, TcpIp, EthSM)
 *  01.03.00  2009-10-30  Ht                    support R8: change EthTrcv to EthTrcv_30_Canoeemu
 *                                              support EthTrcv_30_Dp83848
 *                                              change CanTrcv_30_Xdio to CanTrcv_30___Your_Trcv__
 *                                              change CanTrcv_30_Tja1040dio to CanTrcv_30_Tja1041
 *                                              change name FrTrcv to FrTrcv_30_Tja1080dio
 *                        Lo                    add Cp_AsrXcp
 *                        Ht                    add Cp_XcpOnFrAsr
 *  01.03.01  2010-01-13  Ht                    support SysService_AsrCal
 *  01.03.02  2010-02-15  Ht                    support SysService_SswRcs_Daimler, SysService_Tls, Tp_Http, 
 *                                                      SysService_Dns, SysService_Json, DrvTrans_GenericLindioAsr
 *                        Lo                    add Diag_AsrDem for all oems
 *                                              rename internal variables and filtermethods
 *  01.04.00  2010-03-04  Ht                    change name FrTrcv_30_Tja1080dio to FrTrcv_30_Tja1080
 *  01.04.01  2010-03-10  Ht                    support DrvTrans_GenericFrAsr, DrvTrans_As8223FrspiAsr, DrvEep and If_AsrIfEa
 *  01.04.02  2010-04-07  Lo                    change IfFee to real components and add If_AsrIfWdV85xNec01Sub
 *  01.04.03  2010-06-11  Ht                    add CanTrcv_30_Tja1043
 *                        Lo                    add Il_AsrIpduMEbBmwSub
 *  01.04.04  2010-08-24  Ht                    add CanTrcv_30_Tle62512G, DrvEep_XAt25128EAsr, Tp_AsrTpFrEbBmwSub
 *  01.05.00  2010-08-24  Ht                    support R10:
 *                                              change LinTrcv_30_Tle7259dio to LinTrcv_30_Tle7259
 *  01.05.01  2010-10-14  Ht                    add VStdLib, SysService_SswScc, SysService_IpBase, SysService_Crypto
 *  01.05.02  2010-10-20  Ht                    support comments for Package Merge Tool
 *  01.05.03  2010-11-03  Ht                    add SysService_E2eLibTttechSub, SysService_E2ePwTttechSub
 *  01.05.04  2010-11-16  Ht                    add SysService_Exi, DrvTrans_Int6400EthAsr, Cdd_AsrCdd_Fiat, Diag_AsrDem_Fiat
 *********************************************************************************************************************
 * Nexteer Change Log
 *********************************************************************************************************************
 * Version Control:
 * Date Created:      Wed Apr 13 10:24:37 2011
 * %version:          EA3#24.1.26.1.16.1.9 %
 * %derived_by:       gz324f %
 * %date_modified:    Mon Mar  12 18:51:36 2012 %
 *---------------------------------------------------------------------------------------------------------------------
 * Date      Rev      Author         Change Description                                                        SCR #
 * -------   -------  --------  ---------------------------------------------------------------------------  ----------
 * 2012-06-12   15      JJW       add defines for SpiNxt and TurnsCounter component
 * 02/22/13		24.1.2	SAH		Added closed section for typeh variables
 * 02/26/13		24.1.3	SAH		Added defines for ADC
 * 02/26/13		24.1.4	SAH		Added defines for PwmCdd
 * 03/01/13     24.1.5  JJW     add defines for updated Gpt integration for priv reg write API support
 * 03/04/13     24.1.6  JJW     add includes for Wdg MemMap files as part of v2.0.x Wdg Stack integration
 *								remove WDGM MemMap statements from this file
 *								add STOP_SEC_CONST_UNSPECIFIED handling to accomadate WdgM MemMap
 * 07/10/13     24.1.26.1.9  JJW     Add mapping for IoHwab10, CalConstants, and ArbLmt
 * 07/18/13		24.1.26.1.13	Mapped resetcause to fixed memory location
 *********************************************************************************************************************/

/**********************************************************************************************************************
 * INCLUDES
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  GLOBAL CONSTANT MACROS
 *********************************************************************************************************************/

#undef MEM_VENDOR_ID
#undef MEM_AR_MAJOR_VERSION
#undef MEM_AR_MINOR_VERSION
#undef MEM_AR_PATCH_VERSION
#undef MEM_SW_MAJOR_VERSION
#undef MEM_SW_MINOR_VERSION
#undef MEM_SW_PATCH_VERSION

#define MEM_VENDOR_ID        (30u)
#define MEM_AR_MAJOR_VERSION (1u)                      /* part of Autosare release 3.0.1 */
#define MEM_AR_MINOR_VERSION (1u)
#define MEM_AR_PATCH_VERSION (0u)

#define MEM_SW_MAJOR_VERSION (1u)
#define MEM_SW_MINOR_VERSION (5u)
#define MEM_SW_PATCH_VERSION (4u)

#define MEMMAP_ERROR

/* Package Merger: Start Section MemMapModuleList */

/* Include these prior to Rte_MemMap, because that file includes Os_MemMap */

#include "Wdg_MemMap.h"
#include "WdgM_MemMap.h"

/* include Rte MemMap because the Rte sections are configuration dependent*/
#include "Rte_MemMap.h"


/**********************************************************************************************************************
 *  Metrics START
 *********************************************************************************************************************/

#ifdef METRICS_START_SEC_VAR_CLEARED_UNSPECIFIED
    #define VAR_SEC_OPEN
	#pragma SET_DATA_SECTION(".osdata")
    #undef METRICS_START_SEC_VAR_CLEARED_UNSPECIFIED
    #undef MEMMAP_ERROR
#endif

#ifdef METRICS_STOP_SEC_VAR_CLEARED_UNSPECIFIED
    #undef METRICS_STOP_SEC_VAR_CLEARED_UNSPECIFIED
    #define STOP_SEC_VAR
#endif


/**********************************************************************************************************************
 *  Metrics END
 *********************************************************************************************************************/
#ifdef WDGRESETHANDLER_START_SEC_VAR_POWER_ON_CLEARED_8
    #undef WDGRESETHANDLER_START_SEC_VAR_POWER_ON_CLEARED_8
    #define START_SEC_VAR_POWER_ON_CLEARED_8_0
#endif
#ifdef WDGRESETHANDLER_STOP_SEC_VAR_POWER_ON_CLEARED_8
    #undef WDGRESETHANDLER_STOP_SEC_VAR_POWER_ON_CLEARED_8
    #define STOP_SEC_VAR
#endif

/**********************************************************************************************************************
 *  AbsHwPosScom START
 *********************************************************************************************************************/

/* Type H Variables */
 #ifdef ABSHWPOSSCOM_START_SEC_VAR_SAVED_ZONEH_32
    #define VAR_SEC_OPEN
	#pragma SET_DATA_SECTION(".ossDataAp_10:noinit:typeH:AbsHwPosScom")
    #undef ABSHWPOSSCOM_START_SEC_VAR_SAVED_ZONEH_32
    #undef MEMMAP_ERROR
#endif

#ifdef ABSHWPOSSCOM_STOP_SEC_VAR_SAVED_ZONEH_32
    #undef ABSHWPOSSCOM_STOP_SEC_VAR_SAVED_ZONEH_32
    #define STOP_SEC_VAR
#endif

/* Variables */
#ifdef ABSHWPOSSCOM_START_SEC_VAR_CLEARED_32
    #undef ABSHWPOSSCOM_START_SEC_VAR_CLEARED_32
    #define START_SEC_VAR_NOINIT_32_10
#endif

#ifdef ABSHWPOSSCOM_STOP_SEC_VAR_CLEARED_32
    #undef ABSHWPOSSCOM_STOP_SEC_VAR_CLEARED_32
    #define STOP_SEC_VAR
#endif

#ifdef ABSHWPOSSCOM_START_SEC_VAR_CLEARED_16
    #undef ABSHWPOSSCOM_START_SEC_VAR_CLEARED_16
    #define START_SEC_VAR_NOINIT_16_10
#endif

#ifdef ABSHWPOSSCOM_STOP_SEC_VAR_CLEARED_16
    #undef ABSHWPOSSCOM_STOP_SEC_VAR_CLEARED_16
    #define STOP_SEC_VAR
#endif

#ifdef ABSHWPOSSCOM_START_SEC_VAR_CLEARED_BOOLEAN
    #undef ABSHWPOSSCOM_START_SEC_VAR_CLEARED_BOOLEAN
    #define START_SEC_VAR_NOINIT_UNSPECIFIED_10
#endif

#ifdef ABSHWPOSSCOM_STOP_SEC_VAR_CLEARED_BOOLEAN
    #undef ABSHWPOSSCOM_STOP_SEC_VAR_CLEARED_BOOLEAN
    #define STOP_SEC_VAR
#endif

#ifdef ABSHWPOSSCOM_START_SEC_VAR_CLEARED_UNSPECIFIED
    #undef ABSHWPOSSCOM_START_SEC_VAR_CLEARED_UNSPECIFIED
    #define START_SEC_VAR_NOINIT_UNSPECIFIED_10
#endif

#ifdef ABSHWPOSSCOM_STOP_SEC_VAR_CLEARED__UNSPECIFIED
    #undef ABSHWPOSSCOM_STOP_SEC_VAR_CLEARED__UNSPECIFIED
    #define STOP_SEC_VAR
#endif
/**********************************************************************************************************************
 *  AbsHwPosScom END
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  ActivePull START
 *********************************************************************************************************************/
/* Type H Variables */
 #ifdef ACTIVEPULL_START_SEC_VAR_SAVED_ZONEH_32
    #define VAR_SEC_OPEN
	#pragma SET_DATA_SECTION(".ossDataAp_9:noinit:typeH:ActivePull")
    #undef ACTIVEPULL_START_SEC_VAR_SAVED_ZONEH_32
    #undef MEMMAP_ERROR
#endif

#ifdef ACTIVEPULL_STOP_SEC_VAR_SAVED_ZONEH_32
    #undef ACTIVEPULL_STOP_SEC_VAR_SAVED_ZONEH_32
    #define STOP_SEC_VAR
#endif

/* VAR sections */

#ifdef ACTIVEPULL_START_SEC_VAR_CLEARED_32
	# undef ACTIVEPULL_START_SEC_VAR_CLEARED_32
	# define START_SEC_VAR_NOINIT_32_9
#endif
#ifdef ACTIVEPULL_STOP_SEC_VAR_CLEARED_32
	# undef ACTIVEPULL_STOP_SEC_VAR_CLEARED_32
	# define STOP_SEC_VAR
#endif

#ifdef ACTIVEPULL_START_SEC_VAR_CLEARED_16
    #undef ACTIVEPULL_START_SEC_VAR_CLEARED_16
    #define START_SEC_VAR_NOINIT_16_9
#endif

#ifdef ACTIVEPULL_STOP_SEC_VAR_CLEARED_16
    #undef ACTIVEPULL_STOP_SEC_VAR_CLEARED_16
    #define STOP_SEC_VAR
#endif

#ifdef ACTIVEPULL_START_SEC_VAR_CLEARED_BOOLEAN
    #undef ACTIVEPULL_START_SEC_VAR_CLEARED_BOOLEAN
    #define START_SEC_VAR_NOINIT_UNSPECIFIED_9
#endif

#ifdef ACTIVEPULL_STOP_SEC_VAR_CLEARED_BOOLEAN
    #undef ACTIVEPULL_STOP_SEC_VAR_CLEARED_BOOLEAN
    #define STOP_SEC_VAR
#endif

#ifdef ACTIVEPULL_START_SEC_VAR_CLEARED_UNSPECIFIED
	# undef ACTIVEPULL_START_SEC_VAR_CLEARED_UNSPECIFIED
	# define START_SEC_VAR_NOINIT_UNSPECIFIED_9
#endif
#ifdef ACTIVEPULL_STOP_SEC_VAR_CLEARED_UNSPECIFIED
	# undef ACTIVEPULL_STOP_SEC_VAR_CLEARED_UNSPECIFIED
	# define STOP_SEC_VAR
#endif

/**********************************************************************************************************************
 *  ActivePull END
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  Adc START
 *********************************************************************************************************************/

/*******  CODE sections *******/

#ifdef ADC_START_SEC_CODE
    #undef ADC_START_SEC_CODE
    #define START_SEC_CODE
#endif

#ifdef ADC_STOP_SEC_CODE
    #undef ADC_STOP_SEC_CODE
    #define STOP_SEC_CODE
#endif

#ifdef ADC2_START_SEC_CODE
    #undef ADC2_START_SEC_CODE
    #define START_SEC_CODE
#endif

#ifdef ADC2_STOP_SEC_CODE
    #undef ADC2_STOP_SEC_CODE
    #define STOP_SEC_CODE
#endif

/*******  CONST sections  *******/

#ifdef ADC_START_SEC_CONST_32
    #undef ADC_START_SEC_CONST_32
    #define START_SEC_CONST_32BIT
#endif

#ifdef ADC_STOP_SEC_CONST_32
    #undef ADC_STOP_SEC_CONST_32
    #define STOP_SEC_CONST
#endif

#ifdef ADC2_START_SEC_CONST_32
    #undef ADC2_START_SEC_CONST_32
    #define START_SEC_CONST_32BIT
#endif

#ifdef ADC2_STOP_SEC_CONST_32
    #undef ADC2_STOP_SEC_CONST_32
    #define STOP_SEC_CONST
#endif

/**********************************************************************************************************************
 *  Adc END
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  ArbLmt START
 *********************************************************************************************************************/
/* VAR sections */
#ifdef ARBLMT_START_SEC_VAR_CLEARED_BOOLEAN
	# undef ARBLMT_START_SEC_VAR_CLEARED_BOOLEAN
	# define START_SEC_VAR_CLEARED_BOOLEAN_10
#endif
#ifdef ARBLMT_STOP_SEC_VAR_CLEARED_BOOLEAN
	# undef ARBLMT_STOP_SEC_VAR_CLEARED_BOOLEAN
	# define STOP_SEC_VAR
#endif

#ifdef ARBLMT_START_SEC_VAR_CLEARED_32
	# undef ARBLMT_START_SEC_VAR_CLEARED_32
	# define START_SEC_VAR_CLEARED_32_10
#endif
#ifdef ARBLMT_STOP_SEC_VAR_CLEARED_32
	# undef ARBLMT_STOP_SEC_VAR_CLEARED_32
	# define STOP_SEC_VAR
#endif

#ifdef ARBLMT_START_SEC_VAR_CLEARED_UNSPECIFIED
	# undef ARBLMT_START_SEC_VAR_CLEARED_UNSPECIFIED
	# define START_SEC_VAR_CLEARED_UNSPECIFIED_10
#endif

#ifdef ARBLMT_STOP_SEC_VAR_CLEARED_UNSPECIFIED
	# undef ARBLMT_STOP_SEC_VAR_CLEARED_UNSPECIFIED
	# define STOP_SEC_VAR
#endif

/**********************************************************************************************************************
 *  ArbLmt END
 *********************************************************************************************************************/

 /**********************************************************************************************************************
 *  Assist START
 *********************************************************************************************************************/

#ifdef ASSIST_START_SEC_VAR_CLEARED_16
    #undef ASSIST_START_SEC_VAR_CLEARED_16
    #define START_SEC_VAR_NOINIT_16_10
#endif

#ifdef ASSIST_STOP_SEC_VAR_CLEARED_16
    #undef ASSIST_STOP_SEC_VAR_CLEARED_16
    #define STOP_SEC_VAR
#endif

/**********************************************************************************************************************
 *  Assist END
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  AssistFirewall START
 *********************************************************************************************************************/
/* Variables */
#ifdef ASSISTFIREWALL_START_SEC_VAR_CLEARED_16
    #undef ASSISTFIREWALL_START_SEC_VAR_CLEARED_16
    #define START_SEC_VAR_NOINIT_16_10
#endif

#ifdef ASSISTFIREWALL_STOP_SEC_VAR_CLEARED_16
    #undef ASSISTFIREWALL_STOP_SEC_VAR_CLEARED_16
    #define STOP_SEC_VAR
#endif

#ifdef ASSISTFIREWALL_START_SEC_VAR_CLEARED_32
    #undef ASSISTFIREWALL_START_SEC_VAR_CLEARED_32
    #define START_SEC_VAR_NOINIT_32_10
#endif

#ifdef ASSISTFIREWALL_STOP_SEC_VAR_CLEARED_32
    #undef ASSISTFIREWALL_STOP_SEC_VAR_CLEARED_32
    #define STOP_SEC_VAR
#endif

#ifdef ASSISTFIREWALL_START_SEC_VAR_CLEARED_UNSPECIFIED
    #undef ASSISTFIREWALL_START_SEC_VAR_CLEARED_UNSPECIFIED
    #define START_SEC_VAR_NOINIT_UNSPECIFIED_10
#endif

#ifdef ASSISTFIREWALL_STOP_SEC_VAR_CLEARED_UNSPECIFIED
    #undef ASSISTFIREWALL_STOP_SEC_VAR_CLEARED_UNSPECIFIED
    #define STOP_SEC_VAR
#endif

#ifdef ASSISTFIREWALL_START_SEC_VAR_CLEARED_BOOLEAN
    #undef ASSISTFIREWALL_START_SEC_VAR_CLEARED_BOOLEAN
    #define START_SEC_VAR_NOINIT_UNSPECIFIED_10
#endif

#ifdef ASSISTFIREWALL_STOP_SEC_VAR_CLEARED_BOOLEAN
    #undef ASSISTFIREWALL_STOP_SEC_VAR_CLEARED_BOOLEAN
    #define STOP_SEC_VAR
#endif

/**********************************************************************************************************************
 *  AssistFirewall END
 *********************************************************************************************************************/

/**********************************************************************************************************************
*  AstLmt START
*********************************************************************************************************************/

#ifdef ASTLMT_START_SEC_VAR_CLEARED_32
    #undef ASTLMT_START_SEC_VAR_CLEARED_32
    #define START_SEC_VAR_CLEARED_32_GLOBALSHARED /*Changed to global shared for manual trq cmd over XCP test */
#endif

#ifdef ASTLMT_STOP_SEC_VAR_CLEARED_32
    #undef ASTLMT_STOP_SEC_VAR_CLEARED_32
    #define STOP_SEC_VAR
#endif

#ifdef ASTLMT_START_SEC_VAR_CLEARED_BOOLEAN
    #undef ASTLMT_START_SEC_VAR_CLEARED_BOOLEAN
    #define START_SEC_VAR_CLEARED_BOOLEAN_GLOBALSHARED
#endif

#ifdef ASTLMT_STOP_SEC_VAR_CLEARED_BOOLEAN
    #undef ASTLMT_STOP_SEC_VAR_CLEARED_BOOLEAN
    #define STOP_SEC_VAR
#endif

/**********************************************************************************************************************
 *  AstLmt END
 *********************************************************************************************************************/

 /**********************************************************************************************************************
 *  Atan2_NxtrLib START
 *********************************************************************************************************************/

#ifdef ATAN2_START_SEC_VAR_INIT_32
    #undef ATAN2_START_SEC_VAR_INIT_32
    #define START_SEC_VAR_INIT_32_10
#endif

#ifdef ATAN2_STOP_SEC_VAR_INIT_32
    #undef ATAN2_STOP_SEC_VAR_INIT_32
    #define STOP_SEC_VAR
#endif

/**********************************************************************************************************************
 *  Atan2_NxtrLib END
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  AvgFricLrn START
 *********************************************************************************************************************/
/* Variables */
#ifdef AVGFRICLRN_START_SEC_VAR_CLEARED_32
    #undef AVGFRICLRN_START_SEC_VAR_CLEARED_32
    #define START_SEC_VAR_NOINIT_32_9
#endif

#ifdef AVGFRICLRN_STOP_SEC_VAR_CLEARED_32
    #undef AVGFRICLRN_STOP_SEC_VAR_CLEARED_32
    #define STOP_SEC_VAR
#endif

#ifdef AVGFRICLRN_START_SEC_VAR_CLEARED_BOOLEAN
    #undef AVGFRICLRN_START_SEC_VAR_CLEARED_BOOLEAN
    #define START_SEC_VAR_NOINIT_8_9
#endif

#ifdef AVGFRICLRN_STOP_SEC_VAR_CLEARED_BOOLEAN
    #undef AVGFRICLRN_STOP_SEC_VAR_CLEARED_BOOLEAN
    #define STOP_SEC_VAR
#endif

#ifdef AVGFRICLRN_START_SEC_VAR_CLEARED_UNSPECIFIED
    #undef AVGFRICLRN_START_SEC_VAR_CLEARED_UNSPECIFIED
    #define START_SEC_VAR_NOINIT_UNSPECIFIED_9
#endif

#ifdef AVGFRICLRN_STOP_SEC_VAR_CLEARED_UNSPECIFIED
    #undef AVGFRICLRN_STOP_SEC_VAR_CLEARED_UNSPECIFIED
    #define STOP_SEC_VAR
#endif

/**********************************************************************************************************************
 *  AvgFricLrn END
 *********************************************************************************************************************/

/**********************************************************************************************************************
*  Battery Voltage START
*********************************************************************************************************************/

#ifdef BATTERYVOLTAGE_START_SEC_VAR_CLEARED_32
    #undef BATTERYVOLTAGE_START_SEC_VAR_CLEARED_32
    #define START_SEC_VAR_NOINIT_32_9
#endif

#ifdef BATTERYVOLTAGE_STOP_SEC_VAR_CLEARED_32
    #undef BATTERYVOLTAGE_STOP_SEC_VAR_CLEARED_32
    #define STOP_SEC_VAR
#endif

#ifdef BATTERYVOLTAGE_START_SEC_VAR_CLEARED_16
    #undef BATTERYVOLTAGE_START_SEC_VAR_CLEARED_16
    #define START_SEC_VAR_NOINIT_16_9
#endif

#ifdef BATTERYVOLTAGE_STOP_SEC_VAR_CLEARED_16
    #undef BATTERYVOLTAGE_STOP_SEC_VAR_CLEARED_16
    #define STOP_SEC_VAR
#endif

#ifdef BATTERYVOLTAGE_START_SEC_VAR_CLEARED_BOOLEAN
    #undef BATTERYVOLTAGE_START_SEC_VAR_CLEARED_BOOLEAN
    #define START_SEC_VAR_NOINIT_8_9
#endif

#ifdef BATTERYVOLTAGE_STOP_SEC_VAR_CLEARED_BOOLEAN
    #undef BATTERYVOLTAGE_STOP_SEC_VAR_CLEARED_BOOLEAN
    #define STOP_SEC_VAR
#endif

/**********************************************************************************************************************
 *  Battery Voltage END
 *********************************************************************************************************************/

/**********************************************************************************************************************
*  BkCpPc START
*********************************************************************************************************************/

#ifdef BKCPPC_START_SEC_VAR_CLEARED_32
    #undef BKCPPC_START_SEC_VAR_CLEARED_32
    #define START_SEC_VAR_CLEARED_32_9
#endif

#ifdef BKCPPC_STOP_SEC_VAR_CLEARED_32
    #undef BKCPPC_STOP_SEC_VAR_CLEARED_32
    #define STOP_SEC_VAR
#endif

#ifdef BKCPPC_START_SEC_VAR_CLEARED_16
    #undef BKCPPC_START_SEC_VAR_CLEARED_16
    #define START_SEC_VAR_CLEARED_16_9
#endif

#ifdef BKCPPC_STOP_SEC_VAR_CLEARED_16
    #undef BKCPPC_STOP_SEC_VAR_CLEARED_16
    #define STOP_SEC_VAR
#endif

#ifdef BKCPPC_START_SEC_VAR_CLEARED_UNSPECIFIED
    #undef BKCPPC_START_SEC_VAR_CLEARED_UNSPECIFIED
    #define START_SEC_VAR_CLEARED_UNSPECIFIED_9
#endif

#ifdef BKCPPC_STOP_SEC_VAR_CLEARED_UNSPECIFIED
    #undef BKCPPC_STOP_SEC_VAR_CLEARED_UNSPECIFIED
    #define STOP_SEC_VAR
#endif

/**********************************************************************************************************************
 *  BkCpPc END
 *********************************************************************************************************************/


/**********************************************************************************************************************
*  BVDiag START
*********************************************************************************************************************/

#ifdef BVDIAG_START_SEC_VAR_CLEARED_32
    #undef BVDIAG_START_SEC_VAR_CLEARED_32
    #define START_SEC_VAR_NOINIT_32_9
#endif

#ifdef BVDIAG_STOP_SEC_VAR_CLEARED_32
    #undef BVDIAG_STOP_SEC_VAR_CLEARED_32
    #define STOP_SEC_VAR
#endif

/**********************************************************************************************************************
 *  BVDiag END
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  CalConstants START
 *********************************************************************************************************************/

#ifdef CALCONSTANTS_START_SEC_VAR_NOINIT_UNSPECIFIED
    #undef CALCONSTANTS_START_SEC_VAR_NOINIT_UNSPECIFIED
    #define START_SEC_VAR_NOINIT_UNSPECIFIED_10
#endif

#ifdef CALCONSTANTS_STOP_SEC_VAR_NOINIT_UNSPECIFIED
    #undef CALCONSTANTS_STOP_SEC_VAR_NOINIT_UNSPECIFIED
    #define STOP_SEC_VAR
#endif

/**********************************************************************************************************************
 *  CalConstants EMD
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  CDDInterface START
 *********************************************************************************************************************/
/* Variables */
  /*CDDDATA9 START*/
#ifdef CDDDATA9_START_SEC_VAR_NOINIT_32
    #undef CDDDATA9_START_SEC_VAR_NOINIT_32
    #define START_SEC_VAR_NOINIT_32_9

#elif defined CDDDATA9_STOP_SEC_VAR_NOINIT_32
    #undef CDDDATA9_STOP_SEC_VAR_NOINIT_32
    #define STOP_SEC_VAR

#elif defined CDDDATA9_START_SEC_VAR_NOINIT_16
    #undef CDDDATA9_START_SEC_VAR_NOINIT_16
    #define START_SEC_VAR_NOINIT_16_9

#elif defined CDDDATA9_STOP_SEC_VAR_NOINIT_16
    #undef CDDDATA9_STOP_SEC_VAR_NOINIT_16
    #define STOP_SEC_VAR

#elif defined CDDDATA9_START_SEC_VAR_NOINIT_BOOLEAN
    #undef CDDDATA9_START_SEC_VAR_NOINIT_BOOLEAN
    #define START_SEC_VAR_NOINIT_BOOLEAN_9

#elif defined CDDDATA9_STOP_SEC_VAR_NOINIT_BOOLEAN
    #undef CDDDATA9_STOP_SEC_VAR_NOINIT_BOOLEAN
    #define STOP_SEC_VAR
#endif
  /*CDDDATA10 START*/
#ifdef CDDDATA10_START_SEC_VAR_NOINIT_32
    #undef CDDDATA10_START_SEC_VAR_NOINIT_32
    #define START_SEC_VAR_NOINIT_32_10

#elif defined CDDDATA10_STOP_SEC_VAR_NOINIT_32
    #undef CDDDATA10_STOP_SEC_VAR_NOINIT_32
    #define STOP_SEC_VAR

#elif defined CDDDATA10_START_SEC_VAR_NOINIT_16
    #undef CDDDATA10_START_SEC_VAR_NOINIT_16
    #define START_SEC_VAR_NOINIT_16_10

#elif defined CDDDATA10_STOP_SEC_VAR_NOINIT_16
    #undef CDDDATA10_STOP_SEC_VAR_NOINIT_16
    #define STOP_SEC_VAR

#elif defined CDDDATA10_START_SEC_VAR_NOINIT_BOOLEAN
    #undef CDDDATA10_START_SEC_VAR_NOINIT_BOOLEAN
    #define START_SEC_VAR_NOINIT_BOOLEAN_10

#elif defined CDDDATA10_STOP_SEC_VAR_NOINIT_BOOLEAN
    #undef CDDDATA10_STOP_SEC_VAR_NOINIT_BOOLEAN
    #define STOP_SEC_VAR
#endif
  /* CDDInterface Internal Variables Start */
#ifdef CDDINTERFACE_START_SEC_VAR_NOINIT_32
    #undef CDDINTERFACE_START_SEC_VAR_NOINIT_32
    #define START_SEC_VAR_CLEARED_32_10
#endif

#ifdef CDDINTERFACE_STOP_SEC_VAR_NOINIT_32
    #undef CDDINTERFACE_STOP_SEC_VAR_NOINIT_32
    #define STOP_SEC_VAR
#endif

#ifdef CDDINTERFACE_START_SEC_VAR_CLEARED_8
    #undef CDDINTERFACE_START_SEC_VAR_CLEARED_8
    #define START_SEC_VAR_NOINIT_8_10
#endif

#ifdef CDDINTERFACE_STOP_SEC_VAR_CLEARED_8
    #undef CDDINTERFACE_STOP_SEC_VAR_CLEARED_8
    #define STOP_SEC_VAR
#endif
/**********************************************************************************************************************
 *  CDDInterface END
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  CmMtrCurr START
 *********************************************************************************************************************/
/* Variables */
#ifdef CMMTRCURR_START_SEC_VAR_CLEARED_16
    #undef CMMTRCURR_START_SEC_VAR_CLEARED_16
    #define START_SEC_VAR_NOINIT_16_10
#endif

#ifdef CMMTRCURR_STOP_SEC_VAR_CLEARED_16
    #undef CMMTRCURR_STOP_SEC_VAR_CLEARED_16
    #define STOP_SEC_VAR
#endif

#ifdef CMMTRCURR_START_SEC_VAR_CLEARED_32
    #undef CMMTRCURR_START_SEC_VAR_CLEARED_32
    #define START_SEC_VAR_NOINIT_32_10
#endif

#ifdef CMMTRCURR_STOP_SEC_VAR_CLEARED_32
    #undef CMMTRCURR_STOP_SEC_VAR_CLEARED_32
    #define STOP_SEC_VAR
#endif

#ifdef CMMTRCURR_START_SEC_VAR_CLEARED_BOOLEAN
    #undef CMMTRCURR_START_SEC_VAR_CLEARED_BOOLEAN
    #define START_SEC_VAR_NOINIT_8_10
#endif

#ifdef CMMTRCURR_STOP_SEC_VAR_CLEARED_BOOLEAN
    #undef CMMTRCURR_STOP_SEC_VAR_CLEARED_BOOLEAN
    #define STOP_SEC_VAR
#endif

#ifdef CMMTRCURR_START_SEC_VAR_CLEARED_UNSPECIFIED
    #undef CMMTRCURR_START_SEC_VAR_CLEARED_UNSPECIFIED
    #define START_SEC_VAR_NOINIT_UNSPECIFIED_10
#endif

#ifdef CMMTRCURR_STOP_SEC_VAR_CLEARED_UNSPECIFIED
    #undef CMMTRCURR_STOP_SEC_VAR_CLEARED_UNSPECIFIED
    #define STOP_SEC_VAR
#endif

/**********************************************************************************************************************
 *  CmMtrCurr END
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  CtrldDisShtdn START
 *********************************************************************************************************************/
/* Variables */
#ifdef CTRLDDISSHTDN_START_SEC_VAR_CLEARED_16
    #undef CTRLDDISSHTDN_START_SEC_VAR_CLEARED_16
    #define START_SEC_VAR_NOINIT_16_10
#endif

#ifdef CTRLDDISSHTDN_STOP_SEC_VAR_CLEARED_16
    #undef CTRLDDISSHTDN_STOP_SEC_VAR_CLEARED_16
    #define STOP_SEC_VAR
#endif

#ifdef CTRLDDISSHTDN_START_SEC_VAR_CLEARED_32
    #undef CTRLDDISSHTDN_START_SEC_VAR_CLEARED_32
    #define START_SEC_VAR_NOINIT_32_10
#endif

#ifdef CTRLDDISSHTDN_STOP_SEC_VAR_CLEARED_32
    #undef CTRLDDISSHTDN_STOP_SEC_VAR_CLEARED_32
    #define STOP_SEC_VAR
#endif

/**********************************************************************************************************************
 *  CtrldDisShtdn END
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  CtrlTemp START
 *********************************************************************************************************************/
/* Variables */

#ifdef CTRLTEMP_START_SEC_VAR_CLEARED_32
    #undef CTRLTEMP_START_SEC_VAR_CLEARED_32
    #define START_SEC_VAR_NOINIT_32_9
#endif

#ifdef CTRLTEMP_STOP_SEC_VAR_CLEARED_32
    #undef CTRLTEMP_STOP_SEC_VAR_CLEARED_32
    #define STOP_SEC_VAR
#endif

#ifdef CTRLTEMP_START_SEC_VAR_CLEARED_16
    #undef CTRLTEMP_START_SEC_VAR_CLEARED_16
    #define START_SEC_VAR_NOINIT_16_9
#endif

#ifdef CTRLTEMP_STOP_SEC_VAR_CLEARED_16
    #undef CTRLTEMP_STOP_SEC_VAR_CLEARED_16
    #define STOP_SEC_VAR
#endif

#ifdef CTRLTEMP_START_SEC_VAR_CLEARED_UNSPECIFIED
    #undef CTRLTEMP_START_SEC_VAR_CLEARED_UNSPECIFIED
    #define START_SEC_VAR_NOINIT_UNSPECIFIED_9
#endif

#ifdef CTRLTEMP_STOP_SEC_VAR_CLEARED_UNSPECIFIED
    #undef CTRLTEMP_STOP_SEC_VAR_CLEARED_UNSPECIFIED
    #define STOP_SEC_VAR
#endif

/**********************************************************************************************************************
 *  CtrlTemp END
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  CurrCmd START
 *********************************************************************************************************************/
/* Variables */
#ifdef CURRCMD_START_SEC_VAR_CLEARED_32
    #undef CURRCMD_START_SEC_VAR_CLEARED_32
    #define START_SEC_VAR_NOINIT_32_10
#endif

#ifdef CURRCMD_STOP_SEC_VAR_CLEARED_32
    #undef CURRCMD_STOP_SEC_VAR_CLEARED_32
    #define STOP_SEC_VAR
#endif

#ifdef CURRCMD_START_SEC_VAR_CLEARED_16
    #undef CURRCMD_START_SEC_VAR_CLEARED_16
    #define START_SEC_VAR_NOINIT_16_10
#endif

#ifdef CURRCMD_STOP_SEC_VAR_CLEARED_16
    #undef CURRCMD_STOP_SEC_VAR_CLEARED_16
    #define STOP_SEC_VAR
#endif

/**********************************************************************************************************************
 *  CurrCmd END
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  CurrParamComp START
 *********************************************************************************************************************/
/* Variables */
#ifdef CURRPARAMCOMP_START_SEC_VAR_CLEARED_32
    #undef CURRPARAMCOMP_START_SEC_VAR_CLEARED_32
    #define START_SEC_VAR_NOINIT_32_10
#endif

#ifdef CURRPARAMCOMP_STOP_SEC_VAR_CLEARED_32
    #undef CURRPARAMCOMP_STOP_SEC_VAR_CLEARED_32
    #define STOP_SEC_VAR
#endif

/**********************************************************************************************************************
 *  CurrParamComp END
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  Damping START
 *********************************************************************************************************************/
/* Variables */
#ifdef DAMPING_START_SEC_VAR_CLEARED_16
    #undef DAMPING_START_SEC_VAR_CLEARED_16
    #define START_SEC_VAR_NOINIT_16_10
#endif

#ifdef DAMPING_STOP_SEC_VAR_CLEARED_16
    #undef DAMPING_STOP_SEC_VAR_CLEARED_16
    #define STOP_SEC_VAR
#endif

#ifdef DAMPING_START_SEC_VAR_CLEARED_32
    #undef DAMPING_START_SEC_VAR_CLEARED_32
    #define START_SEC_VAR_NOINIT_32_10
#endif

#ifdef DAMPING_STOP_SEC_VAR_CLEARED_32
    #undef DAMPING_STOP_SEC_VAR_CLEARED_32
    #define STOP_SEC_VAR
#endif

#ifdef DAMPING_START_SEC_VAR_CLEARED_UNSPECIFIED
    #undef DAMPING_START_SEC_VAR_CLEARED_UNSPECIFIED
    #define START_SEC_VAR_NOINIT_UNSPECIFIED_10
#endif

#ifdef DAMPING_STOP_SEC_VAR_CLEARED_UNSPECIFIED
    #undef DAMPING_STOP_SEC_VAR_CLEARED_UNSPECIFIED
    #define STOP_SEC_VAR
#endif

/**********************************************************************************************************************
 *  Damping END
 *********************************************************************************************************************/

 /**********************************************************************************************************************
 *  DampingFirewall START
 *********************************************************************************************************************/

/* Variables */
#ifdef DAMPINGFIREWALL_START_SEC_VAR_CLEARED_32
    #undef DAMPINGFIREWALL_START_SEC_VAR_CLEARED_32
    #define START_SEC_VAR_NOINIT_32_10
#endif

#ifdef DAMPINGFIREWALL_STOP_SEC_VAR_CLEARED_32
    #undef DAMPINGFIREWALL_STOP_SEC_VAR_CLEARED_32
    #define STOP_SEC_VAR
#endif

#ifdef DAMPINGFIREWALL_START_SEC_VAR_CLEARED_16
    #undef DAMPINGFIREWALL_START_SEC_VAR_CLEARED_16
    #define START_SEC_VAR_NOINIT_16_10
#endif

#ifdef DAMPINGFIREWALL_STOP_SEC_VAR_CLEARED_16
    #undef DAMPINGFIREWALL_STOP_SEC_VAR_CLEARED_16
    #define STOP_SEC_VAR
#endif

#ifdef DAMPINGFIREWALL_START_SEC_VAR_CLEARED_UNSPECIFIED
    #undef DAMPINGFIREWALL_START_SEC_VAR_CLEARED_UNSPECIFIED
    #define START_SEC_VAR_NOINIT_UNSPECIFIED_10
#endif

#ifdef DAMPINGFIREWALL_STOP_SEC_VAR_CLEARED_UNSPECIFIED
    #undef DAMPINGFIREWALL_STOP_SEC_VAR_CLEARED_UNSPECIFIED
    #define STOP_SEC_VAR
#endif

#ifdef DAMPINGFIREWALL_START_SEC_VAR_CLEARED_BOOLEAN
    #undef DAMPINGFIREWALL_START_SEC_VAR_CLEARED_BOOLEAN
    #define START_SEC_VAR_NOINIT_UNSPECIFIED_10
#endif

#ifdef DAMPINGFIREWALL_STOP_SEC_VAR_CLEARED_BOOLEAN
    #undef DAMPINGFIREWALL_STOP_SEC_VAR_CLEARED_BOOLEAN
    #define STOP_SEC_VAR
#endif
/**********************************************************************************************************************
 *  DampingFirewall END
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  DiagMgr START
 *********************************************************************************************************************/
/* VAR section */
#ifdef DIAGMGR_START_SEC_VAR_SAVED_ZONEHGS_UNSPECIFIED
    #define VAR_SEC_OPEN
	#pragma SET_DATA_SECTION(".ossGlobalShared:noinit")
	#undef DIAGMGR_START_SEC_VAR_SAVED_ZONEHGS_UNSPECIFIED
	#undef MEMMAP_ERROR
#endif

#ifdef DIAGMGR_STOP_SEC_VAR_SAVED_ZONEHGS_UNSPECIFIED
    #undef DIAGMGR_STOP_SEC_VAR_SAVED_ZONEHGS_UNSPECIFIED
    #define STOP_SEC_VAR
#endif

#ifdef DIAGMGR_START_SEC_VAR_CLEARED_BOOLEAN
    #undef DIAGMGR_START_SEC_VAR_CLEARED_BOOLEAN
    #define START_SEC_VAR_CLEARED_8_GLOBALSHARED
#endif

#ifdef DIAGMGR_STOP_SEC_VAR_CLEARED_BOOLEAN
    #undef DIAGMGR_STOP_SEC_VAR_CLEARED_BOOLEAN
    #define STOP_SEC_VAR
#endif

/* CONST section */
#ifdef DIAGMGR_START_SEC_CONST_UNSPECIFIED
	#undef DIAGMGR_START_SEC_CONST_UNSPECIFIED
	#undef MEMMAP_ERROR
#endif

#ifdef DIAGMGR_STOP_SEC_CONST_UNSPECIFIED
    #undef DIAGMGR_STOP_SEC_CONST_UNSPECIFIED
	#undef MEMMAP_ERROR
#endif

/**********************************************************************************************************************
 *  DiagMgr END
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  DIAGMGR8 START
 *********************************************************************************************************************/

#ifdef DIAGMGR8_START_SEC_VAR_CLEARED_8
    #undef DIAGMGR8_START_SEC_VAR_CLEARED_8
    #define START_SEC_VAR_NOINIT_8_8
#endif

#ifdef DIAGMGR8_STOP_SEC_VAR_CLEARED_8
    #undef DIAGMGR8_STOP_SEC_VAR_CLEARED_8
    #define STOP_SEC_VAR
#endif

#ifdef DIAGMGR8_START_SEC_VAR_CLEARED_16
    #undef DIAGMGR8_START_SEC_VAR_CLEARED_16
    #define START_SEC_VAR_NOINIT_16_8
#endif

#ifdef DIAGMGR8_STOP_SEC_VAR_CLEARED_16
    #undef DIAGMGR8_STOP_SEC_VAR_CLEARED_16
    #define STOP_SEC_VAR
#endif

#ifdef DIAGMGR8_START_SEC_VAR_CLEARED_32
    #undef DIAGMGR8_START_SEC_VAR_CLEARED_32
    #define START_SEC_VAR_NOINIT_32_8
#endif

#ifdef DIAGMGR8_STOP_SEC_VAR_CLEARED_32
    #undef DIAGMGR8_STOP_SEC_VAR_CLEARED_32
    #define STOP_SEC_VAR
#endif

#ifdef DIAGMGR8_START_SEC_VAR_CLEARED_UNSPECIFIED
    #undef DIAGMGR8_START_SEC_VAR_CLEARED_UNSPECIFIED
    #define START_SEC_VAR_NOINIT_UNSPECIFIED_8
#endif

#ifdef DIAGMGR8_STOP_SEC_VAR_CLEARED_UNSPECIFIED
    #undef DIAGMGR8_STOP_SEC_VAR_CLEARED_UNSPECIFIED
    #define STOP_SEC_VAR
#endif

/**********************************************************************************************************************
 *  DIAGMGR8 END
 *********************************************************************************************************************/


/**********************************************************************************************************************
 *  DIAGMGR9 START
 *********************************************************************************************************************/

#ifdef DIAGMGR9_START_SEC_VAR_CLEARED_8
    #undef DIAGMGR9_START_SEC_VAR_CLEARED_8
    #define START_SEC_VAR_NOINIT_8_9
#endif

#ifdef DIAGMGR9_STOP_SEC_VAR_CLEARED_8
    #undef DIAGMGR9_STOP_SEC_VAR_CLEARED_8
    #define STOP_SEC_VAR
#endif

#ifdef DIAGMGR9_START_SEC_VAR_CLEARED_16
    #undef DIAGMGR9_START_SEC_VAR_CLEARED_16
    #define START_SEC_VAR_NOINIT_16_9
#endif

#ifdef DIAGMGR9_STOP_SEC_VAR_CLEARED_16
    #undef DIAGMGR9_STOP_SEC_VAR_CLEARED_16
    #define STOP_SEC_VAR
#endif

#ifdef DIAGMGR9_START_SEC_VAR_CLEARED_32
    #undef DIAGMGR9_START_SEC_VAR_CLEARED_32
    #define START_SEC_VAR_NOINIT_32_9
#endif

#ifdef DIAGMGR9_STOP_SEC_VAR_CLEARED_32
    #undef DIAGMGR9_STOP_SEC_VAR_CLEARED_32
    #define STOP_SEC_VAR
#endif

#ifdef DIAGMGR9_START_SEC_VAR_CLEARED_UNSPECIFIED
    #undef DIAGMGR9_START_SEC_VAR_CLEARED_UNSPECIFIED
    #define START_SEC_VAR_NOINIT_UNSPECIFIED_9
#endif

#ifdef DIAGMGR9_STOP_SEC_VAR_CLEARED_UNSPECIFIED
    #undef DIAGMGR9_STOP_SEC_VAR_CLEARED_UNSPECIFIED
    #define STOP_SEC_VAR
#endif

/**********************************************************************************************************************
 *  DIAGMGR9 END
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  DIAGMGR10 START
 *********************************************************************************************************************/

#ifdef DIAGMGR10_START_SEC_VAR_CLEARED_8
    #undef DIAGMGR10_START_SEC_VAR_CLEARED_8
    #define START_SEC_VAR_NOINIT_8_10
#endif

#ifdef DIAGMGR10_STOP_SEC_VAR_CLEARED_8
    #undef DIAGMGR10_STOP_SEC_VAR_CLEARED_8
    #define STOP_SEC_VAR
#endif

#ifdef DIAGMGR10_START_SEC_VAR_CLEARED_16
    #undef DIAGMGR10_START_SEC_VAR_CLEARED_16
    #define START_SEC_VAR_NOINIT_16_10
#endif

#ifdef DIAGMGR10_STOP_SEC_VAR_CLEARED_16
    #undef DIAGMGR10_STOP_SEC_VAR_CLEARED_16
    #define STOP_SEC_VAR
#endif

#ifdef DIAGMGR10_START_SEC_VAR_CLEARED_32
    #undef DIAGMGR10_START_SEC_VAR_CLEARED_32
    #define START_SEC_VAR_NOINIT_32_10
#endif

#ifdef DIAGMGR10_STOP_SEC_VAR_CLEARED_32
    #undef DIAGMGR10_STOP_SEC_VAR_CLEARED_32
    #define STOP_SEC_VAR
#endif

#ifdef DIAGMGR10_START_SEC_VAR_CLEARED_UNSPECIFIED
    #undef DIAGMGR10_START_SEC_VAR_CLEARED_UNSPECIFIED
    #define START_SEC_VAR_NOINIT_UNSPECIFIED_10
#endif

#ifdef DIAGMGR10_STOP_SEC_VAR_CLEARED_UNSPECIFIED
    #undef DIAGMGR10_STOP_SEC_VAR_CLEARED_UNSPECIFIED
    #define STOP_SEC_VAR
#endif

/**********************************************************************************************************************
 *  DIAGMGR10 END
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  DIAGMGRDEMIF START
 *********************************************************************************************************************/

#ifdef DIAGMGRDEMIF_START_SEC_VAR_16
    #undef DIAGMGRDEMIF_START_SEC_VAR_16
    #define START_SEC_VAR_NOINIT_16_9
#endif

#ifdef DIAGMGRDEMIF_STOP_SEC_VAR_16
    #undef DIAGMGRDEMIF_STOP_SEC_VAR_16
    #define STOP_SEC_VAR
#endif

/**********************************************************************************************************************
 *  DIAGMGRDEMIF END
 *********************************************************************************************************************/


/**********************************************************************************************************************
 *  DigPhsReasDiag START
 *********************************************************************************************************************/
/* Variables */
#ifdef DIGPHSREASDIAG_START_SEC_VAR_CLEARED_32
    #undef DIGPHSREASDIAG_START_SEC_VAR_CLEARED_32
    #define START_SEC_VAR_NOINIT_32_10
#endif

#ifdef DIGPHSREASDIAG_STOP_SEC_VAR_CLEARED_32
    #undef DIGPHSREASDIAG_STOP_SEC_VAR_CLEARED_32
    #define STOP_SEC_VAR
#endif

#ifdef DIGPHSREASDIAG_START_SEC_VAR_CLEARED_16
    #undef DIGPHSREASDIAG_START_SEC_VAR_CLEARED_16
    #define START_SEC_VAR_NOINIT_16_10
#endif

#ifdef DIGPHSREASDIAG_STOP_SEC_VAR_CLEARED_16
    #undef DIGPHSREASDIAG_STOP_SEC_VAR_CLEARED_16
    #define STOP_SEC_VAR
#endif

#ifdef DIGPHSREASDIAG_START_SEC_VAR_CLEARED_8
    #undef DIGPHSREASDIAG_START_SEC_VAR_CLEARED_8
    #define START_SEC_VAR_NOINIT_8_10
#endif

#ifdef DIGPHSREASDIAG_STOP_SEC_VAR_CLEARED_8
    #undef DIGPHSREASDIAG_STOP_SEC_VAR_CLEARED_8
    #define STOP_SEC_VAR
#endif

#ifdef DIGPHSREASDIAG_START_SEC_VAR_CLEARED_BOOLEAN
    #undef DIGPHSREASDIAG_START_SEC_VAR_CLEARED_BOOLEAN
    #define START_SEC_VAR_NOINIT_UNSPECIFIED_10
#endif

#ifdef DIGPHSREASDIAG_STOP_SEC_VAR_CLEARED_BOOLEAN
    #undef DIGPHSREASDIAG_STOP_SEC_VAR_CLEARED_BOOLEAN
    #define STOP_SEC_VAR
#endif

/**********************************************************************************************************************
 *  DigPhsReasDiag END
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  ElePwr START
 *********************************************************************************************************************/
/* Variables */
#ifdef ELEPWR_START_SEC_VAR_CLEARED_32
    #undef ELEPWR_START_SEC_VAR_CLEARED_32
    #define START_SEC_VAR_NOINIT_32_9
#endif

#ifdef ELEPWR_STOP_SEC_VAR_CLEARED_32
    #undef ELEPWR_STOP_SEC_VAR_CLEARED_32
    #define STOP_SEC_VAR
#endif

/**********************************************************************************************************************
 *  ElePwr END
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  EpsDiagSrvc START
 *********************************************************************************************************************/
/* CONST section */
#ifdef EPSDIAGSRVC_START_SEC_CONST_8
    #undef EPSDIAGSRVC_START_SEC_CONST_8
    #define START_SEC_CONST_8_9
#endif

#ifdef EPSDIAGSRVC_STOP_SEC_CONST_8
    #undef EPSDIAGSRVC_STOP_SEC_CONST_8
    #define STOP_SEC_CONST
#endif

/* Variables */
#ifdef EPSDIAGSRVC_START_SEC_VAR_CLEARED_UNSPECIFIED
    #undef EPSDIAGSRVC_START_SEC_VAR_CLEARED_UNSPECIFIED
    #define START_SEC_VAR_CLEARED_UNSPECIFIED_9
#endif

#ifdef EPSDIAGSRVC_STOP_SEC_VAR_CLEARED_UNSPECIFIED
    #undef EPSDIAGSRVC_STOP_SEC_VAR_CLEARED_UNSPECIFIED
    #define STOP_SEC_VAR
#endif

#ifdef EPSDIAGSRVC_START_SEC_VAR_CLEARED_BOOLEAN
    #undef EPSDIAGSRVC_START_SEC_VAR_CLEARED_BOOLEAN
    #define START_SEC_VAR_CLEARED_BOOLEAN_9
#endif

#ifdef EPSDIAGSRVC_STOP_SEC_VAR_CLEARED_BOOLEAN
    #undef EPSDIAGSRVC_STOP_SEC_VAR_CLEARED_BOOLEAN
    #define STOP_SEC_VAR
#endif

#ifdef EPSDIAGSRVC_START_SEC_VAR_CLEARED_32
    #undef EPSDIAGSRVC_START_SEC_VAR_CLEARED_32
    #define START_SEC_VAR_CLEARED_32_9
#endif

#ifdef EPSDIAGSRVC_STOP_SEC_VAR_CLEARED_32
    #undef EPSDIAGSRVC_STOP_SEC_VAR_CLEARED_32
    #define STOP_SEC_VAR
#endif

#ifdef EPSDIAGSRVC_START_SEC_VAR_CLEARED_16
    #undef EPSDIAGSRVC_START_SEC_VAR_CLEARED_16
    #define START_SEC_VAR_CLEARED_16_9
#endif

#ifdef EPSDIAGSRVC_STOP_SEC_VAR_CLEARED_16
    #undef EPSDIAGSRVC_STOP_SEC_VAR_CLEARED_16
    #define STOP_SEC_VAR
#endif

#ifdef EPSDIAGSRVC_START_SEC_VAR_CLEARED_8
    #undef EPSDIAGSRVC_START_SEC_VAR_CLEARED_8
    #define START_SEC_VAR_CLEARED_8_9
#endif

#ifdef EPSDIAGSRVC_STOP_SEC_VAR_CLEARED_8
    #undef EPSDIAGSRVC_STOP_SEC_VAR_CLEARED_8
    #define STOP_SEC_VAR
#endif

#ifdef EPSXCPSRVC_START_SEC_VAR_CLEARED_16
    #undef EPSXCPSRVC_START_SEC_VAR_CLEARED_16
    #define START_SEC_VAR_CLEARED_16_9
#endif

#ifdef EPSXCPSRVC_STOP_SEC_VAR_CLEARED_16
    #undef EPSXCPSRVC_STOP_SEC_VAR_CLEARED_16
    #define STOP_SEC_VAR
#endif


/**********************************************************************************************************************
 *  EpsDiagSrvc END
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  ePWM START
 *********************************************************************************************************************/

#ifdef EPWM_START_SEC_CODE
    #undef EPWM_START_SEC_CODE
    #define START_SEC_CODE
#endif
#ifdef EPWM_STOP_SEC_CODE
    #undef EPWM_STOP_SEC_CODE
    #define STOP_SEC_CODE
#endif

/**********************************************************************************************************************
 *  ePWM END
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  EOTActuatorMng START
 *********************************************************************************************************************/

#ifdef EOTACTUATORMNG_START_SEC_VAR_CLEARED_32
    #undef EOTACTUATORMNG_START_SEC_VAR_CLEARED_32
    #define START_SEC_VAR_NOINIT_32_10
#endif

#ifdef EOTACTUATORMNG_STOP_SEC_VAR_CLEARED_32
    #undef EOTACTUATORMNG_STOP_SEC_VAR_CLEARED_32
    #define STOP_SEC_VAR
#endif

#ifdef EOTACTUATORMNG_START_SEC_VAR_CLEARED_BOOLEAN
    #undef EOTACTUATORMNG_START_SEC_VAR_CLEARED_BOOLEAN
    #define START_SEC_VAR_NOINIT_8_10
#endif

#ifdef EOTACTUATORMNG_STOP_SEC_VAR_CLEARED_BOOLEAN
    #undef EOTACTUATORMNG_STOP_SEC_VAR_CLEARED_BOOLEAN
    #define STOP_SEC_VAR
#endif

#ifdef EOTACTUATORMNG_START_SEC_VAR_CLEARED_UNSPECIFIED
    #undef EOTACTUATORMNG_START_SEC_VAR_CLEARED_UNSPECIFIED
    #define START_SEC_VAR_NOINIT_UNSPECIFIED_10
#endif

#ifdef EOTACTUATORMNG_STOP_SEC_VAR_CLEARED_UNSPECIFIED
    #undef EOTACTUATORMNG_STOP_SEC_VAR_CLEARED_UNSPECIFIED
    #define STOP_SEC_VAR
#endif

/**********************************************************************************************************************
 *  EOTActuatorMng END
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  Fee START
 *********************************************************************************************************************/
/*  CODE sections */

#ifdef FEE_START_SEC_CODE
    #undef FEE_START_SEC_CODE
    #define START_SEC_CODE
 	#define START_SEC_VAR_INIT_UNSPECIFIED_0
#endif
#ifdef FEE_STOP_SEC_CODE
    #undef FEE_STOP_SEC_CODE
    #define STOP_SEC_CODE
	#define STOP_SEC_VAR
#endif

/* CONST sections */

#ifdef FEE_START_SEC_CONST_UNSPECIFIED
    #undef FEE_START_SEC_CONST_UNSPECIFIED
    #define START_SEC_CONST_UNSPECIFIED
#endif
#ifdef FEE_STOP_SEC_CONST_UNSPECIFIED
    #undef FEE_STOP_SEC_CONST_UNSPECIFIED
    #define STOP_SEC_CONST
#endif

/* VAR INIT sections */

#ifdef FEE_START_SEC_VAR_INIT_UNSPECIFIED
    #undef FEE_START_SEC_VAR_INIT_UNSPECIFIED
	#define START_SEC_VAR_INIT_UNSPECIFIED_0
#endif
#ifdef FEE_STOP_SEC_VAR_INIT_UNSPECIFIED
    #undef FEE_STOP_SEC_VAR_INIT_UNSPECIFIED
    #define STOP_SEC_VAR
#endif

/**********************************************************************************************************************
 *  Fee END
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  FrqDepDmpnInrtCmp START
 *********************************************************************************************************************/
/* Variables */
#ifdef FRQDEPDMPNINRTCMP_START_SEC_VAR_CLEARED_32
    #undef FRQDEPDMPNINRTCMP_START_SEC_VAR_CLEARED_32
    #define START_SEC_VAR_NOINIT_32_10
#endif

#ifdef FRQDEPDMPNINRTCMP_STOP_SEC_VAR_CLEARED_32
    #undef FRQDEPDMPNINRTCMP_STOP_SEC_VAR_CLEARED_32
    #define STOP_SEC_VAR
#endif

#ifdef FRQDEPDMPNINRTCMP_START_SEC_VAR_CLEARED_UNSPECIFIED
    #undef FRQDEPDMPNINRTCMP_START_SEC_VAR_CLEARED_UNSPECIFIED
    #define START_SEC_VAR_NOINIT_UNSPECIFIED_10
#endif

#ifdef FRQDEPDMPNINRTCMP_STOP_SEC_VAR_CLEARED_UNSPECIFIED
    #undef FRQDEPDMPNINRTCMP_STOP_SEC_VAR_CLEARED_UNSPECIFIED
    #define STOP_SEC_VAR
#endif

/**********************************************************************************************************************
 *  FrqDepDmpnInrtCmp END
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  Gsod START
 *********************************************************************************************************************/
/* VAR sections */

#ifdef GSOD_START_SEC_VAR_CLEARED_BOOLEAN
	#undef GSOD_START_SEC_VAR_CLEARED_BOOLEAN
	#define START_SEC_VAR_NOINIT_UNSPECIFIED_8
#endif

#ifdef GSOD_STOP_SEC_VAR_CLEARED_BOOLEAN
	#undef GSOD_STOP_SEC_VAR_CLEARED_BOOLEAN
	#define STOP_SEC_VAR
#endif

/**********************************************************************************************************************
 *  Gsod END
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  HaLF START
 *********************************************************************************************************************/
/* VAR sections */

#ifdef HALFTO_START_SEC_VAR_CLEARED_8
    #undef HALFTO_START_SEC_VAR_CLEARED_8
    #define START_SEC_VAR_NOINIT_8_10
#endif

#ifdef HALFTO_STOP_SEC_VAR_CLEARED_8
    #undef HALFTO_STOP_SEC_VAR_CLEARED_8
    #define STOP_SEC_VAR
#endif

#ifdef HALFTO_START_SEC_VAR_CLEARED_BOOLEAN
    #undef HALFTO_START_SEC_VAR_CLEARED_BOOLEAN
    #define START_SEC_VAR_NOINIT_UNSPECIFIED_10
#endif

#ifdef HALFTO_STOP_SEC_VAR_CLEARED_BOOLEAN
    #undef HALFTO_STOP_SEC_VAR_CLEARED_BOOLEAN
    #define STOP_SEC_VAR
#endif

#ifdef HALFTO_START_SEC_VAR_NOINIT_32
	# undef HALFTO_START_SEC_VAR_NOINIT_32
	# define START_SEC_VAR_NOINIT_32_10
#endif

#ifdef HALFTO_STOP_SEC_VAR_NOINIT_32
	# undef HALFTO_STOP_SEC_VAR_NOINIT_32
	# define STOP_SEC_VAR
#endif

/**********************************************************************************************************************
 *  HaLF END
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  HighFreqAssist START
 *********************************************************************************************************************/
/* VAR sections */

#ifdef HIGHFREQASSIST_START_SEC_VAR_CLEARED_32
	#undef HIGHFREQASSIST_START_SEC_VAR_CLEARED_32
	#define START_SEC_VAR_NOINIT_32_10
#endif

#ifdef HIGHFREQASSIST_STOP_SEC_VAR_CLEARED_32
	#undef HIGHFREQASSIST_STOP_SEC_VAR_CLEARED_32
	#define STOP_SEC_VAR
#endif

#ifdef HYSTADD_START_SEC_VAR_CLEARED_UNSPECIFIED
	#undef HYSTADD_START_SEC_VAR_CLEARED_UNSPECIFIED
	#define START_SEC_VAR_NOINIT_UNSPECIFIED_10
#endif

#ifdef HYSTADD_STOP_SEC_VAR_CLEARED_UNSPECIFIED
	#undef HYSTADD_STOP_SEC_VAR_CLEARED_UNSPECIFIED
	#define STOP_SEC_VAR
#endif

/**********************************************************************************************************************
 *  HighFreqAssist END
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  HiLoadStall START
 *********************************************************************************************************************/
/* Variables */
#ifdef HILOADSTALL_START_SEC_VAR_CLEARED_16
    #undef HILOADSTALL_START_SEC_VAR_CLEARED_16
    #define START_SEC_VAR_CLEARED_16_9
#endif

#ifdef HILOADSTALL_STOP_SEC_VAR_CLEARED_16
    #undef HILOADSTALL_STOP_SEC_VAR_CLEARED_16
    #define STOP_SEC_VAR
#endif

#ifdef HILOADSTALL_START_SEC_VAR_CLEARED_32
    #undef HILOADSTALL_START_SEC_VAR_CLEARED_32
    #define START_SEC_VAR_CLEARED_32_9
#endif

#ifdef HILOADSTALL_STOP_SEC_VAR_CLEARED_32
    #undef HILOADSTALL_STOP_SEC_VAR_CLEARED_32
    #define STOP_SEC_VAR
#endif

/**********************************************************************************************************************
 *  HiLoadStall END
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  HwPwUp START
 *********************************************************************************************************************/
/* VAR sections */

#ifdef HWPWUP_START_SEC_VAR_CLEARED_UNSPECIFIED
	#undef HWPWUP_START_SEC_VAR_CLEARED_UNSPECIFIED
	#define START_SEC_VAR_NOINIT_UNSPECIFIED_10
#endif

#ifdef HWPWUP_STOP_SEC_VAR_CLEARED_UNSPECIFIED
	#undef HWPWUP_STOP_SEC_VAR_CLEARED_UNSPECIFIED
	#define STOP_SEC_VAR
#endif

/**********************************************************************************************************************
 *  HwPwUp END
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  HwTrq START
 *********************************************************************************************************************/
/* Type H Variables */
 #ifdef HWTRQ_START_SEC_VAR_SAVED_ZONEH_32
    #define VAR_SEC_OPEN
/* Enter here a #pragma command for opening the specified section */
#pragma SET_DATA_SECTION(".ossDataAp_10:noinit:typeH:HwTrq")

    #undef HWTRQ_START_SEC_VAR_SAVED_ZONEH_32
    #undef MEMMAP_ERROR
#endif

#ifdef HWTRQ_STOP_SEC_VAR_SAVED_ZONEH_32
    #undef HWTRQ_STOP_SEC_VAR_SAVED_ZONEH_32
    #define STOP_SEC_VAR
#endif

/* Variables */
#ifdef HWTRQ_START_SEC_VAR_CLEARED_8
    #undef HWTRQ_START_SEC_VAR_CLEARED_8
    #define START_SEC_VAR_NOINIT_8_10
#endif

#ifdef HWTRQ_STOP_SEC_VAR_CLEARED_8
    #undef HWTRQ_STOP_SEC_VAR_CLEARED_8
    #define STOP_SEC_VAR
#endif

#ifdef HWTRQ_START_SEC_VAR_CLEARED_16
    #undef HWTRQ_START_SEC_VAR_CLEARED_16
    #define START_SEC_VAR_NOINIT_16_10
#endif

#ifdef HWTRQ_STOP_SEC_VAR_CLEARED_16
    #undef HWTRQ_STOP_SEC_VAR_CLEARED_16
    #define STOP_SEC_VAR
#endif

#ifdef HWTRQ_START_SEC_VAR_CLEARED_32
    #undef HWTRQ_START_SEC_VAR_CLEARED_32
    #define START_SEC_VAR_NOINIT_32_10
#endif

#ifdef HWTRQ_STOP_SEC_VAR_CLEARED_32
    #undef HWTRQ_STOP_SEC_VAR_CLEARED_32
    #define STOP_SEC_VAR
#endif

/**********************************************************************************************************************
 *  HwTrq END
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  HwTrq2 START
 *********************************************************************************************************************/
/* Type H Variables */
 #ifdef HWTRQ2_START_SEC_VAR_SAVED_ZONEH_32
    #define VAR_SEC_OPEN
/* Enter here a #pragma command for opening the specified section */
#pragma SET_DATA_SECTION(".ossDataAp_8:noinit:typeH:HwTrq2")

    #undef HWTRQ2_START_SEC_VAR_SAVED_ZONEH_32
    #undef MEMMAP_ERROR
#endif

#ifdef HWTRQ2_STOP_SEC_VAR_SAVED_ZONEH_32
    #undef HWTRQ2_STOP_SEC_VAR_SAVED_ZONEH_32
    #define STOP_SEC_VAR
#endif

/* Variables */
#ifdef HWTRQ2_START_SEC_VAR_CLEARED_16
    #undef HWTRQ2_START_SEC_VAR_CLEARED_16
    #define START_SEC_VAR_NOINIT_16_8
#endif

#ifdef HWTRQ2_STOP_SEC_VAR_CLEARED_16
    #undef HWTRQ2_STOP_SEC_VAR_CLEARED_16
    #define STOP_SEC_VAR
#endif

#ifdef HWTRQ2_START_SEC_VAR_CLEARED_32
    #undef HWTRQ2_START_SEC_VAR_CLEARED_32
    #define START_SEC_VAR_NOINIT_32_8
#endif

#ifdef HWTRQ2_STOP_SEC_VAR_CLEARED_32
    #undef HWTRQ2_STOP_SEC_VAR_CLEARED_32
    #define STOP_SEC_VAR
#endif

/**********************************************************************************************************************
 *  HwTrq2 END
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  HystComp START
 *********************************************************************************************************************/
/* Variables */
#ifdef HYSTCOMP_START_SEC_VAR_CLEARED_16
    #undef HYSTCOMP_START_SEC_VAR_CLEARED_16
    #define START_SEC_VAR_CLEARED_16_10
#endif

#ifdef HYSTCOMP_STOP_SEC_VAR_CLEARED_16
    #undef HYSTCOMP_STOP_SEC_VAR_CLEARED_16
    #define STOP_SEC_VAR
#endif

#ifdef HYSTCOMP_START_SEC_VAR_CLEARED_32
    #undef HYSTCOMP_START_SEC_VAR_CLEARED_32
    #define START_SEC_VAR_CLEARED_32_10
#endif

#ifdef HYSTCOMP_STOP_SEC_VAR_CLEARED_32
    #undef HYSTCOMP_STOP_SEC_VAR_CLEARED_32
    #define STOP_SEC_VAR
#endif

#ifdef HYSTCOMP_START_SEC_VAR_CLEARED_UNSPECIFIED
    #undef HYSTCOMP_START_SEC_VAR_CLEARED_UNSPECIFIED
    #define START_SEC_VAR_NOINIT_UNSPECIFIED_10
#endif

#ifdef HYSTCOMP_STOP_SEC_VAR_CLEARED_UNSPECIFIED
    #undef HYSTCOMP_STOP_SEC_VAR_CLEARED_UNSPECIFIED
    #define STOP_SEC_VAR
#endif

/**********************************************************************************************************************
 *  HystComp END
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  IoHwAb10 START
 *********************************************************************************************************************/
#ifdef IOHWAB10_START_SEC_VAR_CLEARED_8
    #undef IOHWAB10_START_SEC_VAR_CLEARED_8
    #define START_SEC_VAR_CLEARED_8_10
#endif

#ifdef IOHWAB10_STOP_SEC_VAR_CLEARED_8
    #undef IOHWAB10_STOP_SEC_VAR_CLEARED_8
    #define STOP_SEC_VAR
#endif

#ifdef IOHWAB10_START_SEC_VAR_CLEARED_16
    #undef IOHWAB10_START_SEC_VAR_CLEARED_16
    #define START_SEC_VAR_CLEARED_16_10
#endif

#ifdef IOHWAB10_STOP_SEC_VAR_CLEARED_16
    #undef IOHWAB10_STOP_SEC_VAR_CLEARED_16
    #define STOP_SEC_VAR
#endif

#ifdef IOHWAB10_START_SEC_VAR_CLEARED_32
    #undef IOHWAB10_START_SEC_VAR_CLEARED_32
    #define START_SEC_VAR_CLEARED_32_10
#endif

#ifdef IOHWAB10_STOP_SEC_VAR_CLEARED_32
    #undef IOHWAB10_STOP_SEC_VAR_CLEARED_32
    #define STOP_SEC_VAR
#endif

/**********************************************************************************************************************
 *  IoHwAb10 END
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  LmtCod START
 *********************************************************************************************************************/
/* Variables */
#ifdef LMTCOD_START_SEC_VAR_CLEARED_32
    #undef LMTCOD_START_SEC_VAR_CLEARED_32
    #define START_SEC_VAR_CLEARED_32_9
#endif

#ifdef LMTCOD_STOP_SEC_VAR_CLEARED_32
    #undef LMTCOD_STOP_SEC_VAR_CLEARED_32
    #define STOP_SEC_VAR
#endif

/**********************************************************************************************************************
 *  LmtCod END
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  LrnEOT START
 *********************************************************************************************************************/
/* Variables */
#ifdef LRNEOT_START_SEC_VAR_CLEARED_32
    #undef LRNEOT_START_SEC_VAR_CLEARED_32
    #define START_SEC_VAR_NOINIT_32_9
#endif

#ifdef LRNEOT_STOP_SEC_VAR_CLEARED_32
    #undef LRNEOT_STOP_SEC_VAR_CLEARED_32
    #define STOP_SEC_VAR
#endif

#ifdef LRNEOT_START_SEC_VAR_CLEARED_BOOLEAN
    #undef LRNEOT_START_SEC_VAR_CLEARED_BOOLEAN
    #define START_SEC_VAR_NOINIT_8_9
#endif

#ifdef LRNEOT_STOP_SEC_VAR_CLEARED_BOOLEAN
    #undef LRNEOT_STOP_SEC_VAR_CLEARED_BOOLEAN
    #define STOP_SEC_VAR
#endif
/**********************************************************************************************************************
 *  LrnEOT END
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  MemIf START
 *********************************************************************************************************************/
#ifdef MEMIF_START_SEC_CONST_32BIT
    #undef MEMIF_START_SEC_CONST_32BIT
	#include "Cd_FeeIf.h"
    #define START_SEC_CONST_32BIT
	#define Fee_Read			TWrapC_Fee_Read
	#define Fee_Write 			TWrapC_Fee_Write
	#define Fee_EraseImmediateBlock 	TWrapC_Fee_EraseImmediateBlock
	#define Fee_InvalidateBlock 		TWrapC_Fee_InvalidateBlock
	#define Fee_Cancel 			TWrapC_Fee_Cancel
	#define Fee_GetStatus 		 (MemIf_ApiGetJobResultType)TWrapC_Fee_GetStatus
	#define Fee_GetJobResult 		 (MemIf_ApiGetJobResultType)TWrapC_Fee_GetJobResult
#endif

#ifdef MEMIF_STOP_SEC_CONST_32BIT
	#undef MEMIF_STOP_SEC_CONST_32BIT
	#define STOP_SEC_CONST
	#undef Fee_Read
	#undef Fee_Write
	#undef Fee_EraseImmediateBlock
	#undef Fee_InvalidateBlock
	#undef Fee_Cancel
	#undef Fee_GetStatus
	#undef Fee_GetJobResult
#endif
/**********************************************************************************************************************
 *  MemIf END
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  MtrDrvDiag START
 *********************************************************************************************************************/
/* VAR sections */

#ifdef MTRDRVDIAG_START_SEC_VAR_CLEARED_32
	#undef MTRDRVDIAG_START_SEC_VAR_CLEARED_32
	#define START_SEC_VAR_NOINIT_32_10
#endif

#ifdef MTRDRVDIAG_STOP_SEC_VAR_CLEARED_32
	#undef MTRDRVDIAG_STOP_SEC_VAR_CLEARED_32
	#define STOP_SEC_VAR
#endif

#ifdef MTRDRVDIAG_START_SEC_VAR_CLEARED_16
    #undef MTRDRVDIAG_START_SEC_VAR_CLEARED_16
    #define START_SEC_VAR_NOINIT_16_10
#endif

#ifdef MTRDRVDIAG_STOP_SEC_VAR_CLEARED_16
    #undef MTRDRVDIAG_STOP_SEC_VAR_CLEARED_16
    #define STOP_SEC_VAR
#endif

#ifdef MTRDRVDIAG_START_SEC_VAR_CLEARED_BOOLEAN
    #undef MTRDRVDIAG_START_SEC_VAR_CLEARED_BOOLEAN
    #define START_SEC_VAR_NOINIT_UNSPECIFIED_10
#endif

#ifdef MTRDRVDIAG_STOP_SEC_VAR_CLEARED_BOOLEAN
    #undef MTRDRVDIAG_STOP_SEC_VAR_CLEARED_BOOLEAN
    #define STOP_SEC_VAR
#endif

#ifdef MTRDRVDIAG_START_SEC_VAR_CLEARED_UNSPECIFIED
	#undef MTRDRVDIAG_START_SEC_VAR_CLEARED_UNSPECIFIED
	#define START_SEC_VAR_NOINIT_UNSPECIFIED_10
#endif

#ifdef MTRDRVDIAG_STOP_SEC_VAR_CLEARED_UNSPECIFIED
	#undef MTRDRVDIAG_STOP_SEC_VAR_CLEARED_UNSPECIFIED
	#define STOP_SEC_VAR
#endif

/**********************************************************************************************************************
 *  MtrDrvDiag END
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  MtrPos START
 *********************************************************************************************************************/
/* CONST sections */
#ifdef MTRPOS_START_SEC_CONST_UNSPECIFIED
	#undef MTRPOS_START_SEC_CONST_UNSPECIFIED
	#define START_SEC_CONST_UNSPECIFIED
#endif

#ifdef MTRPOS_STOP_SEC_CONST_UNSPECIFIED
	#undef MTRPOS_STOP_SEC_CONST_UNSPECIFIED
	#define STOP_SEC_CONST
#endif

/* VAR sections */

#ifdef MTRPOS_START_SEC_VAR_NOINIT_32
	#undef MTRPOS_START_SEC_VAR_NOINIT_32
	#define START_SEC_VAR_NOINIT_32_10
#endif

#ifdef MTRPOS_STOP_SEC_VAR_NOINIT_32
	#undef MTRPOS_STOP_SEC_VAR_NOINIT_32
	#define STOP_SEC_VAR
#endif

#ifdef MTRPOS_START_SEC_VAR_CLEARED_16
    #undef MTRPOS_START_SEC_VAR_CLEARED_16
    #define START_SEC_VAR_NOINIT_16_10
#endif

#ifdef MTRPOS_STOP_SEC_VAR_CLEARED_16
    #undef MTRPOS_STOP_SEC_VAR_CLEARED_16
    #define STOP_SEC_VAR
#endif

#ifdef MTRPOS_START_SEC_VAR_CLEARED_BOOLEAN
    #undef MTRPOS_START_SEC_VAR_CLEARED_BOOLEAN
    #define START_SEC_VAR_NOINIT_UNSPECIFIED_10
#endif

#ifdef MTRPOS_STOP_SEC_VAR_CLEARED_BOOLEAN
    #undef MTRPOS_STOP_SEC_VAR_CLEARED_BOOLEAN
    #define STOP_SEC_VAR
#endif

/**********************************************************************************************************************
 *  MtrPos END
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  MtrPos2 START
 *********************************************************************************************************************/

/* Type H Variables */
 #ifdef MTRPOS2_START_SEC_VAR_SAVED_ZONEH_32
    #define VAR_SEC_OPEN
/* Enter here a #pragma command for opening the specified section */
#pragma SET_DATA_SECTION(".ossDataAp_10:noinit:typeH:MtrPos2")
    #undef MTRPOS2_START_SEC_VAR_SAVED_ZONEH_32
    #undef MEMMAP_ERROR
#endif

#ifdef MTRPOS2_STOP_SEC_VAR_SAVED_ZONEH_32
    #undef MTRPOS2_STOP_SEC_VAR_SAVED_ZONEH_32
    #define STOP_SEC_VAR
#endif

/* VAR sections */
#ifdef MTRPOS2_START_SEC_VAR_NOINIT_32
	#undef MTRPOS2_START_SEC_VAR_NOINIT_32
	#define START_SEC_VAR_NOINIT_32_10
#endif

#ifdef MTRPOS2_STOP_SEC_VAR_NOINIT_32
	#undef MTRPOS2_STOP_SEC_VAR_NOINIT_32
	#define STOP_SEC_VAR
#endif

#ifdef MTRPOS2_START_SEC_VAR_CLEARED_32
	#undef MTRPOS2_START_SEC_VAR_CLEARED_32
	#define START_SEC_VAR_NOINIT_32_10
#endif

#ifdef MTRPOS2_STOP_SEC_VAR_CLEARED_32
	#undef MTRPOS2_STOP_SEC_VAR_CLEARED_32
	#define STOP_SEC_VAR
#endif

#ifdef MTRPOS2_START_SEC_VAR_CLEARED_16
    #undef MTRPOS2_START_SEC_VAR_CLEARED_16
    #define START_SEC_VAR_NOINIT_16_10
#endif

#ifdef MTRPOS2_STOP_SEC_VAR_CLEARED_16
    #undef MTRPOS2_STOP_SEC_VAR_CLEARED_16
    #define STOP_SEC_VAR
#endif

#ifdef MTRPOS2_START_SEC_VAR_CLEARED_8
    #undef MTRPOS2_START_SEC_VAR_CLEARED_8
    #define START_SEC_VAR_NOINIT_8_10
#endif

#ifdef MTRPOS2_STOP_SEC_VAR_CLEARED_8
    #undef MTRPOS2_STOP_SEC_VAR_CLEARED_8
    #define STOP_SEC_VAR
#endif

/**********************************************************************************************************************
 *  MtrPos2 END
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  MtrPos3 START
 *********************************************************************************************************************/
/* CONST sections */
#ifdef MTRPOS3_START_SEC_CONST_UNSPECIFIED
	#undef MTRPOS3_START_SEC_CONST_UNSPECIFIED
	#define START_SEC_CONST_UNSPECIFIED
#endif

#ifdef MTRPOS3_STOP_SEC_CONST_UNSPECIFIED
	#undef MTRPOS3_STOP_SEC_CONST_UNSPECIFIED
	#define STOP_SEC_CONST
#endif

/* VAR sections */
#ifdef MTRPOS3_START_SEC_VAR_CLEARED_32
    #undef MTRPOS3_START_SEC_VAR_CLEARED_32
    #define START_SEC_VAR_NOINIT_32_8
#endif

#ifdef MTRPOS3_STOP_SEC_VAR_CLEARED_32
    #undef MTRPOS3_STOP_SEC_VAR_CLEARED_32
    #define STOP_SEC_VAR
#endif

#ifdef MTRPOS3_START_SEC_VAR_CLEARED_16
    #undef MTRPOS3_START_SEC_VAR_CLEARED_16
    #define START_SEC_VAR_NOINIT_16_8
#endif

#ifdef MTRPOS3_STOP_SEC_VAR_CLEARED_16
    #undef MTRPOS3_STOP_SEC_VAR_CLEARED_16
    #define STOP_SEC_VAR
#endif

/**********************************************************************************************************************
 *  MtrPos3 END
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  MtrTempEst START
 *********************************************************************************************************************/
/* VAR sections */

#ifdef MTRTEMPEST_START_SEC_VAR_CLEARED_32
	#undef MTRTEMPEST_START_SEC_VAR_CLEARED_32
	#define START_SEC_VAR_NOINIT_32_9
#endif

#ifdef MTRTEMPEST_STOP_SEC_VAR_CLEARED_32
	#undef MTRTEMPEST_STOP_SEC_VAR_CLEARED_32
	#define STOP_SEC_VAR
#endif

#ifdef MTRTEMPEST_START_SEC_VAR_CLEARED_BOOLEAN
    #undef MTRTEMPEST_START_SEC_VAR_CLEARED_BOOLEAN
    #define START_SEC_VAR_NOINIT_UNSPECIFIED_9
#endif

#ifdef MTRTEMPEST_STOP_SEC_VAR_CLEARED_BOOLEAN
    #undef MTRTEMPEST_STOP_SEC_VAR_CLEARED_BOOLEAN
    #define STOP_SEC_VAR
#endif

#ifdef MTRTEMPEST_START_SEC_VAR_CLEARED_UNSPECIFIED
	#undef MTRTEMPEST_START_SEC_VAR_CLEARED_UNSPECIFIED
	#define START_SEC_VAR_NOINIT_UNSPECIFIED_9
#endif

#ifdef MTRTEMPEST_STOP_SEC_VAR_CLEARED_UNSPECIFIED
	#undef MTRTEMPEST_STOP_SEC_VAR_CLEARED_UNSPECIFIED
	#define STOP_SEC_VAR
#endif

/**********************************************************************************************************************
 *  MtrTempEst END
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  MtrVel START
 *********************************************************************************************************************/
/* VAR sections */

#ifdef MTRVEL_START_SEC_VAR_CLEARED_32
    #undef MTRVEL_START_SEC_VAR_CLEARED_32
    #define START_SEC_VAR_CLEARED_32_10
#endif

#ifdef MTRVEL_STOP_SEC_VAR_CLEARED_32
    #undef MTRVEL_STOP_SEC_VAR_CLEARED_32
    #define STOP_SEC_VAR
#endif

#ifdef MTRVEL_START_SEC_VAR_CLEARED_16
    #undef MTRVEL_START_SEC_VAR_CLEARED_16
    #define START_SEC_VAR_CLEARED_16_10
#endif

#ifdef MTRVEL_STOP_SEC_VAR_CLEARED_16
    #undef MTRVEL_STOP_SEC_VAR_CLEARED_16
    #define STOP_SEC_VAR
#endif

#ifdef MTRVEL_START_SEC_VAR_CLEARED_8
    #undef MTRVEL_START_SEC_VAR_CLEARED_8
    #define START_SEC_VAR_CLEARED_8_10
#endif

#ifdef MTRVEL_STOP_SEC_VAR_CLEARED_8
    #undef MTRVEL_STOP_SEC_VAR_CLEARED_8
    #define STOP_SEC_VAR
#endif

#ifdef MTRVEL_START_SEC_VAR_CLEARED_8_GLOBALSHARED
    #undef MTRVEL_START_SEC_VAR_CLEARED_8_GLOBALSHARED
    #define START_SEC_VAR_CLEARED_8_GLOBALSHARED
#endif

#ifdef MTRVEL_STOP_SEC_VAR_CLEARED_8_GLOBALSHARED
    #undef MTRVEL_STOP_SEC_VAR_CLEARED_8_GLOBALSHARED
    #define STOP_SEC_VAR
#endif

/**********************************************************************************************************************
 *  MtrVel END
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  MtrVel2 START
 *********************************************************************************************************************/
/* VAR sections */

#ifdef MTRVEL2_START_SEC_VAR_CLEARED_32
    #undef MTRVEL2_START_SEC_VAR_CLEARED_32
    #define START_SEC_VAR_CLEARED_32_8
#endif

#ifdef MTRVEL2_STOP_SEC_VAR_CLEARED_32
    #undef MTRVEL2_STOP_SEC_VAR_CLEARED_32
    #define STOP_SEC_VAR
#endif

#ifdef MTRVEL2_START_SEC_VAR_CLEARED_16
    #undef MTRVEL2_START_SEC_VAR_CLEARED_16
    #define START_SEC_VAR_CLEARED_UNSPECIFIED_8
#endif

#ifdef MTRVEL2_STOP_SEC_VAR_CLEARED_16
    #undef MTRVEL2_STOP_SEC_VAR_CLEARED_16
    #define STOP_SEC_VAR
#endif

#ifdef MTRVEL2_START_SEC_VAR_CLEARED_UNSPECIFIED
	#undef MTRVEL2_START_SEC_VAR_CLEARED_UNSPECIFIED
	#define START_SEC_VAR_CLEARED_UNSPECIFIED_8
#endif

#ifdef MTRVEL2_STOP_SEC_VAR_CLEARED_UNSPECIFIED
	#undef MTRVEL2_STOP_SEC_VAR_CLEARED_UNSPECIFIED
	#define STOP_SEC_VAR
#endif

/**********************************************************************************************************************
 *  MtrVel2 END
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  MtrVel3 START
 *********************************************************************************************************************/
/* VAR sections */

#ifdef MTRVEL3_START_SEC_VAR_CLEARED_16
    #undef MTRVEL3_START_SEC_VAR_CLEARED_16
    #define START_SEC_VAR_CLEARED_16_10
#endif

#ifdef MTRVEL3_STOP_SEC_VAR_CLEARED_16
    #undef MTRVEL3_STOP_SEC_VAR_CLEARED_16
    #define STOP_SEC_VAR
#endif

#ifdef MTRVEL3_START_SEC_VAR_CLEARED_8
    #undef MTRVEL3_START_SEC_VAR_CLEARED_8
    #define START_SEC_VAR_CLEARED_8_10
#endif

#ifdef MTRVEL3_STOP_SEC_VAR_CLEARED_8
    #undef MTRVEL3_STOP_SEC_VAR_CLEARED_8
    #define STOP_SEC_VAR
#endif


/**********************************************************************************************************************
 *  MtrVel3 END
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  Nhet START
 *********************************************************************************************************************/

#ifdef NHET_START_SEC_CODE
    #undef NHET_START_SEC_CODE
    #define START_SEC_CODE
#endif
#ifdef NHET_STOP_SEC_CODE
    #undef NHET_STOP_SEC_CODE
    #define STOP_SEC_CODE
#endif

/**********************************************************************************************************************
 *  Nhet END
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  NtWrap START
 *********************************************************************************************************************/

#ifdef NTWRAP_START_SEC_VAR_NOINIT_UNSPECIFIED
    #undef NTWRAP_START_SEC_VAR_NOINIT_UNSPECIFIED
    #define START_SEC_VAR_CLEARED_UNSPECIFIED_GLOBALSHARED
#endif
#ifdef NTWRAP_STOP_SEC_VAR_NOINIT_UNSPECIFIED
    #undef NTWRAP_STOP_SEC_VAR_NOINIT_UNSPECIFIED
    #define STOP_SEC_VAR
#endif

/**********************************************************************************************************************
 *  NtWrap END
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  NvmProxy START
 *********************************************************************************************************************/
/* Code */
#if defined NVMPROXY_START_SEC_CODE
    #undef NVMPROXY_START_SEC_CODE
    #define START_SEC_CODE

#elif defined NVMPROXY_STOP_SEC_CODE
    #undef NVMPROXY_STOP_SEC_CODE
    #define STOP_SEC_CODE

#elif defined NVMPROXY_START_SEC_CONST_UNSPECIFIED
    #undef NVMPROXY_START_SEC_CONST_UNSPECIFIED
    #define START_SEC_CONST_UNSPECIFIED

#elif defined NVMPROXY_STOP_SEC_CONST_UNSPECIFIED
    #undef NVMPROXY_STOP_SEC_CONST_UNSPECIFIED
    #define STOP_SEC_CONST

/* Variables */
#elif defined NVMPROXY_START_SEC_VAR_CLEARED_16
    #undef NVMPROXY_START_SEC_VAR_CLEARED_16
    #define START_SEC_VAR_CLEARED_16_GLOBALSHARED

#elif defined NVMPROXY_STOP_SEC_VAR_CLEARED_16
    #undef NVMPROXY_STOP_SEC_VAR_CLEARED_16
    #define STOP_SEC_VAR
	
#elif defined NVMPROXY_START_SEC_VAR_CLEARED_UNSPECIFIED
    #undef NVMPROXY_START_SEC_VAR_CLEARED_UNSPECIFIED
    #define START_SEC_VAR_CLEARED_UNSPECIFIED_GLOBALSHARED

#elif defined NVMPROXY_STOP_SEC_VAR_CLEARED_UNSPECIFIED
    #undef NVMPROXY_STOP_SEC_VAR_CLEARED_UNSPECIFIED
    #define STOP_SEC_VAR

#elif defined NVMPROXY_START_SEC_VAR_NOINIT_8
    #undef NVMPROXY_START_SEC_VAR_NOINIT_8
    #define START_SEC_VAR_NOINIT_8_9

#elif defined NVMPROXY_STOP_SEC_VAR_NOINIT_8
    #undef NVMPROXY_STOP_SEC_VAR_NOINIT_8
    #define STOP_SEC_VAR
#endif
/**********************************************************************************************************************
 *  NvmProxy END
 *********************************************************************************************************************/

 /**********************************************************************************************************************
 *  OvrVoltMon START
 *********************************************************************************************************************/
/* VAR sections */

#ifdef OVRVOLTMON_START_SEC_VAR_CLEARED_16
	#undef OVRVOLTMON_START_SEC_VAR_CLEARED_16
	#define START_SEC_VAR_NOINIT_16_10
#endif

#ifdef OVRVOLTMON_STOP_SEC_VAR_CLEARED_16
	#undef OVRVOLTMON_STOP_SEC_VAR_CLEARED_16
	#define STOP_SEC_VAR
#endif

/**********************************************************************************************************************
 *  OvrVoltMon END
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  PAwTO START
 *********************************************************************************************************************/
/* CONST sections */
#ifdef PAWTO_START_SEC_CONST_8
	#undef PAWTO_START_SEC_CONST_8
	#define START_SEC_CONST_8BIT
#endif

#ifdef PAWTO_STOP_SEC_CONST_8
	#undef PAWTO_STOP_SEC_CONST_8
	#define STOP_SEC_CONST
#endif

/* VAR sections */

#ifdef PAWTO_START_SEC_VAR_CLEARED_8
    #undef PAWTO_START_SEC_VAR_CLEARED_8
    #define START_SEC_VAR_NOINIT_8_10
#endif

#ifdef PAWTO_STOP_SEC_VAR_CLEARED_8
    #undef PAWTO_STOP_SEC_VAR_CLEARED_8
    #define STOP_SEC_VAR
#endif

#ifdef PAWTO_START_SEC_VAR_CLEARED_BOOLEAN
    #undef PAWTO_START_SEC_VAR_CLEARED_BOOLEAN
    #define START_SEC_VAR_NOINIT_UNSPECIFIED_10
#endif

#ifdef PAWTO_STOP_SEC_VAR_CLEARED_BOOLEAN
    #undef PAWTO_STOP_SEC_VAR_CLEARED_BOOLEAN
    #define STOP_SEC_VAR
#endif

#ifdef PAWTO_START_SEC_VAR_NOINIT_32
	#undef PAWTO_START_SEC_VAR_NOINIT_32
	#define START_SEC_VAR_NOINIT_32_10
#endif

#ifdef PAWTO_STOP_SEC_VAR_NOINIT_32
	#undef PAWTO_STOP_SEC_VAR_NOINIT_32
	#define STOP_SEC_VAR
#endif

/**********************************************************************************************************************
 *  PAwTO END
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  PeakCurrEst START
 *********************************************************************************************************************/
/* Variables */
#ifdef PEAKCURREST_START_SEC_VAR_CLEARED_32
    #undef PEAKCURREST_START_SEC_VAR_CLEARED_32
    #define START_SEC_VAR_NOINIT_32_10
#endif

#ifdef PEAKCURREST_STOP_SEC_VAR_CLEARED_32
    #undef PEAKCURREST_STOP_SEC_VAR_CLEARED_32
    #define STOP_SEC_VAR
#endif

/**********************************************************************************************************************
 *  PeakCurrEst END
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  PICurrContrl START
 *********************************************************************************************************************/
/* Variables */
#ifdef PICURRCNTRL_START_SEC_VAR_CLEARED_32
    #undef PICURRCNTRL_START_SEC_VAR_CLEARED_32
    #define START_SEC_VAR_NOINIT_32_10
#endif

#ifdef PICURRCNTRL_STOP_SEC_VAR_CLEARED_32
    #undef PICURRCNTRL_STOP_SEC_VAR_CLEARED_32
    #define STOP_SEC_VAR
#endif

/**********************************************************************************************************************
 *  PICurrContrl END
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  PwmCdd START
 *********************************************************************************************************************/
/* VAR sections */

#ifdef PWMCDD_START_SEC_VAR_CLEARED_16
	# undef PWMCDD_START_SEC_VAR_CLEARED_16
	# define START_SEC_VAR_NOINIT_16_10
#endif

#ifdef PWMCDD_STOP_SEC_VAR_CLEARED_16
	# undef PWMCDD_STOP_SEC_VAR_CLEARED_16
	# define STOP_SEC_VAR
#endif

/**********************************************************************************************************************
 *  PwmCdd END
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  PwrLmtFuncCr START
 *********************************************************************************************************************/
/* VAR sections */

#ifdef PWRLMTFUNCCR_START_SEC_VAR_CLEARED_32
	# undef PWRLMTFUNCCR_START_SEC_VAR_CLEARED_32
	# define START_SEC_VAR_NOINIT_32_10
#endif

#ifdef PWRLMTFUNCCR_STOP_SEC_VAR_CLEARED_32
	# undef PWRLMTFUNCCR_STOP_SEC_VAR_CLEARED_32
	# define STOP_SEC_VAR
#endif

#ifdef PWRLMTFUNCCR_START_SEC_VAR_CLEARED_BOOLEAN
    #undef PWRLMTFUNCCR_START_SEC_VAR_CLEARED_BOOLEAN
    #define START_SEC_VAR_NOINIT_8_10
#endif

#ifdef PWRLMTFUNCCR_STOP_SEC_VAR_CLEARED_BOOLEAN
    #undef PWRLMTFUNCCR_STOP_SEC_VAR_CLEARED_BOOLEAN
    #define STOP_SEC_VAR
#endif

#ifdef PWRLMTFUNCCR_START_SEC_VAR_CLEARED_UNSPECIFIED
	# undef PWRLMTFUNCCR_START_SEC_VAR_CLEARED_UNSPECIFIED
	# define START_SEC_VAR_NOINIT_UNSPECIFIED_10
#endif

#ifdef PWRLMTFUNCCR_STOP_SEC_VAR_CLEARED_UNSPECIFIED
	# undef PWRLMTFUNCCR_STOP_SEC_VAR_CLEARED_UNSPECIFIED
	# define STOP_SEC_VAR
#endif

/**********************************************************************************************************************
 *  PwrLmtFuncCr END
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  QuadDet START
 *********************************************************************************************************************/
/* VAR sections */
#ifdef QUADDET_START_SEC_VAR_INIT_8
	# undef QUADDET_START_SEC_VAR_INIT_8
	# define START_SEC_VAR_INIT_8_10
#endif

#ifdef QUADDET_STOP_SEC_VAR_INIT_8
	# undef QUADDET_STOP_SEC_VAR_INIT_8
	# define STOP_SEC_VAR
#endif

#ifdef QUADDET_START_SEC_VAR_INIT_32
	# undef QUADDET_START_SEC_VAR_INIT_32
	# define START_SEC_VAR_INIT_32_10
#endif

#ifdef QUADDET_STOP_SEC_VAR_INIT_32
	# undef QUADDET_STOP_SEC_VAR_INIT_32
	# define STOP_SEC_VAR
#endif

/**********************************************************************************************************************
 *  QuadDet END
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  ResetCause START
 *********************************************************************************************************************/

#ifdef RESETCAUSE_START_SEC_VAR_POWER_ON_CLEARED_8
	#undef RESETCAUSE_START_SEC_VAR_POWER_ON_CLEARED_8
	#pragma SET_DATA_SECTION(".resetcause")
    #undef MEMMAP_ERROR
#endif

#ifdef RESETCAUSE_STOP_SEC_VAR_POWER_ON_CLEARED_8
	#undef RESETCAUSE_STOP_SEC_VAR_POWER_ON_CLEARED_8
	#define STOP_SEC_VAR
#endif

/**********************************************************************************************************************
 *  ResetCause END
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  Return START
 *********************************************************************************************************************/

/* Variables */
#ifdef RETURN_START_SEC_VAR_CLEARED_32
    #undef RETURN_START_SEC_VAR_CLEARED_32
    #define START_SEC_VAR_NOINIT_32_10
#endif

#ifdef RETURN_STOP_SEC_VAR_CLEARED_32
    #undef RETURN_STOP_SEC_VAR_CLEARED_32
    #define STOP_SEC_VAR
#endif

#ifdef RETURN_START_SEC_VAR_CLEARED_16
    #undef RETURN_START_SEC_VAR_CLEARED_16
    #define START_SEC_VAR_NOINIT_16_10
#endif

#ifdef RETURN_STOP_SEC_VAR_CLEARED_16
    #undef RETURN_STOP_SEC_VAR_CLEARED_16
    #define STOP_SEC_VAR
#endif

/**********************************************************************************************************************
 *  Return END
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  ReturnFirewall START
 *********************************************************************************************************************/

/* Variables */
#ifdef RETURNFIREWALL_START_SEC_VAR_CLEARED_32
    #undef RETURNFIREWALL_START_SEC_VAR_CLEARED_32
    #define START_SEC_VAR_NOINIT_32_10
#endif

#ifdef RETURNFIREWALL_STOP_SEC_VAR_CLEARED_32
    #undef RETURNFIREWALL_STOP_SEC_VAR_CLEARED_32
    #define STOP_SEC_VAR
#endif

#ifdef RETURNFIREWALL_START_SEC_VAR_CLEARED_BOOLEAN
	#undef RETURNFIREWALL_START_SEC_VAR_CLEARED_BOOLEAN
	#define START_SEC_VAR_NOINIT_UNSPECIFIED_10
#endif

#ifdef RETURNFIREWALL_STOP_SEC_VAR_CLEARED_BOOLEAN
	#undef RETURNFIREWALL_STOP_SEC_VAR_CLEARED_BOOLEAN
	#define STOP_SEC_VAR
#endif
/**********************************************************************************************************************
 *  ReturnFirewall END
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  ShtdnMech START
 *********************************************************************************************************************/

/* Variables */
#ifdef SHTDNMECH_START_SEC_VAR_CLEARED_32
    #undef SHTDNMECH_START_SEC_VAR_CLEARED_32
    #define START_SEC_VAR_NOINIT_32_10
#endif

#ifdef SHTDNMECH_STOP_SEC_VAR_CLEARED_32
    #undef SHTDNMECH_STOP_SEC_VAR_CLEARED_32
    #define STOP_SEC_VAR
#endif

#ifdef SHTDNMECH_START_SEC_VAR_CLEARED_8
	#undef SHTDNMECH_START_SEC_VAR_CLEARED_8
	#define START_SEC_VAR_NOINIT_8_10
#endif

#ifdef SHTDNMECH_STOP_SEC_VAR_CLEARED_8
	#undef SHTDNMECH_STOP_SEC_VAR_CLEARED_8
	#define STOP_SEC_VAR
#endif
/**********************************************************************************************************************
 *  ShtdnMech END
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  SignlCondn START
 *********************************************************************************************************************/
/* VAR sections */

#ifdef SIGNLCONDN_START_SEC_VAR_NOINIT_32
	#undef SIGNLCONDN_START_SEC_VAR_NOINIT_32
	#define START_SEC_VAR_NOINIT_32_10
#endif

#ifdef SIGNLCONDN_STOP_SEC_VAR_NOINIT_32
	#undef SIGNLCONDN_STOP_SEC_VAR_NOINIT_32
	#define STOP_SEC_VAR
#endif

/**********************************************************************************************************************
 *  SignlCondn END
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  SrlComInput START
 *********************************************************************************************************************/

/* Type H Variables */
 #ifdef SRLCOMINPUT_START_SEC_VAR_SAVED_ZONEH_8
    #define VAR_SEC_OPEN
	#pragma SET_DATA_SECTION(".ossDataAp_9:noinit:typeH:SrlComInput")
    #undef SRLCOMINPUT_START_SEC_VAR_SAVED_ZONEH_8
    #undef MEMMAP_ERROR
#endif
#ifdef SRLCOMINPUT_STOP_SEC_VAR_SAVED_ZONEH_8
    #undef SRLCOMINPUT_STOP_SEC_VAR_SAVED_ZONEH_8
    #define STOP_SEC_VAR
#endif

 #ifdef SRLCOMINPUT_START_SEC_VAR_SAVED_ZONEH_16
    #define VAR_SEC_OPEN
	#pragma SET_DATA_SECTION(".ossDataAp_9:noinit:typeH:SrlComInput")
    #undef SRLCOMINPUT_START_SEC_VAR_SAVED_ZONEH_16
    #undef MEMMAP_ERROR
#endif
#ifdef SRLCOMINPUT_STOP_SEC_VAR_SAVED_ZONEH_16
    #undef SRLCOMINPUT_STOP_SEC_VAR_SAVED_ZONEH_16
    #define STOP_SEC_VAR
#endif

/**********************************************************************************************************************
 *  SrlComInput END
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  SrlComOutput START
 *********************************************************************************************************************/
/* VAR sections */

#ifdef SRLCOMOUTPUT_START_SEC_VAR_CLEARED_8
	#undef SRLCOMOUTPUT_START_SEC_VAR_CLEARED_8
	#define START_SEC_VAR_NOINIT_8_9
#endif

#ifdef SRLCOMOUTPUT_STOP_SEC_VAR_CLEARED_8
	#undef SRLCOMOUTPUT_STOP_SEC_VAR_CLEARED_8
	#define STOP_SEC_VAR
#endif

#ifdef SRLCOMOUTPUT_START_SEC_VAR_CLEARED_32
	#undef SRLCOMOUTPUT_START_SEC_VAR_CLEARED_32
	#define START_SEC_VAR_NOINIT_32_9
#endif

#ifdef SRLCOMOUTPUT_STOP_SEC_VAR_CLEARED_32
	#undef SRLCOMOUTPUT_STOP_SEC_VAR_CLEARED_32
	#define STOP_SEC_VAR
#endif

#ifdef SRLCOMOUTPUT_START_SEC_VAR_CLEARED_BOOLEAN
	#undef SRLCOMOUTPUT_START_SEC_VAR_CLEARED_BOOLEAN
	#define START_SEC_VAR_NOINIT_8_9
#endif

#ifdef SRLCOMOUTPUT_STOP_SEC_VAR_CLEARED_BOOLEAN
	#undef SRLCOMOUTPUT_STOP_SEC_VAR_CLEARED_BOOLEAN
	#define STOP_SEC_VAR
#endif

/**********************************************************************************************************************
 *  SrlComOutput END
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  StabilityComp START
 *********************************************************************************************************************/
/* Variables */
#ifdef STABILITYCOMP_START_SEC_VAR_CLEARED_32
    #undef STABILITYCOMP_START_SEC_VAR_CLEARED_32
    #define START_SEC_VAR_CLEARED_32_10
#endif

#ifdef STABILITYCOMP_STOP_SEC_VAR_CLEARED_32
    #undef STABILITYCOMP_STOP_SEC_VAR_CLEARED_32
    #define STOP_SEC_VAR
#endif

#ifdef STABILITYCOMP_START_SEC_VAR_CLEARED_16
    #undef STABILITYCOMP_START_SEC_VAR_CLEARED_16
    #define START_SEC_VAR_CLEARED_16_10
#endif

#ifdef STABILITYCOMP_STOP_SEC_VAR_CLEARED_16
    #undef STABILITYCOMP_STOP_SEC_VAR_CLEARED_16
    #define STOP_SEC_VAR
#endif

#ifdef STABILITYCOMP_START_SEC_VAR_CLEARED_BOOLEAN
    #undef STABILITYCOMP_START_SEC_VAR_CLEARED_BOOLEAN
    #define START_SEC_VAR_CLEARED_UNSPECIFIED_10
#endif

#ifdef STABILITYCOMP_STOP_SEC_VAR_CLEARED_BOOLEAN
    #undef STABILITYCOMP_STOP_SEC_VAR_CLEARED_BOOLEAN
    #define STOP_SEC_VAR
#endif

#ifdef STABILITYCOMP_START_SEC_VAR_CLEARED_UNSPECIFIED
    #undef STABILITYCOMP_START_SEC_VAR_CLEARED_UNSPECIFIED
    #define START_SEC_VAR_CLEARED_UNSPECIFIED_10
#endif

#ifdef STABILITYCOMP_STOP_SEC_VAR_CLEARED_UNSPECIFIED
    #undef STABILITYCOMP_STOP_SEC_VAR_CLEARED_UNSPECIFIED
    #define STOP_SEC_VAR
#endif

/**********************************************************************************************************************
 *  StabilityComp END
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  StabilityComp2 START
 *********************************************************************************************************************/
/* Variables */
#ifdef STABILITYCOMP2_START_SEC_VAR_CLEARED_32
    #undef STABILITYCOMP2_START_SEC_VAR_CLEARED_32
    #define START_SEC_VAR_CLEARED_32_8
#endif

#ifdef STABILITYCOMP2_STOP_SEC_VAR_CLEARED_32
    #undef STABILITYCOMP2_STOP_SEC_VAR_CLEARED_32
    #define STOP_SEC_VAR
#endif

#ifdef STABILITYCOMP2_START_SEC_VAR_CLEARED_UNSPECIFIED
    #undef STABILITYCOMP2_START_SEC_VAR_CLEARED_UNSPECIFIED
    #define START_SEC_VAR_CLEARED_UNSPECIFIED_8
#endif

#ifdef STABILITYCOMP2_STOP_SEC_VAR_CLEARED_UNSPECIFIED
    #undef STABILITYCOMP2_STOP_SEC_VAR_CLEARED_UNSPECIFIED
    #define STOP_SEC_VAR
#endif

/**********************************************************************************************************************
 *  StabilityComp2 END
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  StaMd START
 *********************************************************************************************************************/
/* CONST sections */
#ifdef STAMD_START_SEC_CONST_UNSPECIFIED
	#undef STAMD_START_SEC_CONST_UNSPECIFIED
	#undef MEMMAP_ERROR
#endif

#ifdef STAMD_STOP_SEC_CONST_UNSPECIFIED
	#undef STAMD_STOP_SEC_CONST_UNSPECIFIED
	#undef MEMMAP_ERROR
#endif

#ifdef STAMD_START_SEC_VAR_SAVED_ZONEHGS_8
	#undef STAMD_START_SEC_VAR_SAVED_ZONEHGS_8
	#define START_SEC_VAR_CLEARED_8_GLOBALSHARED
#endif

#ifdef STAMD_STOP_SEC_VAR_SAVED_ZONEHGS_8
    #undef STAMD_STOP_SEC_VAR_SAVED_ZONEHGS_8
    #define STOP_SEC_VAR
#endif

#ifdef STAMD_START_SEC_VAR_SAVED_ZONEHGS_32
	#undef STAMD_START_SEC_VAR_SAVED_ZONEHGS_32
	#define START_SEC_VAR_CLEARED_32_GLOBALSHARED
#endif

#ifdef STAMD_STOP_SEC_VAR_SAVED_ZONEHGS_32
    #undef STAMD_STOP_SEC_VAR_SAVED_ZONEHGS_32
    #define STOP_SEC_VAR
#endif

#ifdef STAMD10_START_SEC_VAR_INIT_UNSPECIFIED
	#undef STAMD10_START_SEC_VAR_INIT_UNSPECIFIED
	#define START_SEC_VAR_INIT_UNSPECIFIED_10
#endif

#ifdef STAMD10_STOP_SEC_VAR_INIT_UNSPECIFIED
	#undef STAMD10_STOP_SEC_VAR_INIT_UNSPECIFIED
	#define STOP_SEC_VAR
#endif

#ifdef STAMD10_START_SEC_VAR_CLEARED_16
	#undef STAMD10_START_SEC_VAR_CLEARED_16
	#define START_SEC_VAR_CLEARED_16_10
#endif

#ifdef STAMD10_STOP_SEC_VAR_CLEARED_16
	#undef STAMD10_STOP_SEC_VAR_CLEARED_16
	#define STOP_SEC_VAR
#endif

#ifdef STAMD10_START_SEC_VAR_CLEARED_32
	#undef STAMD10_START_SEC_VAR_CLEARED_32
	#define START_SEC_VAR_CLEARED_32_10
#endif

#ifdef STAMD10_STOP_SEC_VAR_CLEARED_32
	#undef STAMD10_STOP_SEC_VAR_CLEARED_32
	#define STOP_SEC_VAR
#endif

#ifdef STAMD10_START_SEC_VAR_CLEARED_8
	#undef STAMD10_START_SEC_VAR_CLEARED_8
	#define START_SEC_VAR_CLEARED_8_10
#endif

#ifdef STAMD10_STOP_SEC_VAR_CLEARED_8
	#undef STAMD10_STOP_SEC_VAR_CLEARED_8
	#define STOP_SEC_VAR
#endif

#ifdef STAMD10_START_SEC_VAR_CLEARED_BOOLEAN
	#undef STAMD10_START_SEC_VAR_CLEARED_BOOLEAN
	#define START_SEC_VAR_CLEARED_UNSPECIFIED_10
#endif

#ifdef STAMD10_STOP_SEC_VAR_CLEARED_BOOLEAN
	#undef STAMD10_STOP_SEC_VAR_CLEARED_BOOLEAN
	#define STOP_SEC_VAR
#endif

#ifdef STAMD9_START_SEC_VAR_INIT_UNSPECIFIED
	#undef STAMD9_START_SEC_VAR_INIT_UNSPECIFIED
	#define START_SEC_VAR_INIT_UNSPECIFIED_9
#endif

#ifdef STAMD9_STOP_SEC_VAR_INIT_UNSPECIFIED
	#undef STAMD9_STOP_SEC_VAR_INIT_UNSPECIFIED
	#define STOP_SEC_VAR
#endif

#ifdef STAMD9_START_SEC_VAR_CLEARED_32
	#undef STAMD9_START_SEC_VAR_CLEARED_32
	#define START_SEC_VAR_CLEARED_32_9
#endif

#ifdef STAMD9_STOP_SEC_VAR_CLEARED_32
	#undef STAMD9_STOP_SEC_VAR_CLEARED_32
	#define STOP_SEC_VAR
#endif

#ifdef STAMD9_START_SEC_VAR_CLEARED_BOOLEAN
	#undef STAMD9_START_SEC_VAR_CLEARED_BOOLEAN
	#define START_SEC_VAR_CLEARED_UNSPECIFIED_9
#endif

#ifdef STAMD9_STOP_SEC_VAR_CLEARED_BOOLEAN
	#undef STAMD9_STOP_SEC_VAR_CLEARED_BOOLEAN
	#define STOP_SEC_VAR
#endif

#ifdef STAMD8_START_SEC_VAR_INIT_UNSPECIFIED
	#undef STAMD8_START_SEC_VAR_INIT_UNSPECIFIED
	#define START_SEC_VAR_INIT_UNSPECIFIED_8
#endif

#ifdef STAMD8_STOP_SEC_VAR_INIT_UNSPECIFIED
	#undef STAMD8_STOP_SEC_VAR_INIT_UNSPECIFIED
	#define STOP_SEC_VAR
#endif

#ifdef STAMD8_START_SEC_VAR_CLEARED_32
	#undef STAMD8_START_SEC_VAR_CLEARED_32
	#define START_SEC_VAR_CLEARED_32_8
#endif

#ifdef STAMD8_STOP_SEC_VAR_CLEARED_32
	#undef STAMD8_STOP_SEC_VAR_CLEARED_32
	#define STOP_SEC_VAR
#endif

/**********************************************************************************************************************
 *  StaMd END
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  StbCTO START
 *********************************************************************************************************************/
/* Variables */
#ifdef STBCTO_START_SEC_VAR_NOINIT_32
    #undef STBCTO_START_SEC_VAR_NOINIT_32
    #define START_SEC_VAR_NOINIT_32_10
#endif

#ifdef STBCTO_STOP_SEC_VAR_NOINIT_32
    #undef STBCTO_STOP_SEC_VAR_NOINIT_32
    #define STOP_SEC_VAR
#endif

#ifdef STBCTO_START_SEC_VAR_CLEARED_32
    #undef STBCTO_START_SEC_VAR_CLEARED_32
    #define START_SEC_VAR_CLEARED_32_10
#endif

#ifdef STBCTO_STOP_SEC_VAR_CLEARED_32
    #undef STBCTO_STOP_SEC_VAR_CLEARED_32
    #define STOP_SEC_VAR
#endif

#ifdef STBCTO_START_SEC_VAR_CLEARED_BOOLEAN
	#undef STBCTO_START_SEC_VAR_CLEARED_BOOLEAN
	#define START_SEC_VAR_CLEARED_UNSPECIFIED_10
#endif

#ifdef STBCTO_STOP_SEC_VAR_CLEARED_BOOLEAN
	#undef STBCTO_STOP_SEC_VAR_CLEARED_BOOLEAN
	#define STOP_SEC_VAR
#endif

#ifdef STBCTO_START_SEC_VAR_CLEARED_8
    #undef STBCTO_START_SEC_VAR_CLEARED_8
    #define START_SEC_VAR_CLEARED_8_10
#endif

#ifdef STBCTO_STOP_SEC_VAR_CLEARED_8
    #undef STBCTO_STOP_SEC_VAR_CLEARED_8
    #define STOP_SEC_VAR
#endif

#ifdef STBCTO_START_SEC_VAR_CLEARED_UNSPECIFIED
    #undef STBCTO_START_SEC_VAR_CLEARED_UNSPECIFIED
    #define START_SEC_VAR_CLEARED_UNSPECIFIED_10
#endif

#ifdef STBCTO_STOP_SEC_VAR_CLEARED_UNSPECIFIED
    #undef STBCTO_STOP_SEC_VAR_CLEARED_UNSPECIFIED
    #define STOP_SEC_VAR
#endif

/**********************************************************************************************************************
 *  StbCTO END
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  StOpCtrl START
 *********************************************************************************************************************/
/* Variables */
#ifdef STOPCTRL_START_SEC_VAR_NOINIT_32
    #undef STOPCTRL_START_SEC_VAR_NOINIT_32
    #define START_SEC_VAR_CLEARED_32_10
#endif

#ifdef STOPCTRL_STOP_SEC_VAR_NOINIT_32
    #undef STOPCTRL_STOP_SEC_VAR_NOINIT_32
    #define STOP_SEC_VAR
#endif

#ifdef STOPCTRL_START_SEC_VAR_NOINIT_UNSPECIFIED
    #undef STOPCTRL_START_SEC_VAR_NOINIT_UNSPECIFIED
    #define START_SEC_VAR_CLEARED_UNSPECIFIED_10
#endif

#ifdef STOPCTRL_STOP_SEC_VAR_NOINIT_UNSPECIFIED
    #undef STOPCTRL_STOP_SEC_VAR_NOINIT_UNSPECIFIED
    #define STOP_SEC_VAR
#endif

/**********************************************************************************************************************
 *  StOpCtrl END
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  ThrmlDutyCycle START
 *********************************************************************************************************************/
/* Type H Variables */
 #ifdef THRMLDUTYCYCLE_START_SEC_VAR_SAVED_ZONEH_8
    #define VAR_SEC_OPEN
	#pragma SET_DATA_SECTION(".ossDataAp_9:noinit:typeH:ThrmlDutyCycle")
    #undef THRMLDUTYCYCLE_START_SEC_VAR_SAVED_ZONEH_8
    #undef MEMMAP_ERROR
#endif
#ifdef THRMLDUTYCYCLE_STOP_SEC_VAR_SAVED_ZONEH_8
    #undef THRMLDUTYCYCLE_STOP_SEC_VAR_SAVED_ZONEH_8
    #define STOP_SEC_VAR
#endif

/* Variables */
#ifdef THRMLDUTYCYCLE_START_SEC_VAR_CLEARED_16
    #undef THRMLDUTYCYCLE_START_SEC_VAR_CLEARED_16
    #define START_SEC_VAR_NOINIT_16_9
#endif

#ifdef THRMLDUTYCYCLE_STOP_SEC_VAR_CLEARED_16
    #undef THRMLDUTYCYCLE_STOP_SEC_VAR_CLEARED_16
    #define STOP_SEC_VAR
#endif

#ifdef THRMLDUTYCYCLE_START_SEC_VAR_CLEARED_32
    #undef THRMLDUTYCYCLE_START_SEC_VAR_CLEARED_32
    #define START_SEC_VAR_NOINIT_32_9
#endif

#ifdef THRMLDUTYCYCLE_STOP_SEC_VAR_CLEARED_32
    #undef THRMLDUTYCYCLE_STOP_SEC_VAR_CLEARED_32
    #define STOP_SEC_VAR
#endif

#ifdef THRMLDUTYCYCLE_START_SEC_VAR_CLEARED_UNSPECIFIED
    #undef THRMLDUTYCYCLE_START_SEC_VAR_CLEARED_UNSPECIFIED
    #define START_SEC_VAR_NOINIT_UNSPECIFIED_9
#endif

#ifdef THRMLDUTYCYCLE_STOP_SEC_VAR_CLEARED_UNSPECIFIED
    #undef THRMLDUTYCYCLE_STOP_SEC_VAR_CLEARED_UNSPECIFIED
    #define STOP_SEC_VAR
#endif

/**********************************************************************************************************************
 *  ThrmlDutyCycle END
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  TmprlMon START
 *********************************************************************************************************************/
/* CONST sections */

#ifdef TMPRLMON_START_SEC_CONST_UNSPECIFIED
	#undef TMPRLMON_START_SEC_CONST_UNSPECIFIED
	#define START_SEC_CONST_UNSPECIFIED
#endif

#ifdef TMPRLMON_STOP_SEC_CONST_UNSPECIFIED
	#undef TMPRLMON_STOP_SEC_CONST_UNSPECIFIED
	#define STOP_SEC_CONST
#endif

/* VAR sections */

#ifdef TMPRLMON_START_SEC_VAR_CLEARED_8
	#undef TMPRLMON_START_SEC_VAR_CLEARED_8
	#define START_SEC_VAR_CLEARED_8_10
#endif

#ifdef TMPRLMON_STOP_SEC_VAR_CLEARED_8
	#undef TMPRLMON_STOP_SEC_VAR_CLEARED_8
	#define STOP_SEC_VAR
#endif

#ifdef TMPRLMON_START_SEC_VAR_CLEARED_32
	#undef TMPRLMON_START_SEC_VAR_CLEARED_32
	#define START_SEC_VAR_CLEARED_32_10
#endif

#ifdef TMPRLMON_STOP_SEC_VAR_CLEARED_32
	#undef TMPRLMON_STOP_SEC_VAR_CLEARED_32
	#define STOP_SEC_VAR
#endif

#ifdef TMPRLMON_START_SEC_VAR_CLEARED_16
	#undef TMPRLMON_START_SEC_VAR_CLEARED_16
	#define START_SEC_VAR_CLEARED_16_10
#endif

#ifdef TMPRLMON_STOP_SEC_VAR_CLEARED_16
	#undef TMPRLMON_STOP_SEC_VAR_CLEARED_16
	#define STOP_SEC_VAR
#endif

#ifdef TMPRLMON_START_SEC_VAR_CLEARED_UNSPECIFIED
	#undef TMPRLMON_START_SEC_VAR_CLEARED_UNSPECIFIED
	#define START_SEC_VAR_CLEARED_UNSPECIFIED_10
#endif

#ifdef TMPRLMON_STOP_SEC_VAR_CLEARED_UNSPECIFIED
	#undef TMPRLMON_STOP_SEC_VAR_CLEARED_UNSPECIFIED
	#define STOP_SEC_VAR
#endif

#ifdef TMPRLMON_START_SEC_VAR_CLEARED_BOOLEAN
	#undef TMPRLMON_START_SEC_VAR_CLEARED_BOOLEAN
	#define START_SEC_VAR_CLEARED_BOOLEAN_10
#endif

#ifdef TMPRLMON_STOP_SEC_VAR_CLEARED_BOOLEAN
	#undef TMPRLMON_STOP_SEC_VAR_CLEARED_BOOLEAN
	#define STOP_SEC_VAR
#endif

/**********************************************************************************************************************
 *  TmprlMon END
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  TrqCanc START
 *********************************************************************************************************************/
/* CONST sections */

#ifdef TRQCANC_START_SEC_CONST_16
	#undef TRQCANC_START_SEC_CONST_16
	#define START_SEC_CONST_16BIT
#endif

#ifdef TRQCANC_STOP_SEC_CONST_16
	#undef TRQCANC_STOP_SEC_CONST_16
	#define STOP_SEC_CONST
#endif

/* Variables */
#ifdef TRQCANC_START_SEC_VAR_CLEARED_16
    #undef TRQCANC_START_SEC_VAR_CLEARED_16
    #define START_SEC_VAR_NOINIT_16_10
#endif

#ifdef TRQCANC_STOP_SEC_VAR_CLEARED_16
    #undef TRQCANC_STOP_SEC_VAR_CLEARED_16
    #define STOP_SEC_VAR
#endif

#ifdef TRQCANC_START_SEC_VAR_CLEARED_32
    #undef TRQCANC_START_SEC_VAR_CLEARED_32
    #define START_SEC_VAR_NOINIT_32_10
#endif

#ifdef TRQCANC_STOP_SEC_VAR_CLEARED_32
    #undef TRQCANC_STOP_SEC_VAR_CLEARED_32
    #define STOP_SEC_VAR
#endif

/**********************************************************************************************************************
 *  TrqCanc END
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  TqRsDg START
 *********************************************************************************************************************/
/* Variables */
#ifdef TQRSDG_START_SEC_VAR_CLEARED_32
    #undef TQRSDG_START_SEC_VAR_CLEARED_32
    #define START_SEC_VAR_CLEARED_32_10
#endif

#ifdef TQRSDG_STOP_SEC_VAR_CLEARED_32
    #undef TQRSDG_STOP_SEC_VAR_CLEARED_32
    #define STOP_SEC_VAR
#endif

#ifdef TQRSDG_START_SEC_VAR_CLEARED_16
    #undef TQRSDG_START_SEC_VAR_CLEARED_16
    #define START_SEC_VAR_CLEARED_16_10
#endif

#ifdef TQRSDG_STOP_SEC_VAR_CLEARED_16
    #undef TQRSDG_STOP_SEC_VAR_CLEARED_16
    #define STOP_SEC_VAR
#endif

#ifdef TQRSDG_START_SEC_VAR_CLEARED_8
    #undef TQRSDG_START_SEC_VAR_CLEARED_8
    #define START_SEC_VAR_CLEARED_8_10
#endif

#ifdef TQRSDG_STOP_SEC_VAR_CLEARED_8
    #undef TQRSDG_STOP_SEC_VAR_CLEARED_8
    #define STOP_SEC_VAR
#endif

#ifdef TQRSDG_START_SEC_VAR_NOINIT_UNSPECIFIED
    #undef TQRSDG_START_SEC_VAR_NOINIT_UNSPECIFIED
    #define START_SEC_VAR_NOINIT_UNSPECIFIED_10
#endif

#ifdef TQRSDG_STOP_SEC_VAR_NOINIT_UNSPECIFIED
    #undef TQRSDG_STOP_SEC_VAR_NOINIT_UNSPECIFIED
    #define STOP_SEC_VAR
#endif

/**********************************************************************************************************************
 *  TqRsDg END
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  TuningSelAuth START
 *********************************************************************************************************************/
/* Variables */
#ifdef TUNINGSELAUTH_START_SEC_VAR_CLEARED_16
    #undef TUNINGSELAUTH_START_SEC_VAR_CLEARED_16
    #define START_SEC_VAR_CLEARED_16_10
#endif

#ifdef TUNINGSELAUTH_STOP_SEC_VAR_CLEARED_16
    #undef TUNINGSELAUTH_STOP_SEC_VAR_CLEARED_16
    #define STOP_SEC_VAR
#endif

#ifdef TUNINGSELAUTH_START_SEC_VAR_CLEARED_UNSPECIFIED
    #undef TUNINGSELAUTH_START_SEC_VAR_CLEARED_UNSPECIFIED
    #define START_SEC_VAR_CLEARED_UNSPECIFIED_10
#endif

#ifdef TUNINGSELAUTH_STOP_SEC_VAR_CLEARED_UNSPECIFIED
    #undef TUNINGSELAUTH_STOP_SEC_VAR_CLEARED_UNSPECIFIED
    #define STOP_SEC_VAR
#endif

/**********************************************************************************************************************
 *  TuningSelAuth END
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  uDiag START
 *********************************************************************************************************************/
/* CONST sections */

#ifdef UDIAG_START_SEC_CONST_UNSPECIFIED
	#undef MEMMAP_ERROR
	#undef UDIAG_START_SEC_CONST_UNSPECIFIED
#endif

#ifdef UDIAG_STOP_SEC_CONST_UNSPECIFIED
	#undef MEMMAP_ERROR
	#undef UDIAG_STOP_SEC_CONST_UNSPECIFIED
#endif

/* VAR sections */

#ifdef UDIAG_START_SEC_VAR_CLEARED_BOOLEAN
	#undef UDIAG_START_SEC_VAR_CLEARED_BOOLEAN
	#define START_SEC_VAR_NOINIT_UNSPECIFIED_10
#endif

#ifdef UDIAG_STOP_SEC_VAR_CLEARED_BOOLEAN
	#undef UDIAG_STOP_SEC_VAR_CLEARED_BOOLEAN
	#define STOP_SEC_VAR
#endif

#ifdef UDIAG_START_SEC_VAR_CLEARED_16
	#undef UDIAG_START_SEC_VAR_CLEARED_16
	#define START_SEC_VAR_NOINIT_16_10
#endif

#ifdef UDIAG_STOP_SEC_VAR_CLEARED_16
	#undef UDIAG_STOP_SEC_VAR_CLEARED_16
	#define STOP_SEC_VAR
#endif

#ifdef UDIAG_START_SEC_VAR_CLEARED_UNSPECIFIED
	#undef UDIAG_START_SEC_VAR_CLEARED_UNSPECIFIED
	#define START_SEC_VAR_NOINIT_UNSPECIFIED_10
#endif

#ifdef UDIAG_STOP_SEC_VAR_CLEARED_UNSPECIFIED
	#undef UDIAG_STOP_SEC_VAR_CLEARED_UNSPECIFIED
	#define STOP_SEC_VAR
#endif

#ifdef UDIAG_START_SEC_VAR_CLEARED_32
	#undef UDIAG_START_SEC_VAR_CLEARED_32
	#define START_SEC_VAR_NOINIT_32_10
#endif

#ifdef UDIAG_STOP_SEC_VAR_CLEARED_32
	#undef UDIAG_STOP_SEC_VAR_CLEARED_32
	#define STOP_SEC_VAR
#endif

#ifdef UDIAG_START_SEC_VAR_SAVED_UNSPECIFIED
	#define VAR_SEC_OPEN
	#pragma SET_DATA_SECTION(".noclear")
	#undef MEMMAP_ERROR
    #undef UDIAG_START_SEC_VAR_SAVED_UNSPECIFIED
#endif

#ifdef UDIAG_STOP_SEC_VAR_SAVED_UNSPECIFIED
    #undef UDIAG_STOP_SEC_VAR_SAVED_UNSPECIFIED
    #define STOP_SEC_VAR
#endif

/**********************************************************************************************************************
 *  uDiag END
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  VehPwrMd START
 *********************************************************************************************************************/

/* Variables */
#ifdef VEHPWRMD_START_SEC_VAR_CLEARED_BOOLEAN
    #undef VEHPWRMD_START_SEC_VAR_CLEARED_BOOLEAN
    #define START_SEC_VAR_NOINIT_UNSPECIFIED_9
#endif

#ifdef VEHPWRMD_STOP_SEC_VAR_CLEARED_BOOLEAN
    #undef VEHPWRMD_STOP_SEC_VAR_CLEARED_BOOLEAN
    #define STOP_SEC_VAR
#endif
/**********************************************************************************************************************
 *  VehPwrMd END
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  VehSpdLmt START
 *********************************************************************************************************************/

/* Variables */
#ifdef VEHSPDLMT_START_SEC_VAR_CLEARED_16
    #undef VEHSPDLMT_START_SEC_VAR_CLEARED_16
    #define START_SEC_VAR_NOINIT_16_9
#endif

#ifdef VEHSPDLMT_STOP_SEC_VAR_CLEARED_16
    #undef VEHSPDLMT_STOP_SEC_VAR_CLEARED_16
    #define STOP_SEC_VAR
#endif

/**********************************************************************************************************************
 *  VehSpdLmt END
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  WhlImbRej START
 *********************************************************************************************************************/
/* Type H Variables */
 #ifdef WHLIMBREJ_START_SEC_VAR_SAVED_ZONEH_32
    #define VAR_SEC_OPEN
	#pragma SET_DATA_SECTION(".ossDataAp_10:noinit:typeH:WhlImbRej")
    #undef WHLIMBREJ_START_SEC_VAR_SAVED_ZONEH_32
    #undef MEMMAP_ERROR
#endif

#ifdef WHLIMBREJ_STOP_SEC_VAR_SAVED_ZONEH_32
    #undef WHLIMBREJ_STOP_SEC_VAR_SAVED_ZONEH_32
    #define STOP_SEC_VAR
#endif

/* Variables */
#ifdef WHLIMBREJ_START_SEC_VAR_CLEARED_32
    #undef WHLIMBREJ_START_SEC_VAR_CLEARED_32
    #define START_SEC_VAR_NOINIT_32_10
#endif

#ifdef WHLIMBREJ_STOP_SEC_VAR_CLEARED_32
    #undef WHLIMBREJ_STOP_SEC_VAR_CLEARED_32
    #define STOP_SEC_VAR
#endif

#ifdef WHLIMBREJ_START_SEC_VAR_CLEARED_16
    #undef WHLIMBREJ_START_SEC_VAR_CLEARED_16
    #define START_SEC_VAR_NOINIT_16_10
#endif

#ifdef WHLIMBREJ_STOP_SEC_VAR_CLEARED_16
    #undef WHLIMBREJ_STOP_SEC_VAR_CLEARED_16
    #define STOP_SEC_VAR
#endif

#ifdef WHLIMBREJ_START_SEC_VAR_CLEARED_BOOLEAN
    #undef WHLIMBREJ_START_SEC_VAR_CLEARED_BOOLEAN
    #define START_SEC_VAR_NOINIT_UNSPECIFIED_10
#endif

#ifdef WHLIMBREJ_STOP_SEC_VAR_CLEARED_BOOLEAN
    #undef WHLIMBREJ_STOP_SEC_VAR_CLEARED_BOOLEAN
    #define STOP_SEC_VAR
#endif

#ifdef WHLIMBREJ_START_SEC_VAR_CLEARED_UNSPECIFIED
    #undef WHLIMBREJ_START_SEC_VAR_CLEARED_UNSPECIFIED
    #define START_SEC_VAR_NOINIT_UNSPECIFIED_10
#endif

#ifdef WHLIMBREJ_STOP_SEC_VAR_CLEARED_UNSPECIFIED
    #undef WHLIMBREJ_STOP_SEC_VAR_CLEARED_UNSPECIFIED
    #define STOP_SEC_VAR
#endif

/**********************************************************************************************************************
 *  WhlImbRej END
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  WIRInputQual START
 *********************************************************************************************************************/

/* Variables */
#ifdef WIRINPUTQUAL_START_SEC_VAR_CLEARED_16
    #undef WIRINPUTQUAL_START_SEC_VAR_CLEARED_16
    #define START_SEC_VAR_NOINIT_16_10
#endif

#ifdef WIRINPUTQUAL_STOP_SEC_VAR_CLEARED_16
    #undef WIRINPUTQUAL_STOP_SEC_VAR_CLEARED_16
    #define STOP_SEC_VAR
#endif

#ifdef WIRINPUTQUAL_START_SEC_VAR_CLEARED_32
    #undef WIRINPUTQUAL_START_SEC_VAR_CLEARED_32
    #define START_SEC_VAR_NOINIT_32_10
#endif

#ifdef WIRINPUTQUAL_STOP_SEC_VAR_CLEARED_32
    #undef WIRINPUTQUAL_STOP_SEC_VAR_CLEARED_32
    #define STOP_SEC_VAR
#endif

/**********************************************************************************************************************
 *  WIRInputQual END
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  AP_XCP START
 *********************************************************************************************************************/
/* Variables */
#if defined APXCP_START_SEC_VAR_CLEARED_8
    #undef APXCP_START_SEC_VAR_CLEARED_8
    #define START_SEC_VAR_CLEARED_8_9

#elif defined APXCP_STOP_SEC_VAR_CLEARED_8
    #undef APXCP_STOP_SEC_VAR_CLEARED_8
    #define STOP_SEC_VAR

#elif defined APXCP_START_SEC_VAR_CLEARED_UNSPECIFIED
    #undef APXCP_START_SEC_VAR_CLEARED_UNSPECIFIED
    #define START_SEC_VAR_CLEARED_UNSPECIFIED_9

#elif defined APXCP_STOP_SEC_VAR_CLEARED_UNSPECIFIED
    #undef APXCP_START_SEC_VAR_CLEARED_UNSPECIFIED
    #define STOP_SEC_VAR

#elif defined APXCP_START_SEC_VAR_CLEARED_BOOLEAN
    #undef APXCP_START_SEC_VAR_CLEARED_BOOLEAN
    #define START_SEC_VAR_CLEARED_BOOLEAN_9

#elif defined APXCP_STOP_SEC_VAR_CLEARED_BOOLEAN
    #undef APXCP_STOP_SEC_VAR_CLEARED_BOOLEAN
    #define STOP_SEC_VAR

#elif defined APXCP_START_SEC_VAR_NOINIT_8
    #undef APXCP_START_SEC_VAR_NOINIT_8
    #define START_SEC_VAR_NOINIT_8_9

#elif defined APXCP_STOP_SEC_VAR_NOINIT_8
    #undef APXCP_STOP_SEC_VAR_NOINIT_8
    #define STOP_SEC_VAR

#elif defined APXCP_START_SEC_VAR_NOINIT_32
    #undef APXCP_START_SEC_VAR_NOINIT_32
    #define START_SEC_VAR_NOINIT_32_9

#elif defined APXCP_STOP_SEC_VAR_NOINIT_32
    #undef APXCP_STOP_SEC_VAR_NOINIT_32
    #define STOP_SEC_VAR

#elif defined APXCP_START_SEC_VAR_INIT_UNSPECIFIED
    #undef APXCP_START_SEC_VAR_INIT_UNSPECIFIED
    #define START_SEC_VAR_INIT_UNSPECIFIED_9

#elif defined APXCP_STOP_SEC_VAR_INIT_UNSPECIFIED
    #undef APXCP_START_SEC_VAR_INIT_UNSPECIFIED
    #define STOP_SEC_VAR

#endif
/**********************************************************************************************************************
 *  AP_XCP END
 *********************************************************************************************************************/

 /**********************************************************************************************************************
 *  FlsTst START
 *********************************************************************************************************************/
/* CONST sections */

#ifdef FLSTST_START_SEC_CONST_UNSPECIFIED
	#undef MEMMAP_ERROR
	#undef FLSTST_START_SEC_CONST_UNSPECIFIED
#endif

#ifdef FLSTST_STOP_SEC_CONST_UNSPECIFIED
	#undef MEMMAP_ERROR
	#undef FLSTST_STOP_SEC_CONST_UNSPECIFIED
#endif

/* VAR sections */

#ifdef FLSTST_START_SEC_VAR_UNSPECIFIED
	#undef FLSTST_START_SEC_VAR_UNSPECIFIED
	#define START_SEC_VAR_NOINIT_UNSPECIFIED_0
#endif

#ifdef FLSTST_STOP_SEC_VAR_UNSPECIFIED
	#undef FLSTST_STOP_SEC_VAR_UNSPECIFIED
	#define STOP_SEC_VAR
#endif

#ifdef FLSTST_START_SEC_VAR_16
	#undef FLSTST_START_SEC_VAR_16
	#define START_SEC_VAR_NOINIT_16_0
#endif

#ifdef FLSTST_STOP_SEC_VAR_16
	#undef FLSTST_STOP_SEC_VAR_16
	#define STOP_SEC_VAR
#endif

#ifdef FLSTST_START_SEC_VAR_CLEARED_8
	#undef FLSTST_START_SEC_VAR_CLEARED_8
	#define START_SEC_VAR_NOINIT_8_0
#endif

#ifdef FLSTST_STOP_SEC_VAR_CLEARED_8
	#undef FLSTST_STOP_SEC_VAR_CLEARED_8
	#define STOP_SEC_VAR
#endif

#ifdef FLSTST_START_SEC_VAR_CLEARED_UNSPECIFIED
	#undef FLSTST_START_SEC_VAR_CLEARED_UNSPECIFIED
	#define START_SEC_VAR_NOINIT_UNSPECIFIED_0
#endif

#ifdef FLSTST_STOP_SEC_VAR_CLEARED_UNSPECIFIED
	#undef FLSTST_STOP_SEC_VAR_CLEARED_UNSPECIFIED
	#define STOP_SEC_VAR
#endif

#ifdef FLSTST_START_SEC_CODE
	#undef MEMMAP_ERROR
	#undef FLSTST_START_SEC_CODE
#endif

#ifdef FLSTST_STOP_SEC_CODE
	#undef MEMMAP_ERROR
	#undef FLSTST_STOP_SEC_CODE
#endif


/**********************************************************************************************************************
 *  FlsTst END
 *********************************************************************************************************************/

#ifdef DIO_START_SEC_CODE
  #undef DIO_START_SEC_CODE
  #define START_SEC_CODE
#endif

#ifdef DIO_STOP_SEC_CODE
  #undef DIO_STOP_SEC_CODE
  #define STOP_SEC_CODE
#endif

#ifdef DIO_START_SEC_CONST_UNSPECIFIED
  #undef DIO_START_SEC_CONST_UNSPECIFIED
  #define START_SEC_CONST_32BIT
#endif

#ifdef DIO_STOP_SEC_CONST_UNSPECIFIED
  #undef DIO_STOP_SEC_CONST_UNSPECIFIED
  #define STOP_SEC_CONST
#endif






#ifdef GPT_START_SEC_CODE
 #undef GPT_START_SEC_CODE
 #define START_SEC_CODE
#endif

#ifdef GPT_STOP_SEC_CODE
 #undef GPT_STOP_SEC_CODE
 #define STOP_SEC_CODE
#endif

#ifdef GPT_START_SEC_CODE_ISR
 #undef GPT_START_SEC_CODE_ISR
 #define START_SEC_CODE_ISR
#endif

#ifdef GPT_STOP_SEC_CODE_ISR
 #undef GPT_STOP_SEC_CODE_ISR
 #define STOP_SEC_CODE
#endif

#ifdef GPT_START_SEC_PBCFG_ROOT
 #undef GPT_START_SEC_PBCFG_ROOT
 #define START_SEC_CONST_PBCFG
#endif

#ifdef GPT_STOP_SEC_PBCFG_ROOT
 #undef GPT_STOP_SEC_PBCFG_ROOT
 #define STOP_SEC_CONST
#endif

#ifdef GPT_START_SEC_PBCFG
 #undef GPT_START_SEC_PBCFG
 #define START_SEC_CONST_PBCFG
#endif

#ifdef GPT_STOP_SEC_PBCFG
 #undef GPT_STOP_SEC_PBCFG
 #define STOP_SEC_CONST
#endif

#ifdef GPT_START_SEC_CONST_32BIT
 #undef GPT_START_SEC_CONST_32BIT
 #define START_SEC_CONST_32BIT
#endif

#ifdef GPT_STOP_SEC_CONST_32BIT
 #undef GPT_STOP_SEC_CONST_32BIT
 #define STOP_SEC_CONST
#endif

#ifdef GPT_START_SEC_VAR_32BIT
 #undef GPT_START_SEC_VAR_32BIT
 #define START_SEC_VAR_NOINIT_32_9
#endif

#ifdef GPT_STOP_SEC_VAR_32BIT
 #undef GPT_STOP_SEC_VAR_32BIT
 #define STOP_SEC_VAR
#endif

#ifdef GPT_START_SEC_VAR_INIT_UNSPECIFIED
 #undef GPT_START_SEC_VAR_INIT_UNSPECIFIED
 #define START_SEC_VAR_NOINIT_UNSPECIFIED_9
#endif

#ifdef GPT_STOP_SEC_VAR_INIT_UNSPECIFIED
 #undef GPT_STOP_SEC_VAR_INIT_UNSPECIFIED
 #define STOP_SEC_VAR
#endif

#ifdef GPT_START_SEC_VAR_UNSPECIFIED
 #undef GPT_START_SEC_VAR_UNSPECIFIED
 #define START_SEC_VAR_NOINIT_UNSPECIFIED_9
#endif

#ifdef GPT_STOP_SEC_VAR_UNSPECIFIED
 #undef GPT_STOP_SEC_VAR_UNSPECIFIED
 #define STOP_SEC_VAR
#endif



/**********************************************************************************************************************
 *  DrvIcu_Tms570Tinhet01Asr START
 *********************************************************************************************************************/

/*******  CODE sections **********************************************************************************************/

#ifdef ICU_START_SEC_CODE
    #undef ICU_START_SEC_CODE
    #define START_SEC_CODE
#endif
#ifdef ICU_STOP_SEC_CODE
    #undef ICU_STOP_SEC_CODE
    #define STOP_SEC_CODE
#endif

#ifdef ICU_START_SEC_CODE_ISR
    #undef ICU_START_SEC_CODE_ISR
    #define START_SEC_CODE_ISR
#endif
#ifdef ICU_STOP_SEC_CODE_ISR
    #undef ICU_STOP_SEC_CODE_ISR
    #define STOP_SEC_CODE
#endif

/*******  CONST sections  ********************************************************************************************/

/* CONST sections */

#ifdef ICU_START_SEC_CONST_8BIT
    #undef ICU_START_SEC_CONST_8BIT
    #define START_SEC_CONST_8BIT
#endif
#ifdef ICU_STOP_SEC_CONST_8BIT
    #undef ICU_STOP_SEC_CONST_8BIT
    #define STOP_SEC_CONST
#endif

#ifdef ICU_START_SEC_CONST_32BIT
    #undef ICU_START_SEC_CONST_32BIT
    #define START_SEC_CONST_32BIT
#endif
#ifdef ICU_STOP_SEC_CONST_32BIT
    #undef ICU_STOP_SEC_CONST_32BIT
    #define STOP_SEC_CONST
#endif

#ifdef ICU_START_SEC_CONST_UNSPECIFIED
    #undef ICU_START_SEC_CONST_UNSPECIFIED
    #define START_SEC_CONST_UNSPECIFIED
#endif
#ifdef ICU_STOP_SEC_CONST_UNSPECIFIED
    #undef ICU_STOP_SEC_CONST_UNSPECIFIED
    #define STOP_SEC_CONST
#endif

/* Postbuild CFG CONST sections */

#ifdef ICU_START_SEC_CONST_PBCFG
    #undef ICU_START_SEC_CONST_PBCFG
    #define START_SEC_CONST_PBCFG
#endif
#ifdef ICU_STOP_SEC_CONST_PBCFG
    #undef ICU_STOP_SEC_CONST_PBCFG
    #define STOP_SEC_CONST
#endif

/*******  VAR sections  **********************************************************************************************/

/* VAR NOINIT sections */

#ifdef ICU_START_SEC_VAR_NOINIT_8BIT
    #undef ICU_START_SEC_VAR_NOINIT_8BIT
    #define START_SEC_VAR_NOINIT_8_9
#endif
#ifdef ICU_STOP_SEC_VAR_NOINIT_8BIT
    #undef ICU_STOP_SEC_VAR_NOINIT_8BIT
    #define STOP_SEC_VAR
#endif

#ifdef ICU_START_SEC_VAR_NOINIT_32BIT
    #undef ICU_START_SEC_VAR_NOINIT_32BIT
    #define START_SEC_VAR_NOINIT_32_9
#endif
#ifdef ICU_STOP_SEC_VAR_NOINIT_32BIT
    #undef ICU_STOP_SEC_VAR_NOINIT_32BIT
    #define STOP_SEC_VAR
#endif

/* VAR ZERO INIT sections */

#ifdef ICU_START_SEC_VAR_ZERO_INIT_8BIT
    #undef ICU_START_SEC_VAR_ZERO_INIT_8BIT
    #define START_SEC_VAR_CLEARED_8_9
#endif
#ifdef ICU_STOP_SEC_VAR_ZERO_INIT_8BIT
    #undef ICU_STOP_SEC_VAR_ZERO_INIT_8BIT
    #define STOP_SEC_VAR
#endif

#ifdef ICU_START_SEC_VAR_ZERO_INIT_UNSPECIFIED
    #undef ICU_START_SEC_VAR_ZERO_INIT_UNSPECIFIED
    #define START_SEC_VAR_CLEARED_UNSPECIFIED_9
#endif
#ifdef ICU_STOP_SEC_VAR_ZERO_INIT_UNSPECIFIED
    #undef ICU_STOP_SEC_VAR_ZERO_INIT_UNSPECIFIED
    #define STOP_SEC_VAR
#endif

/**********************************************************************************************************************
 *  DrvIcu_Tms570Tinhet01Asr END
 *********************************************************************************************************************/





/**********************************************************************************************************************
 *  MCU START
 **********************************************************************************************************************/

/****************************************  CODE sections **************************************************************/
#ifdef MCU_START_SEC_CODE
    #undef MCU_START_SEC_CODE
    #define START_SEC_CODE
#endif
#ifdef MCU_STOP_SEC_CODE
    #undef MCU_STOP_SEC_CODE
    #define STOP_SEC_CODE
#endif

/*******  CONST sections  *********************************************************************************************/

#ifdef MCU_START_SEC_PBCFG
    #undef MCU_START_SEC_PBCFG
    #define START_SEC_CONST_PBCFG
#endif
#ifdef MCU_STOP_SEC_PBCFG
    #undef MCU_STOP_SEC_PBCFG
    #define STOP_SEC_CONST
#endif

#ifdef MCU_START_SEC_PBCFG_ROOT
  #undef MCU_START_SEC_PBCFG_ROOT
  #define START_SEC_CONST_PBCFG
#endif
#ifdef MCU_STOP_SEC_PBCFG_ROOT
  #undef MCU_STOP_SEC_PBCFG_ROOT
  #define STOP_SEC_CONST
#endif

/*******  VAR sections  **********************************************************************************************/

#ifdef MCU_START_SEC_VAR_ZERO_INIT_UNSPECIFIED
    #undef MCU_START_SEC_VAR_ZERO_INIT_UNSPECIFIED
    #define START_SEC_VAR_CLEARED_UNSPECIFIED_9
#endif
#ifdef MCU_STOP_SEC_VAR_ZERO_INIT_UNSPECIFIED
    #undef MCU_STOP_SEC_VAR_ZERO_INIT_UNSPECIFIED
    #define STOP_SEC_VAR
#endif

/**********************************************************************************************************************
 *  MCU END
 **********************************************************************************************************************/



/**********************************************************************************************************************
 *  PORT START 
 *********************************************************************************************************************/
 
/*******  CODE sections **********************************************************************************************/

#ifdef PORT_START_SEC_CODE
    #undef PORT_START_SEC_CODE
    #define START_SEC_CODE
#endif

#ifdef PORT_STOP_SEC_CODE
    #undef PORT_STOP_SEC_CODE
    #define STOP_SEC_CODE
#endif

#ifdef PORT_START_SEC_PBCODE
    #undef PORT_START_SEC_PBCODE
    #define START_SEC_CODE
#endif

#ifdef PORT_STOP_SEC_PBCODE
    #undef PORT_STOP_SEC_PBCODE
    #define STOP_SEC_CODE
#endif

/*******  CONST sections  ********************************************************************************************/

#ifdef PORT_START_SEC_PBCFG
    #undef PORT_START_SEC_PBCFG
    #define START_SEC_CONST_PBCFG
#endif

#ifdef PORT_STOP_SEC_PBCFG
    #undef PORT_STOP_SEC_PBCFG
    #define STOP_SEC_CONST
#endif

#ifdef PORT_START_SEC_PBCFG_ROOT
    #undef PORT_START_SEC_PBCFG_ROOT
    #define START_SEC_CONST_PBCFG
#endif

#ifdef PORT_STOP_SEC_PBCFG_ROOT
    #undef PORT_STOP_SEC_PBCFG_ROOT
    #define STOP_SEC_CONST
#endif

/*******  VAR sections  **********************************************************************************************/

#ifdef PORT_START_SEC_VAR_UNSPECIFIED
    #undef PORT_START_SEC_VAR_UNSPECIFIED
    #define START_SEC_VAR_INIT_UNSPECIFIED_9
#endif

#ifdef PORT_STOP_SEC_VAR_UNSPECIFIED
    #undef PORT_STOP_SEC_VAR_UNSPECIFIED
    #define STOP_SEC_VAR
#endif

/**********************************************************************************************************************
 *  PORT END 
 *********************************************************************************************************************/




#ifdef PWM_START_SEC_CODE
    #undef PWM_START_SEC_CODE
    #define START_SEC_CODE
#endif

#ifdef PWM_STOP_SEC_CODE
    #undef PWM_STOP_SEC_CODE
    #define STOP_SEC_CODE
#endif

#ifdef PWM_START_SEC_PBCFG
    #undef PWM_START_SEC_PBCFG
    #define START_SEC_CONST_PBCFG
#endif

#ifdef PWM_STOP_SEC_PBCFG
    #undef PWM_STOP_SEC_PBCFG
    #define STOP_SEC_CONST
#endif

#ifdef PWM_START_SEC_VAR_NOINIT_UNSPECIFIED
    #undef PWM_START_SEC_VAR_NOINIT_UNSPECIFIED
    #define START_SEC_VAR_NOINIT_UNSPECIFIED_9
#endif

#ifdef PWM_STOP_SEC_VAR_NOINIT_UNSPECIFIED
    #undef PWM_STOP_SEC_VAR_NOINIT_UNSPECIFIED
    #define STOP_SEC_VAR
#endif

#ifdef PWM_START_SEC_VAR_INIT_8BIT
    #undef PWM_START_SEC_VAR_INIT_8BIT
    #define START_SEC_VAR_INIT_8_9
#endif

#ifdef PWM_STOP_SEC_VAR_INIT_8BIT
    #undef PWM_STOP_SEC_VAR_INIT_8BIT
    #define STOP_SEC_VAR
#endif


#ifdef PWM_START_SEC_VAR_NOINIT_8BIT
    #undef PWM_START_SEC_VAR_NOINIT_8BIT
    #define START_SEC_VAR_NOINIT_8_9
#endif

#ifdef PWM_STOP_SEC_VAR_NOINIT_8BIT
    #undef PWM_STOP_SEC_VAR_NOINIT_8BIT
    #define STOP_SEC_VAR
#endif

#ifdef PWM_START_SEC_CODE_ISR
    #undef PWM_START_SEC_CODE_ISR
    #define START_SEC_CODE_ISR
#endif

#ifdef PWM_STOP_SEC_CODE_ISR
    #undef PWM_STOP_SEC_CODE_ISR
    #define STOP_SEC_CODE
#endif





/**********************************************************************************************************************
 *  Spi START 
 **********************************************************************************************************************/

/*******  CODE sections  **********************************************************************************************/

#ifdef SPI_START_SEC_CODE
    #undef SPI_START_SEC_CODE
    #define START_SEC_CODE
#endif

#ifdef SPI_STOP_SEC_CODE
    #undef SPI_STOP_SEC_CODE
    #define STOP_SEC_CODE
#endif

/*******  ISR sections  ***********************************************************************************************/

#ifdef SPI_START_SEC_CODE_ISR
    #undef SPI_START_SEC_CODE_ISR
    #define START_SEC_CODE_ISR
#endif

#ifdef SPI_STOP_SEC_CODE_ISR
    #undef SPI_STOP_SEC_CODE_ISR
    #define STOP_SEC_CODE
#endif

/*******  CONST sections  *********************************************************************************************/

#ifdef SPI_START_SEC_PBCFG_ROOT
    #undef SPI_START_SEC_PBCFG_ROOT
    #define START_SEC_CONST_PBCFG
#endif

#ifdef SPI_STOP_SEC_PBCFG_ROOT
    #undef SPI_STOP_SEC_PBCFG_ROOT
    #define STOP_SEC_CONST
#endif

#ifdef SPI_START_SEC_PBCFG
    #undef SPI_START_SEC_PBCFG
    #define START_SEC_CONST_PBCFG
#endif

#ifdef SPI_STOP_SEC_PBCFG
    #undef SPI_STOP_SEC_PBCFG
    #define STOP_SEC_CONST
#endif

#ifdef SPI_START_SEC_CONST_32BIT
    #undef SPI_START_SEC_CONST_32BIT
    #define START_SEC_CONST_32BIT
#endif

#ifdef SPI_STOP_SEC_CONST_32BIT
    #undef SPI_STOP_SEC_CONST_32BIT
    #define STOP_SEC_CONST
#endif

#ifdef SPI_START_SEC_CONST_UNSPECIFIED
    #undef SPI_START_SEC_CONST_UNSPECIFIED
    #define START_SEC_CONST_UNSPECIFIED
#endif

#ifdef SPI_STOP_SEC_CONST_UNSPECIFIED
    #undef SPI_STOP_SEC_CONST_UNSPECIFIED
    #define STOP_SEC_CONST
#endif

/*******  VAR sections  ***********************************************************************************************/
#ifdef SPI_START_SEC_VAR_INIT_UNSPECIFIED
    #undef SPI_START_SEC_VAR_INIT_UNSPECIFIED
    #define START_SEC_VAR_INIT_UNSPECIFIED_9
#endif

#ifdef SPI_STOP_SEC_VAR_INIT_UNSPECIFIED
    #undef SPI_STOP_SEC_VAR_INIT_UNSPECIFIED
    #define STOP_SEC_VAR
#endif

#ifdef SPI_START_SEC_VAR_NOINIT_UNSPECIFIED
    #undef SPI_START_SEC_VAR_NOINIT_UNSPECIFIED
    #define START_SEC_VAR_NOINIT_UNSPECIFIED_9
#endif

#ifdef SPI_STOP_SEC_VAR_NOINIT_UNSPECIFIED
    #undef SPI_STOP_SEC_VAR_NOINIT_UNSPECIFIED
    #define STOP_SEC_VAR
#endif

#ifdef SPI_START_SEC_VAR_ZERO_INIT_UNSPECIFIED
    #undef SPI_START_SEC_VAR_ZERO_INIT_UNSPECIFIED
    #define START_SEC_VAR_CLEARED_UNSPECIFIED_9
#endif

#ifdef SPI_STOP_SEC_VAR_ZERO_INIT_UNSPECIFIED
    #undef SPI_STOP_SEC_VAR_ZERO_INIT_UNSPECIFIED
    #define STOP_SEC_VAR
#endif

/**********************************************************************************************************************
 *  Spi END
 **********************************************************************************************************************/





/**********************************************************************************************************************
 *  WDG START
 *********************************************************************************************************************/

/* Code section - START */
#if defined WDG_START_SEC_CODE                      /* Code */
    #undef WDG_START_SEC_CODE
    #define START_SEC_CODE
#elif defined WDG_STOP_SEC_CODE
    #undef WDG_STOP_SEC_CODE
    #define STOP_SEC_CODE

#elif defined WDG_START_SEC_CONST_8BIT         /* Global or static constants */
    #undef WDG_START_SEC_CONST_8BIT
    #define START_SEC_CONST_8BIT
#elif defined WDG_STOP_SEC_CONST_8BIT
    #undef WDG_STOP_SEC_CONST_8BIT
    #define STOP_SEC_CONST

#elif defined WDG_START_SEC_CONST_16BIT
    #undef WDG_START_SEC_CONST_16BIT
    #define START_SEC_CONST_16BIT
#elif defined WDG_STOP_SEC_CONST_16BIT
    #undef WDG_STOP_SEC_CONST_16BIT
    #define STOP_SEC_CONST

#elif defined WDG_START_SEC_CONST_32BIT
    #undef WDG_START_SEC_CONST_32BIT
    #define START_SEC_CONST_32BIT
#elif defined WDG_STOP_SEC_CONST_32BIT
    #undef WDG_STOP_SEC_CONST_32BIT
    #define STOP_SEC_CONST

#elif defined WDG_START_SEC_CONST_UNSPECIFIED
    #undef WDG_START_SEC_CONST_UNSPECIFIED
    #define START_SEC_CONST_UNSPECIFIED
#elif defined WDG_STOP_SEC_CONST_UNSPECIFIED
    #undef WDG_STOP_SEC_CONST_UNSPECIFIED
    #define STOP_SEC_CONST
#endif

/**********************************************************************************************************************
 *  WDG END
 *********************************************************************************************************************/



/**********************************************************************************************************************
 *  EcuAb_AsrIoHwAb START
 *********************************************************************************************************************/

/*******  CODE sections **********************************************************************************************/

#ifdef IOHWAB_START_SEC_CODE
    #undef IOHWAB_START_SEC_CODE
    #define START_SEC_CODE
#endif
#ifdef IOHWAB_STOP_SEC_CODE
    #undef IOHWAB_STOP_SEC_CODE
    #define STOP_SEC_CODE
#endif

/*******  CONST sections  ********************************************************************************************/

#ifdef IOHWAB_START_SEC_CONST_32BIT
    #undef IOHWAB_START_SEC_CONST_32BIT
    #define START_SEC_CONST_32BIT
#endif
#ifdef IOHWAB_STOP_SEC_CONST_32BIT
    #undef IOHWAB_STOP_SEC_CONST_32BIT
    #define STOP_SEC_CONST
#endif

/*******  VAR sections  **********************************************************************************************/

#ifdef IOHWAB_START_SEC_VAR_ZERO_INIT_UNSPECIFIED
    #undef IOHWAB_START_SEC_VAR_ZERO_INIT_UNSPECIFIED
    #define START_SEC_VAR_CLEARED_UNSPECIFIED_10
#endif
#ifdef IOHWAB_STOP_SEC_VAR_ZERO_INIT_UNSPECIFIED
    #undef IOHWAB_STOP_SEC_VAR_ZERO_INIT_UNSPECIFIED
    #define STOP_SEC_VAR
#endif

/**********************************************************************************************************************
 *  EcuAb_AsrIoHwAb END
 *********************************************************************************************************************/







/**********************************************************************************************************************
 *  If_AsrIfEa START 
 *********************************************************************************************************************/

/*******  CODE sections **********************************************************************************************/
/**********************************************************************************************************************
 *  If_AsrIfEa END
 *********************************************************************************************************************/


















#ifdef MEMIF_START_SEC_CONST_8BIT 
    #undef MEMIF_START_SEC_CONST_8BIT 
    #define START_SEC_CONST_8BIT
#endif

#ifdef MEMIF_STOP_SEC_CONST_8BIT 
    #undef MEMIF_STOP_SEC_CONST_8BIT 
    #define STOP_SEC_CONST
#endif


#ifdef MEMIF_START_SEC_CONST_32BIT
    #undef MEMIF_START_SEC_CONST_32BIT
    #define START_SEC_CONST_32BIT
#endif

#ifdef MEMIF_STOP_SEC_CONST_32BIT
    #undef MEMIF_STOP_SEC_CONST_32BIT
    #define STOP_SEC_CONST
#endif


#ifdef MEMIF_START_SEC_CODE
    #undef MEMIF_START_SEC_CODE
    #define START_SEC_CODE
#endif

#ifdef MEMIF_STOP_SEC_CODE
    #undef MEMIF_STOP_SEC_CODE
    #define STOP_SEC_CODE
#endif





/**********************************************************************************************************************
 *  If_AsrIfWd START
 *********************************************************************************************************************/

/* Code section - START */
#if defined WDGIF_START_SEC_CODE                      /* Code */
    #undef WDGIF_START_SEC_CODE
    #define START_SEC_CODE
#elif defined WDGIF_STOP_SEC_CODE
    #undef WDGIF_STOP_SEC_CODE
    #define STOP_SEC_CODE
#endif

/* Variables - START */
#if defined WDGIF_START_SEC_VAR_INIT_8BIT           /* Init variables */
    #undef WDGIF_START_SEC_VAR_INIT_8BIT
    #define START_SEC_VAR_INIT_8_0
#elif defined WDGIF_STOP_SEC_VAR_INIT_8BIT
    #undef WDGIF_STOP_SEC_VAR_INIT_8BIT
    #define STOP_SEC_VAR

#elif defined WDGIF_START_SEC_VAR_INIT_16BIT
    #undef WDGIF_START_SEC_VAR_INIT_16BIT
    #define START_SEC_VAR_INIT_16_0
#elif defined WDGIF_STOP_SEC_VAR_INIT_16BIT
    #undef WDGIF_STOP_SEC_VAR_INIT_16BIT
    #define STOP_SEC_VAR

#elif defined WDGIF_START_SEC_VAR_INIT_32BIT
    #undef WDGIF_START_SEC_VAR_INIT_32BIT
    #define START_SEC_VAR_INIT_32_0
#elif defined WDGIF_STOP_SEC_VAR_INIT_32BIT
    #undef WDGIF_STOP_SEC_VAR_INIT_32BIT
    #define STOP_SEC_VAR

#elif defined WDGIF_START_SEC_VAR_INIT_UNSPECIFIED
    #undef WDGIF_START_SEC_VAR_INIT_UNSPECIFIED
    #define START_SEC_VAR_INIT_UNSPECIFIED_0
#elif defined WDGIF_STOP_SEC_VAR_INIT_UNSPECIFIED
    #undef WDGIF_STOP_SEC_VAR_INIT_UNSPECIFIED
    #define STOP_SEC_VAR

#elif defined WDGIF_START_SEC_VAR_NOINIT_8BIT           /* No init variables */
    #undef WDGIF_START_SEC_VAR_NOINIT_8BIT
    #define START_SEC_VAR_NOINIT_8_0
#elif defined WDGIF_STOP_SEC_VAR_NOINIT_8BIT
    #undef WDGIF_STOP_SEC_VAR_NOINIT_8BIT
    #define STOP_SEC_VAR

#elif defined WDGIF_START_SEC_VAR_NOINIT_16BIT
    #undef WDGIF_START_SEC_VAR_NOINIT_16BIT
    #define START_SEC_VAR_NOINIT_16_0
#elif defined WDGIF_STOP_SEC_VAR_NOINIT_16BIT
    #undef WDGIF_STOP_SEC_VAR_NOINIT_16BIT
    #define STOP_SEC_VAR

#elif defined WDGIF_START_SEC_VAR_NOINIT_32BIT
    #undef WDGIF_START_SEC_VAR_NOINIT_32BIT
    #define START_SEC_VAR_NOINIT_32_0
#elif defined WDGIF_STOP_SEC_VAR_NOINIT_32BIT
    #undef WDGIF_STOP_SEC_VAR_NOINIT_32BIT
    #define STOP_SEC_VAR

#elif defined WDGIF_START_SEC_VAR_NOINIT_UNSPECIFIED
    #undef WDGIF_START_SEC_VAR_NOINIT_UNSPECIFIED
    #define START_SEC_VAR_NOINIT_UNSPECIFIED_0
#elif defined WDGIF_STOP_SEC_VAR_NOINIT_UNSPECIFIED
    #undef WDGIF_STOP_SEC_VAR_NOINIT_UNSPECIFIED
    #define STOP_SEC_VAR

#elif defined WDGIF_START_SEC_VAR_ZERO_INIT_8BIT           /* Zero init variables */
    #undef WDGIF_START_SEC_VAR_ZERO_INIT_8BIT
    #define START_SEC_VAR_CLEARED_8_0
#elif defined WDGIF_STOP_SEC_VAR_ZERO_INIT_8BIT
    #undef WDGIF_STOP_SEC_VAR_ZERO_INIT_8BIT
    #define STOP_SEC_VAR

#elif defined WDGIF_START_SEC_VAR_ZERO_INIT_16BIT
    #undef WDGIF_START_SEC_VAR_ZERO_INIT_16BIT
    #define START_SEC_VAR_CLEARED_16_0
#elif defined WDGIF_STOP_SEC_VAR_ZERO_INIT_16BIT
    #undef WDGIF_STOP_SEC_VAR_ZERO_INIT_16BIT
    #define STOP_SEC_VAR

#elif defined WDGIF_START_SEC_VAR_ZERO_INIT_32BIT
    #undef WDGIF_START_SEC_VAR_ZERO_INIT_32BIT
    #define START_SEC_VAR_CLEARED_32_0
#elif defined WDGIF_STOP_SEC_VAR_ZERO_INIT_32BIT
    #undef WDGIF_STOP_SEC_VAR_ZERO_INIT_32BIT
    #define STOP_SEC_VAR

#elif defined WDGIF_START_SEC_VAR_ZERO_INIT_UNSPECIFIED
    #undef WDGIF_START_SEC_VAR_ZERO_INIT_UNSPECIFIED
    #define START_SEC_VAR_CLEARED_UNSPECIFIED_0
#elif defined WDGIF_STOP_SEC_VAR_ZERO_INIT_UNSPECIFIED
    #undef WDGIF_STOP_SEC_VAR_ZERO_INIT_UNSPECIFIED
    #define STOP_SEC_VAR

#elif defined WDGIF_START_SEC_CONST_8BIT         /* Global or static constants */
    #undef WDGIF_START_SEC_CONST_8BIT
    #define START_SEC_CONST_8BIT
#elif defined WDGIF_STOP_SEC_CONST_8BIT
    #undef WDGIF_STOP_SEC_CONST_8BIT
    #define STOP_SEC_CONST

#elif defined WDGIF_START_SEC_CONST_16BIT
    #undef WDGIF_START_SEC_CONST_16BIT
    #define START_SEC_CONST_16BIT
#elif defined WDGIF_STOP_SEC_CONST_16BIT
    #undef WDGIF_STOP_SEC_CONST_16BIT
    #define STOP_SEC_CONST

#elif defined WDGIF_START_SEC_CONST_32BIT
    #undef WDGIF_START_SEC_CONST_32BIT
    #define START_SEC_CONST_32BIT
#elif defined WDGIF_STOP_SEC_CONST_32BIT
    #undef WDGIF_STOP_SEC_CONST_32BIT
    #define STOP_SEC_CONST

#elif defined WDGIF_START_SEC_CONST_UNSPECIFIED
    #undef WDGIF_START_SEC_CONST_UNSPECIFIED
    #define START_SEC_CONST_UNSPECIFIED
#elif defined WDGIF_STOP_SEC_CONST_UNSPECIFIED
    #undef WDGIF_STOP_SEC_CONST_UNSPECIFIED
    #define STOP_SEC_CONST
#endif

/**********************************************************************************************************************
 *  If_AsrIfWd END
 *********************************************************************************************************************/


















/**********************************************************************************************************************
 *  NvM START 
 *********************************************************************************************************************/

/*******  CODE sections **********************************************************************************************/

#ifdef NVM_START_SEC_CODE
    #undef NVM_START_SEC_CODE
    #define START_SEC_CODE                /* mapped to default code section */
#endif
#ifdef NVM_STOP_SEC_CODE
    #undef NVM_STOP_SEC_CODE
    #define STOP_SEC_CODE                /* default code stop section */
#endif


/*******  CONST sections  ********************************************************************************************/

/* CONST sections */

#ifdef NVM_START_SEC_CONST_8BIT
    #undef NVM_START_SEC_CONST_8BIT
    #define START_SEC_CONST_8BIT
#endif
#ifdef NVM_STOP_SEC_CONST_8BIT
    #undef NVM_STOP_SEC_CONST_8BIT
    #define STOP_SEC_CONST
#endif

#ifdef NVM_START_SEC_CONST_16BIT
    #undef NVM_START_SEC_CONST_16BIT
    #define START_SEC_CONST_16BIT
#endif
#ifdef NVM_STOP_SEC_CONST_16BIT
    #undef NVM_STOP_SEC_CONST_16BIT
    #define STOP_SEC_CONST
#endif

#ifdef NVM_START_SEC_CONST_UNSPECIFIED
    #undef NVM_START_SEC_CONST_UNSPECIFIED
    #define START_SEC_CONST_UNSPECIFIED
#endif
#ifdef NVM_STOP_SEC_CONST_UNSPECIFIED
    #undef NVM_STOP_SEC_CONST_UNSPECIFIED
    #define STOP_SEC_CONST
#endif

#ifdef NVM_START_SEC_CONST_DESCRIPTOR_TABLE
    #undef NVM_START_SEC_CONST_DESCRIPTOR_TABLE
    #define START_SEC_CONST_UNSPECIFIED
#endif
#ifdef NVM_STOP_SEC_CONST_DESCRIPTOR_TABLE
    #undef NVM_STOP_SEC_CONST_DESCRIPTOR_TABLE
    #define STOP_SEC_CONST
#endif


/*******  VAR sections  **********************************************************************************************/

/* VAR NOINIT sections */

#ifdef NVM_START_SEC_VAR_NOINIT_8BIT
    #undef NVM_START_SEC_VAR_NOINIT_8BIT
    #define START_SEC_VAR_NOINIT_8_9
#endif
#ifdef NVM_STOP_SEC_VAR_NOINIT_8BIT
    #undef NVM_STOP_SEC_VAR_NOINIT_8BIT
    #define STOP_SEC_VAR
#endif

#ifdef NVM_START_SEC_VAR_NOINIT_UNSPECIFIED
    #undef NVM_START_SEC_VAR_NOINIT_UNSPECIFIED
    #define START_SEC_VAR_NOINIT_UNSPECIFIED_9
#endif
#ifdef NVM_STOP_SEC_VAR_NOINIT_UNSPECIFIED
    #undef NVM_STOP_SEC_VAR_NOINIT_UNSPECIFIED
    #define STOP_SEC_VAR
#endif

#ifdef NVM_START_SEC_VAR_UNSPECIFIED
    #undef NVM_START_SEC_VAR_UNSPECIFIED
    #define START_SEC_VAR_NOINIT_UNSPECIFIED_9
#endif
#ifdef NVM_STOP_SEC_VAR_UNSPECIFIED
    #undef NVM_STOP_SEC_VAR_UNSPECIFIED
    #define STOP_SEC_VAR
#endif

/* VAR FAST NOINIT sections */

#ifdef NVM_START_SEC_VAR_FAST_8BIT
    #undef NVM_START_SEC_VAR_FAST_8BIT
    #define START_SEC_VAR_FAST_NOINIT_8BIT
#endif
#ifdef NVM_STOP_SEC_VAR_FAST_8BIT
    #undef NVM_STOP_SEC_VAR_FAST_8BIT
    #define STOP_SEC_VAR
#endif

/* VAR ZERO INIT sections */

#ifdef NVM_START_SEC_VAR_POWER_ON_INIT_UNSPECIFIED
    #undef NVM_START_SEC_VAR_POWER_ON_INIT_UNSPECIFIED
    #define START_SEC_VAR_CLEARED_UNSPECIFIED_9
#endif
#ifdef NVM_STOP_SEC_VAR_POWER_ON_INIT_UNSPECIFIED
    #undef NVM_STOP_SEC_VAR_POWER_ON_INIT_UNSPECIFIED
    #define STOP_SEC_VAR
#endif

/**********************************************************************************************************************
 *  NvM END
 *********************************************************************************************************************/












#ifdef CRC_START_SEC_CODE
    #undef CRC_START_SEC_CODE
    #define START_SEC_CODE
#endif
#ifdef CRC_START_SEC_CONST_8BIT
    #undef CRC_START_SEC_CONST_8BIT
    #define START_SEC_CONST_8BIT
#endif
#ifdef CRC_START_SEC_CONST_16BIT
    #undef CRC_START_SEC_CONST_16BIT
    #define START_SEC_CONST_16BIT
#endif
#ifdef CRC_START_SEC_CONST_32BIT
    #undef CRC_START_SEC_CONST_32BIT
    #define START_SEC_CONST_32BIT
#endif

#ifdef CRC_STOP_SEC_CODE
    #undef CRC_STOP_SEC_CODE
    #define STOP_SEC_CODE
#endif
#ifdef CRC_STOP_SEC_CONST_8BIT
    #undef CRC_STOP_SEC_CONST_8BIT
    #define STOP_SEC_CONST
#endif

#ifdef CRC_STOP_SEC_CONST_16BIT
    #undef CRC_STOP_SEC_CONST_16BIT
    #define STOP_SEC_CONST
#endif

#ifdef CRC_STOP_SEC_CONST_32BIT
    #undef CRC_STOP_SEC_CONST_32BIT
    #define STOP_SEC_CONST
#endif



#ifdef DET_START_SEC_CODE
# undef DET_START_SEC_CODE
# define START_SEC_CODE
#endif
#ifdef DET_STOP_SEC_CODE
# undef DET_STOP_SEC_CODE
# define STOP_SEC_CODE
#endif

#ifdef DET_START_SEC_VAR_UNSPECIFIED
# undef DET_START_SEC_VAR_UNSPECIFIED
# define START_SEC_VAR_NOINIT_UNSPECIFIED_9
#endif
#ifdef DET_STOP_SEC_VAR_UNSPECIFIED
# undef DET_STOP_SEC_VAR_UNSPECIFIED
# define STOP_SEC_VAR
#endif



/**********************************************************************************************************************
 *  SYSSERVICE_ASRECUM START 
 *********************************************************************************************************************/

/*******  CODE sections **********************************************************************************************/

#ifdef ECUM_START_SEC_CODE
# undef ECUM_START_SEC_CODE
# define START_SEC_CODE                            /* mapped to default code section */
#endif
#ifdef ECUM_STOP_SEC_CODE
# undef ECUM_STOP_SEC_CODE
# define STOP_SEC_CODE                             /* default code stop section */
#endif

#ifdef ECUM_START_SEC_CODE_SET_BOOT_TARGET
# undef ECUM_START_SEC_CODE_SET_BOOT_TARGET
# define START_SEC_CODE                            /* mapped to default fast code section */
#endif
#ifdef ECUM_STOP_SEC_CODE_SET_BOOT_TARGET
# undef ECUM_STOP_SEC_CODE_SET_BOOT_TARGET
# define STOP_SEC_CODE                             /* default code stop section */
#endif

#ifdef ECUM_START_SEC_CODE_GET_BOOT_TARGET
# undef ECUM_START_SEC_CODE_GET_BOOT_TARGET
# define START_SEC_CODE                            /* mapped to default ISR code section */
#endif
#ifdef ECUM_STOP_SEC_CODE_GET_BOOT_TARGET
# undef ECUM_STOP_SEC_CODE_GET_BOOT_TARGET
# define STOP_SEC_CODE                             /* default code stop section */
#endif

/*******  CONST sections  ********************************************************************************************/

/* CONST sections */

#ifdef ECUM_START_SEC_CONST_8BIT
# undef ECUM_START_SEC_CONST_8BIT
# define START_SEC_CONST_8BIT                       /* mapped to default const 8bit section */
#endif
#ifdef ECUM_STOP_SEC_CONST_8BIT
# undef ECUM_STOP_SEC_CONST_8BIT
# define STOP_SEC_CONST                             /* default const stop section */
#endif

#ifdef ECUM_START_SEC_CONST_UNSPECIFIED
# undef ECUM_START_SEC_CONST_UNSPECIFIED
# define START_SEC_CONST_UNSPECIFIED
#endif
#ifdef ECUM_STOP_SEC_CONST_UNSPECIFIED
# undef ECUM_STOP_SEC_CONST_UNSPECIFIED
# define STOP_SEC_CONST
#endif

/* FAST CONST sections */

/* Postbuild CFG CONST sections */

/* Root table for postbuild data */
#ifdef ECUM_START_SEC_CONST_PBCFG_ROOT
# undef ECUM_START_SEC_CONST_PBCFG_ROOT
# define START_SEC_CONST_PBCFG
#endif
#ifdef ECUM_STOP_SEC_CONST_PBCFG_ROOT
# undef ECUM_STOP_SEC_CONST_PBCFG_ROOT
# define STOP_SEC_CONST
#endif

#ifdef ECUM_START_SEC_CONST_PBCFG
# undef ECUM_START_SEC_CONST_PBCFG
# define START_SEC_CONST_PBCFG
#endif
#ifdef ECUM_STOP_SEC_CONST_PBCFG
# undef ECUM_STOP_SEC_CONST_PBCFG
# define STOP_SEC_CONST
#endif

/*******  VAR sections  **********************************************************************************************/

/* VAR INIT sections */

#ifdef ECUM_START_SEC_VAR_INIT_UNSPECIFIED
# undef ECUM_START_SEC_VAR_INIT_UNSPECIFIED
# define START_SEC_VAR_INIT_UNSPECIFIED_9
#endif
#ifdef ECUM_STOP_SEC_VAR_INIT_UNSPECIFIED
# undef ECUM_STOP_SEC_VAR_INIT_UNSPECIFIED
# define STOP_SEC_VAR
#endif

/* VAR NOINIT sections */

#ifdef ECUM_START_SEC_VAR_NOINIT_8BIT
# undef ECUM_START_SEC_VAR_NOINIT_8BIT
# define START_SEC_VAR_NOINIT_8_9
#endif
#ifdef ECUM_STOP_SEC_VAR_NOINIT_8BIT
# undef ECUM_STOP_SEC_VAR_NOINIT_8BIT
# define STOP_SEC_VAR
#endif

#ifdef ECUM_START_SEC_VAR_NOINIT_16BIT
# undef ECUM_START_SEC_VAR_NOINIT_16BIT
# define START_SEC_VAR_NOINIT_16_9
#endif
#ifdef ECUM_STOP_SEC_VAR_NOINIT_16BIT
# undef ECUM_STOP_SEC_VAR_NOINIT_16BIT
# define STOP_SEC_VAR
#endif

#ifdef ECUM_START_SEC_VAR_NOINIT_UNSPECIFIED
# undef ECUM_START_SEC_VAR_NOINIT_UNSPECIFIED
# define START_SEC_VAR_NOINIT_UNSPECIFIED_9
#endif
#ifdef ECUM_STOP_SEC_VAR_NOINIT_UNSPECIFIED
# undef ECUM_STOP_SEC_VAR_NOINIT_UNSPECIFIED
# define STOP_SEC_VAR
#endif

/* VAR ZERO INIT sections */

/* VAR FAST INIT sections */

/* VAR FAST NOINIT sections */

/* VAR FAST ZERO INIT sections */

/**********************************************************************************************************************
 *  SYSSERVICE_ASRECUM END
 *********************************************************************************************************************/







/**********************************************************************************************************************
 *  SYSSERVICE_ASRWDM START 
 *********************************************************************************************************************/

/* Code section - START */
#if defined WDGM_START_SEC_CODE                      /* Code */
    #undef WDGM_START_SEC_CODE
    #define START_SEC_CODE
#elif defined WDGM_STOP_SEC_CODE
    #undef WDGM_STOP_SEC_CODE
    #define STOP_SEC_CODE
#endif

/* Variables - START */
#if defined WDGM_START_SEC_VAR_INIT_8BIT           /* Init variables */
    #undef WDGM_START_SEC_VAR_INIT_8BIT
    #define START_SEC_VAR_INIT_8_0
#elif defined WDGM_STOP_SEC_VAR_INIT_8BIT
    #undef WDGM_STOP_SEC_VAR_INIT_8BIT
    #define STOP_SEC_VAR

#elif defined WDGM_START_SEC_VAR_INIT_16BIT
    #undef WDGM_START_SEC_VAR_INIT_16BIT
    #define START_SEC_VAR_INIT_16_0
#elif defined WDGM_STOP_SEC_VAR_INIT_16BIT
    #undef WDGM_STOP_SEC_VAR_INIT_16BIT
    #define STOP_SEC_VAR

#elif defined WDGM_START_SEC_VAR_INIT_32BIT
    #undef WDGM_START_SEC_VAR_INIT_32BIT
    #define START_SEC_VAR_INIT_32_0
#elif defined WDGM_STOP_SEC_VAR_INIT_32BIT
    #undef WDGM_STOP_SEC_VAR_INIT_32BIT
    #define STOP_SEC_VAR

#elif defined WDGM_START_SEC_VAR_INIT_UNSPECIFIED 
    #undef WDGM_START_SEC_VAR_INIT_UNSPECIFIED
	#undef MEMMAP_ERROR

#elif defined WDGM_STOP_SEC_VAR_INIT_UNSPECIFIED
    #undef WDGM_STOP_SEC_VAR_INIT_UNSPECIFIED
	#undef MEMMAP_ERROR

                                                 /* GLOBAL DATA OF THE S-WDGM */
#elif defined WDGM_GLOBAL_START_SEC_VAR_INIT_32BIT
    #undef WDGM_GLOBAL_START_SEC_VAR_INIT_32BIT
	#undef MEMMAP_ERROR
#elif defined WDGM_GLOBAL_STOP_SEC_VAR_INIT_32BIT
    #undef WDGM_GLOBAL_STOP_SEC_VAR_INIT_32BIT
	#undef MEMMAP_ERROR

                                          /* GLOBAL SHARED DATA OF THE S-WDGM */
#elif defined WDGM_GLOBAL_SHARED_START_SEC_VAR_INIT_32BIT
    #undef WDGM_GLOBAL_SHARED_START_SEC_VAR_INIT_32BIT             
    #undef MEMMAP_ERROR
#elif defined WDGM_GLOBAL_SHARED_STOP_SEC_VAR_INIT_32BIT
    #undef WDGM_GLOBAL_SHARED_STOP_SEC_VAR_INIT_32BIT
	#undef MEMMAP_ERROR

#elif defined WDGM_START_SEC_VAR_NOINIT_8BIT           /* No init variables */
    #undef WDGM_START_SEC_VAR_NOINIT_8BIT
    #define START_SEC_VAR_NOINIT_8_0
#elif defined WDGM_STOP_SEC_VAR_NOINIT_8BIT
    #undef WDGM_STOP_SEC_VAR_NOINIT_8BIT
    #define STOP_SEC_VAR

#elif defined WDGM_START_SEC_VAR_NOINIT_16BIT
    #undef WDGM_START_SEC_VAR_NOINIT_16BIT
    #define START_SEC_VAR_NOINIT_16_0
#elif defined WDGM_STOP_SEC_VAR_NOINIT_16BIT
    #undef WDGM_STOP_SEC_VAR_NOINIT_16BIT
    #define STOP_SEC_VAR

#elif defined WDGM_START_SEC_VAR_NOINIT_32BIT
    #undef WDGM_START_SEC_VAR_NOINIT_32BIT
    #define START_SEC_VAR_NOINIT_32_0
#elif defined WDGM_STOP_SEC_VAR_NOINIT_32BIT
    #undef WDGM_STOP_SEC_VAR_NOINIT_32BIT
    #define STOP_SEC_VAR

#elif defined WDGM_START_SEC_VAR_NOINIT_UNSPECIFIED
    #undef WDGM_START_SEC_VAR_NOINIT_UNSPECIFIED
    #define START_SEC_VAR_NOINIT_UNSPECIFIED_0
#elif defined WDGM_STOP_SEC_VAR_NOINIT_UNSPECIFIED
    #undef WDGM_STOP_SEC_VAR_NOINIT_UNSPECIFIED
    #define STOP_SEC_VAR

                                                 /* GLOBAL DATA OF THE S-WDGM */
#elif defined WDGM_GLOBAL_START_SEC_VAR_NOINIT_32BIT
    #undef WDGM_GLOBAL_START_SEC_VAR_NOINIT_32BIT
	#undef MEMMAP_ERROR
#elif defined WDGM_GLOBAL_STOP_SEC_VAR_NOINIT_32BIT
    #undef WDGM_GLOBAL_STOP_SEC_VAR_NOINIT_32BIT
	#undef MEMMAP_ERROR

                                          /* GLOBAL SHARED DATA OF THE S-WDGM */
#elif defined WDGM_GLOBAL_SHARED_START_SEC_VAR_NOINIT_32BIT
    #undef WDGM_GLOBAL_SHARED_START_SEC_VAR_NOINIT_32BIT
	#undef MEMMAP_ERROR
#elif defined WDGM_GLOBAL_SHARED_STOP_SEC_VAR_NOINIT_32BIT
    #undef WDGM_GLOBAL_SHARED_STOP_SEC_VAR_NOINIT_32BIT
	#undef MEMMAP_ERROR

#elif defined WDGM_START_SEC_VAR_ZERO_INIT_8BIT           /* Zero init variables */
    #undef WDGM_START_SEC_VAR_ZERO_INIT_8BIT
    #define START_SEC_VAR_CLEARED_8_0
#elif defined WDGM_STOP_SEC_VAR_ZERO_INIT_8BIT
    #undef WDGM_STOP_SEC_VAR_ZERO_INIT_8BIT
    #define STOP_SEC_VAR

#elif defined WDGM_START_SEC_VAR_ZERO_INIT_16BIT
    #undef WDGM_START_SEC_VAR_ZERO_INIT_16BIT
    #define START_SEC_VAR_CLEARED_16_0
#elif defined WDGM_STOP_SEC_VAR_ZERO_INIT_16BIT
    #undef WDGM_STOP_SEC_VAR_ZERO_INIT_16BIT
    #define STOP_SEC_VAR

#elif defined WDGM_START_SEC_VAR_ZERO_INIT_32BIT
    #undef WDGM_START_SEC_VAR_ZERO_INIT_32BIT
    #define START_SEC_VAR_CLEARED_32_0
#elif defined WDGM_STOP_SEC_VAR_ZERO_INIT_32BIT
    #undef WDGM_STOP_SEC_VAR_ZERO_INIT_32BIT
    #define STOP_SEC_VAR

#elif defined WDGM_START_SEC_VAR_ZERO_INIT_UNSPECIFIED
    #undef WDGM_START_SEC_VAR_ZERO_INIT_UNSPECIFIED
    #define START_SEC_VAR_CLEARED_UNSPECIFIED_0
#elif defined WDGM_STOP_SEC_VAR_ZERO_INIT_UNSPECIFIED
    #undef WDGM_STOP_SEC_VAR_ZERO_INIT_UNSPECIFIED
    #define STOP_SEC_VAR
                                                 /* GLOBAL DATA OF THE S-WDGM */
#elif defined WDGM_GLOBAL_START_SEC_VAR_ZERO_INIT_32BIT
    #undef WDGM_GLOBAL_START_SEC_VAR_ZERO_INIT_32BIT
	#undef MEMMAP_ERROR
#elif defined WDGM_GLOBAL_STOP_SEC_VAR_ZERO_INIT_32BIT
    #undef WDGM_GLOBAL_STOP_SEC_VAR_ZERO_INIT_32BIT
	#undef MEMMAP_ERROR

                                          /* GLOBAL SHARED DATA OF THE S-WDGM */
#elif defined WDGM_GLOBAL_SHARED_START_SEC_VAR_ZERO_INIT_32BIT
    #undef WDGM_GLOBAL_SHARED_START_SEC_VAR_ZERO_INIT_32BIT
	#undef MEMMAP_ERROR
#elif defined WDGM_GLOBAL_SHARED_STOP_SEC_VAR_ZERO_INIT_32BIT
    #undef WDGM_GLOBAL_SHARED_STOP_SEC_VAR_ZERO_INIT_32BIT
	#undef MEMMAP_ERROR

#elif defined WDGM_START_SEC_CONST_8BIT         /* Global or static constants */
    #undef WDGM_START_SEC_CONST_8BIT
    #define START_SEC_CONST_8BIT
#elif defined WDGM_STOP_SEC_CONST_8BIT
    #undef WDGM_STOP_SEC_CONST_8BIT
    #define STOP_SEC_CONST

#elif defined WDGM_START_SEC_CONST_16BIT
    #undef WDGM_START_SEC_CONST_16BIT
    #define START_SEC_CONST_16BIT
#elif defined WDGM_STOP_SEC_CONST_16BIT
    #undef WDGM_STOP_SEC_CONST_16BIT
    #define STOP_SEC_CONST

#elif defined WDGM_START_SEC_CONST_32BIT
    #undef WDGM_START_SEC_CONST_32BIT
    #define START_SEC_CONST_32BIT
#elif defined WDGM_STOP_SEC_CONST_32BIT
    #undef WDGM_STOP_SEC_CONST_32BIT
    #define STOP_SEC_CONST

#elif defined WDGM_START_SEC_CONST_UNSPECIFIED
    #undef WDGM_START_SEC_CONST_UNSPECIFIED
    #define START_SEC_CONST_UNSPECIFIED
#elif defined WDGM_STOP_SEC_CONST_UNSPECIFIED
    #undef WDGM_STOP_SEC_CONST_UNSPECIFIED
    #define STOP_SEC_CONST

#endif

/* Variables from WdgM_MemMap */
#ifdef Task_for_QM_START_SEC_VAR_NOINIT_32BIT
	#undef Task_for_QM_START_SEC_VAR_NOINIT_32BIT
	#define START_SEC_VAR_NOINIT_32_9
#endif

#ifdef Task_for_QM_STOP_SEC_VAR_NOINIT_32BIT
	#undef Task_for_QM_STOP_SEC_VAR_NOINIT_32BIT
	#define STOP_SEC_VAR
#endif

/**********************************************************************************************************************
 *  SYSSERVICE_ASRWDM END
 *********************************************************************************************************************/






/**********************************************************************************************************************
 *  DrvIcu_Tms570Tinhet01ExtVx START
 *********************************************************************************************************************/

/*******  CODE sections **********************************************************************************************/
#ifdef HET_START_SEC_CODE
    #undef HET_START_SEC_CODE
    #define START_SEC_CODE
#endif

#ifdef HET_STOP_SEC_CODE
    #undef HET_STOP_SEC_CODE
    #define STOP_SEC_CODE
#endif


/*******  VAR sections  **********************************************************************************************/

/* VAR NOINIT sections */
#ifdef HET_START_SEC_VAR_ZERO_INIT_UNSPECIFIED
    #undef HET_START_SEC_VAR_ZERO_INIT_UNSPECIFIED
    #define START_SEC_VAR_CLEARED_UNSPECIFIED_9
#endif

#ifdef HET_STOP_SEC_VAR_ZERO_INIT_UNSPECIFIED
    #undef HET_STOP_SEC_VAR_ZERO_INIT_UNSPECIFIED
    #define STOP_SEC_VAR
#endif

/**********************************************************************************************************************
 *  DrvIcu_Tms570Tinhet01ExtVx END
 *********************************************************************************************************************/



































/**********************************************************************************************************************
 *  XCP START 
 *********************************************************************************************************************/

/*******  CODE sections **********************************************************************************************/

#ifdef XCP_START_SEC_CODE 
    #undef XCP_START_SEC_CODE 
    #define START_SEC_CODE
#endif

#ifdef XCP_STOP_SEC_CODE 
    #undef XCP_STOP_SEC_CODE 
    #define STOP_SEC_CODE
#endif


/*******  CONST sections  ********************************************************************************************/

/* CONST sections */

#ifdef XCP_START_SEC_CONST_UNSPECIFIED
    #undef XCP_START_SEC_CONST_UNSPECIFIED
    #define START_SEC_CONST_UNSPECIFIED
#endif

#ifdef XCP_STOP_SEC_CONST_UNSPECIFIED
    #undef XCP_STOP_SEC_CONST_UNSPECIFIED
    #define STOP_SEC_CONST
#endif

#ifdef XCP_START_SEC_CONST_16BIT 
    #undef XCP_START_SEC_CONST_16BIT 
    #define START_SEC_CONST_16BIT
#endif

#ifdef XCP_STOP_SEC_CONST_16BIT 
    #undef XCP_STOP_SEC_CONST_16BIT 
    #define STOP_SEC_CONST
#endif

#ifdef XCP_START_SEC_CONST_8BIT 
    #undef XCP_START_SEC_CONST_8BIT 
    #define START_SEC_CONST_8BIT
#endif

#ifdef XCP_STOP_SEC_CONST_8BIT 
    #undef XCP_STOP_SEC_CONST_8BIT 
    #define STOP_SEC_CONST
#endif


/*******  VAR sections  **********************************************************************************************/

/* VAR INIT sections */

#ifdef XCP_START_SEC_VAR_NOINIT_UNSPECIFIED 
    #undef XCP_START_SEC_VAR_NOINIT_UNSPECIFIED 
    #define START_SEC_VAR_NOINIT_UNSPECIFIED_9
#endif

#ifdef XCP_STOP_SEC_VAR_NOINIT_UNSPECIFIED 
    #undef XCP_STOP_SEC_VAR_NOINIT_UNSPECIFIED 
    #define STOP_SEC_VAR
#endif

#ifdef XCP_START_SEC_VAR_NOINIT_8BIT 
    #undef XCP_START_SEC_VAR_NOINIT_8BIT 
    #define START_SEC_VAR_NOINIT_8_9
#endif

#ifdef XCP_STOP_SEC_VAR_NOINIT_8BIT 
    #undef XCP_STOP_SEC_VAR_NOINIT_8BIT 
    #define STOP_SEC_VAR
#endif


/**********************************************************************************************************************
 *  XCP END
 *********************************************************************************************************************/



/**********************************************************************************************************************
 *  CanXcp START 
 *********************************************************************************************************************/

/*******  CODE sections **********************************************************************************************/

#ifdef CANXCP_START_SEC_CODE
  #undef CANXCP_START_SEC_CODE
  #define START_SEC_CODE                            /* mapped to default code section */
#endif

#ifdef CANXCP_STOP_SEC_CODE
  #undef CANXCP_STOP_SEC_CODE
  #define STOP_SEC_CODE                             /* default code stop section */
#endif


/*******  CONST sections  ********************************************************************************************/

/* CONST sections */

#ifdef CANXCP_START_SEC_CONST_8BIT
  #undef CANXCP_START_SEC_CONST_8BIT
  #define START_SEC_CONST_8BIT                      /* mapped to const 8 bit section */
#endif

#ifdef CANXCP_STOP_SEC_CONST_8BIT
  #undef CANXCP_STOP_SEC_CONST_8BIT
  #define STOP_SEC_CONST                            /* default const stop section */
#endif


/* Post build config unspecified */

#ifdef CANXCP_START_SEC_PBCFG_ROOT
  #undef CANXCP_START_SEC_PBCFG_ROOT
  #define START_SEC_CONST_PBCFG                     /* mapped to const unspecified section */
#endif

#ifdef CANXCP_STOP_SEC_PBCFG_ROOT
  #undef CANXCP_STOP_SEC_PBCFG_ROOT
  #define STOP_SEC_CONST                            /* default const stop section */
#endif


#ifdef CANXCP_START_SEC_PBCFG
  #undef CANXCP_START_SEC_PBCFG
  #define START_SEC_CONST_PBCFG                     /* mapped to const unspecified section */
#endif

#ifdef CANXCP_STOP_SEC_PBCFG
  #undef CANXCP_STOP_SEC_PBCFG
  #define STOP_SEC_CONST                            /* default const stop section */
#endif


/*******  VAR sections  **********************************************************************************************/

/* VAR INIT sections */

#ifdef CANXCP_START_SEC_VAR_NOINIT_8BIT
  #undef CANXCP_START_SEC_VAR_NOINIT_8BIT
  #define START_SEC_VAR_NOINIT_8_9                 /* mapped to uninitialized RAM 8bit section */
#endif

#ifdef CANXCP_STOP_SEC_VAR_NOINIT_8BIT
  #undef CANXCP_STOP_SEC_VAR_NOINIT_8BIT
  #define STOP_SEC_VAR                              /* default RAM stop section */
#endif


/* Var noinit unspecified */
#ifdef CANXCP_START_SEC_VAR_NOINIT_UNSPECIFIED
  #undef CANXCP_START_SEC_VAR_NOINIT_UNSPECIFIED
  #define START_SEC_VAR_NOINIT_UNSPECIFIED_9          /* mapped to uninitialized RAM unspecified section */
#endif

#ifdef CANXCP_STOP_SEC_VAR_NOINIT_UNSPECIFIED
  #undef CANXCP_STOP_SEC_VAR_NOINIT_UNSPECIFIED
  #define STOP_SEC_VAR                              /* default RAM stop section */
#endif


/**********************************************************************************************************************
 *  CANXCP END
 *********************************************************************************************************************/












/** DEM ***************************************************************************/
/*---------------------START-MODULE-SPECIFIC-START-SECTIONS-----------------------*/
                                                              /* code section */
#if defined (DEM_START_SEC_CODE)
    #undef DEM_START_SEC_CODE
    #define START_SEC_CODE
#endif
                                                              /* vars initialized by startup code */
#if defined (DEM_START_SEC_VAR_8BIT)
    #undef DEM_START_SEC_VAR_8BIT
    #define START_SEC_VAR_INIT_8_9
#endif
#if defined (DEM_START_SEC_VAR_32BIT)
    #undef DEM_START_SEC_VAR_32BIT
    #define START_SEC_VAR_INIT_32_9
#endif
                                                              /* never initialized vars with high number of accesses */
#if defined (DEM_START_SEC_VAR_FAST_8BIT)
    #undef DEM_START_SEC_VAR_FAST_8BIT
    #define START_SEC_VAR_FAST_NOINIT_8BIT
#endif
#if defined (DEM_START_SEC_VAR_FAST_16BIT)
    #undef DEM_START_SEC_VAR_FAST_16BIT
    #define START_SEC_VAR_FAST_NOINIT_16BIT
#endif
#if defined (DEM_START_SEC_VAR_FAST_32BIT)
    #undef DEM_START_SEC_VAR_FAST_32BIT
    #define START_SEC_VAR_FAST_NOINIT_32BIT
#endif
                                                              /* never initialized vars */
#if defined (DEM_START_SEC_VAR_NOINIT_8BIT)
    #undef DEM_START_SEC_VAR_NOINIT_8BIT
    #define START_SEC_VAR_NOINIT_8BIT
#endif
#if defined (DEM_START_SEC_VAR_NOINIT_16BIT)
    #undef DEM_START_SEC_VAR_NOINIT_16BIT
    #define START_SEC_VAR_NOINIT_16BIT
#endif
#if defined (DEM_START_SEC_VAR_NOINIT_UNSPECIFIED)
    #undef DEM_START_SEC_VAR_NOINIT_UNSPECIFIED
    #define START_SEC_VAR_NOINIT_UNSPECIFIED
#endif
                                                              /* vars saved in non volatile memory */
#if defined (DEM_START_SEC_VAR_SAVED_ZONE0_UNSPECIFIED)
    #undef DEM_START_SEC_VAR_SAVED_ZONE0_UNSPECIFIED
    #define START_SEC_VAR_FAST_NOINIT_UNSPECIFIED
#endif
                                                              /* global or static constants */
#if defined (DEM_START_SEC_CONST_8BIT)
    #undef DEM_START_SEC_CONST_8BIT
    #define START_SEC_CONST_8BIT
#endif
#if defined (DEM_START_SEC_CONST_32BIT)
    #undef DEM_START_SEC_CONST_32BIT
    #define START_SEC_CONST_32BIT
#endif
#if defined (DEM_START_SEC_CONST_UNSPECIFIED)
    #undef DEM_START_SEC_CONST_UNSPECIFIED
    #define START_SEC_CONST_UNSPECIFIED
#endif
                                                              /* global or static constants (linktime) */
#if defined (DEM_START_SEC_CONST_LCFG)
    #undef DEM_START_SEC_CONST_LCFG
    #define START_SEC_CONST_UNSPECIFIED
#endif
                                                              /* global or static constants (postbuild) */
#if defined (DEM_START_SEC_PBCONST_ROOT)
    #undef DEM_START_SEC_PBCONST_ROOT
    #define START_SEC_CONST_PBCFG
#endif
#if defined (DEM_START_SEC_PBCONST)
    #undef DEM_START_SEC_PBCONST
    #define START_SEC_CONST_PBCFG
#endif
/*---------------------STOP-MODULE-SPECIFIC-START-SECTIONS------------------------*/

/*---------------------START-MODULE-SPECIFIC-STOP-SECTIONS------------------------*/

#if defined (DEM_STOP_SEC_CODE)
    #undef DEM_STOP_SEC_CODE
    #define STOP_SEC_CODE
#endif

#if defined (DEM_STOP_SEC_VAR_8BIT)
    #undef DEM_STOP_SEC_VAR_8BIT
    #define STOP_SEC_VAR
#endif
#if defined (DEM_STOP_SEC_VAR_32BIT)
    #undef DEM_STOP_SEC_VAR_32BIT
    #define STOP_SEC_VAR
#endif


#if defined (DEM_STOP_SEC_VAR_FAST_8BIT)
    #undef DEM_STOP_SEC_VAR_FAST_8BIT
    #define STOP_SEC_VAR
#endif
#if defined (DEM_STOP_SEC_VAR_FAST_16BIT)
    #undef DEM_STOP_SEC_VAR_FAST_16BIT
    #define STOP_SEC_VAR
#endif
#if defined (DEM_STOP_SEC_VAR_FAST_32BIT)
    #undef DEM_STOP_SEC_VAR_FAST_32BIT
    #define STOP_SEC_VAR
#endif

#if defined (DEM_STOP_SEC_VAR_NOINIT_8BIT)
    #undef DEM_STOP_SEC_VAR_NOINIT_8BIT
    #define STOP_SEC_VAR
#endif
#if defined (DEM_STOP_SEC_VAR_NOINIT_16BIT)
    #undef DEM_STOP_SEC_VAR_NOINIT_16BIT
    #define STOP_SEC_VAR
#endif
#if defined (DEM_STOP_SEC_VAR_NOINIT_UNSPECIFIED)
    #undef DEM_STOP_SEC_VAR_NOINIT_UNSPECIFIED
    #define STOP_SEC_VAR
#endif

#if defined (DEM_STOP_SEC_VAR_SAVED_ZONE0_UNSPECIFIED)
    #undef DEM_STOP_SEC_VAR_SAVED_ZONE0_UNSPECIFIED
    #define STOP_SEC_VAR
#endif

#if defined (DEM_STOP_SEC_CONST_8BIT)
    #undef DEM_STOP_SEC_CONST_8BIT
    #define STOP_SEC_CONST
#endif
#if defined (DEM_STOP_SEC_CONST_32BIT)
    #undef DEM_STOP_SEC_CONST_32BIT
    #define STOP_SEC_CONST
#endif
#if defined (DEM_STOP_SEC_CONST_UNSPECIFIED)
    #undef DEM_STOP_SEC_CONST_UNSPECIFIED
    #define STOP_SEC_CONST
#endif

#if defined (DEM_STOP_SEC_CONST_LCFG)
    #undef DEM_STOP_SEC_CONST_LCFG
    #define STOP_SEC_CONST
#endif

#if defined (DEM_STOP_SEC_PBCONST_ROOT)
    #undef DEM_STOP_SEC_PBCONST_ROOT
    #define STOP_SEC_CONST
#endif
#if defined (DEM_STOP_SEC_PBCONST)
    #undef DEM_STOP_SEC_PBCONST
    #define STOP_SEC_CONST
#endif
/*---------------------STOP-MODULE-SPECIFIC-STOP-SECTIONS------------------------*/
/** End of DEM *******************************************************************/



















/* Kernbauer Version: 1.16 Konfiguration: DrvCAN Erzeugungsgangnummer: 486 */

/*-------------------------------------------------------------------------------------------------------------------*/
/* CAN driver start MemMap.inc                                                                                       */
/*-------------------------------------------------------------------------------------------------------------------*/


/*---------------------------------- Code ---------------------------------------------------------------------------*/
#ifdef CAN_START_SEC_CODE                             /* CAN code */
# undef CAN_START_SEC_CODE                              /* PRQA S 0841 */
# define START_SEC_CODE                               /* mapped to default code section */
#endif
#ifdef CAN_STOP_SEC_CODE
# undef CAN_STOP_SEC_CODE                               /* PRQA S 0841 */
# define STOP_SEC_CODE
#endif

#ifdef CAN_START_SEC_CODE_APPL                        /* Appl code (generic precopy)*/
# undef CAN_START_SEC_CODE_APPL                         /* PRQA S 0841 */
# define START_SEC_CODE                               /* mapped to default code section */
#endif
#ifdef CAN_STOP_SEC_CODE_APPL
# undef CAN_STOP_SEC_CODE_APPL                          /* PRQA S 0841 */
# define STOP_SEC_CODE
#endif

/*---------------------------------- Const --------------------------------------------------------------------------*/

#ifdef CAN_START_SEC_CONST_8BIT                       /* Const 8bit */
# undef CAN_START_SEC_CONST_8BIT                        /* PRQA S 0841 */
# define START_SEC_CONST_8BIT                         /* mapped to default const 8bit section */
#endif
#ifdef CAN_STOP_SEC_CONST_8BIT
# undef CAN_STOP_SEC_CONST_8BIT                         /* PRQA S 0841 */
# define STOP_SEC_CONST
#endif

#ifdef CAN_START_SEC_CONST_16BIT                      /* Const 16bit */
# undef CAN_START_SEC_CONST_16BIT                       /* PRQA S 0841 */
# define START_SEC_CONST_16BIT                        /* mapped to default const 16bit section */
#endif
#ifdef CAN_STOP_SEC_CONST_16BIT
# undef CAN_STOP_SEC_CONST_16BIT                        /* PRQA S 0841 */
# define STOP_SEC_CONST
#endif

#ifdef CAN_START_SEC_CONST_32BIT                      /* Const 32bit */
# undef CAN_START_SEC_CONST_32BIT                       /* PRQA S 0841 */
# define START_SEC_CONST_32BIT                        /* mapped to default const 32bit section */
#endif
#ifdef CAN_STOP_SEC_CONST_32BIT
# undef CAN_STOP_SEC_CONST_32BIT                        /* PRQA S 0841 */
# define STOP_SEC_CONST
#endif

#ifdef CAN_START_SEC_CONST_UNSPECIFIED                /* Const unspecified */
# undef CAN_START_SEC_CONST_UNSPECIFIED                 /* PRQA S 0841 */
# define START_SEC_CONST_UNSPECIFIED                  /* mapped to default const unspec section */
#endif
#ifdef CAN_STOP_SEC_CONST_UNSPECIFIED
# undef CAN_STOP_SEC_CONST_UNSPECIFIED                  /* PRQA S 0841 */
# define STOP_SEC_CONST
#endif

#ifdef CAN_START_SEC_PBCFG                            /* Generated Postbuild */
# undef CAN_START_SEC_PBCFG                             /* PRQA S 0841 */
# define START_SEC_CONST_PBCFG                        /* mapped to default const postbuild section */
/*# define START_SEC_PBCONST                           compatibility to older version */
#endif
#ifdef CAN_STOP_SEC_PBCFG
# undef CAN_STOP_SEC_PBCFG                              /* PRQA S 0841 */
# define STOP_SEC_CONST
#endif
#ifdef CAN_START_SEC_PBCFG_ROOT                       /* Generated Postbuild Root Table */
# undef CAN_START_SEC_PBCFG_ROOT                        /* PRQA S 0841 */
# define START_SEC_CONST_PBCFG                        /* mapped to default const postbuild section */
/*# define START_SEC_PBCONST                           compatibility to older version */
#endif
#ifdef CAN_STOP_SEC_PBCFG_ROOT
# undef CAN_STOP_SEC_PBCFG_ROOT                         /* PRQA S 0841 */
# define STOP_SEC_CONST
#endif

/*---------------------------------- RAM ----------------------------------------------------------------------------*/

#ifdef CAN_START_SEC_VAR_NOINIT_UNSPECIFIED           /* uninit RAM*/
# undef CAN_START_SEC_VAR_NOINIT_UNSPECIFIED            /* PRQA S 0841 */
# define START_SEC_VAR_NOINIT_UNSPECIFIED_9             /* mapped to default uninit var section */
#endif
#ifdef CAN_STOP_SEC_VAR_NOINIT_UNSPECIFIED
# undef CAN_STOP_SEC_VAR_NOINIT_UNSPECIFIED             /* PRQA S 0841 */
# define STOP_SEC_VAR
#endif

#ifdef CAN_START_SEC_VAR_INIT_UNSPECIFIED             /* init RAM*/
# undef CAN_START_SEC_VAR_INIT_UNSPECIFIED              /* PRQA S 0841 */
# define START_SEC_VAR_INIT_UNSPECIFIED_9               /* mapped to default init var section */
#endif
#ifdef CAN_STOP_SEC_VAR_INIT_UNSPECIFIED
# undef CAN_STOP_SEC_VAR_INIT_UNSPECIFIED               /* PRQA S 0841 */
# define STOP_SEC_VAR
#endif


/*-------------------------------------------------------------------------------------------------------------------*/
/* CAN driver end MemMap.inc                                                                                         */
/*-------------------------------------------------------------------------------------------------------------------*/





/**********************************************************************************************************************
 *  PDUR START
 *********************************************************************************************************************/

/*******  CODE sections **********************************************************************************************/

#ifdef PDUR_START_SEC_CODE
# undef PDUR_START_SEC_CODE
# define START_SEC_CODE
#endif
#ifdef PDUR_STOP_SEC_CODE
# undef PDUR_STOP_SEC_CODE
# define STOP_SEC_CODE
#endif


/*******  CONST sections  ********************************************************************************************/

/* CONST sections */

#ifdef PDUR_START_SEC_CONST_8BIT
# undef PDUR_START_SEC_CONST_8BIT
# define START_SEC_CONST_8BIT
#endif
#ifdef PDUR_STOP_SEC_CONST_8BIT
# undef PDUR_STOP_SEC_CONST_8BIT
# define STOP_SEC_CONST
#endif

#ifdef PDUR_START_SEC_CONST_32BIT
# undef PDUR_START_SEC_CONST_32BIT
# define START_SEC_CONST_32BIT
#endif
#ifdef PDUR_STOP_SEC_CONST_32BIT
# undef PDUR_STOP_SEC_CONST_32BIT
# define STOP_SEC_CONST
#endif

#ifdef PDUR_START_SEC_CONST_UNSPECIFIED
# undef PDUR_START_SEC_CONST_UNSPECIFIED
# define START_SEC_CONST_UNSPECIFIED
#endif
#ifdef PDUR_STOP_SEC_CONST_UNSPECIFIED
# undef PDUR_STOP_SEC_CONST_UNSPECIFIED
# define STOP_SEC_CONST
#endif


/* FAST CONST sections */



/* Postbuild CFG CONST sections */

/* Root table for postbuild data */
#ifdef PDUR_START_SEC_PBCFG
# undef PDUR_START_SEC_PBCFG
# define START_SEC_CONST_PBCFG
#endif
#ifdef PDUR_STOP_SEC_PBCFG
# undef PDUR_STOP_SEC_PBCFG
# define STOP_SEC_CONST
#endif

#ifdef PDUR_START_SEC_PBCFG_ROOT
# undef PDUR_START_SEC_PBCFG_ROOT
# define START_SEC_CONST_PBCFG
#endif
#ifdef PDUR_STOP_SEC_PBCFG_ROOT
# undef PDUR_STOP_SEC_PBCFG_ROOT
# define STOP_SEC_CONST
#endif


/*******  VAR sections  **********************************************************************************************/

/* VAR INIT sections */

#ifdef PDUR_START_SEC_VAR_ZERO_INIT_UNSPECIFIED
# undef PDUR_START_SEC_VAR_ZERO_INIT_UNSPECIFIED
# define START_SEC_VAR_CLEARED_UNSPECIFIED_9
#endif
#ifdef PDUR_STOP_SEC_VAR_ZERO_INIT_UNSPECIFIED
# undef PDUR_STOP_SEC_VAR_ZERO_INIT_UNSPECIFIED
# define STOP_SEC_VAR
#endif


/* VAR NOINIT sections */

#ifdef PDUR_START_SEC_VAR_NOINIT_BOOLEAN
# undef PDUR_START_SEC_VAR_NOINIT_BOOLEAN
# define START_SEC_VAR_NOINIT_8_9
#endif
#ifdef PDUR_STOP_SEC_VAR_NOINIT_BOOLEAN
# undef PDUR_STOP_SEC_VAR_NOINIT_BOOLEAN
# define STOP_SEC_VAR
#endif



#ifdef PDUR_START_SEC_VAR_NOINIT_UNSPECIFIED
# undef PDUR_START_SEC_VAR_NOINIT_UNSPECIFIED
# define START_SEC_VAR_NOINIT_UNSPECIFIED_9
#endif
#ifdef PDUR_STOP_SEC_VAR_NOINIT_UNSPECIFIED
# undef PDUR_STOP_SEC_VAR_NOINIT_UNSPECIFIED
# define STOP_SEC_VAR
#endif


/* VAR ZERO INIT sections */



/* VAR FAST INIT sections */



/* VAR FAST NOINIT sections */


/* VAR FAST ZERO INIT sections */



/**********************************************************************************************************************
 *  PDUR END
 *********************************************************************************************************************/


/*-------------------------------------------------------------------------------------------------------------------*/
/* CANIF                                                                                                             */
/*-------------------------------------------------------------------------------------------------------------------*/

/* Code */

#ifdef CANIF_START_SEC_CODE
# undef CANIF_START_SEC_CODE
# define START_SEC_CODE                            /* mapped to default code section */
#endif

#ifdef CANIF_STOP_SEC_CODE
# undef CANIF_STOP_SEC_CODE
# define STOP_SEC_CODE                             /* default code stop section */
#endif


#ifdef CANIF_START_SEC_APPL_CODE
# undef CANIF_START_SEC_APPL_CODE
# define START_SEC_CODE                            /* mapped to default code section */
#endif

#ifdef CANIF_STOP_SEC_APPL_CODE
# undef CANIF_STOP_SEC_APPL_CODE
# define STOP_SEC_CODE                             /* default code stop section */
#endif




/* Const 8bit */

#ifdef CANIF_START_SEC_CONST_8BIT
# undef CANIF_START_SEC_CONST_8BIT
# define START_SEC_CONST_8BIT                      /* mapped to const 8 bit section */
#endif

#ifdef CANIF_STOP_SEC_CONST_8BIT
# undef CANIF_STOP_SEC_CONST_8BIT
# define STOP_SEC_CONST                            /* default const stop section */
#endif

/* Const 32bit */

#ifdef CANIF_START_SEC_CONST_32BIT
# undef CANIF_START_SEC_CONST_32BIT
# define START_SEC_CONST_32BIT                      /* mapped to const 32 bit section */
#endif

#ifdef CANIF_STOP_SEC_CONST_32BIT
# undef CANIF_STOP_SEC_CONST_32BIT
# define STOP_SEC_CONST                            /* default const stop section */
#endif


/* Const unspecified */

#ifdef CANIF_START_SEC_CONST_UNSPECIFIED
# undef CANIF_START_SEC_CONST_UNSPECIFIED
# define START_SEC_CONST_UNSPECIFIED               /* mapped to const unspecified section */
#endif

#ifdef CANIF_STOP_SEC_CONST_UNSPECIFIED
# undef CANIF_STOP_SEC_CONST_UNSPECIFIED
# define STOP_SEC_CONST                            /* default const stop section */
#endif


/* Post build config unspecified */

#ifdef CANIF_START_SEC_PBCFG
# undef CANIF_START_SEC_PBCFG
# define START_SEC_CONST_PBCFG                     /* mapped to const unspecified section */
#endif

#ifdef CANIF_STOP_SEC_PBCFG
# undef CANIF_STOP_SEC_PBCFG
# define STOP_SEC_CONST                            /* default const stop section */
#endif

#ifdef CANIF_START_SEC_PBCFG_ROOT
# undef CANIF_START_SEC_PBCFG_ROOT
# define START_SEC_CONST_PBCFG                     /* mapped to const unspecified section */
#endif

#ifdef CANIF_STOP_SEC_PBCFG_ROOT
# undef CANIF_STOP_SEC_PBCFG_ROOT
# define STOP_SEC_CONST                            /* default const stop section */
#endif


/* Var noinit unspecified */

#ifdef CANIF_START_SEC_VAR_NOINIT_UNSPECIFIED
# undef CANIF_START_SEC_VAR_NOINIT_UNSPECIFIED
# define START_SEC_VAR_NOINIT_UNSPECIFIED_9          /* mapped to uninitialized RAM unspecified section */
#endif

#ifdef CANIF_STOP_SEC_VAR_NOINIT_UNSPECIFIED
# undef CANIF_STOP_SEC_VAR_NOINIT_UNSPECIFIED
# define STOP_SEC_VAR                              /* default RAM stop section */
#endif

/* Var zero init unspecified */
#ifdef CANIF_START_SEC_VAR_ZERO_INIT_UNSPECIFIED
# undef CANIF_START_SEC_VAR_ZERO_INIT_UNSPECIFIED
# define START_SEC_VAR_CLEARED_UNSPECIFIED_9       /* mapped to zero initialized RAM unspecified section */
#endif

#ifdef CANIF_STOP_SEC_VAR_ZERO_INIT_UNSPECIFIED
# undef CANIF_STOP_SEC_VAR_ZERO_INIT_UNSPECIFIED
# define STOP_SEC_VAR                              /* default RAM stop section */
#endif


/* Var init unspecified */
#ifdef CANIF_START_SEC_VAR_INIT_UNSPECIFIED
# undef CANIF_START_SEC_VAR_INIT_UNSPECIFIED
# define START_SEC_VAR_INIT_UNSPECIFIED_9            /* mapped to initialized RAM unspecified section */
#endif

#ifdef CANIF_STOP_SEC_VAR_INIT_UNSPECIFIED
# undef CANIF_STOP_SEC_VAR_INIT_UNSPECIFIED
# define STOP_SEC_VAR                              /* default RAM stop section */
#endif


/*-------------------------------------------------------------------------------------------------------------------*/
/* CANIF                                                                                                             */
/*-------------------------------------------------------------------------------------------------------------------*/



/**********************************************************************************************************************
 *  Com START
 *********************************************************************************************************************/

/*******  CODE sections **********************************************************************************************/

#ifdef COM_START_SEC_CODE
# undef COM_START_SEC_CODE
# define START_SEC_CODE
#endif
#ifdef COM_STOP_SEC_CODE
# undef COM_STOP_SEC_CODE
# define STOP_SEC_CODE
#endif
/* COM application callback code section (Rte_Cbk.h)*/
#ifdef COM_START_SEC_APPL_CODE
# undef COM_START_SEC_APPL_CODE
# define START_SEC_CODE
#endif
#ifdef COM_STOP_SEC_APPL_CODE
# undef COM_STOP_SEC_APPL_CODE
# define STOP_SEC_CODE
#endif


/*******  CONST sections  ********************************************************************************************/

/* CONST sections */

#ifdef COM_START_SEC_CONST_32BIT
# undef COM_START_SEC_CONST_32BIT
# define START_SEC_CONST_32BIT
#endif
#ifdef COM_STOP_SEC_CONST_32BIT
# undef COM_STOP_SEC_CONST_32BIT
# define STOP_SEC_CONST
#endif

#ifdef COM_START_SEC_CONST_UNSPECIFIED
# undef COM_START_SEC_CONST_UNSPECIFIED
# define START_SEC_CONST_UNSPECIFIED
#endif
#ifdef COM_STOP_SEC_CONST_UNSPECIFIED
# undef COM_STOP_SEC_CONST_UNSPECIFIED
# define STOP_SEC_CONST
#endif


/* FAST CONST sections */



/* Postbuild CFG CONST sections */

/* Root table for postbuild data */
#ifdef COM_START_SEC_PBCFG_ROOT
# undef COM_START_SEC_PBCFG_ROOT
# define START_SEC_CONST_PBCFG
#endif
#ifdef COM_STOP_SEC_PBCFG_ROOT
# undef COM_STOP_SEC_PBCFG_ROOT
# define STOP_SEC_CONST
#endif

#ifdef COM_START_SEC_PBCFG
# undef COM_START_SEC_PBCFG
# define START_SEC_CONST_PBCFG
#endif
#ifdef COM_STOP_SEC_PBCFG
# undef COM_STOP_SEC_PBCFG
# define STOP_SEC_CONST
#endif


/*******  VAR sections  **********************************************************************************************/

/* VAR INIT sections */

#ifdef COM_START_SEC_VAR_INIT_UNSPECIFIED
# undef COM_START_SEC_VAR_INIT_UNSPECIFIED
# define START_SEC_VAR_INIT_UNSPECIFIED_9
#endif
#ifdef COM_STOP_SEC_VAR_INIT_UNSPECIFIED
# undef COM_STOP_SEC_VAR_INIT_UNSPECIFIED
# define STOP_SEC_VAR
#endif


/* VAR NOINIT sections */

#ifdef COM_START_SEC_VAR_NOINIT_BOOLEAN
# undef COM_START_SEC_VAR_NOINIT_BOOLEAN
# define START_SEC_VAR_NOINIT_8_9
#endif
#ifdef COM_STOP_SEC_VAR_NOINIT_BOOLEAN
# undef COM_STOP_SEC_VAR_NOINIT_BOOLEAN
# define STOP_SEC_VAR
#endif

#ifdef COM_START_SEC_VAR_NOINIT_8BIT
# undef COM_START_SEC_VAR_NOINIT_8BIT
# define START_SEC_VAR_NOINIT_8_9
#endif
#ifdef COM_STOP_SEC_VAR_NOINIT_8BIT
# undef COM_STOP_SEC_VAR_NOINIT_8BIT
# define STOP_SEC_VAR
#endif

#ifdef COM_START_SEC_VAR_NOINIT_16BIT
# undef COM_START_SEC_VAR_NOINIT_16BIT
# define START_SEC_VAR_NOINIT_16_9
#endif
#ifdef COM_STOP_SEC_VAR_NOINIT_16BIT
# undef COM_STOP_SEC_VAR_NOINIT_16BIT
# define STOP_SEC_VAR
#endif

#ifdef COM_START_SEC_VAR_NOINIT_UNSPECIFIED
# undef COM_START_SEC_VAR_NOINIT_UNSPECIFIED
# define START_SEC_VAR_NOINIT_UNSPECIFIED_9
#endif
#ifdef COM_STOP_SEC_VAR_NOINIT_UNSPECIFIED
# undef COM_STOP_SEC_VAR_NOINIT_UNSPECIFIED
# define STOP_SEC_VAR
#endif


/* VAR ZERO INIT sections */



/* VAR FAST INIT sections */



/* VAR FAST NOINIT sections */


/* VAR FAST ZERO INIT sections */



/**********************************************************************************************************************
 *  Com END
 *********************************************************************************************************************/






/* Package Merger: Stop Section MemMapModuleList */ 

/*------------------------------GLOBAL-SECTIONS-----------------------------*/
/* Check code sections */
#if ( (defined CODE_SEC_OPEN)                            && \
     ((defined START_SEC_CODE                          ) || \
      (defined START_SEC_CODE_FAST                     ) || \
      (defined START_SEC_CODE_ISR                      )    \
      ))
    #error "MemMap.h: Close the former code segment before opening a new one."
#endif

/* Check const sections */
#if ( (defined CONST_SEC_OPEN)                           && \
     ((defined START_SEC_CONST_8BIT                    ) || \
      (defined START_SEC_CONST_16BIT                   ) || \
      (defined START_SEC_CONST_32BIT                   ) || \
      (defined START_SEC_CONST_UNSPECIFIED             ) || \
      (defined START_SEC_CONST_FAST_8BIT               ) || \
      (defined START_SEC_CONST_FAST_16BIT              ) || \
      (defined START_SEC_CONST_FAST_32BIT              ) || \
      (defined START_SEC_CONST_FAST_UNSPECIFIED        ) || \
      (defined START_SEC_CONST_PBCFG                   )    \
      ))
    #error "MemMap.h: Close the former const segment before opening a new one."
#endif

/* Check data sections */
#if ( (defined VAR_SEC_OPEN)                             && \
     ((defined START_SEC_VAR_INIT_8BIT                 ) || \
      (defined START_SEC_VAR_INIT_16BIT                ) || \
      (defined START_SEC_VAR_INIT_32BIT                ) || \
      (defined START_SEC_VAR_INIT_UNSPECIFIED          ) || \
      (defined START_SEC_VAR_NOINIT_8BIT               ) || \
      (defined START_SEC_VAR_NOINIT_16BIT              ) || \
      (defined START_SEC_VAR_NOINIT_32BIT              ) || \
      (defined START_SEC_VAR_NOINIT_UNSPECIFIED        ) || \
      (defined START_SEC_VAR_ZERO_INIT_8BIT            ) || \
      (defined START_SEC_VAR_ZERO_INIT_16BIT           ) || \
      (defined START_SEC_VAR_ZERO_INIT_32BIT           ) || \
      (defined START_SEC_VAR_ZERO_INIT_UNSPECIFIED     ) || \
      (defined START_SEC_VAR_FAST_INIT_8BIT            ) || \
      (defined START_SEC_VAR_FAST_INIT_16BIT           ) || \
      (defined START_SEC_VAR_FAST_INIT_32BIT           ) || \
      (defined START_SEC_VAR_FAST_INIT_UNSPECIFIED     ) || \
      (defined START_SEC_VAR_FAST_NOINIT_8BIT          ) || \
      (defined START_SEC_VAR_FAST_NOINIT_16BIT         ) || \
      (defined START_SEC_VAR_FAST_NOINIT_32BIT         ) || \
      (defined START_SEC_VAR_FAST_NOINIT_UNSPECIFIED   ) || \
      (defined START_SEC_VAR_FAST_ZERO_INIT_8BIT       ) || \
      (defined START_SEC_VAR_FAST_ZERO_INIT_16BIT      ) || \
      (defined START_SEC_VAR_FAST_ZERO_INIT_32BIT      ) || \
      (defined START_SEC_VAR_FAST_ZERO_INIT_UNSPECIFIED)    \
      ))
    #error "MemMap.h: Close the former variable segment before opening a new one."
#endif



/*------------------------------GLOBAL-START-SECTIONS------------------------------*/

/* Code section */
#ifdef START_SEC_CODE                          
    #define CODE_SEC_OPEN
/* Enter here a #pragma command for opening the specified section */
/*    #pragma */
    #undef START_SEC_CODE                          
    #undef MEMMAP_ERROR
#endif


#ifdef START_SEC_CODE_FAST                     
    #define CODE_SEC_OPEN
/* Enter here a #pragma command for opening the specified section */
/*    #pragma */
    #undef START_SEC_CODE_FAST                     
    #undef MEMMAP_ERROR
#endif


#ifdef START_SEC_CODE_ISR                      
    #define CODE_SEC_OPEN
/* Enter here a #pragma command for opening the specified section */
/*    #pragma */
    #undef START_SEC_CODE_ISR                      
    #undef MEMMAP_ERROR
#endif




/* Const section */
#ifdef START_SEC_CONST_8BIT                    
    #define CONST_SEC_OPEN
/* Enter here a #pragma command for opening the specified section */
/*    #pragma */
    #undef START_SEC_CONST_8BIT                    
    #undef MEMMAP_ERROR
#endif


#ifdef START_SEC_CONST_16BIT                   
    #define CONST_SEC_OPEN
/* Enter here a #pragma command for opening the specified section */
/*    #pragma */
    #undef START_SEC_CONST_16BIT                   
    #undef MEMMAP_ERROR
#endif


#ifdef START_SEC_CONST_32BIT                   
    #define CONST_SEC_OPEN
/* Enter here a #pragma command for opening the specified section */
/*    #pragma */
    #undef START_SEC_CONST_32BIT                   
    #undef MEMMAP_ERROR
#endif


#ifdef START_SEC_CONST_UNSPECIFIED             
    #define CONST_SEC_OPEN
/* Enter here a #pragma command for opening the specified section */
/*    #pragma */
    #undef START_SEC_CONST_UNSPECIFIED             
    #undef MEMMAP_ERROR
#endif


#ifdef START_SEC_CONST_FAST_8BIT               
    #define CONST_SEC_OPEN
/* Enter here a #pragma command for opening the specified section */
/*    #pragma */
    #undef START_SEC_CONST_FAST_8BIT               
    #undef MEMMAP_ERROR
#endif


#ifdef START_SEC_CONST_FAST_16BIT              
    #define CONST_SEC_OPEN
/* Enter here a #pragma command for opening the specified section */
/*    #pragma */
    #undef START_SEC_CONST_FAST_16BIT              
    #undef MEMMAP_ERROR
#endif


#ifdef START_SEC_CONST_FAST_32BIT              
    #define CONST_SEC_OPEN
/* Enter here a #pragma command for opening the specified section */
/*    #pragma */
    #undef START_SEC_CONST_FAST_32BIT              
    #undef MEMMAP_ERROR
#endif


#ifdef START_SEC_CONST_FAST_UNSPECIFIED        
    #define CONST_SEC_OPEN
/* Enter here a #pragma command for opening the specified section */
/*    #pragma */
    #undef START_SEC_CONST_FAST_UNSPECIFIED        
    #undef MEMMAP_ERROR
#endif


#ifdef START_SEC_CONST_PBCFG                   
    #define CONST_SEC_OPEN
/* Enter here a #pragma command for opening the specified section */
/*    #pragma */
    #undef START_SEC_CONST_PBCFG                   
    #undef MEMMAP_ERROR
#endif




/* Var section */
#ifdef START_SEC_VAR_INIT_8BIT                 
    #define VAR_SEC_OPEN
/* Enter here a #pragma command for opening the specified section */
#pragma SET_DATA_SECTION(".ossDataAp_9:init")
    #undef START_SEC_VAR_INIT_8BIT                 
    #undef MEMMAP_ERROR
#endif


#ifdef START_SEC_VAR_INIT_16BIT                
    #define VAR_SEC_OPEN
/* Enter here a #pragma command for opening the specified section */
#pragma SET_DATA_SECTION(".ossDataAp_9:init")
    #undef START_SEC_VAR_INIT_16BIT                
    #undef MEMMAP_ERROR
#endif


#ifdef START_SEC_VAR_INIT_32BIT                
    #define VAR_SEC_OPEN
/* Enter here a #pragma command for opening the specified section */
#pragma SET_DATA_SECTION(".ossDataAp_9:init")
    #undef START_SEC_VAR_INIT_32BIT                
    #undef MEMMAP_ERROR
#endif


#ifdef START_SEC_VAR_INIT_UNSPECIFIED          
    #define VAR_SEC_OPEN
/* Enter here a #pragma command for opening the specified section */
#pragma SET_DATA_SECTION(".ossDataAp_9:init")
    #undef START_SEC_VAR_INIT_UNSPECIFIED          
    #undef MEMMAP_ERROR
#endif


#ifdef START_SEC_VAR_NOINIT_8BIT               
    #define VAR_SEC_OPEN
/* Enter here a #pragma command for opening the specified section */
#pragma SET_DATA_SECTION(".ossDataAp_9:noinit")
    #undef START_SEC_VAR_NOINIT_8BIT               
    #undef MEMMAP_ERROR
#endif


#ifdef START_SEC_VAR_NOINIT_16BIT              
    #define VAR_SEC_OPEN
/* Enter here a #pragma command for opening the specified section */
#pragma SET_DATA_SECTION(".ossDataAp_9:noinit")
    #undef START_SEC_VAR_NOINIT_16BIT              
    #undef MEMMAP_ERROR
#endif


#ifdef START_SEC_VAR_NOINIT_32BIT              
    #define VAR_SEC_OPEN
/* Enter here a #pragma command for opening the specified section */
#pragma SET_DATA_SECTION(".ossDataAp_9:noinit")
    #undef START_SEC_VAR_NOINIT_32BIT              
    #undef MEMMAP_ERROR
#endif


#ifdef START_SEC_VAR_NOINIT_UNSPECIFIED        
    #define VAR_SEC_OPEN
/* Enter here a #pragma command for opening the specified section */
#pragma SET_DATA_SECTION(".ossDataAp_9:noinit")
    #undef START_SEC_VAR_NOINIT_UNSPECIFIED        
    #undef MEMMAP_ERROR
#endif


#ifdef START_SEC_VAR_ZERO_INIT_8BIT            
    #define VAR_SEC_OPEN
/* Enter here a #pragma command for opening the specified section */
#pragma SET_DATA_SECTION(".ossDataAp_9:init")
    #undef START_SEC_VAR_ZERO_INIT_8BIT            
    #undef MEMMAP_ERROR
#endif


#ifdef START_SEC_VAR_ZERO_INIT_16BIT           
    #define VAR_SEC_OPEN
/* Enter here a #pragma command for opening the specified section */
#pragma SET_DATA_SECTION(".ossDataAp_9:init")
    #undef START_SEC_VAR_ZERO_INIT_16BIT           
    #undef MEMMAP_ERROR
#endif


#ifdef START_SEC_VAR_ZERO_INIT_32BIT           
    #define VAR_SEC_OPEN
/* Enter here a #pragma command for opening the specified section */
#pragma SET_DATA_SECTION(".ossDataAp_9:init")
    #undef START_SEC_VAR_ZERO_INIT_32BIT           
    #undef MEMMAP_ERROR
#endif


#ifdef START_SEC_VAR_ZERO_INIT_UNSPECIFIED     
    #define VAR_SEC_OPEN
/* Enter here a #pragma command for opening the specified section */
#pragma SET_DATA_SECTION(".ossDataAp_9:init")
    #undef START_SEC_VAR_ZERO_INIT_UNSPECIFIED     
    #undef MEMMAP_ERROR
#endif


#ifdef START_SEC_VAR_FAST_INIT_8BIT            
    #define VAR_SEC_OPEN
/* Enter here a #pragma command for opening the specified section */
#pragma SET_DATA_SECTION(".ossDataAp_9:init")
    #undef START_SEC_VAR_FAST_INIT_8BIT            
    #undef MEMMAP_ERROR
#endif


#ifdef START_SEC_VAR_FAST_INIT_16BIT           
    #define VAR_SEC_OPEN
/* Enter here a #pragma command for opening the specified section */
#pragma SET_DATA_SECTION(".ossDataAp_9:init")
    #undef START_SEC_VAR_FAST_INIT_16BIT           
    #undef MEMMAP_ERROR
#endif


#ifdef START_SEC_VAR_FAST_INIT_32BIT           
    #define VAR_SEC_OPEN
/* Enter here a #pragma command for opening the specified section */
#pragma SET_DATA_SECTION(".ossDataAp_9:init")
    #undef START_SEC_VAR_FAST_INIT_32BIT           
    #undef MEMMAP_ERROR
#endif


#ifdef START_SEC_VAR_FAST_INIT_UNSPECIFIED     
    #define VAR_SEC_OPEN
/* Enter here a #pragma command for opening the specified section */
#pragma SET_DATA_SECTION(".ossDataAp_9:init")
    #undef START_SEC_VAR_FAST_INIT_UNSPECIFIED     
    #undef MEMMAP_ERROR
#endif


#ifdef START_SEC_VAR_FAST_NOINIT_8BIT          
    #define VAR_SEC_OPEN
/* Enter here a #pragma command for opening the specified section */
#pragma SET_DATA_SECTION(".ossDataAp_9:noinit")
    #undef START_SEC_VAR_FAST_NOINIT_8BIT          
    #undef MEMMAP_ERROR
#endif


#ifdef START_SEC_VAR_FAST_NOINIT_16BIT         
    #define VAR_SEC_OPEN
/* Enter here a #pragma command for opening the specified section */
#pragma SET_DATA_SECTION(".ossDataAp_9:noinit")
    #undef START_SEC_VAR_FAST_NOINIT_16BIT         
    #undef MEMMAP_ERROR
#endif


#ifdef START_SEC_VAR_FAST_NOINIT_32BIT         
    #define VAR_SEC_OPEN
/* Enter here a #pragma command for opening the specified section */
#pragma SET_DATA_SECTION(".ossDataAp_9:noinit")
    #undef START_SEC_VAR_FAST_NOINIT_32BIT         
    #undef MEMMAP_ERROR
#endif


#ifdef START_SEC_VAR_FAST_NOINIT_UNSPECIFIED   
    #define VAR_SEC_OPEN
/* Enter here a #pragma command for opening the specified section */
#pragma SET_DATA_SECTION(".ossDataAp_9:noinit")
    #undef START_SEC_VAR_FAST_NOINIT_UNSPECIFIED   
    #undef MEMMAP_ERROR
#endif


#ifdef START_SEC_VAR_FAST_ZERO_INIT_8BIT       
    #define VAR_SEC_OPEN
/* Enter here a #pragma command for opening the specified section */
#pragma SET_DATA_SECTION(".ossDataAp_9:init")
    #undef START_SEC_VAR_FAST_ZERO_INIT_8BIT       
    #undef MEMMAP_ERROR
#endif


#ifdef START_SEC_VAR_FAST_ZERO_INIT_16BIT      
    #define VAR_SEC_OPEN
/* Enter here a #pragma command for opening the specified section */
#pragma SET_DATA_SECTION(".ossDataAp_9:init")
    #undef START_SEC_VAR_FAST_ZERO_INIT_16BIT      
    #undef MEMMAP_ERROR
#endif


#ifdef START_SEC_VAR_FAST_ZERO_INIT_32BIT      
    #define VAR_SEC_OPEN
/* Enter here a #pragma command for opening the specified section */
#pragma SET_DATA_SECTION(".ossDataAp_9:init")
    #undef START_SEC_VAR_FAST_ZERO_INIT_32BIT      
    #undef MEMMAP_ERROR
#endif


#ifdef START_SEC_VAR_FAST_ZERO_INIT_UNSPECIFIED
    #define VAR_SEC_OPEN
/* Enter here a #pragma command for opening the specified section */
#pragma SET_DATA_SECTION(".ossDataAp_9:init")
    #undef START_SEC_VAR_FAST_ZERO_INIT_UNSPECIFIED
    #undef MEMMAP_ERROR
#endif

/************************************** Global Shared Variable Sections (AUTOSAR 4.0) *******************************/

#ifdef START_SEC_VAR_INIT_8_GLOBALSHARED        
    #define VAR_SEC_OPEN
/* Enter here a #pragma command for opening the specified section */
#pragma SET_DATA_SECTION(".ossGlobalShared:init")

    #undef START_SEC_VAR_INIT_8_GLOBALSHARED      
    #undef MEMMAP_ERROR
#endif

#ifdef START_SEC_VAR_INIT_16_GLOBALSHARED        
    #define VAR_SEC_OPEN
/* Enter here a #pragma command for opening the specified section */
#pragma SET_DATA_SECTION(".ossGlobalShared:init")

    #undef START_SEC_VAR_INIT_16_GLOBALSHARED      
    #undef MEMMAP_ERROR
#endif

#ifdef START_SEC_VAR_INIT_32_GLOBALSHARED        
    #define VAR_SEC_OPEN
/* Enter here a #pragma command for opening the specified section */
#pragma SET_DATA_SECTION(".ossGlobalShared:init")

    #undef START_SEC_VAR_INIT_32_GLOBALSHARED        
    #undef MEMMAP_ERROR
#endif

#ifdef START_SEC_VAR_INIT_32_GLOBALSHARED
    #define VAR_SEC_OPEN
/* Enter here a #pragma command for opening the specified section */
#pragma SET_DATA_SECTION(".ossGlobalShared:init")

    #undef START_SEC_VAR_INIT_32_GLOBALSHARED
    #undef MEMMAP_ERROR
#endif

#ifdef START_SEC_VAR_INIT_BOOLEAN_GLOBALSHARED
    #define VAR_SEC_OPEN
/* Enter here a #pragma command for opening the specified section */
#pragma SET_DATA_SECTION(".ossGlobalShared:init")

    #undef START_SEC_VAR_INIT_BOOLEAN_GLOBALSHARED
    #undef MEMMAP_ERROR
#endif

#ifdef START_SEC_VAR_INIT_UNSPECIFIED_GLOBALSHARED
    #define VAR_SEC_OPEN
/* Enter here a #pragma command for opening the specified section */
#pragma SET_DATA_SECTION(".ossGlobalShared:init")

    #undef START_SEC_VAR_INIT_UNSPECIFIED_GLOBALSHARED
    #undef MEMMAP_ERROR
#endif

#ifdef START_SEC_VAR_NOINIT_8_GLOBALSHARED        
    #define VAR_SEC_OPEN
/* Enter here a #pragma command for opening the specified section */
#pragma SET_DATA_SECTION(".ossGlobalShared:noinit")

    #undef START_SEC_VAR_NOINIT_8_GLOBALSHARED      
    #undef MEMMAP_ERROR
#endif

#ifdef START_SEC_VAR_NOINIT_16_GLOBALSHARED        
    #define VAR_SEC_OPEN
/* Enter here a #pragma command for opening the specified section */
#pragma SET_DATA_SECTION(".ossGlobalShared:noinit")

    #undef START_SEC_VAR_NOINIT_16_GLOBALSHARED      
    #undef MEMMAP_ERROR
#endif

#ifdef START_SEC_VAR_NOINIT_32_GLOBALSHARED        
    #define VAR_SEC_OPEN
/* Enter here a #pragma command for opening the specified section */
#pragma SET_DATA_SECTION(".ossGlobalShared:noinit")

    #undef START_SEC_VAR_NOINIT_32_GLOBALSHARED        
    #undef MEMMAP_ERROR
#endif

#ifdef START_SEC_VAR_NOINIT_32_GLOBALSHARED
    #define VAR_SEC_OPEN
/* Enter here a #pragma command for opening the specified section */
#pragma SET_DATA_SECTION(".ossGlobalShared:noinit")

    #undef START_SEC_VAR_NOINIT_32_GLOBALSHARED
    #undef MEMMAP_ERROR
#endif

#ifdef START_SEC_VAR_NOINIT_BOOLEAN_GLOBALSHARED
    #define VAR_SEC_OPEN
/* Enter here a #pragma command for opening the specified section */
#pragma SET_DATA_SECTION(".ossGlobalShared:noinit")

    #undef START_SEC_VAR_NOINIT_BOOLEAN_GLOBALSHARED
    #undef MEMMAP_ERROR
#endif

#ifdef START_SEC_VAR_NOINIT_UNSPECIFIED_GLOBALSHARED
    #define VAR_SEC_OPEN
/* Enter here a #pragma command for opening the specified section */
#pragma SET_DATA_SECTION(".ossGlobalShared:noinit")

    #undef START_SEC_VAR_NOINIT_UNSPECIFIED_GLOBALSHARED
    #undef MEMMAP_ERROR
#endif

#ifdef START_SEC_VAR_CLEARED_8_GLOBALSHARED        
    #define VAR_SEC_OPEN
/* Enter here a #pragma command for opening the specified section */
#pragma SET_DATA_SECTION(".ossGlobalShared")

    #undef START_SEC_VAR_CLEARED_8_GLOBALSHARED      
    #undef MEMMAP_ERROR
#endif

#ifdef START_SEC_VAR_CLEARED_16_GLOBALSHARED        
    #define VAR_SEC_OPEN
/* Enter here a #pragma command for opening the specified section */
#pragma SET_DATA_SECTION(".ossGlobalShared")

    #undef START_SEC_VAR_CLEARED_16_GLOBALSHARED      
    #undef MEMMAP_ERROR
#endif

#ifdef START_SEC_VAR_CLEARED_32_GLOBALSHARED        
    #define VAR_SEC_OPEN
/* Enter here a #pragma command for opening the specified section */
#pragma SET_DATA_SECTION(".ossGlobalShared")

    #undef START_SEC_VAR_CLEARED_32_GLOBALSHARED        
    #undef MEMMAP_ERROR
#endif

#ifdef START_SEC_VAR_CLEARED_32_GLOBALSHARED
    #define VAR_SEC_OPEN
/* Enter here a #pragma command for opening the specified section */
#pragma SET_DATA_SECTION(".ossGlobalShared")

    #undef START_SEC_VAR_CLEARED_32_GLOBALSHARED
    #undef MEMMAP_ERROR
#endif

#ifdef START_SEC_VAR_CLEARED_BOOLEAN_GLOBALSHARED
    #define VAR_SEC_OPEN
/* Enter here a #pragma command for opening the specified section */
#pragma SET_DATA_SECTION(".ossGlobalShared")

    #undef START_SEC_VAR_CLEARED_BOOLEAN_GLOBALSHARED
    #undef MEMMAP_ERROR
#endif

#ifdef START_SEC_VAR_CLEARED_UNSPECIFIED_GLOBALSHARED
    #define VAR_SEC_OPEN
/* Enter here a #pragma command for opening the specified section */
#pragma SET_DATA_SECTION(".ossGlobalShared")

    #undef START_SEC_VAR_CLEARED_UNSPECIFIED_GLOBALSHARED
    #undef MEMMAP_ERROR
#endif

/************************************** Application #0 Variable Sections ***************************************/
 /* Initialized Memory */
#ifdef START_SEC_VAR_INIT_8_0
    #define VAR_SEC_OPEN
/* Enter here a #pragma command for opening the specified section */
#pragma SET_DATA_SECTION(".ossDataAp_0:init")

    #undef START_SEC_VAR_INIT_8_0
    #undef MEMMAP_ERROR
#endif

#ifdef START_SEC_VAR_INIT_16_0
    #define VAR_SEC_OPEN
/* Enter here a #pragma command for opening the specified section */
#pragma SET_DATA_SECTION(".ossDataAp_0:init")

    #undef START_SEC_VAR_INIT_16_0
    #undef MEMMAP_ERROR
#endif

#ifdef START_SEC_VAR_INIT_32_0
    #define VAR_SEC_OPEN
/* Enter here a #pragma command for opening the specified section */
#pragma SET_DATA_SECTION(".ossDataAp_0:init")

    #undef START_SEC_VAR_INIT_32_0
    #undef MEMMAP_ERROR
#endif

#ifdef START_SEC_VAR_INIT_BOOLEAN_0
    #define VAR_SEC_OPEN
/* Enter here a #pragma command for opening the specified section */
#pragma SET_DATA_SECTION(".ossDataAp_0:init")

    #undef START_SEC_VAR_INIT_BOOLEAN_0
    #undef MEMMAP_ERROR
#endif

#ifdef START_SEC_VAR_INIT_UNSPECIFIED_0
    #define VAR_SEC_OPEN
/* Enter here a #pragma command for opening the specified section */
#pragma SET_DATA_SECTION(".ossDataAp_0:init")

    #undef START_SEC_VAR_INIT_UNSPECIFIED_0
    #undef MEMMAP_ERROR
#endif

#ifdef START_SEC_VAR_POWER_ON_CLEARED_8_0
    #define VAR_SEC_OPEN
/* Enter here a #pragma command for opening the specified section */
#pragma SET_DATA_SECTION(".noclear")

    #undef START_SEC_VAR_POWER_ON_CLEARED_8_0
    #undef MEMMAP_ERROR
#endif

 /* Uninitialized Memory */
 #ifdef START_SEC_VAR_CLEARED_8_0
    #define VAR_SEC_OPEN
/* Enter here a #pragma command for opening the specified section */
#pragma SET_DATA_SECTION(".ossDataAp_0:noinit")

    #undef START_SEC_VAR_CLEARED_8_0
    #undef MEMMAP_ERROR
#endif

#ifdef START_SEC_VAR_CLEARED_16_0
    #define VAR_SEC_OPEN
/* Enter here a #pragma command for opening the specified section */
#pragma SET_DATA_SECTION(".ossDataAp_0:noinit")

    #undef START_SEC_VAR_CLEARED_16_0
    #undef MEMMAP_ERROR
#endif

#ifdef START_SEC_VAR_CLEARED_32_0
    #define VAR_SEC_OPEN
/* Enter here a #pragma command for opening the specified section */
#pragma SET_DATA_SECTION(".ossDataAp_0:noinit")

    #undef START_SEC_VAR_CLEARED_32_0
    #undef MEMMAP_ERROR
#endif

#ifdef START_SEC_VAR_CLEARED_BOOLEAN_0
    #define VAR_SEC_OPEN
/* Enter here a #pragma command for opening the specified section */
#pragma SET_DATA_SECTION(".ossDataAp_0:noinit")

    #undef START_SEC_VAR_CLEARED_BOOLEAN_0
    #undef MEMMAP_ERROR
#endif

#ifdef START_SEC_VAR_CLEARED_UNSPECIFIED_0
    #define VAR_SEC_OPEN
/* Enter here a #pragma command for opening the specified section */
#pragma SET_DATA_SECTION(".ossDataAp_0:noinit")

    #undef START_SEC_VAR_CLEARED_UNSPECIFIED_0
    #undef MEMMAP_ERROR
#endif

#ifdef START_SEC_VAR_NOINIT_8_0
    #define VAR_SEC_OPEN
/* Enter here a #pragma command for opening the specified section */
#pragma SET_DATA_SECTION(".ossDataAp_0:noinit")

    #undef START_SEC_VAR_NOINIT_8_0
    #undef MEMMAP_ERROR
#endif

#ifdef START_SEC_VAR_NOINIT_16_0
    #define VAR_SEC_OPEN
/* Enter here a #pragma command for opening the specified section */
#pragma SET_DATA_SECTION(".ossDataAp_0:noinit")

    #undef START_SEC_VAR_NOINIT_16_0
    #undef MEMMAP_ERROR
#endif

#ifdef START_SEC_VAR_NOINIT_32_0
    #define VAR_SEC_OPEN
/* Enter here a #pragma command for opening the specified section */
#pragma SET_DATA_SECTION(".ossDataAp_0:noinit")

    #undef START_SEC_VAR_NOINIT_32_0
    #undef MEMMAP_ERROR
#endif

#ifdef START_SEC_VAR_NOINIT_BOOLEAN_0
    #define VAR_SEC_OPEN
/* Enter here a #pragma command for opening the specified section */
#pragma SET_DATA_SECTION(".ossDataAp_0:noinit")

    #undef START_SEC_VAR_NOINIT_BOOLEAN_0
    #undef MEMMAP_ERROR
#endif

#ifdef START_SEC_VAR_NOINIT_UNSPECIFIED_0
    #define VAR_SEC_OPEN
/* Enter here a #pragma command for opening the specified section */
#pragma SET_DATA_SECTION(".ossDataAp_0:noinit")

    #undef START_SEC_VAR_NOINIT_UNSPECIFIED_0
    #undef MEMMAP_ERROR
#endif

/************************************** Application #8 Variable Sections ***************************************/
 /* Initialized Memory */
#ifdef START_SEC_VAR_INIT_8_8
    #define VAR_SEC_OPEN
/* Enter here a #pragma command for opening the specified section */
#pragma SET_DATA_SECTION(".ossDataAp_8:init")

    #undef START_SEC_VAR_INIT_8_8
    #undef MEMMAP_ERROR
#endif

#ifdef START_SEC_VAR_INIT_16_8
    #define VAR_SEC_OPEN
/* Enter here a #pragma command for opening the specified section */
#pragma SET_DATA_SECTION(".ossDataAp_8:init")

    #undef START_SEC_VAR_INIT_16_8
    #undef MEMMAP_ERROR
#endif

#ifdef START_SEC_VAR_INIT_32_8
    #define VAR_SEC_OPEN
/* Enter here a #pragma command for opening the specified section */
#pragma SET_DATA_SECTION(".ossDataAp_8:init")

    #undef START_SEC_VAR_INIT_32_8
    #undef MEMMAP_ERROR
#endif

#ifdef START_SEC_VAR_INIT_BOOLEAN_8
    #define VAR_SEC_OPEN
/* Enter here a #pragma command for opening the specified section */
#pragma SET_DATA_SECTION(".ossDataAp_8:init")

    #undef START_SEC_VAR_INIT_BOOLEAN_8
    #undef MEMMAP_ERROR
#endif

#ifdef START_SEC_VAR_INIT_UNSPECIFIED_8
    #define VAR_SEC_OPEN
/* Enter here a #pragma command for opening the specified section */
#pragma SET_DATA_SECTION(".ossDataAp_8:init")

    #undef START_SEC_VAR_INIT_UNSPECIFIED_8
    #undef MEMMAP_ERROR
#endif

 /* Uninitialized Memory */
 #ifdef START_SEC_VAR_CLEARED_8_8
    #define VAR_SEC_OPEN
/* Enter here a #pragma command for opening the specified section */
#pragma SET_DATA_SECTION(".ossDataAp_8:noinit")

    #undef START_SEC_VAR_CLEARED_8_8
    #undef MEMMAP_ERROR
#endif

#ifdef START_SEC_VAR_CLEARED_16_8
    #define VAR_SEC_OPEN
/* Enter here a #pragma command for opening the specified section */
#pragma SET_DATA_SECTION(".ossDataAp_8:noinit")

    #undef START_SEC_VAR_CLEARED_16_8
    #undef MEMMAP_ERROR
#endif

#ifdef START_SEC_VAR_CLEARED_32_8
    #define VAR_SEC_OPEN
/* Enter here a #pragma command for opening the specified section */
#pragma SET_DATA_SECTION(".ossDataAp_8:noinit")

    #undef START_SEC_VAR_CLEARED_32_8
    #undef MEMMAP_ERROR
#endif

#ifdef START_SEC_VAR_CLEARED_BOOLEAN_8
    #define VAR_SEC_OPEN
/* Enter here a #pragma command for opening the specified section */
#pragma SET_DATA_SECTION(".ossDataAp_8:noinit")

    #undef START_SEC_VAR_CLEARED_BOOLEAN_8
    #undef MEMMAP_ERROR
#endif

#ifdef START_SEC_VAR_CLEARED_UNSPECIFIED_8
    #define VAR_SEC_OPEN
/* Enter here a #pragma command for opening the specified section */
#pragma SET_DATA_SECTION(".ossDataAp_8:noinit")

    #undef START_SEC_VAR_CLEARED_UNSPECIFIED_8
    #undef MEMMAP_ERROR
#endif

#ifdef START_SEC_VAR_NOINIT_8_8
    #define VAR_SEC_OPEN
/* Enter here a #pragma command for opening the specified section */
#pragma SET_DATA_SECTION(".ossDataAp_8:noinit")

    #undef START_SEC_VAR_NOINIT_8_8
    #undef MEMMAP_ERROR
#endif

#ifdef START_SEC_VAR_NOINIT_16_8
    #define VAR_SEC_OPEN
/* Enter here a #pragma command for opening the specified section */
#pragma SET_DATA_SECTION(".ossDataAp_8:noinit")

    #undef START_SEC_VAR_NOINIT_16_8
    #undef MEMMAP_ERROR
#endif

#ifdef START_SEC_VAR_NOINIT_32_8
    #define VAR_SEC_OPEN
/* Enter here a #pragma command for opening the specified section */
#pragma SET_DATA_SECTION(".ossDataAp_8:noinit")

    #undef START_SEC_VAR_NOINIT_32_8
    #undef MEMMAP_ERROR
#endif

#ifdef START_SEC_VAR_NOINIT_BOOLEAN_8
    #define VAR_SEC_OPEN
/* Enter here a #pragma command for opening the specified section */
#pragma SET_DATA_SECTION(".ossDataAp_8:noinit")

    #undef START_SEC_VAR_NOINIT_BOOLEAN_8
    #undef MEMMAP_ERROR
#endif

#ifdef START_SEC_VAR_NOINIT_UNSPECIFIED_8
    #define VAR_SEC_OPEN
/* Enter here a #pragma command for opening the specified section */
#pragma SET_DATA_SECTION(".ossDataAp_8:noinit")

    #undef START_SEC_VAR_NOINIT_UNSPECIFIED_8
    #undef MEMMAP_ERROR
#endif

/************************************** Application #8 Constant Sections ***************************************/
/* Const section */
#ifdef START_SEC_CONST_8_8
    #define CONST_SEC_OPEN
/* Enter here a #pragma command for opening the specified section, otherwise default allocation is used */
    #undef START_SEC_CONST_8_8
    #undef MEMMAP_ERROR
#endif

#ifdef START_SEC_CONST_16_8
    #define CONST_SEC_OPEN
/* Enter here a #pragma command for opening the specified section, otherwise default allocation is used */
    #undef START_SEC_CONST_16_8
    #undef MEMMAP_ERROR
#endif

#ifdef START_SEC_CONST_32_8
    #define CONST_SEC_OPEN
/* Enter here a #pragma command for opening the specified section, otherwise default allocation is used */
    #undef START_SEC_CONST_32_8
    #undef MEMMAP_ERROR
#endif

#ifdef START_SEC_CONST_UNSPECIFIED_8
    #define CONST_SEC_OPEN
/* Enter here a #pragma command for opening the specified section, otherwise default allocation is used */
    #undef START_SEC_CONST_UNSPECIFIED_8
    #undef MEMMAP_ERROR
#endif

#ifdef START_SEC_CONST_FAST_UNSPECIFIED_8
    #define CONST_SEC_OPEN
/* Enter here a #pragma command for opening the specified section, otherwise default allocation is used */
    #undef START_SEC_CONST_FAST_UNSPECIFIED_8
    #undef MEMMAP_ERROR
#endif

#ifdef START_SEC_CONST_PBCFG_8
    #define CONST_SEC_OPEN
/* Enter here a #pragma command for opening the specified section, otherwise default allocation is used */
    #undef START_SEC_CONST_PBCFG_8
    #undef MEMMAP_ERROR
#endif

/************************************** Application #9 Variable Sections ***************************************/
 /* Initialized Memory */
#ifdef START_SEC_VAR_INIT_8_9
    #define VAR_SEC_OPEN
/* Enter here a #pragma command for opening the specified section */
#pragma SET_DATA_SECTION(".ossDataAp_9:init")

    #undef START_SEC_VAR_INIT_8_9
    #undef MEMMAP_ERROR
#endif

#ifdef START_SEC_VAR_INIT_16_9
    #define VAR_SEC_OPEN
/* Enter here a #pragma command for opening the specified section */
#pragma SET_DATA_SECTION(".ossDataAp_9:init")

    #undef START_SEC_VAR_INIT_16_9
    #undef MEMMAP_ERROR
#endif

#ifdef START_SEC_VAR_INIT_32_9
    #define VAR_SEC_OPEN
/* Enter here a #pragma command for opening the specified section */
#pragma SET_DATA_SECTION(".ossDataAp_9:init")

    #undef START_SEC_VAR_INIT_32_9
    #undef MEMMAP_ERROR
#endif

#ifdef START_SEC_VAR_INIT_BOOLEAN_9
    #define VAR_SEC_OPEN
/* Enter here a #pragma command for opening the specified section */
#pragma SET_DATA_SECTION(".ossDataAp_9:init")

    #undef START_SEC_VAR_INIT_BOOLEAN_9
    #undef MEMMAP_ERROR
#endif

#ifdef START_SEC_VAR_INIT_UNSPECIFIED_9
    #define VAR_SEC_OPEN
/* Enter here a #pragma command for opening the specified section */
#pragma SET_DATA_SECTION(".ossDataAp_9:init")

    #undef START_SEC_VAR_INIT_UNSPECIFIED_9
    #undef MEMMAP_ERROR
#endif

 /* Uninitialized Memory */
 #ifdef START_SEC_VAR_CLEARED_8_9
    #define VAR_SEC_OPEN
/* Enter here a #pragma command for opening the specified section */
#pragma SET_DATA_SECTION(".ossDataAp_9:noinit")

    #undef START_SEC_VAR_CLEARED_8_9
    #undef MEMMAP_ERROR
#endif

#ifdef START_SEC_VAR_CLEARED_16_9
    #define VAR_SEC_OPEN
/* Enter here a #pragma command for opening the specified section */
#pragma SET_DATA_SECTION(".ossDataAp_9:noinit")

    #undef START_SEC_VAR_CLEARED_16_9
    #undef MEMMAP_ERROR
#endif

#ifdef START_SEC_VAR_CLEARED_32_9
    #define VAR_SEC_OPEN
/* Enter here a #pragma command for opening the specified section */
#pragma SET_DATA_SECTION(".ossDataAp_9:noinit")

    #undef START_SEC_VAR_CLEARED_32_9
    #undef MEMMAP_ERROR
#endif

#ifdef START_SEC_VAR_CLEARED_BOOLEAN_9
    #define VAR_SEC_OPEN
/* Enter here a #pragma command for opening the specified section */
#pragma SET_DATA_SECTION(".ossDataAp_9:noinit")

    #undef START_SEC_VAR_CLEARED_BOOLEAN_9
    #undef MEMMAP_ERROR
#endif

#ifdef START_SEC_VAR_CLEARED_UNSPECIFIED_9
    #define VAR_SEC_OPEN
/* Enter here a #pragma command for opening the specified section */
#pragma SET_DATA_SECTION(".ossDataAp_9:noinit")

    #undef START_SEC_VAR_CLEARED_UNSPECIFIED_9
    #undef MEMMAP_ERROR
#endif

#ifdef START_SEC_VAR_NOINIT_8_9
    #define VAR_SEC_OPEN
/* Enter here a #pragma command for opening the specified section */
#pragma SET_DATA_SECTION(".ossDataAp_9:noinit")

    #undef START_SEC_VAR_NOINIT_8_9
    #undef MEMMAP_ERROR
#endif

#ifdef START_SEC_VAR_NOINIT_16_9
    #define VAR_SEC_OPEN
/* Enter here a #pragma command for opening the specified section */
#pragma SET_DATA_SECTION(".ossDataAp_9:noinit")

    #undef START_SEC_VAR_NOINIT_16_9
    #undef MEMMAP_ERROR
#endif

#ifdef START_SEC_VAR_NOINIT_32_9
    #define VAR_SEC_OPEN
/* Enter here a #pragma command for opening the specified section */
#pragma SET_DATA_SECTION(".ossDataAp_9:noinit")

    #undef START_SEC_VAR_NOINIT_32_9
    #undef MEMMAP_ERROR
#endif

#ifdef START_SEC_VAR_NOINIT_BOOLEAN_9
    #define VAR_SEC_OPEN
/* Enter here a #pragma command for opening the specified section */
#pragma SET_DATA_SECTION(".ossDataAp_9:noinit")

    #undef START_SEC_VAR_NOINIT_BOOLEAN_9
    #undef MEMMAP_ERROR
#endif

#ifdef START_SEC_VAR_NOINIT_UNSPECIFIED_9
    #define VAR_SEC_OPEN
/* Enter here a #pragma command for opening the specified section */
#pragma SET_DATA_SECTION(".ossDataAp_9:noinit")

    #undef START_SEC_VAR_NOINIT_UNSPECIFIED_9
    #undef MEMMAP_ERROR
#endif

/************************************** Application #9 Constant Sections ***************************************/
/* Const section */
#ifdef START_SEC_CONST_8_9
    #define CONST_SEC_OPEN
/* Enter here a #pragma command for opening the specified section, otherwise default allocation is used */
    #undef START_SEC_CONST_8_9
    #undef MEMMAP_ERROR
#endif

#ifdef START_SEC_CONST_16_9
    #define CONST_SEC_OPEN
/* Enter here a #pragma command for opening the specified section, otherwise default allocation is used */
    #undef START_SEC_CONST_16_9
    #undef MEMMAP_ERROR
#endif

#ifdef START_SEC_CONST_32_9
    #define CONST_SEC_OPEN
/* Enter here a #pragma command for opening the specified section, otherwise default allocation is used */
    #undef START_SEC_CONST_32_9
    #undef MEMMAP_ERROR
#endif

#ifdef START_SEC_CONST_UNSPECIFIED_9
    #define CONST_SEC_OPEN
/* Enter here a #pragma command for opening the specified section, otherwise default allocation is used */
    #undef START_SEC_CONST_UNSPECIFIED_9
    #undef MEMMAP_ERROR
#endif

#ifdef START_SEC_CONST_FAST_UNSPECIFIED_9
    #define CONST_SEC_OPEN
/* Enter here a #pragma command for opening the specified section, otherwise default allocation is used */
    #undef START_SEC_CONST_FAST_UNSPECIFIED_9
    #undef MEMMAP_ERROR
#endif

#ifdef START_SEC_CONST_PBCFG_9
    #define CONST_SEC_OPEN
/* Enter here a #pragma command for opening the specified section, otherwise default allocation is used */
    #undef START_SEC_CONST_PBCFG_9
    #undef MEMMAP_ERROR
#endif

/************************************** Application #10 Variable Sections ***************************************/
 /* Initialized Memory */
#ifdef START_SEC_VAR_INIT_8_10
    #define VAR_SEC_OPEN
/* Enter here a #pragma command for opening the specified section */
#pragma SET_DATA_SECTION(".ossDataAp_10:init")

    #undef START_SEC_VAR_INIT_8_10
    #undef MEMMAP_ERROR
#endif

#ifdef START_SEC_VAR_INIT_16_10
    #define VAR_SEC_OPEN
/* Enter here a #pragma command for opening the specified section */
#pragma SET_DATA_SECTION(".ossDataAp_10:init")

    #undef START_SEC_VAR_INIT_16_10
    #undef MEMMAP_ERROR
#endif

#ifdef START_SEC_VAR_INIT_32_10
    #define VAR_SEC_OPEN
/* Enter here a #pragma command for opening the specified section */
#pragma SET_DATA_SECTION(".ossDataAp_10:init")

    #undef START_SEC_VAR_INIT_32_10
    #undef MEMMAP_ERROR
#endif

#ifdef START_SEC_VAR_INIT_BOOLEAN_10
    #define VAR_SEC_OPEN
/* Enter here a #pragma command for opening the specified section */
#pragma SET_DATA_SECTION(".ossDataAp_10:init")

    #undef START_SEC_VAR_INIT_BOOLEAN_10
    #undef MEMMAP_ERROR
#endif

#ifdef START_SEC_VAR_INIT_UNSPECIFIED_10
    #define VAR_SEC_OPEN
/* Enter here a #pragma command for opening the specified section */
#pragma SET_DATA_SECTION(".ossDataAp_10:init")

    #undef START_SEC_VAR_INIT_UNSPECIFIED_10
    #undef MEMMAP_ERROR
#endif

 /* Uninitialized Memory */
#ifdef START_SEC_VAR_POWER_ON_CLEARED_8_10
    #define VAR_SEC_OPEN
/* Enter here a #pragma command for opening the specified section */
#pragma SET_DATA_SECTION(".noclear")

    #undef START_SEC_VAR_POWER_ON_CLEARED_8_10
    #undef MEMMAP_ERROR
#endif

#ifdef START_SEC_VAR_CLEARED_8_10
    #define VAR_SEC_OPEN
/* Enter here a #pragma command for opening the specified section */
#pragma SET_DATA_SECTION(".ossDataAp_10:noinit")

    #undef START_SEC_VAR_CLEARED_8_10
    #undef MEMMAP_ERROR
#endif

#ifdef START_SEC_VAR_CLEARED_16_10
    #define VAR_SEC_OPEN
/* Enter here a #pragma command for opening the specified section */
#pragma SET_DATA_SECTION(".ossDataAp_10:noinit")

    #undef START_SEC_VAR_CLEARED_16_10
    #undef MEMMAP_ERROR
#endif

#ifdef START_SEC_VAR_CLEARED_32_10
    #define VAR_SEC_OPEN
/* Enter here a #pragma command for opening the specified section */
#pragma SET_DATA_SECTION(".ossDataAp_10:noinit")

    #undef START_SEC_VAR_CLEARED_32_10
    #undef MEMMAP_ERROR
#endif

#ifdef START_SEC_VAR_CLEARED_BOOLEAN_10
    #define VAR_SEC_OPEN
/* Enter here a #pragma command for opening the specified section */
#pragma SET_DATA_SECTION(".ossDataAp_10:noinit")

    #undef START_SEC_VAR_CLEARED_BOOLEAN_10
    #undef MEMMAP_ERROR
#endif

#ifdef START_SEC_VAR_CLEARED_UNSPECIFIED_10
    #define VAR_SEC_OPEN
/* Enter here a #pragma command for opening the specified section */
#pragma SET_DATA_SECTION(".ossDataAp_10:noinit")

    #undef START_SEC_VAR_CLEARED_UNSPECIFIED_10
    #undef MEMMAP_ERROR
#endif

#ifdef START_SEC_VAR_NOINIT_8_10
    #define VAR_SEC_OPEN
/* Enter here a #pragma command for opening the specified section */
#pragma SET_DATA_SECTION(".ossDataAp_10:noinit")

    #undef START_SEC_VAR_NOINIT_8_10
    #undef MEMMAP_ERROR
#endif

#ifdef START_SEC_VAR_NOINIT_16_10
    #define VAR_SEC_OPEN
/* Enter here a #pragma command for opening the specified section */
#pragma SET_DATA_SECTION(".ossDataAp_10:noinit")

    #undef START_SEC_VAR_NOINIT_16_10
    #undef MEMMAP_ERROR
#endif

#ifdef START_SEC_VAR_NOINIT_32_10
    #define VAR_SEC_OPEN
/* Enter here a #pragma command for opening the specified section */
#pragma SET_DATA_SECTION(".ossDataAp_10:noinit")

    #undef START_SEC_VAR_NOINIT_32_10
    #undef MEMMAP_ERROR
#endif

#ifdef START_SEC_VAR_NOINIT_BOOLEAN_10
    #define VAR_SEC_OPEN
/* Enter here a #pragma command for opening the specified section */
#pragma SET_DATA_SECTION(".ossDataAp_10:noinit")

    #undef START_SEC_VAR_NOINIT_BOOLEAN_10
    #undef MEMMAP_ERROR
#endif

#ifdef START_SEC_VAR_NOINIT_UNSPECIFIED_10
    #define VAR_SEC_OPEN
/* Enter here a #pragma command for opening the specified section */
#pragma SET_DATA_SECTION(".ossDataAp_10:noinit")

    #undef START_SEC_VAR_NOINIT_UNSPECIFIED_10
    #undef MEMMAP_ERROR
#endif

/************************************** Application #10 Constant Sections ***************************************/
/* Const section */
#ifdef START_SEC_CONST_8_10
    #define CONST_SEC_OPEN
/* Enter here a #pragma command for opening the specified section, otherwise default allocation is used */
    #undef START_SEC_CONST_8_10
    #undef MEMMAP_ERROR
#endif

#ifdef START_SEC_CONST_16_10
    #define CONST_SEC_OPEN
/* Enter here a #pragma command for opening the specified section, otherwise default allocation is used */
    #undef START_SEC_CONST_16_10
    #undef MEMMAP_ERROR
#endif

#ifdef START_SEC_CONST_32_10
    #define CONST_SEC_OPEN
/* Enter here a #pragma command for opening the specified section, otherwise default allocation is used */
    #undef START_SEC_CONST_32_10
    #undef MEMMAP_ERROR
#endif

#ifdef START_SEC_CONST_UNSPECIFIED_10
    #define CONST_SEC_OPEN
/* Enter here a #pragma command for opening the specified section, otherwise default allocation is used */
    #undef START_SEC_CONST_UNSPECIFIED_10
    #undef MEMMAP_ERROR
#endif

#ifdef START_SEC_CONST_FAST_UNSPECIFIED_10
    #define CONST_SEC_OPEN
/* Enter here a #pragma command for opening the specified section, otherwise default allocation is used */
    #undef START_SEC_CONST_FAST_UNSPECIFIED_10
    #undef MEMMAP_ERROR
#endif

#ifdef START_SEC_CONST_PBCFG_10
    #define CONST_SEC_OPEN
/* Enter here a #pragma command for opening the specified section, otherwise default allocation is used */
    #undef START_SEC_CONST_PBCFG_10
    #undef MEMMAP_ERROR
#endif
/*------------------------------GENERAL-STOP-SECTIONS-------------------------------*/

/*default segment for Code*/
#ifdef STOP_SEC_CODE
    #undef CODE_SEC_OPEN
	#pragma SET_CODE_SECTION()
    #undef STOP_SEC_CODE
    #undef MEMMAP_ERROR
#endif

/*default segment for Constants*/
#ifdef STOP_SEC_CONST_UNSPECIFIED
    #undef CONST_SEC_OPEN
	#pragma SET_DATA_SECTION()
    #undef STOP_SEC_CONST_UNSPECIFIED
    #undef MEMMAP_ERROR
#endif

/*default segment for Constants*/
#ifdef STOP_SEC_CONST
    #undef CONST_SEC_OPEN
	#pragma SET_DATA_SECTION()
    #undef STOP_SEC_CONST
    #undef MEMMAP_ERROR
#endif

/*default segment for Datas*/
#ifdef STOP_SEC_VAR
    #undef VAR_SEC_OPEN
	#pragma SET_DATA_SECTION()
    #undef STOP_SEC_VAR
    #undef MEMMAP_ERROR
#endif


#ifdef MEMMAP_ERROR
    #error "MemMap.h, wrong pragma command"
#endif

/**********************************************************************************************************************
 *  GLOBAL FUNCTION MACROS
 *********************************************************************************************************************/


/**********************************************************************************************************************
 *  GLOBAL DATA TYPES AND STRUCTURES
 *********************************************************************************************************************/


/**********************************************************************************************************************
 *  GLOBAL DATA PROTOTYPES
 *********************************************************************************************************************/


/**********************************************************************************************************************
 *  GLOBAL FUNCTION PROTOTYPES
 *********************************************************************************************************************/


/**********************************************************************************************************************
 *  END OF FILE: MemMap.h
 *********************************************************************************************************************/
/************   Organi, Version 3.9.0 Vector-Informatik GmbH  ************/
/************   Organi, Version 3.9.0 Vector-Informatik GmbH  ************/
