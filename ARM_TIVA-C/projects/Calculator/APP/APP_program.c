/*Author:      Mohamed Gamal ROushdy                                                                      
  Version:     v01                                                                       
  Date:        22/08/2023                                                                             
  Description: APP driver program file    
*/
//LIB utilities
#include "./LIB/BIT_MATH.h"
#include "./LIB/STD_TYPES.h"

// MCAL drivers
#include "./MCAL/SYSTCK/SYSTCK_interface.h"
#include "./MCAL/GPIO/GPIO_interface.h"
#include "./MCAL/EXTI/EXTI_interface.h"

// HAL drivers
#include "./HAL/LCD/LCD_interface.h"
#include "./HAL/KEYPAD/KEYPAD_interface.h"
#include "./HAL/KEYPAD/KEYPAD_config.h"

#include "./APP/APP_interface.h"
#include "./APP/APP_private.h"
#include "./APP/APP_config.h"



/*************************************Driving Function*********************************************/
void APP(void)
{

    // Local Varaibles definitions
    u8 Local_Key = NO_KEY;
    u8 Local_LastPressIdx = 0;          // Index for storing key presses in ParsedInputString
    u8 Local_isComplete = 0;            // Flag indicating if the current input is complete

    // initializations
    KEYPAD_Init(); // initialize keypad with the chosen configs
    LCD_Init(); // initialize LCD with the chosen configs
    EXTI_Init(PORTE_ID, KEYPAD_COL_BITS,KEYPAD_COL_BITS); // Initialize interuppt for keypad col port


    while(1)
    {
           if(INT_FLAG_PORTE)
           {
               _delay_ms(50);
               Local_Key = KEYPAD_GetKeyPressed();
               INT_FLAG_PORTE = 0 ;

              // Reset the LCD on '*' key press
              if (Local_Key == 'J')
              {
                  // Clear the LCD display and reset variables
                  LCD_SendCommand(FORCE_FIRSTL);  // Set DDRAM address to 0 (start of 1st line)
                  LCD_SendCommand(LCD_CLEAR);     // Clear the display
                  ResetVariables();               // Call the function to reset variables
                  Local_LastPressIdx = 0;         // Reset the Local_LastPressIdx
                  Local_isComplete = 0;           // Reset the Local_isComplete flag
              }
              // Start processing input key
              else if (Local_Key!=NO_KEY && !(Local_isComplete))
              {
                  LCD_DisplayCharacter(Local_Key);  // Display the pressed key on the LCD
                  ParsedInputString[Local_LastPressIdx++] = Local_Key;  // Store the key in ParsedInputString

                  if (Local_Key == '=' || Local_LastPressIdx > 15)
                  {
                      // Calculate and display result when '=' is pressed or input is full
                      Local_LastPressIdx = 0;  // Reset Local_LastPressIdx
                      ParseInputString();   // Call the function to parse the input string
                      f64 res = CalculateResultWithPriority();  // Calculate the result of the expression

                      s8 outputResult[16] = {0};  // Initialize an array to store the result string
                      Ftoa(&res, outputResult, 5);  // Convert the result to a string
                      TrimFloat(outputResult);  // Remove unnecessary zeros from the result string

                      LCD_SendCommand(0xC0);  // Set DDRAM address to 40 (start of 2nd line)
                      LCD_DisplayString((u8*)outputResult);  // Display the result on the LCD

                      Local_LastPressIdx = 0;   // Reset Local_LastPressIdx
                      Local_isComplete = 1;        // Set Local_isComplete flag to indicate completion
                  }
              }

              Local_Key = 0;  // Clear the Local_Key variable



           }
     }


}

/****************************************** Helper functions **************************************/

// Todo: Replace with systick delay
static void _delay_ms(u32 msecs)
{
    u32 i,j;
    for(i=0;i<msecs;i++)
        for(j=0;j<3180;j++)
        {};
}



