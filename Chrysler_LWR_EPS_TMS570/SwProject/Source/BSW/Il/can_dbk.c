/*****************************************************************************
| Project Name: FLEXKOM            (flexible communication for CAN)
|    File Name: can_dbk.c          (functions)
|
|  Description: can_dbk.c contains all Flexkom-Functions to handle the
|               bit/nbit, byte, n16bit, word and nbyte-Signals
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
| Bd           Steffen Braendle          Vector Informatik GmbH
| Gz           Oliver Garnatz            Vector Informatik GmbH
| Fz           Ralf Fritz                Vector Informatik GmbH
| Ml           Patrick Markl             Vector Informatik GmbH
| Rna          Ruediger Naas             Vector Informatik GmbH
| Agh          Alexander Gronbach        Vector Informatik GmbH
|-----------------------------------------------------------------------------
|               R E V I S I O N   H I S T O R Y
|-----------------------------------------------------------------------------
| Date         Ver  Author  Description
| ---------   ---  ------  --------------------------------------------------
|31-Mar-98    1.00  Rn    Auslieferung
|22-Mai-98    1.01  Rn    Erweiterungen fuer HC12 Cosmic Version 4.2a
|27-Mai-98    1.10  Rn    Erweiterungen fuer Mehrkanaligen Can-Treiber
|28-Mai-98    1.11  Rn    bugfix: kCanTxT1T2 war mit kCanTxSendImmdt vertauscht
|01-Jul-98    1.12  Rn    Anpassungen an das Tool Version 1.02
|07-Jul-98    1.13E Rn    Anpassungen an das Tool Version 1.03, 2.05
|                         dbkStart und dbkStop
|                         default-Wert bei Timeout
|                         in Empfangspuffer schreiben
|                         Mehrfachsteuergeraete
|                         Interruptsperrung
|11-Aug-98    1.14  Rn    bugfix: dbkPutnBit CanRxSigMask anstatt CanTxSigMask
|                         bugfix: CanInterruptDisable
|                         Datenkonsistenz auch bei dbkGetTx
|                         Anpassungen fuer Mehrfachsteuergeraete
|24-Mar-99    1.15  Rn    more than 255 Receive-Signale possible
|                         bugfix: Timeoutflags without Timeout-Function possible
|                         bugfix: dbkConfirmation for multiple ECU
|                         uint->canuint
|                         MULTIPLE_RECEIVE_BUFFER and SINGLE_RECEIVE_BUFFER
|                         Indirection in dbkPrecopy/dbkIndication
|                         byteaccess for word-signals
|30-Mar-99    1.16  Bd    signal evaluation functions for NBYTE signals added
|                   Rn    support TITUS
|                         force Indication if timeout
|                   Bd    dbkom structures CanXXX renamed into DbkXXX
|                         dbkStart/dbkStop functions divided into dbkTx/RxStart and
|                         dbkTx/RxStop function
|21-Mai-99    1.17  Bd    defines for used evalfunctions and switch
|                         C_ENABLE_PRODUCTION added
|                   Bd/Rn mask for containersignals
|                   Rn    delete reset of signalstate in dbkPut
|28-Jun-99    1.18  Rn    undo the delete reset of signalstate in dbkPut
|14-Okt-99    1.19  Rn    call dbkRxPutByte, dbkRxPutWord shift the parameter
|                   Bd    brackets added in defines for CANFLEX == 3
|                   Bd    Code for switch C_ENABLE_MULTIPLE_ECU_RCV_OPT added
|                   Bd/Rn changes in dbkPrecopy for N16Bit Signals with BYTE_ACCESS
|                         ifdef switches for optimized dbkGetTxWord function added
|                         ifdef switches for optimized dbkConfirmation function added
|17-Jan-99    1.20  Rn    support new controller
|                         optimize dbkRxTask
|                         save dataconsitency in dbkRxTask
|                         index depends of Controllertype
|                         optimize nByte-signal evaluation
|                         dbkRxStart: only initialize if stoped
|                         insert messurement-points
|                         optimize for nec-controller
|                   Bd    rom pointers in the eval functions changed to MEMORY_ROM
|                         define variables only when really used
|                   Rn    adaption to lint
|18-Apr-00    1.21  Gz    support FUJITSU 16LX controller
|15-Mai-00    1.22a Rn    results of Codereview
|10-Jun-00    1.23  Rn    bugfix for multipleECU: dbkRxTask
|21-Aug-00    1.24  Rn    optimize in dbkIndication
|                   Rn    integrate dbkIndication in dbkPrecopy
|                   Mr    modify CanTxSignalState
|                   Bd    ZEROPAGE_FOR_DATA switch removed
|                         indirection in dbkTransmit and reindirection in dbkConfirmation
|                         MULTIPLE_RECEIVE_CHANNEL renamed into C_MULTIPLE_RECEIVE_CHANNEL
|                   Rn    support multichannel
|14-Nov-00    1.25  Bd    support new controller C_COMP_DIABDATA_MCORE
|04-Dec-00    1.26  Gz    support new controller C_COMP_MITSUBISHI_M16C
|                         added DBK_PTR_FAR_CAST to get a cast into far memory
|                         added DBK_DUMMY_STATEMENT to avoid compiler warnings
|31-Jan-2001  1.27  Rn    support multipleECU with with DbkomGen > 2.02
|                   Mr    additional corrections for MULT.ECU-USE with DBKOMGEN > 2.02
|                   Mr    2 fixed in dbkConfirmation() and dbkTransmit() for MULT.ECU-USE
|                   Bd    kCanNumberOfChannels renamed into kDbkNumberOfChannels
|20-Feb-2001  1.28  Fz    Byte access for V850 added
|01-Mar-2001  1.29  Gz    support new controller C_COMP_IAR_M16C
|04-Apr-2001  1.30  Gz    support new controller C_COMP_IAR_78K0
|28-Jun-2001  1.31  Rn    ESCAN00000897: dbkGetSignalState() 
|                   Rn    ESCAN00000466: access to can-driver-structures 
|                   Rn    pragma for M16C IAR
|13-Jul-2001  1.32  Rn    no changes
|24-Jul-2001  1.33  Gz    Replace of memcpy for M16C IAR
|25-Jul-2001  1.34  Ml    casts for cosmic-compiler with -pck-check
|14-Sep-2001  1.35  Ml    Message indication flags are set in dbkprecopy. This
|                         was inserted for the message gateway 
|05-Oct-2001  1.36  Sa    ESCAN00001544: Cast operator fixed.
|                   Rn    Set Msg-Indication-Flag in case.of timeout
|                   Fz    M16C memcopy prototype removed for other compilers
|23-Nov-2001  1.37  Rn    ESCAN00002022: Support C_SINGLE_RECEIVE_CHANNEL
|                   Rn    ESCAN00001831: access to flags changed
|30-Nov-2001  1.38  Ml    DBK_DUMMY_STATEMENT not used in case of 
|                         C_COMP_DIABDATA_MCORE
|                   Rn    ESCAN00001907: dbkTxStart/dbkTxStop channelspecific
|                   Rn    ESCAN00001759: enter DBK_DBKOM_INTERNAL
|                   Rn    ESCAN00001855: enter DBK_API_CALL_TYPE 
|                   Rn    ESCAN00002021: each # in first column
|15-Feb-2001  1.39  Rn    ESCAN00002020: support INTEL/MOTOROLA
|                         ESCAN00002071: save dataconsistency in dbkGetTxWord
|                         ESCAN00002072: byteaccess in dbkGetn16Bit
|                         ESCAN00002299: support new Controller
|                         ESCAN00001932: support new Controller
|                         ESCAN00002127: kDbkBugFixVersion
|                         ESCAN00002356: wrong default values on timeout (nByte signals)
|01-Mar-2002 1.40   Fz    ESCAN00002403: Failure in selective start of channel
|                                        removed
|14-Mar-2002 1.41   Rn    ESCAN00002486: set Canindication in Timeout too
|04-Apr-2002 1.42   Rn    ESCAN00002486: rejected
|                   Rn    ESCAN00002635: save dataconsitency
|12-Apr-2002 1.43   Fz    ESCAN00002658: Check of bugfix version added
|25-Apr-2002 1.44   Rn    ESCAN00002721: support more than 255 signals  
|30-Apr-2002 1.45   Ml    ECSCAN0002764: corrected prototypes
|14-Mar-2002 1.46   Rn    ESCAN00002486: set Canindication in Timeout too
|11-Jul-2002 1.47   Rn    ESCAN00003210: support new Controller
|22-Jul-2002 1.48   Rn    ESCAN00002635: save dataconsitency
|06-Sep-2002 1.49   Ml    ESCAN00003687: added cast in function dbkPutnByte
|18-Oct-2002 1.50   Go    ESCAN00003981: replaced MEMORY_ROM with const in DBKMEMCPY() and in dbkRxSignByteEvaXX()
|                                        for compatibility with PPC and Metrowerks
|30-Oct-2002 1.51   Rn    ESCAN00004023: add additional compiler
|                         ESCAN00004047: message is sent immediate without changes
|08-Nov-2002 1.52   Ml    ESCAN00004142: support byteaccess for ST10
|2003-02-24         AP                 : support byteaccess for easyCAN4
|2003-02-24         Rna   ESCAN00004640: Cast operators added to avoid compiler warnings.
|2003-02-24  1.53   Rna   ESCAN00004641: Cast operators added to avoid compiler warnings.
|2003-04-10  1.54   Rn    ESCAN00005211: no changes
|2003-05-08  1.55   Rn    ESCAN00005585: Mask in dbkGetTxByte and dbkGetTxWord
|2003-05-19  1.56   Rn    ESCAN00005211: no changes
|2003-05-26  1.57   Bus   added V_MEMROM0 
|                   Rna   ESCAN00005833: dbkPutRxnByteSwap does not exist
|2003-05-26  1.58   Rna   ESCAN00006408: switch C_BYTE_ACCESS_DBKOM for H8S IAR added
|2004-01-28  2.00   Rn    ESCAN00006918: Support Geny-output (not compatible to SLP6-Tool)
|                                        Support MultipleECU
|                                        DbkTxSignByteX1Value[kDbkNumberOfTxXxX1Bytes]
|                                        Defaulvalues n16Bit/Word for little endian fixed
|                                        Timeout for multipleECU. Delete old multipleECU
|2004-02-11  2.01   Ml    ESCAN00007550: Indicationflag is set in case of timeout
|                   Rn    ESCAN00007478: Reload SendTimer in dbkTxStart
|                         ESCAN00007423: warning: variable "SigHdl" was declared but never referenced
|2004-02-20  2.02   Bus   ESCAN00007655: support for  C_COMP_GNU_TRICORE_MULTICAN and C_COMP_TASKING_TRICORE_MULTICAN
|2004-02-25  2.03   Rna   ESCAN00007710: Compiler Error: comMultipleECUCurrent undefined 
|                         ESCAN00007749: DbkTxSigSwitch.s_default for Geny not still existent (Todo)
|2004-03-05  2.04   Bus   ESCAN00007800: support for DC Powertrain Module
|2004-03-16  2.05   Bus   ESCAN00007908: define C_ENABLE_MULTICAN not sufficient for Gnu compiler
|2004-04-05  2.06   Rna   ESCAN00008156: Support Intel/Motorola signals/container
|2004-04-13  2.07   Bus   ESCAN00008167: no changes 
|                         ESCAN00008168: nested comments
|                         ESCAN00008161: no changes
|2004-05-13  2.08   Fmi   ESCAN00008361: Added support for task split
|                   Rna   ESCAN00008382: nothing changed
|2004-07-07  2.09   Rna   ESCAN00008766: message is sent too late in start up phase
|2004-07-07         Rna   ESCAN00008422: wrong timeoutvalue for signals sharing one byte of a message
|                         ESCAN00008680: MISRA check
|2004-07-16         Rna   ESCAN00007423: warning: variable "SigHdl" was declared but  never referenced
|2004-08-16         Rn    ESCAN00008456: Signal evaluation may return wrong result
|2004-09-07         Rna   ESCAN00009410: function DBkGetTxnBit returns wrong value
|2004-09-13         Rna   ESCAN00009462: Naming Conventions
|2004-09-21        Hso/RnaESCAN00009563: callback function for init/ start/ stop
|2004-10-01         Rna   ESCAN00009735: chooseable variable memory classifier for dbkom variables
|2004-12-06  2.10   Rna                : renaming byteorder swap switches
|2004-12-07         Bus   ESCAN00010045: support for Tx optimization new CRC interface
|                         ESCAN00008680: MISRA check
|2005-02-01         Rna   ESCAN00010596: dbkGetTxnBit: incorrect signal value due to missing signal mask
|2005-03-31         Rna   ESCAN00011108: this is the right ESCAN number for Dbkom V.2.xx. ESCAN10596 is for DBKom V.1.xx
|2005-02-02         Rna   ESCAN00010996: BAF message is not sent after calling dbkTxStop and dbkTxStart
|2005-04-07         Rna   ESCAN00011767: this is the right ESCAN number for Dbkom V.2.xx. ESCAN10996 is for DBKom V.1.xx
|2005-02-10         Rna   ESCAN00011082: Simplification of "Byteswapmechanism"
|2005-02-11  2.11   Rna   ESCAN00011113: dbkPutTxSignalname effects wrong value on the bus
|2005-02-21         Rna   ESCAN00011120: NULL should not be used in the component
|2005-02-22         Rna   ESCAN00003686: support 32-bit signaltype for 32-bit controller
|2005-02-22         Rna   ESCAN00011190: string.h should not be included (don't use library functions)
|2005-02-22         Rna   ESCAN00007582: support common API for signals <= 16 Bit and > 16 Bit
|2005-03-01  2.12   Rna   ESCAN00011178: Sync macros are wrong in cyclic dbkput functions (fix made with v.2.11, history updated 2.12)
|2005-03-01         Rna   ESCAN00011312: variable "Switch" not defined
|2005-03-03         Rna   ESCAN00011356: comMultipleECUCurrent is undefined
|2005-03-03         Rna   ESCAN00011363: CanTxnByteEvalFunctions/pValue/dbkTxSignByteMask not defined
|2005-03-04         Rna   ESCAN00011372: missing casts
|2005-03-08  2.13   Rna   ESCAN00011398: A compile error argument of type "const void*" is incombatible with parameter of type  "void*"
|                   Bus   ESCAN00011425: with sendtype Changed only first signal is updated
|                   Bus   ESCAN00011372: missing casts
|2005-03-14  2.14   Ml    ESCAN00011468: resolved truncating assignment
|2005-03-31  2.15   Rna   ESCAN00011668: Lowest prioritized instead of highest prioritized Dbkom messages get transmitted
|2005-04-11         Rna   ESCAN00011874: Dbkom Buffer for Rx signal contains wrong value in timeout case
|2005-05-02  2.16   Rna   ESCAN00012135: compile error '=' : incompatible types in function dbkRxTask
|2005-06-14  2.17   Rna   ESCAN00012527: Cycle time of Dbkom messages is not correct
|2005-06-22         Rna   ESCAN00012230: Unsigned/signed comparision fails on Mcs12x/Metrowerks
|2005-06-22         Rna   ESCAN00012624: Warning due to unused variable (signal_state)
|2005-06-22         Rna   ESCAN00012572: Add Copperhead/DiabData to the Uneven Word Access Microcontroller List
|2005-06-29         Rna   ESCAN00012689: Transmission of signals with sendtype cyclicIfActiveFast is delayed
|2005-06-29         Rna   ESCAN00012695: Todo:Memory qualifier for ROM tables expanded
|2005-07-01         Rna   ESCAN00012720: Todo:Do use macros instead of values to delete flags
|2005-07-01         Rna   ESCAN00012721: Todo:Use the macro kCanXxHandleNotUsed instead the value 0xFF for compability with different CAN-Driver
|2005-07-01         Rna   ESCAN00012723: Init the Timeoutvalues must be done channelspecific (dbkRxStart)
|2005-07-05  2.18   Rn    ESCAN00012704: insert comments for different resource categories
|2005-07-26         Rna   ESCAN00013025: Todo:Optimization of Precopy function; Support multichannel and MultipleECU (dbkRxStart) removed
|2005-07-27         Rna   ESCAN00013056: MISRA and PC LINT check
|2005-08-03         Rna   ESCAN00013146: Compile error: Variable MsgHdl not declared
|2005-08-25	 2.19   Rna	  ESCAN00013322: truncation assignement
|2005-09-13  2.20   Rna   ESCAN00013541: Variable "switch" not defined
|2005-09-28  2.21   Rna	  ESCAN00012704: insert comments for different resource categories
|2005-10-05         Rna	  ESCAN00013705: Values are not right masked for interlocked containers (Gaps)
|2005-10-07  2.22   Rna	  ESCAN00013766: compiler warning: unused variable "MsgHdl"
|2005-10-12         Rna	  ESCAN00013857: Indication- function/flag are not called/set the rigth way
|2005-12-14  2.23   Rna   ESCAN00014653: insert comments for different resource categories
|2006-02-15  2.24   Rna   ESCAN00015399: Memory qualifier need to get adjusted for HCS12 Xgate gConst section
|2006-03-09  2.25   Rna   ESCAN00015254: Compiler error:" the size of an array must be greater than zero" occures for dbk_def.h
|                   Rna   ESCAN00015602: Value of received signals are wrong
|                   Rna   ESCAN00015768: compiler warning: Incompatible type to previous declaration (found 'void (*) ()', expected 'void (*far ) ()')
|                   Rna   ESCAN00015779: Wrong copying of nByte containers with Metrowerks compiler on platforms with paging
|                   Rna   ESCAN00016105: Support DBKom for V85x with IAR compiler
|2006-05-16  2.26   Rna   ESCAN00016366: Sendtype "sofort" is send out of task instead spontaneous
|2006-06-22  2.27   Ml    ESCAN00016661: Wrong default values after timeout if global const is used on Mcs12x
|                   Fmi   ESCAN00016665: Compile error in function dbkGetTxnBit using Cosmic compiler with option -pck 
|2006-07-19  2.28   Rna   ESCAN00016781: New API to stop cyclic messages  
|2006-07-28  2.29   Rna   ESCAN00017112: Duplication of function dbkPutRxnByte into dbkPutRxnByteinternal and dbkPutRxnByte
|                   Rna   ESCAN00017123: dWord support not still required
|2006-10-05         Rna   ESCAN00017852: Signals of type "immediately" are fnot sent if value changes
|2006-10-10         Rna   ESCAN00017984: Implement variant handling for cyclic DBKOM messages
|2006-12-04  2.30   Rna   ESCAN00018611: #define for array size for table DbkVariantIndirection changed
|2006-12-05         Rna   ESCAN00018625: dbkPutTxSignalname() for n16Bit and Word signals may result wrong values on bus
|2007-02-08  2.31   Rna   ESCAN00019475: Compiler warning: "Implicit cast in assignment" occures
|2007-06-28         Dbr   ESCAN00021287: Support DBKom for SH2 with HEW compiler
|2007-10-12  2.32   Dbr   ESCAN00022685: Support DBKom for XC2000 with Tasking compiler
|2007-11-06  2.33   Rna   ESCAN00023111: Byteaccess for C_COMP_FUJITSU_FR60_CCAN and C_COMP_GHS_MPC55XX
|2008-01-06  2.34   Rna   ESCAN00023740: #define DBK_DUMMY_STATEMENT should be derived from #define V_ENABLE_USE_DUMMY_STATEMENT
|2008-01-28  2.35   Rna   ESCAN00024223: Support DBKOM for TX4961 with GHS compiler
|2008-02-06  2.36   Rna   ESCAN00024404: Support DBKOM for TMS470/TI
|2008-02-06         Rna   ESCAN00024408: Size of bitstructures for flags depends on swicht  V_CPUTYPE_BITARRAY_XXBIT
|2008-02-08  2.37   Rna   ESCAN00024466: Warning "Conversion in argument" occurs
|2008-02-08         Rna   ESCAN00024467: Prepressor warning "Zero used for undefined preprocessing identifier"
|2008-02-12  2.38   Rna   ESCAN00024532: invalid conversion from "unsigned char volatile __far *" to "void __near *"
|2008-04-21  2.39   Rna   ESCAN00026296: Support C_COMP_ARM_TMS470 added
|                   Rna   ESCAN00026294: Inication function/flag is not correct called/set and Rx buffer do not belong to received data
|2008-08-20  2.40   Rna   ESCAN00029327: Support PIC24/PIC16 with Microchip compiler
|2008-08-28         Rna   ESCAN00029469: Support C_COMP_GNU_VR55XX_AFCAN added
|2008-10-07  2.41   Rna   ESCAN00030486: Support C_COMP_TASKING_XC16X
|2008-11-18  2.42   Rna   ESCAN00031379: Access to array DbkRxMsgDeltaT with one instead of two parameters
|2009-01-19  2.43   Rna   ESCAN00032464: Support of C_COMP_GNU_IMX_FLEXCAN2
|2009-01-23  2.44   Rna   ESCAN00032544: Support FAR RAM for MCS12X Cosmic
|2009-01-28         Rna   ESCAN00032580: Support C_COMP_IAR_M16C_RCAN2
|2009-02-18  2.45   Rna   ESCAN00033183: Support C_COMP_KEIL_XC16X
|                   Rna   ESCAN00033185: Support C_COMP_GNU_ST30_CCAN
|2009-03-24  2.46   Rna   ESCAN00034017: The compile error "incompatible argument type" occurs
|2009-04-17         Rna   ESCAN00034617: Change of Precopy function regarding number of bytes to be copied
|2009-06-04 2.47    Rna   ESCAN00035493: IlDbkom overwrites data buffer in case CanRxActualDLC > CanRxDataLen
|                   Rna   ESCAN00035427: compile error due to wrong types in declaration and implementation
|2009-06-09 2.48    Rna   ESCAN00035629: Support C_COMP_MICROSOFT_TMS320ARM
|2009-11-26 2.49    Rna   ESCAN00039409: set #define C_BYTE_ACCESS_DBKOM for platform C_COMP_GAIO_SH2_RCAN
|2010-01-13 2.50    Rna   ESCAN00040102: Support of QNX context switch
|                   Rna   ESCAN00039980: Support C_COMP_VDSP_BF5XX
|2010-04-14 2.51    Rna   ESCAN00042287: Support C_COMP_QCC_TMS320ARM
|2010-05-20 2.52    Rna   ESCAN00041096: Unexpected transmission of cyclic messages after cancel of Waitbussleep
|                   Rna   ESCAN00040639: Compile error."@dbkRxTask() incompatible near pointer cast" occurs
|2010-07-22 2.53    Rna   ESCAN00044220: Support of controller C_COMP_IAR_78K0R
|2011-01-05 2.54    Rna   ESCAN00047893: Support TMS320
|2011-01-14         Rna   ESCAN00048051: Rx indication functions/flags are called/set wrong
|2011-02-28 2.55    Rna   ESCAN00048992: Compiler warning/error "truncation assignment"
|2011-03-07         Rna   ESCAN00049100: dbkGetRx...() Macro does not return the correct container value
|2011-07-04 2.56    Agh   ESCAN00051968: Rx indication functions/flags are called/set wrong (only word containers with gaps are affected)
|2011-11-24 2.57    Rna   ESCAN00051838: Compiler warning: narrowing or signed-to-unsigned type conversion found: int to unsigned short
|                   Rna   ESCAN00054689: Compiler warning: possible redundant expression
|2012-04-12 2.58    Agh   ESCAN00058081: set #define C_BYTE_ACCESS_DBKOM for platform C_COMP_HEW_SH2_RCAN2
|***************************************************************************/
#define DBK_DBKOM_INTERNAL
#include "can_inc.h"
#include "dbk_def.h"
#include "v_par.h"


/***************************************************************************/
/* Version check                                                           */
/***************************************************************************/
#if( DBK_VERSION_REF_IMPLEMENTATION < 0x0220)
# error "Please update your IL_DBKOM generator (Il_Dbkom.dll)"
#endif





#if defined( C_COMP_TI_470 )           || \
    defined( C_COMP_TI_TMS470 )        || \
	defined( C_COMP_TI_TMS470_DCAN )   
   #define C_BYTE_ACCESS_DBKOM
#endif



#define DbkInterruptDisable()     (CanInterruptDisable())
#define DbkInterruptRestore()     (CanInterruptRestore())

# define DBK_EIGHTBIT_CAST


#if ((defined C_ENABLE_MULTICAN) && (!defined C_MULTIPLE_RECEIVE_CHANNEL))
# if ( CANFLEX == 0 )
#  define CAN_DRV_0
#  define CanTransmit                CanTransmit_0
#  define CAN_GLOBAL_RX_HANDLE(i)    canRxHandle_0
#  define StartTxWriteSync()         StartTxWriteSync_0()
#  define EndTxWriteSync()           EndTxWriteSync_0()
#  define StartTxReadSync()          StartTxReadSync_0()
#  define EndTxReadSync()            EndTxReadSync_0()
#  define StartRxWriteSync()         StartRxWriteSync_0()
#  define EndRxWriteSync()           EndRxWriteSync_0()
#  define StartRxReadSync()          StartRxReadSync_0()
#  define EndRxReadSync()            EndRxReadSync_0()
# endif
# if ( CANFLEX == 1 )
#  define CAN_DRV_1
#  define CanTransmit                CanTransmit_1
#  define CAN_GLOBAL_RX_HANDLE(i)    canRxHandle_1
#  define StartTxWriteSync()         StartTxWriteSync_1()
#  define EndTxWriteSync()           EndTxWriteSync_1()
#  define StartTxReadSync()          StartTxReadSync_1()
#  define EndTxReadSync()            EndTxReadSync_1()
#  define StartRxWriteSync()         StartRxWriteSync_1()
#  define EndRxWriteSync()           EndRxWriteSync_1()
#  define StartRxReadSync()          StartRxReadSync_1()
#  define EndRxReadSync()            EndRxReadSync_1()
# endif
# if ( CANFLEX == 2 )
#  define CAN_DRV_2
#  define CanTransmit                CanTransmit_2
#  define CAN_GLOBAL_RX_HANDLE(i)    canRxHandle_2
#  define StartTxWriteSync()         StartTxWriteSync_2()
#  define EndTxWriteSync()           EndTxWriteSync_2()
#  define StartTxReadSync()          StartTxReadSync_2()
#  define EndTxReadSync()            EndTxReadSync_2()
#  define StartRxWriteSync()         StartRxWriteSync_2()
#  define EndRxWriteSync()           EndRxWriteSync_2()
#  define StartRxReadSync()          StartRxReadSync_2()
#  define EndRxReadSync()            EndRxReadSync_2()
# endif
# if ( CANFLEX == 3 )
#  define CAN_DRV_3
#  define CanTransmit                CanTransmit_3
#  define CAN_GLOBAL_RX_HANDLE(i)    canRxHandle_3
#  define StartTxWriteSync()         StartTxWriteSync_3()
#  define EndTxWriteSync()           EndTxWriteSync_3()
#  define StartTxReadSync()          StartTxReadSync_3()
#  define EndTxReadSync()            EndTxReadSync_3()
#  define StartRxWriteSync()         StartRxWriteSync_3()
#  define EndRxWriteSync()           EndRxWriteSync_3()
#  define StartRxReadSync()          StartRxReadSync_3()
#  define EndRxReadSync()            EndRxReadSync_3()
# endif
#endif



