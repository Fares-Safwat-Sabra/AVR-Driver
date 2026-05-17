/*
 * D101_DRIVERS.c
 *
 * Created: 4/12/2026 8:54:38 PM
 * Author : fathi
 */ 
#include "main.h"


int main(void)
{
  DIO_voidSetPortDir(DIO_PORTA, OUTPUT) ;
  DIO_voidSetPortDir(DIO_PORTB, OUTPUT) ;
  DIO_voidSetPortDir(DIO_PORTD, INPUT) ;

  u8 count = 0 ;
  
    while (1)
    {
      Display_Multiplex(count);

        /* --- فحص الأزرار --- */
        if(DIO_u8ReadPinVal(DIO_PORTD, DIO_PIN2) == LOW)
        { 
            if(count == 99) { count = 0; }
            else { count++; }
            
            // قفل المعالج حتى رفع الإصبع + تحديث الشاشة لمنع الانطفاء
            while(DIO_u8ReadPinVal(DIO_PORTD, DIO_PIN2) == LOW) {
                Display_Multiplex(count);
            }
        }

        if(DIO_u8ReadPinVal(DIO_PORTD, DIO_PIN3) == LOW)
        { 
            if(count == 0) { count = 99; }
            else { count--; }
            
            while(DIO_u8ReadPinVal(DIO_PORTD, DIO_PIN3) == LOW) {
                Display_Multiplex(count);
            }
        }

        if(DIO_u8ReadPinVal(DIO_PORTD, DIO_PIN7) == LOW)
        { 
            count = 0;
            while(DIO_u8ReadPinVal(DIO_PORTD, DIO_PIN7) == LOW) {
                Display_Multiplex(count);
            }
        }
    }
}

