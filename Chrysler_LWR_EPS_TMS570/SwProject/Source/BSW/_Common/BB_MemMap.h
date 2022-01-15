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
 *         File:  BB_MemMap.h
 *    Component:  -
 *       Module:  -
 *    Generator:  -
 *
 *  Description:  This File is a template for the MemMap.h
 *                This file has to be extended with the memory section defines for all BSW modules
 *                which where used.
 *                
 *                This file was modified for use by Ford black box components.  It has deviated from
 *                the original design, but the Vector changelog is left for ease of future updates.
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
 * Date Created:      Tue Apr  3 16:00:00 2012
 * %version:          1 %
 * %derived_by:       nzx5jd %
 * %date_modified:    Tue Apr  3 16:01:00 2012 %
 *---------------------------------------------------------------------------------------------------------------------
 * Date         Rev    Author   Change Description                                                               SCR #
 * ----------   -----  -------  -------------------------------------------------------------------------------  ------
 * 2012-04-03   1      OT       Initial Version                                                                  
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




/**********************************************************************************************************************
 *  BlackBox START
 *********************************************************************************************************************/


/* Code */

#ifdef BLACKBOX_START_SEC_CODE
    #undef BLACKBOX_START_SEC_CODE
    #define START_SEC_CODE
#endif

#ifdef BLACKBOX_STOP_SEC_CODE
    #undef BLACKBOX_STOP_SEC_CODE
    #define STOP_SEC_CODE
#endif



/* Constants */

#ifdef BLACKBOX_START_SEC_CONST_8
    #undef BLACKBOX_START_SEC_CONST_8
    #define START_SEC_CONST_8BIT
#endif
#ifdef BLACKBOX_STOP_SEC_CONST_8
    #undef BLACKBOX_STOP_SEC_CONST_8
    #define STOP_SEC_CONST
#endif

#ifdef BLACKBOX_START_SEC_CONST_16
    #undef BLACKBOX_START_SEC_CONST_16
    #define START_SEC_CONST_16BIT
#endif
#ifdef BLACKBOX_STOP_SEC_CONST_16
    #undef BLACKBOX_STOP_SEC_CONST_16
    #define STOP_SEC_CONST
#endif

#ifdef BLACKBOX_START_SEC_CONST_32
    #undef BLACKBOX_START_SEC_CONST_32
    #define START_SEC_CONST_32BIT
#endif
#ifdef BLACKBOX_STOP_SEC_CONST_32
    #undef BLACKBOX_STOP_SEC_CONST_32
    #define STOP_SEC_CONST
#endif

#ifdef BLACKBOX_START_SEC_CONST_UNSPECIFIED
    #undef BLACKBOX_START_SEC_CONST_UNSPECIFIED
    #define START_SEC_CONST_UNSPECIFIED
#endif
#ifdef BLACKBOX_STOP_SEC_CONST_UNSPECIFIED
    #undef BLACKBOX_STOP_SEC_CONST_UNSPECIFIED
    #define STOP_SEC_CONST
#endif



/* Variables */

#ifdef BLACKBOX_START_SEC_VAR_CLEARED_8
    #undef BLACKBOX_START_SEC_VAR_CLEARED_8
    #define START_SEC_VAR_ZERO_INIT_8BIT
#endif
#ifdef BLACKBOX_STOP_SEC_VAR_CLEARED_8
    #undef BLACKBOX_STOP_SEC_VAR_CLEARED_8
    #define STOP_SEC_VAR
#endif

#ifdef BLACKBOX_START_SEC_VAR_CLEARED_16
    #undef BLACKBOX_START_SEC_VAR_CLEARED_16
    #define START_SEC_VAR_ZERO_INIT_16BIT
#endif
#ifdef BLACKBOX_STOP_SEC_VAR_CLEARED_16
    #undef BLACKBOX_STOP_SEC_VAR_CLEARED_16
    #define STOP_SEC_VAR
#endif

#ifdef BLACKBOX_START_SEC_VAR_CLEARED_32
    #undef BLACKBOX_START_SEC_VAR_CLEARED_32
    #define START_SEC_VAR_ZERO_INIT_32BIT
#endif
#ifdef BLACKBOX_STOP_SEC_VAR_CLEARED_32
    #undef BLACKBOX_STOP_SEC_VAR_CLEARED_32
    #define STOP_SEC_VAR
#endif

#ifdef BLACKBOX_START_SEC_VAR_CLEARED_UNSPECIFIED
    #undef BLACKBOX_START_SEC_VAR_CLEARED_UNSPECIFIED
    #define START_SEC_VAR_ZERO_INIT_UNSPECIFIED