#if((!defined DBK_ENABLE_TX_GENERAL_BYTESWAP) && (!defined DBK_ENABLE_TX_NEVER_BYTESWAP))
#define DBK_ENABLE_TX_DYN_BYTESWAP
#endif

#if((!defined DBK_ENABLE_RX_GENERAL_BYTESWAP) && (!defined DBK_ENABLE_RX_NEVER_BYTESWAP))
#define DBK_ENABLE_RX_DYN_BYTESWAP
#endif

#include "dbk_def.h"

#ifdef DBK_ENABLE_TX_CHANNEL_SPECIFIC
# define START_CHANNEL channel
#else
# define START_CHANNEL 0
#endif

#if !defined (DBK_ENABLE_MULTIPLE_PHYSICAL_LAYER)
# ifdef SINGLE_RECEIVE_BUFFER
#  ifdef C_ENABLE_MULTICAN
#   if ( CANFLEX == 1 )
#    define RDS ((canuint8*)CanRDSPtr_1)
#   endif
#   if ( CANFLEX == 2 )
#    define RDS ((canuint8*)CanRDSPtr_2)
#   endif
#   if ( CANFLEX == 3 )
#    define RDS ((canuint8*)CanRDSPtr_3)
#   endif
#  else
#   define RDS ((canuint8*)CanRDSPtr)
#  endif
# endif
#endif



/*************************************************************/
/* Defines                                                   */
/*************************************************************/

#ifndef True
# define True  1
#endif

#ifndef False
# define False 0
#endif

#ifndef kCanTxFailed
# define kCanTxFailed        0
#endif

#if defined(DBK_ENABLE_MULTIPLE_ECU)
#define CAN_RX_HANDLE_CANDRV    canHandle
#else
#define CAN_RX_HANDLE_CANDRV    CAN_RX_HANDLE
#endif 



/*************************************************************/
/* Defines for dbkStatus Variable                            */
/*************************************************************/

#define dbkTxStatusStart         0x80
#define dbkRxStatusStart         0x40
#define dbkInitCall              0x01
#define dbkTxStatusStop          0x7F /*because of MISRA it is not possible to negate dbkTxStatusStart*/
#define dbkRxStatusStop          0xBF /*because of MISRA it is not possible to negate dbkRxStatusStart*/

/* Assertions ----------------------------------------------------------------*/
/* Function assertCan used only if option DBK_ENABLE_HARDWARE_CHECK is active   */
#if defined ( DBK_ENABLE_USER_CHECK )
# define assertUser(p,e)     if (!(p)) ApplDbkFatalError(e)
#else
# define assertUser(a,b)
#endif
#if defined ( DBK_ENABLE_GEN_CHECK )
# define assertGen(p,e)      if (!(p)) ApplDbkFatalError(e)
#else
# define assertGen(a,b)
#endif
#if defined ( DBK_ENABLE_HARDWARE_CHECK )
# define assertHardware(p,e) if (!(p)) ApplDbkFatalError(e)
#else
# define assertHardware(a,b)
#endif
#if defined ( DBK_ENABLE_INTERNAL_CHECK )
# define assertInternal(p,e) if (!(p))  ApplDbkFatalError(e)
#else
# define assertInternal(a,b)
#endif

/*==========================================================================*/
/* Driver Version for Diagnostics                                           */
/*==========================================================================*/

/* ROM CATEGORY 4 START*/
V_MEMROM0 V_MEMROM1 canuint8 V_MEMROM2 kDbkMainVersion= (canuint8)(IL_DBKOM_VERSION >> 8);
V_MEMROM0 V_MEMROM1 canuint8 V_MEMROM2 kDbkSubVersion = (canuint8) (IL_DBKOM_VERSION & 0xff);
V_MEMROM0 V_MEMROM1 canuint8 V_MEMROM2 kDbkBugFixVersion = (canuint8) (IL_DBKOM_RELEASE_VERSION & 0xff);
/* ROM CATEGORY 4 END*/

#if( IL_DBKOM_VERSION != 0x258)
 #error "Source and Header file are inconsistent!"
#endif

#if( IL_DBKOM_RELEASE_VERSION != 0x00)
 #error "Source and Header file are inconsistent!"
#endif


/*************************************************************/
/*  Structures for the access to evaluation-function          */
/*************************************************************/
/* ROM CATEGORY 1 START*/
#ifdef _NBIT_TX_SIGNALE_AKTIV
V_MEMROM0 V_MEMROM1 EvalnBitFuncPtr    V_MEMROM2       CanTxnBitEvalFunctions[7] =
{
  (EvalnBitFuncPtr) dbkTxSignBitByteEval0,  /*new&X1=X2*/
  (EvalnBitFuncPtr) dbkTxSignBitEval1,      /*new==old*/
  (EvalnBitFuncPtr) dbkTxSignBitEval2,      /*new<old*/
  (EvalnBitFuncPtr) dbkTxSignBitEval3,      /*new>old*/
  (EvalnBitFuncPtr) dbkTxSignBitByteEval4,  /*x1<=new<=x2*/
  (EvalnBitFuncPtr) dbkTxSignBitEval5,      /*(new&x1)==(old&x1)*/
  (EvalnBitFuncPtr) dbkSignBitEval6         /*TRUE*/
};
#endif
#ifdef _NBIT_RX_SIGNALE_AKTIV
V_MEMROM0 V_MEMROM1 EvalnBitFuncPtr    V_MEMROM2       CanRxnBitEvalFunctions[7] =
{
  (EvalnBitFuncPtr) dbkRxSignBitByteEval0,  /*new&X1=X2*/
  (EvalnBitFuncPtr) dbkRxSignBitEval1,      /*new==old*/
  (EvalnBitFuncPtr) dbkRxSignBitEval2,      /*new<old*/
  (EvalnBitFuncPtr) dbkRxSignBitEval3,      /*new>old*/
  (EvalnBitFuncPtr) dbkRxSignBitByteEval4,  /*x1<=new<=x2*/
  (EvalnBitFuncPtr) dbkRxSignBitEval5,      /*(new&x1)==(old&x1)*/
  (EvalnBitFuncPtr) dbkSignBitEval6         /*TRUE*/
};
#endif
#ifdef _N16BIT_TX_SIGNALE_AKTIV
V_MEMROM0 V_MEMROM1 Evaln16BitFuncPtr  V_MEMROM2       CanTxn16BitEvalFunctions[7] =
{
  (Evaln16BitFuncPtr) dbkTxSign16BitWordEval0,  /*new&X1=X2*/
  (Evaln16BitFuncPtr) dbkTxSign16BitEval1,      /*new==old*/
  (Evaln16BitFuncPtr) dbkTxSign16BitEval2,      /*new<old*/
  (Evaln16BitFuncPtr) dbkTxSign16BitEval3,      /*new>old*/
  (Evaln16BitFuncPtr) dbkTxSign16BitWordEval4,  /*x1<=new<=x2*/
  (Evaln16BitFuncPtr) dbkTxSign16BitEval5,      /*(new&x1)==(old&x1)*/
  (Evaln16BitFuncPtr) dbkSign16BitEval6         /*TRUE*/
};
#endif
#ifdef _N16BIT_RX_SIGNALE_AKTIV
V_MEMROM0 V_MEMROM1 Evaln16BitFuncPtr  V_MEMROM2       CanRxn16BitEvalFunctions[7] =
{
  (Evaln16BitFuncPtr) dbkRxSign16BitWordEval0,  /*new&X1=X2*/
  (Evaln16BitFuncPtr) dbkRxSign16BitEval1,      /*new==old*/
  (Evaln16BitFuncPtr) dbkRxSign16BitEval2,      /*new<old*/
  (Evaln16BitFuncPtr) dbkRxSign16BitEval3,      /*new>old*/
  (Evaln16BitFuncPtr) dbkRxSign16BitWordEval4,  /*x1<=new<=x2*/
  (Evaln16BitFuncPtr) dbkRxSign16BitEval5,      /*(new&x1)==(old&x1)*/
  (Evaln16BitFuncPtr) dbkSign16BitEval6         /*TRUE*/
};
#endif
#ifdef _BYTE_TX_SIGNALE_AKTIV
V_MEMROM0 V_MEMROM1 EvalByteFuncPtr    V_MEMROM2       CanTxByteEvalFunctions[7] =
{
  (EvalByteFuncPtr) dbkTxSignBitByteEval0,  /*new&X1=X2*/
  (EvalByteFuncPtr) dbkTxSigByteEval1,      /*new==old*/
  (EvalByteFuncPtr) dbkTxSigByteEval2,      /*new<old*/
  (EvalByteFuncPtr) dbkTxSigByteEval3,      /*new>old*/
  (EvalByteFuncPtr) dbkTxSignBitByteEval4,  /*x1<=new<=x2*/
  (EvalByteFuncPtr) dbkTxSigByteEval5,      /*(new&x1)==(old&x1)*/
  (EvalByteFuncPtr) dbkSigByteEval6         /*TRUE*/
};
#endif
#ifdef _BYTE_RX_SIGNALE_AKTIV
V_MEMROM0 V_MEMROM1 EvalByteFuncPtr    V_MEMROM2       CanRxByteEvalFunctions[7] =
{
  (EvalByteFuncPtr) dbkRxSignBitByteEval0,  /*new&X1=X2*/
  (EvalByteFuncPtr) dbkRxSigByteEval1,      /*new==old*/
  (EvalByteFuncPtr) dbkRxSigByteEval2,      /*new<old*/
  (EvalByteFuncPtr) dbkRxSigByteEval3,      /*new>old*/
  (EvalByteFuncPtr) dbkRxSignBitByteEval4,  /*x1<=new<=x2*/
  (EvalByteFuncPtr) dbkRxSigByteEval5,      /*(new&x1)==(old&x1)*/
  (EvalByteFuncPtr) dbkSigByteEval6         /*TRUE*/
};
#endif
#ifdef _WORD_TX_SIGNALE_AKTIV
V_MEMROM0 V_MEMROM1 EvalWordFuncPtr    V_MEMROM2       CanTxWordEvalFunctions[7] =
{
  (EvalWordFuncPtr) dbkTxSign16BitWordEval0,  /*new&X1=X2*/
  (EvalWordFuncPtr) dbkTxSigWordEval1,        /*new==old*/
  (EvalWordFuncPtr) dbkTxSigWordEval2,        /*new<old*/
  (EvalWordFuncPtr) dbkTxSigWordEval3,        /*new>old*/
  (EvalWordFuncPtr) dbkTxSign16BitWordEval4,  /*x1<=new<=x2*/
  (EvalWordFuncPtr) dbkTxSigWordEval5,        /*(new&x1)==(old&x1)*/
  (EvalWordFuncPtr) dbkSigWordEval6           /*TRUE*/
};
#endif
#ifdef _WORD_RX_SIGNALE_AKTIV
V_MEMROM0 V_MEMROM1 EvalWordFuncPtr    V_MEMROM2       CanRxWordEvalFunctions[7] = 
{
  (EvalWordFuncPtr) dbkRxSign16BitWordEval0,  /*new&X1=X2*/
  (EvalWordFuncPtr) dbkRxSigWordEval1,        /*new==old*/
  (EvalWordFuncPtr) dbkRxSigWordEval2,        /*new<old*/
  (EvalWordFuncPtr) dbkRxSigWordEval3,        /*new>old*/
  (EvalWordFuncPtr) dbkRxSign16BitWordEval4,  /*x1<=new<=x2*/
  (EvalWordFuncPtr) dbkRxSigWordEval5,        /*(new&x1)==(old&x1)*/
  (EvalWordFuncPtr) dbkSigWordEval6           /*TRUE*/
};
#endif
#if (defined _NBYTE_TX_SIGNALE_AKTIV)
V_MEMROM0 V_MEMROM1 EvalnByteFuncPtr   V_MEMROM2       CanTxnByteEvalFunctions[7] =
{
  (EvalnByteFuncPtr) dbkTxSignByteEval0,       /*new&X1=X2*/
  (EvalnByteFuncPtr) dbkTxSignByteEval1,       /*new==old*/
  (EvalnByteFuncPtr) dbkTxSignByteEval2,       /*new<old*/
  (EvalnByteFuncPtr) dbkTxSignByteEval3,       /*new>old*/
  (EvalnByteFuncPtr) dbkTxSignByteEval4,       /*x1<=new<=x2*/
  (EvalnByteFuncPtr) dbkTxSignByteEval5,       /*(new&x1)==(old&x1)*/
  (EvalnByteFuncPtr) dbkSignByteEval6          /*TRUE*/
};
#endif
#if (defined _NBYTE_RX_SIGNALE_AKTIV)
V_MEMROM0 V_MEMROM1 EvalnByteFuncPtr   V_MEMROM2       CanRxnByteEvalFunctions[7] =
{
  (EvalnByteFuncPtr) dbkRxSignByteEval0,       /*new&X1=X2*/
  (EvalnByteFuncPtr) dbkRxSignByteEval1,       /*new==old*/
  (EvalnByteFuncPtr) dbkRxSignByteEval2,       /*new<old*/
  (EvalnByteFuncPtr) dbkRxSignByteEval3,       /*new>old*/
  (EvalnByteFuncPtr) dbkRxSignByteEval4,       /*x1<=new<=x2*/
  (EvalnByteFuncPtr) dbkRxSignByteEval5,       /*(new&x1)==(old&x1)*/
  (EvalnByteFuncPtr) dbkSignByteEval6          /*TRUE*/
};
#endif
/* ROM CATEGORY 1 END*/







#ifndef DBK_USE_OWN_VARIABLES   /* if the application defines the follwing
                                   variables these switch must be set */
/*************************************************************/
/* Databuffer for send objects                               */
/*************************************************************/
#ifdef DBK_ENABLE_TX_CONF_FLAG
/* RAM CATEGORY 1 START*/
DBK_MEMORY_FAST  union DbkConfirmationBits DbkTxConfirmationFlags;/*bits to tell the Application the Message was sent*/
/* RAM CATEGORY 1 END*/
#endif
/* RAM CATEGORY 2 START*/
#if kDbkNumberOfTxSigStateBytes == 0   /*** ###ml### ***/
static DBK_MEMORY_FAST  canuint8 CanTxSignalState[ kDbkNumberOfTxSigStateBytes +1 ];
#else 
static DBK_MEMORY_FAST  canuint8 CanTxSignalState[ kDbkNumberOfTxSigStateBytes ];
#endif
#if (kDbkNumberOfTxObjects > 0)
static DBK_MEMORY_FAST  canuint8  CanTxTminTimer[kDbkNumberOfTxObjects];/*Timer to hold the min send-distance*/
static DBK_MEMORY_FAST  canuint8  CanTxMsgStatus[kDbkNumberOfTxObjects];/*bit1 = send_immdeality, bit2 = T1/#T2*/
static canuint8  CanTxMsgNRepZaehler[kDbkNumberOfTxObjects];/*count of Messagerepeat*/
static canuint16 CanTxMsgTimer[kDbkNumberOfTxObjects];/*Timer to hold the send-distance*/
#endif
#if defined(V_ENABLE_USED_GLOBAL_VAR)
# if defined( MAKE_DEPEND )
# else
#  define __XGATE_CHECK_VAR__ __TRGT__[0] 
#  if(__XGATE_CHECK_VAR__ == 'X') 
#  else
#   pragma space [] @gpage
#  endif
# endif
#endif 
canuint8   CanSignalsEx[kDbkNumberOfBytesEx]; /*Databuffer in External-Ram*/
#if defined(V_ENABLE_USED_GLOBAL_VAR)
# if defined( MAKE_DEPEND )
# else
#  define __XGATE_CHECK_VAR__ __TRGT__[0] 
#  if(__XGATE_CHECK_VAR__ == 'X') 
#  else
#   pragma space []
#  endif
# endif
#endif
/* RAM CATEGORY 2 END*/

/*************************************************************/
/* Databuffer for receive objects                            */
/*************************************************************/
/* RAM CATEGORY 1 START*/
#ifdef DBK_ENABLE_RX_IND_FLAG 
DBK_MEMORY_FAST  union DbkIndicationBits DbkRxIndicationFlags;/*bits to tell the Application the receive a Message*/
#endif
#ifdef DBK_ENABLE_RX_TIMEOUT_FLAG
DBK_MEMORY_FAST  union DbkTimeoutBits  DbkRxTimeoutFlags;/*bits to tell the Application the Timeout for a receive-message*/
#endif
/* RAM CATEGORY 1 END*/
/* RAM CATEGORY 2 START*/
#ifdef DBK_ENABLE_RX_SIMULATION
canuint16 CanRxMsgTimer[kCanNumberOfRxDbkMessages];/*Timer to simulate a receive-message*/
#endif
#if   defined( DBK_ENABLE_RX_TIMEOUT_FLAG ) \
   || defined( DBK_ENABLE_RX_TIMEOUT_FUNC ) \
   || defined( DBK_ENABLE_DEFAULT_TO )
static canuint16 CanRxTimeoutTimer[kDbkNumberOfRxObjects];/*Timer to proof the Timeout*/
#endif
/* RAM CATEGORY 2 END*/

#endif /* DBK_USE_OWN_VARIABLES */

/*==========================================================================*/
/*variabledefinition                                                        */
/*==========================================================================*/

/* RAM CATEGORY 2 START*/
static canuint8 dbkStatus[kDbkNumberOfChannels];          /*Status von dbkom zum deaktivieren der Zyklischen Botschaften*/
/* RAM CATEGORY 2 END*/
#if ( kDbkNumberOfChannels > 1 )
#else
#define channel 0
#endif


/*==========================================================================*/
/* Functions  Typ 'nBit'*/
/*==========================================================================*/
#ifdef _NBIT_TX_SIGNALE_AKTIV
/* CODE CATEGORY 2 START*/
/*--------------------------------------------------------------------------*/
canuint8 DBK_API_CALL_TYPE dbkGetTxnBit(DbkSigHandleType SigHdl)
/*read 1-7 BIT-Signals from send-databuffer */
/*--------------------------------------------------------------------------*/
{
  canuint8 sign;

# if defined( TX_CONTAINER_GAPS_BYTE )
  sign = (dbkGetTxByte(SigHdl));
# else
  sign = (canuint8)(dbkGetTxByte(SigHdl) & (canuint8)DbkTxSigMask[SigHdl]);
# endif
  sign >>= DbkTxSigStartbit[SigHdl];                   /*justify signal */
  return sign;
}
/* CODE CATEGORY 2 END*/


/***************************************************************************/
/*                                                                         */
/*                Put Function for nBit signals                            */
/*                                                                         */
/***************************************************************************/
#if defined(DBK_ENABLE_OPTIMIZE_TX_PUT)
/* CODE CATEGORY 2 START*/
/*--------------------------------------------------------------------------*/
void DBK_API_CALL_TYPE dbkPutnBitCyclic(DbkSigHandleType SigHdl, canuint8 Value)
/*write 1-7 BIT-Signals from databuffer*/
/*--------------------------------------------------------------------------*/
{
  DbkTxOffsetType offset;  /*offset fuer das Messagefeld*/
  canuint8 sign;            /*der Signalwert an der richtigen pos im Byte*/
  /* Test auf richtigen Typ*/
# if !defined( GENy )
  assertUser((DbkTxSigType[SigHdl] == TYP_NBIT), kBadSignalType);
# endif
  assertUser(((~((canuint8)DbkTxSigMask[SigHdl] >> DbkTxSigStartbit[SigHdl]) & Value) == 0), kBadSignalValue);
  sign = (canuint8)((canuint8)(Value << DbkTxSigStartbit[SigHdl]) & (canuint8)DbkTxSigMask[SigHdl]);    /*justify signal*/
  offset = DbkTxSigOffset[SigHdl];                /*get offset*/
  StartTxWriteSync();
  { 
    CanTxSignalsEx[offset] &= (canuint8)~(canuint8)DbkTxSigMask[SigHdl];      /*clear old signal*/
    CanTxSignalsEx[offset] |= sign;                                           /*set new signal*/
  }
  EndTxWriteSync();
}
/* CODE CATEGORY 2 END*/
#endif

/* CODE CATEGORY 2 START*/
/*--------------------------------------------------------------------------*/
void DBK_API_CALL_TYPE dbkPutnBit(DbkSigHandleType SigHdl, canuint8 Value)
/*write 1-7 BIT-Signals from databuffer*/
/*--------------------------------------------------------------------------*/
{
  DbkTxOffsetType offset;  /*offset fuer das Messagefeld*/
  canuint8 sign;            /*der Signalwert an der richtigen pos im Byte*/
  canuint8 signal_state;    /*Ergebnis des Signalbewerters*/
  t_TxSigSwitch  Switch;
  /* Test auf richtigen Typ*/
# if !defined( GENy )
  assertUser((DbkTxSigType[SigHdl] == TYP_NBIT), kBadSignalType);
# endif
  Switch = DbkTxSigSwitch[SigHdl];
  assertUser(((~((canuint8)DbkTxSigMask[SigHdl] >> DbkTxSigStartbit[SigHdl]) & Value) == 0), kBadSignalValue);
  sign = (canuint8)((canuint8)(Value << DbkTxSigStartbit[SigHdl]) & (canuint8)DbkTxSigMask[SigHdl]);    /*justify signal*/
  Value = (canuint8)(sign >> DbkTxSigStartbit[SigHdl]);     
  offset = DbkTxSigOffset[SigHdl];                /*get offset*/
  /* Signalbewertung (Indizierung ueber s_mode)*/
  assertUser((CanTxnBitEvalFunctions[Switch.s_mode] != V_NULL), kBadSignalMode);
  StartTxWriteSync();
  signal_state  = (CanTxnBitEvalFunctions[Switch.s_mode])(SigHdl, Value);
  if (Switch.s_mode_sign == 1)
  {
    signal_state = (canuint8)!signal_state;
  }
  { 
    CanTxSignalsEx[offset] &= (canuint8)~(canuint8)DbkTxSigMask[SigHdl];      /*clear old signal*/
    CanTxSignalsEx[offset] |= sign;                                           /*set new signal*/
  }
  EndTxWriteSync();
  /* send immediately ?*/
  if (Switch.s_put != 0)
  {
    (void)dbkTransmit(DbkTxSigMessageHdl[SigHdl]);
  }
  DbkInterruptDisable();
  if (signal_state != 0)
  {/*set bit in 'TX msg signal_state'*/
    CanTxSignalState[ DbkTxSigSignalStateOffset[SigHdl] ] |= DbkTxSigSignalStateMask[SigHdl];
    if (DbkTxMsgAttributes[DbkTxSigMessageHdl[SigHdl]].s_sofort == 1)
    {
      CanTxMsgStatus[DbkTxSigMessageHdl[SigHdl]] |= kCanTxSendImmdt;
    }
    if (DbkTxMsgAttributes[DbkTxSigMessageHdl[SigHdl]].s_demmand == 1)
    {
      CanTxMsgNRepZaehler[DbkTxSigMessageHdl[SigHdl]] = DbkTxMsgNRepeat[DbkTxSigMessageHdl[SigHdl]];
    }
  }
  else
  {/*clear bit in 'TX msg signal_state'*/
    CanTxSignalState[ DbkTxSigSignalStateOffset[SigHdl] ] &= (canuint8)~DbkTxSigSignalStateMask[SigHdl];
  }
  DbkInterruptRestore();
}
/* CODE CATEGORY 2 END*/
#endif

#ifdef _NBIT_RX_SIGNALE_AKTIV
/* CODE CATEGORY 2 START*/
/*--------------------------------------------------------------------------*/
canuint8 DBK_API_CALL_TYPE dbkGetRxnBit(DbkSigHandleType SigHdl)
/*read 1-7 BIT-Signals from receive-databuffer*/
/*--------------------------------------------------------------------------*/
{
  DbkRxOffsetType offset;        /*offset fuer das Messagefeld*/
  canuint8 sign;

  /* Test auf richtigen Typ*/
  assertUser((DbkRxSigType[SigHdl] == TYP_NBIT), kBadSignalType);
  offset = DbkRxSigOffset[SigHdl];                          /*get offset*/

  /*check location of signal*/
  sign = (canuint8)(CanRxSignalsEx[offset] & (canuint8)DbkRxSigMask[SigHdl]);  /*get signal*/

  sign >>= DbkRxSigStartbit[SigHdl];                         /*justify signal*/
  return sign;
}
/* CODE CATEGORY 2 END*/
#endif /*#ifdef _NBIT_RX_SIGNALE_AKTIV*/


/* n16Bit-Signale:*/
/* Laenge 9..15 Bit, immer bei Bit 0 beginnend!*/
/*==========================================================================*/
/* Functions  Typ 'n16Bit'*/
/*==========================================================================*/
#ifdef _N16BIT_TX_SIGNALE_AKTIV
/* CODE CATEGORY 2 START*/
/*--------------------------------------------------------------------------*/
canuint16 DBK_API_CALL_TYPE dbkGetTxn16Bit(DbkSigHandleType SigHdl)
/*read 9-15 BIT-Signals from send-databuffer*/
/*--------------------------------------------------------------------------*/
{
  canuint16 sign;
  DbkTxOffsetType offset;

#if defined DBK_ENABLE_TX_DYN_BYTESWAP
  t_TxSigSwitch  Switch;
  Switch =  DbkTxSigSwitch[SigHdl];
#endif
  offset = DbkTxSigOffset[SigHdl];                 /* get offset */

  StartTxReadSync();

#if defined DBK_ENABLE_TX_DYN_BYTESWAP
  if(Switch.s_container_swap == 1)
#endif
  {
#if ((defined DBK_ENABLE_TX_GENERAL_BYTESWAP) || (defined DBK_ENABLE_TX_DYN_BYTESWAP))
    *(((canuint8*)&sign)) = CanTxSignalsEx[offset+1];                         
    *(((canuint8*)&sign)+1) = CanTxSignalsEx[offset];
#endif
  }
#if defined DBK_ENABLE_TX_DYN_BYTESWAP
  else
#endif
  {
#if ((defined DBK_ENABLE_TX_NEVER_BYTESWAP) || (defined DBK_ENABLE_TX_DYN_BYTESWAP))
# if defined C_BYTE_ACCESS_DBKOM
  *(((canuint8*)&sign)) = CanTxSignalsEx[offset];                         
  *(((canuint8*)&sign)+1) = CanTxSignalsEx[offset+1];
# else  /*C_BYTE_ACCESS_DBKOM*/
#  if defined(V_ENABLE_USED_GLOBAL_VAR)
  sign = (*(@far @gpage canuint16 *)&CanTxSignalsEx[offset]);
#  else
  sign = (*(canuint16 *)&CanTxSignalsEx[offset]);                       
#  endif
# endif /*C_BYTE_ACCESS_DBKOM*/
#endif
  }
  sign &=  DbkTxSigMask[SigHdl];
  sign >>= DbkTxSigStartbit[SigHdl];

  EndTxReadSync();
  
  return sign;
}
/* CODE CATEGORY 2 END*/
#endif /*#ifdef _N16BIT_TX_SIGNALE_AKTIV*/


