/*****************************************************************************
| Project Name: FLEXKOM            (flexible communication for CAN)
|    File Name: dbk_def.h          (Header for the SG-Data)
|
|  Description: dbk_def.h         contains specifc Flexkom-Data and Struct-
|                                 defines. The PreProcessor-Flags are defines
|                                 in dbkdef, which include in c_dbk.c
|
|-----------------------------------------------------------------------------
|               C O P Y R I G H T
|-----------------------------------------------------------------------------
| Copyright (c) 1997 by Vector Informatik GmbH.           All rights reserved.
|-----------------------------------------------------------------------------
|               A U T H O R   I D E N T I T Y
|-----------------------------------------------------------------------------
| Initials     Name                      Company
| --------     ---------------------     ------------------------------------
| Rn           Jochen Rein               Vector Informatik GmbH
| Rna          Ruediger Naas             Vector Informatik GmbH
| Agh          Alexander Gronbach        Vector Informatik GmbH
|-----------------------------------------------------------------------------
|               R E V I S I O N   H I S T O R Y
|-----------------------------------------------------------------------------
| Date         Ver  Author  Description
| ---------   ---  ------  --------------------------------------------------
|31-Mar-1998    1.00  Rn    Auslieferung
|22-Mai-1998    1.01  Rn    Erweiterungen fuer HC12 Cosmic Version 4.2a
|27-Mai-1998    1.10  Rn    Erweiterungen fuer Mehrkanaligen Can-Treiber
|28-Mai-1998    1.11  Rn    bugfix: kCanTxT1T2 war mit kCanTxSendImmdt vertauscht
|01-Jul-1998    1.12  Rn    Anpassungen an das Tool Version 1.02
|07-Jul-1998    1.13  Rn    Anpassungen an das Tool Version 1.02, 2.05
|                           dbkStart und dbkStop
|                           default-Wert bei Timeout
|                           in Empfangspuffer schreiben
|                           Mehrfachsteuergeraete
|11-Aug-1998    1.14  Rn    Anpassungen fuer Mehrfachsteuergeraete
|24-Mar-1999    1.15  Rn    more then 255 Receive-Signale possible
|                           separate Timeout- and Indication-Flags
|30-Mar-1999    1.16  Bd    signal evaluation functions for NBYTE signals added
|                           CanTx/RxSignByteX1/X2Value[] arrays added for NBYTE signals
|                     Rn    force Indication if timeout
|                     Bd    dbkom structures CanXXX renamed into DbkXXX
|                     Bd    dbkStart/dbkStop functions divided into dbkTx/RxStart and
|                           dbkTx/RxStop function
|19-Mai-1999    1.17  Bd    Tx/Rx Message Structures concerning the candriver module
|                           removed and added in c_flex.c
|21-Mai-1999    1.17  Bd/Rn switch C_ENABLE_PRODUCTION and defines for evalfunctions added
|28-Jun-1999    1.18  Rn    insert canbittype
|14-Okt-1999    1.19  Bd    DbkRxMECUHandleTable for switch C_ENABLE_MULTIPLE_ECU_RCV_OPT added
|28-Dec-1999    1.20  Rn    no changes
|18-Apr-2000    1.21  Rn    delete version-declarations 
|15-Mai-00      1.22D Rn    results of Codereview
|10-jun-2000    1.23  Rn    no changes
|21-Aug-2000    1.24  Rn    no changes
|                     Mr    modify CanTxSignalState
|29-Nov-2000    1.25  Bd    no changes
|04-Dec-2000    1.26  Gz    no changes
|21-Dec-2000    1.27  Mr    modify DbkTxMsgECUMask - size
|                     Rn    support multipleECU with with DbkomGen > 2.02
|                     Mr    additional corrections for MULT.ECU-USE with DBKOMGEN > 2.02
|                     Bd    #include dbk_init.h changed into dbk_cfg.h
|20-Feb-2001    1.28  Fz    No changes
|01-Mar-2001    1.29  Gz    added array dimensions
|04-Apr-2001    1.30  Gz    no changes
|04-Apr-2001    1.31  Rn    no changes
|13-Jul-2001    1.32  Rn    _c_Charbit with char instead canbittype (ESCAN00000968)
|24-Jul-2001    1.33  Gz    no changes
|25-Jul-2001    1.34  Ml    casts for cosmic-compiler with -pck-check
|14-Sep-2001    1.35  Ml    Message indication flags are set in dbkprecopy. This
|                           was inserted for the message gateway 
|05-Oct-2001    1.36  Sa    ESCAN00001544: Cast operator fixed.
|23-Nov-2001    1.37  Rn    ESCAN00001831: access to flags changed
|04-Jan-2002    1.38  Rn    ESCAN00001855: enter DBK_API_CALL_TYPE 
|                     Rn    ESCAN00002021: each # in first column
|30-Nov-2001    1.39  Rn    ESCAN00002020: support INTEL/MOTOROLA
|                           ESCAN00002084: Confirmation/indication
|                           ESCAN00002356: wrong default values on timeout (nByte signals)
|01-Mar-2002    1.40  Fz    ESCAN00002404: missing ";" at prototype added  
|14-Mar-2002    1.41  Rn    ESCAN00002486: no changes
|04-Apr-2002    1.42  Rn    ESCAN00002486: no changes
|14-Apr-2002    1.43  Fz    ESCAN00002659: data type of array DbkTxMsgDataOffset
|                           now depending  on count of tx signals
|                           ESCAN00002663: Compiler warning because of value 
|                           truncation
|25-Apr-2002    1.44  Rn    ESCAN00002721: support more than 255 signals  
|30-Apr-2002    1.45  Ml    ESCAN00002764: corrected prototypes
|14-Mar-2002    1.46  Rn    ESCAN00002486: no changes
|11-Jul-2002    1.47  Rn    ESCAN00003210: support new Controller
|22-Jul-2002    1.48  Fz    ESCAN00003299: Flags for V850 changed
|06-Sep-2002    1.49  Ml    ESCAN00003687: no changes
|18-Oct-2002    1.50  Go    ESCAN00003981: no changes
|28-Oct-2002    1.51  Rn    ESCAN00004023: support canbittype new comiler
|08-Nov-2002    1.52  Ml    ESCAN00004142: no changes
|2003-02-24           AP                 : no changes
|2003-02-24           Rna   ESCAN00004640: no changes
|2003-02-24     1.53  Rna   ESCAN00004641: no changes
|2003-04-10     1.54  Rn    ESCAN00005211: wrong indication-flags or confirmation-flags set
|2003-05-08     1.55  Rn    ESCAN00005585: Mask in dbkGetTxByte and dbkGetTxWord
|2003-05-19     1.56  Rn    ESCAN00005211: wrong indication-flags or confirmation-flags set
|2003-05-26     1.57  Bus   added V_MEMROM0 
|                     Rna   ESCAN00005833: dbkPutRxnByteSwap does not exist
|2003-05-26     1.58  Rna   ESCAN00006408: switch C_BYTE_ACCESS_DBKOM for H8S IAR added
|2003-10-31     2.00  Rn    ESCAN00006918: Support Geny-output
|                     Rna                  MultiEcu support
|                                          DbkTxSignByteX1Value[kDbkNumberOfTxXxX1Bytes]
|                                          Multiple ECU fixed
|                                          Defaulvalues n16Bit/Word for little endian fixed
|                                          Timeout for multipleECU. Delete old multipleECU
|2004-02-11     2.01   Ml   ESCAN00007550: no changes
|                      Rn   ESCAN00007478: no changes
|                      Rn   ESCAN00007423: no chnages
|2004-02-20     2.02   Bus  ESCAN00007655: support for  C_COMP_GNU_TRICORE_MULTICAN and C_COMP_TASKING_TRICORE_MULTICAN
|2004-02-25     2.03   Rna  ESCAN00007710: Compiler Error: comMultipleECUCurrent undefined (.c file)
|                           ESCAN00007749: DbkTxSigSwitch.s_default for Geny not still existent (Todo)
|2004-03-05     2.04   Bus  ESCAN00007800: support for DC Powertrain Module
|2004-03-16     2.05   Bus  ESCAN00007908: define C_ENABLE_MULTICAN not sufficient for Gnu compiler
|2004-04-05     2.06   Rna  ESCAN00008156: Support Intel/Motorola signals/container
|2004-04-13     2.07   Bus  ESCAN00008167: redeclaration of DbkTxMsgDefault, DbkRxMsgDefault 
|                           ESCAN00008168: no changes
|                           ESCAN00008161: avoid redundant declaration error
|2004-05-13     2.08   Fmi  ESCAN00008361: Added support for task split
|                      Rna  ESCAN00008382: Possible truncation of values in DbkRxSigStartbit table
|2004-07-07     2.09   Rna  ESCAN00008766: message is sent too late in start up phase
|2004-07-07            Rna  ESCAN00008422: wrong timeoutvalue for signals sharing one byte of a message
|                           ESCAN00008680: MISRA check
|2004-07-16            Rna  ESCAN00007423: warning: variable "SigHdl" was declared but  never referenced
|2004-08-16            Rn   ESCAN00008456: Signal evaluation may return wrong result
|2004-09-07            Rna  ESCAN00009410: nothing changed in header
|2004-09-13            Rna  ESCAN00009462: Naming Conventions
|2004-09-21          Hso/RnaESCAN00009563: callback function for init/ start/ stop
|2004-10-01            Rna  ESCAN00009735: chooseable variable memory classifier for dbkom variables
|2004-12-06     2.10   Rna               : renaming byteorder swap switches
|2004-12-07            Bus  ESCAN00010045: support for Tx optimization new CRC interface
|                      Rna  ESCAN00008680: MISRA check
|2005-02-01  		       Rna  ESCAN00010596: dbkGetTxnBit: incorrect signal value due to missing signal mask
|2005-03-31            Rna  ESCAN00011108: this is the right ESCAN number for Dbkom V.2.xx. ESCAN10596 is for DBKom V.1.xx
|2005-02-02            Rna  ESCAN00010996: BAF message is not sent after calling dbkTxStop and dbkTxStart
|2005-04-07            Rna  ESCAN00011767: this is the right ESCAN number for Dbkom V.2.xx. ESCAN10996 is for DBKom V.1.xx
|2005-02-10            Rna  ESCAN00011082: Simplification of "Byteswapmechanism"
|2005-02-11     2.11   Rna  ESCAN00011113: dbkPutTxSignalname effects wrong value on the bus
|2005-02-21            Rna  ESCAN00011120: NULL should not be used in the component
|2005-02-22            Rna  ESCAN00003686: support 32-bit signaltype for 32-bit controller
|2005-02-22            Rna  ESCAN00011190: string.h should not be included (do not use library functions)
|2005-02-22            Rna  ESCAN00007582: support common API for signals <= 16 Bit and > 16 Bit
|2005-03-01     2.12   Rna  ESCAN00011178: Sync macros are wrong in cyclic dbkput functions (fix made with v.2.11, history updated 2.12)
|2005-03-01            Rna  ESCAN00011312: variable "Switch" not defined
|2005-03-03            Rna  ESCAN00011356: comMultipleECUCurrent is undefined
|2005-03-03            Rna  ESCAN00011363: CanTxnByteEvalFunctions/pValue/dbkTxSignByteMask not defined
|2005-03-04            Rna  ESCAN00011372: missing casts
|2005-03-08     2.13   Rna  ESCAN00011398: A compile error argument of type "const void*" is incombatible with parameter of type  "void*"
|                      Bus  ESCAN00011425: no changes
|                      Bus  ESCAN00011372: no changes
|2005-03-14     2.14   Ml   ESCAN00011468: no changes
|2005-03-31     2.15   Rna  ESCAN00011668: Lowest prioritized instead of highest prioritized Dbkom messages get transmitted
|2005-04-11            Rna  ESCAN00011874: Dbkom Buffer for Rx signal contains wrong value in timeout case
|2005-05-02     2.16   Rna  ESCAN00012135: compile error = : incompatible types in function dbkRxTask
|2005-06-14     2.17   Rna  ESCAN00012527: Cycle time of Dbkom messages is not correct
|2005-06-22            Rna  ESCAN00012230: Unsigned/signed comparision fails on Mcs12x/Metrowerks
|2005-06-22            Rna  ESCAN00012624: Warning due to unused variable (signal_state)
|2005-06-22            Rna  ESCAN00012572: Add Copperhead/DiabData to the Uneven Word Access Microcontroller List
|2005-06-29            Rna  ESCAN00012689: Transmission of signals with sendtype cyclicIfActiveFast is delayed
|2005-06-29            Rna  ESCAN00012695: Todo:Memory qualifier for ROM tables expanded
|2005-07-01            Rna  ESCAN00012720: Do use macros instead of values to delete flags
|2005-07-01            Rna  ESCAN00012723: Init the Timeoutvalues must be done channelspecific (dbkRxStart)
|2005-07-05     2.18   Rn   ESCAN00012704: insert comments for different resource categories
|2005-07-26            Rna  ESCAN00013025: Todo:Optimization of Precopy function; Support multichannel and MultipleECU (dbkRxStart) removed
|2005-07-27            Rna  ESCAN00013056: MISRA and PC LINT check
|2005-08-03            Rna  ESCAN00013146: Compile error: Variable MsgHdl not declared
|2005-08-25     2.19   Rna  ESCAN00013322: truncation assignement
|2005-09-13     2.20   Rna  ESCAN00013541: Variable "switch" not defined
|2005-09-28     2.21   Rna  ESCAN00012704: insert comments for different resource categories
|2005-10-05            Rna  ESCAN00013705: Values are not right masked for interlocked containers (Gaps)
|2005-10-07     2.22   Rna  ESCAN00013766: compiler warning: unused variable "MsgHdl"
|2005-10-12            Rna  ESCAN00013857: Indication- function/flag are not called/set the rigth way
|2005-12-14     2.23   Rna  ESCAN00014653: insert comments for different resource categories
|2006-02-15     2.24   Rna  ESCAN00015399: Memory qualifier need to get adjusted for HCS12 Xgate gConst section
|2006-03-09     2.25   Rna  ESCAN00015254: Compiler error:" the size of an array must be greater than zero" occures for dbk_def.h
|                      Rna  ESCAN00015602: Value of received signals are wrong
|                      Rna  ESCAN00015768: compiler warning: Incompatible type to previous declaration (found 'void (*) ()', expected 'void (*far ) ()')
|                      Rna  ESCAN00015779: Wrong copying of nByte containers with Metrowerks compiler on platforms with paging
|                      Rna  ESCAN00016105: Support DBKom for V85x with IAR compiler
|2006-05-16     2.26   Rna  ESCAN00016366: Sendtype "sofort" is send out of task instead spontaneous
|2006-06-22     2.27   Ml   ESCAN00016661: Wrong default values after timeout if glo bal const is used on Mcs12x
|                      Fmi  ESCAN00016665: Compile error in function dbkGetTxnBit using Cosmic compiler with option -pck
|2006-07-19     2.28   Rna  ESCAN00016781: New API to stop cyclic messages
|2006-07-28     2.29   Rna  ESCAN00017112: Duplication of function dbkPutRxnByte into dbkPutRxnByteinternal and dbkPutRxnByte
|                      Rna  ESCAN00017123: dWord support not still required
|2006-10-05            Rna  ESCAN00017852: Signals of type "immediately" are not sent if value changes
|2006-10-10            Rna  ESCAN00017984: Implement variant handling for cyclic DBKOM messages
|2006-12-04     2.30   Rna  ESCAN00018611: #define for array size for table DbkVariantIndirection changed
|2006-12-05            Rna  ESCAN00018625: dbkPutTxSignalname() for n16Bit and Word signals may result wrong values on bus
|2007-02-08     2.31   Rna  ESCAN00019475: Compiler warning: "Implicit cast in assignment" occures
|2007-06-28            Dbr  ESCAN00021287: Support DBKom for SH2 with HEW compiler
|2007-10-12     2.32   Dbr  ESCAN00022685: Support DBKom for XC2000 with Tasking compiler
|2007-11-06     2.33   Rna  ESCAN00023111: Byteaccess for C_COMP_FUJITSU_FR60_CCAN and C_COMP_GHS_MPC55XX
|2008-01-06     2.34   Rna  ESCAN00023740: #define DBK_DUMMY_STATEMENT should be derived from #define V_ENABLE_USE_DUMMY_STATEMENT
|2008-01-28     2.35   Rna  ESCAN00024223: Support DBKOM for TX4961 with GHS compiler
|2008-02-06     2.36   Rna  ESCAN00024404: Support DBKOM for TMS470/TI
|2008-02-06            Rna  ESCAN00024408: Size of bitstructures for flags depends on swicht  V_CPUTYPE_BITARRAY_XXBIT
|2008-02-08     2.37   Rna  ESCAN00024466: Warning "Conversion in argument" occurs
|2008-02-08            Rna  ESCAN00024467: Prepressor warning "Zero used for undefined preprocessing identifier"
|2008-02-12     2.38   Rna  ESCAN00024532: invalid conversion from "unsigned char volatile __far *" to "void __near *"
|2008-04-21     2.39   Rna  ESCAN00026296: Support C_COMP_ARM_TMS470 added
|                      Rna  ESCAN00026294: Inication function/flag is not correct called/set and Rx buffer do not belong to received data
|2008-08-20     2.40   Rna  ESCAN00029327: Support PIC24/PIC16 with Microchip compiler
|2008-08-28            Rna  ESCAN00029469: Support C_COMP_GNU_VR55XX_AFCAN added
|2008-10-07     2.41   Rna  ESCAN00030486: Support C_COMP_TASKING_XC16X
|2008-11-18     2.42   Rna  ESCAN00031379: Access to array DbkRxMsgDeltaT with one instead of two parameters
|2009-01-19     2.43   Rna  ESCAN00032464: Support of C_COMP_GNU_IMX_FLEXCAN2
|2009-01-23     2.44   Rna  ESCAN00032544: Support FAR RAM for MCS12X Cosmic
|2009-01-28            Rna  ESCAN00032580: Support C_COMP_IAR_M16C_RCAN2
|2009-02-18     2.45   Rna  ESCAN00033183: Support C_COMP_KEIL_XC16X
|                      Rna  ESCAN00033185: Support C_COMP_GNU_ST30_CCAN
|2009-03-24     2.46   Rna  ESCAN00034017: The compile error "incompatible argument type" occurs
|2009-04-17            Rna  ESCAN00034617: Change of Precopy function regarding number of bytes to be copied
|2009-06-04     2.47   Rna  ESCAN00035493: IlDbkom overwrites data buffer in case CanRxActualDLC > CanRxDataLen
|                      Rna  ESCAN00035427: compile error due to wrong types in declaration and implementation
|2009-06-09     2.48   Rna  ESCAN00035629: Support C_COMP_MICROSOFT_TMS320ARM
|2009-11-26     2.49   Rna  ESCAN00039409: set #define C_BYTE_ACCESS_DBKOM for platform C_COMP_GAIO_SH2_RCAN
|2010-01-13     2.50   Rna  ESCAN00040102: Support of QNX context switch
|                      Rna  ESCAN00039980: Support C_COMP_VDSP_BF5XX
|2010-04-14     2.51   Rna  ESCAN00042287: Support C_COMP_QCC_TMS320ARM
|2010-05-20     2.52   Rna  ESCAN00041096: Unexpected transmission of cyclic messages after cancel of Waitbussleep
|                      Rna  ESCAN00040639: Compile error."@dbkRxTask() incompatible near pointer cast" occurs
|2010-07-22     2.53   Rna  ESCAN00044220: Support of controller C_COMP_IAR_78K0R
|2011-01-05     2.54   Rna  ESCAN00047893: Support TMS320
|2011-01-14            Rna  ESCAN00048051: Rx indication functions/flags are called/set wrong
|2011-02-28     2.55   Rna  ESCAN00048992: Compiler warning/error "truncation assignment"
|2011-03-07            Rna  ESCAN00049100: dbkGetRx...() Macro does not return the correct container value
|2011-07-04     2.56   Agh  ESCAN00051968: Rx indication functions/flags are called/set wrong (only word containers with gaps are affected)
|2011-11-24     2.57   Rna  ESCAN00051838: Compiler warning: narrowing or signed-to-unsigned type conversion found: int to unsigned short
|                      Rna  ESCAN00054689: Compiler warning: possible redundant expression
|2012-04-12     2.58   Agh  ESCAN00058081: set #define C_BYTE_ACCESS_DBKOM for platform C_COMP_HEW_SH2_RCAN2
|****************************************************************************/

