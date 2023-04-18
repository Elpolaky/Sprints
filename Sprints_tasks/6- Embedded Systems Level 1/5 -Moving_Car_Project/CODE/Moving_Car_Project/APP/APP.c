#include "APP.h"


void move_withSpeedAndDelay(uint8_t speed , uint8_t delay){
	uint8_t s = speed / 100 ;
	double duty_cycle = s * 0.256 ;
LED_ON(pinb0);
	TIMER_0_DELAY_MS(duty_cycle);
LED_OFF(pinb0);
	TIMER_0_DELAY_MS(duty_cycle);

	
}