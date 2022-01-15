/*** Generated code, do not change!                                        ***/
/*** Module WdgM_PBcfg, written by Wdg_Mgr_Cfg_Gen 2.0.1 (build 204883) on ***/
/*** Wed 20-Jul-2016 14:46:08                                              ***/

#include "WdgM.h"
#include "WdgM_PBcfg.h"

#define NR_OF_CHECKPOINTS 20
#define NR_OF_ENTITIES 10
#define NR_OF_WATCHDOGS 1
#define NR_OF_TRIGGER_MODES 1
#define NR_OF_ALLOWED_CALLERS 1
#define NR_OF_GLOBAL_TRANSITIONS 6
#define NR_OF_LOCAL_TRANSITIONS 9


#define WDGM_SE0_START_SEC_VAR_NOINIT_UNSPECIFIED 
#include "MemMap.h"
/* RAM section for SE100ms_9                                                 */
static WdgM_EntityStatusLType EntityStatusL_0;
#define WDGM_SE0_STOP_SEC_VAR_NOINIT_UNSPECIFIED 
#include "MemMap.h"

#define WDGM_SE0_START_SEC_VAR_NOINIT_32BIT 
#include "MemMap.h"
/* Local Alive Counters for CPs in `SE100ms_9`                               */
static WdgM_AliveCounterLType Alive_CounterL_0;
#define WDGM_SE0_STOP_SEC_VAR_NOINIT_32BIT 
#include "MemMap.h"


#define WDGM_SE1_START_SEC_VAR_NOINIT_UNSPECIFIED 
#include "MemMap.h"
/* RAM section for SE100ms_10                                                */
static WdgM_EntityStatusLType EntityStatusL_1;
#define WDGM_SE1_STOP_SEC_VAR_NOINIT_UNSPECIFIED 
#include "MemMap.h"

#define WDGM_SE1_START_SEC_VAR_NOINIT_32BIT 
#include "MemMap.h"
/* Local Alive Counters for CPs in `SE100ms_10`                              */
static WdgM_AliveCounterLType Alive_CounterL_1;
#define WDGM_SE1_STOP_SEC_VAR_NOINIT_32BIT 
#include "MemMap.h"


#define WDGM_SE2_START_SEC_VAR_NOINIT_UNSPECIFIED 
#include "MemMap.h"
/* RAM section for SE100ms_8                                                 */
static WdgM_EntityStatusLType EntityStatusL_2;
#define WDGM_SE2_STOP_SEC_VAR_NOINIT_UNSPECIFIED 
#include "MemMap.h"

#define WDGM_SE3_START_SEC_VAR_NOINIT_UNSPECIFIED 
#include "MemMap.h"
/* RAM section for SE10ms_10                                                 */
static WdgM_EntityStatusLType EntityStatusL_3;
#define WDGM_SE3_STOP_SEC_VAR_NOINIT_UNSPECIFIED 
#include "MemMap.h"

#define WDGM_SE3_START_SEC_VAR_NOINIT_32BIT 
#include "MemMap.h"
/* Local Alive Counters for CPs in `SE10ms_10`                               */
static WdgM_AliveCounterLType Alive_CounterL_2;
#define WDGM_SE3_STOP_SEC_VAR_NOINIT_32BIT 
#include "MemMap.h"


#define WDGM_SE4_START_SEC_VAR_NOINIT_UNSPECIFIED 
#include "MemMap.h"
/* RAM section for SE10ms_9                                                  */
static WdgM_EntityStatusLType EntityStatusL_4;
#define WDGM_SE4_STOP_SEC_VAR_NOINIT_UNSPECIFIED 
#include "MemMap.h"

#define WDGM_SE4_START_SEC_VAR_NOINIT_32BIT 
#include "MemMap.h"
/* Local Alive Counters for CPs in `SE10ms_9`                                */
static WdgM_AliveCounterLType Alive_CounterL_3;
#define WDGM_SE4_STOP_SEC_VAR_NOINIT_32BIT 
#include "MemMap.h"


#define WDGM_SE5_START_SEC_VAR_NOINIT_UNSPECIFIED 
#include "MemMap.h"
/* RAM section for SE4ms_8                                                   */
static WdgM_EntityStatusLType EntityStatusL_5;
#define WDGM_SE5_STOP_SEC_VAR_NOINIT_UNSPECIFIED 
#include "MemMap.h"

#define WDGM_SE5_START_SEC_VAR_NOINIT_32BIT 
#include "MemMap.h"
/* Local Alive Counters for CPs in `SE4ms_8`                                 */
static WdgM_AliveCounterLType Alive_CounterL_4;
#define WDGM_SE5_STOP_SEC_VAR_NOINIT_32BIT 
#include "MemMap.h"


#define WDGM_SE6_START_SEC_VAR_NOINIT_UNSPECIFIED 
#include "MemMap.h"
/* RAM section for SE4ms_10                                                  */
static WdgM_EntityStatusLType EntityStatusL_6;
#define WDGM_SE6_STOP_SEC_VAR_NOINIT_UNSPECIFIED 
#include "MemMap.h"

#define WDGM_SE6_START_SEC_VAR_NOINIT_32BIT 
#include "MemMap.h"
/* Local Alive Counters for CPs in `SE4ms_10`                                */
static WdgM_AliveCounterLType Alive_CounterL_5;
#define WDGM_SE6_STOP_SEC_VAR_NOINIT_32BIT 
#include "MemMap.h"


#define WDGM_SE7_START_SEC_VAR_NOINIT_UNSPECIFIED 
#include "MemMap.h"
/* RAM section for SE2ms_10                                                  */
static WdgM_EntityStatusLType EntityStatusL_7;
#define WDGM_SE7_STOP_SEC_VAR_NOINIT_UNSPECIFIED 
#include "MemMap.h"

#define WDGM_SE7_START_SEC_VAR_NOINIT_32BIT 
#include "MemMap.h"
/* Local Alive Counters for CPs in `SE2ms_10`                                */
static WdgM_AliveCounterLType Alive_CounterL_6;
#define WDGM_SE7_STOP_SEC_VAR_NOINIT_32BIT 
#include "MemMap.h"


#define WDGM_SE8_START_SEC_VAR_NOINIT_UNSPECIFIED 
#include "MemMap.h"
/* RAM section for SE2ms_9                                                   */
static WdgM_EntityStatusLType EntityStatusL_8;
#define WDGM_SE8_STOP_SEC_VAR_NOINIT_UNSPECIFIED 
#include "MemMap.h"

#define WDGM_SE8_START_SEC_VAR_NOINIT_32BIT 
#include "MemMap.h"
/* Local Alive Counters for CPs in `SE2ms_9`                                 */
static WdgM_AliveCounterLType Alive_CounterL_7;
#define WDGM_SE8_STOP_SEC_VAR_NOINIT_32BIT 
#include "MemMap.h"


#define WDGM_SE9_START_SEC_VAR_NOINIT_UNSPECIFIED 
#include "MemMap.h"
/* RAM section for SE2ms_8                                                   */
static WdgM_EntityStatusLType EntityStatusL_9;
#define WDGM_SE9_STOP_SEC_VAR_NOINIT_UNSPECIFIED 
#include "MemMap.h"