#if defined (V_MEMROM0)
#else
  #define V_MEMROM0
#endif

#ifndef C_DBK_H
#define C_DBK_H

#include "dbk_cfg.h"                  /*includes the defines from the Tool*/

/*==========================================================================*/
/* defines for Paging-mode                                                  */
/*==========================================================================*/
#ifndef DBK_API_CALL_TYPE                 /* API-Type */
# define DBK_API_CALL_TYPE
#endif
#ifndef DBK_API_CALLBACK_TYPE             /* Applicationfunction called by DBKOM */
# define DBK_API_CALLBACK_TYPE
#endif
#ifndef DBK_INTERNAL_CALL_TYPE            /* functions called from other vector-layers */
# define DBK_INTERNAL_CALL_TYPE
#endif


/*==========================================================================*/
/* defines for optimizations to get removed                                 */
/*==========================================================================*/
#if defined DBK_ENABLE_TX_GENERAL_BYTE_SWAP
# define    DBK_ENABLE_TX_GENERAL_BYTESWAP
#endif
#if defined DBK_ENABLE_RX_GENERAL_BYTE_SWAP
# define    DBK_ENABLE_RX_GENERAL_BYTESWAP
#endif

#if defined DBK_DISABLE_TX_BYTEORDER_CONV
# define    DBK_ENABLE_TX_NEVER_BYTESWAP
#endif  

#if defined DBK_DISABLE_RX_BYTEORDER_CONV
# define    DBK_ENABLE_RX_NEVER_BYTESWAP
#endif  

# if defined C_CPUTYPE_BIGENDIAN
#define MOffset 1
#else 
#define MOffset 0
#endif
/*************************************************************/
/* Defines for RAM classifier                                */
/*************************************************************/

#if defined DBK_ENABLE_FAST_RAM
#define DBK_MEMORY_FAST   MEMORY_NEAR
#else
#define DBK_MEMORY_FAST MEMORY_NORMAL
#endif

/*==========================================================================*/
/* Driver Version for Diagnostics                                           */
/*==========================================================================*/
#if defined (IL_TYPE_DBKOM)
/* ##V_CFG_MANAGEMENT ##CQProject : Il_Dbkom CQComponent : Implementation */
# endif
#define IL_DBKOM_VERSION 0x0258
#define IL_DBKOM_RELEASE_VERSION 0x00

#define DBK_DRIVER_VERSION  IL_DBKOM_VERSION
#define DBK_BUGFIX_VERSION  IL_DBKOM_RELEASE_VERSION


/* ROM CATEGORY 4 START*/
V_MEMROM0 extern V_MEMROM1 canuint8 V_MEMROM2 kDbkMainVersion;
/* ROM CATEGORY 4 END*/
/* ROM CATEGORY 4 START*/
V_MEMROM0 extern V_MEMROM1 canuint8 V_MEMROM2 kDbkSubVersion;
/* ROM CATEGORY 4 END*/
/* ROM CATEGORY 4 START*/
V_MEMROM0 extern V_MEMROM1 canuint8 V_MEMROM2 kDbkBugFixVersion;
/* ROM CATEGORY 4 END*/

/* internal status for the message  the variable C_TX_MsgStatus */
#define kCanTxSendImmdt         1   /* sofortiges senden */
#define kCanTxT1T2              2   /* Zustand von T1#T2 */

/* calculate size of cond/ind-flags */
#define kDbkNumberOfConfBytes   ((kDbkNumberOfConfFlags + 7)/8)
#define kDbkNumberOfConfWords   ((kDbkNumberOfConfFlags + 15)/16)
#define kDbkNumberOfConfLongs   ((kDbkNumberOfConfFlags + 31)/32)
#define kDbkNumberOfIndBytes    ((kDbkNumberOfIndFlags + 7)/8)
#define kDbkNumberOfIndWords    ((kDbkNumberOfIndFlags + 15)/16)
#define kDbkNumberOfIndLongs    ((kDbkNumberOfIndFlags + 31)/32)
#define kDbkNumberOfTOBytes     ((kDbkNumberOfTOFlags + 7)/8)
#define kDbkNumberOfTOWords     ((kDbkNumberOfTOFlags + 15)/16)
#define kDbkNumberOfTOLongs     ((kDbkNumberOfTOFlags + 31)/32)

