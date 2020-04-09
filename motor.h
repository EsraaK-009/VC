#ifndef MOTOR_H_INCLUDED
#define MOTOR_H_INCLUDED


typedef enum
{
    TRIAC_OFF = 0,
    TRIAC_ON = 1
}TRIAC_State;
typedef enum
{
    Harmonic=0,
    Soft_Switching_up,
    Soft_Switching_Down
}ModeChoose;

//here we init the pin
//And in init we fire for time on current angle.
void Motor_Init(void);

void Update_Angle(void);
void Fire(void);

tWord Time_For_timer(void);
void Set_Target_Angle(tWord Angle);
#endif // MOTOR_H_INCLUDED
