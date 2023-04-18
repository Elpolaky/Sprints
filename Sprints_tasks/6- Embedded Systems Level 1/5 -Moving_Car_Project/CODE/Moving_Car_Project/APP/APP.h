
#ifndef app_H_
#define app_H_

#include "../HAL/MOTOR/MOTOR.h"

#include "../HAL/BUTTON/BUTTON.h"
#include "../HAL/LED/LED.h"
#include "../MCAL/TIMERS/timer.h"


void move_withSpeedAndDelay(uint8_t speed , uint8_t delay);

#endif