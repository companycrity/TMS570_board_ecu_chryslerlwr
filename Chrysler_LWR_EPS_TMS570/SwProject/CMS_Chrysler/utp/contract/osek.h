/* The following is only part of the header that was required at the 
 * time this component was made. 
 */
 
void osPsysSuspendAllInterrupts(void);
#define SuspendAllInterrupts() (osPsysSuspendAllInterrupts())
  
void osPsysResumeAllInterrupts(void);
#define ResumeAllInterrupts() (osPsysResumeAllInterrupts())
