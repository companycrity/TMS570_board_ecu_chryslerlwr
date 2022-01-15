/*********************************************************************************************************************/
/*!
 * \file sip_vers.c
 * \par      copyright
 * \verbatim
 *  Copyright (c) by Vector Informatik GmbH. All rights reserved.
 * 
 *  This software is copyright protected and proprietary to Vector Informatik GmbH.
 *  Vector Informatik GmbH grants to you only those rights as set out in the license conditions.
 *  All other rights remain with Vector Informatik GmbH.
 * \endverbatim
 */
/*  -------------------------------------------------------------------------------------------------------------------
 *  FILE DESCRIPTION
 *  -------------------------------------------------------------------------------------------------------------------
 *
 *  Description:  
 *  1) Check that all currently compiled files in the system have the correct 
 *     versions according to the delivered software integration package (SIP).
 *  2) Provide the SIP version as ROM constants for e.g. diagnostic purposes.
 *
 *  Usage hints:
 *    If a compiler error occurs within this file, a wrong version
 *    for the notified module has been detected. 
 *    Please check, if
 *    a) The module is part of your project and the include path is 
 *       set correct (if not, the compiler may assume 0 for the 
 *       version number comparison)
 *    b) The used module may have an incorrect version for this
 *       project. Proof carefully, if a newer (or older) version
 *       of the notified component is already available on your site
 *       and an erroneous version mixup had occurred. See the required
 *       module's main and bugfix version above of the error message.
 *    c) This may be the wrong SIP version check file for the project.
 *       Proof carefully, if the file has been exchanged together with
 *       the latest change of a component (e.g. an bugfix delivery), 
 *       too.
 *    In case none of the above mention points is true, please contact 
 *    your Vector's contact person for further help.
 *
 *  Background information:
 *    Each Vector software component checks its own header
 *    and code files for version consistency. With this, a version  
 *    mixup within each component could be detected during compilation.
 *    To detect the mixup of different components in a project, too,
 *    this version check file has been introduced.
 */
/*********************************************************************************************************************/

#include "v_inc.h"

#if defined(VGEN_ENABLE_IL_VECTOR)
#include "il_inc.h"
#endif

/*----------------------------------------------------------------------------
  Ccl_Dc
  ---------------------------------------------------------------------------*/
#if defined(VGEN_ENABLE_CCL)
#include "ccl_inc.h"
#endif

/*----------------------------------------------------------------------------
  Ccl_Dpm_Dc
  ---------------------------------------------------------------------------*/
#if defined(VGEN_ENABLE_DPM)
#include "dpm.h"
#endif

/*----------------------------------------------------------------------------
  Cp_Xcp
  ---------------------------------------------------------------------------*/
#if defined(VGEN_ENABLE_XCP)
#include "XcpProf.h"
#endif

/*----------------------------------------------------------------------------
  Cp_XcpOnCan
  ---------------------------------------------------------------------------*/
#if defined(VGEN_ENABLE_XCP)
#include "xcp_can.h"
#endif

/*----------------------------------------------------------------------------
  DrvCan_Tms470DcanHll
  ---------------------------------------------------------------------------*/
#if defined(VGEN_ENABLE_CAN_DRV)
#include "can_def.h"
#endif

/*----------------------------------------------------------------------------
  Il_Dbkom
  ---------------------------------------------------------------------------*/
#if defined(VGEN_ENABLE_IL_DBKOM)
#include "dbk_def.h"
#endif

/*----------------------------------------------------------------------------
  Nm_DirOsek
  ---------------------------------------------------------------------------*/
#if defined(VGEN_ENABLE_NM_OSEK_D)
#include "n_onmdef.h"
#endif

/*----------------------------------------------------------------------------
  Nm_DirOsekExt_Dc
  ---------------------------------------------------------------------------*/
#if defined(VGEN_ENABLE_NM_OSEK_D_UD)
#include "onmxdc.h"
#endif

/*----------------------------------------------------------------------------
  Nm_PwrTrainBasic
  ---------------------------------------------------------------------------*/
#if defined(VGEN_ENABLE_NM_BASIC)
#include "nm_basic.h"
#endif

/*----------------------------------------------------------------------------
  Tp_Iso15765
  ---------------------------------------------------------------------------*/
#if defined(VGEN_ENABLE_TP_ISO_MC)
#include "tpmc.h"
#endif

/*----------------------------------------------------------------------------
  VStdLib_Arm7
  ---------------------------------------------------------------------------*/
#if defined(VGEN_ENABLE_VSTDLIB)
#include "vstdlib.h"
#endif



/*----------------------------------------------------------------------------
  Ccl_Dc
  ---------------------------------------------------------------------------*/
#if defined(VGEN_ENABLE_CCL)
 #if( CCL_DC_VERSION !=  0x0130u )
  #error "Ccl_Dc: Wrong main/sub version detected for this SIP delivery!"
 #endif
 #if( CCL_DC_RELEASE_VERSION !=  0x28u )
  #error "Ccl_Dc: Wrong release version detected for this SIP delivery!"
 #endif
#endif
/*----------------------------------------------------------------------------
  Ccl_Dpm_Dc
  ---------------------------------------------------------------------------*/
#if defined(VGEN_ENABLE_DPM)
 #if( CCL_DPM_DC_VERSION !=  0x0223u )
  #error "Ccl_Dpm_Dc: Wrong main/sub version detected for this SIP delivery!"
 #endif
 #if( CCL_DPM_DC_RELEASE_VERSION !=  0x03u )
  #error "Ccl_Dpm_Dc: Wrong release version detected for this SIP delivery!"
 #endif
#endif
/*----------------------------------------------------------------------------
  Cp_Xcp
  ---------------------------------------------------------------------------*/
