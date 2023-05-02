/*
 * Ext_IntCnfg.h
 *
 * Created: 4/9/2023 5:34:01 AM
 *  Author: moham
 */ 


#ifndef EXT_INTCNFG_H_
#define EXT_INTCNFG_H_

#include "Ext_interrupt.h"



/************* CONFIGURATIONS ***************/	

/* NOTE : INT0,INT1 ----> CAN SENSE		  ( LOW_LEVEL    , FALLING_EDGE , RAISING_EDGE , ANY_LOGIC )
		  INT2 ---------> CAN SENSE ONLY  ( FALLING_EDGE , RAISING_EDGE )
*/

#define INT0_ENABLE			ENABLE
#define INT1_ENABLE			ENABLE
#define INT2_ENABLE			DISABLE

#define INT0_SENSE_MODE 	FALLING_EDGE
#define INT1_SENSE_MODE 	FALLING_EDGE
#define INT2_SENSE_MODE 	FALLING_EDGE  




#endif /* EXT_INTCNFG_H_ */