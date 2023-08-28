/********************************************************************************************/
/*Author: Mohamed Gamal Rousdhy                                                             */
/*Version: V01                                                                              */
/*Date: 19/08/2023                                                                          */
/*Description: SYSTCK driver configuration file                                               */
/********************************************************************************************/
#ifndef _SYSTCK_PRIVATE_H
#define _SYSTCK_PRIVATE_H


typedef struct
{
   volatile u32 STCTRL_R;
   volatile u32 STRELOAD_R;
   volatile u32 STCURRENT_R;

}Systick_R;


#define  SYSTICK ((volatile Systick_R*)(0xE000E010))

#endif

