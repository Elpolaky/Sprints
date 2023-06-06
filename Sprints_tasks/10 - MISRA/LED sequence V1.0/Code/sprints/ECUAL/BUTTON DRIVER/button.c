/*
 * button.c
 *
 * Created: 4/6/2023 5:10:53 AM
 *  Author: moham
 */ 
#include "button.h"

enu_Dio_ErrorStatus BUTTON_init(enu_PORT_NUM portnum ,enu_PIN_NUM pinnum){
	enu_Dio_ErrorStatus loc_errorStatus = DIO_init(portnum,pinnum,INPUT);
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

enu_Dio_ErrorStatus BUTTON_read(enu_PORT_NUM portnum ,enu_PIN_NUM pinnum, uint8_t *value){
	
	enu_Dio_ErrorStatus loc_errorStatus = DIO_read(portnum,pinnum,value);
	 if (loc_errorStatus == Dio_PortError){
	
		return Dio_PortError;
	
	}else if (loc_errorStatus == Dio_PinError){
	
		return Dio_PinError;
	
	}else if (loc_errorStatus == Dio_NullPointer){
	
		return Dio_NullPointer;
	
	}
	else{
		return Dio_Ok;
	}
}


void BUTTON_unitTesting(void){
	uint8_t value ;
	
	BUTTON_init(PORT_C,PIN_0);
	BUTTON_init(PORT_C,PIN_1);
	BUTTON_init(PORT_C,PIN_2);
	BUTTON_init(PORT_C,PIN_3);
	BUTTON_init(PORT_C,PIN_4);
	BUTTON_init(PORT_C,PIN_5);
	BUTTON_init(PORT_C,PIN_6);
	BUTTON_init(PORT_C,PIN_7);
	
	BUTTON_read(PORT_C,PIN_0,&value);
	BUTTON_read(PORT_C,PIN_1,&value);
	BUTTON_read(PORT_C,PIN_2,&value);
	BUTTON_read(PORT_C,PIN_3,&value);
	BUTTON_read(PORT_C,PIN_4,&value);
	BUTTON_read(PORT_C,PIN_5,&value);
	BUTTON_read(PORT_C,PIN_6,&value);
	BUTTON_read(PORT_C,PIN_7,&value);

	

	
}
