#include "main.h"
#include "SW.h"
#include "OS.h"
#include "display.h"
//#include "motor.h"
#include "SSD.h"
#include "VC.h"

tWord __at(0x2007) CONFIG = _HS_OSC & _WDT_OFF & _PWRTE_ON & _BODEN_OFF & _LVP_OFF & _CPD_OFF & _WRT_OFF & _DEBUG_OFF & _CP_OFF;
tByte flag = 0;


void main (void)
{
    /* Initialization */
    SW_Init();
    DISP_Init();
    VC_init();

    TMR_Init();
    TMR_Start();



    while (1)
    {
        /* Do nothing */
      //TMR_Start();

    }

}

