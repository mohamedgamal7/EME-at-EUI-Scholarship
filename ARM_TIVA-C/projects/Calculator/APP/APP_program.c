/********************************************************************************************/
/* Author:      Mohamed Gamal ROushdy                                                       */
/* Version:     v01                                                                         */
/* Date:        22/08/2023                                                                  */
/* Description: APP driver program file                                                     */
/********************************************************************************************/
/* LIB utilities */
#include "./LIB/BIT_MATH.h"
#include "./LIB/STD_TYPES.h"

/* MCAL drivers */
#include "./MCAL/SYSTCK/SYSTCK_interface.h"
#include "./MCAL/GPIO/GPIO_interface.h"
#include "./MCAL/EXTI/EXTI_interface.h"

/* HAL drivers */
#include "./HAL/LCD/LCD_interface.h"
#include "./HAL/KEYPAD/KEYPAD_interface.h"
#include "./HAL/KEYPAD/KEYPAD_config.h"

#include "./APP/APP_interface.h"
#include "./APP/APP_private.h"
#include "./APP/APP_config.h"



/*************************************Driving Function*********************************************/
void APP(void)
{
    /* Local Variable definitions */
    u8 Local_Key = NO_KEY;
    u8 Local_LastPressIdx = 0u;          /* Index for storing key presses in ParsedInputString */
    u8 Local_isComplete = 0u;            /* Flag indicating if the current input is complete */

    /* Initializations */
    KEYPAD_Init(); /* Initialize keypad with the chosen configs */
    LCD_Init(); /* Initialize LCD with the chosen configs */
    EXTI_Init(PORTE_ID, KEYPAD_COL_BITS, KEYPAD_COL_BITS); /* Initialize interrupt for keypad col port */

    while(1)
    {
        if(INT_FLAG_PORTE)
        {
            _delay_ms(50U);
            Local_Key = KEYPAD_GetKeyPressed();
            INT_FLAG_PORTE = 0u ;

            /* Reset the LCD on '*' key press */
            if (Local_Key == 74u) /* ascii of 'J' */
            {
                /* Clear the LCD display and reset variables */
                LCD_SendCommand(FORCE_FIRSTL); /* Set DDRAM address to 0 (start of 1st line) */
                LCD_SendCommand(LCD_CLEAR); /* Clear the display */
                ResetVariables(); /* Call the function to reset variables */
                Local_LastPressIdx = 0u; /* Reset the Local_LastPressIdx */
                Local_isComplete = 0u; /* Reset the Local_isComplete flag */
            }
            /* Start processing input key */
            else if ((Local_Key != NO_KEY) && (!(Local_isComplete)))
            {
                LCD_DisplayCharacter(Local_Key); /* Display the pressed key on the LCD */
                ParsedInputString[Local_LastPressIdx] = (s8)Local_Key; /* Store the key in ParsedInputString */
                Local_LastPressIdx++;
                /*'=' has ascii of 61 */
                if ((Local_Key == 61u) || (Local_LastPressIdx > 15u))
                {
                    /* Calculate and display result when '=' is pressed or input is full */
                    Local_LastPressIdx = 0u; /* Reset Local_LastPressIdx */
                    ParseInputString(); /* Call the function to parse the input string */
                    f64 Local_res = CalculateResultWithPriority(); /* Calculate the result of the expression */
                    s8 outputResult[16] = {0}; /* Initialize an array to store the result string */
                    Ftoa(&Local_res, outputResult, 5); /* Convert the result to a string */
                    TrimFloat(outputResult); /* Remove unnecessary zeros from the result string */

                    LCD_SendCommand(FORCE_SECONDL); /* Set DDRAM address to 40 (start of 2nd line) */
                    LCD_DisplayString((const u8*)outputResult); /* Display the result on the LCD */

                    Local_LastPressIdx = 0u; /* Reset Local_LastPressIdx */
                    Local_isComplete = 1u; /* Set Local_isComplete flag to indicate completion */
                }
                else
                {
                    /* do nothing for misra */
                }
            }

            else
            {
                /* do nothing for misra */
            }

            Local_Key = 0u; /* Clear the Local_Key variable */
        }
    }
}

/****************************************** Helper functions **************************************/

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


