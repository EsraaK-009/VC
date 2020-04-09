#ifndef LEDD_H_INCLUDED
#define LEDD_H_INCLUDED

typedef enum
{
   LED_OFF = 0,
   LED_ON  = 1
}tLED_State;


void LEDD_INIT(tLED_State state);
void DLED_ON(void);

#endif // LEDD_H_INCLUDED
