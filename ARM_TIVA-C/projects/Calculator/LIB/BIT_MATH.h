/********************************************************************************************/
/*Author: Mohamed Gamal Rousdhy                                                             */
/*Version: V01																			    */
/*Date:	19/08/2023																			*/
/*Description: Bit maipulation macros 														*/
/********************************************************************************************/

#ifndef _BIT_MATH_H
#define _BIT_MATH_H

#define SET_BIT(REG, BIT)   ((REG) |= ((u32)1ul << (BIT)))
#define CLR_BIT(REG,BIT)   	((REG)&=~((u32)1ul<<(BIT)))
#define TOG_BIT(REG,BIT)   	((REG)^=((u32)1ul<<(BIT)))
#define GET_BIT(REG,BIT)   (((u32)(REG)>>(BIT))&(u32)1ul)


#endif
