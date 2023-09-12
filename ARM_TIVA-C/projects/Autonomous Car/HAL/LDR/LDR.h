#ifndef LDR_H__
#define LDR_H__

#include <stdint.h>

#include "MCAL/ADC/ADC.h"

typedef enum{
    STAY = 0,
    RIGHT,
    LEFT
}dirType;


void LDR_Init(void);
dirType LDR_Comp(void);

#endif