/* define for Tool, to use the new flag-structures */
#define DBK_ENABLE_NEW_FLAGS


#if !defined V_CPUTYPE_BITARRAY_32BIT && !defined V_CPUTYPE_BITARRAY_16BIT && !defined(V_CPUTYPE_BITARRAY_8BIT)
#error inconsistent generated data
#endif


/* datatypes for indication, Confirmation and confirmation flags */
#if defined ( DBK_ENABLE_TX_CONF_FLAG )
union DbkConfirmationBits 
{
  canuint8         _c[kDbkNumberOfConfBytes];
# if defined V_CPUTYPE_BITARRAY_32BIT
#  if ( kDbkNumberOfConfFlags > 16 )
  struct _c_bits32 w[kDbkNumberOfConfLongs];
#  endif
#  if ( kDbkNumberOfConfFlags > 8 ) && ( kDbkNumberOfConfFlags <= 16 )
  struct _c_bits16 w[1];
#  endif
# else
  #if ( kDbkNumberOfConfFlags > 8 )
  struct _c_bits16 w[kDbkNumberOfConfWords];
  #endif
  #endif
# if ( kDbkNumberOfConfFlags < 9 )
  struct _c_bits8  w[1];
# endif
}; 
#endif


#if defined ( DBK_ENABLE_RX_IND_FLAG ) || \
    defined ( DBK_ENABLE_RX_IND_FUNC )
union DbkIndicationBits 
{
  canuint8         _c[kDbkNumberOfIndBytes];
#if defined V_CPUTYPE_BITARRAY_32BIT
#  if ( kDbkNumberOfIndFlags > 16 )
  struct _c_bits32 w[kDbkNumberOfIndLongs];
#  endif
#  if ( kDbkNumberOfIndFlags > 8 ) && ( kDbkNumberOfIndFlags <= 16 )
  struct _c_bits16 w[1];
#  endif
# else
  #if ( kDbkNumberOfIndFlags > 8 )
  struct _c_bits16 w[kDbkNumberOfIndWords];
  #endif
  #endif
# if ( kDbkNumberOfIndFlags < 9 )
  struct _c_bits8  w[1];
# endif
}; 
#endif


#if defined ( DBK_ENABLE_RX_TIMEOUT_FLAG )
union DbkTimeoutBits 
{
  canuint8         _c[kDbkNumberOfTOBytes];
#if defined V_CPUTYPE_BITARRAY_32BIT
#  if ( kDbkNumberOfTOFlags > 16 )
  struct _c_bits32 w[kDbkNumberOfTOLongs];
#  endif
#  if ( kDbkNumberOfTOFlags > 8 ) && ( kDbkNumberOfTOFlags <= 16 )
  struct _c_bits16 w[1];
#  endif
# else
  #if ( kDbkNumberOfTOFlags > 8 )
  struct _c_bits16 w[kDbkNumberOfTOWords];
  #endif
  #endif
# if ( kDbkNumberOfTOFlags < 9 )
  struct _c_bits8  w[1];
# endif
}; 
#endif

/****************************************************************************
* dbkGetModuleContext/dbkSetModuleContext Interface
****************************************************************************/
#if defined(DBK_ENABLE_GET_CONTEXT) || defined(DBK_ENABLE_SET_CONTEXT) || \
  ((defined(VGEN_ENABLE_MDWRAP) || defined(VGEN_ENABLE_QWRAP))   && \
    defined(VQNX_ENABLE_CONTEXT_SWITCH))
/* Dbkom context structure C_ENABLE_QNX_MINIDRIVER */
typedef struct
{
  vuint32 dbkMagicNumber;
#if defined DBK_ENABLE_TX_CONF_FLAG
  union DbkConfirmationBits CanTxConfirmationFlagsCTB;/*bits to tell the Application the Message was sent*/
#endif
#ifdef DBK_ENABLE_RX_IND_FLAG 
  union DbkIndicationBits CanRxIndicationFlagsCTB;/*bits to tell the Application the receive a Message*/
#endif
#if defined( DBK_ENABLE_RX_IND_FLAG ) || defined( DBK_ENABLE_RX_IND_FUNC )
  union DbkIndicationBits  dbkDummyIndicationFlagsCTB;/*bits to tell the Application the receive a Message*/
#endif
#ifdef DBK_ENABLE_RX_TIMEOUT_FLAG
  union DbkTimeoutBits  CanRxTimeoutFlagsCTB;/*bits to tell the Application the Timeout for a receive-message*/
#endif
#if   defined( DBK_ENABLE_RX_TIMEOUT_FLAG ) \
   || defined( DBK_ENABLE_RX_TIMEOUT_FUNC ) \
   || defined( DBK_ENABLE_DEFAULT_TO )
  canuint16 CanRxTimeoutTimerCTB[kDbkNumberOfRxObjects];/*Timer to proof the Timeout*/
#endif
#if kDbkNumberOfTxSigStateBytes == 0 
  canuint8 CanTxSignalStateCTB[ kDbkNumberOfTxSigStateBytes + 1 ];
#else 
  canuint8 CanTxSignalStateCTB[ kDbkNumberOfTxSigStateBytes ];
#endif
#if (kDbkNumberOfTxObjects > 0)
  canuint8 CanTxTminTimerCTB[kDbkNumberOfTxObjects];
  canuint8 CanTxMsgStatusCTB[kDbkNumberOfTxObjects];
  canuint8 CanTxMsgNRepZaehlerCTB[kDbkNumberOfTxObjects];
  canuint16 CanTxMsgTimerCTB[kDbkNumberOfTxObjects];
#endif
  canuint8 dbkStatusCTB[kDbkNumberOfChannels];          
}
tdbkModuleContextStruct;

typedef tdbkModuleContextStruct* tdbkModuleContextStructPtr;

#endif 
#if defined(DBK_ENABLE_GET_CONTEXT) || (defined(VGEN_ENABLE_MDWRAP) && defined(VQNX_ENABLE_CONTEXT_SWITCH))
void extern dbkGetModuleContext(tdbkModuleContextStructPtr pContext);
#endif
#if defined(DBK_ENABLE_SET_CONTEXT) || (defined(VGEN_ENABLE_QWRAP) && defined(VQNX_ENABLE_CONTEXT_SWITCH))
vuint8 extern dbkSetModuleContext(tdbkModuleContextStructPtr pContext);
#endif


#if !defined(kDbkNumberOfRxSignals)
# define kDbkNumberOfRxSignals kCanNumberOfRxSignals
#endif
#if !defined( kDbkNumberOfTxSigStateBytes )
# define kDbkNumberOfTxSigStateBytes kCanNumberOfTxSigStateBytes
#endif 
#if !defined( kDbkNumberOfTxXxBytes )
# define kDbkNumberOfTxXxBytes kCanNumberOfTxXxBytes
#endif 
#if !defined( kDbkNumberOfRxXxBytes )
# define kDbkNumberOfRxXxBytes kCanNumberOfRxXxBytes
#endif 
#if !defined( kDbkNumberOfTotalTxSignals )
# define kDbkNumberOfTotalTxSignals kCanNumberOfTotalTxSignals
#endif 

/***************************************************************************/
/* error codes                                                             */
/***************************************************************************/
/* assertion gentool */

#define kNoDummyFunctionDefined   0x01

#define kBadSignalType            0x01
#define kBadSignalMode            0x02
#define kBadSignalValue           0x03
#define kDbkErrorInitCall         0x04
#define kDbkErrorRxDlcTooLarge    0x05

#define kDbkErrorWrongSignalType  0x40


#define TYP_NBIT    1
#define TYP_BYTE    2
#define TYP_N16BIT  3
#define TYP_WORD    4
#define TYP_NBYTE   5

/***************************************************************************/
/* Defines                                                                 */
/***************************************************************************/
#if (kDbkNumberOfTxObjects > 255)
# define DbkSignalStateType canuint16
#else
# define DbkSignalStateType canuint8
#endif

#if (kDbkNumberOfRxSignals > 255)||\
    (kDbkNumberOfTxSignals > 255)
# define DbkSigHandleType canuint16
# define dbkSigHandleType canuint16   /* compatibility for older Tool-versions */
#else
# define DbkSigHandleType canuint8
# define dbkSigHandleType canuint8    /* compatibility for older Tool-versions */
#endif

#if (kDbkNumberOfBytesEx > 255)
# define DbkTxOffsetType canuint16
# define DbkRxOffsetType canuint16
#else
# define DbkTxOffsetType canuint8
# define DbkRxOffsetType canuint8
#endif

#if ((kDbkNumberOfTxXxBytes > 255)  || (kDbkNumberOfRxXxBytes > 255) )
# define DbknByteOffsetType canuint16
#else
# define DbknByteOffsetType canuint8
#endif

/* only dbkom version since 1.30 */
#define CanTxSignalsEx  CanSignalsEx
#define CanRxSignalsEx  CanSignalsEx
#define DbkRxMsgDefault DbkMsgDefault  
#define DbkTxMsgDefault DbkMsgDefault  


#ifndef kDbkNumberOfChannels
 #define kDbkNumberOfChannels 1
#endif


/*==========================================================================*/
/* Prototypes for CIO                                                       */
/*==========================================================================*/
#ifdef DBK_ENABLE_EXT_INIT
/* CODE CATEGORY 2 START*/
extern void  ApplDbkInit(void);
/* CODE CATEGORY 2 END*/
#endif

#ifdef DBK_ENABLE_EXT_TX_START
 #ifdef DBK_ENABLE_TX_CHANNEL_SPECIFIC
/* CODE CATEGORY 2 START*/
extern void ApplDbkTxStart(CanChannelHandle channel);
/* CODE CATEGORY 2 END*/
 #else
/* CODE CATEGORY 2 START*/
extern void ApplDbkTxStart(void);
/* CODE CATEGORY 2 END*/
 #endif
#endif

#ifdef DBK_ENABLE_EXT_RX_START
 #if ( kDbkNumberOfChannels > 1 )
/* CODE CATEGORY 2 START*/
extern void ApplDbkRxStart(CanChannelHandle channel);
/* CODE CATEGORY 2 END*/
 #else
/* CODE CATEGORY 2 START*/
extern void ApplDbkRxStart(void);
/* CODE CATEGORY 2 END*/
 #endif
#endif

#ifdef DBK_ENABLE_TX_CHANNEL_SPECIFIC
#ifdef DBK_ENABLE_EXT_TX_STOP
/* CODE CATEGORY 2 START*/
extern void ApplDbkTxStop(CanChannelHandle channel);
/* CODE CATEGORY 2 END*/
#endif
#else
#ifdef DBK_ENABLE_EXT_TX_STOP
/* CODE CATEGORY 2 START*/
extern void ApplDbkTxStop(void);
/* CODE CATEGORY 2 END*/
#endif
#endif

#ifdef DBK_ENABLE_EXT_RX_STOP
 #if ( kDbkNumberOfChannels > 1 )
/* CODE CATEGORY 2 START*/
extern void ApplDbkRxStop(CanChannelHandle channel);
/* CODE CATEGORY 2 END*/
 #else
/* CODE CATEGORY 2 START*/
extern void ApplDbkRxStop(void);
/* CODE CATEGORY 2 END*/
 #endif
#endif



/*==========================================================================*/
/* Prototypes for the evaluation-Functions                                   */
/*==========================================================================*/
#ifdef _NBIT_SIGNALE_AKTIV
#if defined ( NBIT_RX_EVALMODE_6_USED ) || defined ( NBIT_TX_EVALMODE_6_USED )
/* CODE CATEGORY 1 START*/
extern canuint8 dbkSignBitEval6(DbkSigHandleType SigHdl, canuint8 Value);
/* CODE CATEGORY 1 END*/
#else
#define dbkSignBitEval6 0
#endif
#endif

#ifdef _NBIT_BYTE_TX_SIGNALE_AKTIV
#if defined ( NBIT_TX_EVALMODE_0_USED ) || defined ( BYTE_TX_EVALMODE_0_USED )
/* CODE CATEGORY 2 START*/
extern canuint8 dbkTxSignBitByteEval0(DbkSigHandleType SigHdl, canuint8 Value);
/* CODE CATEGORY 2 END*/
#else
#define dbkTxSignBitByteEval0 0
#endif
#if defined ( NBIT_TX_EVALMODE_4_USED ) || defined ( BYTE_TX_EVALMODE_4_USED )
/* CODE CATEGORY 2 START*/
extern canuint8 dbkTxSignBitByteEval4(DbkSigHandleType SigHdl, canuint8 Value);
/* CODE CATEGORY 2 END*/
#else
#define dbkTxSignBitByteEval4 0
#endif
#endif