/***************************************************************************/
/*                                                                         */
/*                Put Function for n16Bit signals                          */
/*                                                                         */
/***************************************************************************/
#ifdef _N16BIT_TX_SIGNALE_AKTIV
#if defined(DBK_ENABLE_OPTIMIZE_TX_PUT)
/* CODE CATEGORY 2 START*/
/*--------------------------------------------------------------------------*/
void DBK_API_CALL_TYPE dbkPutn16BitCyclic(DbkSigHandleType SigHdl, canuint16 Value) 
/*write 9-15 BIT-Signals from databuffer*/
/*--------------------------------------------------------------------------*/
{
  DbkTxOffsetType offset;                 /*offset fuer das Messagefeld*/
  canuint16 sign;
#if defined DBK_ENABLE_TX_DYN_BYTESWAP
  t_TxSigSwitch  Switch;
  Switch =  DbkTxSigSwitch[SigHdl];
#endif

  /* Test auf richtigen Typ*/
# if !defined( GENy )
  assertUser((DbkTxSigType[SigHdl] == TYP_N16BIT), kBadSignalType);
# endif

  assertUser(((~(DbkTxSigMask[SigHdl] >> DbkTxSigStartbit[SigHdl]) & Value) == 0), kBadSignalValue);
  sign = (canuint16)((canuint16)Value <<  DbkTxSigStartbit[SigHdl]) & DbkTxSigMask[SigHdl];
  
  /*get RAM type and offset:*/
  offset = DbkTxSigOffset[SigHdl];               /*get offset*/

  StartTxWriteSync();
#if defined DBK_ENABLE_TX_DYN_BYTESWAP
  if(Switch.s_container_swap == 1)
#endif
  {
#if ((defined DBK_ENABLE_TX_GENERAL_BYTESWAP) || (defined DBK_ENABLE_TX_DYN_BYTESWAP))
    CanTxSignalsEx[offset + 0] &= (canuint8) ~ *(((V_MEMROM1 vuint8 V_MEMROM2 V_MEMROM3*)&DbkTxSigMask[SigHdl])+1);     
    CanTxSignalsEx[offset + 1] &= (canuint8) ~ *(((V_MEMROM1 vuint8 V_MEMROM2 V_MEMROM3*)&DbkTxSigMask[SigHdl]));  
    CanTxSignalsEx[offset + 0]  |= *(((canuint8*)&sign)+1);
    CanTxSignalsEx[offset + 1]  |= *(((canuint8*)&sign));
#endif
  }
#if defined DBK_ENABLE_TX_DYN_BYTESWAP
  else
#endif
  {
#if ((defined DBK_ENABLE_TX_NEVER_BYTESWAP) || (defined DBK_ENABLE_TX_DYN_BYTESWAP))
# if defined C_BYTE_ACCESS_DBKOM
    CanTxSignalsEx[offset + 0] &= (canuint8) ~ *(((V_MEMROM1 vuint8 V_MEMROM2 V_MEMROM3*)&DbkTxSigMask[SigHdl]));  
    CanTxSignalsEx[offset + 1] &= (canuint8) ~ *(((V_MEMROM1 vuint8 V_MEMROM2 V_MEMROM3*)&DbkTxSigMask[SigHdl])+1);
    CanTxSignalsEx[offset + 0]  |= *(((canuint8*)&sign));
    CanTxSignalsEx[offset + 1]  |= *(((canuint8*)&sign)+1);
# else
#  if defined(V_ENABLE_USED_GLOBAL_VAR)
    *(@far @gpage canuint16*)&CanTxSignalsEx[offset] &= (canuint16)~DbkTxSigMask[SigHdl];
    *(@far @gpage canuint16*)(&CanTxSignalsEx[offset]) |= sign;
#  else
    *(canuint16*)&CanTxSignalsEx[offset] &= (canuint16)~DbkTxSigMask[SigHdl];
    *(canuint16*)(&CanTxSignalsEx[offset]) |= sign;
#  endif
# endif
#endif
  }
  EndTxWriteSync();
}
/* CODE CATEGORY 2 END*/
#endif /*#if defined(DBK_ENABLE_OPTIMIZE_TX_PUT)*/
#endif /*#ifdef _N16BIT_TX_SIGNALE_AKTIV*/



#ifdef _N16BIT_TX_SIGNALE_AKTIV
/* CODE CATEGORY 2 START*/
/*--------------------------------------------------------------------------*/
void DBK_API_CALL_TYPE dbkPutn16Bit(DbkSigHandleType SigHdl, canuint16 Value)
/*write 9-15 BIT-Signals from databuffer*/
/*--------------------------------------------------------------------------*/
{
  DbkTxOffsetType offset;                 /*offset fuer das Messagefeld*/
  canuint16 sign;
  canuint8 signal_state;           /*Ergebnis des Signalbewerters*/
  t_TxSigSwitch  Switch;

  /* Test auf richtigen Typ*/
# if !defined( GENy )
  assertUser((DbkTxSigType[SigHdl] == TYP_N16BIT), kBadSignalType);
# endif
  Switch =  DbkTxSigSwitch[SigHdl];

  assertUser(((~(DbkTxSigMask[SigHdl] >> DbkTxSigStartbit[SigHdl]) & Value) == 0), kBadSignalValue);
  sign = (canuint16)(Value <<  DbkTxSigStartbit[SigHdl]) & DbkTxSigMask[SigHdl];
  Value = (canuint16)(sign >> DbkTxSigStartbit[SigHdl]);     
  /*get RAM type and offset:*/
  offset = DbkTxSigOffset[SigHdl];               /*get offset*/
  /* Signalbewertung (Indizierung ueber s_mode)*/
  assertUser((CanTxn16BitEvalFunctions[Switch.s_mode] != V_NULL), kBadSignalMode);

  StartTxWriteSync();
  signal_state = (CanTxn16BitEvalFunctions[Switch.s_mode])(SigHdl, Value);
  if (Switch.s_mode_sign == 1) 
  {
    signal_state = (canuint8)!signal_state;
  }

#if defined DBK_ENABLE_TX_DYN_BYTESWAP
  if(Switch.s_container_swap == 1)
#endif
  {
#if ((defined DBK_ENABLE_TX_GENERAL_BYTESWAP) || (defined DBK_ENABLE_TX_DYN_BYTESWAP))
    CanTxSignalsEx[offset + 0] &= (canuint8) ~ *(((V_MEMROM1 vuint8 V_MEMROM2 V_MEMROM3*)&DbkTxSigMask[SigHdl])+1);     
    CanTxSignalsEx[offset + 1] &= (canuint8) ~ *(((V_MEMROM1 vuint8 V_MEMROM2 V_MEMROM3*)&DbkTxSigMask[SigHdl]));  
    CanTxSignalsEx[offset + 0]  |= *(((canuint8*)&sign)+1);
    CanTxSignalsEx[offset + 1]  |= *(((canuint8*)&sign));
#endif
  }
#if defined DBK_ENABLE_TX_DYN_BYTESWAP
  else
#endif
  {
#if ((defined DBK_ENABLE_TX_NEVER_BYTESWAP) || (defined DBK_ENABLE_TX_DYN_BYTESWAP))
# if defined C_BYTE_ACCESS_DBKOM
    CanTxSignalsEx[offset + 0] &= (canuint8) ~ *(((V_MEMROM1 vuint8 V_MEMROM2 V_MEMROM3*)&DbkTxSigMask[SigHdl]));  
    CanTxSignalsEx[offset + 1] &= (canuint8) ~ *(((V_MEMROM1 vuint8 V_MEMROM2 V_MEMROM3*)&DbkTxSigMask[SigHdl])+1);
    CanTxSignalsEx[offset + 0]  |= *(((canuint8*)&sign));
    CanTxSignalsEx[offset + 1]  |= *(((canuint8*)&sign)+1);
# else
#  if defined(V_ENABLE_USED_GLOBAL_VAR)
    *(@far @gpage canuint16*)&CanTxSignalsEx[offset] &= (canuint16)~DbkTxSigMask[SigHdl];
    *(@far @gpage canuint16*)(&CanTxSignalsEx[offset]) |= sign;
#  else
    *(canuint16*)&CanTxSignalsEx[offset] &= (canuint16)~DbkTxSigMask[SigHdl];
    *(canuint16*)(&CanTxSignalsEx[offset]) |= sign;
#  endif
# endif
#endif
  }
  EndTxWriteSync();
  /* send immediately ?*/
  if (Switch.s_put != 0)
  {
    (void)dbkTransmit(DbkTxSigMessageHdl[SigHdl]);
  }
  DbkInterruptDisable();
  if (signal_state != 0)
  {/*set bit in 'TX msg signal_state'*/
    CanTxSignalState[ DbkTxSigSignalStateOffset[SigHdl] ] |= DbkTxSigSignalStateMask[SigHdl];
    if (DbkTxMsgAttributes[DbkTxSigMessageHdl[SigHdl]].s_sofort == 1)
    {
      CanTxMsgStatus[DbkTxSigMessageHdl[SigHdl]] |= kCanTxSendImmdt;
    }
    if (DbkTxMsgAttributes[DbkTxSigMessageHdl[SigHdl]].s_demmand == 1)
    {
      CanTxMsgNRepZaehler[DbkTxSigMessageHdl[SigHdl]] = DbkTxMsgNRepeat[DbkTxSigMessageHdl[SigHdl]];
    }
  }
  else
  {/*clear bit in 'TX msg signal_state'*/
    CanTxSignalState[ DbkTxSigSignalStateOffset[SigHdl] ] &= (canuint8)~DbkTxSigSignalStateMask[SigHdl];
  }
  DbkInterruptRestore();
}
/* CODE CATEGORY 2 END*/
#endif /*#ifdef _N16BIT_TX_SIGNALE_AKTIV*/


#ifdef _N16BIT_RX_SIGNALE_AKTIV
/* CODE CATEGORY 2 START*/
/*--------------------------------------------------------------------------*/
canuint16 DBK_API_CALL_TYPE dbkGetRxn16Bit(DbkSigHandleType SigHdl)
/*read 9-15 BIT-Signals from receive-databuffer*/
/*--------------------------------------------------------------------------*/
{
  DbkRxOffsetType offset;                            /* offset fuer das Messagefeld */
  canuint16 sign;
#if defined DBK_ENABLE_RX_DYN_BYTESWAP
  t_RxSigSwitch  Switch;
  Switch = DbkRxSigSwitch[SigHdl];
#endif

  /* Test auf richtigen Typ*/
  assertUser((DbkRxSigType[SigHdl] == TYP_N16BIT), kBadSignalType);
  offset = DbkRxSigOffset[SigHdl];                    /* get offset */
  
  /*check location of signal*/
  StartRxReadSync();

#if defined DBK_ENABLE_RX_DYN_BYTESWAP
  if(Switch.s_container_swap == 1)
#endif
  {
#if ((defined DBK_ENABLE_RX_GENERAL_BYTESWAP) || (defined DBK_ENABLE_RX_DYN_BYTESWAP))
  *(((canuint8*)&sign)) = CanRxSignalsEx[offset+1]; 
  *(((canuint8*)&sign)+1) = CanRxSignalsEx[offset];
#endif
  }
#if defined DBK_ENABLE_RX_DYN_BYTESWAP
  else
#endif
  {
#if ((defined DBK_ENABLE_RX_NEVER_BYTESWAP) || (defined DBK_ENABLE_RX_DYN_BYTESWAP))
#  if defined C_BYTE_ACCESS_DBKOM
    *(((canuint8*)&sign)) = CanRxSignalsEx[offset];   /*swap                      */
    *(((canuint8*)&sign)+1) = CanRxSignalsEx[offset+1];
#  else  /*C_BYTE_ACCESS_DBKOM*/
#   if defined(V_ENABLE_USED_GLOBAL_VAR)
    sign = (*(@far @gpage canuint16 *)&CanRxSignalsEx[offset]);  /*get signal*/
#   else
    sign = (*(canuint16 *)&CanRxSignalsEx[offset]);  /*get signal*/
#   endif
#  endif /*C_BYTE_ACCESS_DBKOM*/
#endif
  }
  sign &= DbkRxSigMask[SigHdl];
  sign >>= DbkRxSigStartbit[SigHdl];
  EndRxReadSync();
  return sign;
}
/* CODE CATEGORY 2 END*/
#endif /*#ifdef _N16BIT_RX_SIGNALE_AKTIV*/


/*==========================================================================*/
/* Functions  Typ 'Byte'                                                    */
/*==========================================================================*/
/*--------------------------------------------------------------------------*/
/* CODE CATEGORY 2 START*/
canuint8 DBK_API_CALL_TYPE dbkGetTxByte(DbkSigHandleType SigHdl)
/*read 1 BYTE-Signals from send-databuffer*/
/*--------------------------------------------------------------------------*/
{
  DbkTxOffsetType offset;                    /*offset fuer das Messagefeld*/

  offset = DbkTxSigOffset[SigHdl];               /*get offset*/

  /*check location of signal*/

# ifdef TX_CONTAINER_GAPS_BYTE
  return( (canuint8)(CanTxSignalsEx[offset] & (canuint8)DbkTxSigMask[SigHdl]) );
# else
  return CanTxSignalsEx[offset];
# endif
}
/* CODE CATEGORY 2 END*/

#ifdef _BYTE_TX_SIGNALE_AKTIV
/***************************************************************************/
/*                                                                         */
/*                Put Function for Byte signals                            */
/*                                                                         */
/***************************************************************************/
#if defined(DBK_ENABLE_OPTIMIZE_TX_PUT)
/* CODE CATEGORY 2 START*/
/*--------------------------------------------------------------------------*/
void DBK_API_CALL_TYPE dbkPutByteCyclic(DbkSigHandleType SigHdl, canuint8 Value)
/*write 1 BYTE-Signals from databuffer*/
/*--------------------------------------------------------------------------*/
{
  DbkTxOffsetType offset;                    /*offset fuer das Messagefeld*/
  /* Test auf richtigen Typ*/
# if !defined( GENy )
  assertUser((DbkTxSigType[SigHdl] == TYP_BYTE), kBadSignalType);
# endif
# ifdef TX_CONTAINER_GAPS_BYTE
  Value &= (canuint8)DbkTxSigMask[SigHdl];
# endif
  /*get RAM type and offset:*/
  offset = DbkTxSigOffset[SigHdl];                /*get offset*/

  StartTxWriteSync();

  /*check location of signal and write signal*/

# ifdef TX_CONTAINER_GAPS_BYTE
  CanTxSignalsEx[offset] = (canuint8)(Value | (CanTxSignalsEx[offset] & (canuint8)~(canuint8)DbkTxSigMask[SigHdl]));
# else
  CanTxSignalsEx[offset] = Value;                    /*set new signal*/
# endif

  EndTxWriteSync();
}
/* CODE CATEGORY 2 END*/
#endif /*#if defined(DBK_ENABLE_OPTIMIZE_TX_PUT)*/


/*--------------------------------------------------------------------------*/
/* CODE CATEGORY 2 START*/
void DBK_API_CALL_TYPE dbkPutByte(DbkSigHandleType SigHdl, canuint8 Value)
/*write 1 BYTE-Signals from databuffer*/
/*--------------------------------------------------------------------------*/
{
  DbkTxOffsetType offset;                    /*offset fuer das Messagefeld*/
  canuint8 signal_state;              /*Ergebnis des Signalbewerters*/
  t_TxSigSwitch  Switch;
  /* Test auf richtigen Typ*/
# if !defined( GENy )
  assertUser((DbkTxSigType[SigHdl] == TYP_BYTE), kBadSignalType);
# endif
  Switch =  DbkTxSigSwitch[SigHdl];
# ifdef TX_CONTAINER_GAPS_BYTE
  Value &= (canuint8)DbkTxSigMask[SigHdl];
# endif
  /*get RAM type and offset:*/
  offset = DbkTxSigOffset[SigHdl];                /*get offset*/

  /* Signalbewertung (ind. ueber s_mode)*/
  assertUser((CanTxByteEvalFunctions[Switch.s_mode] != V_NULL), kBadSignalMode);

  StartTxWriteSync();
  signal_state = (CanTxByteEvalFunctions[Switch.s_mode])(SigHdl, Value);
  if (Switch.s_mode_sign == 1) 
  {
    signal_state = (canuint8)!signal_state;
  }
  /*check location of signal and write signal*/

# ifdef TX_CONTAINER_GAPS_BYTE
  CanTxSignalsEx[offset] = (canuint8)(Value | (CanTxSignalsEx[offset] & (canuint8)~(canuint8)DbkTxSigMask[SigHdl]));
# else
  CanTxSignalsEx[offset] = Value;                    /*set new signal*/
# endif

  EndTxWriteSync();
  /* send immediately ?*/
  if (Switch.s_put != 0)
  {    
    (void)dbkTransmit(DbkTxSigMessageHdl[SigHdl]);
  }
  DbkInterruptDisable();
  if (signal_state != 0)
  {/*set bit in 'TX msg signal_state'*/
    CanTxSignalState[ DbkTxSigSignalStateOffset[SigHdl] ] |= DbkTxSigSignalStateMask[SigHdl];
    if (DbkTxMsgAttributes[DbkTxSigMessageHdl[SigHdl]].s_sofort == 1)
    {
      CanTxMsgStatus[DbkTxSigMessageHdl[SigHdl]] |= kCanTxSendImmdt;
    }
    if (DbkTxMsgAttributes[DbkTxSigMessageHdl[SigHdl]].s_demmand == 1)
    {
      CanTxMsgNRepZaehler[DbkTxSigMessageHdl[SigHdl]] = DbkTxMsgNRepeat[DbkTxSigMessageHdl[SigHdl]];
    }
  }
  else
  {/*clear bit in 'TX msg signal_state'*/
    CanTxSignalState[ DbkTxSigSignalStateOffset[SigHdl] ] &= (canuint8)~DbkTxSigSignalStateMask[SigHdl];
  }
  DbkInterruptRestore(); 
}
/* CODE CATEGORY 2 END*/
#endif /*#ifdef _BYTE_TX_SIGNALE_AKTIV*/


#ifdef _BYTE_RX_SIGNALE_AKTIV
/* CODE CATEGORY 2 START*/
/*--------------------------------------------------------------------------*/
canuint8 DBK_API_CALL_TYPE dbkGetRxByte(DbkSigHandleType SigHdl)
/*read BYTE-Signals from receive-databuffer*/
/*--------------------------------------------------------------------------*/
{
  DbkRxOffsetType offset;        /*offset fuer das Messagefeld*/
  canuint8 sign;

  /* Test auf richtigen Typ*/
  assertUser((DbkRxSigType[SigHdl] == TYP_BYTE), kBadSignalType);
  offset = DbkRxSigOffset[SigHdl];                   /*get offset*/
# ifdef RX_CONTAINER_GAPS_BYTE
  sign = (canuint8)(CanRxSignalsEx[offset] & (canuint8)DbkRxSigMask[SigHdl]);  /*get signal*/
# else
  sign = CanRxSignalsEx[offset];
# endif
  return sign;
}
/* CODE CATEGORY 2 END*/
#endif

/*==========================================================================*/
/* Functions  Typ 'Word'*/
/*==========================================================================*/
/*--------------------------------------------------------------------------*/
#if defined( _WORD_TX_SIGNALE_AKTIV ) || defined( _N16BIT_TX_SIGNALE_AKTIV )
/* CODE CATEGORY 2 START*/
canuint16 DBK_API_CALL_TYPE dbkGetTxWord(DbkSigHandleType SigHdl)
/*read 1 WORD-Signals from send-databuffer*/
/*--------------------------------------------------------------------------*/
{
  DbkTxOffsetType offset;                               /* offset fuer das Messagefeld */
  canuint16 sign;
#if ((!defined DBK_ENABLE_TX_NEVER_BYTESWAP) && (!defined DBK_ENABLE_TX_GENERAL_BYTESWAP))
  t_TxSigSwitch  Switch;
  Switch =  DbkTxSigSwitch[SigHdl];
#endif
  offset = DbkTxSigOffset[SigHdl];                      /* get offset */
  
  StartTxReadSync();
  /*check location of signal*/

#if defined DBK_ENABLE_TX_DYN_BYTESWAP
  if(Switch.s_container_swap == 1)
#endif
  {
#if ((defined DBK_ENABLE_TX_GENERAL_BYTESWAP)  || (defined DBK_ENABLE_TX_DYN_BYTESWAP))
    *(((canuint8*)&sign)) = CanTxSignalsEx[offset+1]; 
    *(((canuint8*)&sign)+1) = CanTxSignalsEx[offset]; 
#endif
  }
#if defined DBK_ENABLE_TX_DYN_BYTESWAP
  else
#endif
  {
#if ((defined DBK_ENABLE_TX_NEVER_BYTESWAP) || (defined DBK_ENABLE_TX_DYN_BYTESWAP))
# if defined C_BYTE_ACCESS_DBKOM
    *(((canuint8*)&sign)) = CanTxSignalsEx[offset]; 
    *(((canuint8*)&sign)+1) = CanTxSignalsEx[offset+1]; 
#   else  /*C_BYTE_ACCESS_DBKOM*/
#    if defined(V_ENABLE_USED_GLOBAL_VAR)
    sign = (*(@far @gpage canuint16 *)&CanTxSignalsEx[offset]);                            /*get signal*/
#    else
    sign = (*(canuint16 *)&CanTxSignalsEx[offset]);                            /*get signal*/
#    endif
# endif /*C_BYTE_ACCESS_DBKOM*/
#endif
  }
# ifdef TX_CONTAINER_GAPS_WORD                          /* GAPS in Container-Signals */
  sign &= DbkTxSigMask[SigHdl];
# endif                                                 /* byteorder different to the bus-byteorder*/ 
  EndTxReadSync();

  return sign;
}
/* CODE CATEGORY 2 END*/
#endif /*#if defined( _WORD_TX_SIGNALE_AKTIV ) || defined( _N16BIT_TX_SIGNALE_AKTIV )*/


#ifdef _WORD_TX_SIGNALE_AKTIV
/***************************************************************************/
/*                                                                         */
/*                Put Function for Word signals                            */
/*                                                                         */
/***************************************************************************/
#if defined(DBK_ENABLE_OPTIMIZE_TX_PUT)
/* CODE CATEGORY 2 START*/
/*--------------------------------------------------------------------------*/
void DBK_API_CALL_TYPE dbkPutWordCyclic(DbkSigHandleType SigHdl, canuint16 Value)
/*write 1 WORD-Signals from databuffer*/
/*--------------------------------------------------------------------------*/
{
  DbkTxOffsetType offset;                   /*offset fuer das Messagefeld*/
#if defined DBK_ENABLE_TX_DYN_BYTESWAP
  t_TxSigSwitch  Switch;
  Switch =  DbkTxSigSwitch[SigHdl];
#endif
  
  /* Test auf richtigen Typ*/
#if !defined( GENy )
  assertUser((DbkTxSigType[SigHdl] == TYP_WORD), kBadSignalType);
#endif

#ifdef TX_CONTAINER_GAPS_WORD
  Value &= DbkTxSigMask[SigHdl];
#endif
  /*get RAM type and offset:*/
  offset = DbkTxSigOffset[SigHdl];                /*get offset*/
  /*check location of signal and write signal*/
  StartTxWriteSync();
#ifdef TX_CONTAINER_GAPS_WORD
#if defined DBK_ENABLE_TX_DYN_BYTESWAP
  if(Switch.s_container_swap == 1)
#endif
  {
#if ((defined DBK_ENABLE_TX_GENERAL_BYTESWAP) || (defined DBK_ENABLE_TX_DYN_BYTESWAP))
  CanTxSignalsEx[offset + 0] &= (canuint8) ~ *(((V_MEMROM1 vuint8 V_MEMROM2 V_MEMROM3*)&DbkTxSigMask[SigHdl])+1);  
  CanTxSignalsEx[offset + 1] &= (canuint8) ~ *(((V_MEMROM1 vuint8 V_MEMROM2 V_MEMROM3*)&DbkTxSigMask[SigHdl]));  
  CanTxSignalsEx[offset + 0] |=              *(((canuint8*)&Value)+1);
  CanTxSignalsEx[offset + 1] |=              *(((canuint8*)&Value));
#endif
  }
#if defined DBK_ENABLE_TX_DYN_BYTESWAP
  else
#endif
  {
#if ((defined DBK_ENABLE_TX_NEVER_BYTESWAP) || (defined DBK_ENABLE_TX_DYN_BYTESWAP))
# if defined C_BYTE_ACCESS_DBKOM
  CanTxSignalsEx[offset + 0] &= (canuint8) ~ *(((V_MEMROM1 vuint8 V_MEMROM2 V_MEMROM3*)&DbkTxSigMask[SigHdl]));  
  CanTxSignalsEx[offset + 1] &= (canuint8) ~ *(((V_MEMROM1 vuint8 V_MEMROM2 V_MEMROM3*)&DbkTxSigMask[SigHdl])+1);  
  CanTxSignalsEx[offset + 0] |=              *(((canuint8*)&Value));
  CanTxSignalsEx[offset + 1] |=              *(((canuint8*)&Value)+1);
# else  /*C_BYTE_ACCESS_DBKOM*/
#  if defined(V_ENABLE_USED_GLOBAL_VAR)
  *(@far @gpage canuint16*)&CanTxSignalsEx[offset] &= (canuint16)~DbkTxSigMask[SigHdl];
  *(@far @gpage canuint16*)&CanTxSignalsEx[offset] |= Value;
#  else
  *(canuint16*)&CanTxSignalsEx[offset] &= (canuint16)~DbkTxSigMask[SigHdl];
  *(canuint16*)&CanTxSignalsEx[offset] |= Value;
#  endif
#endif /*C_BYTE_ACCESS_DBKOM*/
#endif
  }

#else /*#ifdef TX_CONTAINER_GAPS_WORD*/

#if defined DBK_ENABLE_TX_DYN_BYTESWAP
  if(Switch.s_container_swap == 1)
#endif
  {
#if ((defined DBK_ENABLE_TX_GENERAL_BYTESWAP) || (defined DBK_ENABLE_TX_DYN_BYTESWAP))
  CanTxSignalsEx[offset + 0] = *(((canuint8*)&Value)+1);
  CanTxSignalsEx[offset + 1] = *(((canuint8*)&Value));
#endif
  }
#if defined DBK_ENABLE_TX_DYN_BYTESWAP
  else
#endif
  {
#if ((defined DBK_ENABLE_TX_NEVER_BYTESWAP) || (defined DBK_ENABLE_TX_DYN_BYTESWAP))
# if defined C_BYTE_ACCESS_DBKOM
  CanTxSignalsEx[offset + 0] = *(((canuint8*)&Value));
  CanTxSignalsEx[offset + 1] = *(((canuint8*)&Value)+1);
# else  /*C_BYTE_ACCESS_DBKOM*/
#  if defined(V_ENABLE_USED_GLOBAL_VAR)
  *(@far @gpage canuint16*)(&CanTxSignalsEx[offset]) = Value;     /* set */ /*1:1*/
#  else
  *(canuint16*)(&CanTxSignalsEx[offset]) = Value;                 /* set */ /*1:1*/
#  endif
# endif /*C_BYTE_ACCESS_DBKOM*/
#endif
  }
#endif /*#else #ifdef TX_CONTAINER_GAPS_WORD*/
  EndTxWriteSync();
}
/* CODE CATEGORY 2 END*/
#endif /*#if defined(DBK_ENABLE_OPTIMIZE_TX_PUT)*/
#endif /*#ifdef _WORD_TX_SIGNALE_AKTIV*/


