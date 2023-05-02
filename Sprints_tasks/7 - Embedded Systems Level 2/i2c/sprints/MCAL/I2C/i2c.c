/*
 * i2c.c
 *
 * Created: 5/1/2023 1:11:32 PM
 *  Author: moham
 */ 
#include "i2c.h"


void I2C_init(I2C_PRESCALER prescaler){
	
	TWSR = 0x00 ;
	
	switch (prescaler){
		case I2C_PRESCALER_1 :
		CLR_BIT(TWSR,TWPS0);
		CLR_BIT(TWSR,TWPS1);
		break;
		
		case I2C_PRESCALER_4 :
		SET_BIT(TWSR,TWPS0);
		CLR_BIT(TWSR,TWPS1);
		break;
		
		case I2C_PRESCALER_16 :
		CLR_BIT(TWSR,TWPS0);
		SET_BIT(TWSR,TWPS1);
		break;
		
		
		case I2C_PRESCALER_64 :
		SET_BIT(TWSR,TWPS0);
		SET_BIT(TWSR,TWPS1);
		break;
		
		default:
		break;
	}
	
	
	TWBR  = BITRATE(TWSR);
	
}

uint8_t I2C_start(){
	
	SET_BIT(TWCR,TWINT);  // clear flag
	SET_BIT(TWCR,TWSTA);  // enable start condition
	SET_BIT(TWCR,TWEN);   // enable i2c
	while(GET_BIT(TWCR,TWINT) != 1);  // wait for flag to set
	
	if((TWSR & 0xf8) == START_SENT){   // check start condition status
		return EVENT_OK ;
		
	}else {
		
		return START_NOT_SENT ;
	}
	
}


uint8_t I2C_addressEvent(uint8_t a_address ,R_W r_w ){
	switch(r_w){
		
		case WRITE : 
		TWDR = a_address + WRITE ; //SET ADDRESS + WRITE
		
		SET_BIT(TWCR,TWINT);  // clear flag
		SET_BIT(TWCR,TWEN);   // enable i2c
		while(GET_BIT(TWCR,TWINT) != 1);  // wait for flag to set
		
		if((TWSR & 0xf8) == AD_W_SENT_ACK){   // check status of sending address that we want to write in and ack received
			return AD_W_SENT_ACK_OK ;
		}
		else if ((TWSR & 0xf8) == AD_W_SENT_NACK){
			return AD_W_SENT_NACK_OK ;
		}
		else {
			
			return AD_W_SENT_FAILED ;
		}
		
		break; // END OF WRITE CASE
		
		
		
		case READ :
		TWDR = a_address + READ ; //SET ADDRESS + read
		
		SET_BIT(TWCR,TWINT);  // clear flag
		SET_BIT(TWCR,TWEN);   // enable i2c
		while(GET_BIT(TWCR,TWINT) != 1);  // wait for flag to set
		
		if((TWSR & 0xf8) == AD_R_SENT_ACK){   // // check status of sending address that we want to read from and ack received
			return AD_R_SENT_ACK_OK ;
		}
		else if ((TWSR & 0xf8) == AD_R_SENT_NACK){
			return AD_R_SENT_NACK_OK ;
		}
		else {
				
			return AD_R_SENT_FAILED ;
		}
			
		
		break;// END OF READ CASE
		
	}

	
}
uint8_t I2C_sendData(uint8_t *data ){
		
		TWDR = *data ;
		SET_BIT(TWCR,TWINT);  // clear flag
		SET_BIT(TWCR,TWEN);   // enable i2c
		while(GET_BIT(TWCR,TWINT) != 1);  // wait for flag to set
		
		if((TWSR & 0xf8) == DATA_SENT_ACK){   //  // check status of sending data  and ack received
			return DATA_SENT_ACK_OK ;
		}
		else if ((TWSR & 0xf8) == DATA_SENT_NACK){
			return DATA_SENT_NACK_OK ;
		}
		else {
			
			return DATA_SENT_FAILED ;
		}
	
}

void I2C_stop(){
	CLR_BIT(TWCR,TWSTA);  // clear start
	SET_BIT(TWCR,TWINT);  // clear flag
	SET_BIT(TWCR,TWSTO);  // enable stop condition
	SET_BIT(TWCR,TWEN);   // enable i2c
	while(GET_BIT(TWCR,TWSTO) != 0);  // wait for flag to set
	
}


uint8_t I2C_receiveData(uint8_t *data, ACKOLEDGMENT ack){
	
	switch(ack){ 
		case ACK :
		SET_BIT(TWCR,TWEA); 
		break;
		
		case NACK :
		CLR_BIT(TWCR,TWEA);
		break;
		
	}
	
	SET_BIT(TWCR,TWINT);  // clear flag
	SET_BIT(TWCR,TWEN);   // enable i2c
	while(GET_BIT(TWCR,TWINT) != 1);  // wait for flag to set
	*data = TWDR ;
	if((TWSR & 0xf8) == DATA_RECIEVE_ACK){    // check status of receiving data and ack received
		return DATA_RECIEVE_ACK_OK ;
	}
	else if ((TWSR & 0xf8) == DATA_RECIEVE_NACK){
		return DATA_RECIEVE_NACK_OK ;
	}
	else {
		
		return DATA_RECIEVE_FAILED ;
	}
	

}

uint8_t I2c_Restart(){
	
		SET_BIT(TWCR,TWINT);  // clear flag
		SET_BIT(TWCR,TWSTA);  // enable start condition
		SET_BIT(TWCR,TWEN);   // enable i2c
		while(GET_BIT(TWCR,TWINT) != 1);  // wait for flag to set
		
		if((TWSR & 0xf8) == RESTART_SENT){   // check start condition status
			return EVENT_OK ;
			
		}else {
			
			return START_NOT_SENT ;
		}
		
}



void EEPROM_Write (uint8_t *data, uint8_t *_address){
	
	if(I2C_start()==EVENT_OK){
		
		if(I2C_addressEvent(0xA0,WRITE)==AD_W_SENT_ACK_OK){
			
			if(I2C_sendData(_address)== DATA_SENT_ACK_OK){
				
				if(I2C_sendData(data)== DATA_SENT_ACK_OK){
					
					I2C_stop();
				}
			}
			
		}
		
	}
	
	
}
void EEPROM_Read ( uint8_t *data ,uint8_t* _address) {

	if(I2C_start()==EVENT_OK){
	
	//	if(I2C_addressEvent(0xA0,WRITE)==AD_W_SENT_ACK_OK){
			
		//	if(I2C_sendData(_address)== DATA_SENT_ACK_OK){
			
			//	if(I2c_Restart()==EVENT_OK){
					
					if(I2C_addressEvent(0xA0,READ)==AD_R_SENT_ACK_OK){
						
						if(I2C_sendData(data)== DATA_SENT_NACK_OK){
							
							I2C_stop();
							
						}
					}
					
			//	}
				
			//}
			
		//}
		
		
		
	}
	
	
}