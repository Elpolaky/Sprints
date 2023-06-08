/*
 * led.c
 *
 * Created: 4/6/2023 2:27:43 AM
 *  Author: moham
 */ 
#include "led.h"

enu_Dio_ErrorStatus LED_init(enu_PORT_NUM portNum , enu_PIN_NUM pinNum){
	enu_Dio_ErrorStatus loc_errorStatus = DIO_init(portNum,pinNum,OUTPUT);
	
		return loc_errorStatus ;
}

enu_Dio_ErrorStatus LED_on (enu_PORT_NUM portNum , enu_PIN_NUM pinNum){
	enu_Dio_ErrorStatus loc_errorStatus = DIO_write(portNum,pinNum,HIGH);
	
		return loc_errorStatus ;
}

enu_Dio_ErrorStatus LED_off(enu_PORT_NUM portNum , enu_PIN_NUM pinNum){
	enu_Dio_ErrorStatus loc_errorStatus = DIO_write(portNum,pinNum,LOW);	
	
	return loc_errorStatus ;
	
}
	
enu_Dio_ErrorStatus LED_toggle(enu_PORT_NUM portNum , enu_PIN_NUM pinNum){
	enu_Dio_ErrorStatus loc_errorStatus = DIO_toggle(portNum,pinNum);
	
	return loc_errorStatus ;
}



void LED_uintTesting(void){
	
	LED_init(PORT_B,PIN_0);
	LED_init(PORT_B,PIN_1);
	LED_init(PORT_B,PIN_2);
	LED_init(PORT_B,PIN_3);
	LED_init(PORT_B,PIN_4);
	LED_init(PORT_B,PIN_5);
	LED_init(PORT_B,PIN_6);
	LED_init(PORT_B,PIN_7);
	
	LED_on(PORT_B,PIN_0);
	LED_on(PORT_B,PIN_1);
	LED_on(PORT_B,PIN_2);
	LED_on(PORT_B,PIN_3);
	LED_on(PORT_B,PIN_4);
	LED_on(PORT_B,PIN_5);
	LED_on(PORT_B,PIN_6);
	LED_on(PORT_B,PIN_7);
	
	LED_off(PORT_B,PIN_0);
	LED_off(PORT_B,PIN_1);
	LED_off(PORT_B,PIN_2);
	LED_off(PORT_B,PIN_3);
	LED_off(PORT_B,PIN_4);
	LED_off(PORT_B,PIN_5);
	LED_off(PORT_B,PIN_6);
	LED_off(PORT_B,PIN_7);


	
	
}