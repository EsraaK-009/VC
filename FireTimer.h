#ifndef FIRETIMER_H_INCLUDED
#define FIRETIMER_H_INCLUDED

#include "main.h"
//#define TMR1_INTERRUPT_ENABLE	    /* 0 --> Interrupts disabled */
									/* 1 --> Interrupts enabled */



void TMR1_Init(void);
void TMR1_Start(tWord Time);
tByte TMR1_CheckOverFlow(void);
void TMR1_Stop(void);
void TMR1_ISR(void);


#endif // FIRETIMER_H_INCLUDED
