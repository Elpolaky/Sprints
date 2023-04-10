/*
 * LED_SequenceV1.c
 *
 * Created: 4/7/2023 6:19:18 PM
 *  Author: moham
 */ 

#include "LED_Sequence.h"

uint8_t flag,value ;
void Led_sequenceV1(void){
	 
	 
	BUTTON_init(BUTTON_1_PORT,BUTTON_1_PIN);
	LED_init(PORT_B,PIN_0);
	LED_init(PORT_B,PIN_1);
	LED_init(PORT_B,PIN_2);
	LED_init(PORT_B,PIN_3);
	
	while (1)
	{
		BUTTON_read(BUTTON_1_PORT,BUTTON_1_PIN,&value);
		
		if(value == HIGH){
			flag++;
			_delay_ms(300);
			
		}
		
		if(flag == 1){
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
			
			}else if (flag == 8){
			LED_off(PORT_B,PIN_0);
			LED_off(PORT_B,PIN_1);
			LED_off(PORT_B,PIN_2);
			LED_off(PORT_B,PIN_3);
			flag =0 ;
		}
	}
	
	
}