#define WDGM_GLOBAL_START_SEC_VAR_NOINIT_UNSPECIFIED 
#include "MemMap.h"
/* Global Status for Supervised Entities                                     */
static WdgM_EntityStatusGType EntityStatusG_0;
static WdgM_EntityStatusGType EntityStatusG_1;
static WdgM_EntityStatusGType EntityStatusG_2;
static WdgM_EntityStatusGType EntityStatusG_3;
static WdgM_EntityStatusGType EntityStatusG_4;
static WdgM_EntityStatusGType EntityStatusG_5;
static WdgM_EntityStatusGType EntityStatusG_6;
static WdgM_EntityStatusGType EntityStatusG_7;
static WdgM_EntityStatusGType EntityStatusG_8;
static WdgM_EntityStatusGType EntityStatusG_9;

/* Global Alive Counters for Checkpoints in SE `SE100ms_9`                   */
static WdgM_AliveCounterGType Alive_CounterG_0;

/* Global Alive Counters for Checkpoints in SE `SE100ms_10`                  */
static WdgM_AliveCounterGType Alive_CounterG_1;

/* Global Alive Counters for Checkpoints in SE `SE10ms_10`                   */
static WdgM_AliveCounterGType Alive_CounterG_2;

/* Global Alive Counters for Checkpoints in SE `SE10ms_9`                    */
static WdgM_AliveCounterGType Alive_CounterG_3;

/* Global Alive Counters for Checkpoints in SE `SE4ms_8`                     */
static WdgM_AliveCounterGType Alive_CounterG_4;

/* Global Alive Counters for Checkpoints in SE `SE4ms_10`                    */
static WdgM_AliveCounterGType Alive_CounterG_5;

/* Global Alive Counters for Checkpoints in SE `SE2ms_10`                    */
static WdgM_AliveCounterGType Alive_CounterG_6;

/* Global Alive Counters for Checkpoints in SE `SE2ms_9`                     */
static WdgM_AliveCounterGType Alive_CounterG_7;

/* RAM section for Global Status                                             */
static WdgM_DataGType StatusG;
#define WDGM_GLOBAL_STOP_SEC_VAR_NOINIT_UNSPECIFIED 
#include "MemMap.h"

#define WDGM_GLOBAL_SHARED_START_SEC_VAR_NOINIT_UNSPECIFIED 
#include "MemMap.h"
/* RAM section for Global Shared data                                        */
static WdgM_DataGSType StatusGS;
static WdgM_EntityGSType EntityGS [NR_OF_ENTITIES];
static WdgM_GlobalTransitionFlagGSType GlobalTransitionFlagsGS [NR_OF_GLOBAL_TRANSITIONS];
#define WDGM_GLOBAL_SHARED_STOP_SEC_VAR_NOINIT_UNSPECIFIED 
#include "MemMap.h"

#define WDGM_START_SEC_CONST_UNSPECIFIED 
#include "MemMap.h"

static const WdgM_TransitionType WdgMTransition [NR_OF_LOCAL_TRANSITIONS] =
  { { 0 /* SE100ms_9 */ /* EntitySourceId                                    */
    , 0 /* CtrlTemp_Per2_CP0 */ /* CheckpointSourceId                        */
    , 0 /* WdgMDeadlineMin                                                   */
    , 0 /* WdgMDeadlineMax                                                     */
    } /* [0]                                                               */
  , { 1 /* SE100ms_10 */ /* EntitySourceId                                   */
    , 0 /* HwTrq_Per3_CP0 */ /* CheckpointSourceId                           */
    , 0 /* WdgMDeadlineMin                                                   */
    , 0 /* WdgMDeadlineMax                                                     */
    } /* [1]                                                               */
  , { 3 /* SE10ms_10 */ /* EntitySourceId                                    */
    , 0 /* TuningSelAuth_Per1_CP0 */ /* CheckpointSourceId                   */
    , 0 /* WdgMDeadlineMin                                                   */
    , 0 /* WdgMDeadlineMax                                                     */
    } /* [2]                                                               */
  , { 4 /* SE10ms_9 */ /* EntitySourceId                                     */
    , 0 /* SrlComInput_Per1_CP0 */ /* CheckpointSourceId                     */
    , 0 /* WdgMDeadlineMin                                                   */
    , 0 /* WdgMDeadlineMax                                                     */
    } /* [3]                                                               */
  , { 5 /* SE4ms_8 */ /* EntitySourceId                                      */
    , 0 /* MtrVel2_Per2_CP0 */ /* CheckpointSourceId                         */
    , 0 /* WdgMDeadlineMin                                                   */
    , 0 /* WdgMDeadlineMax                                                     */
    } /* [4]                                                               */
  , { 6 /* SE4ms_10 */ /* EntitySourceId                                     */
    , 0 /* uDiagLossOfExec_per3_CP0 */ /* CheckpointSourceId                 */
    , 0 /* WdgMDeadlineMin                                                   */
    , 0 /* WdgMDeadlineMax                                                     */
    } /* [5]                                                               */
  , { 7 /* SE2ms_10 */ /* EntitySourceId                                     */
    , 0 /* MtrVel_Per1_CP0 */ /* CheckpointSourceId                          */
    , 0 /* WdgMDeadlineMin                                                   */
    , 0 /* WdgMDeadlineMax                                                     */
    } /* [6]                                                               */
  , { 8 /* SE2ms_9 */ /* EntitySourceId                                      */
    , 0 /* BatterVoltage_Per1_CP0 */ /* CheckpointSourceId                   */
    , 0 /* WdgMDeadlineMin                                                   */
    , 0 /* WdgMDeadlineMax                                                     */
    } /* [7]                                                               */
  , { 9 /* SE2ms_8 */ /* EntitySourceId                                      */
    , 0 /* MtrVel2_Per1_CP0 */ /* CheckpointSourceId                         */
    , 0 /* WdgMDeadlineMin                                                   */
    , 0 /* WdgMDeadlineMax                                                     */
    } /* [8]                                                               */
  };
#define WDGM_STOP_SEC_CONST_UNSPECIFIED 
#include "MemMap.h"

#define WDGM_START_SEC_CONST_UNSPECIFIED 
#include "MemMap.h"

static const WdgM_GlobalTransitionType WdgMGlobalTransition [NR_OF_GLOBAL_TRANSITIONS] =
  { { 2 /* SE100ms_8 */ /* EntitySourceId                                    */
    , 0 /* HwTrq2_Per3_CP0 */ /* CheckpointSourceId                          */
    , 0 /* WdgMDeadlineMin                                                   */
    , 0 /* WdgMDeadlineMax                                                     */
    , 0 /* GlobalTransitionFlagId                                              */
    } /* [0]                                                               */
  , { 1 /* SE100ms_10 */ /* EntitySourceId                                   */
    , 1 /* uDiagStaticRegs_Per_CP1 */ /* CheckpointSourceId                  */
    , 0 /* WdgMDeadlineMin                                                   */
    , 0 /* WdgMDeadlineMax                                                     */
    , 1 /* GlobalTransitionFlagId                                              */
    } /* [1]                                                               */
  , { 4 /* SE10ms_9 */ /* EntitySourceId                                     */
    , 1 /* BVDiag_Per1_CP1 */ /* CheckpointSourceId                          */
    , 0 /* WdgMDeadlineMin                                                   */
    , 0 /* WdgMDeadlineMax                                                     */
    , 2 /* GlobalTransitionFlagId                                              */
    } /* [2]                                                               */
  , { 6 /* SE4ms_10 */ /* EntitySourceId                                     */
    , 1 /* ArbLmt_Per1_CP1 */ /* CheckpointSourceId                          */
    , 0 /* WdgMDeadlineMin                                                   */
    , 0 /* WdgMDeadlineMax                                                     */
    , 3 /* GlobalTransitionFlagId                                              */
    } /* [3]                                                               */
  , { 9 /* SE2ms_8 */ /* EntitySourceId                                      */
    , 1 /* TmprlMon2_Per1_CP1 */ /* CheckpointSourceId                       */
    , 0 /* WdgMDeadlineMin                                                   */
    , 0 /* WdgMDeadlineMax                                                     */
    , 4 /* GlobalTransitionFlagId                                              */
    } /* [4]                                                               */
  , { 7 /* SE2ms_10 */ /* EntitySourceId                                     */
    , 1 /* StaMd_Per1_CP1 */ /* CheckpointSourceId                           */
    , 0 /* WdgMDeadlineMin                                                   */
    , 0 /* WdgMDeadlineMax                                                     */
    , 5 /* GlobalTransitionFlagId                                              */
    } /* [5]                                                               */
  };