#ifdef _WORD_TX_SIGNALE_AKTIV
/* CODE CATEGORY 2 START*/
/*--------------------------------------------------------------------------*/
void DBK_API_CALL_TYPE dbkPutWord(DbkSigHandleType SigHdl, canuint16 Value)
/*write 1 WORD-Signals from databuffer*/
/*--------------------------------------------------------------------------*/
{
  DbkTxOffsetType offset;                   /*offset fuer das Messagefeld*/
  canuint8 signal_state;             /*Ergebnis des Signalbewerters*/
  t_TxSigSwitch  Switch;
  
  /* Test auf richtigen Typ*/
#if !defined( GENy )
  assertUser((DbkTxSigType[SigHdl] == TYP_WORD), kBadSignalType);
#endif
  Switch =  DbkTxSigSwitch[SigHdl];

#ifdef TX_CONTAINER_GAPS_WORD
  Value &= DbkTxSigMask[SigHdl];
#endif
  /*get RAM type and offset:*/
  offset = DbkTxSigOffset[SigHdl];                /*get offset*/
  /*check location of signal and write signal*/

  /* Signalbewertung (ind. ueber s_mode)*/
  assertUser((CanTxWordEvalFunctions[Switch.s_mode] != V_NULL), kBadSignalMode);

  StartTxWriteSync();
  signal_state = (CanTxWordEvalFunctions[Switch.s_mode])(SigHdl, Value);
  if (Switch.s_mode_sign == 1) {signal_state = (canuint8)!signal_state;}

#ifdef TX_CONTAINER_GAPS_WORD
#if defined DBK_ENABLE_TX_DYN_BYTESWAP
  if(Switch.s_container_swap == 1)
#endif
  {
#if ((defined DBK_ENABLE_TX_GENERAL_BYTESWAP) || (defined DBK_ENABLE_TX_DYN_BYTESWAP))
  CanTxSignalsEx[offset + 0] &= (canuint8) ~ *(((V_MEMROM1 vuint8 V_MEMROM2 V_MEMROM3*)&DbkTxSigMask[SigHdl])+1);  
  CanTxSignalsEx[offset + 1] &= (canuint8) ~ *(((V_MEMROM1 vuint8 V_MEMROM2 V_MEMROM3*)&DbkTxSigMask[SigHdl]));  
  CanTxSignalsEx[offset + 0] |=              *(((canuint8*)&Value)+1);
  CanTxSignalsEx[offset + 1] |=              *(((canuint8*)&Value));
#endif
  }
#if defined DBK_ENABLE_TX_DYN_BYTESWAP
  else
#endif
  {
#if ((defined DBK_ENABLE_TX_NEVER_BYTESWAP) || (defined DBK_ENABLE_TX_DYN_BYTESWAP))
# if defined C_BYTE_ACCESS_DBKOM
  CanTxSignalsEx[offset + 0] &= (canuint8) ~ *(((V_MEMROM1 vuint8 V_MEMROM2 V_MEMROM3*)&DbkTxSigMask[SigHdl]));  
  CanTxSignalsEx[offset + 1] &= (canuint8) ~ *(((V_MEMROM1 vuint8 V_MEMROM2 V_MEMROM3*)&DbkTxSigMask[SigHdl])+1);  
  CanTxSignalsEx[offset + 0] |=              *(((canuint8*)&Value));
  CanTxSignalsEx[offset + 1] |=              *(((canuint8*)&Value)+1);
# else  /*C_BYTE_ACCESS_DBKOM*/
#  if defined(V_ENABLE_USED_GLOBAL_VAR)
  *(@far @gpage canuint16*)&CanTxSignalsEx[offset] &= (canuint16)~DbkTxSigMask[SigHdl];
  *(@far @gpage canuint16*)&CanTxSignalsEx[offset] |= Value;
#  else
  *(canuint16*)&CanTxSignalsEx[offset] &= (canuint16)~DbkTxSigMask[SigHdl];
  *(canuint16*)&CanTxSignalsEx[offset] |= Value;
#  endif
#endif /*C_BYTE_ACCESS_DBKOM*/
#endif
  }

#else /*#ifdef TX_CONTAINER_GAPS_WORD*/

#if defined DBK_ENABLE_TX_DYN_BYTESWAP
  if(Switch.s_container_swap == 1)
#endif
  {
#if ((defined DBK_ENABLE_TX_GENERAL_BYTESWAP) || (defined DBK_ENABLE_TX_DYN_BYTESWAP))
  CanTxSignalsEx[offset + 0] = *(((canuint8*)&Value)+1);
  CanTxSignalsEx[offset + 1] = *(((canuint8*)&Value));
#endif
  }
#if defined DBK_ENABLE_TX_DYN_BYTESWAP
  else
#endif
  {
#if ((defined DBK_ENABLE_TX_NEVER_BYTESWAP) || (defined DBK_ENABLE_TX_DYN_BYTESWAP))
# if defined C_BYTE_ACCESS_DBKOM
  CanTxSignalsEx[offset + 0] = *(((canuint8*)&Value));
  CanTxSignalsEx[offset + 1] = *(((canuint8*)&Value)+1);
# else  /*C_BYTE_ACCESS_DBKOM*/
#  if defined(V_ENABLE_USED_GLOBAL_VAR)
  *(@far @gpage canuint16*)(&CanTxSignalsEx[offset]) = Value;     /* set */ /*1:1*/
#  else
  *(canuint16*)(&CanTxSignalsEx[offset]) = Value;                 /* set */ /*1:1*/
#  endif
# endif /*C_BYTE_ACCESS_DBKOM*/
#endif
  }
#endif /*#else #ifdef TX_CONTAINER_GAPS_WORD*/
EndTxWriteSync();
  if (Switch.s_put != 0)
  {
    (void)dbkTransmit(DbkTxSigMessageHdl[SigHdl]);
  }
  DbkInterruptDisable();
  if (signal_state != 0)
  {/*set bit in 'TX msg signal_state'*/
    CanTxSignalState[ DbkTxSigSignalStateOffset[SigHdl] ] |= DbkTxSigSignalStateMask[SigHdl];
    if (DbkTxMsgAttributes[DbkTxSigMessageHdl[SigHdl]].s_sofort == 1)
    {
      CanTxMsgStatus[DbkTxSigMessageHdl[SigHdl]] |= kCanTxSendImmdt;
    }
    if (DbkTxMsgAttributes[DbkTxSigMessageHdl[SigHdl]].s_demmand == 1)
    {
      CanTxMsgNRepZaehler[DbkTxSigMessageHdl[SigHdl]] = DbkTxMsgNRepeat[DbkTxSigMessageHdl[SigHdl]];
    }
  }
  else
  {/*clear bit in 'TX msg signal_state'*/
    CanTxSignalState[ DbkTxSigSignalStateOffset[SigHdl] ] &= (canuint8)~DbkTxSigSignalStateMask[SigHdl];
  }
  DbkInterruptRestore();
/* KB end SendOldWord */
}
/* CODE CATEGORY 2 END*/
#endif /*#ifdef _WORD_TX_SIGNALE_AKTIV*/


#ifdef _WORD_RX_SIGNALE_AKTIV
/* CODE CATEGORY 2 START*/
/*--------------------------------------------------------------------------*/
canuint16 DBK_API_CALL_TYPE dbkGetRxWord(DbkSigHandleType SigHdl)
/*read WORD-Signals from receive-databuffer*/
/*--------------------------------------------------------------------------*/
{
  DbkRxOffsetType offset;                          /* offset fuer das Messagefeld */
  canuint16 sign;
#if ((!defined DBK_ENABLE_RX_GENERAL_BYTESWAP) && (!defined DBK_ENABLE_RX_NEVER_BYTESWAP))
  t_RxSigSwitch  Switch;
  Switch = DbkRxSigSwitch[SigHdl];
# endif

  /* Test auf richtigen Typ*/
  assertUser((DbkRxSigType[SigHdl] == TYP_WORD), kBadSignalType);
  offset = DbkRxSigOffset[SigHdl];                      /* get offset */
  
  /*check location of signal*/
  StartRxReadSync();

#if defined DBK_ENABLE_RX_DYN_BYTESWAP
  if(Switch.s_container_swap == 1)
#endif
  {
#if ((defined DBK_ENABLE_RX_GENERAL_BYTESWAP) || (defined DBK_ENABLE_RX_DYN_BYTESWAP))
    *(((canuint8*)&sign)) = CanRxSignalsEx[offset+1];                         /*get signal*/
    *(((canuint8*)&sign)+1) = CanRxSignalsEx[offset];
#endif
  }
#if defined DBK_ENABLE_RX_DYN_BYTESWAP
  else
#endif
  {
#if ((defined DBK_ENABLE_RX_NEVER_BYTESWAP) || (defined DBK_ENABLE_RX_DYN_BYTESWAP))
# if defined C_BYTE_ACCESS_DBKOM
    *(((canuint8*)&sign)) = CanRxSignalsEx[offset];                         /*get signal*/
    *(((canuint8*)&sign)+1) = CanRxSignalsEx[offset+1];
# else  /*C_BYTE_ACCESS_DBKOM*/
#  if defined(V_ENABLE_USED_GLOBAL_VAR)
    sign = (*(@far @gpage canuint16 *)&CanRxSignalsEx[offset]);  /*get signal*/
#  else
    sign = (*(canuint16 *)&CanRxSignalsEx[offset]);  /*get signal*/
#  endif
# endif /*C_BYTE_ACCESS_DBKOM*/
# endif
  }
# ifdef RX_CONTAINER_GAPS_WORD
    sign &= (canuint16)(DbkRxSigMask[SigHdl]);
# endif
  EndRxReadSync();
  return sign;
}
/* CODE CATEGORY 2 END*/
#endif /*#ifdef _WORD_RX_SIGNALE_AKTIV*/

/*==========================================================================*/
/* Functions  Typ 'nByte'*/
/*==========================================================================*/
#if (defined  _NBYTE_TX_SIGNALE_AKTIV)
/* CODE CATEGORY 2 START*/
/*--------------------------------------------------------------------------*/
TxDataPtr  DBK_API_CALL_TYPE dbkGetTxnByte(DbkSigHandleType SigHdl)
/*read 3-8 BYTE-Signals from send-databuffer*/
/*--------------------------------------------------------------------------*/
{
  DbkTxOffsetType offset;                          /*offset fuer das Messagefeld*/

  offset = DbkTxSigOffset[SigHdl];          /*get offset*/
  /*check location of signal*/

    return &CanTxSignalsEx[offset];
}
/* CODE CATEGORY 2 END*/


/***************************************************************************/
/*                                                                         */
/*                Put Function for nByte signals                           */
/*                                                                         */
/***************************************************************************/
#if defined(DBK_ENABLE_OPTIMIZE_TX_PUT)
/* CODE CATEGORY 2 START*/
/*--------------------------------------------------------------------------*/
void DBK_API_CALL_TYPE dbkPutnByteCyclic(DbkSigHandleType SigHdl, TxDataPtr pValue)
/*write 3-8 BYTE-Signals from databuffer*/
/*--------------------------------------------------------------------------*/
{
  DbkTxOffsetType offset;                   /*offset fuer das Messagefeld*/
# if defined( TX_CONTAINER_GAPS_NBYTE )
  vsintx i;
# endif

  /* Test auf richtigen Typ*/
# if !defined( GENy )
  assertUser((DbkTxSigType[SigHdl] == TYP_NBYTE), kBadSignalType);
# endif
  /*get RAM type and offset:*/
  offset = DbkTxSigOffset[SigHdl];                /*get offset*/
  StartTxWriteSync();
  /*EXRAM*/
# if defined( TX_CONTAINER_GAPS_NBYTE ) 
  for (i = (vsintx)(DbkTxSigMask[SigHdl]-1); i >= (vsintx)0; i--)
  {
    CanTxSignalsEx[offset+i] &= (canuint8)~DbkTxSignByteMask[DbkTxSigStartbit[SigHdl]+i];
    CanTxSignalsEx[offset+i] |= (canuint8)(*((canuint8*)(pValue)+i) & DbkTxSignByteMask[DbkTxSigStartbit[SigHdl]+i]);
  }
# else
#  if defined(V_ENABLE_USED_GLOBAL_VAR)
  VStdMemCpyFarRamToFarRam(&CanTxSignalsEx[offset], pValue, (canuint8)DbkTxSigMask[SigHdl]);
#  else
  VStdMemCpyRamToRam(&CanTxSignalsEx[offset], pValue, (canuint8)DbkTxSigMask[SigHdl]);
#  endif
# endif
  EndTxWriteSync();
}
/* CODE CATEGORY 2 END*/
#endif

/* CODE CATEGORY 2 START*/
/*--------------------------------------------------------------------------*/
void DBK_API_CALL_TYPE dbkPutnByte(DbkSigHandleType SigHdl, TxDataPtr pValue)
/*write 3-8 BYTE-Signals from databuffer*/
/*--------------------------------------------------------------------------*/
{
  DbkTxOffsetType offset;                   /*offset fuer das Messagefeld*/
  canuint8 signal_state;             /*Ergebnis des Signalbewerters*/
  t_TxSigSwitch  Switch;
# if defined( TX_CONTAINER_GAPS_NBYTE )
  vsintx i;
# endif
  /* Test auf richtigen Typ*/
# if !defined( GENy )
  assertUser((DbkTxSigType[SigHdl] == TYP_NBYTE), kBadSignalType);
# endif
  Switch =  DbkTxSigSwitch[SigHdl];
  /*get RAM type and offset:*/
  offset = DbkTxSigOffset[SigHdl];                /*get offset*/
  /* Signalbewertung (ind. ueber s_mode)*/
  assertUser((CanTxnByteEvalFunctions[Switch.s_mode] != V_NULL), kBadSignalMode);
  StartTxWriteSync();
  signal_state = (CanTxnByteEvalFunctions[Switch.s_mode])(SigHdl, pValue);
  if (Switch.s_mode_sign == 1) 
  {
    signal_state = (canuint8)!signal_state;
  }
  /*EXRAM*/
# if defined( TX_CONTAINER_GAPS_NBYTE ) 
  for (i = (vsintx)(DbkTxSigMask[SigHdl]-1); i >= (vsintx)0; i--)
  {
    CanTxSignalsEx[offset+i] &= (canuint8)~DbkTxSignByteMask[DbkTxSigStartbit[SigHdl]+i];
    CanTxSignalsEx[offset+i] |= (canuint8)(*((pValue)+i) & DbkTxSignByteMask[DbkTxSigStartbit[SigHdl]+i]);
  }
# else
#  if defined(V_ENABLE_USED_GLOBAL_VAR)
  VStdMemCpyFarRamToFarRam(&CanTxSignalsEx[offset], pValue, (canuint8)DbkTxSigMask[SigHdl]);
#  else
  VStdMemCpyRamToRam(&CanTxSignalsEx[offset], pValue, (canuint8)DbkTxSigMask[SigHdl]);
#  endif
# endif
  EndTxWriteSync();
  /*Senden ueber T1/#T2 freigeben*/
  /* send immediately ?*/
  if (Switch.s_put != 0)
  {
    (void)dbkTransmit(DbkTxSigMessageHdl[SigHdl]);
  }
  DbkInterruptDisable();
  if (signal_state != 0)
  {/*set bit in 'TX msg signal_state'*/
    CanTxSignalState[ DbkTxSigSignalStateOffset[SigHdl] ] |= DbkTxSigSignalStateMask[SigHdl];
    if (DbkTxMsgAttributes[DbkTxSigMessageHdl[SigHdl]].s_sofort == 1)
    {
      CanTxMsgStatus[DbkTxSigMessageHdl[SigHdl]] |= kCanTxSendImmdt;
    }
    if (DbkTxMsgAttributes[DbkTxSigMessageHdl[SigHdl]].s_demmand == 1)
    {
      CanTxMsgNRepZaehler[DbkTxSigMessageHdl[SigHdl]] = DbkTxMsgNRepeat[DbkTxSigMessageHdl[SigHdl]];
    }
  }
  else
  {/*clear bit in 'TX msg signal_state'*/
    CanTxSignalState[ DbkTxSigSignalStateOffset[SigHdl] ] &= (canuint8)~DbkTxSigSignalStateMask[SigHdl];
  }
  DbkInterruptRestore();
}
/* CODE CATEGORY 2 END*/
#endif




#if (defined _NBYTE_RX_SIGNALE_AKTIV)
/* CODE CATEGORY 2 START*/
/*--------------------------------------------------------------------------*/
TxDataPtr DBK_API_CALL_TYPE dbkGetRxnByte(DbkSigHandleType SigHdl)
/*read 3-8 BYTE-Signals from receive-databuffer*/
/*--------------------------------------------------------------------------*/
{
  DbkRxOffsetType offset;        /*offset fuer das Messagefeld*/
  TxDataPtr sign;
  /* Test auf richtigen Typ*/
  assertUser((DbkRxSigType[SigHdl] == TYP_NBYTE), kBadSignalType);
  offset = DbkRxSigOffset[SigHdl];                   /*get offset*/

  /*check location of signal*/
  /*EXRAM*/
  sign = &CanRxSignalsEx[offset];

  return sign;
}
/* CODE CATEGORY 2 END*/
#endif

/*==========================================================================*/
/*===============  Sonderfunktionen: Schreiben in RX-Puffer ================*/
/*==========================================================================*/
#ifdef _BYTE_PUTRX_AKTIV
/* CODE CATEGORY 2 START*/
/****************************************************************************/
void DBK_API_CALL_TYPE dbkPutRxByte(DbkSigHandleType SigHdl, canuint8 value)
/****************************************************************************/
{
  StartRxWriteSync();
  CanRxSignalsEx[DbkRxSigOffset[SigHdl]] &= (canuint8)~(canuint8)DbkRxSigMask[SigHdl];
  CanRxSignalsEx[DbkRxSigOffset[SigHdl]] |= (canuint8)((canuint8)(value << DbkRxSigStartbit[SigHdl]) & (canuint8)DbkRxSigMask[SigHdl]); /*cosmic -pck*/
  EndRxWriteSync();
}
/* CODE CATEGORY 2 END*/
#endif /*#ifdef _BYTE_PUTRX_AKTIV*/

#ifdef _WORD_PUTRX_AKTIV
/* CODE CATEGORY 2 START*/
/****************************************************************************/
void DBK_API_CALL_TYPE dbkPutRxWord(DbkSigHandleType SigHdl, canuint16 value)
/****************************************************************************/
{
#if defined DBK_ENABLE_RX_DYN_BYTESWAP
  t_RxSigSwitch  Switch;
  Switch =  DbkRxSigSwitch[SigHdl];
#endif
  StartRxWriteSync();
  value <<= DbkRxSigStartbit[SigHdl];

#if defined DBK_ENABLE_RX_DYN_BYTESWAP
  if(Switch.s_container_swap == 1) 
#endif
  {
#if ((defined DBK_ENABLE_RX_GENERAL_BYTESWAP) || (defined DBK_ENABLE_RX_DYN_BYTESWAP))
  CanRxSignalsEx[DbkRxSigOffset[SigHdl]]   &= (canuint8) ~ *(((V_MEMROM1 vuint8 V_MEMROM2 V_MEMROM3*)&DbkRxSigMask[SigHdl])+1);
  CanRxSignalsEx[DbkRxSigOffset[SigHdl]]   |= (canuint8)((*(((canuint8*)&value)+1)) & (*(((V_MEMROM1 vuint8 V_MEMROM2 V_MEMROM3*)&DbkRxSigMask[SigHdl])+1)));
  CanRxSignalsEx[DbkRxSigOffset[SigHdl]+1]   &= (canuint8) ~ *(((V_MEMROM1 vuint8 V_MEMROM2 V_MEMROM3*)&DbkRxSigMask[SigHdl]));
  CanRxSignalsEx[DbkRxSigOffset[SigHdl]+1]   |= (canuint8)((*(((canuint8*)&value))) & (*(((V_MEMROM1 vuint8 V_MEMROM2 V_MEMROM3*)&DbkRxSigMask[SigHdl]))));
#endif /*#if ((defined DBK_ENABLE_RX_GENERAL_BYTESWAP) || (defined DBK_ENABLE_RX_DYN_BYTESWAP)*/
  }
#if defined DBK_ENABLE_RX_DYN_BYTESWAP
  else
#endif
  {
#if ((defined DBK_ENABLE_RX_NEVER_BYTESWAP) || (defined DBK_ENABLE_RX_DYN_BYTESWAP))
# if defined C_BYTE_ACCESS_DBKOM
  CanRxSignalsEx[DbkRxSigOffset[SigHdl]]   &= (canuint8) ~ *(((V_MEMROM1 vuint8 V_MEMROM2 V_MEMROM3*)&DbkRxSigMask[SigHdl]));
  CanRxSignalsEx[DbkRxSigOffset[SigHdl]]   |= (*(((canuint8*)&value))) & (*(((V_MEMROM1 vuint8 V_MEMROM2 V_MEMROM3*)&DbkRxSigMask[SigHdl])));
  CanRxSignalsEx[DbkRxSigOffset[SigHdl]+1]   &= (canuint8) ~ *(((V_MEMROM1 vuint8 V_MEMROM2 V_MEMROM3*)&DbkRxSigMask[SigHdl])+1);
  CanRxSignalsEx[DbkRxSigOffset[SigHdl]+1]   |= (*(((canuint8*)&value)+1)) & (*(((V_MEMROM1 vuint8 V_MEMROM2 V_MEMROM3*)&DbkRxSigMask[SigHdl])+1));
# else  /*C_BYTE_ACCESS_DBKOM*/
#  if defined(V_ENABLE_USED_GLOBAL_VAR)
  *(@far @gpage canuint16*)(&CanRxSignalsEx[DbkRxSigOffset[SigHdl]])  &= (canuint16)~DbkRxSigMask[SigHdl]; /*1:1*/
  *(@far @gpage canuint16*)(&CanRxSignalsEx[DbkRxSigOffset[SigHdl]])  |= (value & DbkRxSigMask[SigHdl]);
#  else
  *(canuint16*)(&CanRxSignalsEx[DbkRxSigOffset[SigHdl]])  &= (canuint16)~DbkRxSigMask[SigHdl]; /*1:1*/
  *(canuint16*)(&CanRxSignalsEx[DbkRxSigOffset[SigHdl]])  |= (value & DbkRxSigMask[SigHdl]);
#  endif
# endif /*C_BYTE_ACCESS_DBKOM*/
#endif
  }
  EndRxWriteSync();
}
/* CODE CATEGORY 2 END*/
#endif /*#ifdef _WORD_PUTRX_AKTIV*/



#ifdef _NBYTE_PUTRX_AKTIV
/* CODE CATEGORY 2 START*/
/****************************************************************************/
void DBK_API_CALL_TYPE dbkPutRxnByteInternal(DbkSigHandleType SigHdl, V_MEMROM1 vuint8 V_MEMROM2 V_MEMROM3* value)
/****************************************************************************/
{
# if defined( RX_CONTAINER_GAPS_NBYTE )
  vsintx i;
# endif
  StartRxWriteSync();
# if defined( RX_CONTAINER_GAPS_NBYTE )
  for (i = (vsintx) (DbkRxSigMask[SigHdl]-1); i >= (vsintx)0; i--)
  {
    *(&CanRxSignalsEx[DbkRxSigOffset[SigHdl]]+i) &= (canuint8)~DbkRxSignByteMask[DbkRxSigStartbit[SigHdl]+i];
    *(&CanRxSignalsEx[DbkRxSigOffset[SigHdl]]+i) |= (canuint8)(*(value+DBK_EIGHTBIT_CAST i) & DbkRxSignByteMask[DbkRxSigStartbit[SigHdl]+i]);
  }
# else                                            /* RX_CONTAINER_GAPS_NBYTE  */ 
  VStdMemCpyRomToFarRam(&CanRxSignalsEx[DbkRxSigOffset[SigHdl]], (V_MEMROM1 void V_MEMROM2 V_MEMROM3*)value, DbkRxSigMask[SigHdl]);
# endif                                           /* RX_CONTAINER_GAPS_NBYTE */
  EndRxWriteSync();
}
/* CODE CATEGORY 2 END*/

/* CODE CATEGORY 2 START*/
/****************************************************************************/
void DBK_API_CALL_TYPE dbkPutRxnByte(DbkSigHandleType SigHdl, TxDataPtr value)
/****************************************************************************/
{
# if defined( RX_CONTAINER_GAPS_NBYTE )
  vsintx i;
# endif
  StartRxWriteSync();
# if defined( RX_CONTAINER_GAPS_NBYTE )
  for (i = (vsintx) (DbkRxSigMask[SigHdl]-1); i >= (vsintx)0; i--)
  {
    *(&CanRxSignalsEx[DbkRxSigOffset[SigHdl]]+i) &= (canuint8)~DbkRxSignByteMask[DbkRxSigStartbit[SigHdl]+i];
    *(&CanRxSignalsEx[DbkRxSigOffset[SigHdl]]+i) |= (canuint8)(*(value+DBK_EIGHTBIT_CAST i) & DbkRxSignByteMask[DbkRxSigStartbit[SigHdl]+i]);
  }
# else                                            /* RX_CONTAINER_GAPS_NBYTE  */ 
  VStdMemCpyFarRamToFarRam(&CanRxSignalsEx[DbkRxSigOffset[SigHdl]], value, DbkRxSigMask[SigHdl]);
# endif                                           /* RX_CONTAINER_GAPS_NBYTE */
  EndRxWriteSync();
}
/* CODE CATEGORY 2 END*/
#endif  /*#ifdef _NBYTE_PUTRX_AKTIV*/


