#ifndef _VC_H
#define _VC_H

typedef enum
{
    LOW=0,
    MID,
    HIGH
}Speed;

typedef enum
{
    Normal =0,
    VC_PLUS,
    VC_MINUS,
    No_MORE


}VC_state;


void Check_Dled(void);
void VC_init(void);

void VC_update();
//sending target speed to motor and speed to display.


Speed VC_getSpeed();
//update on switch state and save the convert to speed. Display take this.





#endif

