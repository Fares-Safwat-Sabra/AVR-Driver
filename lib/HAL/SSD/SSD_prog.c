/*
 * SSD_prog.c
 *
 * Created: 4/13/2026 7:10:06 PM
 *  Author: fathi
 */ 
#include "BIT_MATH.h"
#include "STD_TYPE.h"
#include "DIO_interface.h"
#include "SSD_config.h"




void SSD_voidDispalyNum(u8 copy_u8num)
{
	u8  ssd[10]={0x3f,0x06,0x5b,0x4f,0x66,0x6d,0x7d,0x07,0x7f,0x6f} ; 
		
	DIO_voidSetPortDir(SSD_PORT,0xff) ; 
	
	DIO_voidSetPortVal(SSD_PORT,ssd[copy_u8num]) ; 
		
	  
	
}