/*==========================================================================*/
/*================  Signalbewertungsfunktionen =============================*/
/*==========================================================================*/
/*Note: Parameter fuer die Signalbewertungsfunktionen beginnen immer mit Bit 0!*/
/*      Benoetigt ein Signal nur einen Teil des Bytes so ist der Rest 0!*/
/*============================ N B I T ======================================*/
#ifdef _NBIT_TX_SIGNALE_AKTIV
/*--------------------------------------------------------------------------*/
/*TX-Funktionen:*/
/*--------------------------------------------------------------------------*/
# if defined ( NBIT_TX_EVALMODE_1_USED )
/* CODE CATEGORY 2 START*/
canuint8 dbkTxSignBitEval1(DbkSigHandleType SigHdl, canuint8 Value)
/*Bewertungsfunktion2: new == old ?*/
{
  return
  ((canuint8)((Value == dbkGetTxnBit(SigHdl))  ?  True : False));   /* new == old?*/
}
/* CODE CATEGORY 2 END*/
# endif
# if defined ( NBIT_TX_EVALMODE_2_USED )
/* CODE CATEGORY 2 START*/
canuint8 dbkTxSignBitEval2(DbkSigHandleType SigHdl, canuint8 Value)
/*Bewertungsfunktion3: new < old ?*/
{
  return
  ((canuint8)((Value < dbkGetTxnBit(SigHdl))  ?  True : False));    /* new < old?*/
}
/* CODE CATEGORY 2 END*/
# endif
# if defined ( NBIT_TX_EVALMODE_3_USED )
/* CODE CATEGORY 2 START*/
canuint8 dbkTxSignBitEval3(DbkSigHandleType SigHdl, canuint8 Value)
/*Bewertungsfunktion4: new > old ?*/
{
  return
  ((canuint8)((Value > dbkGetTxnBit(SigHdl))  ?  True : False));    /* new > old?*/
}
/* CODE CATEGORY 2 END*/
# endif
# if defined ( NBIT_TX_EVALMODE_5_USED )
/* CODE CATEGORY 2 START*/
canuint8 dbkTxSignBitEval5(DbkSigHandleType SigHdl, canuint8 Value)
/*Bewertungsfunktion6:  Keine Aenderung im Signalwert ?*/
{
  canuint8 x1;

  /*get parameter*/
  x1 = (canuint8)DbkTxSigX1[SigHdl];                        /*Lo Byte only*/
  return
  ((canuint8)(((Value & x1) == (dbkGetTxnBit(SigHdl) & x1))  ?  True : False));   /* Val&x1 == old&x1 ?*/
}
/* CODE CATEGORY 2 END*/
# endif
#endif

#ifdef _NBIT_SIGNALE_AKTIV
# if defined ( NBIT_TX_EVALMODE_6_USED ) || defined ( NBIT_RX_EVALMODE_6_USED )
/* CODE CATEGORY 1 START*/
canuint8 dbkSignBitEval6(DbkSigHandleType SigHdl, canuint8 Value)
/*Bewertungsfunktion7:  Signal = True!*/
{
#  if defined( V_ENABLE_USE_DUMMY_STATEMENT )
    SigHdl = SigHdl;
    Value  = Value;
#  endif
  return True;
}
/* CODE CATEGORY 1 END*/
# endif
#endif

#ifdef _NBIT_BYTE_TX_SIGNALE_AKTIV
# if defined ( NBIT_TX_EVALMODE_0_USED ) || defined ( BYTE_TX_EVALMODE_0_USED )
/* CODE CATEGORY 2 START*/
canuint8 dbkTxSignBitByteEval0(DbkSigHandleType SigHdl, canuint8 Value)
/*Bewertungsfunktion1: new == Schalterkonf.?*/
{
  return
  (canuint8)(((Value & (canuint8)DbkTxSigX1[SigHdl]) == (canuint8)DbkTxSigX2[SigHdl])  ?  True : False);   /* new == Schalterkonf.?*/
}
/* CODE CATEGORY 2 END*/
# endif
# if defined ( NBIT_TX_EVALMODE_4_USED ) || defined ( BYTE_TX_EVALMODE_4_USED )
/* CODE CATEGORY 2 START*/
canuint8 dbkTxSignBitByteEval4(DbkSigHandleType SigHdl, canuint8 Value)
/*Bewertungsfunktion5:  Signal innerhalb Bereich ?*/
{
  return
  ((canuint8)((((canuint8)DbkTxSigX1[SigHdl] <= Value) && (Value <= (canuint8)DbkTxSigX2[SigHdl]))  ?  True : False));   /* x1<=Val<=x2 ?*/
}
/* CODE CATEGORY 2 END*/
# endif
#endif

#ifdef _NBIT_RX_SIGNALE_AKTIV
/*RX-Funktionen:*/
# if defined ( NBIT_RX_EVALMODE_1_USED )
/* CODE CATEGORY 1 START*/
canuint8 dbkRxSignBitEval1(DbkSigHandleType SigHdl, canuint8 Value)
/*Bewertungsfunktion2: new == old ?*/
{
  return
  ((canuint8)((Value == dbkGetRxnBit(SigHdl))  ?  True : False));   /* new == old?*/
}
/* CODE CATEGORY 1 END*/
# endif
# if defined ( NBIT_RX_EVALMODE_2_USED )
/* CODE CATEGORY 1 START*/
canuint8 dbkRxSignBitEval2(DbkSigHandleType SigHdl, canuint8 Value)
/*Bewertungsfunktion3: new < old ?*/
{
  return
  ((canuint8)((Value < dbkGetRxnBit(SigHdl))  ?  True : False));    /* new < old?*/
}
/* CODE CATEGORY 1 END*/
# endif
# if defined ( NBIT_RX_EVALMODE_3_USED )
/* CODE CATEGORY 1 START*/
canuint8 dbkRxSignBitEval3(DbkSigHandleType SigHdl, canuint8 Value)
/*Bewertungsfunktion4: new > old ?*/
{
  return
  ((canuint8)((Value > dbkGetRxnBit(SigHdl))  ?  True : False));    /* new > old?*/
}
/* CODE CATEGORY 1 END*/
# endif
# if defined ( NBIT_RX_EVALMODE_5_USED )
/* CODE CATEGORY 1 START*/
canuint8 dbkRxSignBitEval5(DbkSigHandleType SigHdl, canuint8 Value)
/*Bewertungsfunktion6:  Keine Aenderung im Signalwert ?*/
{
  canuint8 x1;

  x1 = (canuint8)DbkRxSigX1[SigHdl];                        /*Lo Byte only*/

  return
  ((canuint8)(((Value & x1) == (dbkGetRxnBit(SigHdl) & x1))  ?  True : False));   /* Val&x1 == old&x1 ?*/
}
/* CODE CATEGORY 1 END*/
# endif
#endif   /*end of evaluation functions for Signals type 'nBit'*/


#ifdef _NBIT_BYTE_RX_SIGNALE_AKTIV
# if defined ( NBIT_RX_EVALMODE_0_USED ) || defined ( BYTE_RX_EVALMODE_0_USED )
/* CODE CATEGORY 1 START*/
canuint8 dbkRxSignBitByteEval0(DbkSigHandleType SigHdl, canuint8 Value)
/*Bewertungsfunktion1: new == Schalterkonf.?*/
{
  return
    (canuint8)(((Value & (canuint8)DbkRxSigX1[SigHdl]) == (canuint8)DbkRxSigX2[SigHdl])  ?  True : False);   /* new == Schalterkonf.?*/
}
/* CODE CATEGORY 1 END*/
# endif
# if defined ( NBIT_RX_EVALMODE_4_USED ) || defined ( BYTE_RX_EVALMODE_4_USED )
/* CODE CATEGORY 1 START*/
canuint8 dbkRxSignBitByteEval4(DbkSigHandleType SigHdl, canuint8 Value)
/*Bewertungsfunktion5:  Signal innerhalb Bereich ?*/
{
  return
  ((canuint8)((((canuint8)DbkRxSigX1[SigHdl] <= Value) && (Value <= (canuint8)DbkRxSigX2[SigHdl]))  ?  True : False));   /* x1<=Val<=x2 ?*/
}
/* CODE CATEGORY 1 END*/
# endif
#endif

/*============================ N 1 6 B I T ==================================*/
#ifdef _N16BIT_TX_SIGNALE_AKTIV
# if defined ( N16BIT_TX_EVALMODE_1_USED )
/* CODE CATEGORY 2 START*/
canuint8 dbkTxSign16BitEval1(DbkSigHandleType SigHdl, canuint16 Value)
/*Bewertungsfunktion2: new == old ?*/
{
  return
  ((canuint8)((Value == dbkGetTxn16Bit(SigHdl))  ?  True : False));   /* new == old?*/
}
/* CODE CATEGORY 2 END*/
# endif
# if defined ( N16BIT_TX_EVALMODE_2_USED )
/* CODE CATEGORY 2 START*/
canuint8 dbkTxSign16BitEval2(DbkSigHandleType SigHdl, canuint16 Value)
/*Bewertungsfunktion3: new < old ?*/
{
  return
  ((canuint8)((Value < dbkGetTxn16Bit(SigHdl))  ?  True : False));    /* new < old?*/
}
/* CODE CATEGORY 2 END*/
# endif
# if defined ( N16BIT_TX_EVALMODE_3_USED )
/* CODE CATEGORY 2 START*/
canuint8 dbkTxSign16BitEval3(DbkSigHandleType SigHdl, canuint16 Value)
/*Bewertungsfunktion4: new > old ?*/
{
  return
  ((canuint8)((Value > dbkGetTxn16Bit(SigHdl))  ?  True : False));    /* new > old?*/
}
/* CODE CATEGORY 2 END*/
# endif
# if defined ( N16BIT_TX_EVALMODE_5_USED )
/* CODE CATEGORY 2 START*/
canuint8 dbkTxSign16BitEval5(DbkSigHandleType SigHdl, canuint16 Value)
/*Bewertungsfunktion6:  Keine Aenderung im Signalwert ?*/
{
  canuint16 x1;

  /*get parameter*/
  x1 = DbkTxSigX1[SigHdl];                                /*Lo Byte only*/

  return
  ((canuint8)(((Value & x1) == (dbkGetTxn16Bit(SigHdl) & x1))  ?  True : False));   /* Val&x1 == old&x1 ?*/
}
/* CODE CATEGORY 2 END*/
# endif
#endif

#ifdef _N16BIT_WORD_TX_SIGNALE_AKTIV
# if defined ( N16BIT_TX_EVALMODE_0_USED ) || defined ( WORD_TX_EVALMODE_0_USED )
/* CODE CATEGORY 2 START*/
canuint8 dbkTxSign16BitWordEval0(DbkSigHandleType SigHdl, canuint16 Value)
/*Bewertungsfunktion1: new == Schalterkonf.?*/
{
  return
  (canuint8)(((Value & DbkTxSigX1[SigHdl]) == DbkTxSigX2[SigHdl])  ?  True : False);   /* new == Schalterkonf.?*/
}
/* CODE CATEGORY 2 END*/
# endif
# if defined ( N16BIT_TX_EVALMODE_4_USED ) || defined ( WORD_TX_EVALMODE_4_USED )
/* CODE CATEGORY 2 START*/
canuint8 dbkTxSign16BitWordEval4(DbkSigHandleType SigHdl, canuint16 Value)
/*Bewertungsfunktion5:  Signal innerhalb Bereich ?*/
{
  return
  ((canuint8)(((DbkTxSigX1[SigHdl] <= Value) && (Value <= DbkTxSigX2[SigHdl]))  ?  True : False));   /* x1<=Val<=x2 ?*/
}
/* CODE CATEGORY 2 END*/
# endif
#endif

#ifdef _N16BIT_SIGNALE_AKTIV
# if defined ( N16BIT_TX_EVALMODE_6_USED ) || defined ( N16BIT_RX_EVALMODE_6_USED )
/* CODE CATEGORY 1 START*/
canuint8 dbkSign16BitEval6(DbkSigHandleType SigHdl, canuint16 Value)
/*Bewertungsfunktion7:  Signal = True!*/
{
#  if defined( V_ENABLE_USE_DUMMY_STATEMENT )
  SigHdl = SigHdl;
  Value = Value;
#  endif
  return True;
}
/* CODE CATEGORY 1 END*/
# endif
#endif

#ifdef _N16BIT_RX_SIGNALE_AKTIV
# if defined ( N16BIT_RX_EVALMODE_1_USED )
/* CODE CATEGORY 1 START*/
/*RX-Funktionen:*/
canuint8 dbkRxSign16BitEval1(DbkSigHandleType SigHdl, canuint16 Value)
/*Bewertungsfunktion2: new == old ?*/
{
  return
  ((canuint8)((Value == dbkGetRxn16Bit(SigHdl))  ?  True : False));   /* new == old?*/
}
/* CODE CATEGORY 1 END*/
# endif
# if defined ( N16BIT_RX_EVALMODE_2_USED )
/* CODE CATEGORY 1 START*/
canuint8 dbkRxSign16BitEval2(DbkSigHandleType SigHdl, canuint16 Value)
/*Bewertungsfunktion3: new < old ?*/
{
  return
  ((canuint8)((Value < dbkGetRxn16Bit(SigHdl))  ?  True : False));    /* new < old?*/
}
/* CODE CATEGORY 1 END*/
# endif
# if defined ( N16BIT_RX_EVALMODE_3_USED )
/* CODE CATEGORY 1 START*/
canuint8 dbkRxSign16BitEval3(DbkSigHandleType SigHdl, canuint16 Value)
/*Bewertungsfunktion4: new > old ?*/
{
  return
  ((canuint8)((Value > dbkGetRxn16Bit(SigHdl))  ?  True : False));    /* new > old?*/
}
/* CODE CATEGORY 1 END*/
# endif
# if defined ( N16BIT_RX_EVALMODE_5_USED )
/* CODE CATEGORY 1 START*/
canuint8 dbkRxSign16BitEval5(DbkSigHandleType SigHdl, canuint16 Value)
/*Bewertungsfunktion6:  Keine Aenderung im Signalwert ?*/
{
  canuint16 x1;

  x1 = DbkRxSigX1[SigHdl];                                /*Lo Byte only*/

  return
  ((canuint8)(((Value & x1) == (dbkGetRxn16Bit(SigHdl) & x1))  ?  True : False));   /* Val&x1 == old&x1 ?*/
}
/* CODE CATEGORY 1 END*/
# endif
#endif   /*end of evaluation functions for Signals type 'n16Bit'*/

#ifdef _N16BIT_WORD_RX_SIGNALE_AKTIV
/*RX-Funktionen:*/
# if defined ( N16BIT_RX_EVALMODE_0_USED ) || defined ( WORD_RX_EVALMODE_0_USED )
/* CODE CATEGORY 1 START*/
canuint8 dbkRxSign16BitWordEval0(DbkSigHandleType SigHdl, canuint16 Value)
/*Bewertungsfunktion1: new == Schalterkonf.?*/
{
  return
  ((canuint8)(((Value & DbkRxSigX1[SigHdl]) == DbkRxSigX2[SigHdl])  ?  True : False));   /* new == Schalterkonf.?*/
}
/* CODE CATEGORY 1 END*/
# endif
# if defined ( N16BIT_RX_EVALMODE_4_USED ) || defined ( WORD_RX_EVALMODE_4_USED )
/* CODE CATEGORY 1 START*/
canuint8 dbkRxSign16BitWordEval4(DbkSigHandleType SigHdl, canuint16 Value)
/*Bewertungsfunktion5:  Signal innerhalb Bereich ?*/
{
  return
  ((canuint8)(((DbkRxSigX1[SigHdl] <= Value) && (Value <= DbkRxSigX2[SigHdl]))  ?  True : False));   /* x1<=Val<=x2 ?*/
}
/* CODE CATEGORY 1 END*/
# endif
#endif

/*============================ B Y T E ======================================*/
#ifdef _BYTE_TX_SIGNALE_AKTIV
# if defined ( BYTE_TX_EVALMODE_1_USED )
/* CODE CATEGORY 2 START*/
canuint8 dbkTxSigByteEval1(DbkSigHandleType SigHdl, canuint8 Value)
/*Bewertungsfunktion2: new == old ?*/
{
  return
  ((canuint8)((Value == dbkGetTxByte(SigHdl))  ?  True : False));     /* new == old?*/
}
/* CODE CATEGORY 2 END*/
# endif
# if defined ( BYTE_TX_EVALMODE_2_USED )
/* CODE CATEGORY 2 START*/
canuint8 dbkTxSigByteEval2(DbkSigHandleType SigHdl, canuint8 Value)
/*Bewertungsfunktion3: new < old ?*/
{
  return
  ((canuint8)((Value < dbkGetTxByte(SigHdl))  ?  True : False));      /* new < old?*/
}
/* CODE CATEGORY 2 END*/
# endif
# if defined ( BYTE_TX_EVALMODE_3_USED )
/* CODE CATEGORY 2 START*/
canuint8 dbkTxSigByteEval3(DbkSigHandleType SigHdl, canuint8 Value)
/*Bewertungsfunktion4: new > old ?*/
{
  return
  ((canuint8)((Value > dbkGetTxByte(SigHdl)) ?  True : False));       /* new > old?*/
}
/* CODE CATEGORY 2 END*/
# endif
# if defined ( BYTE_TX_EVALMODE_5_USED )
/* CODE CATEGORY 2 START*/
canuint8 dbkTxSigByteEval5(DbkSigHandleType SigHdl, canuint8 Value)
/*Bewertungsfunktion6:  Keine Aenderung im Signalwert ?*/
{
  canuint8 x1;
  x1 = (canuint8)DbkTxSigX1[SigHdl];                          /*Lo Byte only*/

  return
  ((canuint8)(((Value & x1) == (dbkGetTxByte(SigHdl) & x1))  ?  True : False));   /* Val&x1 == old&x1 ?*/
}
/* CODE CATEGORY 2 END*/
# endif
#endif   /*end of evaluation functions for Signals type 'Byt'*/


#ifdef _BYTE_SIGNALE_AKTIV
# if defined ( BYTE_TX_EVALMODE_6_USED ) || defined ( BYTE_RX_EVALMODE_6_USED )
/* CODE CATEGORY 1 START*/
canuint8 dbkSigByteEval6(DbkSigHandleType SigHdl, canuint8 Value)
/*Bewertungsfunktion7:  Signal = True!*/
{
#  if defined( V_ENABLE_USE_DUMMY_STATEMENT )
  SigHdl = SigHdl;
  Value  = Value;
#  endif

  return True;
}
/* CODE CATEGORY 1 END*/
# endif
#endif

#ifdef _BYTE_RX_SIGNALE_AKTIV
# if defined ( BYTE_RX_EVALMODE_1_USED )
/* CODE CATEGORY 1 START*/
canuint8 dbkRxSigByteEval1(DbkSigHandleType SigHdl, canuint8 Value)
/*Bewertungsfunktion2: new == old ?*/
{
  return
  ((canuint8)((Value == dbkGetRxByte(SigHdl))  ?  True : False));     /* new == old?*/
}
/* CODE CATEGORY 1 END*/
# endif
# if defined ( BYTE_RX_EVALMODE_2_USED )
/* CODE CATEGORY 1 START*/
canuint8 dbkRxSigByteEval2(DbkSigHandleType SigHdl, canuint8 Value)
/*Bewertungsfunktion3: new < old ?*/
{
  return
  ((canuint8)((Value < dbkGetRxByte(SigHdl))  ?  True : False));      /* new < old?*/
}
/* CODE CATEGORY 1 END*/
# endif
# if defined ( BYTE_RX_EVALMODE_3_USED )
/* CODE CATEGORY 1 START*/
canuint8 dbkRxSigByteEval3(DbkSigHandleType SigHdl, canuint8 Value)
/*Bewertungsfunktion4: new > old ?*/
{
  return
  ((canuint8)((Value > dbkGetRxByte(SigHdl))  ?  True : False));      /* new > old?*/
}
/* CODE CATEGORY 1 END*/
# endif
# if defined ( BYTE_RX_EVALMODE_5_USED )
/* CODE CATEGORY 1 START*/
canuint8 dbkRxSigByteEval5(DbkSigHandleType SigHdl, canuint8 Value)
/*Bewertungsfunktion6:  Keine Aenderung im Signalwert ?*/
{
  canuint8 x1;
  x1 = (canuint8)DbkRxSigX1[SigHdl];                          /*Lo Byte only*/

  return
  ((canuint8)(((Value & x1) == (dbkGetRxByte(SigHdl) & x1))  ?  True : False));   /* Val&x1 == old&x1 ?*/
}
/* CODE CATEGORY 1 END*/
# endif
#endif   /*end of evaluation functions for Signals type 'Byte'*/


/*============================ W O R D ======================================*/
#ifdef _WORD_TX_SIGNALE_AKTIV
/*****************************************************************************/
# if defined ( WORD_TX_EVALMODE_1_USED )
/* CODE CATEGORY 2 START*/
canuint8 dbkTxSigWordEval1(DbkSigHandleType SigHdl, canuint16 Value)
/*Bewertungsfunktion2: new == old ?*/
{
  return
  ((canuint8)((Value == dbkGetTxWord(SigHdl))  ?  True : False));     /* new == old?*/
}
/* CODE CATEGORY 2 END*/
# endif
# if defined ( WORD_TX_EVALMODE_2_USED )
/* CODE CATEGORY 2 START*/
canuint8 dbkTxSigWordEval2(DbkSigHandleType SigHdl, canuint16 Value)
/*Bewertungsfunktion3: new < old ?*/
{
  return
  ((canuint8)((Value < dbkGetTxWord(SigHdl))  ?  True : False));      /* new < old?*/
}
/* CODE CATEGORY 2 END*/
# endif
# if defined ( WORD_TX_EVALMODE_3_USED )
/* CODE CATEGORY 2 START*/
canuint8 dbkTxSigWordEval3(DbkSigHandleType SigHdl, canuint16 Value)
/*Bewertungsfunktion4: new > old ?*/
{
  return
  ((canuint8)((Value > dbkGetTxWord(SigHdl))  ?  True : False));      /* new > old?*/
}
/* CODE CATEGORY 2 END*/
# endif
# if defined ( WORD_TX_EVALMODE_5_USED )
/* CODE CATEGORY 2 START*/
canuint8 dbkTxSigWordEval5(DbkSigHandleType SigHdl, canuint16 Value)
/*Bewertungsfunktion6:  Keine Aenderung im Signalwert ?*/
{
  canuint16 x1;
  x1 = DbkTxSigX1[SigHdl];

  return
  ((canuint8)(((Value & x1) == (dbkGetTxWord(SigHdl) & x1))  ?  True : False));   /* Val&x1 == old&x1 ?*/
}
/* CODE CATEGORY 2 END*/
# endif
#endif   /*end of evaluation functions for Signals type 'Byte'*/

#ifdef _WORD_SIGNALE_AKTIV
# if defined ( WORD_TX_EVALMODE_6_USED ) || defined ( WORD_RX_EVALMODE_6_USED )
/* CODE CATEGORY 1 START*/
canuint8 dbkSigWordEval6(DbkSigHandleType SigHdl, canuint16 Value)
/*Bewertungsfunktion7:  Signal = True!*/
{
#  if defined( V_ENABLE_USE_DUMMY_STATEMENT )
    SigHdl = SigHdl;
    Value  = Value;
#  endif

  return True;
}
/* CODE CATEGORY 1 END*/
# endif
#endif

#ifdef _WORD_RX_SIGNALE_AKTIV
/*RX-Funktionen:*/
# if defined ( WORD_RX_EVALMODE_1_USED )
/* CODE CATEGORY 1 START*/
canuint8 dbkRxSigWordEval1(DbkSigHandleType SigHdl, canuint16 Value)
/*Bewertungsfunktion2: new == old ?*/
{
  return
  ((canuint8)((Value == dbkGetRxWord(SigHdl))  ?  True : False));     /* new == old?*/
}
/* CODE CATEGORY 1 END*/
# endif
# if defined ( WORD_RX_EVALMODE_2_USED )
/* CODE CATEGORY 1 START*/
canuint8 dbkRxSigWordEval2(DbkSigHandleType SigHdl, canuint16 Value)
/*Bewertungsfunktion3: new < old ?*/
{
  return
  ((canuint8)((Value < dbkGetRxWord(SigHdl))  ?  True : False));      /* new < old?*/
}
/* CODE CATEGORY 1 END*/
# endif
# if defined ( WORD_RX_EVALMODE_3_USED )
/* CODE CATEGORY 1 START*/
canuint8 dbkRxSigWordEval3(DbkSigHandleType SigHdl, canuint16 Value)
/*Bewertungsfunktion4: new > old ?*/
{
  return
  ((canuint8)((Value > dbkGetRxWord(SigHdl))  ?  True : False));      /* new > old?*/
}
/* CODE CATEGORY 1 END*/
# endif
# if defined ( WORD_RX_EVALMODE_5_USED )
/* CODE CATEGORY 1 START*/
canuint8 dbkRxSigWordEval5(DbkSigHandleType SigHdl, canuint16 Value)
/*Bewertungsfunktion6:  Keine Aenderung im Signalwert ?*/
{
  canuint16 x1;
  x1 = DbkRxSigX1[SigHdl];

  return
  ((canuint8)(((Value & x1) == (dbkGetRxWord(SigHdl) & x1))  ?  True : False));   /* Val&x1 == old&x1 ?*/
}
/* CODE CATEGORY 1 END*/
# endif
#endif   /*end of evaluation functions for Signals type 'Word'*/



