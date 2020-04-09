#include "main.h"
#include "port.h"
#include "OS.h"
#include "VC.h"
#include "motor.h"

#define FIRING_PULSE_WIDTH (100)
#define MOTOR_PERIOD_MS   (10)
#define ANGLE_UPDATE_TIME  (40)
#define ONE_DEGREE_TIME  (55)
#define STARTING_ANGLE   (170)


typedef enum
{
    PLUS_FIVE=0,
    MIUNS_FIVE

} Harmonic_State;

static Harmonic_State Current_Harmonic_state;
static void Set_Firing_Angle(tWord Angle);
tWord Compare;
ModeChoose Mode;
static tWord CurrentAngle;
static tWord Time_Timer;
static tWord TargetAngle;
 static tWord Firing_Angle;
//static void Fire(tWord Angle);
static void Harmonic_FN(void);

static void delay_us(void);

void Motor_Init (void)
{
      GPIO_InitPortPin(TRIAC_PORT_CR,TRIAC_PIN,GPIO_OUT);
      GPIO_WritePortPin(TRIAC_PORT_DR, TRIAC_PIN, TRIAC_OFF);

      Mode = Soft_Switching_Down;
      CurrentAngle = STARTING_ANGLE;
      Time_Timer = CurrentAngle * ONE_DEGREE_TIME;
      Set_Firing_Angle(CurrentAngle);
      Current_Harmonic_state = PLUS_FIVE;
      //Fire(STARTING_ANGLE);
}

void Update_Angle(void)

{
    static tWord Motor_counter = 0;
    Motor_counter += TMR_TICK_MS;

    //tWord Compare;
    //Compare = (CurrentAngle - TargetAngle);

    if (CurrentAngle == TargetAngle)
    {
        Mode = Harmonic;
    }
    else if (CurrentAngle < TargetAngle)
    {
        Mode = Soft_Switching_up;
    }
    else if (CurrentAngle > TargetAngle)
    {
        Mode = Soft_Switching_Down;
    }
    else
    {

    }

    switch(Mode)
    {

    case Harmonic:
        Harmonic_FN();
        break;

    case Soft_Switching_up:
         if (Motor_counter == ANGLE_UPDATE_TIME){
           CurrentAngle++;
           Set_Firing_Angle(CurrentAngle);
           Motor_counter = 0;
              }
        else
        {

        }

         break;
    case Soft_Switching_Down:
        if (Motor_counter == ANGLE_UPDATE_TIME){
        CurrentAngle--;
        Set_Firing_Angle(CurrentAngle);
        Motor_counter =0;
              }
        else{

        }
         break;
    default:
        break;

    }




}

//I have to know how much time firing take
void Fire(void)
{

    GPIO_WritePortPin(TRIAC_PORT_DR, TRIAC_PIN, TRIAC_ON);
    // delay for 100 us
    delay_us();

    GPIO_WritePortPin(TRIAC_PORT_DR, TRIAC_PIN, TRIAC_OFF);

}

static void delay_us(void)
{
    int i =0;
    for(i=0;i<FIRING_PULSE_WIDTH;i++)
    {

    }
}

tWord Time_For_timer(void)
{
    Time_Timer = Firing_Angle * ONE_DEGREE_TIME;
    return Time_Timer;
}

void Set_Target_Angle(tWord Angle)
{
    Firing_Angle = Angle;
}


static void Set_Firing_Angle(tWord Angle)
{
    TargetAngle = Angle;
}

static void Harmonic_FN(void)
{

    if(Current_Harmonic_state== PLUS_FIVE)
    {
        Set_Firing_Angle(CurrentAngle + 5);
        Current_Harmonic_state== MIUNS_FIVE;
    }
    else if(Current_Harmonic_state== MIUNS_FIVE)
    {
        Set_Firing_Angle(CurrentAngle - 5);
        Current_Harmonic_state== PLUS_FIVE;
    }
    else
    {

    }
     //Current_Harmonic_state

}