#if defined(VGEN_ENABLE_XCP)
 #if( CP_XCP_VERSION !=  0x0127u )
  #error "Cp_Xcp: Wrong main/sub version detected for this SIP delivery!"
 #endif
 #if( CP_XCP_RELEASE_VERSION !=  0x06u )
  #error "Cp_Xcp: Wrong release version detected for this SIP delivery!"
 #endif
#endif
/*----------------------------------------------------------------------------
  Cp_XcpOnCan
  ---------------------------------------------------------------------------*/
#if defined(VGEN_ENABLE_XCP)
 #if( CP_XCPONCAN_VERSION !=  0x0107u )
  #error "Cp_XcpOnCan: Wrong main/sub version detected for this SIP delivery!"
 #endif
 #if( CP_XCPONCAN_RELEASE_VERSION !=  0x03u )
  #error "Cp_XcpOnCan: Wrong release version detected for this SIP delivery!"
 #endif
#endif
/*----------------------------------------------------------------------------
  DrvCan_Tms470DcanHll
  ---------------------------------------------------------------------------*/
#if defined(VGEN_ENABLE_CAN_DRV)
 #if( DRVCAN_TMS470DCANHLL_VERSION !=  0x0112u )
  #error "DrvCan_Tms470DcanHll: Wrong main/sub version detected for this SIP delivery!"
 #endif
 #if( DRVCAN_TMS470DCANHLL_RELEASE_VERSION !=  0x01u )
  #error "DrvCan_Tms470DcanHll: Wrong release version detected for this SIP delivery!"
 #endif
#endif
/*----------------------------------------------------------------------------
  Il_Dbkom
  ---------------------------------------------------------------------------*/
#if defined(VGEN_ENABLE_IL_DBKOM)
 #if( IL_DBKOM_VERSION !=  0x0258u )
  #error "Il_Dbkom: Wrong main/sub version detected for this SIP delivery!"
 #endif
 #if( IL_DBKOM_RELEASE_VERSION !=  0x00u )
  #error "Il_Dbkom: Wrong release version detected for this SIP delivery!"
 #endif
#endif
/*----------------------------------------------------------------------------
  Nm_DirOsek
  ---------------------------------------------------------------------------*/
#if defined(VGEN_ENABLE_NM_OSEK_D)
 #if( NM_DIROSEK_VERSION !=  0x0364u )
  #error "Nm_DirOsek: Wrong main/sub version detected for this SIP delivery!"
 #endif
 #if( NM_DIROSEK_RELEASE_VERSION !=  0x17u )
  #error "Nm_DirOsek: Wrong release version detected for this SIP delivery!"
 #endif
#endif
/*----------------------------------------------------------------------------
  Nm_DirOsekExt_Dc
  ---------------------------------------------------------------------------*/
#if defined(VGEN_ENABLE_NM_OSEK_D_UD)
 #if( NM_DIROSEKEXT_DC_VERSION !=  0x0115u )
  #error "Nm_DirOsekExt_Dc: Wrong main/sub version detected for this SIP delivery!"
 #endif
 #if( NM_DIROSEKEXT_DC_RELEASE_VERSION !=  0x01u )
  #error "Nm_DirOsekExt_Dc: Wrong release version detected for this SIP delivery!"
 #endif
#endif
/*----------------------------------------------------------------------------
  Nm_PwrTrainBasic
  ---------------------------------------------------------------------------*/
#if defined(VGEN_ENABLE_NM_BASIC)
 #if( NM_PWRTRAINBASIC_VERSION !=  0x0115u )
  #error "Nm_PwrTrainBasic: Wrong main/sub version detected for this SIP delivery!"
 #endif
 #if( NM_PWRTRAINBASIC_RELEASE_VERSION !=  0x05u )
  #error "Nm_PwrTrainBasic: Wrong release version detected for this SIP delivery!"
 #endif
#endif
/*----------------------------------------------------------------------------
  Tp_Iso15765
  ---------------------------------------------------------------------------*/
#if defined(VGEN_ENABLE_TP_ISO_MC)
 #if( TP_ISO15765_VERSION !=  0x0307u )
  #error "Tp_Iso15765: Wrong main/sub version detected for this SIP delivery!"
 #endif
 #if( TP_ISO15765_RELEASE_VERSION !=  0x03u )
  #error "Tp_Iso15765: Wrong release version detected for this SIP delivery!"
 #endif
#endif
/*----------------------------------------------------------------------------
  VStdLib_Arm7
  ---------------------------------------------------------------------------*/
#if defined(VGEN_ENABLE_VSTDLIB)
 #if( VSTDLIB_ARM7_VERSION !=  0x0132u )
  #error "VStdLib_Arm7: Wrong main/sub version detected for this SIP delivery!"
 #endif
 #if( VSTDLIB_ARM7_RELEASE_VERSION !=  0x01u )
  #error "VStdLib_Arm7: Wrong release version detected for this SIP delivery!"
 #endif
#endif


/******************************************************************************
| Store SIP version in ROM constants
|*****************************************************************************/
/* ROM CATEGORY 4 START*/
V_MEMROM0 V_MEMROM1 vuint8 V_MEMROM2 kSipMainVersion   = (vuint8)(VGEN_DELIVERY_VERSION_BYTE_0);
V_MEMROM0 V_MEMROM1 vuint8 V_MEMROM2 kSipSubVersion    = (vuint8)(VGEN_DELIVERY_VERSION_BYTE_1);
V_MEMROM0 V_MEMROM1 vuint8 V_MEMROM2 kSipBugFixVersion = (vuint8)(VGEN_DELIVERY_VERSION_BYTE_2);
/* ROM CATEGORY 4 END*/