/*============================ N B Y T E =====================================*/
#if (defined _NBYTE_TX_SIGNALE_AKTIV)
# if ( defined NBYTE_TX_EVALMODE_0_USED )
/* CODE CATEGORY 2 START*/
canuint8 dbkTxSignByteEval0(DbkSigHandleType SigHdl, TxDataPtr pValue)
/*Bewertungsfunktion1: new == Schalterkonf.? (new & x1) == x2 */
{
  V_MEMROM1 canuint8 V_MEMROM2 V_MEMROM3 *x1;
  V_MEMROM1 canuint8 V_MEMROM2 V_MEMROM3 *x2;
  vsintx i;


  x1 = &DbkTxSignByteX1Value[DbkTxSigX1[SigHdl]];
  x2 = &DbkTxSignByteX2Value[DbkTxSigX2[SigHdl]];

  for (i=(vsintx) (DbkTxSigMask[SigHdl]-1); i >= (vsintx)0; i--)
  {
    if ( (pValue[DBK_EIGHTBIT_CAST i] & x1[DBK_EIGHTBIT_CAST i]) != x2[DBK_EIGHTBIT_CAST i] )
    {
      return False;
    }
  }
  return True;     /* (new & x1) == x2 */
}
/* CODE CATEGORY 2 END*/
# endif
# if ( defined NBYTE_TX_EVALMODE_1_USED )
/* CODE CATEGORY 2 START*/
canuint8 dbkTxSignByteEval1(DbkSigHandleType SigHdl, TxDataPtr pValue)
/*Bewertungsfunktion2: new == old ?*/
{
  TxDataPtr pOldval;
  vsintx i;


  /*get old signal*/
  pOldval = dbkGetTxnByte(SigHdl);

  for (i=(vsintx) (DbkTxSigMask[SigHdl]-1); i >= (vsintx)0; i--)
  {
#  ifdef TX_CONTAINER_GAPS_NBYTE
    if ( (pValue[DBK_EIGHTBIT_CAST i] & DbkTxSignByteMask[DbkTxSigStartbit[SigHdl]+i]) !=
         (pOldval[DBK_EIGHTBIT_CAST i]& DbkTxSignByteMask[DbkTxSigStartbit[SigHdl]+i]) )
    {
      return False;
    }
#  else
    if (pValue[DBK_EIGHTBIT_CAST i] != pOldval[DBK_EIGHTBIT_CAST i])
    {
      return False;
    }
#  endif
  }
  return True;
}
/* CODE CATEGORY 2 END*/
# endif
# if ( defined NBYTE_TX_EVALMODE_2_USED )
/* CODE CATEGORY 2 START*/
canuint8 dbkTxSignByteEval2(DbkSigHandleType SigHdl, TxDataPtr pValue)
/*Bewertungsfunktion3: new < old ? with significance */
{
  TxDataPtr pOldval;
#  ifdef TX_CONTAINER_GAPS_NBYTE
  V_MEMROM1 canuint8 V_MEMROM2 V_MEMROM3 *mask;
#  endif
  vsintx i;


  pOldval = dbkGetTxnByte(SigHdl);                  /* get old signal */

#  ifdef TX_CONTAINER_GAPS_NBYTE
  mask = &DbkTxSignByteMask[DbkTxSigStartbit[SigHdl]];
#  endif

  for (i=(vsintx)(DbkTxSigMask[SigHdl]-1); i >= (vsintx)0; i--)
  {
#  ifdef TX_CONTAINER_GAPS_NBYTE
    if ( (*(pValue) & *mask) <
         (*(pOldval)& *mask) )
    {
      return True;
    }
    if ( (*(pValue) & *mask) >
         (*(pOldval)& *mask) )
    {
      return False;
    }
    mask++;
#  else
    if (*(pValue) < *(pOldval))
    {
      return True;
    }
    else if (*(pValue) > *(pOldval))
    {
      return False;
    }
#  endif
    pValue++;
    pOldval++;
  }
  return False;                  /* new and old are equal */
}
/* CODE CATEGORY 2 END*/
# endif
# if ( defined NBYTE_TX_EVALMODE_3_USED )
/* CODE CATEGORY 2 START*/
canuint8 dbkTxSignByteEval3(DbkSigHandleType SigHdl, TxDataPtr pValue)
/*Bewertungsfunktion4: new > old ? with significance */
{
  TxDataPtr pOldval;
#  ifdef TX_CONTAINER_GAPS_NBYTE
 V_MEMROM1 canuint8 V_MEMROM2 V_MEMROM3 *mask;
#  endif
  vsintx i;


  pOldval = dbkGetTxnByte(SigHdl);                  /* get old signal */

#  ifdef TX_CONTAINER_GAPS_NBYTE
  mask = &DbkTxSignByteMask[DbkTxSigStartbit[SigHdl]];
#  endif

  for (i=(vsintx)(DbkTxSigMask[SigHdl]-1); i >= (vsintx)0; i--)
  {
#  ifdef TX_CONTAINER_GAPS_NBYTE
    if ( (*pValue  & *mask) >
         (*pOldval & *mask) )
    {
      return True;
    }
    if ( (*pValue  & *mask) <
         (*pOldval & *mask) )
    {
      return False;
    }
    mask++;
#  else
    if (*(pValue) > *(pOldval))
    {
      return True;
    }
    else if (*(pValue) < *(pOldval))
    {
      return False;
    }
#  endif
    pValue++;
    pOldval++;
  }
  return False;                  /* new and old are equal */
}
/* CODE CATEGORY 2 END*/
# endif
# if ( defined NBYTE_TX_EVALMODE_4_USED )
/* CODE CATEGORY 2 START*/
canuint8 dbkTxSignByteEval4(DbkSigHandleType SigHdl, TxDataPtr pValue)
/*Bewertungsfunktion5:  Signal innerhalb Bereich ?*/
{
  V_MEMROM1 canuint8 V_MEMROM2 V_MEMROM3 *x1;
  V_MEMROM1 canuint8 V_MEMROM2 V_MEMROM3 *x2;
#  ifdef TX_CONTAINER_GAPS_NBYTE
  canuint8 mask;
#  endif
  vsintx i;


  x1 = &DbkTxSignByteX1Value[ DbkTxSigX1[SigHdl]];
  x2 = &DbkTxSignByteX2Value[ DbkTxSigX2[SigHdl]];

  for (i=(vsintx)(DbkTxSigMask[SigHdl]-1); i >= (vsintx)0; i--)
  {
#  ifdef TX_CONTAINER_GAPS_NBYTE
    mask = DbkTxSignByteMask[DbkTxSigStartbit[SigHdl]+i];
    if ( ((pValue[DBK_EIGHTBIT_CAST i] & mask) < x1[DBK_EIGHTBIT_CAST i]) ||
         ((pValue[DBK_EIGHTBIT_CAST i] & mask) > x2[DBK_EIGHTBIT_CAST i]) )
#  else
    if ( (pValue[DBK_EIGHTBIT_CAST i] < x1[DBK_EIGHTBIT_CAST i]) ||
         (pValue[DBK_EIGHTBIT_CAST i] > x2[DBK_EIGHTBIT_CAST i]) )
#  endif
    {
      return False;
    }
  }
  return True;        /* x1<=Val<=x2 ?*/
}
/* CODE CATEGORY 2 END*/
# endif
# if ( defined NBYTE_TX_EVALMODE_5_USED )
/* CODE CATEGORY 2 START*/
canuint8 dbkTxSignByteEval5(DbkSigHandleType SigHdl, TxDataPtr pValue)
/*Bewertungsfunktion6:  Keine Aenderung im Signalwert ?*/
{
  V_MEMROM1 canuint8 V_MEMROM2 V_MEMROM3 *x1;
  TxDataPtr pOldval;
  vsintx i;

  /*get old signal*/
  pOldval = dbkGetTxnByte(SigHdl);

  x1 = &DbkTxSignByteX1Value[ DbkTxSigX1[SigHdl]];

  for (i=(vsintx)(DbkTxSigMask[SigHdl]-1); i >= (vsintx)0; i--)
  {
    if ( (pValue[DBK_EIGHTBIT_CAST i] & x1[DBK_EIGHTBIT_CAST i]) !=
         (pOldval[DBK_EIGHTBIT_CAST i] & x1[DBK_EIGHTBIT_CAST i]) )
    {
      return False;
    }
  }
  return True;                      /* Val&x1 == old&x1 ?*/
}
/* CODE CATEGORY 2 END*/
# endif
#endif   /*end of evaluation functions for Signals type 'nByte'*/

#if (defined  _NBYTE_SIGNALE_AKTIV)
# if ((defined NBYTE_TX_EVALMODE_6_USED ) || (defined  NBYTE_RX_EVALMODE_6_USED ))
/* CODE CATEGORY 1 START*/
canuint8 dbkSignByteEval6(DbkSigHandleType SigHdl, TxDataPtr pValue)
/*Bewertungsfunktion7:  Signal = True!*/
{
#  if defined( V_ENABLE_USE_DUMMY_STATEMENT )
  SigHdl = SigHdl;
  pValue = pValue;
#  endif

  return True;
}
/* CODE CATEGORY 1 END*/
# endif
#endif

#if (defined _NBYTE_RX_SIGNALE_AKTIV )
# if (defined NBYTE_RX_EVALMODE_0_USED )
/* CODE CATEGORY 1 START*/
/*RX-Funktionen:*/
canuint8 dbkRxSignByteEval0(DbkSigHandleType SigHdl, TxDataPtr pValue)
/*Bewertungsfunktion1: new == Schalterkonf.?*/
{
  V_MEMROM1 canuint8 V_MEMROM2 V_MEMROM3 *x1;
  V_MEMROM1 canuint8 V_MEMROM2 V_MEMROM3 *x2;
  vsintx i;


  x1 = &DbkRxSignByteX1Value[ DbkRxSigX1[SigHdl]];
  x2 = &DbkRxSignByteX2Value[ DbkRxSigX2[SigHdl]];

  for (i=(vsintx)(DbkRxSigMask[SigHdl]-1); i >= (vsintx)0; i--)
  {
    if ( (pValue[DBK_EIGHTBIT_CAST i] & x1[DBK_EIGHTBIT_CAST i]) != x2[DBK_EIGHTBIT_CAST i] )
    {
      return False;
    }
  }
  return True;    /* (new & x1) == x2 */
}
/* CODE CATEGORY 1 END*/
# endif
# if (defined NBYTE_RX_EVALMODE_1_USED )
/* CODE CATEGORY 1 START*/
canuint8 dbkRxSignByteEval1(DbkSigHandleType SigHdl, TxDataPtr pValue)
/*Bewertungsfunktion2: new == old ?*/
{
  TxDataPtr pOldval;
  vsintx i;


  /*get old signal*/
  pOldval = dbkGetRxnByte(SigHdl);

  for (i=(vsintx)(DbkRxSigMask[SigHdl]-1); i >= (vsintx)0; i--)
  {
#  ifdef RX_CONTAINER_GAPS_NBYTE
    if ( (pValue[DBK_EIGHTBIT_CAST i] & DbkRxSignByteMask[DbkRxSigStartbit[SigHdl]+i]) !=
         (pOldval[DBK_EIGHTBIT_CAST i]& DbkRxSignByteMask[DbkRxSigStartbit[SigHdl]+i]) )
    {
      return False;
    }
#  else
    if (pValue[DBK_EIGHTBIT_CAST i] != pOldval[DBK_EIGHTBIT_CAST i])
    {
      return False;
    }
#  endif
  }
  return True;
}
/* CODE CATEGORY 1 END*/
# endif
# if (defined NBYTE_RX_EVALMODE_2_USED )
/* CODE CATEGORY 1 START*/
canuint8 dbkRxSignByteEval2(DbkSigHandleType SigHdl, TxDataPtr pValue)
/*Bewertungsfunktion3: new < old ? with significance */
{
  TxDataPtr pOldval;
#  ifdef RX_CONTAINER_GAPS_NBYTE
  V_MEMROM1 canuint8 V_MEMROM2 V_MEMROM3 *mask;
#  endif
  vsintx i;


  pOldval = dbkGetRxnByte(SigHdl);                  /* get old signal */

#  ifdef RX_CONTAINER_GAPS_NBYTE
  mask = &DbkRxSignByteMask[DbkRxSigStartbit[SigHdl]];
#  endif

  for (i = 0; i < (vsintx) DbkRxSigMask[SigHdl]; i++)
  {
#  ifdef RX_CONTAINER_GAPS_NBYTE
    if ( (*pValue  & *mask) <
         (*pOldval & *mask) )
    {
      return True;
    }
    if ( (*pValue  & *mask) >
         (*pOldval & *mask) )
    {
      return False;
    }
    mask++;
#  else
    if (*pValue < *pOldval )
    {
      return True;
    }
    else if (*pValue > *pOldval)
    {
      return False;
    }
#  endif
    pValue++;
    pOldval++;
  }
  return False;                  /* new and old are equal */
}
/* CODE CATEGORY 1 END*/
# endif
# if (defined NBYTE_RX_EVALMODE_3_USED )
/* CODE CATEGORY 1 START*/
canuint8 dbkRxSignByteEval3(DbkSigHandleType SigHdl, TxDataPtr pValue)
/*Bewertungsfunktion4: new > old ? with significance */
{
  TxDataPtr pOldval;
#  ifdef RX_CONTAINER_GAPS_NBYTE
  V_MEMROM1 canuint8 V_MEMROM2 V_MEMROM3 *mask;
#  endif

  vsintx i;


  pOldval = dbkGetRxnByte(SigHdl);                  /* get old signal */
 
#  ifdef RX_CONTAINER_GAPS_NBYTE
  mask = &DbkRxSignByteMask[DbkRxSigStartbit[SigHdl]];
#  endif

  for (i = 0; i < (vsintx) DbkRxSigMask[SigHdl]; i++)
  {
#  ifdef RX_CONTAINER_GAPS_NBYTE
    if ( (*pValue  & *mask) >
         (*pOldval & *mask) )
    {
      return True;
    }
    if ( (*pValue & *mask) <
         (*pOldval& *mask) )
    {
      return False;
    }
    mask++;
#  else
    if (*pValue > *pOldval)
    {
      return True;
    }
    else if (*pValue < *pOldval)
    {
      return False;
    }
#  endif
    pValue++;
    pOldval++;
  }
  return False;                  /* new and old are equal */
}
/* CODE CATEGORY 1 END*/
# endif
# if (defined NBYTE_RX_EVALMODE_4_USED )
/* CODE CATEGORY 1 START*/
canuint8 dbkRxSignByteEval4(DbkSigHandleType SigHdl, TxDataPtr pValue)
/*Bewertungsfunktion5:  Signal innerhalb Bereich ?*/
{
  V_MEMROM1 canuint8 V_MEMROM2 V_MEMROM3 *x1;
  V_MEMROM1 canuint8 V_MEMROM2 V_MEMROM3 *x2;
#  ifdef RX_CONTAINER_GAPS_NBYTE
  canuint8 mask;
#  endif

  vsintx i;


  x1 = &DbkRxSignByteX1Value[ DbkRxSigX1[SigHdl] ];
  x2 = &DbkRxSignByteX2Value[ DbkRxSigX2[SigHdl] ];

  for (i=(vsintx) (DbkRxSigMask[SigHdl]-1); i >= (vsintx)0; i--)
  {
#  ifdef RX_CONTAINER_GAPS_NBYTE
    mask = DbkRxSignByteMask[DbkRxSigStartbit[SigHdl]+i];
    if ( ((pValue[DBK_EIGHTBIT_CAST i] & mask) < x1[DBK_EIGHTBIT_CAST i]) ||
         ((pValue[DBK_EIGHTBIT_CAST i] & mask) > x2[DBK_EIGHTBIT_CAST i]) )
#  else
    if ( (pValue[DBK_EIGHTBIT_CAST i] < x1[DBK_EIGHTBIT_CAST i]) ||
         (pValue[DBK_EIGHTBIT_CAST i] > x2[DBK_EIGHTBIT_CAST i]) )
#  endif
    {
      return False;
    }
  }
  return True;      /* x1<=Val<=x2 ?*/
}
/* CODE CATEGORY 1 END*/
# endif
# if (defined NBYTE_RX_EVALMODE_5_USED )
/* CODE CATEGORY 1 START*/
canuint8 dbkRxSignByteEval5(DbkSigHandleType SigHdl, TxDataPtr pValue)
/*Bewertungsfunktion6:  Keine Aenderung im Signalwert ?*/
{
  V_MEMROM1 canuint8 V_MEMROM2 V_MEMROM3 *x1;
  TxDataPtr pOldval;

  vsintx i;


  /*get old signal*/
  pOldval = dbkGetRxnByte(SigHdl);
  x1 = &DbkRxSignByteX1Value[ DbkRxSigX1[SigHdl]];

  for (i=(vsintx) (DbkRxSigMask[SigHdl]-1); i >= (vsintx)0; i--)
  {
    if ( (pValue[DBK_EIGHTBIT_CAST i] & x1[DBK_EIGHTBIT_CAST i]) !=
         (pOldval[DBK_EIGHTBIT_CAST i] & x1[DBK_EIGHTBIT_CAST i]) )
    {
      return False;
    }
  }
  return True;                      /* Val&x1 == old&x1 ?*/
}
/* CODE CATEGORY 1 END*/
# endif
#endif   /*end of evaluation functions for Signals type 'nByte'*/
/* End of all evaluation functions */

/*==========================================================================*/
/*==============    i n t e r r u p t S U B r o u t i n e s          =======*/
/*==========================================================================*/
/******************************************************************************
* NAME:               dbkConfirmation
* FUNCTIONGROUP:      DBKOM-Driver
* PROTOTYPE:          void dbkConfirmation(CanTransmitHandle MsgHdl)
* CALLED BY:          will be called by the Send-Interrupt-Function from Can-Driver
* PRECONDITIONS:      -
* INPUT PARAMETERS:   MsgHdl
* RETURN VALUE:       -
* DESCRIPTION:        Calls the Confirmation-Function or sets the
*                     Confirmation-Flags of a send signal, if this signal was
*                     sended (if desired from the user)
*
******************************************************************************/
/* CODE CATEGORY 1 START*/
/*--------------------------------------------------------------------------*/
void DBK_INTERNAL_CALL_TYPE dbkConfirmation(CanTransmitHandle txObject)
{
#if defined( DBK_ENABLE_TX_CONF_FLAG ) || defined( DBK_ENABLE_TX_CONF_FUNC )
  vsintx sigHdl;


  txObject = DbkTxMsgCanToDbkIndirection[txObject]; /* get old handle via re-indirection */

  if (DbkTxMsgAttributes[txObject].s_Msgconfirmation == 0)
  {
    return;
  }
  /* Confirmation Flags/Func. fuer alle Signale der Botschaft:*/
  for (sigHdl=(vsintx)(DbkTxMsgDataOffset[txObject+1]-1); sigHdl>=(vsintx)(DbkTxMsgDataOffset[txObject]); sigHdl--)       /* ueber alle Signale der Botschaft*/
  {
    if (DbkTxSigSwitch[sigHdl].s_confirmation == 1)
    {
# ifdef DBK_ENABLE_TX_CONF_FLAG
      /*set confirmation flag*/
      DbkTxConfirmationFlags._c[DbkTxSigConfirmationOffset[sigHdl]] |= DbkTxSigConfirmationMask[sigHdl];
# endif
# ifdef DBK_ENABLE_TX_CONF_FUNC
      /*execute confirmation function*/
#  ifndef V_ENABLE_USE_DUMMY_FUNCTIONS
#ifndef SignalConfirmationDummy
      #if defined ( DBK_ENABLE_GEN_CHECK )
   assertGen(1, kNoDummyFunctionDefined);   
      #endif
#endif /*#ifndef SignalConfirmationDummy*/
      if (DbkTxSigConfirmationFunc[sigHdl] != V_NULL)
#  endif
      {
        (DbkTxSigConfirmationFunc[sigHdl])();
      }
# endif
    }
  }
#else
# if defined( V_ENABLE_USE_DUMMY_STATEMENT )
  txObject = txObject;
# endif  
#endif
}
/* CODE CATEGORY 1 END*/


/******************************************************************************
* NAME:               dbkPrecopy
* FUNCTIONGROUP:      DBKOM-Driver 
* PROTOTYPE:          (dependant from configuration)
*                     canuint8 dbkPrecopy(pChipDataPtr RDS, CanReceiveHandle canRxHandle)
*                 or  canuint8 dbkPrecopy(pChipDataPtr RDS)
*                 or  canuint8 dbkPrecopy(CanReceiveHandle canRxHandle)
* CALLED BY:          will be called from the Receive function in the CAN-Driver
* PRECONDITIONS:      -
* INPUT PARAMETERS:   RDS and/or canRxHandle
* RETURN VALUE:       kCanNoCopyData or kCanCopyData
* DESCRIPTION:        will be called from the Receive function
*                     in the CAN-Driver and set the Indicationflag
*                     will be called before the CAN-buffer is copied to the
*                     receive buffer
*
******************************************************************************/
/* CODE CATEGORY 1 START*/
/*--------------------------------------------------------------------------*/
#ifdef DBK_ENABLE_MULTIPLE_PHYSICAL_LAYER
# define CAN_RX_HANDLE         (rcvObject)
canuint8 DBK_API_CALL_TYPE dbkPrecopy(pChipDataPtr RDS, CanReceiveHandle rcvObject)
#endif
#ifdef MULTIPLE_RECEIVE_BUFFER
# define CAN_RX_HANDLE            (canRxHandle)
# define CAN_GLOBAL_RX_HANDLE(i)  (canRxHandle)
canuint8 DBK_INTERNAL_CALL_TYPE dbkPrecopy(pChipDataPtr RDS )
#endif
#ifdef SINGLE_RECEIVE_BUFFER
# define CAN_RX_HANDLE            (preParam)
# define CAN_GLOBAL_RX_HANDLE(i)  (canRxHandle)
canuint8 DBK_INTERNAL_CALL_TYPE dbkPrecopy(CanReceiveHandle preParam)
#endif
#if defined( C_MULTIPLE_RECEIVE_CHANNEL ) || defined( C_SINGLE_RECEIVE_CHANNEL )
# define RDS                     (preParam->pChipData)
# define CAN_RX_HANDLE           (preParam->Handle)
# if (kDbkNumberOfChannels > 1)
#  define CAN_GLOBAL_RX_HANDLE(i)  (canRxHandle[i])
# else
#  define CAN_GLOBAL_RX_HANDLE(i)  (canRxHandle[0])
# endif
canuint8 DBK_INTERNAL_CALL_TYPE dbkPrecopy(CanRxInfoStructPtr preParam)
#endif
/*--------------------------------------------------------------------------*/
{
  vsintx sigHdl;
#if defined( DBK_ENABLE_RX_IND_FLAG ) || defined( DBK_ENABLE_RX_IND_FUNC )
  t_RxSigSwitch  Switch;       /* local variable for runtime-improvement */  
# if (!defined DBK_ENABLE_RX_SIGNALEVAL_ALWAYSTRUE)
  /*variables for signalevaluation*/
  canuint8 signal_state;
  canuint8  value;
  canuint8 byteValue;
#  if defined (_N16BIT_RX_SIGNALE_AKTIV) || defined (_WORD_RX_SIGNALE_AKTIV)
  canuint16 dValue;
#  endif
#  if (defined _NBYTE_RX_SIGNALE_AKTIV)
  canuint8 *pValue;
#  endif
  /*variables for signalevaluation END*/
    union DbkIndicationBits  dbkDummyIndicationFlags;/* needed in part evaluation and to set the real Flags*/
# endif
#endif
#if defined(DBK_ENABLE_MULTIPLE_ECU)
  CanReceiveHandle      canHandle;    /* Handle for CAN-Driver-Tables */
#endif

  /* Signalbewertung und Indication Flag/Func. fuer alle Signale der Botschaft:*/

#if defined DBK_ENABLE_MULTIPLE_ECU           
  canHandle     = CAN_RX_HANDLE;
  CAN_RX_HANDLE = DbkRxMsgCanToDbkIndirection[comMultipleECUCurrent][CAN_RX_HANDLE];
  if (CAN_RX_HANDLE == kCanRxHandleNotUsed) return kCanNoCopyData;
#endif /*#if defined DBK_ENABLE_MULTIPLE_ECU*/
#if ((!defined DBK_ENABLE_RX_SIGNALEVAL_ALWAYSTRUE) && ((defined DBK_ENABLE_RX_IND_FLAG ) || (defined DBK_ENABLE_RX_IND_FUNC )))
  if (DbkRxMsgAttributes[CAN_RX_HANDLE].s_Indication == 1) 
  {
    for (sigHdl=(vsintx)(DbkRxMsgDataOffset[CAN_RX_HANDLE+1]-1); sigHdl>=(vsintx)(DbkRxMsgDataOffset[CAN_RX_HANDLE]); sigHdl--)       /* ueber alle Signale der Botschaft*/
    {
      Switch = DbkRxSigSwitch[sigHdl];

      if (Switch.s_indication == 1)
      {
        /*get signal value:*/
        byteValue = DbkRxSigBytePos[sigHdl];                   /*get offset*/
        switch (DbkRxSigType[sigHdl])
        {
#ifdef _NBIT_RX_SIGNALE_AKTIV
          case TYP_NBIT:
            assertUser((CanRxnBitEvalFunctions[Switch.s_mode] != V_NULL), kBadSignalMode);
            value = (canuint8)(RDS[byteValue] & DbkRxSigMask[sigHdl]);     /*get signal*/
            value >>= DbkRxSigStartbit[sigHdl];                /*justify signal*/
            signal_state = (CanRxnBitEvalFunctions[Switch.s_mode])((DbkSigHandleType)sigHdl, value);
          break;
#endif
#ifdef _BYTE_RX_SIGNALE_AKTIV
          case TYP_BYTE:
            assertUser((CanRxByteEvalFunctions[Switch.s_mode] != V_NULL), kBadSignalMode);
 #ifdef RX_CONTAINER_GAPS_BYTE
            value = (canuint8)(RDS[byteValue] & (canuint8)DbkRxSigMask[sigHdl]);
 #else
            value = RDS[byteValue];                            /*get signal*/
 #endif
            signal_state = (CanRxByteEvalFunctions[Switch.s_mode])((DbkSigHandleType)sigHdl, value);
          break;
#endif
#ifdef _N16BIT_RX_SIGNALE_AKTIV
          case TYP_N16BIT:
            assertUser((CanRxn16BitEvalFunctions[Switch.s_mode] != V_NULL), kBadSignalMode);


# if defined DBK_ENABLE_RX_DYN_BYTESWAP
            if(Switch.s_container_swap == 1)
# endif
            {
# if ((defined DBK_ENABLE_RX_GENERAL_BYTESWAP) || (defined DBK_ENABLE_RX_DYN_BYTESWAP))
              *(((canuint8*)&dValue)) = RDS[byteValue+1]; 
              *(((canuint8*)&dValue)+1) = RDS[byteValue];
# endif
            }
# if defined DBK_ENABLE_RX_DYN_BYTESWAP
            else
# endif
            {
# if ((defined DBK_ENABLE_RX_NEVER_BYTESWAP) || (defined DBK_ENABLE_RX_DYN_BYTESWAP))
#   if defined C_BYTE_ACCESS_DBKOM
              *(((canuint8*)&dValue)) = RDS[byteValue];   /*swap                      */
              *(((canuint8*)&dValue)+1) = RDS[byteValue+1];
#   else  /*C_BYTE_ACCESS_DBKOM*/
              dValue = (*(canuint16 *)&RDS[byteValue]);  /*get signal*/
#   endif /*C_BYTE_ACCESS_DBKOM*/
# endif
            }
            dValue &= DbkRxSigMask[sigHdl];
            dValue >>= DbkRxSigStartbit[sigHdl];
            signal_state = (CanRxn16BitEvalFunctions[Switch.s_mode])((DbkSigHandleType)sigHdl, dValue);
          break;
#endif
#ifdef _WORD_RX_SIGNALE_AKTIV
          case TYP_WORD:
            assertUser((CanRxWordEvalFunctions[Switch.s_mode] != V_NULL), kBadSignalMode);

#if defined DBK_ENABLE_RX_DYN_BYTESWAP
            if(Switch.s_container_swap == 1) 
#endif
            {
#if ((defined DBK_ENABLE_RX_GENERAL_BYTESWAP) || (defined DBK_ENABLE_RX_DYN_BYTESWAP))
              *(((canuint8*)&dValue)) = (RDS[byteValue+1]);
              *(((canuint8*)&dValue)+1) = (RDS[byteValue]); 
#endif
            }
#if defined DBK_ENABLE_RX_DYN_BYTESWAP
            else
#endif
            {
#if ((defined DBK_ENABLE_RX_NEVER_BYTESWAP) || (defined DBK_ENABLE_RX_DYN_BYTESWAP))
              *(((canuint8*)&dValue)) = (RDS[byteValue]);
              *(((canuint8*)&dValue)+1) = (RDS[byteValue+1]); 
#endif
            }
# ifdef RX_CONTAINER_GAPS_WORD
            dValue &= (canuint16)DbkRxSigMask[sigHdl];
# endif
            signal_state = (CanRxWordEvalFunctions[Switch.s_mode])((DbkSigHandleType)sigHdl, dValue);
          break;
#endif

#ifdef _NBYTE_RX_SIGNALE_AKTIV
          case TYP_NBYTE:
            assertUser((CanRxnByteEvalFunctions[Switch.s_mode] != V_NULL), kBadSignalMode);
            pValue = (canuint8 *)&RDS[byteValue];
            signal_state = (CanRxnByteEvalFunctions[Switch.s_mode])((DbkSigHandleType)sigHdl, pValue);
          break;
#endif
          default:
#ifdef DBK_ENABLE_GEN_CHECK
            ApplDbkFatalError( kDbkErrorWrongSignalType );
#else
            signal_state = 0;
#endif
          break;
        } /* end switch */
        if (Switch.s_mode_sign == 1) {signal_state = (canuint8)!signal_state;}
#if defined( DBK_ENABLE_RX_IND_FLAG ) || defined( DBK_ENABLE_RX_IND_FUNC )
        if (signal_state != 0)
        {
          dbkDummyIndicationFlags._c[DbkRxSigIndicationOffset[sigHdl]] |= DbkRxSigIndicationMask[sigHdl];
        }
        else
        {
          dbkDummyIndicationFlags._c[DbkRxSigIndicationOffset[sigHdl]] &= (canuint8)~DbkRxSigIndicationMask[sigHdl];
        }
#endif
      } /* endif (Switch.s_indication == 1) */
    } /* endfor */
  } /* endif ( DbkRxMsgAttributes[CAN_RX_HANDLE].s_Indication != 0) */
#endif /*#if !defined DBK_ENABLE_RX_SIGNALEVAL_ALWAYSTRUE*/
/************************************/
/* copy data */
  assertUser((CanRxActualDLC(preParam) <= CanGetRxDataLen(CAN_RX_HANDLE_CANDRV)), kDbkErrorRxDlcTooLarge);
  if (CanRxDataPtr[CAN_RX_HANDLE] != V_NULL)
  {
    vuint8 nCnt;
    if((CanRxActualDLC(preParam) > CanGetRxDataLen(CAN_RX_HANDLE_CANDRV)))
    {
      nCnt = (vuint8)CanGetRxDataLen(CAN_RX_HANDLE_CANDRV);
    }
    else
    {
      nCnt = (vuint8)CanRxActualDLC(preParam);
    }
    while(nCnt > 0x00)
    {  
      nCnt--;
      *(CanGetRxDataPtr(CAN_RX_HANDLE_CANDRV) + nCnt) = *((CanChipDataPtr)RDS + nCnt);
    }
  }
/************************************/
  /* set the message indication flags -> needed for message gateway */
#if defined( C_ENABLE_INDICATION_FLAG )
  /* set indication flag */
  DbkInterruptDisable();
  CanIndicationFlags._c[CanIndicationOffset[CAN_RX_HANDLE]] |= CanIndicationMask[CAN_RX_HANDLE];
  DbkInterruptRestore();
#endif

  /* verify s_Indication_timeout-flag */
  if (DbkRxMsgAttributes[CAN_RX_HANDLE].s_Indication_timeout == 0) {return kCanNoCopyData;}

  /* *** loop: set indication-flags, ex-dbkIndication-functionality */
  for (sigHdl=(vsintx)(DbkRxMsgDataOffset[CAN_RX_HANDLE+1]-1); sigHdl>=(vsintx)(DbkRxMsgDataOffset[CAN_RX_HANDLE]); sigHdl--)       /* ueber alle Signale der Botschaft*/
  {
#if (((defined DBK_ENABLE_RX_IND_FLAG ) || (defined DBK_ENABLE_RX_IND_FUNC )))
    Switch = DbkRxSigSwitch[sigHdl];

    if (Switch.s_indication == 1)
    {
# if (!defined DBK_ENABLE_RX_SIGNALEVAL_ALWAYSTRUE) 
      if ((dbkDummyIndicationFlags._c[DbkRxSigIndicationOffset[sigHdl]] & DbkRxSigIndicationMask[sigHdl]) != 0)
# endif
      {
        /*set Indication flag*/
# ifdef DBK_ENABLE_RX_IND_FLAG
        DbkRxIndicationFlags._c[DbkRxSigIndicationOffset[sigHdl]] |= DbkRxSigIndicationMask[sigHdl];
# endif
# ifdef DBK_ENABLE_RX_IND_FUNC
#  ifndef V_ENABLE_USE_DUMMY_FUNCTIONS
#   ifndef SignalIndicationDummy
#    if defined ( DBK_ENABLE_GEN_CHECK )
   assertGen(1, kNoDummyFunctionDefined);   
#    endif
#   endif /*#ifndef SignalIndicationDummy*/
        if ( DbkRxSigIndicationFunc[sigHdl] != V_NULL )
#  endif
        {
          (DbkRxSigIndicationFunc[sigHdl])();
        }
# endif
      }
    } /* endif (Switch.s_indication == 1) */
#endif

    


    /* ex-dbkIndication()-functionality */

#if defined( DBK_ENABLE_RX_TIMEOUT_FUNC ) || defined( DBK_ENABLE_RX_TIMEOUT_FLAG ) \
 || defined( DBK_ENABLE_DEFAULT_TO )
    if ((DbkRxSigSwitch[sigHdl].s_timeout == 1) || (DbkRxSigSwitch[sigHdl].s_copydefault == 1))
    {
# if defined( DBK_ENABLE_RX_TIMEOUT_FLAG )
      DbkRxTimeoutFlags._c[DbkRxSigTimeoutOffset[sigHdl]] &= (canuint8)~DbkRxSigTimeoutMask[sigHdl];
# endif
    }
#endif
  } /* endfor all signals of the message*/

#if defined( DBK_ENABLE_RX_TIMEOUT_FUNC ) || defined( DBK_ENABLE_RX_TIMEOUT_FLAG ) \
   || defined( DBK_ENABLE_DEFAULT_TO )
# if defined( DBK_ENABLE_MULTIPLE_ECU )
  CanRxTimeoutTimer[CAN_RX_HANDLE] = DbkRxMsgDeltaT[comMultipleECUCurrent][CAN_RX_HANDLE];
# else
  CanRxTimeoutTimer[CAN_RX_HANDLE] = DbkRxMsgDeltaT[CAN_RX_HANDLE];
# endif
#endif

  return kCanNoCopyData;
}  /* end dbkPrecopy() */
/* CODE CATEGORY 1 END*/



