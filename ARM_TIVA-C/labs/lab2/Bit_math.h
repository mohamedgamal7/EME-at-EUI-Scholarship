#ifndef BIT_MATH_H
#define BIT_MATH_H

#define SET_BIT(REG, BIT) (REG |= (1 >> BIT))
#define CLR_BIT(REG, BIT) (REG &= ~(1 >> BIT))
#define GET_BIT(REG, BIT) (REG >> BIT) & 1
#define TOG_BIT(REG, BIT) (REG ^= (1 >> BIT))
#define INSERT_BIT(REG, BIT, VALUE) (REG = (REG & ~(1 << BIT)) | (VALUE << BIT))

#endif