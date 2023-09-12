/********************************************************************************************/
/*Authors: Mohamed Gamal, Ehab Roushdy, Mohamed abelmoteleb and Aya Yasser                  */
/*Version: V01                                                                              */
/*Date: 10/09/2023                                                                          */
/*Description: Schedular Driver tyoes                                                       */
/********************************************************************************************/

#ifndef  SHEDULER_TYPES_H__
#define  SHEDULER_TYPES_H__

#include <stdint.h>

/*Task control block struct*/
typedef struct{
    void(*taskPtr)();
    uint32_t period;
    uint32_t delay;

}TCB_Type;


#endif
