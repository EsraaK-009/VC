#include "main.h"
#include "port.h"
#include "LedD.h"


void LEDD_INIT(tLED_State state)
{

            GPIO_InitPortPin(LED_D_PORT_CR, LED_D_PIN, GPIO_OUT);
            GPIO_WritePortPin(LED_D_PORT_DR, LED_D_PIN, state);

           // LED_SetState(led, state);
    /* End of your code */

}


void DLED_ON(void)
{

    GPIO_WritePortPin(LED_D_PORT_DR, LED_D_PIN, LED_ON);
}