#define WDGM_STOP_SEC_CONST_UNSPECIFIED 
#include "MemMap.h"

#define WDGM_START_SEC_CONST_UNSPECIFIED 
#include "MemMap.h"
static const WdgM_TransitionIdType StartsGlobalTransition_SE100ms_8_HwTrq2_Per3_CP0 [1] =
  { 0 /* [0]                                                                 */
  };
static const WdgM_TransitionIdType StartsGlobalTransition_SE2ms_8_TmprlMon2_Per1_CP1 [1] =
  { 4 /* [0]                                                                 */
  };
static const WdgM_TransitionIdType StartsGlobalTransition_SE2ms_10_StaMd_Per1_CP1 [1] =
  { 5 /* [0]                                                                 */
  };
static const WdgM_TransitionIdType StartsGlobalTransition_SE4ms_10_ArbLmt_Per1_CP1 [1] =
  { 3 /* [0]                                                                 */
  };
static const WdgM_TransitionIdType StartsGlobalTransition_SE10ms_9_BVDiag_Per1_CP1 [1] =
  { 2 /* [0]                                                                 */
  };
static const WdgM_TransitionIdType StartsGlobalTransition_SE100ms_10_uDiagStaticRegs_Per_CP1 [1] =
  { 1 /* [0]                                                                 */
  };
#define WDGM_STOP_SEC_CONST_UNSPECIFIED 
#include "MemMap.h"
#define WDGM_START_SEC_CONST_UNSPECIFIED 
#include "MemMap.h"