void ParseInputString()
{
    char left = 0;               // Index for the left boundary of the current substring
    char right = 0;              // Index for the right boundary of the current substring
    unsigned char opCounter = 0; // Counter for the number of parsed operands
    unsigned char numCounter = 0;// Counter for the number of parsed numbers

    while (right < 17)  // Process up to the 17th element of ParsedInputString
    {
        if (ParsedInputString[right] >= '0' && ParsedInputString[right] <= '9' && right < 17)
        {
            right++;  // Move the right boundary to the right while parsing digits
        }
        else
        {
            u64 val = 0;

            // Convert the substring from left to right to an integer value
            while (left < right)
            {
                val = val * 10 + (ParsedInputString[left] - '0');  // Convert ASCII to numerical value
                left++;  // Move the left boundary to the right
            }

            // Store the parsed number
            ParsedNumbers[numCounter++] = val;

            if (ParsedInputString[right] == '=')
            {
                break;  // Exit the loop if '=' is encountered
            }

            // Store the parsed operand and move boundaries to the right
            ParsedOperands[opCounter++] = ParsedInputString[right];
            right++;
            left++;
        }
    }
}

f64 CalculateResultWithPriority()
{
    unsigned char i = 0;
    double orderedNumbers[8];
    signed char orderedOperators[8];

    // Initialize arrays to store ordered numbers and operators
    for(i = 0; i < 8; ++i)
    {
        orderedNumbers[i] = -1;         // Initialize orderedNumbers with -1
        orderedOperators[i] = -1;       // Initialize orderedOperators with -1
    }

    unsigned char c = 0;
    i = 0;

    // First pass: Order and process numbers and operators
    for (i = 0; (i < 8) && (ParsedNumbers[i] != -1); ++i)
    {
        if(ParsedNumbers[i] != -2)  // If parsedNumber is not a placeholder
        {
            switch (ParsedOperands[i])
            {
                case '+':
                case '-':
                    orderedNumbers[c] = ParsedNumbers[i];     // Store the number
                    orderedOperators[c] = ParsedOperands[i];  // Store the operator
                    c++;  // Move to the next index in ordered arrays
                    break;

                case '*':
                    orderedNumbers[c] = ParsedNumbers[i] * ParsedNumbers[i+1];  // Perform multiplication
                    ParsedNumbers[i+1] = -2;  // Mark the second operand as used
                    break;
                case '/':
                    orderedNumbers[c] = (double)ParsedNumbers[i] / ParsedNumbers[i+1];  // Perform division
                    ParsedNumbers[i+1] = -2;  // Mark the second operand as used
                    break;
                default:
                    orderedNumbers[c] = ParsedNumbers[i];  // Store the number
                    break;
            }
        }
        else // parsedNumber is -2 (placeholder for the second operand of * and /)
        {
            switch (ParsedOperands[i])
            {
                case '+':
                case '-':
                    orderedOperators[c] = ParsedOperands[i];  // Store the operator
                    c++;  // Move to the next index in orderedOperators array
                    break;

                case '*':
                    orderedNumbers[c] = orderedNumbers[c] * ParsedNumbers[i+1];  // Perform multiplication
                    ParsedNumbers[i+1] = -2;  // Mark the second operand as used
                    break;
                case '/':
                    orderedNumbers[c] = orderedNumbers[c] / ParsedNumbers[i+1];  // Perform division
                    ParsedNumbers[i+1] = -2;  // Mark the second operand as used
                    break;
                default:
                    break;
            }
        }
    }

    // Second pass: Perform addition and subtraction based on ordered numbers and operators
    double result = orderedNumbers[0];
    i = 1;
    for (i = 1; (orderedNumbers[i] != -1) && (i < 8); ++i)
    {
        switch (orderedOperators[i-1])
        {
            case '+':
                result += orderedNumbers[i];
                break;
            case '-':
                result -= orderedNumbers[i];
                break;
            case '*':
                result *= orderedNumbers[i];
                break;
            case '/':
                result /= orderedNumbers[i];
                break;
            default:
                break;
        }
    }
    return result;  // Return the final calculated result
}