static void ParseInputString(void)
{
    s8 left = 0;               /* Index for the left boundary of the current substring */
    s8 right = 0;              /* Index for the right boundary of the current substring */
    u8 opCounter = 0u; /* Counter for the number of parsed operands */
    u8 numCounter = 0u;/* Counter for the number of parsed numbers */

    while (right < 17)  /* Process up to the 17th element of ParsedInputString */
    {
        /* ASCII of '0' is 48 and ASCII of '9' is 57 */
        if ((ParsedInputString[right] >= 48) && (ParsedInputString[right] <= 57) && (right < 17))
        {
            right++;  /* Move the right boundary to the right while parsing digits */
        }
        else
        {
            u64 val = 0u;

            /* Convert the substring from left to right to an integer value */
            while (left < right)
            {
                val = (val * (u64)(10)) + ((u64)ParsedInputString[left] - (u64)48);  /* Convert ASCII to numerical value */
                left++;  /* Move the left boundary to the right */
            }

            /* Store the parsed number */
            ParsedNumbers[numCounter] = (s64)val;
            numCounter++;
            /* ascii value of equal */
            if (ParsedInputString[right] == 61)
            {
                break;  /* Exit the loop if '=' is encountered */
            }

            /* Store the parsed operand and move boundaries to the right */
            ParsedOperands[opCounter] = ParsedInputString[right];
            opCounter++;
            right++;
            left++;
        }
    }
}

static f64 CalculateResultWithPriority(void)
{
    u8 k = 0u;
    f64 orderedNumbers[8];
    s8 orderedOperators[8];

    /* Initialize arrays to store ordered numbers and operators */
    for (k = 0u; k < 8u; ++k)
    {
        orderedNumbers[k] = -1.0;         /* Initialize orderedNumbers with -1 */
        orderedOperators[k] = -1;       /* Initialize orderedOperators with -1 */
    }

    u8 c = 0u;
    u8 i = 0u;

    /* First pass: Order and process numbers and operators */
    for (i = 0; (i < 8) && (ParsedNumbers[i] != -1); ++i)
    {
        if (ParsedNumbers[i] != -2)  /* If parsedNumber is not a placeholder */
        {
            switch (ParsedOperands[i])
            {
                case 43:
                case 45:
                    orderedNumbers[c] = ParsedNumbers[i];     /* Store the number */
                    orderedOperators[c] = ParsedOperands[i];  /* Store the operator */
                    c++;  /* Move to the next index in ordered arrays */
                    break;

                case 42:
                    orderedNumbers[c] = ParsedNumbers[i] * ParsedNumbers[i+1];  /* Perform multiplication */
                    ParsedNumbers[i+1] = -2;  /* Mark the second operand as used */
                    break;
                case 47:
                    orderedNumbers[c] = (f64)ParsedNumbers[i] / ParsedNumbers[i+1];  /* Perform division */
                    ParsedNumbers[i+1] = -2;  /* Mark the second operand as used */
                    break;
                default:
                    orderedNumbers[c] = ParsedNumbers[i];  /* Store the number */
                    break;
            }
        }
        else /* parsedNumber is -2 (placeholder for the second operand of * and /) */
        {
            switch (ParsedOperands[i])
            {
                case 43: /*ascii of +*/
                case 45: /*ascii of -*/
                    orderedOperators[c] = ParsedOperands[i];  /* Store the operator */
                    c++;  /* Move to the next index in orderedOperators array */
                    break;

                case 42: /*ascii of * */
                    orderedNumbers[c] = orderedNumbers[c] * ParsedNumbers[i+1];  /* Perform multiplication */
                    ParsedNumbers[i+1] = -2;  /* Mark the second operand as used */
                    break;
                case 47: /*ascii of / */
                    orderedNumbers[c] = orderedNumbers[c] / (f64)ParsedNumbers[i+1];  /* Perform division */
                    ParsedNumbers[i+1] = -2;  /* Mark the second operand as used */
                    break;
                default:
                    break;
            }
        }
    }

    /* Second pass: Perform addition and subtraction based on ordered numbers and operators */
    f64 result = orderedNumbers[0];
    u8 j = 1u;
    for (j = 1u; (orderedNumbers[j] + 1 > 1) && (j < 8); ++j)
    {
        switch (orderedOperators[j-1])
        {
            case 43: /*ascii of +*/
                result += orderedNumbers[j];
                break;
            case 45: /*ascii of -*/
                result -= orderedNumbers[j];
                break;
            case 42: /*ascii of * */
                result *= orderedNumbers[j];
                break;
            case 47: /*ascii of / */
                result /= orderedNumbers[j];
                break;
            default:
                break;
        }
    }
    return result;  /* Return the final calculated result */
}