static const WdgM_CheckPointType WdgMCheckPoint [NR_OF_CHECKPOINTS] =
  { { 0 /* SE100ms_9/CtrlTemp_Per2_CP0 */ /* WdgMCheckpointId                */
    , FALSE /* WdgMIsEndCheckpoint                                           */
    , FALSE /* WdgMIsEndCheckpointGlobal                                     */
    , 0 /* WdgMExpectedAliveIndications                                        */
    , 0 /* WdgMMinMargin                                                       */
    , 0 /* WdgMMaxMargin                                                       */
    , 0 /* WdgMSupervisionReferenceCycle                                       */
    , NULL_PTR /* WdgMAliveLRef                                                */
    , NULL_PTR /* WdgMAliveGRef                                                */
    , FALSE /* WdgMDeadlineMonitoring                                          */
    , 0 /* WdgMOutgoingDeadlineMax                                             */
    , 0 /* NrOfLocalTransitions                                                */
    , NULL_PTR /* WdgMLocalTransitionRef                                       */
    , 1 /* NrOfGlobalTransitions                                               */
    , &WdgMGlobalTransition [0] /* WdgMGlobalTransitionsRef                    */
    , FALSE /* WdgMStartsAGlobalTransition                                     */
    , 0 /* NrOfStartedGlobalTransitions                                        */
    , NULL_PTR /* WdgMStartedGlobalTransitionIds                               */
    } /* [0]                                                               */
  , { 1 /* SE100ms_9/ThrmlDutyCycle_Per1_CP1 */ /* WdgMCheckpointId          */
    , TRUE /* WdgMIsEndCheckpoint                                            */
    , FALSE /* WdgMIsEndCheckpointGlobal                                     */
    , 1 /* WdgMExpectedAliveIndications                                        */
    , 0 /* WdgMMinMargin                                                       */
    , 0 /* WdgMMaxMargin                                                       */
    , 25 /* WdgMSupervisionReferenceCycle                                      */
    , &Alive_CounterL_0 /* WdgMAliveLRef                                       */
    , &Alive_CounterG_0 /* WdgMAliveGRef                                       */
    , FALSE /* WdgMDeadlineMonitoring                                          */
    , 0 /* WdgMOutgoingDeadlineMax                                             */
    , 1 /* NrOfLocalTransitions                                                */
    , &WdgMTransition [0] /* WdgMLocalTransitionRef                            */
    , 0 /* NrOfGlobalTransitions                                               */
    , NULL_PTR /* WdgMGlobalTransitionsRef                                     */
    , FALSE /* WdgMStartsAGlobalTransition                                     */
    , 0 /* NrOfStartedGlobalTransitions                                        */
    , NULL_PTR /* WdgMStartedGlobalTransitionIds                               */
    } /* [1]                                                               */
  , { 0 /* SE100ms_10/HwTrq_Per3_CP0 */ /* WdgMCheckpointId                  */
    , FALSE /* WdgMIsEndCheckpoint                                           */
    , FALSE /* WdgMIsEndCheckpointGlobal                                     */
    , 1 /* WdgMExpectedAliveIndications                                        */
    , 0 /* WdgMMinMargin                                                       */
    , 0 /* WdgMMaxMargin                                                       */
    , 25 /* WdgMSupervisionReferenceCycle                                      */
    , &Alive_CounterL_1 /* WdgMAliveLRef                                       */
    , &Alive_CounterG_1 /* WdgMAliveGRef                                       */
    , FALSE /* WdgMDeadlineMonitoring                                          */
    , 0 /* WdgMOutgoingDeadlineMax                                             */
    , 0 /* NrOfLocalTransitions                                                */
    , NULL_PTR /* WdgMLocalTransitionRef                                       */
    , 0 /* NrOfGlobalTransitions                                               */
    , NULL_PTR /* WdgMGlobalTransitionsRef                                     */
    , FALSE /* WdgMStartsAGlobalTransition                                     */
    , 0 /* NrOfStartedGlobalTransitions                                        */
    , NULL_PTR /* WdgMStartedGlobalTransitionIds                               */
    } /* [2]                                                               */
  , { 1 /* SE100ms_10/uDiagStaticRegs_Per_CP1 */ /* WdgMCheckpointId         */
    , TRUE /* WdgMIsEndCheckpoint                                            */
    , FALSE /* WdgMIsEndCheckpointGlobal                                     */
    , 0 /* WdgMExpectedAliveIndications                                        */
    , 0 /* WdgMMinMargin                                                       */
    , 0 /* WdgMMaxMargin                                                       */
    , 0 /* WdgMSupervisionReferenceCycle                                       */
    , NULL_PTR /* WdgMAliveLRef                                                */
    , NULL_PTR /* WdgMAliveGRef                                                */
    , FALSE /* WdgMDeadlineMonitoring                                          */
    , 0 /* WdgMOutgoingDeadlineMax                                             */
    , 1 /* NrOfLocalTransitions                                                */
    , &WdgMTransition [1] /* WdgMLocalTransitionRef                            */
    , 0 /* NrOfGlobalTransitions                                               */
    , NULL_PTR /* WdgMGlobalTransitionsRef                                     */
    , TRUE /* WdgMStartsAGlobalTransition                                      */
    , 1 /* NrOfStartedGlobalTransitions                                        */
    , StartsGlobalTransition_SE100ms_10_uDiagStaticRegs_Per_CP1 /* WdgMStarted */
     /* GlobalTrans */
     /* itionIds    */
    } /* [3]                                                               */
  , { 0 /* SE100ms_8/HwTrq2_Per3_CP0 */ /* WdgMCheckpointId                  */
    , TRUE /* WdgMIsEndCheckpoint                                            */
    , FALSE /* WdgMIsEndCheckpointGlobal                                     */
    , 0 /* WdgMExpectedAliveIndications                                        */
    , 0 /* WdgMMinMargin                                                       */
    , 0 /* WdgMMaxMargin                                                       */
    , 0 /* WdgMSupervisionReferenceCycle                                       */
    , NULL_PTR /* WdgMAliveLRef                                                */
    , NULL_PTR /* WdgMAliveGRef                                                */
    , FALSE /* WdgMDeadlineMonitoring                                          */
    , 0 /* WdgMOutgoingDeadlineMax                                             */
    , 0 /* NrOfLocalTransitions                                                */
    , NULL_PTR /* WdgMLocalTransitionRef                                       */
    , 1 /* NrOfGlobalTransitions                                               */
    , &WdgMGlobalTransition [1] /* WdgMGlobalTransitionsRef                    */
    , TRUE /* WdgMStartsAGlobalTransition                                      */
    , 1 /* NrOfStartedGlobalTransitions                                        */
    , StartsGlobalTransition_SE100ms_8_HwTrq2_Per3_CP0 /* WdgMStartedGlobalTra */
     /* nsitionIds           */
    } /* [4]                                                               */
  , { 0 /* SE10ms_10/TuningSelAuth_Per1_CP0 */ /* WdgMCheckpointId           */
    , FALSE /* WdgMIsEndCheckpoint                                           */
    , FALSE /* WdgMIsEndCheckpointGlobal                                     */
    , 0 /* WdgMExpectedAliveIndications                                        */
    , 0 /* WdgMMinMargin                                                       */
    , 0 /* WdgMMaxMargin                                                       */
    , 0 /* WdgMSupervisionReferenceCycle                                       */
    , NULL_PTR /* WdgMAliveLRef                                                */
    , NULL_PTR /* WdgMAliveGRef                                                */
    , FALSE /* WdgMDeadlineMonitoring                                          */
    , 0 /* WdgMOutgoingDeadlineMax                                             */
    , 0 /* NrOfLocalTransitions                                                */
    , NULL_PTR /* WdgMLocalTransitionRef                                       */
    , 1 /* NrOfGlobalTransitions                                               */
    , &WdgMGlobalTransition [2] /* WdgMGlobalTransitionsRef                    */
    , FALSE /* WdgMStartsAGlobalTransition                                     */
    , 0 /* NrOfStartedGlobalTransitions                                        */
    , NULL_PTR /* WdgMStartedGlobalTransitionIds                               */
    } /* [5]                                                               */
  , { 1 /* SE10ms_10/PAwTO_Per2_CP1 */ /* WdgMCheckpointId                   */
    , TRUE /* WdgMIsEndCheckpoint                                            */
    , FALSE /* WdgMIsEndCheckpointGlobal                                     */
    , 2 /* WdgMExpectedAliveIndications                                        */
    , 0 /* WdgMMinMargin                                                       */
    , 0 /* WdgMMaxMargin                                                       */
    , 5 /* WdgMSupervisionReferenceCycle                                       */
    , &Alive_CounterL_2 /* WdgMAliveLRef                                       */
    , &Alive_CounterG_2 /* WdgMAliveGRef                                       */
    , FALSE /* WdgMDeadlineMonitoring                                          */
    , 0 /* WdgMOutgoingDeadlineMax                                             */
    , 1 /* NrOfLocalTransitions                                                */
    , &WdgMTransition [2] /* WdgMLocalTransitionRef                            */
    , 0 /* NrOfGlobalTransitions                                               */
    , NULL_PTR /* WdgMGlobalTransitionsRef                                     */
    , FALSE /* WdgMStartsAGlobalTransition                                     */
    , 0 /* NrOfStartedGlobalTransitions                                        */
    , NULL_PTR /* WdgMStartedGlobalTransitionIds                               */
    } /* [6]                                                               */
  , { 0 /* SE10ms_9/SrlComInput_Per1_CP0 */ /* WdgMCheckpointId              */
    , FALSE /* WdgMIsEndCheckpoint                                           */
    , FALSE /* WdgMIsEndCheckpointGlobal                                     */
    , 2 /* WdgMExpectedAliveIndications                                        */
    , 0 /* WdgMMinMargin                                                       */
    , 0 /* WdgMMaxMargin                                                       */
    , 5 /* WdgMSupervisionReferenceCycle                                       */
    , &Alive_CounterL_3 /* WdgMAliveLRef                                       */
    , &Alive_CounterG_3 /* WdgMAliveGRef                                       */
    , FALSE /* WdgMDeadlineMonitoring                                          */
    , 0 /* WdgMOutgoingDeadlineMax                                             */
    , 0 /* NrOfLocalTransitions                                                */
    , NULL_PTR /* WdgMLocalTransitionRef                                       */
    , 0 /* NrOfGlobalTransitions                                               */
    , NULL_PTR /* WdgMGlobalTransitionsRef                                     */
    , FALSE /* WdgMStartsAGlobalTransition                                     */
    , 0 /* NrOfStartedGlobalTransitions                                        */
    , NULL_PTR /* WdgMStartedGlobalTransitionIds                               */
    } /* [7]                                                               */
  , { 1 /* SE10ms_9/BVDiag_Per1_CP1 */ /* WdgMCheckpointId                   */
    , TRUE /* WdgMIsEndCheckpoint                                            */
    , FALSE /* WdgMIsEndCheckpointGlobal                                     */
    , 0 /* WdgMExpectedAliveIndications                                        */
    , 0 /* WdgMMinMargin                                                       */
    , 0 /* WdgMMaxMargin                                                       */
    , 0 /* WdgMSupervisionReferenceCycle                                       */
    , NULL_PTR /* WdgMAliveLRef                                                */
    , NULL_PTR /* WdgMAliveGRef                                                */
    , FALSE /* WdgMDeadlineMonitoring                                          */
    , 0 /* WdgMOutgoingDeadlineMax                                             */
    , 1 /* NrOfLocalTransitions                                                */
    , &WdgMTransition [3] /* WdgMLocalTransitionRef                            */
    , 0 /* NrOfGlobalTransitions                                               */
    , NULL_PTR /* WdgMGlobalTransitionsRef                                     */
    , TRUE /* WdgMStartsAGlobalTransition                                      */
    , 1 /* NrOfStartedGlobalTransitions                                        */
    , StartsGlobalTransition_SE10ms_9_BVDiag_Per1_CP1 /* WdgMStartedGlobalTran */
     /* sitionIds             */
    } /* [8]                                                               */
  , { 0 /* SE4ms_8/MtrVel2_Per2_CP0 */ /* WdgMCheckpointId                   */
    , FALSE /* WdgMIsEndCheckpoint                                           */
    , FALSE /* WdgMIsEndCheckpointGlobal                                     */
    , 0 /* WdgMExpectedAliveIndications                                        */
    , 0 /* WdgMMinMargin                                                       */
    , 0 /* WdgMMaxMargin                                                       */
    , 0 /* WdgMSupervisionReferenceCycle                                       */
    , NULL_PTR /* WdgMAliveLRef                                                */
    , NULL_PTR /* WdgMAliveGRef                                                */
    , FALSE /* WdgMDeadlineMonitoring                                          */
    , 0 /* WdgMOutgoingDeadlineMax                                             */
    , 0 /* NrOfLocalTransitions                                                */
    , NULL_PTR /* WdgMLocalTransitionRef                                       */
    , 1 /* NrOfGlobalTransitions                                               */
    , &WdgMGlobalTransition [3] /* WdgMGlobalTransitionsRef                    */
    , FALSE /* WdgMStartsAGlobalTransition                                     */
    , 0 /* NrOfStartedGlobalTransitions                                        */
    , NULL_PTR /* WdgMStartedGlobalTransitionIds                               */
    } /* [9]                                                               */
  , { 1 /* SE4ms_8/MtrPos3_Per2_CP1 */ /* WdgMCheckpointId                   */
    , TRUE /* WdgMIsEndCheckpoint                                            */
    , FALSE /* WdgMIsEndCheckpointGlobal                                     */
    , 1 /* WdgMExpectedAliveIndications                                        */
    , 0 /* WdgMMinMargin                                                       */
    , 0 /* WdgMMaxMargin                                                       */
    , 1 /* WdgMSupervisionReferenceCycle                                       */
    , &Alive_CounterL_4 /* WdgMAliveLRef                                       */
    , &Alive_CounterG_4 /* WdgMAliveGRef                                       */
    , FALSE /* WdgMDeadlineMonitoring                                          */
    , 0 /* WdgMOutgoingDeadlineMax                                             */
    , 1 /* NrOfLocalTransitions                                                */
    , &WdgMTransition [4] /* WdgMLocalTransitionRef                            */
    , 0 /* NrOfGlobalTransitions                                               */
    , NULL_PTR /* WdgMGlobalTransitionsRef                                     */
    , FALSE /* WdgMStartsAGlobalTransition                                     */
    , 0 /* NrOfStartedGlobalTransitions                                        */
    , NULL_PTR /* WdgMStartedGlobalTransitionIds                               */
    } /* [10]                                                              */
  , { 0 /* SE4ms_10/uDiagLossOfExec_per3_CP0 */ /* WdgMCheckpointId          */
    , FALSE /* WdgMIsEndCheckpoint                                           */
    , FALSE /* WdgMIsEndCheckpointGlobal                                     */
    , 1 /* WdgMExpectedAliveIndications                                        */
    , 0 /* WdgMMinMargin                                                       */
    , 0 /* WdgMMaxMargin                                                       */
    , 1 /* WdgMSupervisionReferenceCycle                                       */
    , &Alive_CounterL_5 /* WdgMAliveLRef                                       */
    , &Alive_CounterG_5 /* WdgMAliveGRef                                       */
    , FALSE /* WdgMDeadlineMonitoring                                          */
    , 0 /* WdgMOutgoingDeadlineMax                                             */
    , 0 /* NrOfLocalTransitions                                                */
    , NULL_PTR /* WdgMLocalTransitionRef                                       */
    , 0 /* NrOfGlobalTransitions                                               */
    , NULL_PTR /* WdgMGlobalTransitionsRef                                     */
    , FALSE /* WdgMStartsAGlobalTransition                                     */
    , 0 /* NrOfStartedGlobalTransitions                                        */
    , NULL_PTR /* WdgMStartedGlobalTransitionIds                               */
    } /* [11]                                                              */
  , { 1 /* SE4ms_10/ArbLmt_Per1_CP1 */ /* WdgMCheckpointId                   */
    , TRUE /* WdgMIsEndCheckpoint                                            */
    , FALSE /* WdgMIsEndCheckpointGlobal                                     */
    , 0 /* WdgMExpectedAliveIndications                                        */
    , 0 /* WdgMMinMargin                                                       */
    , 0 /* WdgMMaxMargin                                                       */
    , 0 /* WdgMSupervisionReferenceCycle                                       */
    , NULL_PTR /* WdgMAliveLRef                                                */
    , NULL_PTR /* WdgMAliveGRef                                                */
    , FALSE /* WdgMDeadlineMonitoring                                          */
    , 0 /* WdgMOutgoingDeadlineMax                                             */
    , 1 /* NrOfLocalTransitions                                                */
    , &WdgMTransition [5] /* WdgMLocalTransitionRef                            */
    , 0 /* NrOfGlobalTransitions                                               */
    , NULL_PTR /* WdgMGlobalTransitionsRef                                     */
    , TRUE /* WdgMStartsAGlobalTransition                                      */
    , 1 /* NrOfStartedGlobalTransitions                                        */
    , StartsGlobalTransition_SE4ms_10_ArbLmt_Per1_CP1 /* WdgMStartedGlobalTran */
     /* sitionIds             */
    } /* [12]                                                              */
  , { 0 /* SE2ms_10/MtrVel_Per1_CP0 */ /* WdgMCheckpointId                   */
    , FALSE /* WdgMIsEndCheckpoint                                           */
    , FALSE /* WdgMIsEndCheckpointGlobal                                     */
    , 2 /* WdgMExpectedAliveIndications                                        */
    , 0 /* WdgMMinMargin                                                       */
    , 0 /* WdgMMaxMargin                                                       */
    , 1 /* WdgMSupervisionReferenceCycle                                       */
    , &Alive_CounterL_6 /* WdgMAliveLRef                                       */
    , &Alive_CounterG_6 /* WdgMAliveGRef                                       */
    , FALSE /* WdgMDeadlineMonitoring                                          */
    , 0 /* WdgMOutgoingDeadlineMax                                             */
    , 0 /* NrOfLocalTransitions                                                */
    , NULL_PTR /* WdgMLocalTransitionRef                                       */
    , 0 /* NrOfGlobalTransitions                                               */
    , NULL_PTR /* WdgMGlobalTransitionsRef                                     */
    , FALSE /* WdgMStartsAGlobalTransition                                     */
    , 0 /* NrOfStartedGlobalTransitions                                        */
    , NULL_PTR /* WdgMStartedGlobalTransitionIds                               */
    } /* [13]                                                              */
  , { 1 /* SE2ms_10/StaMd_Per1_CP1 */ /* WdgMCheckpointId                    */
    , TRUE /* WdgMIsEndCheckpoint                                            */
    , FALSE /* WdgMIsEndCheckpointGlobal                                     */
    , 0 /* WdgMExpectedAliveIndications                                        */
    , 0 /* WdgMMinMargin                                                       */
    , 0 /* WdgMMaxMargin                                                       */
    , 0 /* WdgMSupervisionReferenceCycle                                       */
    , NULL_PTR /* WdgMAliveLRef                                                */
    , NULL_PTR /* WdgMAliveGRef                                                */
    , FALSE /* WdgMDeadlineMonitoring                                          */
    , 0 /* WdgMOutgoingDeadlineMax                                             */
    , 1 /* NrOfLocalTransitions                                                */
    , &WdgMTransition [6] /* WdgMLocalTransitionRef                            */
    , 0 /* NrOfGlobalTransitions                                               */
    , NULL_PTR /* WdgMGlobalTransitionsRef                                     */
    , TRUE /* WdgMStartsAGlobalTransition                                      */
    , 1 /* NrOfStartedGlobalTransitions                                        */
    , StartsGlobalTransition_SE2ms_10_StaMd_Per1_CP1 /* WdgMStartedGlobalTrans */
     /* itionIds               */
    } /* [14]                                                              */
  , { 2 /* SE2ms_10/GlbFinal_CP0 */ /* WdgMCheckpointId                      */
    , FALSE /* WdgMIsEndCheckpoint                                           */
    , TRUE /* WdgMIsEndCheckpointGlobal                                      */
    , 0 /* WdgMExpectedAliveIndications                                        */
    , 0 /* WdgMMinMargin                                                       */
    , 0 /* WdgMMaxMargin                                                       */
    , 0 /* WdgMSupervisionReferenceCycle                                       */
    , NULL_PTR /* WdgMAliveLRef                                                */
    , NULL_PTR /* WdgMAliveGRef                                                */
    , FALSE /* WdgMDeadlineMonitoring                                          */
    , 0 /* WdgMOutgoingDeadlineMax                                             */
    , 0 /* NrOfLocalTransitions                                                */
    , NULL_PTR /* WdgMLocalTransitionRef                                       */
    , 0 /* NrOfGlobalTransitions                                               */
    , NULL_PTR /* WdgMGlobalTransitionsRef                                     */
    , FALSE /* WdgMStartsAGlobalTransition                                     */
    , 0 /* NrOfStartedGlobalTransitions                                        */
    , NULL_PTR /* WdgMStartedGlobalTransitionIds                               */
    } /* [15]                                                              */
  , { 0 /* SE2ms_9/BatterVoltage_Per1_CP0 */ /* WdgMCheckpointId             */
    , FALSE /* WdgMIsEndCheckpoint                                           */
    , FALSE /* WdgMIsEndCheckpointGlobal                                     */
    , 0 /* WdgMExpectedAliveIndications                                        */
    , 0 /* WdgMMinMargin                                                       */
    , 0 /* WdgMMaxMargin                                                       */
    , 0 /* WdgMSupervisionReferenceCycle                                       */
    , NULL_PTR /* WdgMAliveLRef                                                */
    , NULL_PTR /* WdgMAliveGRef                                                */
    , FALSE /* WdgMDeadlineMonitoring                                          */
    , 0 /* WdgMOutgoingDeadlineMax                                             */
    , 0 /* NrOfLocalTransitions                                                */
    , NULL_PTR /* WdgMLocalTransitionRef                                       */
    , 1 /* NrOfGlobalTransitions                                               */
    , &WdgMGlobalTransition [4] /* WdgMGlobalTransitionsRef                    */
    , FALSE /* WdgMStartsAGlobalTransition                                     */
    , 0 /* NrOfStartedGlobalTransitions                                        */
    , NULL_PTR /* WdgMStartedGlobalTransitionIds                               */
    } /* [16]                                                              */
  , { 1 /* SE2ms_9/VehPwrMd_Per1_CP1 */ /* WdgMCheckpointId                  */
    , TRUE /* WdgMIsEndCheckpoint                                            */
    , FALSE /* WdgMIsEndCheckpointGlobal                                     */
    , 2 /* WdgMExpectedAliveIndications                                        */
    , 0 /* WdgMMinMargin                                                       */
    , 0 /* WdgMMaxMargin                                                       */
    , 1 /* WdgMSupervisionReferenceCycle                                       */
    , &Alive_CounterL_7 /* WdgMAliveLRef                                       */
    , &Alive_CounterG_7 /* WdgMAliveGRef                                       */
    , FALSE /* WdgMDeadlineMonitoring                                          */
    , 0 /* WdgMOutgoingDeadlineMax                                             */
    , 1 /* NrOfLocalTransitions                                                */
    , &WdgMTransition [7] /* WdgMLocalTransitionRef                            */
    , 0 /* NrOfGlobalTransitions                                               */
    , NULL_PTR /* WdgMGlobalTransitionsRef                                     */
    , FALSE /* WdgMStartsAGlobalTransition                                     */
    , 0 /* NrOfStartedGlobalTransitions                                        */
    , NULL_PTR /* WdgMStartedGlobalTransitionIds                               */
    } /* [17]                                                              */
  , { 0 /* SE2ms_8/MtrVel2_Per1_CP0 */ /* WdgMCheckpointId                   */
    , FALSE /* WdgMIsEndCheckpoint                                           */
    , FALSE /* WdgMIsEndCheckpointGlobal                                     */
    , 0 /* WdgMExpectedAliveIndications                                        */
    , 0 /* WdgMMinMargin                                                       */
    , 0 /* WdgMMaxMargin                                                       */
    , 0 /* WdgMSupervisionReferenceCycle                                       */
    , NULL_PTR /* WdgMAliveLRef                                                */
    , NULL_PTR /* WdgMAliveGRef                                                */
    , FALSE /* WdgMDeadlineMonitoring                                          */
    , 0 /* WdgMOutgoingDeadlineMax                                             */
    , 0 /* NrOfLocalTransitions                                                */
    , NULL_PTR /* WdgMLocalTransitionRef                                       */
    , 1 /* NrOfGlobalTransitions                                               */
    , &WdgMGlobalTransition [5] /* WdgMGlobalTransitionsRef                    */
    , FALSE /* WdgMStartsAGlobalTransition                                     */
    , 0 /* NrOfStartedGlobalTransitions                                        */
    , NULL_PTR /* WdgMStartedGlobalTransitionIds                               */
    } /* [18]                                                              */
  , { 1 /* SE2ms_8/TmprlMon2_Per1_CP1 */ /* WdgMCheckpointId                 */
    , TRUE /* WdgMIsEndCheckpoint                                            */
    , FALSE /* WdgMIsEndCheckpointGlobal                                     */
    , 0 /* WdgMExpectedAliveIndications                                        */
    , 0 /* WdgMMinMargin                                                       */
    , 0 /* WdgMMaxMargin                                                       */
    , 0 /* WdgMSupervisionReferenceCycle                                       */
    , NULL_PTR /* WdgMAliveLRef                                                */
    , NULL_PTR /* WdgMAliveGRef                                                */
    , FALSE /* WdgMDeadlineMonitoring                                          */
    , 0 /* WdgMOutgoingDeadlineMax                                             */
    , 1 /* NrOfLocalTransitions                                                */
    , &WdgMTransition [8] /* WdgMLocalTransitionRef                            */
    , 0 /* NrOfGlobalTransitions                                               */
    , NULL_PTR /* WdgMGlobalTransitionsRef                                     */
    , TRUE /* WdgMStartsAGlobalTransition                                      */
    , 1 /* NrOfStartedGlobalTransitions                                        */
    , StartsGlobalTransition_SE2ms_8_TmprlMon2_Per1_CP1 /* WdgMStartedGlobalTr */
     /* ansitionIds         */
    } /* [19]                                                              */
  };
