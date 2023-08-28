#include "./LIB/BIT_MATH.h"
#include "./LIB/STD_TYPES.h"

// needed includes
#include "./MCAL/GPIO/GPIO_interface.h"


// driver's includes
#include "./HAL/KEYPAD/KEYPAD_interface.h"
#include "./HAL/KEYPAD/KEYPAD_private.h"
#include "./HAL/KEYPAD/KEYPAD_config.h"


static u8 keys_map[4][4] = { {'1','2','3','+'},
                             {'4','5','6','-'},
                             {'7','8','9','*'},
                             {'J','0','=','/'} } ;

void KEYPAD_Init()
{
    // initialize rows as output and coloumns as inputs pull up
    GPIO_Init_Port(KEYPAD_ROWSPORT, NO_PINS, KEYPAD_ROW_BITS);
    GPIO_Init_Port(KEYPAD_COLSPORT, KEYPAD_COL_BITS, NO_PINS);

    // initially make all ROW pins low so when a col is pressed an int occurs
    GPIO_Write(KEYPAD_ROWSPORT, KEYPAD_ROW_BITS, LOW);

}

u8 KEYPAD_GetKeyPressed()
{
  u8 row;
  u8 col;
  u8 key =NO_KEY ;
  for(row=ROWS_START;row<ROWS+ROWS_START;row++)
  {
      GPIO_Write(KEYPAD_ROWSPORT, KEYPAD_ROW_BITS, ~(1<<row)); //All rows high except for the current row
      for(col=COLS_START;col<COLS+COLS_START;col++)
      {
          if(GPIO_Read(KEYPAD_COLSPORT, 1<<col)==LOW) // if a zero is read from the col pins
          {
              GPIO_Write(KEYPAD_ROWSPORT, KEYPAD_ROW_BITS,LOW); // Reset the rows to low again
              key = keys_map[row-ROWS_START][col-COLS_START]; // find key in keymap
          }
      }

  }

  // reset the rows to low again when key is not found
  GPIO_Write(KEYPAD_ROWSPORT, KEYPAD_ROW_BITS,LOW);
  return key;
}

// Todo: replace with systick driver delay
static void _delay_ms(u32 msecs)
{
    u32 i,j;
    for(i=0;i<msecs;i++)
        for(j=0;j<3180;j++)
        {};

}
