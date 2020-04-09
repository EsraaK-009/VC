#ifndef SSD_H_INCLUDED
#define SSD_H_INCLUDED



/* Number of SSDs */
#define N_SSD           (3)


typedef enum
{
    SSD_SPEED_LOW=0,
    SSD_SPEED_MID,
    SSD_SPEED_HIGH
}tSSD;

/* SSD states */
typedef enum
{
    SSD_OFF = 0,
    SSD_ON = 1
}tSSD_State;

/* SSD symbols */
typedef enum
{
    SSD_0 = 0,
    SSD_1,
    SSD_2,
    SSD_3,

}tSSD_Symbol;
#define N_SSD_SYMBOLS   (4)


/* Current SSD to be updated */
//static tSSD SSD_current = SSD_SPEED_LOW;

/* SSD values */
//static tSSD_Symbol SSD_Values[N_SSD] = {SSD_0};



void SSD_Init(tSSD ssd);
void SSD_Update(void);
void SSD_SetValue(tSSD ssd, tSSD_Symbol ssd_symbol);
void SSD_SetState(tSSD ssd, tSSD_State state);



#endif // SSD_H_INCLUDED