#define WDGM_STOP_SEC_CONST_UNSPECIFIED 
#include "MemMap.h"

#define WDGM_START_SEC_CONST_UNSPECIFIED 
#include "MemMap.h"

static const WdgM_SupervisedEntityType WdgMSupervisedEntity [NR_OF_ENTITIES] =
  { { 0 /* SE100ms_9 */ /* WdgMSupervisedEntityId                            */
    , FALSE /* WdgMEnableEntityDeactivation                                  */
    , 0 /* WdgMCheckpointLocInitialId                                        */
    , 2 /* NrOfCheckpoints                                                     */
    , &WdgMCheckPoint [0] /* WdgMCheckpointRef                                 */
    , WDGM_LOCAL_STATUS_OK /* WdgMInitialStatus                                */
    , 0 /* WdgMFailedSupervisionRefCycleTol                                    */
    , 0 /* WdgMFailedDeadlineRefCycleTol                                       */
    , 0 /* WdgMDeadlineReferenceCycle                                          */
    , 0 /* WdgMFailedProgramFlowRefCycleTol                                    */
    , 0 /* WdgMProgramFlowReferenceCycle                                       */
    , TRUE /* WdgMProgramFlowMonitoring                                        */
    , WDGM_INVALID_OSAPPLICATION /* OSApplication                              */
    , NULL_PTR /* WdgM_LocalStateChangeCbk                                     */
    , &EntityStatusL_0 /* EntityStatusLRef                                     */
    , &EntityStatusG_0 /* EntityStatusGRef                                     */
    } /* [0]                                                               */
  , { 1 /* SE100ms_10 */ /* WdgMSupervisedEntityId                           */
    , FALSE /* WdgMEnableEntityDeactivation                                  */
    , 0 /* WdgMCheckpointLocInitialId                                        */
    , 2 /* NrOfCheckpoints                                                     */
    , &WdgMCheckPoint [2] /* WdgMCheckpointRef                                 */
    , WDGM_LOCAL_STATUS_OK /* WdgMInitialStatus                                */
    , 0 /* WdgMFailedSupervisionRefCycleTol                                    */
    , 0 /* WdgMFailedDeadlineRefCycleTol                                       */
    , 0 /* WdgMDeadlineReferenceCycle                                          */
    , 0 /* WdgMFailedProgramFlowRefCycleTol                                    */
    , 0 /* WdgMProgramFlowReferenceCycle                                       */
    , TRUE /* WdgMProgramFlowMonitoring                                        */
    , WDGM_INVALID_OSAPPLICATION /* OSApplication                              */
    , NULL_PTR /* WdgM_LocalStateChangeCbk                                     */
    , &EntityStatusL_1 /* EntityStatusLRef                                     */
    , &EntityStatusG_1 /* EntityStatusGRef                                     */
    } /* [1]                                                               */
  , { 2 /* SE100ms_8 */ /* WdgMSupervisedEntityId                            */
    , FALSE /* WdgMEnableEntityDeactivation                                  */
    , 0 /* WdgMCheckpointLocInitialId                                        */
    , 1 /* NrOfCheckpoints                                                     */
    , &WdgMCheckPoint [4] /* WdgMCheckpointRef                                 */
    , WDGM_LOCAL_STATUS_OK /* WdgMInitialStatus                                */
    , 0 /* WdgMFailedSupervisionRefCycleTol                                    */
    , 0 /* WdgMFailedDeadlineRefCycleTol                                       */
    , 0 /* WdgMDeadlineReferenceCycle                                          */
    , 0 /* WdgMFailedProgramFlowRefCycleTol                                    */
    , 0 /* WdgMProgramFlowReferenceCycle                                       */
    , TRUE /* WdgMProgramFlowMonitoring                                        */
    , WDGM_INVALID_OSAPPLICATION /* OSApplication                              */
    , NULL_PTR /* WdgM_LocalStateChangeCbk                                     */
    , &EntityStatusL_2 /* EntityStatusLRef                                     */
    , &EntityStatusG_2 /* EntityStatusGRef                                     */
    } /* [2]                                                               */
  , { 3 /* SE10ms_10 */ /* WdgMSupervisedEntityId                            */
    , FALSE /* WdgMEnableEntityDeactivation                                  */
    , 0 /* WdgMCheckpointLocInitialId                                        */
    , 2 /* NrOfCheckpoints                                                     */
    , &WdgMCheckPoint [5] /* WdgMCheckpointRef                                 */
    , WDGM_LOCAL_STATUS_OK /* WdgMInitialStatus                                */
    , 0 /* WdgMFailedSupervisionRefCycleTol                                    */
    , 0 /* WdgMFailedDeadlineRefCycleTol                                       */
    , 0 /* WdgMDeadlineReferenceCycle                                          */
    , 0 /* WdgMFailedProgramFlowRefCycleTol                                    */
    , 0 /* WdgMProgramFlowReferenceCycle                                       */
    , TRUE /* WdgMProgramFlowMonitoring                                        */
    , WDGM_INVALID_OSAPPLICATION /* OSApplication                              */
    , NULL_PTR /* WdgM_LocalStateChangeCbk                                     */
    , &EntityStatusL_3 /* EntityStatusLRef                                     */
    , &EntityStatusG_3 /* EntityStatusGRef                                     */
    } /* [3]                                                               */
  , { 4 /* SE10ms_9 */ /* WdgMSupervisedEntityId                             */
    , FALSE /* WdgMEnableEntityDeactivation                                  */
    , 0 /* WdgMCheckpointLocInitialId                                        */
    , 2 /* NrOfCheckpoints                                                     */
    , &WdgMCheckPoint [7] /* WdgMCheckpointRef                                 */
    , WDGM_LOCAL_STATUS_OK /* WdgMInitialStatus                                */
    , 0 /* WdgMFailedSupervisionRefCycleTol                                    */
    , 0 /* WdgMFailedDeadlineRefCycleTol                                       */
    , 0 /* WdgMDeadlineReferenceCycle                                          */
    , 0 /* WdgMFailedProgramFlowRefCycleTol                                    */
    , 0 /* WdgMProgramFlowReferenceCycle                                       */
    , TRUE /* WdgMProgramFlowMonitoring                                        */
    , WDGM_INVALID_OSAPPLICATION /* OSApplication                              */
    , NULL_PTR /* WdgM_LocalStateChangeCbk                                     */
    , &EntityStatusL_4 /* EntityStatusLRef                                     */
    , &EntityStatusG_4 /* EntityStatusGRef                                     */
    } /* [4]                                                               */
  , { 5 /* SE4ms_8 */ /* WdgMSupervisedEntityId                              */
    , FALSE /* WdgMEnableEntityDeactivation                                  */
    , 0 /* WdgMCheckpointLocInitialId                                        */
    , 2 /* NrOfCheckpoints                                                     */
    , &WdgMCheckPoint [9] /* WdgMCheckpointRef                                 */
    , WDGM_LOCAL_STATUS_OK /* WdgMInitialStatus                                */
    , 0 /* WdgMFailedSupervisionRefCycleTol                                    */
    , 0 /* WdgMFailedDeadlineRefCycleTol                                       */
    , 0 /* WdgMDeadlineReferenceCycle                                          */
    , 0 /* WdgMFailedProgramFlowRefCycleTol                                    */
    , 0 /* WdgMProgramFlowReferenceCycle                                       */
    , TRUE /* WdgMProgramFlowMonitoring                                        */
    , WDGM_INVALID_OSAPPLICATION /* OSApplication                              */
    , NULL_PTR /* WdgM_LocalStateChangeCbk                                     */
    , &EntityStatusL_5 /* EntityStatusLRef                                     */
    , &EntityStatusG_5 /* EntityStatusGRef                                     */
    } /* [5]                                                               */
  , { 6 /* SE4ms_10 */ /* WdgMSupervisedEntityId                             */
    , FALSE /* WdgMEnableEntityDeactivation                                  */
    , 0 /* WdgMCheckpointLocInitialId                                        */
    , 2 /* NrOfCheckpoints                                                     */
    , &WdgMCheckPoint [11] /* WdgMCheckpointRef                                */
    , WDGM_LOCAL_STATUS_OK /* WdgMInitialStatus                                */
    , 0 /* WdgMFailedSupervisionRefCycleTol                                    */
    , 0 /* WdgMFailedDeadlineRefCycleTol                                       */
    , 0 /* WdgMDeadlineReferenceCycle                                          */
    , 0 /* WdgMFailedProgramFlowRefCycleTol                                    */
    , 0 /* WdgMProgramFlowReferenceCycle                                       */
    , TRUE /* WdgMProgramFlowMonitoring                                        */
    , WDGM_INVALID_OSAPPLICATION /* OSApplication                              */
    , NULL_PTR /* WdgM_LocalStateChangeCbk                                     */
    , &EntityStatusL_6 /* EntityStatusLRef                                     */
    , &EntityStatusG_6 /* EntityStatusGRef                                     */
    } /* [6]                                                               */
  , { 7 /* SE2ms_10 */ /* WdgMSupervisedEntityId                             */
    , FALSE /* WdgMEnableEntityDeactivation                                  */
    , 0 /* WdgMCheckpointLocInitialId                                        */
    , 3 /* NrOfCheckpoints                                                     */
    , &WdgMCheckPoint [13] /* WdgMCheckpointRef                                */
    , WDGM_LOCAL_STATUS_OK /* WdgMInitialStatus                                */
    , 0 /* WdgMFailedSupervisionRefCycleTol                                    */
    , 0 /* WdgMFailedDeadlineRefCycleTol                                       */
    , 0 /* WdgMDeadlineReferenceCycle                                          */
    , 0 /* WdgMFailedProgramFlowRefCycleTol                                    */
    , 0 /* WdgMProgramFlowReferenceCycle                                       */
    , TRUE /* WdgMProgramFlowMonitoring                                        */
    , WDGM_INVALID_OSAPPLICATION /* OSApplication                              */
    , NULL_PTR /* WdgM_LocalStateChangeCbk                                     */
    , &EntityStatusL_7 /* EntityStatusLRef                                     */
    , &EntityStatusG_7 /* EntityStatusGRef                                     */
    } /* [7]                                                               */
  , { 8 /* SE2ms_9 */ /* WdgMSupervisedEntityId                              */
    , FALSE /* WdgMEnableEntityDeactivation                                  */
    , 0 /* WdgMCheckpointLocInitialId                                        */
    , 2 /* NrOfCheckpoints                                                     */
    , &WdgMCheckPoint [16] /* WdgMCheckpointRef                                */
    , WDGM_LOCAL_STATUS_OK /* WdgMInitialStatus                                */
    , 0 /* WdgMFailedSupervisionRefCycleTol                                    */
    , 0 /* WdgMFailedDeadlineRefCycleTol                                       */
    , 0 /* WdgMDeadlineReferenceCycle                                          */
    , 0 /* WdgMFailedProgramFlowRefCycleTol                                    */
    , 0 /* WdgMProgramFlowReferenceCycle                                       */
    , TRUE /* WdgMProgramFlowMonitoring                                        */
    , WDGM_INVALID_OSAPPLICATION /* OSApplication                              */
    , NULL_PTR /* WdgM_LocalStateChangeCbk                                     */
    , &EntityStatusL_8 /* EntityStatusLRef                                     */
    , &EntityStatusG_8 /* EntityStatusGRef                                     */
    } /* [8]                                                               */
  , { 9 /* SE2ms_8 */ /* WdgMSupervisedEntityId                              */
    , FALSE /* WdgMEnableEntityDeactivation                                  */
    , 0 /* WdgMCheckpointLocInitialId                                        */
    , 2 /* NrOfCheckpoints                                                     */
    , &WdgMCheckPoint [18] /* WdgMCheckpointRef                                */
    , WDGM_LOCAL_STATUS_OK /* WdgMInitialStatus                                */
    , 0 /* WdgMFailedSupervisionRefCycleTol                                    */
    , 0 /* WdgMFailedDeadlineRefCycleTol                                       */
    , 0 /* WdgMDeadlineReferenceCycle                                          */
    , 0 /* WdgMFailedProgramFlowRefCycleTol                                    */
    , 0 /* WdgMProgramFlowReferenceCycle                                       */
    , TRUE /* WdgMProgramFlowMonitoring                                        */
    , WDGM_INVALID_OSAPPLICATION /* OSApplication                              */
    , NULL_PTR /* WdgM_LocalStateChangeCbk                                     */
    , &EntityStatusL_9 /* EntityStatusLRef                                     */
    , &EntityStatusG_9 /* EntityStatusGRef                                     */
    } /* [9]                                                               */
  };
