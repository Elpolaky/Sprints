/*
 * led.c
 *
 * Created: 4/6/2023 2:27:43 AM
 *  Author: moham
 */ 
#include "led.h"

Dio_ErrorStatus LED_init(PORT_NUM portNum , PIN_NUM pinNum){
	Dio_ErrorStatus loc_errorStatus = DIO_init(portNum,pinNum,OUTPUT);
	
	if ( loc_errorStatus == Dio_PortError){
		
		return Dio_PortError;
		
	}else if (loc_errorStatus == Dio_PinError){
	
		return Dio_PinError;
	
	
	}else if (loc_errorStatus == Dio_DirectionError){
		
		return Dio_DirectionError;
		
	}else{
		return Dio_Ok;
	}
}

Dio_ErrorStatus LED_on (PORT_NUM portNum , PIN_NUM pinNum){
	Dio_ErrorStatus loc_errorStatus = DIO_write(portNum,pinNum,HIGH);
	
	if ( loc_errorStatus == Dio_PortError){
		
		return Dio_PortError;
		
	}else if (loc_errorStatus == Dio_PinError){
	
	return Dio_PinError;
	
	
	}
	else if (loc_errorStatus == Dio_ValueError){
		
		return Dio_ValueError;
		
	}else{
		return Dio_Ok;
	}
}

Dio_ErrorStatus LED_off(PORT_NUM portNum , PIN_NUM pinNum){
	Dio_ErrorStatus loc_errorStatus = DIO_write(portNum,pinNum,LOW);	
	
	if ( loc_errorStatus == Dio_PortError){
		
		return Dio_PortError;
		
	}else if (loc_errorStatus == Dio_ValueError){
		
		return Dio_ValueError;
		
	}else{
		return Dio_Ok;
	}
	
}
	
Dio_ErrorStatus LED_toggle(PORT_NUM portNum , PIN_NUM pinNum){
	Dio_ErrorStatus loc_errorStatus = DIO_toggle(portNum,pinNum);
	
	if ( loc_errorStatus == Dio_PortError){
		
		return Dio_PortError;
		
	}else if (loc_errorStatus == Dio_PinError){
		
		return Dio_PinError;
		
		
	}else{
		return Dio_Ok;
	}
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