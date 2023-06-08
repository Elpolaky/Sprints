/*
 * timer.c
 *
 * Created: 4/10/2023 8:56:06 AM
 *  Author: moham
 */ 
#include "timer.h"
#include <math.h>

double ovfNum  ;
double t ;
	
enu_Timer_ErrorStatus TIMER_0_init(enu_Timer_Mode mode)
{
	enu_Timer_ErrorStatus errorStatus ;
	 errorStatus = TIMER_OK;
	switch(mode){
		
		case NORMAL_MODE :
		CLR_BIT(TCCR0,WGM00);
		CLR_BIT(TCCR0,WGM01);
		break;
		
		case PWM_PHASE_CORRECT :
		SET_BIT(TCCR0,WGM00);
		CLR_BIT(TCCR0,WGM01);
		break;
		
		case CTC :
		CLR_BIT(TCCR0,WGM00);
		SET_BIT(TCCR0,WGM01);
		break;
		
		
		case FAST_PWM :
		SET_BIT(TCCR0,WGM00);
		SET_BIT(TCCR0,WGM01);
		break;
		
		default:
		errorStatus = INVALID_MODE ;
		break;
	}
	
	
	return errorStatus;
	
}

enu_Timer_ErrorStatus TIMER_0_start(enu_Timer_Prescaler prescaler)
{
	enu_Timer_ErrorStatus errorStatus ;
	errorStatus = TIMER_OK;
	
	switch(prescaler){
		
		case PRECALER_1 :
		SET_BIT(TCCR0,CS00);
		CLR_BIT(TCCR0,CS01);
		CLR_BIT(TCCR0,CS02);
		break;
		
		case PRECALER_8 :
		SET_BIT(TCCR0,CS01);
		CLR_BIT(TCCR0,CS00);
		CLR_BIT(TCCR0,CS02);
		break;
		
		case PRECALER_64 :
		SET_BIT(TCCR0,CS00);
		SET_BIT(TCCR0,CS01);
		CLR_BIT(TCCR0,CS02);
		break;
		
		case PRECALER_256 :
		SET_BIT(TCCR0,CS02);
		CLR_BIT(TCCR0,CS01);
		CLR_BIT(TCCR0,CS00);
		break;
		
		case PRECALER_1024 :
		SET_BIT(TCCR0,CS00);
		CLR_BIT(TCCR0,CS01);
		SET_BIT(TCCR0,CS02);
		break;
		
		default:
		errorStatus= INVALID_PRESCALER;
		break;
	}	
	
	return errorStatus ;
}

void TIMER_0_stop(void){
	
	CLR_BIT(TCCR0,CS00);
	CLR_BIT(TCCR0,CS01);
	CLR_BIT(TCCR0,CS02);
	
}


enu_Timer_ErrorStatus TIMER_0_setIntialValue(uint8_t value){
	enu_Timer_ErrorStatus errorStatus ;
	errorStatus = TIMER_OK;

	if(value < TIMR0_MAX_VALUE && value >= 0){
		
		TCNT0 = value ;
	}else{
		errorStatus = INVALID_VALUE;
	}
	return errorStatus ;
}


enu_Timer_ErrorStatus TIMER_0_OvfNum(double overflow){
	enu_Timer_ErrorStatus errorStatus ;
	errorStatus = TIMER_OK;
	
	double num_ovf = 0;
	if (overflow > 0)
	{
		
		while(num_ovf < overflow){
			
			while(GET_BIT(TIFR,TOV0)==0);
			SET_BIT(TIFR,TOV0);
			num_ovf++;
		}
		num_ovf = 0;
	}
	
	else if (overflow <= 0)
	{
		overflow = 1 ;
		while(num_ovf < overflow){
			
			while(GET_BIT(TIFR,TOV0)==0);
			SET_BIT(TIFR,TOV0);
			num_ovf++;
		}
		num_ovf = 0;
	}
		
	else
	{
		errorStatus = INVALID_OVF;
	}
	
	return errorStatus;
}

void TIMER_0_DELAY_MS(double time_ms){
	 t = time_ms/1000 ;
	ovfNum = ceil (t / 0.000256) ;
	TIMER_0_init(NORMAL_MODE);
	TIMER_0_setIntialValue(0);
	TIMER_0_start(PRECALER_1);
	TIMER_0_OvfNum(ovfNum);
	
}
