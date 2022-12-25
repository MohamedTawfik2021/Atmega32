/**********************************************************************************************************************

 *  FILE DESCRIPTION
 *  -------------------------------------------------------------------------------------------------------------------
 *         File:  Timer1
 *       Module:  General Purpose timer
 *
 *  Description:  Timer1.h   
 *  
 *********************************************************************************************************************/
#ifndef TIMER1_H
#define TIMER1_H

#include <avr/io.h>
#include "StdTypes.h"
#include "Timer1_cfg.h"

#define F_CPU   8000000UL

typedef enum edge
{
	Falling=0,
	Rising
}edge;


void Timer1_Init(void);

/*Delay Mode API*/
void Timer1_Delay_Sec(f32 time);
void Timer1_Delay_mSec(f32 time);
void Timer1_Delay_uSec(f32 time);

/*PWM Modes API*/
void Timer1_FastPWM      (f32 freq, f32 duty);
void Timer1_PhasePWM     (f32 freq, f32 duty);
void Timer1_PhaseFreqPWM (f32 freq, f32 duty);

/*Input Capture Mode API*/
void StartCapture(edge trigger , u16*ticks , f32*time_ms );

/*Pulse Capture Mode API*/
u8   GetPulseCapture(u32*freq , f32*duty);

/*Periodic Tasks Mode API*/
void Timer1_PeriodicTask1(u16 period_ms , void (*p)(void));
void Timer1_PeriodicTask2(u16 period_ms , void (*p)(void));
void Timer1_PeriodicTask3(u16 period_ms , void (*p)(void));

/*Counter Mode API*/
u16 Counter1_GetCounts(void);

#endif  /* TIMER1_H*/

/**********************************************************************************************************************
 *  END OF FILE: TIMER1_H
 *********************************************************************************************************************/