#define WDGM_STOP_SEC_CONST_UNSPECIFIED 
#include "MemMap.h"

#define WDGM_START_SEC_CONST_UNSPECIFIED 
#include "MemMap.h"

static const WdgM_TriggerModeType WdgMTriggerMode  [NR_OF_WATCHDOGS * NR_OF_TRIGGER_MODES] =
  { { 2 /* WdgMTriggerWindowStart                                            */
    , 2000  /* WdgMTicksPerSecond[Hz]=1000000 */ /* WdgMTriggerWindowStartTi */
     /* cks                      */
    , 6 /* WdgMTriggerTimeout                                                  */
    , 6000 /* WdgMTriggerTimeoutTicks                                          */
    , WDGIF_SLOW_MODE /* WdgMWatchdogMode                                      */
    } /* [0]                                                               */
  };
#define WDGM_STOP_SEC_CONST_UNSPECIFIED 
#include "MemMap.h"
/* [0]: Watchdog `WdgMWatchdog`, trigger mode ID `0`                         */


#define WDGM_START_SEC_CONST_UNSPECIFIED 
#include "MemMap.h"
static const WdgM_WatchdogDeviceType WdgMWatchdogDevice [NR_OF_WATCHDOGS] =
  { { &WdgMTriggerMode  [0] /* WdgMTriggerModeRef                            */
    } /* [0]                                                               */
  };
