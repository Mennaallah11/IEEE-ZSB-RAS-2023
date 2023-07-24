#ifndef MATH_H
#define MATH_H

#define SET_BIT(REG,BITNO)  (REG |= (1<<BITNO))
#define GET_BIT(REG,BITNO)  (REG & (1<<BITNO))
#define CLR_BIT(REG,BITNO)  (REG &= (~(1<<BITNO)))
#define TOG_BIT(REG,BITNO)  (REG ^= (1<<BITNO))

#endif
