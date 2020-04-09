#include "main.h"
#include "port.h"
#include "OS.h"
#include "SW.h"
#include "VC.h"
#include "display.h"
#include "motor.h"
#include "LedD.h"

#define DLedPressTime (3000)

#define HIGH_SPEED_ANGLE (10)
#define MID_SPEED_ANGLE (90)
#define LOW_SPEED_ANGLE (140)

Speed CurrentSpeed;
#define VC_PERIOD_MS   (20)

tWord DTime =0;


static VC_state Current_state;
tSW_State ButtonState;
void VC_init(void){

    LEDD_INIT(LED_OFF);
	Set_Target_Angle(MID_SPEED_ANGLE); //Function in motor, Vc set motor.
	CurrentSpeed = MID;
	Current_state = Normal;

	}











void VC_update()
{


	static tWord VC_counter = 0;
    tByte index = 0;

    /* Check if it is time for the SW_Update to run */
    VC_counter += TMR_TICK_MS;

    if (VC_counter != VC_PERIOD_MS){
        return;
    }

    VC_counter = 0;

    switch(Current_state)
    {

    case Normal:
        Check_Dled();
        if(SW_GetState(SW_PLUS)== SW_PRE_PRESSED)
        {
            Current_state = VC_PLUS;
        }
        else if (SW_GetState(SW_MINUS)== SW_PRE_PRESSED)
        {
            Current_state = VC_MINUS;
        }
        else if (SW_GetState(SW_D)== SW_PRE_PRESSED)
        {
            Check_Dled();
            Current_state = Normal;
        }
        else
        {

        }
        break;
    case VC_PLUS:
        if((SW_GetState(SW_PLUS)== SW_PRESSED)&& CurrentSpeed == LOW)
        {
            Current_state = Normal;
            CurrentSpeed = MID;
            Set_Target_Angle(MID_SPEED_ANGLE);

        }
        else if((SW_GetState(SW_PLUS)== SW_PRESSED)&& CurrentSpeed == MID)
        {
            Current_state = Normal;
            CurrentSpeed = HIGH;
            Set_Target_Angle(HIGH_SPEED_ANGLE);

        }
        else if(SW_GetState(SW_MINUS)== SW_PRE_PRESSED)
        {
            Current_state = VC_MINUS;
            //CurrentSpeed = HIGH;

        }
        else
        {

        }
        break;
    case VC_MINUS:
        if((SW_GetState(SW_MINUS)== SW_PRESSED)&& CurrentSpeed == HIGH)
        {
            Current_state = Normal;
            CurrentSpeed = MID;
            Set_Target_Angle(MID_SPEED_ANGLE);

        }
        else if((SW_GetState(SW_MINUS)== SW_PRESSED)&& CurrentSpeed == MID)
        {
            Current_state = Normal;
            CurrentSpeed = LOW;
            Set_Target_Angle(LOW_SPEED_ANGLE);

        }
        else if(SW_GetState(SW_PLUS)== SW_PRE_PRESSED)
        {
            Current_state = VC_PLUS;
            //CurrentSpeed = HIGH;

        }
        else
        {

        }
        break;
    case No_MORE:
        CurrentSpeed = LOW;
        Set_Target_Angle(LOW_SPEED_ANGLE);
        break;
    default:
        break;
    }

	/*for (index = SW_PLUS; index < 3; index++)//sw plus change
    {
       ButtonState = SW_GetState(index);
       switch(index)
        {

		case SW_PLUS:
		  if ((ButtonState == SW_PRE_PRESSED) &&
		      (CurrentSpeed == MID))
			{
			  CurrentSpeed = HIGH;
			  Set_Target_Angle(HIGH_SPEED_ANGLE);
			}
		  else if ((ButtonState == SW_PRE_PRESSED) &&
		    	   (CurrentSpeed == LOW))
			{
			  CurrentSpeed = MID;
			  Set_Target_Angle(MID_SPEED_ANGLE);
			}
		  else  {
			//Do nothing
			}
		  break;
		case SW_MINUS:
		  if ((ButtonState == SW_PRE_PRESSED) &&
		      (CurrentSpeed == MID))
			{
			  CurrentSpeed = LOW;
			  Set_Target_Angle(LOW_SPEED_ANGLE);
			}
		  else if ((ButtonState == SW_PRE_PRESSED) &&
		    	   (CurrentSpeed == HIGH))
			{
			  CurrentSpeed = MID;
			  Set_Target_Angle(MID_SPEED_ANGLE);
			}
		  else  {
			//Do nothing
			}
		  break;
		case SW_D:
		  if (ButtonState == SW_PRESSED)
		      {
			     DTime =+10;
   				 if(DTime == DLedPressTime && CurrentSpeed == HIGH)
				   {

				       DLED_ON();
  					   CurrentSpeed = MID;
					   Set_Target_Angle(MID_SPEED_ANGLE);
					   DTime = 0;
				  }
                 else if (DTime == DLedPressTime && CurrentSpeed == MID)
 					  {
                       CurrentSpeed = LOW;
					   Set_Target_Angle(LOW_SPEED_ANGLE);
					   DTime = 0;
					  }
                 else {
    					     //Donothing
                        }


				  }



		  else
			{
			//Donothing
			}
		   break;

		default:
                break;
	}



    } */
}


Speed VC_getSpeed()
 {

   return CurrentSpeed;
 }


void Check_Dled(void)
{

    if (SW_GetState(SW_D)== SW_PRESSED)
		      {
			     DTime += TMR_TICK_MS;
   				 if(DTime == DLedPressTime && CurrentSpeed == HIGH)
				   {

				       DLED_ON();
  					   CurrentSpeed = MID;
					   Set_Target_Angle(MID_SPEED_ANGLE);
					   DTime = 0;

				  }
				  else if (DTime == DLedPressTime && CurrentSpeed == MID)
 					  {
                       CurrentSpeed = LOW;
					   Set_Target_Angle(LOW_SPEED_ANGLE);
					   DTime = 0;
					   Current_state = No_MORE;
					  }
                 else {
    					     //Donothing
                        }
}
}
