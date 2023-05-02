/*
 * adc.c
 *
 * Created: 4/29/2023 4:02:02 PM
 *  Author: moham
 */ 

#include "adc.h"

float step_size ;

/* DECRIBTION : -
	- CHOOSE CHANNEL
	- CHOOSE VREF
	- CHOOSE MODE
	- CHOOSE LEFT/REIGHT ADJUST
	- ENABLE ADC
	- CHOOSE PRESCALER
	- ENABLE/DISABLE INT
*/
void ADC_init(ADC_CHANNEL a_channel , ADC_MODE a_mode  , ADC_VREF a_vref , ADC_PRESCALER a_prescaler){
	
	// choosing mode and channel
	switch(a_mode){
		
		case SINGLE_INPUT :
			
			CLR_BIT(ADMUX,MUX4);
			CLR_BIT(ADMUX,MUX3);	
			switch(a_channel){
				case ADC_0 : 
				DIO_init(PORT_A,PIN_0,INPUT);
				CLR_BIT(ADMUX,MUX0);
				CLR_BIT(ADMUX,MUX1);
				CLR_BIT(ADMUX,MUX2);
					break;

				case ADC_1 :
				DIO_init(PORT_A,PIN_1,INPUT);
				SET_BIT(ADMUX,MUX0);
				CLR_BIT(ADMUX,MUX1);
				CLR_BIT(ADMUX,MUX2);
				break;

				case ADC_2 :
				DIO_init(PORT_A,PIN_2,INPUT);
				CLR_BIT(ADMUX,MUX0);
				SET_BIT(ADMUX,MUX1);
				CLR_BIT(ADMUX,MUX2);
				break;

				case ADC_3 :
				DIO_init(PORT_A,PIN_3,INPUT);
				SET_BIT(ADMUX,MUX0);
				SET_BIT(ADMUX,MUX1);
				CLR_BIT(ADMUX,MUX2);
				break;

				case ADC_4 :
				DIO_init(PORT_A,PIN_4,INPUT);
				CLR_BIT(ADMUX,MUX0);
				CLR_BIT(ADMUX,MUX1);
				SET_BIT(ADMUX,MUX2);
				break;

				case ADC_5 :
				DIO_init(PORT_A,PIN_5,INPUT);
				SET_BIT(ADMUX,MUX0);
				CLR_BIT(ADMUX,MUX1);
				SET_BIT(ADMUX,MUX2);
				break;

				case ADC_6 :
				DIO_init(PORT_A,PIN_6,INPUT);
				CLR_BIT(ADMUX,MUX0);
				SET_BIT(ADMUX,MUX1);
				SET_BIT(ADMUX,MUX2);
				break;

				case ADC_7 :
				DIO_init(PORT_A,PIN_7,INPUT);
				SET_BIT(ADMUX,MUX0);
				SET_BIT(ADMUX,MUX1);
				SET_BIT(ADMUX,MUX2);
				break;
				
				
				default:
				break;
			}
		break;
		
		
		case DIFFRENTIAL:
		break;
		
		 
		default:
		break;
	}
	
	// setting VREF
	switch(a_vref){
		
		case AVCC :
		SET_BIT(ADMUX,REFS0);
		CLR_BIT(ADMUX,REFS1);
		step_size = 5.0 / 1024.0 ;
		break;
		
		case INTERNAL_VOLT :
		SET_BIT(ADMUX,REFS0);
		SET_BIT(ADMUX,REFS1);
		step_size = 2.56 / 1024.0 ;
		break;
		 
		default:
		break;
	}
	
	
	
	//right adjustment
	CLR_BIT(ADMUX,ADLAR);
	
	// enable adc
	SET_BIT(ADCSRA,ADEN);
	
	
	//set prescaler
	switch(a_prescaler){
		
		case PRESCALER_2 :
		SET_BIT(ADCSRA,ADPS0);
		CLR_BIT(ADCSRA,ADPS1);
		CLR_BIT(ADCSRA,ADPS2);
		break;
		
		case PRESCALER_4 :
		CLR_BIT(ADCSRA,ADPS0);
		SET_BIT(ADCSRA,ADPS1);
		CLR_BIT(ADCSRA,ADPS2);
		break;
		
		case PRESCALER_8 :
		SET_BIT(ADCSRA,ADPS0);
		SET_BIT(ADCSRA,ADPS1);
		CLR_BIT(ADCSRA,ADPS2);
		break;
		
		case PRESCALER_16 :
		SET_BIT(ADCSRA,ADPS2);
		CLR_BIT(ADCSRA,ADPS1);
		CLR_BIT(ADCSRA,ADPS0);
		break;
		
		case PRESCALER_32 :
		SET_BIT(ADCSRA,ADPS0);
		CLR_BIT(ADCSRA,ADPS1);
		SET_BIT(ADCSRA,ADPS2);
		break;
		
		case PRESCALER_64 :
		SET_BIT(ADCSRA,ADPS2);
		SET_BIT(ADCSRA,ADPS1);
		CLR_BIT(ADCSRA,ADPS0);
		break;
		
		case PRESCALER_128 :
		SET_BIT(ADCSRA,ADPS0);
		SET_BIT(ADCSRA,ADPS1);
		SET_BIT(ADCSRA,ADPS2);
		break;
		
		default:
		break;
	}
	
	
	
}

