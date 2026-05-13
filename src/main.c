/*
 * D101_DRIVERS.c
 *
 * Created: 4/12/2026 8:54:38 PM
 * Author : fathi
 */ 
#include "main.h"


int main(void)
{
	  	u8 i=0 ;
	
    while (1) 
    {
		SSD_voidDispalyNum(i);
        i++ ;
        if (i == 10) i=0;
        _delay_ms(1000) ;
    }
}