#endif
#ifdef BLACKBOX_STOP_SEC_VAR_CLEARED_UNSPECIFIED
    #undef BLACKBOX_STOP_SEC_VAR_CLEARED_UNSPECIFIED
    #define STOP_SEC_VAR
#endif


#ifdef BLACKBOX_START_SEC_VAR_NOINIT_8
    #undef BLACKBOX_START_SEC_VAR_NOINIT_8
    #define START_SEC_VAR_NOINIT_8BIT
#endif
#ifdef BLACKBOX_STOP_SEC_VAR_NOINIT_8
    #undef BLACKBOX_STOP_SEC_VAR_NOINIT_8
    #define STOP_SEC_VAR
#endif

#ifdef BLACKBOX_START_SEC_VAR_NOINIT_16
    #undef BLACKBOX_START_SEC_VAR_NOINIT_16
    #define START_SEC_VAR_NOINIT_16BIT
#endif
#ifdef BLACKBOX_STOP_SEC_VAR_NOINIT_16
    #undef BLACKBOX_STOP_SEC_VAR_NOINIT_16
    #define STOP_SEC_VAR
#endif

#ifdef BLACKBOX_START_SEC_VAR_NOINIT_32
    #undef BLACKBOX_START_SEC_VAR_NOINIT_32
    #define START_SEC_VAR_NOINIT_32BIT
#endif
#ifdef BLACKBOX_STOP_SEC_VAR_NOINIT_32
    #undef BLACKBOX_STOP_SEC_VAR_NOINIT_32
    #define STOP_SEC_VAR
#endif

#ifdef BLACKBOX_START_SEC_VAR_NOINIT_UNSPECIFIED
    #undef BLACKBOX_START_SEC_VAR_NOINIT_UNSPECIFIED
    #define START_SEC_VAR_NOINIT_UNSPECIFIED
#endif
#ifdef BLACKBOX_STOP_SEC_VAR_NOINIT_UNSPECIFIED
    #undef BLACKBOX_STOP_SEC_VAR_NOINIT_UNSPECIFIED
    #define STOP_SEC_VAR
#endif


#ifdef BLACKBOX_START_SEC_VAR_8
    #undef BLACKBOX_START_SEC_VAR_8
    #define START_SEC_VAR_INIT_8BIT
#endif
#ifdef BLACKBOX_STOP_SEC_VAR_8
    #undef BLACKBOX_STOP_SEC_VAR_8
    #define STOP_SEC_VAR
#endif

#ifdef BLACKBOX_START_SEC_VAR_16
    #undef BLACKBOX_START_SEC_VAR_16
    #define START_SEC_VAR_INIT_16BIT
#endif
#ifdef BLACKBOX_STOP_SEC_VAR_16
    #undef BLACKBOX_STOP_SEC_VAR_16
    #define STOP_SEC_VAR
#endif

#ifdef BLACKBOX_START_SEC_VAR_32
    #undef BLACKBOX_START_SEC_VAR_32
    #define START_SEC_VAR_INIT_32BIT
#endif
#ifdef BLACKBOX_STOP_SEC_VAR_32
    #undef BLACKBOX_STOP_SEC_VAR_32
    #define STOP_SEC_VAR
#endif

#ifdef BLACKBOX_START_SEC_VAR_UNSPECIFIED
    #undef BLACKBOX_START_SEC_VAR_UNSPECIFIED
    #define START_SEC_VAR_INIT_UNSPECIFIED
#endif
#ifdef BLACKBOX_STOP_SEC_VAR_UNSPECIFIED
    #undef BLACKBOX_STOP_SEC_VAR_UNSPECIFIED
    #define STOP_SEC_VAR
#endif


#ifdef BLACKBOX_START_SEC_VAR_SAVED_ZONEH_8
    #undef BLACKBOX_START_SEC_VAR_SAVED_ZONEH_8
    #define START_SEC_VAR_ZONEH_8BIT
#endif
#ifdef BLACKBOX_STOP_SEC_VAR_SAVED_ZONEH_8
    #undef BLACKBOX_STOP_SEC_VAR_SAVED_ZONEH_8
    #define STOP_SEC_VAR
#endif

#ifdef BLACKBOX_START_SEC_VAR_SAVED_ZONEH_16
    #undef BLACKBOX_START_SEC_VAR_SAVED_ZONEH_16
    #define START_SEC_VAR_ZONEH_16BIT
#endif
#ifdef BLACKBOX_STOP_SEC_VAR_SAVED_ZONEH_16
    #undef BLACKBOX_STOP_SEC_VAR_SAVED_ZONEH_16
    #define STOP_SEC_VAR
