/********************************************************************************************/
/* Authors: Mohamed Gamal, Ehab Roushdy, Mohamed abelmoteleb and Aya Yasser                 */
/* Version: V01                                                                             */
/* Date: 10/09/2023                                                                         */
/* Description: CAR application Driver Program                                              */
/********************************************************************************************/
#include"APP.h"

/*Globals*/

/*Extern Global variables*/
extern uint32_t ticksCount;

/*Initial car state*/
car_state currunt_state = free_running;
dirType LDR_reading;
int32  Reading_differece = 0 ;


void ldr_swing_car(void)
{
    /*Check whether the car is in a free running state without facing any obstacles*/
    if(currunt_state == free_running)
    {
        /*Read LDR values and chose a direction for the car */
        LDR_reading =  LDR_Comp(&Reading_differece);
        switch (LDR_reading)
        {
            case RIGHT:
            {    /*Turn the car right*/
                MotorTurnRight(ENGINE_POWER_LEFT);
                break;
            }
            case LEFT:
            {   /*Turn the car right*/
                MotorTurnLeft(ENGINE_POWER_RIGHT);
                break;
            }
            default:
            {    /*Move forward by default*/
                MotorForward(ENGINE_POWER_FORWARD);
                break;
            }
        }
    }
}

void lcd_display(void)
{    /*Display other remaing data different from the constant string*/
    LcdGoTo(ROW1, COL6);
    LCDSendInt(TempRead());
    LcdGoTo(ROW1, COL13);
    LcdSendString("    ");
    LcdGoTo(ROW1, COL13);
    LCDSendInt(Reading_differece);
    LcdGoTo(ROW2,COL5);
    if (currunt_state == blocked_reverse || currunt_state == blocked_turning)
    { /*The car is blocked by an obstacle*/
       LcdSendString("block");
    }
    else
    {
       switch (LDR_reading)
       {
           case RIGHT:
           { /*The car is turning right */
               LcdSendString("right");
               break;
           }
           case LEFT:
           { /*The car is turning left */
               LcdSendString("left ");
               break;
           }
           default:
           { /*The car is moving forward */
               LcdSendString("front");
               break;
           }
       }
    }
 /*Display time of being ON of the CAR on the LCD screen*/
    LcdGoTo(ROW2, COL15);
    LcdSendString("  ");
    LcdGoTo(ROW2, COL15);
    LCDSendInt(ticksCount * SYSTIC_INT_PERIOD_MS / (1000));
}

void avoid_obstacles(void)
{
    /*This counter value is found by trial an error to enter this task this number of times to achieve rotation 90 degrees without delays*/
    static uint8 turnning_counter = 14;
    switch (currunt_state)
    {
        /*The car is facing an obstacle*/
        case blocked_reverse:
        {
            /*Distance is initially -1 which indicates that a meaurement has been missed */
            float distance = -1;
            distance = Measure_Distance();

            /*The car moves backwards until the distance is 20 cm from the object*/
            if(distance > BACK_DISTANCE)
            {
                /*the car changes the state to turning 90 degrees*/
                currunt_state = blocked_turning;
                MotorTurnRight(ENGINE_POWER_RIGHT);
            }
            break;
        }
        case blocked_turning:
        {
            if (turnning_counter > 0)
            {
                --turnning_counter;
            }
            else
            {
                /*When the time of turning 90 degrees pass the car moves normally forward again*/
                turnning_counter = 14;
                currunt_state = free_running;
                MotorForward(ENGINE_POWER_FORWARD);
            }
            break;
        }
        default: /* free_running */
        {
            /*Distance is initially -1 which indicates that a meaurement has been missed */
            float distance = -1;
            distance = Measure_Distance();

            if(distance<BACK_DISTANCE && distance>WRONG_MEASUREMENT)
            {
                currunt_state = blocked_reverse;
                MotorBackward(ENGINE_POWER_FORWARD);
            }
            else
            {
                /*stay in the current state*/
                currunt_state = free_running;
            }
            break;
        }
    }
}

void lcd_display_const_string(void)
{
    /*Instead of redisplaying this string on lcd task every time display it once and change the different values only*/
    LcdSendString("TEMP:    LDR:   ");
    LcdSendString("TEMP:00 LDR:0000");
    LcdGoTo(ROW2, COL1);
    LcdSendString("DIR:      SEC:00");
}
