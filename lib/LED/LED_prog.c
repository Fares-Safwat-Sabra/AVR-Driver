/*
 * LED_prog.c
 *
 * Created: 4/13/2026 6:54:10 PM
 *  Author: fathi
 */ 
#include "BIT_MATH.h"
#include "STD_TYPE.h"
#include "DIO_interface.h"



void LED_voidOn(u8 copy_u8port , u8 copy_u8pin) {
	
	DIO_voidSetPinDir(copy_u8port,copy_u8pin,OUTPUT) ; 
	
	DIO_voidSetPinVal(copy_u8port,copy_u8pin,HIGH) ; 
	
	
	
}
void LED_voidOff(u8 copy_u8port , u8 copy_u8pin) {
	
		DIO_voidSetPinDir(copy_u8port,copy_u8pin,OUTPUT) ;
		
		DIO_voidSetPinVal(copy_u8port,copy_u8pin,LOW) ;
	
}
void LED_voidToggle(u8 copy_u8port , u8 copy_u8pin) {
	
		DIO_voidSetPinDir(copy_u8port,copy_u8pin,OUTPUT) ;
		
		DIO_voidTogglePinVal(copy_u8port,copy_u8pin) ;
}