static void ResetVariables(void)
{
    s32 i = 0;

    /* Reset the ParsedInputString to -1 for the first 16 elements and set the last element to '=' */
    for (i = 0; i < 16; ++i)
    {
        ParsedInputString[i] = -1;
    }
    ParsedInputString[16] = '=';

    /* Reset ParsedNumbers array to -1 for the first 8 elements */
    for (i = 0; i < 8; ++i)
    {
        ParsedNumbers[i] = -1;
    }

    /* Reset ParsedOperands array to -1 for the first 8 elements */
    for (i = 0; i < 8; ++i)
    {
        ParsedOperands[i] = -1;
    }
}

static void TrimFloat(s8* str)
{
    s8 trim = 0;  /* Flag to indicate whether trimming should be performed */
    u32 i = 0u;

    /* Search for the decimal point in the string */
    for (i = 0u; i < 16u; ++i)
    {
        if (str[i] == 46)
        {
            trim = 1;  /* If decimal point is found, set the trim flag and exit the loop */
            break;
        }
    }

    i = 15u;  /* Start from the last character of the string 0 or .  */
    while (trim && ((str[i] == 48) || (str[i] == 46)))
    {
        if (str[i] == 46)
        {
            str[i] = 0;  /* Convert the decimal point to null terminator to remove it */
            break;  /* Exit the loop after removing the decimal point */
        }
        str[i] = 0;  /* Convert trailing zeros to null terminators */
        i--;  /* Move to the previous character */
    }
}

/* Reverses a string 'str' of length 'len' */
static void Reverse(s8* str, s32 len)
{
    s32 start = 0;
    s32 end = (s32)(len - (s32)1);
    s8 temp;

    /* Iterate through the string from both ends towards the center */
    while (start < end)
    {
        temp = str[start];     /* Store the character at the current 'i' position */
        str[start] = str[end];   /* Replace character at 'i' with character at 'j' */
        str[start] = temp;     /* Replace character at 'j' with the stored character */
        start++;               /* Move 'i' towards the center of the string */
        end--;               /* Move 'j' towards the center of the string */
    }
}


/* Converts a given integer x to string str[].
   d is the number of digits required in the output.
   If d is more than the number of digits in x,
   then 0s are added at the beginning. */
static s32 IntToStr(s64 x, s8 str[], s32 d)
{
    s32 count = 0;

    /* Convert each digit of the integer to its ASCII character representation */
    while (x)
    {
        str[count] = ((s8)x % 10) + 48;  /* Convert the least significant digit to ASCII character */
        count++;
        x = x / 10;  /* Move to the next digit */
    }

    /* If the number of digits required is more, add leading zeros */
    while (count < d)
    {
        str[count] = 48;  /* Fill remaining characters with '0' to achieve desired width */
        count++;
    }
    Reverse(str,count);  /* Reverse the string to correct the digit order */
    str[count] = 0x00;    /* Null-terminate the string to mark its end */
    return count;         /* Return the length of the string */
}

/* Converts a floating-point/double number to a string. */
static void Ftoa(f64* n, s8* res, s32 afterpoint)
{
    /* Handle the sign of the number */
    f64 number;
    u8 isPositive = 1u;

    if ((*n) < 0.0)
    {
        res[0] = 45;  /* Set the first character of the result string as '-' */
        res++;        /* Move the res pointer to the next character */
        number = (*n) * -1.0;  /* Convert the number to its positive counterpart */
        isPositive = 0u;  /* Indicate that the number is negative */
    }
    else
    {
        number = (*n);
    }

    /* Extract integer part */
    s64 ipart = (s64)number;

    /* Extract fractional part */
    f64 fpart = number - (f64)ipart;

    /* Convert integer part to string */
    s32 i = IntToStr(ipart, res, 0);

    /* If there is no integer part, print '0' */
    if (i == 0)
    {
        res[i] = 48;  /* Set the first character of the integer part as '0' */
        i++;
    }

    /* Calculate the number of digits after the decimal point */
    afterpoint = 16 - (i + !isPositive + 1);

    /* Check for the display option after the decimal point */
    if (afterpoint != 0)
    {
        res[i] = 46;  /* Add the decimal point '.' to the result string */

        /* Calculate the value of the fractional part up to the specified number of decimal places */
        s64 pow_ = 1;  /* Initialize a power value to multiply the fractional part */
        s32 pow_count = 0;

        for (pow_count = 0; pow_count< afterpoint; ++pow_count)
        {
            pow_ *= 10;  /* Calculate 10 raised to the power of the desired decimal places */
        }
        fpart = fpart *(f64) pow_;  /* Multiply the fractional part by the power value */

        /* Convert the fractional part to a string and place it in the result string */
        IntToStr((s64)fpart, res + i + 1, afterpoint);
    }
}

