#ifndef OS_H_INCLUDED
#define OS_H_INCLUDED

#include "main.h"
#define TMR0_INTERRUPT_ENABLE	    /* 0 --> Interrupts disabled */
									/* 1 --> Interrupts enabled */

#define TMR_TICK_MS				(10) /* HCF(P1, P2, ..., PN) */

void TMR_Init(void);
void TMR_Start(void);
tByte TMR_CheckOverFlow(void);
void TMR_Stop(void);
void TMR_Update(void) __interrupt(0); /* ISR @  vector 0 */


#endif // OS_H_INCLUDED