#ifdef _NBIT_TX_SIGNALE_AKTIV
#if defined ( NBIT_TX_EVALMODE_1_USED )
/* CODE CATEGORY 2 START*/
extern canuint8 dbkTxSignBitEval1(DbkSigHandleType SigHdl, canuint8 Value);
/* CODE CATEGORY 2 END*/
#else
#define dbkTxSignBitEval1 0
#endif
#if defined ( NBIT_TX_EVALMODE_2_USED )
/* CODE CATEGORY 2 START*/
extern canuint8 dbkTxSignBitEval2(DbkSigHandleType SigHdl, canuint8 Value);
/* CODE CATEGORY 2 END*/
#else
#define dbkTxSignBitEval2 0
#endif
#if defined ( NBIT_TX_EVALMODE_3_USED )
/* CODE CATEGORY 2 START*/
extern canuint8 dbkTxSignBitEval3(DbkSigHandleType SigHdl, canuint8 Value);
/* CODE CATEGORY 2 END*/
#else
#define dbkTxSignBitEval3 0
#endif
#if defined ( NBIT_TX_EVALMODE_5_USED )
/* CODE CATEGORY 2 START*/
extern canuint8 dbkTxSignBitEval5(DbkSigHandleType SigHdl, canuint8 Value);
/* CODE CATEGORY 2 END*/
#else
#define dbkTxSignBitEval5 0
#endif
#endif

#ifdef _NBIT_BYTE_RX_SIGNALE_AKTIV
#if defined ( NBIT_RX_EVALMODE_0_USED ) || defined ( BYTE_RX_EVALMODE_0_USED )
/* CODE CATEGORY 1 START*/
extern canuint8 dbkRxSignBitByteEval0(DbkSigHandleType SigHdl, canuint8 Value);
/* CODE CATEGORY 1 END*/
#else
#define dbkRxSignBitByteEval0 0
#endif
#if defined ( NBIT_RX_EVALMODE_4_USED ) || defined ( BYTE_RX_EVALMODE_4_USED )
/* CODE CATEGORY 1 START*/
extern canuint8 dbkRxSignBitByteEval4(DbkSigHandleType SigHdl, canuint8 Value);
/* CODE CATEGORY 1 END*/
#else
#define dbkRxSignBitByteEval4 0
#endif
#endif

#ifdef _NBIT_RX_SIGNALE_AKTIV
#if defined ( NBIT_RX_EVALMODE_1_USED )
/* CODE CATEGORY 1 START*/
extern canuint8 dbkRxSignBitEval1(DbkSigHandleType SigHdl, canuint8 Value);
/* CODE CATEGORY 1 END*/
#else
#define dbkRxSignBitEval1 0
#endif
#if defined ( NBIT_RX_EVALMODE_2_USED )
/* CODE CATEGORY 1 START*/
extern canuint8 dbkRxSignBitEval2(DbkSigHandleType SigHdl, canuint8 Value);
/* CODE CATEGORY 1 END*/
#else
#define dbkRxSignBitEval2 0
#endif
#if defined ( NBIT_RX_EVALMODE_3_USED )
/* CODE CATEGORY 1 START*/
extern canuint8 dbkRxSignBitEval3(DbkSigHandleType SigHdl, canuint8 Value);
/* CODE CATEGORY 1 END*/
#else
#define dbkRxSignBitEval3 0
#endif
#if defined ( NBIT_RX_EVALMODE_5_USED )
/* CODE CATEGORY 1 START*/
extern canuint8 dbkRxSignBitEval5(DbkSigHandleType SigHdl, canuint8 Value);
/* CODE CATEGORY 1 END*/
#else
#define dbkRxSignBitEval5 0
#endif
#endif

#ifdef _N16BIT_SIGNALE_AKTIV
#if defined ( N16BIT_RX_EVALMODE_6_USED )  || defined ( N16BIT_TX_EVALMODE_6_USED )
/* CODE CATEGORY 1 START*/
extern canuint8 dbkSign16BitEval6(DbkSigHandleType SigHdl, canuint16 Value);
/* CODE CATEGORY 1 END*/
#else
#define dbkSign16BitEval6 0
#endif
#endif

#ifdef _N16BIT_WORD_TX_SIGNALE_AKTIV
#if defined ( N16BIT_TX_EVALMODE_0_USED ) || defined ( WORD_TX_EVALMODE_0_USED )
/* CODE CATEGORY 2 START*/
extern canuint8 dbkTxSign16BitWordEval0(DbkSigHandleType SigHdl, canuint16 Value);
/* CODE CATEGORY 2 END*/
#else
#define dbkTxSign16BitWordEval0 0
#endif
#if defined ( N16BIT_TX_EVALMODE_4_USED ) || defined ( WORD_TX_EVALMODE_4_USED )
/* CODE CATEGORY 2 START*/
extern canuint8 dbkTxSign16BitWordEval4(DbkSigHandleType SigHdl, canuint16 Value);
/* CODE CATEGORY 2 END*/
#else
#define dbkTxSign16BitWordEval4 0
#endif
#endif

#ifdef _N16BIT_TX_SIGNALE_AKTIV
#if defined ( N16BIT_TX_EVALMODE_1_USED )
/* CODE CATEGORY 2 START*/
extern canuint8 dbkTxSign16BitEval1(DbkSigHandleType SigHdl, canuint16 Value);
/* CODE CATEGORY 2 END*/
#else
#define dbkTxSign16BitEval1 0
#endif
#if defined ( N16BIT_TX_EVALMODE_2_USED )
/* CODE CATEGORY 2 START*/
extern canuint8 dbkTxSign16BitEval2(DbkSigHandleType SigHdl, canuint16 Value);
/* CODE CATEGORY 2 END*/
#else
#define dbkTxSign16BitEval2 0
#endif
#if defined ( N16BIT_TX_EVALMODE_3_USED )
/* CODE CATEGORY 2 START*/
extern canuint8 dbkTxSign16BitEval3(DbkSigHandleType SigHdl, canuint16 Value);
/* CODE CATEGORY 2 END*/
#else
#define dbkTxSign16BitEval3 0
#endif
#if defined ( N16BIT_TX_EVALMODE_5_USED )
/* CODE CATEGORY 2 START*/
extern canuint8 dbkTxSign16BitEval5(DbkSigHandleType SigHdl, canuint16 Value);
/* CODE CATEGORY 2 END*/
#else
#define dbkTxSign16BitEval5 0
#endif
#endif

#ifdef _N16BIT_WORD_RX_SIGNALE_AKTIV
#if defined ( N16BIT_RX_EVALMODE_0_USED ) || defined ( WORD_RX_EVALMODE_0_USED )
/* CODE CATEGORY 1 START*/
extern canuint8 dbkRxSign16BitWordEval0(DbkSigHandleType SigHdl, canuint16 Value);
/* CODE CATEGORY 1 END*/
#else
#define dbkRxSign16BitWordEval0 0
#endif
#if defined ( N16BIT_RX_EVALMODE_4_USED ) || defined ( WORD_RX_EVALMODE_4_USED )
/* CODE CATEGORY 1 START*/
extern canuint8 dbkRxSign16BitWordEval4(DbkSigHandleType SigHdl, canuint16 Value);
/* CODE CATEGORY 1 END*/
#else
#define dbkRxSign16BitWordEval4 0
#endif
#endif

#ifdef _N16BIT_RX_SIGNALE_AKTIV
#if defined ( N16BIT_RX_EVALMODE_1_USED )
/* CODE CATEGORY 1 START*/
extern canuint8 dbkRxSign16BitEval1(DbkSigHandleType SigHdl, canuint16 Value);
/* CODE CATEGORY 1 END*/
#else
#define dbkRxSign16BitEval1 0
#endif
#if defined ( N16BIT_RX_EVALMODE_2_USED )
/* CODE CATEGORY 1 START*/
extern canuint8 dbkRxSign16BitEval2(DbkSigHandleType SigHdl, canuint16 Value);
/* CODE CATEGORY 1 END*/
#else
#define dbkRxSign16BitEval2 0
#endif
#if defined ( N16BIT_RX_EVALMODE_3_USED )
/* CODE CATEGORY 1 START*/
extern canuint8 dbkRxSign16BitEval3(DbkSigHandleType SigHdl, canuint16 Value);
/* CODE CATEGORY 1 END*/
#else
#define dbkRxSign16BitEval3 0
#endif
#if defined ( N16BIT_RX_EVALMODE_5_USED )
/* CODE CATEGORY 1 START*/
extern canuint8 dbkRxSign16BitEval5(DbkSigHandleType SigHdl, canuint16 Value);
/* CODE CATEGORY 1 END*/
#else
#define dbkRxSign16BitEval5 0
#endif
#endif

#ifdef _BYTE_SIGNALE_AKTIV
#if defined ( BYTE_RX_EVALMODE_6_USED ) || defined ( BYTE_TX_EVALMODE_6_USED )
/* CODE CATEGORY 1 START*/
extern canuint8 dbkSigByteEval6(DbkSigHandleType SigHdl, canuint8 Value);
/* CODE CATEGORY 1 END*/
#else
#define dbkSigByteEval6 0
#endif
#endif

#ifdef _BYTE_TX_SIGNALE_AKTIV
#if defined ( BYTE_TX_EVALMODE_1_USED )
/* CODE CATEGORY 2 START*/
extern canuint8 dbkTxSigByteEval1(DbkSigHandleType SigHdl, canuint8 Value);
/* CODE CATEGORY 2 END*/
#else
#define dbkTxSigByteEval1 0
#endif
#if defined ( BYTE_TX_EVALMODE_2_USED )
/* CODE CATEGORY 2 START*/
extern canuint8 dbkTxSigByteEval2(DbkSigHandleType SigHdl, canuint8 Value);
/* CODE CATEGORY 2 END*/
#else
#define dbkTxSigByteEval2 0
#endif
#if defined ( BYTE_TX_EVALMODE_3_USED )
/* CODE CATEGORY 2 START*/
extern canuint8 dbkTxSigByteEval3(DbkSigHandleType SigHdl, canuint8 Value);
/* CODE CATEGORY 2 END*/
#else
#define dbkTxSigByteEval3 0
#endif
#if defined ( BYTE_TX_EVALMODE_5_USED )
/* CODE CATEGORY 2 START*/
extern canuint8 dbkTxSigByteEval5(DbkSigHandleType SigHdl, canuint8 Value);
/* CODE CATEGORY 2 END*/
#else
#define dbkTxSigByteEval5 0
#endif
#endif

#ifdef _BYTE_RX_SIGNALE_AKTIV
#if defined ( BYTE_RX_EVALMODE_1_USED )
/* CODE CATEGORY 1 START*/
extern canuint8 dbkRxSigByteEval1(DbkSigHandleType SigHdl, canuint8 Value);
/* CODE CATEGORY 1 END*/
#else
#define dbkRxSigByteEval1 0
#endif
#if defined ( BYTE_RX_EVALMODE_2_USED )
/* CODE CATEGORY 1 START*/
extern canuint8 dbkRxSigByteEval2(DbkSigHandleType SigHdl, canuint8 Value);
/* CODE CATEGORY 1 END*/
#else
#define dbkRxSigByteEval2 0
#endif
#if defined ( BYTE_RX_EVALMODE_3_USED )
/* CODE CATEGORY 1 START*/
extern canuint8 dbkRxSigByteEval3(DbkSigHandleType SigHdl, canuint8 Value);
/* CODE CATEGORY 1 END*/
#else
#define dbkRxSigByteEval3 0
#endif
#if defined ( BYTE_RX_EVALMODE_5_USED )
/* CODE CATEGORY 1 START*/
extern canuint8 dbkRxSigByteEval5(DbkSigHandleType SigHdl, canuint8 Value);
/* CODE CATEGORY 1 END*/
#else
#define dbkRxSigByteEval5 0
#endif
#endif

