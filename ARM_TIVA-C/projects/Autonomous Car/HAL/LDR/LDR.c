#include "HAL/LDR/LDR.h"



void LDR_Init(void){
    ADCStartUse(ADC0);
    ADCInitSampler(ADC0, SAMPLER3, ALWAYS, AIN0);

    ADCStartUse(ADC1);
    ADCInitSampler(ADC1, SAMPLER3, ALWAYS, AIN1);


    //    SYSCTL_RCGCGPIO_R |= (1<<4);
    //    GPIO_PORTE_AMSEL_R |= (1<<3) | (1<<2);
}

dirType LDR_Comp(void){
    uint32_t read1 = 0;
    uint32_t read2 = 0;

    dirType retVal;

    read1 = ADCRead(ADC0, SAMPLER3);
    read2 = ADCRead(ADC1, SAMPLER3);

    if((read1 - read2) < 200 || (read2 - read1) < 200){
        retVal = STAY;
    }else if(read1 < read2){
        retVal = RIGHT;
    }else{
        retVal = LEFT;
    }
    return retVal;
}