/*==========================================================================*/
/*  DBKOM functions */
/*==========================================================================*/
/************************************************************************
* NAME:               dbkTxMessageStart
* FUNKTIONSGRUPPE:    FlexKOM
* PROTOTYP:           void dbkTxMessageStart(vuint16 TxStartDelay, vuintx MsgHdl)
* AUFRUF:             Anwendung
* VORAUSSETZUNGEN:    
* EINGANGSPARAMETER:  ---
* AUSGANGSPARAMETER:  ---
* BESCHREIBUNG:       Aendert den Messagetimer einmalig bei Aufruf der Funktion
*************************************************************************/
/* CODE CATEGORY 4 START*/
void DBK_API_CALL_TYPE dbkTxMessageStart(vuint16 TxStartDelay, vuintx MsgHdl)
{
  CanTxMsgTimer[MsgHdl] = TxStartDelay;
}
/* CODE CATEGORY 4 END*/


/************************************************************************
* NAME:               dbkInit
* FUNKTIONSGRUPPE:    FlexKOM
* PROTOTYP:           void dbkInit(void);
* AUFRUF:             Anwendung
* VORAUSSETZUNGEN:
* EINGANGSPARAMETER:  ---
* AUSGANGSPARAMETER:  ---
* BESCHREIBUNG:       Initialisierung die Variablen und Datenspeicher
*************************************************************************/
/* CODE CATEGORY 4 START*/
void DBK_API_CALL_TYPE dbkInit(void)
{

#if ( kDbkNumberOfChannels > 1 )
# ifdef DBK_ENABLE_USER_CHECK
    VStdMemNearSet(dbkStatus, dbkInitCall, kDbkNumberOfChannels);
# else
    VStdMemNearSet(dbkStatus, 0, kDbkNumberOfChannels);
# endif
#else
# ifdef DBK_ENABLE_USER_CHECK
    dbkStatus[0] = dbkInitCall;
# else
    dbkStatus[0] = 0;
# endif
#endif
#if defined(V_ENABLE_USED_GLOBAL_VAR)
    VStdMemCpyRomToFarRam( CanSignalsEx, (V_MEMROM1 void V_MEMROM2 V_MEMROM3*)DbkRxMsgDefault, kDbkNumberOfBytesEx);
#else
    VStdMemCpyRomToRam(CanSignalsEx, (V_MEMROM1 void V_MEMROM2 V_MEMROM3*)DbkRxMsgDefault, kDbkNumberOfBytesEx);
#endif
  
  /*clear flags*/
#ifdef DBK_ENABLE_RX_IND_FLAG
  VStdMemNearSet((void*)&DbkRxIndicationFlags, 0, kDbkNumberOfIndBytes);
#endif
#ifdef DBK_ENABLE_RX_TIMEOUT_FLAG
  VStdMemNearSet((void*)&DbkRxTimeoutFlags, 0, kDbkNumberOfTOBytes);
#endif
#ifdef DBK_ENABLE_TX_CONF_FLAG
  VStdMemNearSet((void*)&DbkTxConfirmationFlags, 0, kDbkNumberOfConfBytes);
#endif
#if (kDbkNumberOfTxSigStateBytes > 0)
  VStdMemNearSet(CanTxSignalState, 0, kDbkNumberOfTxSigStateBytes);
#else 
  VStdMemNearSet(CanTxSignalState, 0, kDbkNumberOfTxSigStateBytes + 1); /* to avoid "not initialised variable"*/
#endif 
#if (kDbkNumberOfTxObjects > 0)
  VStdMemFarSet(CanTxMsgNRepZaehler, 0, kDbkNumberOfTxObjects);
  VStdMemNearSet(CanTxTminTimer, 0, kDbkNumberOfTxObjects);
#endif /*#if (kDbkNumberOfTxObjects > 0)*/
#ifdef DBK_ENABLE_EXT_INIT
  ApplDbkInit();
#endif
}
/* CODE CATEGORY 4 END*/
/******************************************************************************
* NAME:               dbkTxStart
* FUNCTIONGROUP:      DBKOM-Driver for 
* PROTOTYPE:          void dbkTxStart( void ) 
* CALLED BY:          Application
* PRECONDITIONS:      -
* INPUT PARAMETERS:   -
* RETURN VALUE:       -
* DESCRIPTION:        Sets the DBKOM TX branch into active mode
*
******************************************************************************/
/* CODE CATEGORY 4 START*/
#ifdef DBK_ENABLE_TX_CHANNEL_SPECIFIC
void DBK_API_CALL_TYPE dbkTxStart( CanChannelHandle channel )
#else
void DBK_API_CALL_TYPE dbkTxStart( void )
#endif
{
#if (kDbkNumberOfTxObjects > 0)
  vsintx   MsgHdl;
  assertUser(((dbkStatus[START_CHANNEL] & dbkInitCall) != 0), kDbkErrorInitCall);
  if ( (dbkStatus[START_CHANNEL] & dbkTxStatusStart) == 0)
  {
# ifdef DBK_ENABLE_TX_CHANNEL_SPECIFIC
    for (MsgHdl=(vsintx)DbkTxMsgStartIndex[channel]; MsgHdl < (vsintx)DbkTxMsgStartIndex[channel+1]; MsgHdl++)   /*for all messages  Access*/
# else
    for (MsgHdl=(vsintx)(kDbkNumberOfTxObjects-1); MsgHdl >= (vsintx)0; MsgHdl--)   /*for all messages  Access*/
# endif
    {
      if ( (DbkTxMsgAttributes[MsgHdl].s_timer_mode) == 0 )       /* check for sendtype "fast" */
      {
        if ( DbkTxMsgTimer1[MsgHdl] > 1) 
        {
          CanTxMsgTimer[MsgHdl] = 1;                              /* startdelay for fast = 10ms */
        }
        else {CanTxMsgTimer[MsgHdl] = DbkTxMsgTimer1[MsgHdl];}
      }
      else {CanTxMsgTimer[MsgHdl] = DbkTxMsgTimer1[MsgHdl];}
    }
    DbkInterruptDisable();
    dbkStatus[START_CHANNEL] |= dbkTxStatusStart;
    DbkInterruptRestore();
  }
  VStdMemNearSet(CanTxMsgStatus, 0, kDbkNumberOfTxObjects);
#ifdef DBK_ENABLE_EXT_TX_START
# ifdef DBK_ENABLE_TX_CHANNEL_SPECIFIC
  ApplDbkTxStart(channel);
# else
  ApplDbkTxStart();
# endif
#endif
#endif /*#if (kDbkNumberOfTxObjects > 0)*/
}
/* CODE CATEGORY 4 END*/
/******************************************************************************
* NAME:               dbkRxStart
* FUNCTIONGROUP:      DBKOM-Driver for 
* PROTOTYPE:          void dbkRxStart( void ) or 
*                     void dbkRxStart( canuint8 channel ) (multichannel)
* CALLED BY:          Application
* PRECONDITIONS:      -
* INPUT PARAMETERS:   -
* RETURN VALUE:       -
* DESCRIPTION:        Sets the DBKOM RX branch into active mode
*
******************************************************************************/
/* CODE CATEGORY 4 START*/
#if ( kDbkNumberOfChannels > 1 )
void DBK_API_CALL_TYPE dbkRxStart( CanChannelHandle channel )
#else
void DBK_API_CALL_TYPE dbkRxStart( void )
#endif
{
#if defined( DBK_ENABLE_RX_TIMEOUT_FLAG ) \
 || defined( DBK_ENABLE_RX_TIMEOUT_FUNC ) \
 || defined( DBK_ENABLE_DEFAULT_TO )
# if ( kDbkNumberOfChannels > 1 )
  vsintx MsgHdl;                          /* message-handle for loop */
# endif
#endif
  assertUser(((dbkStatus[channel] & dbkInitCall) != 0), kDbkErrorInitCall);
  if ( (dbkStatus[channel] & dbkRxStatusStart) == 0 )
  {
#if   defined( DBK_ENABLE_RX_TIMEOUT_FLAG ) \
   || defined( DBK_ENABLE_RX_TIMEOUT_FUNC ) \
   || defined( DBK_ENABLE_DEFAULT_TO )
# if ( kDbkNumberOfChannels > 1 )
    for (MsgHdl=(vsintx)DbkRxMsgStartIndex[channel]; MsgHdl < (vsintx)DbkRxMsgStartIndex[channel+1]; MsgHdl++) 
    {
#  if defined( DBK_ENABLE_MULTIPLE_ECU )
      CanRxTimeoutTimer[MsgHdl] = DbkRxMsgDeltaT[comMultipleECUCurrent][MsgHdl];
#  else
      CanRxTimeoutTimer[MsgHdl] = DbkRxMsgDeltaT[MsgHdl];
#  endif
    }
# else
#  if defined( DBK_ENABLE_MULTIPLE_ECU )
    VStdMemCpyRomToRam(CanRxTimeoutTimer, (V_MEMROM1 void V_MEMROM2 V_MEMROM3*)DbkRxMsgDeltaT[comMultipleECUCurrent],kDbkNumberOfRxObjects << 1);   /*reset timer tmin*/
#  else
    VStdMemCpyRomToRam(CanRxTimeoutTimer, (V_MEMROM1 void V_MEMROM2 V_MEMROM3*)DbkRxMsgDeltaT,kDbkNumberOfRxObjects << 1);   /*reset timer tmin*/
#  endif
# endif
#endif
    DbkInterruptDisable();
    dbkStatus[channel] |= dbkRxStatusStart;
    DbkInterruptRestore();
#ifdef DBK_ENABLE_EXT_RX_START
# if ( kDbkNumberOfChannels > 1 )
    ApplDbkRxStart(channel);
# else
    ApplDbkRxStart();
# endif
#endif
  }
}
/* CODE CATEGORY 4 END*/

/******************************************************************************
* NAME:               dbkTxStop
* FUNCTIONGROUP:      DBKOM-Driver for 
* PROTOTYPE:          void dbkTxStop(void);
* CALLED BY:          Application
* PRECONDITIONS:      -
* INPUT PARAMETERS:   -
* RETURN VALUE:       -
* DESCRIPTION:        Sets the DBKOM TX branch into passive mode
*
******************************************************************************/
/* CODE CATEGORY 4 START*/
#ifdef DBK_ENABLE_TX_CHANNEL_SPECIFIC
void DBK_API_CALL_TYPE dbkTxStop( CanChannelHandle channel )
{
  DbkInterruptDisable();
  dbkStatus[channel] = (canuint8)(dbkStatus[channel] & dbkTxStatusStop);
  DbkInterruptRestore();
# ifdef DBK_ENABLE_EXT_TX_STOP
  ApplDbkTxStop(channel);
# endif
}
#else
void DBK_API_CALL_TYPE dbkTxStop( void )
{
  DbkInterruptDisable();
  dbkStatus[0] = (canuint8)(dbkStatus[0] & dbkTxStatusStop);
  DbkInterruptRestore();
# ifdef DBK_ENABLE_EXT_TX_STOP
  ApplDbkTxStop();
# endif
}
#endif
/* CODE CATEGORY 4 END*/

/******************************************************************************
* NAME:               dbkRxStop
* FUNCTIONGROUP:      DBKOM-Driver for 
* PROTOTYPE:          void dbkRxStop(void);
* CALLED BY:          Application
* PRECONDITIONS:      -
* INPUT PARAMETERS:   -
* RETURN VALUE:       -
* DESCRIPTION:        Sets the DBKOM RX branch into passive mode
*
******************************************************************************/
/* CODE CATEGORY 4 START*/
#if ( kDbkNumberOfChannels > 1 )
void DBK_API_CALL_TYPE dbkRxStop( CanChannelHandle channel )
#else
void DBK_API_CALL_TYPE dbkRxStop( void )
#endif
{
  DbkInterruptDisable();
  dbkStatus[channel] &= dbkRxStatusStop;
  DbkInterruptRestore();
#ifdef DBK_ENABLE_EXT_RX_STOP
 #if ( kDbkNumberOfChannels > 1 )
  ApplDbkRxStop(channel);
 #else
  ApplDbkRxStop();
 #endif
#endif
}
/* CODE CATEGORY 4 END*/


/******************************************************************************
* NAME:               dbkGetSignalState
* FUNKTIONSGRUPPE:    DBKOM-Treiber
* PROTOTYP:           unsigned char dbkGetSignalState(unsigned char SigHdl)
* AUFRUF:             Anwendung
* VORAUSSETZUNGEN:    -
* EINGANGSPARAMETER:  Signalhandle
* AUSGANGSPARAMETER:  Signal muss/muss nicht gesendet werden
* BESCHREIBUNG:       Prueft ob der Signalstate fuer ein bestimmtes Signal gesetzt
*                     ist
******************************************************************************/
/* CODE CATEGORY 4 START*/
canuint8 DBK_API_CALL_TYPE dbkGetSignalState(DbkSigHandleType SigHdl)
{
  if(( CanTxSignalState[ DbkTxSigSignalStateOffset[SigHdl] ]
      & DbkTxSigSignalStateMask[SigHdl]) != 0)
  {
    return True;
  }
  else
  {
    return False;
  }
}
/* CODE CATEGORY 4 END*/

/******************************************************************************
* NAME:               dbkTxTask
* FUNKTIONSGRUPPE:    DBKOM-Treiber
* PROTOTYP:           void dbkTxTask(void);
*                     void dbkTxTask(canuint8 subtask)
*                     void dbkTxTask(canuint8 channel) (multichannel)
*                     void dbkTxTask(canuint8 channel, canuint8 subtask) (multichannel)
* AUFRUF:             zyklisch durch Anwendung
* VORAUSSETZUNGEN:    dbkTxStart() zuvor aufrufen
* EINGANGSPARAMETER:
* AUSGANGSPARAMETER:
* BESCHREIBUNG:       Abarbeitung der FlexKOM-Funktionen
*
******************************************************************************/
/* CODE CATEGORY 2 START*/
#if ( kDbkNumberOfChannels > 1 )
# ifdef DBK_ENABLE_TX_TASKSPLIT
void DBK_API_CALL_TYPE dbkTxTask( canuint8 channel, canuint8 subtask )
# else
void DBK_API_CALL_TYPE dbkTxTask( canuint8 channel )
# endif
#else
# ifdef DBK_ENABLE_TX_TASKSPLIT
void DBK_API_CALL_TYPE dbkTxTask( canuint8 subtask )
# else
void DBK_API_CALL_TYPE dbkTxTask( void )
# endif
#endif
{
#if (kDbkNumberOfTxObjects > 0)

  vsintx MsgHdl;                          /* message-handle for loop */
  vsintx i;                               /* helpvariables */
  canuint8 send;                            /* send flag */
  canuint8 MsgSignalState;                  /* Signalstate in the message */

  /*process TX messages:*/
#ifdef DBK_ENABLE_TX_CHANNEL_SPECIFIC
  if ((dbkStatus[channel] & dbkTxStatusStart) == 0) return; /* TxTask stopped */
#else
  if ((dbkStatus[0] & dbkTxStatusStart) == 0)
  {
    return; /* TxTask stopped */
  }
#endif
#ifdef DBK_ENABLE_TX_TASKSPLIT
  if (subtask >= kDbkNumberOfTxTasks) return;
#endif
#if (kDbkNumberOfChannels > 1)
# ifdef DBK_ENABLE_TX_TASKSPLIT
  for (MsgHdl=(vsintx)(DbkTxMsgStartIndex[channel][subtask+1]-1); MsgHdl >= (vsintx)DbkTxMsgStartIndex[channel][subtask]; MsgHdl--)
# else
  for (MsgHdl=(vsintx)(DbkTxMsgStartIndex[channel+1]-1); MsgHdl >= (vsintx)DbkTxMsgStartIndex[channel]; MsgHdl--)
# endif
#else
# ifdef DBK_ENABLE_TX_TASKSPLIT
  for (MsgHdl=(vsintx)(DbkTxMsgStartIndex[channel][subtask+1]-1); MsgHdl >= (vsintx)DbkTxMsgStartIndex[channel][subtask]; MsgHdl--)
# else
  for (MsgHdl=(vsintx)(kDbkNumberOfTxObjects-1); MsgHdl >= (vsintx)0; MsgHdl--)   /*for all messages  Access*/
# endif
#endif
  {
    send = 0;
    MsgSignalState=0;                                   /* initialize */
    if (DbkTxMsgAttributes[MsgHdl].s_timer == 1)        /* msg timer active at all?*/
    {
      if (CanTxMsgTimer[MsgHdl] == 1)                     
      {
        send = 1;                                       /* send dbkom-msg */
      }
      else
      {
        send = 0;                                       /* default */
      }
      if (DbkTxMsgAttributes[MsgHdl].s_timer_mode == 0) /* evaluation ?*/
      {

        for( i = (vsintx)DbkTxMsgSignalStateOffset[MsgHdl]; i < (vsintx)DbkTxMsgSignalStateOffset[MsgHdl+(vsintx)1]; i++ )
        { /* check signal state for each signal of the message */
           MsgSignalState |= CanTxSignalState[i];
        }

        if (MsgSignalState == 0)        /*T1/#T2*/
        {/*no Signal active*/
          if ((CanTxMsgStatus[MsgHdl] & kCanTxT1T2) != 0)
          {/*T1/#T2 is change from 1 to 0*/
            send=1;
            if (CanTxMsgNRepZaehler[MsgHdl] == 0)
            {/*the repeater is not aktivate*/
              CanTxMsgTimer[MsgHdl] = DbkTxMsgTimer1[MsgHdl];  /*reset msg timer with Time1*/
            }
            else
            {/*the repeater is active*/
              if (CanTxMsgTimer[MsgHdl] > 1)
              {
                CanTxMsgNRepZaehler[MsgHdl]--;
              }
            }
            CanTxMsgStatus[MsgHdl] &= (canuint8)~kCanTxT1T2;             /*delete T1/#T2*/
          }/*no change in T1#T2*/
          if (CanTxMsgTimer[MsgHdl] == 1)
          {
            if (CanTxMsgNRepZaehler[MsgHdl] != 0)
            {
              CanTxMsgNRepZaehler[MsgHdl]--;
#if defined( DBK_ENABLE_MSGTIMER_VARIANT_HANDLING )
              CanTxMsgTimer[MsgHdl] = DbkTxMsgTimer2[DbkVariantIndirection[VActiveVariant]][MsgHdl];  /*reset msg timer with Time2*/
#else
              CanTxMsgTimer[MsgHdl] = DbkTxMsgTimer2[MsgHdl];  /*reset msg timer with Time2*/
#endif
            }
            else
            {
              CanTxMsgTimer[MsgHdl] = DbkTxMsgTimer1[MsgHdl];  /*reset msg timer with Time1*/
            }
          }
        }
        else
        {
          if ((CanTxMsgStatus[MsgHdl] & kCanTxT1T2) == 0)
          {/*Signalstate change from 0 to 1*/
            send=1;
#if defined( DBK_ENABLE_MSGTIMER_VARIANT_HANDLING )
              CanTxMsgTimer[MsgHdl] = DbkTxMsgTimer2[DbkVariantIndirection[VActiveVariant]][MsgHdl];  /*reset msg timer with Time2*/
#else
              CanTxMsgTimer[MsgHdl] = DbkTxMsgTimer2[MsgHdl];  /*reset msg timer with Time2*/
#endif
            CanTxMsgNRepZaehler[MsgHdl] = DbkTxMsgNRepeat[MsgHdl];
          }
          else
          {
            if (CanTxMsgTimer[MsgHdl] <= 1)
            {
#if defined( DBK_ENABLE_MSGTIMER_VARIANT_HANDLING )
              CanTxMsgTimer[MsgHdl] = DbkTxMsgTimer2[DbkVariantIndirection[VActiveVariant]][MsgHdl];  /*reset msg timer with Time2*/
#else
              CanTxMsgTimer[MsgHdl] = DbkTxMsgTimer2[MsgHdl];  /*reset msg timer with Time2*/
#endif
            }
          }
          CanTxMsgStatus[MsgHdl] |= kCanTxT1T2;
        }
      }
      else
      {
        if (CanTxMsgTimer[MsgHdl] == 1)
        {
          if (DbkTxMsgAttributes[MsgHdl].s_demmand == 1)
          {
            if (CanTxMsgNRepZaehler[MsgHdl] > 0)
            {
              send = 1;
              CanTxMsgNRepZaehler[MsgHdl]--;
            }
            else
            {
              send = 0;
            }
          }
          else
          {
            send = 1;
          }
#if defined( DBK_ENABLE_MSGTIMER_VARIANT_HANDLING )
              CanTxMsgTimer[MsgHdl] = DbkTxMsgTimer2[DbkVariantIndirection[VActiveVariant]][MsgHdl];  /*reset msg timer with Time2*/
#else
              CanTxMsgTimer[MsgHdl] = DbkTxMsgTimer2[MsgHdl];  /*reset msg timer with Time2*/
#endif
        }
      }
      if (CanTxMsgTimer[MsgHdl] > 1)
      {
        CanTxMsgTimer[MsgHdl]--;                /*decr. timer*/
      }
    }
    if (send || ((CanTxMsgStatus[MsgHdl] & kCanTxSendImmdt) != 0))
    {
      (void)dbkTransmit((CanTransmitHandle)MsgHdl);                      /*send message*/
    }
    /*Delaytimer*/
    if (CanTxTminTimer[MsgHdl] > 0)
    {
      CanTxTminTimer[MsgHdl]--;
    }
  }/*end of TX msgs*/
#endif  /*#if (kDbkNumberOfTxObjects > 0)*/
} /*end of dbkTxTask()*/
/* CODE CATEGORY 2 END*/

