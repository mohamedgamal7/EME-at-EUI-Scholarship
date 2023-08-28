#include <stdio.h>
#include "ArmExamples.h"

#define INSERT_BIT(REG, BIT, VALUE) (REG = (REG & ~(1 << BIT)) | (VALUE << BIT))
#define base_address (((volatile uint32_t *)0xE000E100))

typedef unsigned char uint8_t;
typedef unsigned int uint32_t;

void enableInterrupt(uint8_t interruptNumber)
{
    // volatile uint32_t *ptr = base_address;
    //  if (interruptNumber < 32)
    //  {
    //      *ptr |= (1 << interruptNumber);
    //  }
    //  else if (interruptNumber < 64)
    //  {
    //      ptr++;
    //      *ptr |= (1 << interruptNumber);
    //  }
    //  else if (interruptNumber < 96)
    //  {
    //      ptr++;
    //      *ptr |= (1 << interruptNumber);
    //  }
    //  else
    //  {
    //      ptr++;
    //      *ptr |= (1 << interruptNumber);
    //  }

    int regIDx = interruptNumber / 32;
    int bitIDX = interruptNumber % 32;
    *(base_address + regIDx) |= (1 << interruptNumber);
}
void setInterruptPriority(uint8_t interruptNumber, uint8_t priority)
{
    uint8_t regnum = interruptNumber / 4;
    volatile uint32_t *priorityReg = &(NVIC_PRI0) + regnum;
    uint8_t shift = interruptNumber / 4;
    *priorityReg = (priority << shift);
}
int main()
{
}