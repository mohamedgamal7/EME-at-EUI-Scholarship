/********************************************************************************************/
/*Author: Mohamed Gamal Rousdhy                                                             */
/*Version: V01                                                                              */
/*Date: 19/08/2023                                                                          */
/*Description: SYSTCK driver configuration file                                               */
/********************************************************************************************/
#ifndef _SYSTCK_INTERFACE_H
#define _SYSTCK_INTERFACE_H


/* PINS DEFINITIONS */
#define SYS_CLOCK          0u
#define PIOSC_4            1u

/* PINS POSITIONS */
#define ENABLE             0u
#define INTEN              1u
#define CLK_SRC            2u
#define COUNT              16u

/* INTERRUPT MODES */
#define SINGLE_INTERVAL    0u
#define PERIODIC_INTERVAL  1u
#define NO_INT             2u

/* FUNCTION PROTOTYPES */
void Systick_Init(void);
void Systick_SetBusyWait(u32 Cpy_Ticks);
void Systick_SetIntervalSingle(u32 Cpy_Ticks, void(*Ptr)(void));
void Systick_SetIntervalPeriodic(u32 Cpy_Ticks, void(*Ptr)(void));
void Systick_StopInterval(void);
u32 Systick_GetElapsedTime(void);
u32 Systick_GetRemainingTime(void);
u8 Systick_GetCountFlag(void);
void Systic_DelayBusyWait(u32 mSecs);
void SYstic_DelaySingleInterval(u32 mSecs,void(*ptr)(void));
void Systic_SEtDelayPeriodic(u32 mSecs,void(*Ptr)(void));




#endif
