#include "main.h"
#include "display.h"
#include "VC.h"
#include "SSD.h"
#include "OS.h"

#define DISP_PERIOD_MS   (20)



void DISP_Init(void)
{

        SSD_Init(SSD_SPEED_LOW);
        SSD_Init(SSD_SPEED_MID);
        SSD_Init(SSD_SPEED_HIGH);
        //SSD_Out(SSD_SPEED_LOW, SSD_1);
            //SSD_Out(SSD_SPEED_MID,SSD_2);
          //  SSD_Out(SSD_SPEED_HIGH, SSD_0);

        SSD_SetValue(SSD_SPEED_LOW, SSD_0);
        SSD_SetValue(SSD_SPEED_MID,SSD_0);//To change this to whatever value.
        SSD_SetValue(SSD_SPEED_HIGH, SSD_0);

}


void DISP_Update(void)
{
    static tWord DISP_counter = 0;




    /* Check if it is time for the DISP_Update to run */
    DISP_counter += TMR_TICK_MS;

    if (DISP_counter != DISP_PERIOD_MS)
    {
        return;
    }
    DISP_counter = 0;




    switch (VC_getSpeed())
    {

        case LOW:

            SSD_SetValue(SSD_SPEED_LOW, SSD_1);
            SSD_SetValue(SSD_SPEED_MID, SSD_0);
            SSD_SetValue(SSD_SPEED_HIGH, SSD_0);
            break;
        case MID:

            SSD_SetValue(SSD_SPEED_LOW, SSD_1);
            SSD_SetValue(SSD_SPEED_MID, SSD_2);
            SSD_SetValue(SSD_SPEED_HIGH, SSD_0);
            break;
        case HIGH:
            SSD_SetValue(SSD_SPEED_LOW, SSD_1);
            SSD_SetValue(SSD_SPEED_MID, SSD_2);
            SSD_SetValue(SSD_SPEED_HIGH, SSD_3);
            break;
        /* Should not be here */
        default:
            break;
    }

}
