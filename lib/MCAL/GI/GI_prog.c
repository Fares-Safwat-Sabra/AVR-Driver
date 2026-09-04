/*
 * GI_prog.c
 *
 * Created: 5/11/2026 10:46:35 PM
 *  Author: fathi
 */ 

#include "BIT_MATH.h"
#include "STD_TYPE.h"
#include "GI_reg.h"

void GI_voidEnable(void) {
	
	
	//SET_BIT(SREG_REG,7) ;  //  SREG |=1<<7 ; ---> 7+1 +1
	
	__asm volatile("SEI") ; 
	
}

void GI_voidDisable(void) {
	
	
	//CLR_BIT(SREG_REG,7) ; 
	
	__asm volatile ("CLI") ; 
}
