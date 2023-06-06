/*
 * utiles.h
 *
 * Created: 4/6/2023 12:59:48 AM
 *  Author: moham
 */ 


#ifndef UTILES_H_
#define UTILES_H_

#define SET_BIT(REG,BIT)	(REG |=(1<<BIT))
#define CLR_BIT(REG,BIT)	(REG &= ~(1<<BIT))
#define GET_BIT(REG,BIT)    ((REG>>BIT) & 1)
#define TGL_BIT(REG,BIT)    (REG ^= (1<<BIT)) 



#endif /* UTILES_H_ */