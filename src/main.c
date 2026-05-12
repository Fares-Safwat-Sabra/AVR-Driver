/*
 * D101_DRIVERS.c
 *
 * Created: 4/12/2026 8:54:38 PM
 * Author : fathi
 */ 
#include "main.h"


int main(void)
{
	  

	 
 	   LCD_voidInit() ; 
	    KPD_voidInit() ; 	
	     
		 u8 key=0xff ; 
	
    while (1) 
    {
		
       do 
       {
		   key = KPD_u8GetKey() ; 
		   
       } while (key==0xff);
		

        LCD_voidSendNumber(key)  ; 
		
		
		

    }
}

