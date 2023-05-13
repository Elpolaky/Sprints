/*
 * uartTypes.h
 *
 * Created: 5/13/2023 5:53:40 PM
 *  Author: moham
 */ 


#ifndef UARTTYPES_H_
#define UARTTYPES_H_

typedef enum{
	TX_ENABLE,
	RX_ENABLE,
	TX_RX_Enable
}EN_STATE_ENABLE;


typedef enum{
	NORMAL_SPEED,
	DOUBLE_SPEED
}EN_SPEED;


typedef enum{
	BAUD_2400,
	BAUD_4800,
	BAUD_9600,
	BAUD_14400,
	BAUD_19200,
	BAUD_28800
}EN_BAUD_RATE;

typedef enum{
	SYNC,
	ASYNC
}EN_SYNC_MODE;



typedef enum{
	ONE_STOP_BIT,
	TWO_STOP_BIT
}EN_STOP_BIT;


typedef enum{
	_5_BITS,
	_6_BITS,
	_7_BITS,
	_8_BITS,
	_9_BITS
}EN_DATA_BITS;


typedef enum{
	NO_PARITY,
	EVEN_PARITY,
	ODD_PARITY
}EN_PARITY;




#endif /* UARTTYPES_H_ */