#endif

#ifdef BLACKBOX_START_SEC_VAR_SAVED_ZONEH_32
    #undef BLACKBOX_START_SEC_VAR_SAVED_ZONEH_32
    #define START_SEC_VAR_ZONEH_32BIT
#endif
#ifdef BLACKBOX_STOP_SEC_VAR_SAVED_ZONEH_32
    #undef BLACKBOX_STOP_SEC_VAR_SAVED_ZONEH_32
    #define STOP_SEC_VAR
#endif

#ifdef BLACKBOX_START_SEC_VAR_SAVED_ZONEH_UNSPECIFIED
    #undef BLACKBOX_START_SEC_VAR_SAVED_ZONEH_UNSPECIFIED
    #define START_SEC_VAR_ZONEH_UNSPECIFIED
#endif
#ifdef BLACKBOX_STOP_SEC_VAR_SAVED_ZONEH_UNSPECIFIED
    #undef BLACKBOX_STOP_SEC_VAR_SAVED_ZONEH_UNSPECIFIED
    #define STOP_SEC_VAR
#endif



/**********************************************************************************************************************
 *  BlackBox END
 *********************************************************************************************************************/




/* Package Merger: Stop Section MemMapModuleList */

/*------------------------------GLOBAL-SECTIONS-----------------------------*/
/* Check code sections */
#if ( (defined CODE_SEC_OPEN)                            && \
     ((defined START_SEC_CODE                          ) || \
      (defined START_SEC_CODE_FAST                     ) || \
      (defined START_SEC_CODE_ISR                      )    \
      ))
    #error "BB_MemMap.h: Close the former code segment before opening a new one."
#endif

/* Check const sections */
#if ( (defined CONST_SEC_OPEN)                           && \
     ((defined START_SEC_CONST_8BIT                    ) || \
      (defined START_SEC_CONST_16BIT                   ) || \
      (defined START_SEC_CONST_32BIT                   ) || \
      (defined START_SEC_CONST_UNSPECIFIED             )    \
      ))
    #error "BB_MemMap.h: Close the former const segment before opening a new one."
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
      (defined START_SEC_VAR_ZONEH_8BIT                ) || \
      (defined START_SEC_VAR_ZONEH_16BIT               ) || \
      (defined START_SEC_VAR_ZONEH_32BIT               ) || \
      (defined START_SEC_VAR_ZONEH_UNSPECIFIED         )    \
      ))
    #error "BB_MemMap.h: Close the former variable segment before opening a new one."
#endif



/*------------------------------GLOBAL-START-SECTIONS------------------------------*/

/* Code section */
#ifdef START_SEC_CODE                         
    #define CODE_SEC_OPEN
	
	#pragma SET_CODE_SECTION(".bbtext")
	
    #undef START_SEC_CODE                         
    #undef MEMMAP_ERROR
#endif




/* Const section */
#ifdef START_SEC_CONST_8BIT
    #define CONST_SEC_OPEN
	
	#pragma SET_DATA_SECTION(".bbconst:bit8")
	
    #undef START_SEC_CONST_8BIT                   
    #undef MEMMAP_ERROR
#endif


#ifdef START_SEC_CONST_16BIT
    #define CONST_SEC_OPEN
	
	#pragma SET_DATA_SECTION(".bbconst:bit16")
	
    #undef START_SEC_CONST_16BIT                  
    #undef MEMMAP_ERROR
#endif


#ifdef START_SEC_CONST_32BIT                  
    #define CONST_SEC_OPEN
	
	#pragma SET_DATA_SECTION(".bbconst:bit32")
	
    #undef START_SEC_CONST_32BIT                  
    #undef MEMMAP_ERROR
#endif


#ifdef START_SEC_CONST_UNSPECIFIED            
    #define CONST_SEC_OPEN
	
	#pragma SET_DATA_SECTION(".bbconst:unspecified")
	
    #undef START_SEC_CONST_UNSPECIFIED            
    #undef MEMMAP_ERROR
#endif




/* Var section */
#ifdef START_SEC_VAR_INIT_8BIT                
    #define VAR_SEC_OPEN
	
	#pragma SET_DATA_SECTION(".bbdata:bit8")
	
    #undef START_SEC_VAR_INIT_8BIT                
    #undef MEMMAP_ERROR
#endif


#ifdef START_SEC_VAR_INIT_16BIT               
    #define VAR_SEC_OPEN
	
	#pragma SET_DATA_SECTION(".bbdata:bit16")
	
    #undef START_SEC_VAR_INIT_16BIT               
    #undef MEMMAP_ERROR
