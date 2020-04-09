#include "main.h"
#include "port.h"
#include "SW.h"
#include "motor.h"
#include "display.h"
#include "SSD.h"
#include "FireTimer.h"
#include "VC.h"

extern tByte flag;

void TMR_Init(void)
{

	TMR0_SET_PRESCALER_256;
	TMR0_DISABLE_CLOCK;
	TMR1_Init();

}
void TMR_Start(void)
{

	TMR0_CLEAR_FLAG;
	TMR0_UPDATE_REGISTER(TEN_MILLI_TICK);
	TMR0_ENABLE_INTERRUPT;
	GLOBAL_INTERRUPT_ENABLE0;
	TMR0_ENABLE_CLOCK;

}
tByte TMR_CheckOverFlow(void)
{
	/* Add your code here! */
	return TMR0_GET_FLAG;
	/* End of your code!*/
}
void TMR_Stop(void)
{

	TMR0_DISABLE_CLOCK;

}

void TMR_Update(void) __interrupt(0)
{

	/* Call Tasks */
	//flag = 1;

    /* Reload timer */
	TMR0_CLEAR_FLAG;
	TMR0_UPDATE_REGISTER(TEN_MILLI_TICK);
    //TMR1_Start(Time_For_timer());
    //RC7 = 1 ^ RC7;
    //VC_update();
    SSD_Update();
    DISP_Update();
    SW_Update();
    //DISP_Update();
    VC_update();

    Update_Angle();
    //TMR_Stop();



}
