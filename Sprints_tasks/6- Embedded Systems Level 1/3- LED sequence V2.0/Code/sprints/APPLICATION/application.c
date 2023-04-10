/*
 * LED_SequenceV1.c
 *
 * Created: 4/7/2023 6:19:18 PM
 *  Author: moham
 */ 

#include "applicarion.h"

uint8_t flag = 0,error_value=0 ,error_value2=0 ;

void SetFlag(){
	
	if(flag <7){
		
		flag++;
		
	}else{
		
		flag = 0;
	}
	
	
}

void app_init(void){
	
	 BUTTON_init(BUTTON_INT0_PORT,BUTTON_INT0_PIN);
	 LED_init(PORT_B,PIN_0);
	 LED_init(PORT_B,PIN_1);
	 LED_init(PORT_B,PIN_2);
	 LED_init(PORT_B,PIN_3);
	 
	 // INTERRUPT
	 SEI;
	error_value= ExtInt_init(); 
	 error_value2=INT0_SetCallback(SetFlag);

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
		LED_off(PORT_B,PIN_1);
		LED_off(PORT_B,PIN_2);
		LED_off(PORT_B,PIN_3);
		
		
	}else if (flag == 2){
		LED_on(PORT_B,PIN_0);
		LED_on(PORT_B,PIN_1);
		LED_off(PORT_B,PIN_2);
		LED_off(PORT_B,PIN_3);
		
		
	}else if (flag == 3){
		LED_on(PORT_B,PIN_0);
		LED_on(PORT_B,PIN_1);
		LED_on(PORT_B,PIN_2);
		LED_off(PORT_B,PIN_3);
		
		
	}else if (flag == 4){
		LED_on(PORT_B,PIN_0);
		LED_on(PORT_B,PIN_1);
		LED_on(PORT_B,PIN_2);
		LED_on(PORT_B,PIN_3);
		
	}else if (flag == 5){
		LED_off(PORT_B,PIN_0);
		LED_on(PORT_B,PIN_1);
		LED_on(PORT_B,PIN_2);
		LED_on(PORT_B,PIN_3);
		
		
	}else if (flag == 6){
		LED_off(PORT_B,PIN_0);
		LED_off(PORT_B,PIN_1);
		LED_on(PORT_B,PIN_2);
		LED_on(PORT_B,PIN_3);
		
	}
	else if (flag == 7){
		LED_off(PORT_B,PIN_0);
		LED_off(PORT_B,PIN_1);
		LED_off(PORT_B,PIN_2);
		LED_on(PORT_B,PIN_3);
		
	}
}

	
