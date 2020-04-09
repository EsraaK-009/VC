#ifndef __SW_H__
#define __SW_H__

typedef enum
{
    SW_PLUS=0,
    SW_MINUS,
    SW_D
}tSW;

typedef enum
{
    SW_RELEASED,
    SW_PRE_PRESSED,
    SW_PRESSED,
    SW_PRE_RELEASED
}tSW_State;



void SW_Init(void);
tSW_State SW_GetState(tSW sw);
void SW_Update(void);

//int ReturnPressedTime(void);

#endif // __SW_H__
