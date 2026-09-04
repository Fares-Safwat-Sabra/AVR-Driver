/*
 * TIM1_prog.c
 *
 * Created: 6/25/2026 8:26:57 PM
 *  Author: x13
 */ 

#include "../../LIB/BIT_MATH.h"
#include "../../LIB/STD_TYPE.h"
#include "../../LIB/InterruptVectorNum.h"
#include "TIM1_reg.h"
#include "TIM1_interface.h"
#include "../../MCAL/DIO/DIO_interface.h"

void (*ICR_PTR)(void)=null ; 


void TIM1_voidFastPwmICR( u8 copy_u8pin) {
	
	/*SET FAST PWM ICR MODE */
	
	 CLR_BIT(TCCR1A_REG,0) ; 
	 SET_BIT(TCCR1A_REG,1) ; 
	 
	 SET_BIT(TCCR1B_REG,3) ; 
	 SET_BIT(TCCR1B_REG,4) ; 
	
	
	/* set prescaler */
	
	  TCCR1B_REG&=0b11111000 ; 
	  TCCR1B_REG |=TIM1_PRESCALER ; 
	
	switch(copy_u8pin){
		
		case  OC1A : 
		                SET_BIT(TCCR1A_REG,7) ; 
						CLR_BIT(TCCR1A_REG,6) ; break ; 
		
		case OC1B :    
		              				
		          SET_BIT(TCCR1A_REG,5) ;
		          CLR_BIT(TCCR1A_REG,4) ; break ; 
	}
	
	
	/*SET TOP VALUE */
	
	ICR1_REG =40000 ; 
	
}




void TIM1_voidSetOCRVal(u16  copy_u16val , u8 copy_u8pin) {
	
	
	switch(copy_u8pin){
		
		case OC1A :  OCR1A_REG = copy_u16val ;break ; 
		case OC1B :  OCR1B_REG =copy_u16val ; break ; 
		
		
	}
	
	
	
	
}




void TIM1_voidICRInit( u8 sense ) {
	
	
		/* set prescaler */
		
		TCCR1B_REG&=0b11111000 ;
		TCCR1B_REG |=TIM1_PRESCALER ;
	
     	SET_BIT(TIMSK_REG,5) ;

	
switch(sense){
	
	
	case  RISING : /*  RISING ICR  */
	                SET_BIT(TCCR1B_REG,6) ;	break; 
	case FALLING : CLR_BIT(TCCR1B_REG,6) ; break; 			 
}



	
}

void TIM1_voidRestICR(void) {
	
	
	ICR1_REG =0x0000 ;
	
	
}

u16 TIM1_u16ReadICR(void) {
	
	
	return ICR1_REG ; 
}




void TIM1_voidICR_SetCallBack(void (*ptr)(void)){
	
	
	ICR_PTR =ptr ; 
	
	
	
}



