#include "main.h"
#include "port.h"
#include "motor.h"


extern tByte flag;

void TMR1_Init(void)
{

	TMR1_PRESCALER;
	TMR1_INTERNAL_CLOCK_ENABLE;
	TMR1_OSCILLATOR_OFF;
	TMR1_STOP;

}
void TMR1_Start(tWord Time)
{

	TMR1_CLEAR_FLAG;
	TMR1_UPDATE_REGISTER(Time);
	TMR1_ENABLE_INTERRUPT;
	TMR1_PERIPHERAL_I_ENABLE;
	TMR1_START;

}
tByte TMR1_CheckOverFlow(void)
{

	return TMR1_GET_FLAG;

}
void TMR1_Stop(void)
{

	TMR1_STOP;

}

void TMR1_ISR(void)
{
    TMR1_CLEAR_FLAG;
	Fire();
	TMR1_Stop();





}