void ResetVariables()
{
    int i = 0;

    // Reset the ParsedInputString to -1 for the first 16 elements and set the last element to '='
    for (i = 0; i < 16; ++i)
        ParsedInputString[i] = -1;
    ParsedInputString[16] = '=';

    // Reset ParsedNumbers array to -1 for the first 8 elements
    for (i = 0; i < 8; ++i)
        ParsedNumbers[i] = -1;

    // Reset ParsedOperands array to -1 for the first 8 elements
    for (i = 0; i < 8; ++i)
        ParsedOperands[i] = -1;
}

void TrimFloat(s8* str)
{
    char trim = 0;  // Flag to indicate whether trimming should be performed
    int i = 0;

    // Search for the decimal point in the string
    for (i = 0; i < 16; ++i)
    {
        if (str[i] == '.')
        {
            trim = 1;  // If decimal point is found, set the trim flag and exit the loop
            break;
        }
    }

    i = 15;  // Start from the last character of the string
    while (trim && (str[i] == '0' || str[i] == '.'))
    {
        if (str[i] == '.')
        {
            str[i] = 0;  // Convert the decimal point to null terminator to remove it
            break;  // Exit the loop after removing the decimal point
        }
        str[i] = 0;  // Convert trailing zeros to null terminators
        i--;  // Move to the previous character
    }
}

//////////////////////////////////////////////////////////////////////////////////////////////

// Reverses a string 'str' of length 'len'
void Reverse(s8* str, u32 len)
{
    int i = 0, j = len - 1, temp;

    // Iterate through the string from both ends towards the center
    while (i < j)
    {
        temp = str[i];     // Store the character at the current 'i' position
        str[i] = str[j];   // Replace character at 'i' with character at 'j'
        str[j] = temp;     // Replace character at 'j' with the stored character
        i++;               // Move 'i' towards the center of the string
        j--;               // Move 'j' towards the center of the string
    }
}

// Converts a given integer x to string str[].
// d is the number of digits required in the output.
// If d is more than the number of digits in x,
// then 0s are added at the beginning.
s32 IntToStr(s64 x, s8 str[], s32 d)
{
    int i = 0;

    // Convert each digit of the integer to its ASCII character representation
    while (x)
    {
        str[i++] = (x % 10) + '0';  // Convert the least significant digit to ASCII character
        x = x / 10;  // Move to the next digit
    }

    // If the number of digits required is more, add leading zeros
    while (i < d)
        str[i++] = '0';  // Fill remaining characters with '0' to achieve desired width

    Reverse(str, i);  // Reverse the string to correct the digit order
    str[i] = '\0';    // Null-terminate the string to mark its end
    return i;         // Return the length of the string
}

// Converts a floating-point/double number to a string.
void Ftoa(double* n, s8* res, s32 afterpoint)
{
    // Handle the sign of the number
    double number;
    unsigned char isPositive = 1;

    if ((*n) < 0)
    {
        res[0] = '-';  // Set the first character of the result string as '-'
        res++;        // Move the res pointer to the next character
        number = (*n) * -1;  // Convert the number to its positive counterpart
        isPositive = 0;  // Indicate that the number is negative
    }
    else
    {
        number = (*n);
    }

    // Extract integer part
    long long ipart = (long long)number;

    // Extract fractional part
    double fpart = number - (double)ipart;

    // Convert integer part to string
    int i = IntToStr(ipart, res, 0);

    // If there is no integer part, print '0'
    if (i == 0)
    {
        res[i++] = '0';  // Set the first character of the integer part as '0'
    }

    // Calculate the number of digits after the decimal point
    afterpoint = 16 - (i + !isPositive + 1);

    // Check for the display option after the decimal point
    if (afterpoint != 0)
    {
        res[i] = '.';  // Add the decimal point to the result string

        // Calculate the value of the fractional part up to the specified number of decimal places
        long long pow = 1;  // Initialize a power value to multiply the fractional part
        unsigned char x = 0;

        for (x = 0; x < afterpoint; ++x)
            pow *= 10;  // Calculate 10 raised to the power of the desired decimal places

        fpart = fpart * pow;  // Multiply the fractional part by the power value

        // Convert the fractional part to a string and place it in the result string
        IntToStr((long long)fpart, res + i + 1, afterpoint);
    }
}



