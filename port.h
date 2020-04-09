#ifndef PORT_H_INCLUDED
#define PORT_H_INCLUDED

#include "main.h"

/*   Triac pin
 */
#define TRIAC_PORT_DR   (GPIO_PORTC_DATA)
#define TRIAC_PORT_CR   (GPIO_PORTC_CONTROL)
#define TRIAC_PIN       (GPIO_PIN_6)

#define LED_D_PORT_DR   (GPIO_PORTB_DATA)
#define LED_D_PORT_CR   (GPIO_PORTB_CONTROL)
#define LED_D_PIN       (GPIO_PIN_3)



/* Fill missing code below */
/* Switches */
#define SW_PLUS_PORT_DR     (GPIO_PORTB_DATA)
#define SW_PLUS_PORT_CR     (GPIO_PORTB_CONTROL)
#define SW_PLUS_PIN         (GPIO_PIN_0)

#define SW_MINUS_PORT_DR    (GPIO_PORTB_DATA)
#define SW_MINUS_PORT_CR    (GPIO_PORTB_CONTROL)
#define SW_MINUS_PIN        (GPIO_PIN_1)

#define SW_D_PORT_DR      (GPIO_PORTB_DATA)
#define SW_D_PORT_CR      (GPIO_PORTB_CONTROL)
#define SW_D_PIN          (GPIO_PIN_2)

/* SSD */
#define SSD_DATA_PORT_DR        (GPIO_PORTD_DATA)
#define SSD_DATA_PORT_CR        (GPIO_PORTD_CONTROL)

#define SSD_SPEED_LOW_DR       (GPIO_PORTB_DATA)
#define SSD_SPEED_LOW_CR       (GPIO_PORTB_CONTROL)
#define SSD_SPEED_LOW_PIN      (GPIO_PIN_7)

#define SSD_SPEED_MID_DR      (GPIO_PORTB_DATA)
#define SSD_SPEED_MID_CR      (GPIO_PORTB_CONTROL)
#define SSD_SPEED_MID_PIN     (GPIO_PIN_6)

#define SSD_SPEED_HIGH_DR     (GPIO_PORTB_DATA)
#define SSD_SPEED_HIGH_CR     (GPIO_PORTB_CONTROL)
#define SSD_SPEED_HIGH_PIN    (GPIO_PIN_5)




#endif // PORT_H_INCLUDED
