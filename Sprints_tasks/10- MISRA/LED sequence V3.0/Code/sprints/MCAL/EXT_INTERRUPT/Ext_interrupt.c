/*
 * Ext_interrupt.c
 *
 * Created: 4/8/2023 8:29:59 PM
 *  Author: moham
 */ 
#include "Ext_IntCnfg.h"

void static (*P0_CallbackFunction) (void);
void static (*P1_CallbackFunction) (void);
void static (*P2_CallbackFunction) (void);



Ext_intErrorStatus error_status = EXT_INT_OK ;

/***************************************************/
//			 EXTERNAL INTERRUPT INIT
/***************************************************/
Ext_intErrorStatus ExtInt_init(){

/****************** INTERRRUPT 0 ******************/	

#if INT0_ENABLE == ENABLE
	
		
//CHOOSE INTERUPT SENSE MODE
#if INT0_SENSE_MODE == LOW_LEVEL
			CLR_BIT(MCUCR,ISC00);
			CLR_BIT(MCUCR,ISC01);
		
#elif INT0_SENSE_MODE == ANY_LOGIC
			SET_BIT(MCUCR,ISC00);
			CLR_BIT(MCUCR,ISC01);
	
#elif INT0_SENSE_MODE == FALLING_EDGE
			SET_BIT(MCUCR,ISC01);
			CLR_BIT(MCUCR,ISC00);
		
#elif INT0_SENSE_MODE == RAISING_EDGE
			SET_BIT(MCUCR,ISC00);
			SET_BIT(MCUCR,ISC01);
#else
	error_status = WRONG_SENSE_MODE;
	
#endif 

//ENABLE INTERRUPT_0
SET_BIT(GICR,INT_0);

#elif INT0_ENABLE != DISABLE && INT0_ENABLE != ENABLE
	error_status = INT_ENABLE_ERROR;


#endif
	
	
/***************** INTERRRUPT 1 ******************/

#if INT1_ENABLE == ENABLE

//CHOOSE INTERUPT SENSE MODE
#if INT1_SENSE_MODE == LOW_LEVEL
	CLR_BIT(MCUCR,ISC10);
	CLR_BIT(MCUCR,ISC11);

#elif INT1_SENSE_MODE == ANY_LOGIC
	SET_BIT(MCUCR,ISC10);
	CLR_BIT(MCUCR,ISC11);

#elif INT1_SENSE_MODE == FALLING_EDGE
	SET_BIT(MCUCR,ISC11);
	CLR_BIT(MCUCR,ISC10);

#elif INT1_SENSE_MODE == RAISING_EDGE
	SET_BIT(MCUCR,ISC10);
	SET_BIT(MCUCR,ISC11);
	
#else
error_status = WRONG_SENSE_MODE;

#endif

//ENABLE INTERRUPT_1
SET_BIT(GICR,INT_1);

#elif INT1_ENABLE != DISABLE && INT0_ENABLE != ENABLE
	error_status = INT_ENABLE_ERROR;

#endif


	
/****************** INTERRRUPT 2 ******************/


#if INT2_ENABLE == ENABLE

//CHOOSE INTERUPT SENSE MODE
#if INT2_SENSE_MODE == FALLING_EDGE
	CLR_BIT(MCUCSR,ISC2);

#elif INT2_SENSE_MODE == RAISING_EDGE
	SET_BIT(MCUCSR,ISC2);
	
#else
error_status = WRONG_SENSE_MODE;

#endif

//ENABLE INTERRUPT_2
SET_BIT(GICR,INT_2);

#elif INT2_ENABLE != DISABLE && INT0_ENABLE != ENABLE
	error_status = INT_ENABLE_ERROR;

#endif



return error_status;
} // END OF ExtInt_init 


/*************************************************/
//				CALLBACK FUNCTIONS
/**************************************************/

// CALLBACK FUNCTION TO INT_0
Ext_intErrorStatus INT0_SetCallback(void(*callback)(void)){
if(error_status==EXT_INT_OK){
	if(callback!=0){
			P0_CallbackFunction=callback;
			return EXT_INT_OK;
	}else{
		return NULL_POINTE;
	}
}
else{
	return error_status;
	
}

}


// CALLBACK FUNCTION TO INT_1
Ext_intErrorStatus INT1_SetCallback(void(*callback)(void)){

	P1_CallbackFunction=callback;
}


// CALLBACK FUNCTION TO INT_2
Ext_intErrorStatus INT2_SetCallback(void(*callback)(void)){

	P2_CallbackFunction=callback;
}



/***************************************************/
//					 ISR FUNCTION
/***************************************************/
 
/**********  ISR OF INT_0  ************/

ISR(EXT_INT_0){

	
		P0_CallbackFunction();
	
	
}


/**********  ISR OF INT_1  ************/

ISR(EXT_INT_1){

	
		P1_CallbackFunction();
	
	
}


/**********  ISR OF INT_2  ************/

ISR(EXT_INT_2){

	
		P2_CallbackFunction();
	
	
}