/*
 * i2c.h
 *
 * Created: 5/1/2023 1:11:46 PM
 *  Author: moham
 */ 


#ifndef I2C_H_
#define I2C_H_

/*************************************************/
//					INCLUDES
/**************************************************/
#include "../../Utilities/registers.h"
#include "../../Utilities/bit_manipulation.h"
#include "../../Utilities/types.h"
#include <math.h>

/*************************************************/
//					MACROS
/**************************************************/
#define  F_CPU			1000000U
#define  SCL_CK			400000U
#define	 BITRATE(TWSR)	((F_CPU /SCL_CK)-16)/(2*pow(4,(TWSR&((1<<TWPS0)|(1<<TWPS1)))))

typedef enum{
	WRITE,
	READ
	
	}R_W;

typedef enum{
	ACK,
	NACK
	
}ACKOLEDGMENT;

typedef enum {
	I2C_PRESCALER_1 ,
	I2C_PRESCALER_4,
	I2C_PRESCALER_16,
	I2C_PRESCALER_64
	}I2C_PRESCALER;

/* MASTER MODE */
#define  START_SENT				0x08
#define  RESTART_SENT			0x10
#define	 AD_W_SENT_ACK			0x18
#define	 AD_W_SENT_NACK			0x20
#define	 DATA_SENT_ACK			0x28
#define  DATA_SENT_NACK			0x30
#define	 AD_R_SENT_ACK			0x40
#define  AD_R_SENT_NACK			0x48
#define	 DATA_RECIEVE_ACK		0x50
#define	 DATA_RECIEVE_NACK		0x58

/* RETURNS  */
#define	 EVENT_OK				 0
#define  START_NOT_SENT			 1 
#define  AD_W_SENT_ACK_OK		 2
#define  AD_W_SENT_NACK_OK		 3
#define  AD_W_SENT_FAILED		 5
#define  AD_R_SENT_ACK_OK	 	 6
#define  AD_R_SENT_NACK_OK		 7
#define	 AD_R_SENT_FAILED		 8
#define	 DATA_SENT_ACK_OK		 9
#define  DATA_SENT_NACK_OK		 10
#define	 DATA_SENT_FAILED		 11
#define  DATA_RECIEVE_ACK_OK	 12
#define	 DATA_RECIEVE_NACK_OK	 13
#define	 DATA_RECIEVE_FAILED	 14


/* TWSR */
#define	TWPS0				 0
#define TWPS1				 1

/* TWCR */
#define  TWIE				 0
#define  TWEN				 2
#define  TWWC				 3
#define  TWSTO				 4
#define	 TWSTA				 5
#define  TWEA				 6
#define  TWINT				 7

/*************************************************/
//			 FUNCTIONS PROTOTYPES
/**************************************************/

void I2C_init(I2C_PRESCALER prescaler);
uint8_t I2C_start();
uint8_t I2C_addressEvent(uint8_t a_address ,R_W r_w );
uint8_t I2C_sendData(uint8_t *data);
uint8_t I2C_receiveData(uint8_t *data, ACKOLEDGMENT ack);
uint8_t I2C_dataEvent(uint8_t *data ,uint8_t s_r , uint8_t ack );
void I2C_stop();
uint8_t I2c_Restart();
void EEPROM_Write (uint8_t *data, uint8_t* _addres);
void EEPROM_Read (uint8_t *data ,uint8_t _address) ;


void EEPROM_Writeseq ( uint8_t *data ,uint8_t _address);
#endif /* I2C_H_ */