#ifdef _WORD_SIGNALE_AKTIV
#if defined ( WORD_RX_EVALMODE_6_USED ) || defined ( WORD_TX_EVALMODE_6_USED )
/* CODE CATEGORY 1 START*/
extern canuint8 dbkSigWordEval6(DbkSigHandleType SigHdl, canuint16 Value);
/* CODE CATEGORY 1 END*/
#else
#define dbkSigWordEval6 0
#endif
#endif

#ifdef _WORD_TX_SIGNALE_AKTIV
#if defined ( WORD_TX_EVALMODE_1_USED )
/* CODE CATEGORY 2 START*/
extern canuint8 dbkTxSigWordEval1(DbkSigHandleType SigHdl, canuint16 Value);
/* CODE CATEGORY 2 END*/
#else
#define dbkTxSigWordEval1 0
#endif
#if defined ( WORD_TX_EVALMODE_2_USED )
/* CODE CATEGORY 2 START*/
extern canuint8 dbkTxSigWordEval2(DbkSigHandleType SigHdl, canuint16 Value);
/* CODE CATEGORY 2 END*/
#else
#define dbkTxSigWordEval2 0
#endif
#if defined ( WORD_TX_EVALMODE_3_USED )
/* CODE CATEGORY 2 START*/
extern canuint8 dbkTxSigWordEval3(DbkSigHandleType SigHdl, canuint16 Value);
/* CODE CATEGORY 2 END*/
#else
#define dbkTxSigWordEval3 0
#endif
#if defined ( WORD_TX_EVALMODE_5_USED )
/* CODE CATEGORY 2 START*/
extern canuint8 dbkTxSigWordEval5(DbkSigHandleType SigHdl, canuint16 Value);
/* CODE CATEGORY 2 END*/
#else
#define dbkTxSigWordEval5 0
#endif
#endif

#ifdef _WORD_RX_SIGNALE_AKTIV
#if defined ( WORD_RX_EVALMODE_1_USED )
/* CODE CATEGORY 1 START*/
extern canuint8 dbkRxSigWordEval1(DbkSigHandleType SigHdl, canuint16 Value);
/* CODE CATEGORY 1 END*/
#else
#define dbkRxSigWordEval1 0
#endif
#if defined ( WORD_RX_EVALMODE_2_USED )
/* CODE CATEGORY 1 START*/
extern canuint8 dbkRxSigWordEval2(DbkSigHandleType SigHdl, canuint16 Value);
/* CODE CATEGORY 1 END*/
#else
#define dbkRxSigWordEval2 0
#endif
#if defined ( WORD_RX_EVALMODE_3_USED )
/* CODE CATEGORY 1 START*/
extern canuint8 dbkRxSigWordEval3(DbkSigHandleType SigHdl, canuint16 Value);
/* CODE CATEGORY 1 END*/
#else
#define dbkRxSigWordEval3 0
#endif
#if defined ( WORD_RX_EVALMODE_5_USED )
/* CODE CATEGORY 1 START*/
extern canuint8 dbkRxSigWordEval5(DbkSigHandleType SigHdl, canuint16 Value);
/* CODE CATEGORY 1 END*/
#else
#define dbkRxSigWordEval5 0
#endif
#endif



#if defined ( _NBYTE_SIGNALE_AKTIV )
#if ((defined  NBYTE_RX_EVALMODE_6_USED ) || (defined  NBYTE_TX_EVALMODE_6_USED ))
/* CODE CATEGORY 1 START*/
extern canuint8 dbkSignByteEval6(DbkSigHandleType SigHdl, TxDataPtr pValue);
/* CODE CATEGORY 1 END*/
#else
#define dbkSignByteEval6 0
#endif
#endif

#if defined  ( _NBYTE_TX_SIGNALE_AKTIV )
#if defined  ( NBYTE_TX_EVALMODE_0_USED )
/* CODE CATEGORY 2 START*/
extern canuint8 dbkTxSignByteEval0(DbkSigHandleType SigHdl, TxDataPtr pValue);
/* CODE CATEGORY 2 END*/
#else
#define dbkTxSignByteEval0 0
#endif
#if defined ( NBYTE_TX_EVALMODE_1_USED )
/* CODE CATEGORY 2 START*/
extern canuint8 dbkTxSignByteEval1(DbkSigHandleType SigHdl, TxDataPtr pValue);
/* CODE CATEGORY 2 END*/
#else
#define dbkTxSignByteEval1 0
#endif
#if defined ( NBYTE_TX_EVALMODE_2_USED )
/* CODE CATEGORY 2 START*/
extern canuint8 dbkTxSignByteEval2(DbkSigHandleType SigHdl, TxDataPtr pValue);
/* CODE CATEGORY 2 END*/
#else
#define dbkTxSignByteEval2 0
#endif
#if defined ( NBYTE_TX_EVALMODE_3_USED )
/* CODE CATEGORY 2 START*/
extern canuint8 dbkTxSignByteEval3(DbkSigHandleType SigHdl, TxDataPtr pValue);
/* CODE CATEGORY 2 END*/
#else
#define dbkTxSignByteEval3 0
#endif
#if defined ( NBYTE_TX_EVALMODE_4_USED )
/* CODE CATEGORY 2 START*/
extern canuint8 dbkTxSignByteEval4(DbkSigHandleType SigHdl, TxDataPtr pValue);
/* CODE CATEGORY 2 END*/
#else
#define dbkTxSignByteEval4 0
#endif
#if defined ( NBYTE_TX_EVALMODE_5_USED )
/* CODE CATEGORY 2 START*/
extern canuint8 dbkTxSignByteEval5(DbkSigHandleType SigHdl, TxDataPtr pValue);
/* CODE CATEGORY 2 END*/
#else
#define dbkTxSignByteEval5 0
#endif
#endif

#if  defined ( _NBYTE_RX_SIGNALE_AKTIV )
#if defined ( NBYTE_RX_EVALMODE_0_USED )
/* CODE CATEGORY 1 START*/
extern canuint8 dbkRxSignByteEval0(DbkSigHandleType SigHdl, TxDataPtr pValue);
/* CODE CATEGORY 1 END*/
#else
#define dbkRxSignByteEval0 0
#endif
#if defined ( NBYTE_RX_EVALMODE_1_USED )
/* CODE CATEGORY 1 START*/
extern canuint8 dbkRxSignByteEval1(DbkSigHandleType SigHdl, TxDataPtr pValue);
/* CODE CATEGORY 1 END*/
#else
#define dbkRxSignByteEval1 0
#endif
#if defined ( NBYTE_RX_EVALMODE_2_USED )
/* CODE CATEGORY 1 START*/
extern canuint8 dbkRxSignByteEval2(DbkSigHandleType SigHdl, TxDataPtr pValue);
/* CODE CATEGORY 1 END*/
#else
#define dbkRxSignByteEval2 0
#endif
#if defined ( NBYTE_RX_EVALMODE_3_USED )
/* CODE CATEGORY 1 START*/
extern canuint8 dbkRxSignByteEval3(DbkSigHandleType SigHdl, TxDataPtr pValue);
/* CODE CATEGORY 1 END*/
#else
#define dbkRxSignByteEval3 0
#endif
#if defined ( NBYTE_RX_EVALMODE_4_USED )
/* CODE CATEGORY 1 START*/
extern canuint8 dbkRxSignByteEval4(DbkSigHandleType SigHdl, TxDataPtr pValue);
/* CODE CATEGORY 1 END*/
#else
#define dbkRxSignByteEval4 0
#endif
#if defined ( NBYTE_RX_EVALMODE_5_USED )
/* CODE CATEGORY 1 START*/
extern canuint8 dbkRxSignByteEval5(DbkSigHandleType SigHdl, TxDataPtr pValue);
/* CODE CATEGORY 1 END*/
#else
#define dbkRxSignByteEval5 0
#endif
#endif

/*==========================================================================*/
/* Prototypes for functions called by CAN driver                             */
/*==========================================================================*/

/* CODE CATEGORY 1 START*/
#ifdef DBK_ENABLE_MULTIPLE_PHYSICAL_LAYER
extern canuint8 DBK_API_CALL_TYPE dbkPrecopy(pChipDataPtr RDS, CanReceiveHandle rcvObject);
#endif
#ifdef MULTIPLE_RECEIVE_BUFFER
extern canuint8 DBK_INTERNAL_CALL_TYPE dbkPrecopy(pChipDataPtr RDS );
#endif
#ifdef SINGLE_RECEIVE_BUFFER
extern canuint8 DBK_INTERNAL_CALL_TYPE dbkPrecopy(CanReceiveHandle preParam);
#endif
#if defined( C_MULTIPLE_RECEIVE_CHANNEL ) || defined( C_SINGLE_RECEIVE_CHANNEL )
extern canuint8 DBK_INTERNAL_CALL_TYPE dbkPrecopy(CanRxInfoStructPtr preParam);
#endif
/* CODE CATEGORY 1 END*/
/* CODE CATEGORY 1 START*/
extern void DBK_INTERNAL_CALL_TYPE dbkConfirmation(CanTransmitHandle txObject);
/* CODE CATEGORY 1 END*/

/*==========================================================================*/
/* Functionspointer for the Functionsstructures                             */
/*==========================================================================*/
typedef DBK_API_CALLBACK_TYPE void (* ConfirmationFuncPtr)(void);
typedef DBK_API_CALLBACK_TYPE void (* IndicationFuncPtr)(void);
typedef DBK_API_CALLBACK_TYPE void (* TimeoutFuncPtr)(void);
#ifdef DBK_ENABLE_MULTIPLE_PHYSICAL_LAYER
typedef DBK_API_CALLBACK_TYPE canuint8 (*TransmitFctPtr ) (CanTransmitHandle  tmtObject); /* transmitfct    */
#endif

/* evaluation-Function */
typedef canuint8 (* EvalnBitFuncPtr)(DbkSigHandleType SigHdl, canuint8 Value);
typedef canuint8 (* Evaln16BitFuncPtr)(DbkSigHandleType SigHdl, canuint16 Value);
typedef canuint8 (* EvalByteFuncPtr)(DbkSigHandleType SigHdl, canuint8 Value);
typedef canuint8 (* EvalWordFuncPtr)(DbkSigHandleType SigHdl, canuint16 Value);
typedef canuint8 (* EvalnByteFuncPtr)(DbkSigHandleType SigHdl,TxDataPtr Value);



/*==========================================================================*/
/*Helpstructures to access as word or byte                                  */
/*==========================================================================*/
struct _c_byte2 {
  canuint8 _h;
  canuint8 _l;
};

union _c_WordByte {
  canuint16    w;
  struct _c_byte2  b;
};

/*==========================================================================*/
/* TX-Messages                                                              */
/*==========================================================================*/
/*----------------------------------------------------------*/

/*----------------------------------------------------------*/
typedef struct
{
  canbittype s_timer_mode           :1;  /*1=zyklisches senden*/
  canbittype s_timer                :1;  /*0=timer ist abgeschaltet senden nur ueber s_put*/
  canbittype s_delay                :1;  /*1=Mindesabstand zwischen Meldungen wird ueberwacht*/
  canbittype s_Msgconfirmation      :1;  /*1=Message enthaelt Signale, welche benachrichtigt werden*/
  canbittype s_demmand              :1;  /*for speceial sendtype (System-Diagnose)*/
  canbittype s_sofort               :1;  /*is true for messages with sendtype "sofort"*/
  canbittype unused                 :2;
}t_TxMsgAttributes;

/*==========================================================================*/
/* TX-Signals*/
/*==========================================================================*/
/*----------------------------------------------------------*/
/* Structure Definitions (common to all types)*/
/*----------------------------------------------------------*/
typedef struct
{
  canbittype s_mode                 :3;  /*Signalbewerter fuer Signalstate*/
  canbittype s_mode_sign            :1;  /*Vorzeichen fuer den Signalbewerter*/
  canbittype s_default              :1;  /*1=es wird anstatt den Anwenungs-Werten mit Defaultwerten gearbeitet*/
  canbittype s_put                  :1;  /*1=es wird bei wahrer Bewertung sofort gesendet*/
  canbittype s_confirmation         :1;  /*1=Signal wird bei erfolgreichem Senden benachrichtigt*/
  canbittype s_container_swap       :1;  /*byter order bus and CPU are different*/
}t_TxSigSwitch;


