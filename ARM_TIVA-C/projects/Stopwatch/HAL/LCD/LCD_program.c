/********************************************************************************************/
/*Author: Mohamed Gamal Rousdhy                                                             */
/*Version: V01                                                                              */
/*Date: 20/08/2023                                                                          */
/*Description: LCD driver configuration file                                               */
/********************************************************************************************/
#include "./LIB/BIT_MATH.h"
#include "./LIB/STD_TYPES.h"

/* needed includes */
#include "./MCAL/GPIO/GPIO_interface.h"


/* driver's includes */
#include "./HAL/LCD/LCD_interface.h"
#include "./HAL/LCD/LCD_private.h"
#include "./HAL/LCD/LCD_config.h"

static void _delay_ms(u32 msecs)
{
    u32 i,j;
    for(i=0u;i<msecs;i++)
    {
        for(j=0u;j<3180u;j++)
        {
            __asm(" NOP ");
        }
    }
}

void LCD_Init(void)
{


#if (LCD_MODE == FOUR_BITS_MODE)
{
    /* Initialize LCD Pins as output */
    GPIO_Init_Port(LCD_DATAPORT, NO_PINS, LCD_LOW_BITS);
    GPIO_Init_Port(LCD_CTRLPORT, NO_PINS, RS|EN);
   /* delay 30 ms after power on */
    _delay_ms(30u);
    LCD_SendCommand(INIT_4_BITS_MODE);
    LCD_SendCommand(TWOLINES_5X7_4BIT_MODE);
    LCD_SendCommand(DIS_ON_CURSOR_BLINK);
    LCD_SendCommand(INC_CURSOR);
    LCD_SendCommand(LCD_CLEAR);
    LCD_SendCommand(FORCE_FIRSTL);
}
#elif(LCD_MODE == EIGHT_BITS_MODE)
{
        /* Initialize LCD pins as output */
        GPIO_Init_Port(LCD_DATAPORT, NO_PINS, ALL_PINS);
        GPIO_Init_Port(LCD_CTRLPORT, NO_PINS, RS|EN);
        /* delay 30 ms after power on */
        _delay_ms(30u);
        LCD_SendCommand(TWOLINES_5X7_8BIT_MODE);
        LCD_SendCommand(DIS_ON_CURSOR_BLINK);
        LCD_SendCommand(INC_CURSOR);
        LCD_SendCommand(TWOLINES_5X7_8BIT_MODE);
        LCD_SendCommand(LCD_CLEAR);
        LCD_SendCommand(FORCE_FIRSTL);
}
#endif

}

void LCD_SendCommand(u8 Cpy_Command)
{

#if (LCD_MODE == FOUR_BITS_MODE)
{
    /* send command RS = 0 */
    GPIO_Write(LCD_CTRLPORT, RS, LOW);
    /* put high nibble of command on port */
    GPIO_Write(LCD_DATAPORT,LCD_LOW_BITS, (Cpy_Command>>4));
    /* enable high */
    GPIO_Write(LCD_CTRLPORT, EN, HIGH);
    /* delay */
    _delay_ms(2u);
    /* enable low */
    GPIO_Write(LCD_CTRLPORT, EN, LOW);
    /* delay */
    _delay_ms(2u);
    /* put low nibble of command on port */
    GPIO_Write(LCD_DATAPORT,LCD_LOW_BITS, (Cpy_Command&0X0FU));
    /* enable high */
    GPIO_Write(LCD_CTRLPORT, EN, HIGH);
    /* delay */
    _delay_ms(2u);
    /* enable low */
    GPIO_Write(LCD_CTRLPORT, EN, LOW);
    /* delay */
    _delay_ms(2u);

}
#elif (LCD_MODE == EIGHT_BITS_MODE)
{
    /* send command RS = 0 */
       GPIO_Write(LCD_CTRLPORT, RS, LOW);
       /* put command on port first */
       GPIO_Write(LCD_DATAPORT,ALL_PINS,Cpy_Command);
       /* enable high */
       GPIO_Write(LCD_CTRLPORT, EN, HIGH);
       /* delay */
       _delay_ms(2u);
       /* enable low */
       GPIO_Write(LCD_CTRLPORT, EN, LOW);
       /* delay */
       _delay_ms(3u);
}
#endif


}

void LCD_DisplayCharacter(u8 Cpy_CharToSend)
{

#if (LCD_MODE == FOUR_BITS_MODE)
{
        /* send data RS = 1 */
        GPIO_Write(LCD_CTRLPORT, RS, HIGH);
        /* put high nibble of data on port */
        GPIO_Write(LCD_DATAPORT,LCD_LOW_BITS, (Cpy_CharToSend>>4));
        /* enable high */
        GPIO_Write(LCD_CTRLPORT, EN, HIGH);
        /* delay */
        _delay_ms(2u);
        /* enable low */
        GPIO_Write(LCD_CTRLPORT, EN, LOW);
        /* delay */
        _delay_ms(2u);
        /* put low nibble of data on port */
        GPIO_Write(LCD_DATAPORT,LCD_LOW_BITS, (Cpy_CharToSend&0X0FU));
        /* enable high*/
        GPIO_Write(LCD_CTRLPORT, EN, HIGH);
        /* delay */
        _delay_ms(2u);
        /* enable low */
        GPIO_Write(LCD_CTRLPORT, EN, LOW);
        /* delay */
        _delay_ms(2u);


}
#elif (LCD_MODE == EIGHT_BITS_MODE)
{
         /* send data RS = 1 */
          GPIO_Write(LCD_CTRLPORT, RS, HIGH);
          /* put data on port first */
          GPIO_Write(LCD_DATAPORT,ALL_PINS,Cpy_CharToSend);
          /* enable high  */
          GPIO_Write(LCD_CTRLPORT, EN, HIGH);
          /* delay */
          _delay_ms(2);
          /* enable low */
          GPIO_Write(LCD_CTRLPORT, EN, LOW);
          /* delay */
          _delay_ms(3);
}
#endif

}

void LCD_DisplayString(const u8 * str)
{
    u8 LCD_COUNT;
    for(LCD_COUNT=0u;str[LCD_COUNT]!=0u;LCD_COUNT++)
    {
        LCD_DisplayCharacter(str[LCD_COUNT]);
    }
}