/* DESCRIBTION :
	- CHOOSE CHANNEL TO READ
	- START CONVERSION
	- WAIT FOR FLAG
	- READ DIGITAL AND CONVERT TO ANALOG
*/
float ADC_read(ADC_CHANNEL a_channel){
		uint8_t a_digialValue = 0 ;
		float   a_analogValue = 0 ;
		//CHOOSE CHANNEL TO READ
		switch(a_channel){
			case ADC_0 :
			DIO_init(PORT_A,PIN_0,INPUT);
			CLR_BIT(ADMUX,MUX0);
			CLR_BIT(ADMUX,MUX1);
			CLR_BIT(ADMUX,MUX2);
			break;

			case ADC_1 :
			CLR_BIT(DDRA,2);
			SET_BIT(ADMUX,MUX0);
			CLR_BIT(ADMUX,MUX1);
			CLR_BIT(ADMUX,MUX2);
			break;

			case ADC_2 :
			DIO_init(PORT_A,PIN_2,INPUT);
			CLR_BIT(ADMUX,MUX0);
			SET_BIT(ADMUX,MUX1);
			CLR_BIT(ADMUX,MUX2);
			break;

			case ADC_3 :
			DIO_init(PORT_A,PIN_3,INPUT);
			SET_BIT(ADMUX,MUX0);
			SET_BIT(ADMUX,MUX1);
			CLR_BIT(ADMUX,MUX2);
			break;

			case ADC_4 :
			DIO_init(PORT_A,PIN_4,INPUT);
			CLR_BIT(ADMUX,MUX0);
			CLR_BIT(ADMUX,MUX1);
			SET_BIT(ADMUX,MUX2);
			break;

			case ADC_5 :
			DIO_init(PORT_A,PIN_5,INPUT);
			SET_BIT(ADMUX,MUX0);
			CLR_BIT(ADMUX,MUX1);
			SET_BIT(ADMUX,MUX2);
			break;

			case ADC_6 :
			DIO_init(PORT_A,PIN_6,INPUT);
			CLR_BIT(ADMUX,MUX0);
			SET_BIT(ADMUX,MUX1);
			SET_BIT(ADMUX,MUX2);
			break;

			case ADC_7 :
			DIO_init(PORT_A,PIN_7,INPUT);
			SET_BIT(ADMUX,MUX0);
			SET_BIT(ADMUX,MUX1);
			SET_BIT(ADMUX,MUX2);
			break;
			
			
			default:
			break;
		}
	
	SET_BIT(ADCSRA,ADSC); // start conversion
	
	while(GET_BIT(ADCSRA,ADIF) == 0){
		 //reading conversion data
		
	}
	 a_digialValue = ADCL | (ADCH << 8) ;
	SET_BIT(ADCSRA,ADIF); // clear the flag
	
	a_analogValue = a_digialValue * step_size ; // calculating the volt resulted
	
	return a_analogValue;
}

uint8_t LM35_calibration(ADC_CHANNEL a_channel){
	
	float sensor_temp = ADC_read(a_channel)/0.01 ; // for 1C = 0.0097 volt
	
	
	return sensor_temp ;
}