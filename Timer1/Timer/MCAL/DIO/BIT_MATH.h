#ifndef BIT_MATH_H
#define BIT_MATH_H

#define SET_BIT(VAR, BITNO)		VAR |= (1 << BITNO)
#define CLR_BIT(VAR, BITNO)		VAR &= ~(1 << BITNO)
#define GET_BIT(VAR, BITNO)		((VAR >> BITNO) & 1)
#define TOG_BIT(VAR, BITNO)		VAR ^= (1 << BITNO)

#endif