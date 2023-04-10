/*
 * LED_SequenceV1.c
 *
 * Created: 4/7/2023 6:19:18 PM
 *  Author: moham
 */ 

#include "applicarion.h"

uint8_t flag = 0,flag2=0 ,error_value=0 ,error_value2=0 ;
float delay_on=100,delay_off=900;

void SetFlag(){
	
	if(flag <7){
		
		flag++;
		
	}else{
		
		flag = 0;
	}
	
	
}

void SetDelay(){
	
	flag2++;
	switch(flag2){
	
		
	case 1 :
	delay_on=200;
	delay_off=800;
	break;
	
	case 2 :
	delay_on=300;
	delay_off=700;
	break;
	
	case 3 :
	delay_on=500;
	delay_off=500;
	break;
	
	case 4 :
	delay_on=800;
	delay_off=200;
	break;
	
	
	default:
		flag2 = 0 ;
		delay_on=100;
		delay_off=900;
		break;
	}
	
	
}
void app_init(void){
	
	 BUTTON_init(BUTTON_INT0_PORT,BUTTON_INT0_PIN);
	 BUTTON_init(BUTTON_INT1_PORT,BUTTON_INT1_PIN);

	 LED_init(PORT_B,PIN_0);
	 LED_init(PORT_B,PIN_1);
	 LED_init(PORT_B,PIN_2);
	 LED_init(PORT_B,PIN_3);
	 
	 // INTERRUPT
	 SEI;
	error_value= ExtInt_init(); 
	error_value2=INT0_SetCallback(SetFlag);
	INT1_SetCallback(SetDelay);
}


void app_start(){
	if (flag == 0){
		LED_off(PORT_B,PIN_0);
		LED_off(PORT_B,PIN_1);
		LED_off(PORT_B,PIN_2);
		LED_off(PORT_B,PIN_3);	

	}
	else if(flag == 1){
		LED_on(PORT_B,PIN_0);
		TIMER0_DELAY_ME(delay_on);
		LED_off(PORT_B,PIN_0);
		TIMER0_DELAY_ME(delay_off);
		LED_off(PORT_B,PIN_1);
		LED_off(PORT_B,PIN_2);
		LED_off(PORT_B,PIN_3);
		
		
	}else if (flag == 2){
		LED_on(PORT_B,PIN_0);
		LED_on(PORT_B,PIN_1);
		TIMER0_DELAY_ME(delay_on);
		LED_off(PORT_B,PIN_0);
		LED_off(PORT_B,PIN_1);
		TIMER0_DELAY_ME(delay_off);
		
		LED_off(PORT_B,PIN_2);
		LED_off(PORT_B,PIN_3);
		
		
	}else if (flag == 3){
		LED_on(PORT_B,PIN_0);
		LED_on(PORT_B,PIN_1);
		LED_on(PORT_B,PIN_2);
		TIMER0_DELAY_ME(delay_on);
		LED_off(PORT_B,PIN_0);
		LED_off(PORT_B,PIN_1);
		LED_off(PORT_B,PIN_2);
		TIMER0_DELAY_ME(delay_off);
		LED_off(PORT_B,PIN_3);
		
		
	}else if (flag == 4){
		LED_on(PORT_B,PIN_0);
		LED_on(PORT_B,PIN_1);
		LED_on(PORT_B,PIN_2);
		LED_on(PORT_B,PIN_3);
		TIMER0_DELAY_ME(delay_on);
		LED_off(PORT_B,PIN_0);
		LED_off(PORT_B,PIN_1);
		LED_off(PORT_B,PIN_2);
		LED_off(PORT_B,PIN_3);
		TIMER0_DELAY_ME(delay_off);
	}else if (flag == 5){
		LED_off(PORT_B,PIN_0);
		
		LED_on(PORT_B,PIN_1);
		LED_on(PORT_B,PIN_2);
		LED_on(PORT_B,PIN_3);
		TIMER0_DELAY_ME(delay_on);
		LED_off(PORT_B,PIN_1);
		LED_off(PORT_B,PIN_2);
		LED_off(PORT_B,PIN_3);
		TIMER0_DELAY_ME(delay_off);
		
	}else if (flag == 6){
		LED_off(PORT_B,PIN_0);
		LED_off(PORT_B,PIN_1);
		
		LED_on(PORT_B,PIN_2);
		LED_on(PORT_B,PIN_3);
		TIMER0_DELAY_ME(delay_on);
		LED_off(PORT_B,PIN_2);
		LED_off(PORT_B,PIN_3);
		TIMER0_DELAY_ME(delay_off);
		
	}
	else if (flag == 7){
		LED_off(PORT_B,PIN_0);
		LED_off(PORT_B,PIN_1);
		LED_off(PORT_B,PIN_2);
		LED_on(PORT_B,PIN_3);
		TIMER0_DELAY_ME(delay_on);
		LED_off(PORT_B,PIN_3);
		TIMER0_DELAY_ME(delay_off);
	}
}

	
