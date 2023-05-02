/*
 * adc.h
 *
 * Created: 4/29/2023 4:01:51 PM
 *  Author: moham
 */ 


#ifndef ADC_H_
#define ADC_H_

/*************************************************/
//					INCLUDES
/**************************************************/
#include "../../Utilities/registers.h"
#include "../../Utilities/bit_manipulation.h"
#include "../../Utilities/types.h"
#include "../DIO DRIVER/dio.h"

/*************************************************/
//					MACROS
/**************************************************/
typedef enum{
	ADC_0,
	ADC_1,
	ADC_2,
	ADC_3,
	ADC_4,
	ADC_5,
	ADC_6,
	ADC_7
	}ADC_CHANNEL;

typedef enum{
	SINGLE_INPUT,
	DIFFRENTIAL,
	
}ADC_MODE;


typedef enum{
	AVCC,
	INTERNAL_VOLT,
	
}ADC_VREF;

typedef enum{
	
	PRESCALER_2,
	PRESCALER_4,
	PRESCALER_8,
	PRESCALER_16,
	PRESCALER_32,
	PRESCALER_64,
	PRESCALER_128,
		
}ADC_PRESCALER;


/* ADMUX */
#define MUX0	0
#define MUX1	1
#define MUX2	2
#define MUX3	3
#define MUX4	4
#define ADLAR	5
#define REFS0	6
#define REFS1	7

/* ADCSRA */
#define ADPS0	0
#define ADPS1	1
#define ADPS2	2
#define ADIE	3
#define ADIF	4
#define ADATE	5
#define ADSC	6
#define ADEN	7

/*************************************************/
//			 FUNCTIONS PROTOTYPES
/**************************************************/
void ADC_init(ADC_CHANNEL a_channel , ADC_MODE a_mode  , ADC_VREF a_vref , ADC_PRESCALER a_prescaler);
float ADC_read(ADC_CHANNEL a_channel);
uint8_t LM35_calibration(ADC_CHANNEL a_channel);


#endif /* ADC_H_ */