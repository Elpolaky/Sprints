/*
 * sprints.c
 *
 * Created: 4/5/2023 8:47:06 PM
 * Author : moham
 */ 



 #include "APPLICATION/LED_Sequence.h"
 #include "MCAL/DIO DRIVER/dio.h"
 #include "ECUAL/LED DRIVER/led.h"
 #include "ECUAL/BUTTON DRIVER/button.h"
 
int main(void)
{
	//DIO_uintTesting();
	//LED_uintTesting();
	//BUTTON_unitTesting();
	Led_sequenceV1();
}