/*==========================================================================*/
/* RX-Messages*/
/*==========================================================================*/
/*----------------------------------------------------------*/
/* Structure Definitions*/
/*----------------------------------------------------------*/
typedef struct
{
  canbittype s_timer_timeout           :1;    /*1=Enthaelt Signale welche Timeout aktiviert haben*/
  canbittype s_Indication              :1;    /*1=der Anwender wird benachrichtigt*/
  canbittype s_Indication_timeout      :1;    /*1=der Anwender wird benachrichtigt/Timoeutbit ist aktiviert*/
  canbittype res                       :5;    /*temporary used for tool */
}t_RxMsgAttributes;

/*==========================================================================*/
/* RX-Signals*/
/*==========================================================================*/
/*----------------------------------------------------------*/
/* Signal Structure Definitions*/
/*----------------------------------------------------------*/
typedef struct
{
  canbittype s_mode               :3;  /*Signalbewerter fuer Signalstate*/
  canbittype s_mode_sign          :1;  /*Vorzeichen fuer den Signalbewerter*/
  canbittype s_indication         :1;  /*Ob Benachrichtigt werden soll*/
  canbittype s_timeout            :1;  /*timeout einer Message wird ueberwacht*/
  canbittype s_copydefault        :1;  /*bei Timeout den defaultwert setzen*/
  canbittype s_container_swap     :1;  /*byter order bus and CPU are different*/
}t_RxSigSwitch;



/*==========================================================================*/
/* evaluation-functions */
/*==========================================================================*/
/* ROM CATEGORY 1 START*/
V_MEMROM0 extern V_MEMROM1 EvalnBitFuncPtr    V_MEMROM2       CanTxnBitEvalFunctions[7];
/* ROM CATEGORY 1 END*/
/* ROM CATEGORY 1 START*/
V_MEMROM0 extern V_MEMROM1 EvalnBitFuncPtr    V_MEMROM2       CanRxnBitEvalFunctions[7];
/* ROM CATEGORY 1 END*/
/* ROM CATEGORY 1 START*/
V_MEMROM0 extern V_MEMROM1 Evaln16BitFuncPtr  V_MEMROM2       CanTxn16BitEvalFunctions[7];
/* ROM CATEGORY 1 END*/
/* ROM CATEGORY 1 START*/
V_MEMROM0 extern V_MEMROM1 Evaln16BitFuncPtr  V_MEMROM2       CanRxn16BitEvalFunctions[7];
/* ROM CATEGORY 1 END*/
/* ROM CATEGORY 1 START*/
V_MEMROM0 extern V_MEMROM1 EvalByteFuncPtr    V_MEMROM2       CanTxByteEvalFunctions[7];
/* ROM CATEGORY 1 END*/
/* ROM CATEGORY 1 START*/
V_MEMROM0 extern V_MEMROM1 EvalByteFuncPtr    V_MEMROM2       CanRxByteEvalFunctions[7];
/* ROM CATEGORY 1 END*/
/* ROM CATEGORY 1 START*/
V_MEMROM0 extern V_MEMROM1 EvalWordFuncPtr    V_MEMROM2       CanTxWordEvalFunctions[7];
/* ROM CATEGORY 1 END*/
/* ROM CATEGORY 1 START*/
V_MEMROM0 extern V_MEMROM1 EvalWordFuncPtr    V_MEMROM2       CanRxWordEvalFunctions[7];
/* ROM CATEGORY 1 END*/
/* ROM CATEGORY 1 START*/
V_MEMROM0 extern V_MEMROM1 EvalnByteFuncPtr   V_MEMROM2       CanTxnByteEvalFunctions[7];
/* ROM CATEGORY 1 END*/
/* ROM CATEGORY 1 START*/
V_MEMROM0 extern V_MEMROM1 EvalnByteFuncPtr   V_MEMROM2       CanRxnByteEvalFunctions[7];
/* ROM CATEGORY 1 END*/


#if (kDbkNumberOfTxObjects > 0)
/*==========================================================================*/
/* Tx-Messages (for all Signal-Types)*/
/*==========================================================================*/
/* ROM CATEGORY 2 START*/ 
V_MEMROM0 extern V_MEMROM1 canuint8  V_MEMROM2    DbkTxMsgECUMask[kDbkNumberOfTxObjects];
/* ROM CATEGORY 2 END*/
/* ROM CATEGORY 2 START*/ 
V_MEMROM0 extern V_MEMROM1 canuint16 V_MEMROM2    DbkTxMsgTimer1[kDbkNumberOfTxObjects];
/* ROM CATEGORY 2 END*/
#if defined( DBK_ENABLE_MSGTIMER_VARIANT_HANDLING )
/* ROM CATEGORY 2 START*/ 
V_MEMROM0 extern V_MEMROM1 canuint16 V_MEMROM2    DbkTxMsgTimer2[kDbkMsgCycleTimeVariants][kDbkNumberOfTxObjects];
/* ROM CATEGORY 2 END*/
#else
/* ROM CATEGORY 2 START*/ 
V_MEMROM0 extern V_MEMROM1 canuint16 V_MEMROM2    DbkTxMsgTimer2[kDbkNumberOfTxObjects];
/* ROM CATEGORY 2 END*/ 
#endif
/* ROM CATEGORY 2 START*/ 
V_MEMROM0 extern V_MEMROM1 canuint8  V_MEMROM2    DbkTxMsgDeltaT[kDbkNumberOfTxObjects];
/* ROM CATEGORY 2 END*/
/* ROM CATEGORY 2 START*/ 
V_MEMROM0 extern V_MEMROM1 canuint8  V_MEMROM2    DbkTxMsgNRepeat[kDbkNumberOfTxObjects];
/* ROM CATEGORY 2 END*/
/* ROM CATEGORY 1 START*/ 
V_MEMROM0 extern V_MEMROM1 t_TxMsgAttributes V_MEMROM2    DbkTxMsgAttributes[kDbkNumberOfTxObjects];
/* ROM CATEGORY 1 END*/
/* ROM CATEGORY 1 START*/ 
V_MEMROM0 extern V_MEMROM1 DbkSigHandleType  V_MEMROM2    DbkTxMsgDataOffset[kDbkNumberOfTxObjects+1];
/* ROM CATEGORY 1 END*/
#endif /*#if (kDbkNumberOfTxObjects > 0)*/

/* ROM CATEGORY 1 START*/ 
V_MEMROM0 extern V_MEMROM1 CanTransmitHandle V_MEMROM2    DbkTxMsgCanToDbkIndirection[kCanNumberOfTxObjects];
/* ROM CATEGORY 1 END*/ 

 
#if defined ( DBK_ENABLE_MULTIPLE_ECU )
/* ROM CATEGORY 1 START */
V_MEMROM0 extern V_MEMROM1 CanReceiveHandle    V_MEMROM2     DbkRxMsgCanToDbkIndirection[kDbkNumberOfNodes][kCanNumberOfRxObjects]; 
/* ROM CATEGORY 1 END */
#if (kDbkNumberOfTxObjects > 0)
/* ROM CATEGORY 1 START */
V_MEMROM0 extern V_MEMROM1 CanTransmitHandle   V_MEMROM2     DbkTxMsgDbkToCanIndirection[kDbkNumberOfNodes][kDbkNumberOfTxObjects];
/* ROM CATEGORY 1 END */
#endif /*#if (kDbkNumberOfTxObjects > 0)*/
#else 
#if (kDbkNumberOfTxObjects > 0)
/* ROM CATEGORY 1 START */
V_MEMROM0 extern V_MEMROM1 CanTransmitHandle   V_MEMROM2     DbkTxMsgDbkToCanIndirection[kDbkNumberOfTxObjects];
/* ROM CATEGORY 1 END */
#endif /*#if (kDbkNumberOfTxObjects > 0)*/
#endif
#if (kDbkNumberOfTxObjects > 0)
/* ROM CATEGORY 1 START */
V_MEMROM0 extern V_MEMROM1 DbkSignalStateType  V_MEMROM2     DbkTxMsgSignalStateOffset[kDbkNumberOfTxObjects+1];
/* ROM CATEGORY 1 END */ 
#endif /*#if (kDbkNumberOfTxObjects > 0)*/


/*==========================================================================*/
/* TX-Signals*/
/*==========================================================================*/
#if (kDbkNumberOfTxSignals > 0)
/* ROM CATEGORY 1 START */
V_MEMROM0 extern V_MEMROM1 DbkTxOffsetType    V_MEMROM2     DbkTxSigOffset[kDbkNumberOfTxSignals];
/* ROM CATEGORY 1 END */
/* ROM CATEGORY 1 START */
V_MEMROM0 extern V_MEMROM1 canuint16          V_MEMROM2     DbkTxSigMask[kDbkNumberOfTxSignals];
/* ROM CATEGORY 1 END */
/* ROM CATEGORY 1 START */
V_MEMROM0 extern V_MEMROM1 DbknByteOffsetType V_MEMROM2     DbkTxSigStartbit[kDbkNumberOfTxSignals];
/* ROM CATEGORY 1 END */
#endif /*#if (kDbkNumberOfTxSignals = 0)*/

#if (kDbkNumberOfTotalTxSignals > 0)
/* ROM CATEGORY 2 START */
V_MEMROM0 extern V_MEMROM1 CanTransmitHandle  V_MEMROM2     DbkTxSigMessageHdl[kDbkNumberOfTotalTxSignals];
/* ROM CATEGORY 2 END */
#endif /*#if (kDbkNumberOfTotalTxSignals > 0)*/


#if (kDbkNumberOfTxSignals > 0)
/* ROM CATEGORY 2 START */
V_MEMROM0 extern V_MEMROM1 canuint16  V_MEMROM2    DbkTxSigDefault[kDbkNumberOfTxSignals];
/* ROM CATEGORY 2 END */
/* ROM CATEGORY 1 START */ 
V_MEMROM0 extern V_MEMROM1 canuint16  V_MEMROM2    DbkTxSigX1[kDbkNumberOfTxSignals];
/* ROM CATEGORY 1 END */
/* ROM CATEGORY 1 START */ 
V_MEMROM0 extern V_MEMROM1 canuint16  V_MEMROM2    DbkTxSigX2[kDbkNumberOfTxSignals];
/* ROM CATEGORY 1 END */
#endif /*#if (kDbkNumberOfTxSignals > 0)*/

#if ( kDbkNumberOfTxXxX1Bytes > 0 )
/* ROM CATEGORY 1 START */ 
V_MEMROM0 extern V_MEMROM1 canuint8  V_MEMROM2     DbkTxSignByteX1Value[kDbkNumberOfTxXxX1Bytes];
/* ROM CATEGORY 1 END */
#endif
#if ( kDbkNumberOfTxXxX2Bytes > 0 )
/* ROM CATEGORY 1 START */ 
V_MEMROM0 extern V_MEMROM1 canuint8  V_MEMROM2     DbkTxSignByteX2Value[kDbkNumberOfTxXxX2Bytes];
/* ROM CATEGORY 1 END */
#endif

#if (kDbkNumberOfTxSignals > 0)
/* ROM CATEGORY 1 START */ 
V_MEMROM0 extern V_MEMROM1 t_TxSigSwitch  V_MEMROM2   DbkTxSigSwitch[kDbkNumberOfTxSignals];
/* ROM CATEGORY 1 END */
#endif /*#if (kDbkNumberOfTxSignals > 0)*/

#ifdef DBK_ENABLE_TX_CONF_FLAG
/* ROM CATEGORY 1 START */ 
V_MEMROM0 extern V_MEMROM1 canuint8  V_MEMROM2        DbkTxSigConfirmationOffset[kDbkNumberOfTxSignals];
/* ROM CATEGORY 1 END */
/* ROM CATEGORY 1 START */ 
V_MEMROM0 extern V_MEMROM1 canuint8  V_MEMROM2        DbkTxSigConfirmationMask[kDbkNumberOfTxSignals];
/* ROM CATEGORY 1 END */
#endif
#ifdef DBK_ENABLE_TX_CONF_FUNC
/* ROM CATEGORY 1 START */ 
V_MEMROM0 extern V_MEMROM1 ConfirmationFuncPtr  V_MEMROM2    DbkTxSigConfirmationFunc[kDbkNumberOfTxSignals];
/* ROM CATEGORY 1 END */
#endif

