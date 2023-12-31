/********************************************************************************************/
/* Authors: Mohamed Gamal, Ehab Roushdy, Mohamed abelmoteleb, and Aya Yasser                */
/* Version: V01                                                                             */
/* Date: 10/09/2023                                                                         */
/* Description: DIO Config  file                                                            */
/********************************************************************************************/

#include "LIB/types.h"

char Ports_Operating[Port_Num]= {1,1,1,1,1,1}; /*working ports = 1 , non-working ports = 0*/
PinConfig * PortStruct_ptr[Port_Num]; /*Array of Pointer to struct */

void PORT_CONFIG(void)
{
    /*PORT A*/
    PinConfig StructPtr_PORT_A= {
                                 .Pins.Pins_Data=0,
                                 .Pins.Pins_Data = 0x60,                   /***********USED PINS***************/
                                 .Pin_DirectionHigh.Pins_Data=0,
                                 .Pin_DirectionHigh.Pins_Data = 0x60,      /**************OUTPUT PINS**************/
                                 .Interrupts_Enable=LOW,
    };
    Read_Write ReadWritePORT_A={
                                .WritePIN.Pins_Data=0,
    };
    PortStruct_ptr[PORTA]= &StructPtr_PORT_A;

    /*PORT B*/
    PinConfig StructPtr_PORT_B= {
                                 .Pins.Pins_Data=0,
                                 .Pins.Pins_Data = 0xD3,                   /***********USED PINS***************/
                                 .Pin_DirectionHigh.Pins_Data=0,
                                 .Pin_DirectionHigh.Pins_Data = 0xD3,      /**************OUTPUT PINS**************/
                                 .Interrupts_Enable=LOW,
    };
    Read_Write ReadWritePORT_B={
                                .WritePIN.Pins_Data=0,
    };
    PortStruct_ptr[PORTB]= &StructPtr_PORT_B;

    /*PORT C*/
    PinConfig StructPtr_PORT_C= {
                                 .Pins.Pins_Data=0,
                                 .Pins.Pins_Data = 0xF0,                   /***********USED PINS***************/
                                 .Pin_DirectionHigh.Pins_Data=0,
                                 .Pin_DirectionHigh.Pins_Data = 0xC0,      /**************OUTPUT PINS**************/
                                 .PullUp_Down=NOT_WORKING,     /*PULL-UP*/
                                 .Interrupts_Enable=LOW,
                                 .Pull_Up.Pins_Data=0,
                                 .Pull_Up.Pins_Data = 0x10,                  /*************PULL_UP PINS****************/

    };
    Read_Write ReadWritePORT_C={
                                .WritePIN.Pins_Data=0,
    };
    PortStruct_ptr[PORTC]= &StructPtr_PORT_C;

    /*PORT D*/
    PinConfig StructPtr_PORT_D= {
                                 .Pins.Pins_Data=0,
                                 .Pins.Pins_Data = 0xC4,                   /***********USED PINS***************/
                                 .Pin_DirectionHigh.Pins_Data=0,
                                 .Pin_DirectionHigh.Pins_Data = 0xC4,      /**************OUTPUT PINS**************/
                                 .PullUp_Down=NOT_WORKING,
                                 .Interrupts_Enable=LOW,            /*********Interrupt on PIN0 & PIN4**************/
    };
    Read_Write ReadWritePORT_D={
                                .WritePIN.Pins_Data=0,
    };
    PortStruct_ptr[PORTD]= &StructPtr_PORT_D;

    /*PORT E*/
    PinConfig StructPtr_PORT_E= {
                                 .Pins.Pins_Data=0,
                                 .Pins.Pins_Data = 0x3C,                   /***********USED PINS***************/
                                 .Pin_DirectionHigh.Pins_Data=0,
                                 .Pin_DirectionHigh.Pins_Data = 0x30,      /**************OUTPUT PINS**************/
                                 .PullUp_Down=NOT_WORKING,
                                 .Interrupts_Enable=LOW,
    };
    Read_Write ReadWritePORT_E={
                                .WritePIN.Pins_Data=0,
    };
    PortStruct_ptr[PORTE]= &StructPtr_PORT_E;

    /*PORT F*/
    PinConfig StructPtr_PORT_F= {
                                 .Pins.Pins_Data=0,
                                 .Pins.Pins_Data = 0x11,                   /***********USED PINS - SWITCH 2***************/
                                 .Pin_DirectionHigh.Pins_Data=0,/**************INPUT PINS**************/
//                                 .Pin_DirectionHigh.Pins_Data = 0x01,      /**************OUTPUT PINS**************/
                                 .PullUp_Down=HIGH,          /*PULL-UP*/
                                 .Interrupts_Enable=LOW,
                                 .Pull_Up.Pins_Data=0,
                                 .Pull_Up.Pins_Data = 0x11,                  /*************PULL_UP PINS****************/
                                 .Level_Detection.Pins_Data=0,
                                 .Level_Detection.Pins_Data=0x00,
                                 .Both_Edges.Pins_Data=0,
                                 .RisingFalling_Edge.Pins_Data=0,          /*****************ALL FALLING EDGE****************/
                                 .Interrupt_Mask.Pins_Data=0x00    /*********Interrupt on PIN0-Interrupt on PIN4**************/
    };
    Read_Write ReadWritePORT_F={
                                .WritePIN.Pins_Data=0,
    };
    PortStruct_ptr[PORTF]= &StructPtr_PORT_F;

}