#endif


#ifdef START_SEC_VAR_INIT_32BIT               
    #define VAR_SEC_OPEN
	
	#pragma SET_DATA_SECTION(".bbdata:bit32")
	
    #undef START_SEC_VAR_INIT_32BIT               
    #undef MEMMAP_ERROR
#endif


#ifdef START_SEC_VAR_INIT_UNSPECIFIED         
    #define VAR_SEC_OPEN
	
	#pragma SET_DATA_SECTION(".bbdata:unspecified")
	
    #undef START_SEC_VAR_INIT_UNSPECIFIED         
    #undef MEMMAP_ERROR
#endif


#ifdef START_SEC_VAR_NOINIT_8BIT              
    #define VAR_SEC_OPEN
	
	#pragma SET_DATA_SECTION(".bbbss:bit8")
	
    #undef START_SEC_VAR_NOINIT_8BIT              
    #undef MEMMAP_ERROR
#endif


#ifdef START_SEC_VAR_NOINIT_16BIT             
    #define VAR_SEC_OPEN
	
	#pragma SET_DATA_SECTION(".bbbss:bit16")
	
    #undef START_SEC_VAR_NOINIT_16BIT             
    #undef MEMMAP_ERROR
#endif


#ifdef START_SEC_VAR_NOINIT_32BIT             
    #define VAR_SEC_OPEN
	
	#pragma SET_DATA_SECTION(".bbbss:bit32")
	
    #undef START_SEC_VAR_NOINIT_32BIT             
    #undef MEMMAP_ERROR
#endif


#ifdef START_SEC_VAR_NOINIT_UNSPECIFIED       
    #define VAR_SEC_OPEN
	
	#pragma SET_DATA_SECTION(".bbbss:unspecified")
	
    #undef START_SEC_VAR_NOINIT_UNSPECIFIED       
    #undef MEMMAP_ERROR
#endif


#ifdef START_SEC_VAR_ZERO_INIT_8BIT           
    #define VAR_SEC_OPEN
	
	#pragma SET_DATA_SECTION(".bbbss:bit8")
	
    #undef START_SEC_VAR_ZERO_INIT_8BIT           
    #undef MEMMAP_ERROR
#endif


#ifdef START_SEC_VAR_ZERO_INIT_16BIT          
    #define VAR_SEC_OPEN
	
	#pragma SET_DATA_SECTION(".bbbss:bit16")
	
    #undef START_SEC_VAR_ZERO_INIT_16BIT          
    #undef MEMMAP_ERROR
#endif


#ifdef START_SEC_VAR_ZERO_INIT_32BIT          
    #define VAR_SEC_OPEN
	
	#pragma SET_DATA_SECTION(".bbbss:bit32")
	
    #undef START_SEC_VAR_ZERO_INIT_32BIT          
    #undef MEMMAP_ERROR
#endif


#ifdef START_SEC_VAR_ZERO_INIT_UNSPECIFIED    
    #define VAR_SEC_OPEN
	
	#pragma SET_DATA_SECTION(".bbbss:unspecified")
	
    #undef START_SEC_VAR_ZERO_INIT_UNSPECIFIED    
    #undef MEMMAP_ERROR
#endif


#ifdef START_SEC_VAR_ZONEH_8BIT
    #define VAR_SEC_OPEN
	
	#pragma SET_DATA_SECTION(".typeH:blackbox:bit8")
	
    #undef START_SEC_VAR_ZONEH_8BIT
    #undef MEMMAP_ERROR
#endif


#ifdef START_SEC_VAR_ZONEH_16BIT
    #define VAR_SEC_OPEN
	
	#pragma SET_DATA_SECTION(".typeH:blackbox:bit16")
	
    #undef START_SEC_VAR_ZONEH_16BIT
    #undef MEMMAP_ERROR
#endif


#ifdef START_SEC_VAR_ZONEH_32BIT
    #define VAR_SEC_OPEN
	
	#pragma SET_DATA_SECTION(".typeH:blackbox:bit32")
	
    #undef START_SEC_VAR_ZONEH_32BIT
    #undef MEMMAP_ERROR
#endif


#ifdef START_SEC_VAR_ZONEH_UNSPECIFIED
    #define VAR_SEC_OPEN
	
	#pragma SET_DATA_SECTION(".typeH:blackbox:unspecified")
	
    #undef START_SEC_VAR_ZONEH_UNSPECIFIED
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
    #error "BB_MemMap.h, wrong pragma command"
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