#if (kDbkNumberOfTxSignals > 0)
/* ROM CATEGORY 1 START */
V_MEMROM0 extern V_MEMROM1 DbkSignalStateType   V_MEMROM2    DbkTxSigSignalStateOffset[kDbkNumberOfTxSignals];
/* ROM CATEGORY 1 END */
/* ROM CATEGORY 1 START */ 
V_MEMROM0 extern V_MEMROM1 canuint8             V_MEMROM2    DbkTxSigSignalStateMask[kDbkNumberOfTxSignals];
/* ROM CATEGORY 1 END */
#endif /*#if (kDbkNumberOfTxSignals > 0)*/

#if defined ( TX_CONTAINER_GAPS_NBYTE)
/* ROM CATEGORY 1 START */ 
V_MEMROM0 extern V_MEMROM1 DbknByteOffsetType   V_MEMROM2    DbkTxSigMaskOffset[kDbkNumberOfTxSignals];
/* ROM CATEGORY 1 END */
 #if ( kDbkNumberOfTxXxBytes > 0 )
/* ROM CATEGORY 1 START */ 
V_MEMROM0 extern V_MEMROM1 canuint8             V_MEMROM2    DbkTxSignByteMask[kDbkNumberOfTxXxBytes];
/* ROM CATEGORY 1 END */
 #endif
#endif

#if defined ( RX_CONTAINER_GAPS_NBYTE)
/* ROM CATEGORY 1 START */ 
V_MEMROM0 extern V_MEMROM1 DbknByteOffsetType   V_MEMROM2    DbkRxSigMaskOffset[kDbkNumberOfRxSignals];
/* ROM CATEGORY 1 END */
 #if ( kDbkNumberOfRxXxBytes > 0 )
/* ROM CATEGORY 1 START */ 
V_MEMROM0 extern V_MEMROM1 canuint8             V_MEMROM2    DbkRxSignByteMask[kDbkNumberOfRxXxBytes];
/* ROM CATEGORY 1 END */
 #endif
#endif
#ifdef DBK_ENABLE_MULTIPLE_PHYSICAL_LAYER
/* ROM CATEGORY 2 START */
V_MEMROM0 extern V_MEMROM1 canuint8             V_MEMROM2    C_TX_Device_D[];  /*get device/medium for this msg.*/
/* ROM CATEGORY 2 END */
/* ROM CATEGORY 2 START */
V_MEMROM0 extern V_MEMROM1 TransmitFctPtr       V_MEMROM2    C_TX_TransmitFct_D[];
/* ROM CATEGORY 2 END */
#endif



/*----------------------------------------------------------*/
/* RX-Message Structures*/
/*----------------------------------------------------------*/
/* ROM CATEGORY 2 START */
V_MEMROM0 extern V_MEMROM1 canuint8             V_MEMROM2    DbkRxDbkMsgECUMask[kDbkNumberOfRxObjects];
/* ROM CATEGORY 2 END */
#if defined(DBK_ENABLE_MULTIPLE_ECU)
/* ROM CATEGORY 2 START */
V_MEMROM0 extern V_MEMROM1 canuint16            V_MEMROM2    DbkRxMsgDeltaT[kDbkNumberOfNodes][kDbkNumberOfRxObjects];
/* ROM CATEGORY 2 END */
#else
/* ROM CATEGORY 2 START */
V_MEMROM0 extern V_MEMROM1 canuint16            V_MEMROM2    DbkRxMsgDeltaT[kDbkNumberOfRxObjects];
/* ROM CATEGORY 2 END */
#endif
/* ROM CATEGORY 2 START */
V_MEMROM0 extern V_MEMROM1 canuint16            V_MEMROM2    DbkRxMsgTCycle[kDbkNumberOfRxObjects];
/* ROM CATEGORY 2 END */ 
/* ROM CATEGORY 1 START */
V_MEMROM0 extern V_MEMROM1 t_RxMsgAttributes    V_MEMROM2    DbkRxMsgAttributes[kDbkNumberOfRxObjects];
/* ROM CATEGORY 1 END */
/* ROM CATEGORY 2 START */
V_MEMROM0 extern V_MEMROM1 DbkSigHandleType     V_MEMROM2    DbkRxMsgDataOffset[kDbkNumberOfRxObjects+1];
/* ROM CATEGORY 2 END */
#ifdef DBK_ENABLE_TX_TASKSPLIT
/* ROM CATEGORY 1 START */ 
V_MEMROM0 extern V_MEMROM1 CanTransmitHandle    V_MEMROM2    DbkTxMsgStartIndex[kDbkNumberOfChannels][kDbkNumberOfTxTasks+1];
/* ROM CATEGORY 1 END */
#else
/* ROM CATEGORY 1 START */ 
V_MEMROM0 extern V_MEMROM1 CanTransmitHandle    V_MEMROM2    DbkTxMsgStartIndex[kDbkNumberOfChannels+1];
/* ROM CATEGORY 1 END */
#endif
 

/*----------------------------------------------------------*/
/* Signal Structure Definitions*/
/*----------------------------------------------------------*/
/* ROM CATEGORY 2 START */
V_MEMROM0 extern V_MEMROM1 canuint32            V_MEMROM2    DbkRxSigUID[kDbkNumberOfRxSignals];
/* ROM CATEGORY 2 END */
/* ROM CATEGORY 1 START */
V_MEMROM0 extern V_MEMROM1 DbkRxOffsetType      V_MEMROM2    DbkRxSigOffset[kDbkNumberOfRxSignals];
/* ROM CATEGORY 1 END */
/* ROM CATEGORY 2 START */
V_MEMROM0 extern V_MEMROM1 canuint8             V_MEMROM2    DbkRxSigBytePos[kDbkNumberOfRxSignals];
/* ROM CATEGORY 2 END */
/* ROM CATEGORY 1 START */ 
V_MEMROM0 extern V_MEMROM1 canuint16            V_MEMROM2    DbkRxSigMask[kDbkNumberOfRxSignals];
/* ROM CATEGORY 1 END */ 
/* ROM CATEGORY 1 START */
V_MEMROM0 extern V_MEMROM1 DbknByteOffsetType   V_MEMROM2    DbkRxSigStartbit[kDbkNumberOfRxSignals];
/* ROM CATEGORY 1 END */ 
/* ROM CATEGORY 1 START */
V_MEMROM0 extern V_MEMROM1 canuint8             V_MEMROM2    DbkRxSigType[kDbkNumberOfRxSignals];
/* ROM CATEGORY 1 END */ 
/* ROM CATEGORY 1 START */
V_MEMROM0 extern V_MEMROM1 canuint16            V_MEMROM2    DbkRxSigX1[kDbkNumberOfRxSignals];
/* ROM CATEGORY 1 END */ 
/* ROM CATEGORY 1 START */
V_MEMROM0 extern V_MEMROM1 canuint16            V_MEMROM2    DbkRxSigX2[kDbkNumberOfRxSignals];
/* ROM CATEGORY 1 END */ 
#if ( kDbkNumberOfRxXxX1Bytes > 0 )
/* ROM CATEGORY 1 START */
V_MEMROM0 extern V_MEMROM1 canuint8             V_MEMROM2    DbkRxSignByteX1Value[kDbkNumberOfRxXxX1Bytes];
/* ROM CATEGORY 1 END */ 
#endif
#if ( kDbkNumberOfRxXxX2Bytes > 0 )
/* ROM CATEGORY 1 START */
V_MEMROM0 extern V_MEMROM1 canuint8             V_MEMROM2    DbkRxSignByteX2Value[kDbkNumberOfRxXxX2Bytes];
/* ROM CATEGORY 1 END */ 
#endif
/* ROM CATEGORY 1 START */
V_MEMROM0 extern V_MEMROM1 t_RxSigSwitch        V_MEMROM2    DbkRxSigSwitch[kDbkNumberOfRxSignals];
/* ROM CATEGORY 1 END */ 
#if defined( DBK_ENABLE_RX_IND_FLAG ) || defined( DBK_ENABLE_RX_IND_FUNC )
/* ROM CATEGORY 1 START */
V_MEMROM0 extern V_MEMROM1 canuint8             V_MEMROM2    DbkRxSigIndicationOffset[kDbkNumberOfRxSignals];
/* ROM CATEGORY 1 END */ 
/* ROM CATEGORY 1 START */
V_MEMROM0 extern V_MEMROM1 canuint8             V_MEMROM2    DbkRxSigIndicationMask[kDbkNumberOfRxSignals];
/* ROM CATEGORY 1 END */ 
#endif
#if defined(DBK_ENABLE_RX_TIMEOUT_FLAG )
/* ROM CATEGORY 1 START */
V_MEMROM0 extern V_MEMROM1 canuint8             V_MEMROM2    DbkRxSigTimeoutOffset[kDbkNumberOfRxSignals];
/* ROM CATEGORY 1 END */ 
/* ROM CATEGORY 1 START */
V_MEMROM0 extern V_MEMROM1 canuint8             V_MEMROM2    DbkRxSigTimeoutMask[kDbkNumberOfRxSignals];
/* ROM CATEGORY 1 END */ 
#endif
#ifdef DBK_ENABLE_RX_IND_FUNC
/* ROM CATEGORY 1 START */
V_MEMROM0 extern V_MEMROM1 IndicationFuncPtr    V_MEMROM2    DbkRxSigIndicationFunc[kDbkNumberOfRxSignals];
/* ROM CATEGORY 1 END */ 
#endif
#ifdef DBK_ENABLE_RX_TIMEOUT_FUNC
/* ROM CATEGORY 1 START */
V_MEMROM0 extern V_MEMROM1 TimeoutFuncPtr       V_MEMROM2    DbkRxSigTimeoutFunc[kDbkNumberOfRxSignals];
/* ROM CATEGORY 1 END */ 
#endif
#ifdef DBK_ENABLE_RX_TASKSPLIT
/* ROM CATEGORY 1 START */
V_MEMROM0 extern V_MEMROM1 CanReceiveHandle     V_MEMROM2    DbkRxMsgStartIndex[kDbkNumberOfChannels][kDbkNumberOfRxTasks+1];
/* ROM CATEGORY 1 END */ 
#else
/* ROM CATEGORY 1 START */
V_MEMROM0 extern V_MEMROM1 CanReceiveHandle     V_MEMROM2    DbkRxMsgStartIndex[kDbkNumberOfChannels+1];
/* ROM CATEGORY 1 END */ 
#endif

/* ROM CATEGORY 4 START */ 
#if defined (DBK_ENABLE_MSGTIMER_VARIANT_HANDLING)
V_MEMROM0 extern V_MEMROM1 vuint8 V_MEMROM2 DbkVariantIndirection[kVNumberOfVariants];
#endif
/* ROM CATEGORY 4 END */ 




/*==========================================================================*/
/* Common-Messages-Structures (for all Signal-Types)*/
/*==========================================================================*/
/* ROM CATEGORY 3 START */
V_MEMROM0 extern V_MEMROM1 canuint8             V_MEMROM2    DbkMsgDefault[kDbkNumberOfBytesEx];
/* ROM CATEGORY 3 END */

/*************************************************************/
/* Variables                                                 */
/*************************************************************/
#if defined(V_ENABLE_USED_GLOBAL_VAR)
# if defined( MAKE_DEPEND )
# else
#  define __XGATE_CHECK_VAR__ __TRGT__[0]
#  if(__XGATE_CHECK_VAR__ == 'X')
#  else
#   pragma space [] @gpage
#  endif
# endif
# endif

/* RAM CATEGORY 2 START*/
extern canuint8  CanSignalsEx[kDbkNumberOfBytesEx]; 
/* RAM CATEGORY 2 END*/

#if defined(V_ENABLE_USED_GLOBAL_VAR)
# if defined( MAKE_DEPEND )
# else
#  define __XGATE_CHECK_VAR__ __TRGT__[0]
#  if(__XGATE_CHECK_VAR__ == 'X')
#  else
#   pragma space []
#  endif
# endif
# endif
#ifdef DBK_ENABLE_TX_CONF_FLAG
/* RAM CATEGORY 1 START*/
extern DBK_MEMORY_FAST  union DbkConfirmationBits DbkTxConfirmationFlags;/*bits to tell the Application the Message was sent*/
/* RAM CATEGORY 1 END*/
#endif
#ifdef DBK_ENABLE_RX_IND_FLAG 
/* RAM CATEGORY 1 START*/
extern DBK_MEMORY_FAST  union DbkIndicationBits DbkRxIndicationFlags;/*bits to tell the Application the receive a Message*/
/* RAM CATEGORY 1 END*/
#endif
#ifdef DBK_ENABLE_RX_TIMEOUT_FLAG
/* RAM CATEGORY 1 START*/
extern DBK_MEMORY_FAST  union DbkTimeoutBits  DbkRxTimeoutFlags;/*bits to tell the Application the Timeout for a receive-message*/
/* RAM CATEGORY 1 END*/
#endif