#define WDGM_STOP_SEC_CONST_UNSPECIFIED 
#include "MemMap.h"

#define WDGM_START_SEC_CONST_UNSPECIFIED 
#include "MemMap.h"
static const WdgM_CallersType WdgMAllowedCallers  [NR_OF_ALLOWED_CALLERS] =
  { { 0 /* WdgMAllowedCaller                                                 */
    } /* [0]                                                               */
  };
#define WDGM_STOP_SEC_CONST_UNSPECIFIED 
#include "MemMap.h"

#define WDGM_START_SEC_CONST_UNSPECIFIED 
#include "MemMap.h"
const WdgM_ConfigType WdgMConfig_Mode0 =
  { 2 /* WdgMConfigMajorVersion                                              */
  , 0 /* WdgMConfigMinorVersion                                              */
  , 0 /* WdgMConfigId                                                        */
  , 0 /* WdgMInitialTriggerModeId                                              */
  , 0 /* WdgMExpiredSupervisionCycleTol                                        */
  , 7 /* WdgMGlobInitialEntityId                                               */
  , 0 /* WdgMGlobInitialCheckpointId                                           */
  , NR_OF_CHECKPOINTS /* NrOfAllCheckpoints                                    */
  , NR_OF_GLOBAL_TRANSITIONS /* NrOfGlobalTransitions                          */
  , NR_OF_WATCHDOGS /* NrOfWatchdogDevices                                     */
  , NR_OF_TRIGGER_MODES /* NrOfTriggerModes                                    */
  , WdgMWatchdogDevice /* WdgMWatchdogDeviceRef                                */
  , NR_OF_ALLOWED_CALLERS /* NrOfAllowedCallers                                */
  , WdgMAllowedCallers  /* WdgMCallersRef                                      */
  , NR_OF_ENTITIES /* NrOfSupervisedEntities                                   */
  , WdgMSupervisedEntity /* WdgMSupervisedEntityRef                            */
  , &StatusG /* DataGRef                                                       */
  , &StatusGS /* DataGSRef                                                     */
  , EntityGS /* EntityGSRef                                                    */
  , GlobalTransitionFlagsGS /* GlobalTransitionFlagsGSRef                      */
  , NULL_PTR /* WdgM_GlobalStateChangeCbk                                      */
  , 85 /* WdgMConfigChecksum                                                   */
  };
#define WDGM_STOP_SEC_CONST_UNSPECIFIED 
#include "MemMap.h"
