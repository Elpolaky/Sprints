/*
 * dio.c
 *
 * Created: 4/5/2023 11:36:49 PM
 *  Author: moham
 */ 

#include "dio.h"

Dio_ErrorStatus DIO_init(PORT_NUM PortNum, PIN_NUM PinNum , PIN_DIR direction){
	Dio_ErrorStatus loc_ErrorStatus = Dio_Ok;
	
	if(PinNum<PIN_0 || PinNum>PIN_7){
		loc_ErrorStatus = Dio_PinError ;
	}
	else{	
		switch (PortNum)
		{

			case PORT_A :
					if (direction == INPUT)
					{
						CLR_BIT(DDRA,PinNum);
					}else if ( direction == OUTPUT){
						SET_BIT(DDRA,PinNum);
					}else{
						// error handling
						loc_ErrorStatus = Dio_DirectionError;
					}
					break;
		
		
			case PORT_B :
					if (direction == INPUT)
					{
						CLR_BIT(DDRB,PinNum);
					}else if ( direction == OUTPUT){
						SET_BIT(DDRB,PinNum);
					}else{
						// error handling
						loc_ErrorStatus = Dio_DirectionError;

					}
					break;
		
		
		
			case PORT_C :
					if (direction == INPUT)
					{
						CLR_BIT(DDRC,PinNum);
					}else if ( direction == OUTPUT){
						SET_BIT(DDRC,PinNum);
					}else{
						// error handling
						loc_ErrorStatus = Dio_DirectionError;
					}
					break;
		
		
		
			case PORT_D :
					if (direction == INPUT)
					{
						CLR_BIT(DDRD,PinNum);
					}else if ( direction == OUTPUT){
						SET_BIT(DDRD,PinNum);
					}else{
						// error handling
						loc_ErrorStatus = Dio_DirectionError;
					}
					break;
		
			default:
			//error handling
					loc_ErrorStatus = Dio_PortError;
					break;
		
		}
					}
	
	return loc_ErrorStatus ;

}


Dio_ErrorStatus DIO_write(PORT_NUM PortNum, PIN_NUM PinNum , VALUE value){
	Dio_ErrorStatus loc_errorStatus = Dio_Ok ;
	
	if(PinNum<PIN_0 || PinNum>PIN_7){
		loc_errorStatus = Dio_PinError ;
	}
	else{
		switch (PortNum)
		{
			case PORT_A :
			
					if (value == LOW)
					{
						CLR_BIT(PORTA,PinNum);
			
					}else if ( value == HIGH){
			
						SET_BIT(PORTA,PinNum);
					}else{
						// error handling
						loc_errorStatus = Dio_ValueError ;
					}
					break;
		
			case PORT_B :
					if (value == LOW)
					{
						CLR_BIT(PORTB,PinNum);
			
					}else if ( value == HIGH){
			
						SET_BIT(PORTB,PinNum);
					}else{
						// error handling
						loc_errorStatus = Dio_ValueError ;
					}
					break;
		
			case PORT_C :
					if (value == LOW)
					{
						CLR_BIT(PORTC,PinNum);
			
					}else if ( value == HIGH){
			
						SET_BIT(PORTC,PinNum);
					}else{
						// error handling
						loc_errorStatus = Dio_ValueError ;
					}
					break;
		
			case PORT_D :
					if (value == LOW)
					{
						CLR_BIT(PORTD,PinNum);
			
					}else if ( value == HIGH){
			
						SET_BIT(PORTD,PinNum);
			
					}else{
						// error handling
						loc_errorStatus = Dio_ValueError ;
					}
					break;
		
		
			default:
			//error handling
				loc_errorStatus = Dio_PortError ;
				break;
		
				}
		}
	return loc_errorStatus;
	}



Dio_ErrorStatus DIO_read(PORT_NUM PortNum, PIN_NUM PinNum , uint8_t* value){
	Dio_ErrorStatus loc_errorStatus = Dio_Ok ;
	
	if(PinNum<PIN_0 || PinNum>PIN_7){
		loc_errorStatus = Dio_PinError ;
	}
	else{
	
		if(value == 0){
			loc_errorStatus = Dio_NullPointer;
		}
		else{
			switch (PortNum)
			{
				case PORT_A :
						*value = GET_BIT(PINA,PinNum);
						break;
		
				case PORT_B :
						*value = GET_BIT(PINB,PinNum);
						break;
				
				case PORT_C :
						*value = GET_BIT(PINC,PinNum);
						break;
		
				case PORT_D :
						*value = GET_BIT(PIND,PinNum);
						break;
		
				default:
				//error handling
						loc_errorStatus = Dio_PortError;
						break;
	
			}
	}
	}
	return loc_errorStatus;
}


Dio_ErrorStatus DIO_toggle(PORT_NUM PortNum, PIN_NUM PinNum ){
	Dio_ErrorStatus loc_errorStatus = Dio_Ok ;
	if(PinNum<PIN_0 || PinNum>PIN_7){
		loc_errorStatus = Dio_PinError ;
	}
	else{	
		switch (PortNum)
		{
			case PORT_A :
				 TGL_BIT(PORTA,PinNum);
				break;
			
			case PORT_B :
				 TGL_BIT(PORTB,PinNum);
				break;
			
			case PORT_C :
				 TGL_BIT(PORTC,PinNum);
				break;
			
			case PORT_D :
				 TGL_BIT(PORTD,PinNum);
				 break;
			
			default:
			//error handling
				loc_errorStatus = Dio_PortError;
				break;
			
		}
	}
	return loc_errorStatus;
}