/*************************************************************/
/* Functions for send objects                               */
/*************************************************************/
/* CODE CATEGORY 4 START*/
void DBK_API_CALL_TYPE dbkTxMessageStart(vuint16 TxStartDelay, vuintx MsgHdl);
/* CODE CATEGORY 4 END*/
/* CODE CATEGORY 4 START*/
void  DBK_API_CALL_TYPE dbkInit(void);
/* CODE CATEGORY 4 END*/
#if ( kDbkNumberOfChannels > 1 )
# ifdef DBK_ENABLE_TX_TASKSPLIT
/* CODE CATEGORY 2 START*/
void  DBK_API_CALL_TYPE dbkTxTask( canuint8 channel, canuint8 subtask );
/* CODE CATEGORY 2 END*/
# else
/* CODE CATEGORY 2 START*/
void  DBK_API_CALL_TYPE dbkTxTask( canuint8 channel );
/* CODE CATEGORY 2 END*/
# endif
# ifdef DBK_ENABLE_RX_TASKSPLIT
/* CODE CATEGORY 2 START*/
void  DBK_API_CALL_TYPE dbkRxTask( canuint8 channel, canuint8 subtask );
/* CODE CATEGORY 2 END*/
# else
/* CODE CATEGORY 2 START*/
void  DBK_API_CALL_TYPE dbkRxTask( canuint8 channel );
/* CODE CATEGORY 2 END*/
# endif
#else
# ifdef DBK_ENABLE_TX_TASKSPLIT
/* CODE CATEGORY 2 START*/
void  DBK_API_CALL_TYPE dbkTxTask( canuint8 subtask );
/* CODE CATEGORY 2 END*/
# else
/* CODE CATEGORY 2 START*/
void  DBK_API_CALL_TYPE dbkTxTask(void);
/* CODE CATEGORY 2 END*/
# endif
# ifdef DBK_ENABLE_RX_TASKSPLIT
/* CODE CATEGORY 2 START*/
void  DBK_API_CALL_TYPE dbkRxTask( canuint8 subtask );
/* CODE CATEGORY 2 END*/
# else
/* CODE CATEGORY 2 START*/
void  DBK_API_CALL_TYPE dbkRxTask(void);
/* CODE CATEGORY 2 END*/
# endif
#endif

/* CODE CATEGORY 4 START*/
unsigned char DBK_API_CALL_TYPE dbkGetSignalState(DbkSigHandleType SigHdl);
/* CODE CATEGORY 4 END*/
/*==========================================================================*/
/*Prototyp fuer dbkTransmit*/
/*==========================================================================*/
/* CODE CATEGORY 1 START*/
canuint8 dbkTransmit(CanTransmitHandle MsgHdl);
/* CODE CATEGORY 1 END*/

/*************************************************************/
/* signal-access-Functions for send objects                  */
/*************************************************************/
#ifdef _NBIT_TX_SIGNALE_AKTIV
/* CODE CATEGORY 2 START*/
canuint8 DBK_API_CALL_TYPE dbkGetTxnBit(DbkSigHandleType SigHdl);
/* CODE CATEGORY 2 END*/
/* CODE CATEGORY 2 START*/
void DBK_API_CALL_TYPE dbkPutnBit(DbkSigHandleType SigHdl, canuint8 Value);
/* CODE CATEGORY 2 END*/
# if defined(DBK_ENABLE_OPTIMIZE_TX_PUT)
/* CODE CATEGORY 2 START*/
void DBK_API_CALL_TYPE dbkPutnBitCyclic(DbkSigHandleType SigHdl, canuint8 Value);
/* CODE CATEGORY 2 END*/
# endif
#endif

#ifdef _N16BIT_TX_SIGNALE_AKTIV
/* CODE CATEGORY 2 START*/
canuint16 DBK_API_CALL_TYPE dbkGetTxn16Bit(DbkSigHandleType SigHdl);
/* CODE CATEGORY 2 END*/
/* CODE CATEGORY 2 START*/
void DBK_API_CALL_TYPE dbkPutn16Bit(DbkSigHandleType SigHdl, canuint16 Value);
/* CODE CATEGORY 2 END*/
# if defined(DBK_ENABLE_OPTIMIZE_TX_PUT)
/* CODE CATEGORY 2 START*/
void DBK_API_CALL_TYPE dbkPutn16BitCyclic(DbkSigHandleType SigHdl, canuint16 Value);
/* CODE CATEGORY 2 END*/
# endif
#endif

/* CODE CATEGORY 2 START*/
canuint8 DBK_API_CALL_TYPE dbkGetTxByte(DbkSigHandleType SigHdl);
/* CODE CATEGORY 2 END*/
#ifdef _BYTE_TX_SIGNALE_AKTIV
/* CODE CATEGORY 2 START*/
void DBK_API_CALL_TYPE dbkPutByte(DbkSigHandleType SigHdl, canuint8 Value);
/* CODE CATEGORY 2 END*/
# if defined(DBK_ENABLE_OPTIMIZE_TX_PUT)
/* CODE CATEGORY 2 START*/
void DBK_API_CALL_TYPE dbkPutByteCyclic(DbkSigHandleType SigHdl, canuint8 Value);
/* CODE CATEGORY 2 END*/
# endif
#endif

/* CODE CATEGORY 2 START*/
canuint16 DBK_API_CALL_TYPE dbkGetTxWord(DbkSigHandleType SigHdl);
/* CODE CATEGORY 2 END*/
#ifdef _WORD_TX_SIGNALE_AKTIV
/* CODE CATEGORY 2 START*/
void DBK_API_CALL_TYPE dbkPutWord(DbkSigHandleType SigHdl, canuint16 Value);
/* CODE CATEGORY 2 END*/
# if defined(DBK_ENABLE_OPTIMIZE_TX_PUT)
/* CODE CATEGORY 2 START*/
void DBK_API_CALL_TYPE dbkPutWordCyclic(DbkSigHandleType SigHdl, canuint16 Value);
/* CODE CATEGORY 2 END*/
# endif
#endif


#ifdef _NBYTE_TX_SIGNALE_AKTIV
/* CODE CATEGORY 2 START*/
TxDataPtr DBK_API_CALL_TYPE dbkGetTxnByte(DbkSigHandleType SigHdl);
/* CODE CATEGORY 2 END*/
/* CODE CATEGORY 2 START*/
void DBK_API_CALL_TYPE  dbkPutnByte(DbkSigHandleType SigHdl, TxDataPtr pValue);
/* CODE CATEGORY 2 END*/
# if defined(DBK_ENABLE_OPTIMIZE_TX_PUT)
/* CODE CATEGORY 2 START*/
void DBK_API_CALL_TYPE  dbkPutnByteCyclic(DbkSigHandleType SigHdl, TxDataPtr pValue);
/* CODE CATEGORY 2 END*/
# endif
#endif

/*************************************************************/
/* Signal-access-Functions for receive objects               */
/*************************************************************/
#ifdef _NBIT_RX_SIGNALE_AKTIV
/* CODE CATEGORY 2 START*/
canuint8 DBK_API_CALL_TYPE dbkGetRxnBit(DbkSigHandleType SigHdl);
/* CODE CATEGORY 2 END*/
#endif
#ifdef _N16BIT_RX_SIGNALE_AKTIV
/* CODE CATEGORY 2 START*/
canuint16 DBK_API_CALL_TYPE dbkGetRxn16Bit(DbkSigHandleType SigHdl);
/* CODE CATEGORY 2 END*/
#endif
#ifdef _BYTE_RX_SIGNALE_AKTIV
/* CODE CATEGORY 2 START*/
canuint8 DBK_API_CALL_TYPE dbkGetRxByte(DbkSigHandleType SigHdl);
/* CODE CATEGORY 2 END*/
#endif
#ifdef _WORD_RX_SIGNALE_AKTIV
/* CODE CATEGORY 2 START*/
canuint16 DBK_API_CALL_TYPE dbkGetRxWord(DbkSigHandleType SigHdl);
/* CODE CATEGORY 2 END*/
#endif
#ifdef _NBYTE_RX_SIGNALE_AKTIV
/* CODE CATEGORY 2 START*/
# if defined(V_ENABLE_USED_GLOBAL_VAR)
@far @gpage canuint8 *  dbkGetRxnByte(DbkSigHandleType SigHdl);
# else
canuint8 * DBK_API_CALL_TYPE dbkGetRxnByte(DbkSigHandleType SigHdl);
# endif
/* CODE CATEGORY 2 END*/
#endif
#ifdef _BYTE_PUTRX_AKTIV
/* CODE CATEGORY 2 START*/
void DBK_API_CALL_TYPE dbkPutRxByte(DbkSigHandleType SigHdl, canuint8 value);
/* CODE CATEGORY 2 END*/
#endif
#ifdef _WORD_PUTRX_AKTIV
/* CODE CATEGORY 2 START*/
void DBK_API_CALL_TYPE dbkPutRxWord(DbkSigHandleType SigHdl, canuint16 value);
/* CODE CATEGORY 2 END*/
#endif
#ifdef _NBYTE_PUTRX_AKTIV
/* CODE CATEGORY 2 START*/
void DBK_API_CALL_TYPE dbkPutRxnByte(DbkSigHandleType SigHdl, TxDataPtr value);
/* CODE CATEGORY 2 END*/
/* CODE CATEGORY 2 START*/
void DBK_API_CALL_TYPE dbkPutRxnByteInternal(DbkSigHandleType SigHdl, V_MEMROM1 vuint8 V_MEMROM2 V_MEMROM3* value);
/* CODE CATEGORY 2 END*/
#endif

/*==========================================================================*/
/* Start and Stop DBKOM*/
/*==========================================================================*/
#if ( kDbkNumberOfChannels > 1 )  /* multichannel */
/* CODE CATEGORY 4 START*/
void DBK_API_CALL_TYPE dbkRxStart( CanChannelHandle channel );
/* CODE CATEGORY 4 END*/
/* CODE CATEGORY 4 START*/
void DBK_API_CALL_TYPE dbkRxStop( CanChannelHandle channel );
/* CODE CATEGORY 4 END*/
# ifdef DBK_ENABLE_TX_CHANNEL_SPECIFIC
/* CODE CATEGORY 4 START*/
void DBK_API_CALL_TYPE dbkTxStart( CanChannelHandle channel );
/* CODE CATEGORY 4 END*/
/* CODE CATEGORY 4 START*/
void DBK_API_CALL_TYPE dbkTxStop( CanChannelHandle channel );
/* CODE CATEGORY 4 END*/
# else
/* CODE CATEGORY 4 START*/
void DBK_API_CALL_TYPE dbkTxStart(void);
/* CODE CATEGORY 4 END*/
/* CODE CATEGORY 4 START*/
void DBK_API_CALL_TYPE dbkTxStop(void);
/* CODE CATEGORY 4 END*/
# endif
#else
/* CODE CATEGORY 4 START*/
void DBK_API_CALL_TYPE dbkRxStart(void);
/* CODE CATEGORY 4 END*/
/* CODE CATEGORY 4 START*/
void DBK_API_CALL_TYPE dbkRxStop(void);
/* CODE CATEGORY 4 END*/
/* CODE CATEGORY 4 START*/
void DBK_API_CALL_TYPE dbkTxStart(void);
/* CODE CATEGORY 4 END*/
/* CODE CATEGORY 4 START*/
void DBK_API_CALL_TYPE dbkTxStop(void);
/* CODE CATEGORY 4 END*/
#endif

/*==========================================================================*/
/* Fehlermeldungen*/
/*==========================================================================*/
#if defined ( DBK_ENABLE_HARDWARE_CHECK ) || \
    defined ( DBK_ENABLE_USER_CHECK )     || \
    defined ( DBK_ENABLE_GEN_CHECK )      || \
    defined ( DBK_ENABLE_INTERNAL_CHECK )
/* CODE CATEGORY 4 START*/
void  DBK_API_CALLBACK_TYPE   ApplDbkFatalError( canuint8 errorNumber );
/* CODE CATEGORY 4 END*/
#endif

#endif

