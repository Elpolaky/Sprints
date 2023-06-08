/*
 * timer.h
 *
 * Created: 4/10/2023 8:55:51 AM
 *  Author: moham
 */ 


#ifndef TIMER_H_
#define TIMER_H_

#include "../../Utilities/registers.h"
#include "../../Utilities/bit_manipulation.h"
#include "../../Utilities/types.h"


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
	}enu_Timer_ErrorStatus;

typedef enum {
	NORMAL_MODE,
	FAST_PWM,
	CTC,
	PWM_PHASE_CORRECT
	
	}enu_Timer_Mode;
	
typedef enum{
	PRECALER_1,
	PRECALER_8,
	PRECALER_64,
	PRECALER_256,
	PRECALER_1024,
	}enu_Timer_Prescaler;

extern enu_Timer_ErrorStatus TIMER_0_init(enu_Timer_Mode mode);
extern enu_Timer_ErrorStatus TIMER_0_start(enu_Timer_Prescaler prescaler);
extern void TIMER_0_stop(void);
extern enu_Timer_ErrorStatus TIMER_0_setIntialValue(uint8_t value);
extern enu_Timer_ErrorStatus TIMER_0_OvfNum(double overflow);
extern void TIMER_0_DELAY_MS(double _delay);


#endif /* TIMER_H_ */