/******************************************************************************
* NAME:               dbkRxTask
* FUNKTIONSGRUPPE:    DBKOM-driver
* PROTOTYP:           void dbkRxTask(void);
*                     void dbkRxTask(canuit8 subtask);
*                     void dbkRxTask(canuit8 channel); (multichannel)
*                     void dbkRxTask(canuit8 channel, canuint8 subtask); (multichannel)
* AUFRUF:             periodic about the application
* VORAUSSETZUNGEN:    activate about dbkRxStart()
* EINGANGSPARAMETER:  -
* AUSGANGSPARAMETER:  -
* BESCHREIBUNG:       generate timeout and simulate a rx-message
*
******************************************************************************/
/* CODE CATEGORY 2 START*/
#if ( kDbkNumberOfChannels > 1 )
# ifdef DBK_ENABLE_RX_TASKSPLIT
void DBK_API_CALL_TYPE dbkRxTask( canuint8 channel, canuint8 subtask )
# else
void DBK_API_CALL_TYPE dbkRxTask( canuint8 channel )
# endif
#else
# ifdef DBK_ENABLE_RX_TASKSPLIT
void DBK_API_CALL_TYPE dbkRxTask( canuint8 subtask )
# else
void DBK_API_CALL_TYPE dbkRxTask( void )
# endif
#endif
{
  vuint16 MsgHdl;                         

#if   defined( DBK_ENABLE_RX_TIMEOUT_FLAG ) \
   || defined( DBK_ENABLE_RX_TIMEOUT_FUNC ) \
   || defined( DBK_ENABLE_DEFAULT_TO )
  DbkSigHandleType        sigHdl;
#endif
#if defined( DBK_ENABLE_DEFAULT_TO ) &&  defined( _WORD_PUTRX_AKTIV )
# if defined( DBK_ENABLE_RX_GENERAL_BYTE_SWAP ) \
  ||(!defined( DBK_ENABLE_RX_GENERAL_BYTE_SWAP ) && defined( DBK_DISABLE_RX_BYTEORDER_CONV ) && defined ( C_BYTE_ACCESS_DBKOM )) \
  ||(!defined( DBK_ENABLE_RX_GENERAL_BYTE_SWAP ) && !defined( DBK_DISABLE_RX_BYTEORDER_CONV ))
  canuint16       dummyvalue;           /*Hilfsvariable*/
# endif
#endif

  
  /*process RX signals:*/
#ifdef DBK_ENABLE_RX_TASKSPLIT
  if (subtask >= kDbkNumberOfRxTasks) {return;}
#endif
  if ((dbkStatus[channel] & dbkRxStatusStart) == 0) {return;}
#if (kDbkNumberOfChannels > 1)  /* Msg - loop for givven channel */
# ifdef DBK_ENABLE_RX_TASKSPLIT
  for (MsgHdl=DbkRxMsgStartIndex[channel][subtask]; MsgHdl < DbkRxMsgStartIndex[channel][subtask+1]; MsgHdl++)
# else
  for (MsgHdl=DbkRxMsgStartIndex[channel]; MsgHdl < DbkRxMsgStartIndex[channel+1]; MsgHdl++)   /*for all messages  Access*/
# endif
#else                           /* Msg - loop for all messages (only singlechannel) */
# ifdef DBK_ENABLE_RX_TASKSPLIT
  for (MsgHdl=DbkRxMsgStartIndex[channel][subtask]; MsgHdl < DbkRxMsgStartIndex[channel][subtask+1]; MsgHdl++)   /*for all messages  Access*/
# else
  for (MsgHdl= 0; MsgHdl <= (vuint16)(kDbkNumberOfRxObjects-1); MsgHdl++)          /*for all messages Access*/
# endif
#endif 
  {
    if (DbkRxMsgAttributes[MsgHdl].s_timer_timeout != 0)
    {
#if   defined( DBK_ENABLE_RX_TIMEOUT_FLAG ) \
   || defined( DBK_ENABLE_RX_TIMEOUT_FUNC ) \
   || defined( DBK_ENABLE_DEFAULT_TO )
      if (CanRxTimeoutTimer[MsgHdl] == 1 )
      {/*check timeout violation*/
         /* set the message indication flags -> needed for message gateway */
        for (sigHdl=(DbkRxMsgDataOffset[MsgHdl]); sigHdl<=(DbkSigHandleType)(DbkRxMsgDataOffset[MsgHdl+(vuint16)1]-1); sigHdl++)       /* ueber alle Signale der Botschaft*/
        {
# if   defined( DBK_ENABLE_RX_TIMEOUT_FLAG ) \
    || defined( DBK_ENABLE_RX_TIMEOUT_FUNC )
          if (DbkRxSigSwitch[sigHdl].s_timeout == 1)            /*timeout check active ?*/
          {
              /*set timeout flag*/
#  ifdef DBK_ENABLE_RX_TIMEOUT_FLAG
            DbkRxTimeoutFlags._c[DbkRxSigTimeoutOffset[sigHdl]] |= DbkRxSigTimeoutMask[sigHdl];
#  endif
#  ifdef DBK_ENABLE_RX_TIMEOUT_FUNC
              /*execute Indication function*/
#   ifndef V_ENABLE_USE_DUMMY_FUNCTIONS
#    ifndef SignalTimeoutDummy
#     if defined ( DBK_ENABLE_GEN_CHECK )
            assertGen(1, kNoDummyFunctionDefined);   
#     endif
#    endif /*#ifndef SignalTimeoutDummy*/
            if (DbkRxSigTimeoutFunc[sigHdl] != V_NULL)
#   endif
            {
              (DbkRxSigTimeoutFunc[sigHdl])();
            }
#  endif
          }
# endif
# ifdef DBK_ENABLE_DEFAULT_TO    /* set defaultvalue in timeout-case */
          if (DbkRxSigSwitch[sigHdl].s_copydefault == 1)
          {
            switch (DbkRxSigType[sigHdl])
            {
#  ifdef _WORD_PUTRX_AKTIV
              case TYP_N16BIT:
              case TYP_WORD:

/******************* homogeneous database **********************************/
#   if defined DBK_ENABLE_RX_GENERAL_BYTESWAP
                *(((canuint8*)&dummyvalue)) = DbkRxMsgDefault[DbkRxSigOffset[sigHdl]+1];  
                *(((canuint8*)&dummyvalue)+1) = DbkRxMsgDefault[DbkRxSigOffset[sigHdl]];  

                dummyvalue &= DbkRxSigMask[sigHdl];
                dummyvalue >>= DbkRxSigStartbit[sigHdl];
                dbkPutRxWord(sigHdl,dummyvalue);
#   endif

#   if defined DBK_ENABLE_RX_NEVER_BYTESWAP
#    if defined C_BYTE_ACCESS_DBKOM
                *(((canuint8*)&dummyvalue)) = DbkRxMsgDefault[DbkRxSigOffset[sigHdl]];  
                *(((canuint8*)&dummyvalue)+1) = DbkRxMsgDefault[DbkRxSigOffset[sigHdl]+1];   
                dummyvalue &= DbkRxSigMask[sigHdl];
                dummyvalue >>= DbkRxSigStartbit[sigHdl];
                dbkPutRxWord(sigHdl,dummyvalue);
#    else  /*C_BYTE_ACCESS_DBKOM*/
                dbkPutRxWord(sigHdl,(canuint16)(((*(V_MEMROM1 canuint16 V_MEMROM2 V_MEMROM3*)&DbkRxMsgDefault[DbkRxSigOffset[sigHdl]]) & DbkRxSigMask[sigHdl])>>DbkRxSigStartbit[sigHdl]));
#    endif /*C_BYTE_ACCESS_DBKOM*/
#   endif

/****************** inhomogenoues database *********************************/
#   if ((!defined DBK_ENABLE_RX_GENERAL_BYTESWAP) && (!defined DBK_ENABLE_RX_NEVER_BYTESWAP))
                if(DbkRxSigSwitch[sigHdl].s_container_swap == 1)                      /*byte order bus different to CPU byte order*/
                {
				          *(((canuint8*)&dummyvalue)) = DbkRxMsgDefault[DbkRxSigOffset[sigHdl]+1];  
                  *(((canuint8*)&dummyvalue)+1) = DbkRxMsgDefault[DbkRxSigOffset[sigHdl]];  
                  dummyvalue &= DbkRxSigMask[sigHdl];
                  dummyvalue >>= DbkRxSigStartbit[sigHdl];
                  dbkPutRxWord(sigHdl,dummyvalue);
                }
                else                                   /* INTEL or no wordaccess to uneven addresss */
                {
#    if defined C_BYTE_ACCESS_DBKOM
                  *(((canuint8*)&dummyvalue)) = DbkRxMsgDefault[DbkRxSigOffset[sigHdl]];  
                  *(((canuint8*)&dummyvalue)+1) = DbkRxMsgDefault[DbkRxSigOffset[sigHdl]+1];   
                  dummyvalue &= DbkRxSigMask[sigHdl];
                  dummyvalue >>= DbkRxSigStartbit[sigHdl];
                  dbkPutRxWord(sigHdl,dummyvalue);
#    else  /*C_BYTE_ACCESS_DBKOM*/
                  dbkPutRxWord(sigHdl,(canuint16)(((*(V_MEMROM1 canuint16 V_MEMROM2 V_MEMROM3*)&DbkRxMsgDefault[DbkRxSigOffset[sigHdl]]) & DbkRxSigMask[sigHdl])>>DbkRxSigStartbit[sigHdl]));
#    endif /*C_BYTE_ACCESS_DBKOM*/
                }
#   endif 
/****************** inhomogenoues database end *********************************/
                break;
#  endif /*#  ifdef _WORD_PUTRX_AKTIV*/

#  ifdef _NBYTE_PUTRX_AKTIV
              case TYP_NBYTE: dbkPutRxnByteInternal(sigHdl,(V_MEMROM1 vuint8 V_MEMROM2 V_MEMROM3*) &DbkRxMsgDefault[DbkRxSigOffset[sigHdl]]);
                break;
#  endif
#  ifdef _BYTE_PUTRX_AKTIV
              case TYP_NBIT:
              case TYP_BYTE:
                dbkPutRxByte(sigHdl,(canuint8)((DbkRxMsgDefault[DbkRxSigOffset[sigHdl]] & (canuint8)DbkRxSigMask[sigHdl])>>DbkRxSigStartbit[sigHdl]));
                break;
#  endif
              default:
#  ifdef DBK_ENABLE_GEN_CHECK
                ApplDbkFatalError( kDbkErrorWrongSignalType );
#  endif
                break;
            }
          }
# endif  /* DBK_ENABLE_DEFAULT_TO */
        } /*end of rx signals (for)*/
# if defined( DBK_ENABLE_MULTIPLE_ECU )
        CanRxTimeoutTimer[MsgHdl] = DbkRxMsgDeltaT[comMultipleECUCurrent][MsgHdl];
# else
        CanRxTimeoutTimer[MsgHdl] = DbkRxMsgDeltaT[MsgHdl];
# endif
# if defined( C_ENABLE_INDICATION_FLAG )
        /* set indication flag */        
        DbkInterruptDisable();
        CanIndicationFlags._c[CanIndicationOffset[MsgHdl]] |= CanIndicationMask[MsgHdl];
        DbkInterruptRestore();
# endif
      }
#endif /* DBK_ENABLE_RX_TIMEOUT_FLAG _FUNC _TO */
#ifdef DBK_ENABLE_RX_SIMULATION
      if (CanRxMsgTimer[MsgHdl] != 0) CanRxMsgTimer[MsgHdl]--;          /*decrement message time*/
#endif
#if   defined( DBK_ENABLE_RX_TIMEOUT_FLAG ) \
    || defined( DBK_ENABLE_RX_TIMEOUT_FUNC ) \
    || defined( DBK_ENABLE_DEFAULT_TO )
      CAN_GLOBAL_RX_HANDLE(channel) = kCanRxHandleNotUsed;
      if (CanRxTimeoutTimer[MsgHdl] != 0)
      {
        CanRxTimeoutTimer[MsgHdl]--;  /*decrement Timeout time*/
      }
      if (CAN_GLOBAL_RX_HANDLE(channel) != kCanRxHandleNotUsed)    /* only for runtime-optimize */
      {
        if (CAN_GLOBAL_RX_HANDLE(channel) == MsgHdl) 
        {
# if defined( DBK_ENABLE_MULTIPLE_ECU )
          CanRxTimeoutTimer[MsgHdl] = DbkRxMsgDeltaT[comMultipleECUCurrent][MsgHdl];
# else
          CanRxTimeoutTimer[MsgHdl] = DbkRxMsgDeltaT[MsgHdl];
# endif
        }
      }
#endif
    }
  } /*end of rx msgs (for)*/
} /* end of dbkRxTask() */
/* CODE CATEGORY 2 END*/

/******************************************************************************
* NAME:               dbkTransmit
* FUNKTIONSGRUPPE:    DBKOM-Treiber
* PROTOTYP:           canuint8 dbkTransmit(canuint8);
* AUFRUF:             durch Anwendung und intern
* VORAUSSETZUNGEN:    dbkTxStart() zuvor aufrufen
* EINGANGSPARAMETER:  Handle auf die zu sendende Botschaft
* AUSGANGSPARAMETER:  Return-Wert von CanTransmit
* BESCHREIBUNG:       Sendet die Botschaft
*
******************************************************************************/
/* CODE CATEGORY 1 START*/
/*--------------------------------------------------------------------------*/
canuint8 dbkTransmit(CanTransmitHandle MsgHdl)
/*call the CAN-Driver Function c_transmit send the Message */
/*make the minimal-send-distance                           */
/*--------------------------------------------------------------------------*/
{
#if (kDbkNumberOfTxObjects > 0)
  canuint8 rc;

#ifdef DBK_ENABLE_TX_CHANNEL_SPECIFIC
  vsintx channel;

  for (channel = (vsintx)(kDbkNumberOfChannels-1); (vsintx)channel>=0; channel--)
  {
# ifdef DBK_ENABLE_TX_TASKSPLIT
    if ( MsgHdl >= DbkTxMsgStartIndex[channel][0] )
# else
    if ( MsgHdl >= DbkTxMsgStartIndex[channel] )
# endif
    {
      break;
    }
  }
  if ( (dbkStatus[channel] & dbkTxStatusStart) == 0 ) return kCanTxFailed; /* TxTask stopped */
#else
  if ((dbkStatus[0] & dbkTxStatusStart) == 0) {return kCanTxFailed;}  /*sendpart switched off */
#endif

  if ((DbkTxMsgAttributes[MsgHdl].s_delay == 0) ||   /* Mindestzeit inaktiv oder*/
    (CanTxTminTimer[MsgHdl] == 0))                   /* Mindestzeit vorbei ?*/
  {
    DbkInterruptDisable(); /* otherwise a new dbkPutTx between CanTransmit and clear kCanTxSendImmdt would delete the sendrequest completly*/
#ifdef DBK_ENABLE_MULTIPLE_ECU
    if (DbkTxMsgDbkToCanIndirection[comMultipleECUCurrent][MsgHdl] != kCanTxHandleNotUsed)
    {
      rc = CanTransmit(DbkTxMsgDbkToCanIndirection[comMultipleECUCurrent][MsgHdl]);  /* indirection for can-driver-tables */
    }
    else rc = kCanTxOk;
#else 
    rc = CanTransmit(DbkTxMsgDbkToCanIndirection[MsgHdl]);  /* indirection for can-driver-tables */
#endif /*#ifdef DBK_ENABLE_MULTIPLE_ECU*/
    if (rc == kCanTxOk)                                             /* can-driver did acceept the msg */        
    {
      CanTxMsgStatus[MsgHdl] = (canuint8)(CanTxMsgStatus[MsgHdl] & (canuint8)~kCanTxSendImmdt);         /* delete sendrequest */
      DbkInterruptRestore();
      CanTxTminTimer[MsgHdl] = DbkTxMsgDeltaT[MsgHdl];              /* reset timer tmin */
      return rc;
    }
    DbkInterruptRestore();
  }
  CanTxMsgStatus[MsgHdl] |= kCanTxSendImmdt;              /* Transmitbuffer not free, try again */
  return kCanTxFailed;
#endif /*#if (kDbkNumberOfTxObjects > 0)*/
}
/* CODE CATEGORY 1 END*/


#if defined(DBK_ENABLE_GET_CONTEXT) || (defined(VGEN_ENABLE_MDWRAP) && defined(VQNX_ENABLE_CONTEXT_SWITCH))
/******************************************************************************
* NAME:               dbkGetModuleContext
* PROTOTYP:           void  dbkGetModuleContext(tdbkModuleContextStructPtr pContext);
* AUFRUF:             from OS
* Input parameter:    Pointer on structure
* Output parameter:   Non
* Description:        Copies the dbkom internal states on the structure
*
******************************************************************************/
void dbkGetModuleContext(tdbkModuleContextStructPtr pContext)
{
# if defined( DBK_ENABLE_TX_CONF_FLAG ) || defined( DBK_ENABLE_RX_IND_FLAG  ) || defined ( DBK_ENABLE_RX_TIMEOUT_FLAG )
  vuintx i;
# endif
  vsintx   MsgHdl;
  vuint16 j;

  pContext -> dbkMagicNumber = (vuint32)((((vuint32)IL_DBKOM_VERSION) << 16) | (vuint32)(IL_DBKOM_RELEASE_VERSION));

# if defined DBK_ENABLE_TX_CONF_FLAG
  for (i=0 ; i < (vuintx)kDbkNumberOfConfBytes ; i++)
  {
    pContext -> CanTxConfirmationFlagsCTB._c[i] = DbkTxConfirmationFlags._c[i];
  }
# endif
# if defined DBK_ENABLE_RX_IND_FLAG
  for (i=0 ; i < (vuintx)kDbkNumberOfIndBytes ; i++)
  {
    pContext -> CanRxIndicationFlagsCTB._c[i] = DbkRxIndicationFlags._c[i];
  }
# endif
# if defined( DBK_ENABLE_RX_IND_FLAG ) || defined( DBK_ENABLE_RX_IND_FUNC )
#  if (!defined DBK_ENABLE_RX_SIGNALEVAL_ALWAYSTRUE)
  for (i=0 ; i < (vuintx)kDbkNumberOfIndBytes ; i++)
  {
    pContext -> dbkDummyIndicationFlagsCTB._c[i] = dbkDummyIndicationFlags._c[i];
  }
#  endif
# endif
# if defined DBK_ENABLE_RX_TIMEOUT_FLAG
  for (i=0 ; i < (vuintx)kDbkNumberOfTOBytes ; i++)
  {
    pContext -> CanRxTimeoutFlagsCTB._c[i] = DbkRxTimeoutFlags._c[i];
  }
# endif
# if  defined( DBK_ENABLE_RX_TIMEOUT_FLAG ) \
   || defined( DBK_ENABLE_RX_TIMEOUT_FUNC ) \
   || defined( DBK_ENABLE_DEFAULT_TO )
  for (MsgHdl = (kCanNumberOfRxDbkMessages-1); MsgHdl >= 0; MsgHdl--)
  {
    pContext -> CanRxTimeoutTimerCTB[MsgHdl] = CanRxTimeoutTimer[MsgHdl];
  }
# endif
  for (j=0 ; j < (vuint16)kDbkNumberOfTxSigStateBytes ; j++)
  {
    pContext -> CanTxSignalStateCTB[j] = CanTxSignalState[j];
  }
    for (MsgHdl=(kDbkNumberOfTxObjects-1); MsgHdl>=0; MsgHdl--)
  {
    pContext -> CanTxTminTimerCTB[MsgHdl] = CanTxTminTimer[MsgHdl];/*Timer to hold the min send-distance*/
    pContext -> CanTxMsgStatusCTB[MsgHdl] = CanTxMsgStatus[MsgHdl];/*bit1 = send_immdeality, bit2 = T1/#T2*/
    pContext -> CanTxMsgNRepZaehlerCTB[MsgHdl] = CanTxMsgNRepZaehler[MsgHdl];/*count of Messagerepeat*/
    pContext -> CanTxMsgTimerCTB[MsgHdl] = CanTxMsgTimer[MsgHdl];/*Timer to hold the send-distance*/
  }
  for (j=0 ; j < kDbkNumberOfChannels ; j++)
  {
    pContext -> dbkStatusCTB[j] = dbkStatus[j];           
  }
}
# endif
#if defined(DBK_ENABLE_SET_CONTEXT) || (defined(VGEN_ENABLE_QWRAP) && defined(VQNX_ENABLE_CONTEXT_SWITCH))
/******************************************************************************
* NAME:               dbkSetModuleContext
* PROTOTYP:           void  dbkSetModuleContext(tdbkModuleContextStructPtr pContext);
* AUFRUF:             from OS
* Input parameter:    Pointer on structure
* Output parameter:   Non
* Description:        initialises Dbkom with the buffered values
*
******************************************************************************/
vuint8 dbkSetModuleContext(tdbkModuleContextStructPtr pContext)
{
# if defined( DBK_ENABLE_TX_CONF_FLAG ) || defined( DBK_ENABLE_RX_IND_FLAG ) || defined ( DBK_ENABLE_RX_TIMEOUT_FLAG )
  vuintx i;
# endif
  vsintx   MsgHdl;
  vuint16 j;

  if(pContext -> dbkMagicNumber == (vuint32)((((vuint32)IL_DBKOM_VERSION) << 16) | (vuint32)(IL_DBKOM_RELEASE_VERSION)) )
  {
# if defined DBK_ENABLE_TX_CONF_FLAG
    for (i=0 ; i < (vuintx)kDbkNumberOfConfBytes ; i++)
    {
      DbkTxConfirmationFlags._c[i]  = pContext -> CanTxConfirmationFlagsCTB._c[i];
    }
# endif
# if defined DBK_ENABLE_RX_IND_FLAG
    for (i=0 ; i < (vuintx)kDbkNumberOfIndBytes ; i++)
    {
      DbkRxIndicationFlags._c[i] = pContext -> CanRxIndicationFlagsCTB._c[i];
    }
# endif
# if defined( DBK_ENABLE_RX_IND_FLAG ) || defined( DBK_ENABLE_RX_IND_FUNC )
#  if (!defined DBK_ENABLE_RX_SIGNALEVAL_ALWAYSTRUE)
    for (i=0 ; i < (vuintx)kDbkNumberOfIndBytes ; i++)
    {
      dbkDummyIndicationFlags._c[i] = pContext -> dbkDummyIndicationFlagsCTB._c[i];
    }
#  endif
# endif
# if defined DBK_ENABLE_RX_TIMEOUT_FLAG
    for (i=0 ; i < (vuintx)kDbkNumberOfTOBytes ; i++)
    {
      DbkRxTimeoutFlags._c[i] = pContext -> CanRxTimeoutFlagsCTB._c[i];
    }
# endif
# if  defined( DBK_ENABLE_RX_TIMEOUT_FLAG ) \
   || defined( DBK_ENABLE_RX_TIMEOUT_FUNC ) \
   || defined( DBK_ENABLE_DEFAULT_TO )
    for (MsgHdl=(kCanNumberOfRxDbkMessages-1); MsgHdl>=0; MsgHdl--)
    {
      CanRxTimeoutTimer[MsgHdl] = pContext -> CanRxTimeoutTimerCTB[MsgHdl];
    }
# endif
   for (j=0 ; j < (vuint16)kDbkNumberOfTxSigStateBytes ; j++)
    {
      CanTxSignalState[j] = pContext -> CanTxSignalStateCTB[j];
    }
    for (MsgHdl=(kDbkNumberOfTxObjects-1); MsgHdl>=0; MsgHdl--)
    {
      CanTxTminTimer[MsgHdl] = pContext -> CanTxTminTimerCTB[MsgHdl];
      CanTxMsgStatus[MsgHdl] = pContext -> CanTxMsgStatusCTB[MsgHdl];
      CanTxMsgNRepZaehler[MsgHdl] = pContext -> CanTxMsgNRepZaehlerCTB[MsgHdl];
      CanTxMsgTimer[MsgHdl]= pContext -> CanTxMsgTimerCTB[MsgHdl];
    }
    for(j = 0; j < kDbkNumberOfChannels; j++)
    {
      dbkStatus[j] = pContext -> dbkStatusCTB[j];
    }
    return(1);
  }
  else
  {
    return(0);
  }
}
#endif 




