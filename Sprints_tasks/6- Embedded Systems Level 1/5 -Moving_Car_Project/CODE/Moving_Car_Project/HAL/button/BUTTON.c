﻿#include "BUTTON.h"


BUTTON_ERROR_TYPE Button_INIT(DIO_PIN_TYPE PIN)
{
	DIO_PIN_TYPE PIN_NUM;
	DIO_PORT_TYPE PORT;
	PORT=PIN/8;
	PIN_NUM=PIN%8;
	if(PORT>4)
	{
		return INVALID_BUTTON_PORT;
	}
	else if(PIN_NUM>32)
	{
		return INVALID_BUTTON_PIN_NUMBER;
	}
	else
	{
		DIO_INITPIN(PIN,INPLUP);
		return VALID_BUTTON;
	}
}
BUTTON_ERROR_TYPE Button_read(DIO_PIN_TYPE PIN,DIO_VOLTAGE_TYPE*VOLT)
{
	DIO_PIN_TYPE PIN_NUM;
	DIO_PORT_TYPE PORT;
	PORT=PIN/8;
	PIN_NUM=PIN%8;
	if(PORT>4)
	{
		return INVALID_BUTTON_PORT;
	}
	else if(PIN_NUM>32)
	{
		return INVALID_BUTTON_PIN_NUMBER;
	}
	else
	{
		DIO_READPIN(PIN,VOLT);
		return VALID_BUTTON;
	}
}