Dio_ErrorStatus DIO_Port_init(PORT_NUM PortNum, PIN_DIR direction){
	Dio_ErrorStatus loc_errorStatus = Dio_Ok ;
		switch (PortNum)
		{

			case PORT_A :
			if (direction == INPUT)
			{
				DDRA = 0x00;
				}
			else if ( direction == OUTPUT){
				DDRA = 0xFF;
				}else{
				
				loc_errorStatus = Dio_DirectionError;// error handling
			}
			break;
			
			
			case PORT_B :
			
			if (direction == INPUT)
			{
				DDRB = 0x00;
			}
			else if ( direction == OUTPUT){
				DDRB = 0xFF;
			}else{
				
				loc_errorStatus = Dio_DirectionError;// error handling
			}
			break;
			
			
			
			case PORT_C :
			if (direction == INPUT)
			{
				DDRC = 0x00;
			}
			else if ( direction == OUTPUT){
				DDRC = 0xFF;
				
			}else{
				
				loc_errorStatus = Dio_DirectionError;// error handling
			}
			break;
			
			
			
			
			case PORT_D :
			if (direction == INPUT)
			{
				DDRD = 0x00;
			}
			else if ( direction == OUTPUT){
				DDRD = 0xFF;
			}else{
			
				loc_errorStatus = Dio_DirectionError;// error handling
			}
			break;
		
			
			default:
			//error handling
			loc_errorStatus = Dio_PortError;
			break;
			
		}
	
	
	return loc_errorStatus ;
	
	
}
Dio_ErrorStatus DIO_Port_write(PORT_NUM PortNum, VALUE value){
	Dio_ErrorStatus loc_errorStatus = Dio_Ok ;
	switch (PortNum)
	{

		case PORT_A :
		if (value == LOW)
		{
			PORTA = 0x00;
		}
		else if ( value == HIGH){
			PORTA = 0xFF;
		
		}else{
			
			loc_errorStatus = Dio_DirectionError;// error handling
		}
		break;
		
		
		case PORT_B :
		
		if (value == LOW)
		{
			PORTB = 0x00;
		}
		else if ( value == HIGH){
			PORTB = 0xFF;
		}else{
			
			loc_errorStatus = Dio_DirectionError;// error handling
		}
		break;
		
		
		
		case PORT_C :
		if (value == LOW)
		{
			PORTC = 0x00;
		}
		else if ( value == HIGH){
			
			PORTC = 0xFF;
			
		}else{
			
			loc_errorStatus = Dio_DirectionError;// error handling
		}
		break;
		
		
		
		
		case PORT_D :
		if (value == LOW)
		{
			PORTD = 0x00;
		}
		else if ( value == HIGH){
			PORTD = 0xFF;
			
		}else{
			
			loc_errorStatus = Dio_DirectionError;// error handling
		}
		break;
		
		
		default:
		//error handling
		loc_errorStatus = Dio_PortError;
		break;
		
	}
	
	
	return loc_errorStatus ;
}


void DIO_uintTesting (void){
	uint8_t value ;
	
	DIO_init(PORT_A,PIN_0,OUTPUT);
	DIO_init(PORT_A,PIN_1,OUTPUT);
	DIO_init(PORT_A,PIN_2,OUTPUT);
	DIO_init(PORT_A,PIN_3,OUTPUT);
	DIO_init(PORT_A,PIN_4,OUTPUT);
	DIO_init(PORT_A,PIN_5,OUTPUT);
	DIO_init(PORT_A,PIN_6,OUTPUT);
	DIO_init(PORT_A,PIN_7,OUTPUT);
	

	DIO_write(PORT_A,PIN_0,HIGH);
	DIO_write(PORT_A,PIN_1,HIGH);
	DIO_write(PORT_A,PIN_2,HIGH);
	DIO_write(PORT_A,PIN_3,HIGH);
	DIO_write(PORT_A,PIN_4,HIGH);
	DIO_write(PORT_A,PIN_5,HIGH);
	DIO_write(PORT_A,PIN_6,HIGH);
	DIO_write(PORT_A,PIN_7,HIGH);
	
	DIO_read(PORT_A,PIN_0,&value);

	
	DIO_write(PORT_A,PIN_0,LOW);
	DIO_write(PORT_A,PIN_1,LOW);
	DIO_write(PORT_A,PIN_2,LOW);
	DIO_write(PORT_A,PIN_3,LOW);
	DIO_write(PORT_A,PIN_4,LOW);
	DIO_write(PORT_A,PIN_5,LOW);
	DIO_write(PORT_A,PIN_6,LOW);
	DIO_write(PORT_A,PIN_7,LOW);
	
	DIO_read(PORT_A,PIN_0,&value);

	
	//DIO_init(PORT_E,PIN_1,LOW);
	//DIO_write(PORT_A,PIN_8,LOW);
	
}