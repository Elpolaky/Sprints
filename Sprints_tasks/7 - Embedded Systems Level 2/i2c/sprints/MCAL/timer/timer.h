/*
 * timer.h
 *
 * Created: 4/10/2023 8:55:51 AM
 *  Author: moham
 */ 


#ifndef TIMER_H_
#define TIMER_H_


/*************************************************/
//					INCLUDES
/**************************************************/
#include "../../Utilities/registers.h"
#include "../../Utilities/bit_manipulation.h"
#include "../../Utilities/types.h"


/*************************************************/
//					MACROS
/**************************************************/

#define CS00				0
#define CS01				1
#define CS02				2
#define WGM01				3
#define WGM00				6

#define TOV0				0

#define TIMR0_MAX_VALUE		256


typedef enum {
	INVALID_PRESCALER,
	INVALID_MODE,
	INVALID_OVF,
	INVALID_VALUE,
	TIMER_OK
	}Timer_ErrorStatus;

typedef enum {
	NORMAL_MODE,
	FAST_PWM,
	CTC,
	PWM_PHASE_CORRECT
	
	}Timer_Mode;
	
typedef enum{
	PRECALER_1,
	PRECALER_8,
	PRECALER_64,
	PRECALER_256,
	PRECALER_1024,
	}Timer_Prescaler;


/*************************************************/
//			 FUNCTIONS PROTOTYPES
/**************************************************/
Timer_ErrorStatus TIMER_0_init(Timer_Mode mode);
Timer_ErrorStatus TIMER_0_start(Timer_Prescaler prescaler);
void TIMER_0_stop(void);
Timer_ErrorStatus TIMER_0_setIntialValue(uint8_t value);
Timer_ErrorStatus TIMER_0_OvfNum(double overflow);
void TIMER_0_DELAY_MS(double _delay);


#endif /* TIMER_H_ */