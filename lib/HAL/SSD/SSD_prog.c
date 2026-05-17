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
#include <util/delay.h>




void SSD_voidDispalyNum(u8 copy_u8num)
{
	u8  ssd[10]={0x3f,0x06,0x5b,0x4f,0x66,0x6d,0x7d,0x07,0x7f,0x6f} ; 
		
	DIO_voidSetPortDir(SSD_PORT,0xff) ; 
	
	DIO_voidSetPortVal(SSD_PORT,ssd[copy_u8num]) ; 
		
	  
	
}

void Display_Multiplex(u8 current_count) {
DIO_voidSetPinVal(DIO_PORTB, DIO_PIN1, HIGH);
    DIO_voidSetPinVal(DIO_PORTB, DIO_PIN2, HIGH);

    if (current_count <= 9) {
        // تجهيز البيانات أولاً
        SSD_voidDispalyNum(current_count);            
        // تشغيل الآحاد فقط
        DIO_voidSetPinVal(DIO_PORTB, DIO_PIN2, LOW);  
        _delay_ms(5);
    } else {
        // --- عرض العشرات ---
        SSD_voidDispalyNum(current_count / 10);       // تجهيز البيانات
        DIO_voidSetPinVal(DIO_PORTB, DIO_PIN1, LOW);  // تفعيل العشرات
        _delay_ms(5);
        
        // --- إظلام فاصل لمنع انتقال الشبح ---
        DIO_voidSetPinVal(DIO_PORTB, DIO_PIN1, HIGH); 
        
        // --- عرض الآحاد ---
        SSD_voidDispalyNum(current_count % 10);       // تجهيز البيانات
        DIO_voidSetPinVal(DIO_PORTB, DIO_PIN2, LOW);  // تفعيل الآحاد
        _delay_ms(5);
        
        // إطفاء الآحاد في النهاية لتسليم الحافلة نظيفة
        DIO_voidSetPinVal(DIO_PORTB, DIO_PIN2, HIGH);
    }
}