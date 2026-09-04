/*
 * UART_prog.c
 *
 * Created: 7/2/2026 8:12:29 PM
 *  Author: x13
 */ 
#include "../../LIB/BIT_MATH.h"
#include "../../LIB/STD_TYPE.h" 
#include "UART_reg.h"




void UART_voidInit(void) {
	
	 u8 temp=0 ; 
	 
	 /*set UART  baud rate : 9600 */
	
	 UBRRL_REG =103 ; 
	 
      SET_BIT(temp,7) ; 
	  	
	  SET_BIT(temp,1) ; 
	  SET_BIT(temp,2) ; 
	  
	  UCSRC_REG = temp ; 
	
	/*Enable RX  , TX */
	
	SET_BIT(UCSRB_REG,4) ; // RX 
	SET_BIT(UCSRB_REG,3) ; // TX 
	
}




void UART_voidSendData( u8 data) {
	
	UDR_REG = data ; 
	
	while(GET_BIT(UCSRA_REG,5)==0) ; 
	
	
	
}


u8 UART_u8ReciveData(void) {
	
	while(GET_BIT(UCSRA_REG,7)==0) ; 
	
	return UDR_REG ; 
	
}
