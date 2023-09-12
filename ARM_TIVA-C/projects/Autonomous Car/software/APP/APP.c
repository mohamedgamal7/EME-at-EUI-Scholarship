/********************************************************************************************/
/* Authors: Mohamed Gamal, Ehab Roushdy, Mohamed abelmoteleb and Aya Yasser                 */
/* Version: V01                                                                             */
/* Date: 10/09/2023                                                                         */
/* Description: CAR application Driver Program                                              */
/********************************************************************************************/

#include"APP.h"

/*Extern Global variables*/
extern uint32_t ticksCount;

/*Global variables*/
dirType LDR_reading;
int32  Reading_differece;
bool is_blocked = false;


void ldr_swing_car(void)
{
    /*Read LDR values and chose a direction for the car */
    LDR_reading =  LDR_Comp(&Reading_differece);
    switch (LDR_reading)
    {
        case RIGHT:
        {   /*Turn the car right*/
            MotorTurnRight(Speed_percent);
            break;
        }
        case LEFT:
        {    /*Turn the car left*/
            MotorTurnLeft(Speed_percent);
            break;
        }
        default:
        {    /*Move forward by default*/
            MotorForward(Speed_percent);
            break;
        }
    }
}

void lcd_display(void)
{
    /*Display other remaing data different from the constant string*/
    LcdGoTo(ROW1, COL6);
    LCDSendInt(TempRead());
    LcdGoTo(ROW1, COL14);
    LcdSendString("   ");
    LcdGoTo(ROW1, COL14);
    LCDSendInt(Reading_differece);
    LcdGoTo(ROW2,COL5);
    if (is_blocked)
    {  /*The car is blocked by an obstacle*/
       LcdSendString("block");
    }
    else
    {
       switch (LDR_reading)
       {
           case RIGHT:
           {   /*The car is turning right */
               LcdSendString("right");
               break;
           }
           case LEFT:
           {   /*The car is turning left */
               LcdSendString("left ");
               break;
           }
           default:
           {   /*The car is moving forward */
               LcdSendString("front");
               break;
           }
       }
    }

    /*Display on time of the CAR on the LCD screen*/
    LcdGoTo(ROW2, COL15);
    LcdSendString("  ");
    LcdGoTo(ROW2, COL15);
    LCDSendInt(ticksCount * SYSTIC_INT_PERIOD_MS / (1000));
}

void avoid_obstacles(void)
{
    /*Distance is initially -1 which indicates that a meaurement has been missed */
    float distance = -1;
    uint32 i;
    for (i = 0; i < 1 && distance < 0; ++i)
    {
        distance = Measure_Distance();
    }
    if(distance<MAX_DISTANCE && distance>WRONG_MEASUREMENT)
    {
        is_blocked = true;
        /*Turn away from the object in front*/
        MotorTurnRight(Speed_percent);

    }
    else
    {
        is_blocked = false;
    }
}

void lcd_display_const_string(void)
{
    /*Instead of redisplaying this string on lcd task every time display it once and change the different values only*/
    LcdSendString("TEMP:    LDR:   ");
    LcdGoTo(ROW2, COL1);
    LcdSendString("DIR:      SEC:  ");
}
