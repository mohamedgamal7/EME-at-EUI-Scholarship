/********************************************************************************************/
/* Authors: Mohamed Gamal, Ehab Roushdy, Mohamed abelmoteleb and Aya Yasser                 */
/* Version: V01                                                                             */
/* Date: 10/09/2023                                                                         */
/* Description: LDR Driver Program                                                          */
/********************************************************************************************/
#include "HAL/LDR/LDR.h"


void LDR_Init(void){
    /*clock gate the adc*/
    ADCStartUse(ADC0);
    /*use sequencer 3 and channel 0*/
    ADCInitSampler(ADC0, SAMPLER3, WHEN_REQUIRED, AIN0);
    /*use sequencer 3 and channel 1*/
    ADCStartUse(ADC1);
    ADCInitSampler(ADC1, SAMPLER3, WHEN_REQUIRED, AIN1);
}

dirType LDR_Comp(int32 * difference)
{
    /*Locals for ldr reading*/
    uint32_t read1 = 0;
    uint32_t read2 = 0;

    dirType retVal;

    /*read the values of both the ldrs*/
    read1 = ADCRead(ADC0, SAMPLER3);
    read2 = ADCRead(ADC1, SAMPLER3);

    /*if difference is less than a thresold stay*/
    if((read1 - read2) < MIN_DIFFERENCE)
    {
        retVal = STAY;
        /*implemented to return absolute difference*/
        *difference = read1 -read2 ;
    }

    else if((read2 - read1) < MIN_DIFFERENCE)
    {
         retVal = STAY;
         /*implemented to return absolute difference*/
         *difference = read2 -read1 ;
    }
    /*Right LDR reading is higher than a thresold over the LEFT LDR*/
    else if(read2 > read1 + MIN_DIFFERENCE)
    {
        retVal = RIGHT;
        *difference = read2 -read1 ;
    }
    /*Left LDR reading is higher than a thresold over the RIGHT LDR*/
    else{
        retVal = LEFT;
        *difference = read1 -read2 ;
    }
    return retVal;
}
