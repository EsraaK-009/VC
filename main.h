#ifndef _MAIN_H
#define _MAIN_H

#include <pic16f877a.h>


/* GPIO definitions */
/* GPIO Pins */
#define GPIO_PIN_0              (0)
#define GPIO_PIN_1              (1)
#define GPIO_PIN_2              (2)
#define GPIO_PIN_3              (3)
#define GPIO_PIN_4              (4)
#define GPIO_PIN_5              (5)
#define GPIO_PIN_6              (6)
#define GPIO_PIN_7              (7)

/* GPIO Port Registers redefinition */
#define GPIO_PORTA_DATA         (PORTA)
#define GPIO_PORTA_CONTROL      (TRISA)

#define GPIO_PORTB_DATA         (PORTB)
#define GPIO_PORTB_CONTROL      (TRISB)

#define GPIO_PORTC_DATA         (PORTC)
#define GPIO_PORTC_CONTROL      (TRISC)

#define GPIO_PORTD_DATA         (PORTD)
#define GPIO_PORTD_CONTROL      (TRISD)

#define GPIO_PORTE_DATA         (PORTE)
#define GPIO_PORTE_CONTROL      (TRISE)

/* GPIO direction setting */
#define GPIO_OUT                (0)
#define GPIO_IN                 (1)

/* GPIO port operations */
#define GPIO_InitPort(CONTROL, DIRECTION)   ((CONTROL) = (DIRECTION)?(~GPIO_OUT):(GPIO_OUT))
#define GPIO_WritePort(PORT, DATA)          ((PORT) = (DATA))
#define GPIO_ReadPort(PORT)                 (PORT)

/* GPIO port pin operations */
#define GPIO_InitPortPin(CONTROL, PIN, DIRECTION)   ((CONTROL) = (CONTROL & (~(1 << PIN)))|(DIRECTION << PIN))
#define GPIO_WritePortPin(PORT, PIN, DATA)          ((PORT) = (PORT & (~(1 << PIN)))|(DATA << PIN))
#define GPIO_ReadPortPin(PORT, PIN)                 (((PORT) & (1 << PIN)) >> (PIN))
/* End of code filling */

/* Timer 0 macros */
/* Fill missing code below */

/* End of code filling */
#define TMR0_SET_PRESCALER_256	PS2 = 1;\
								PS1 = 1;\
								PS0 = 1;\
								PSA = 0

#define TMR0_GET_FLAG			(TMR0IF)
#define TMR0_CLEAR_FLAG			(TMR0IF = 0)

/*

   78.125 ~ 78
   Number of ticks needed to get 10ms
   Based on 8MegaHz osc.

 */
#define TEN_MILLI_TICK (78)


#define TMR0_UPDATE_REGISTER(TIME)		(TMR0 = 256 - (TIME) )

#define TMR0_ENABLE_INTERRUPT	(TMR0IE = 1)
#define GLOBAL_INTERRUPT_ENABLE0 	(GIE = 1)

#define TMR0_ENABLE_CLOCK		(T0CS = 0)
#define TMR0_DISABLE_CLOCK		(T0CS = 1)

//Timer 1
/*

 2 as prescaler, because it's gonna give us number without any float parts.
 if it's one, we will need to divide the equation by 5.
    but we can use 1 too.
    as for 4. It's going to give - not that accurate - Values.

 */
#define TMR1_PRESCALER      T1CKPS0 = 1;\
                            T1CKPS1 = 0



#define TMR1_GET_FLAG			(TMR1IF)
#define TMR1_CLEAR_FLAG			(TMR1IF = 0)

/*    */
#define TMR1_UPDATE_REGISTER(TIME)		(TMR1 = 65536 - (TIME) )

#define TMR1_START	      (TMR1ON = 1)
#define TMR1_STOP	      (TMR1ON = 0)
#define TMR1_ENABLE_INTERRUPT	(TMR1IE = 1)
//#define GLOBAL0_INTERRUPT_ENABLE	(GIE = 1)

#define TMR1_INTERNAL_CLOCK_ENABLE		(TMR1CS = 0)

#define TMR1_OSCILLATOR_OFF    (T1OSCEN = 0)

/* SET peripheral interrupt

*/
#define TMR1_PERIPHERAL_I_ENABLE    (PEIE = 1)
//#define TMR1_DISABLE_CLOCK		(TMR1CS = 1)

typedef unsigned char   tByte;
typedef unsigned int    tWord;
typedef unsigned long   tLong;

#endif // _MAIN_H
