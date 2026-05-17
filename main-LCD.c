/*
 * D101_DRIVERS.c
 *
 * Created: 4/12/2026 8:54:38 PM
 * Author : fathi
 */ 
#include "main.h"


int main(void)
{
  DIO_voidSetPinDir(DIO_PORTB,DIO_PIN3,OUTPUT) ;
  DIO_voidSetPinDir(DIO_PORTC,DIO_PIN2,OUTPUT) ;
  DIO_voidSetPinDir(DIO_PORTC,DIO_PIN7,OUTPUT) ;
  DIO_voidSetPinDir(DIO_PORTD,DIO_PIN6,OUTPUT) ;

  DIO_voidSetPinDir(DIO_PORTD,DIO_PIN2,INPUT) ;
  DIO_voidSetPinDir(DIO_PORTD,DIO_PIN3,INPUT) ;
  DIO_voidSetPinDir(DIO_PORTD,DIO_PIN7,INPUT) ;

  LCD_voidInit() ;

  u8 count = 0 ;

  LCD_voidGotoXY(0,1) ;
  LCD_voidSendString((s8*) "ENG FARES") ;

  u8 Hface1[] = {
  0x00,
  0x02,
  0x02,
  0x18,
  0x18,
  0x1F,
  0x1F,
  0x00
  };
    u8 Hface2[] = {
  0x00,
  0x08,
  0x08,
  0x03,
  0x03,
  0x1F,
  0x1F,
  0x00
  };


  LCD_voidDrawData(Hface1, 0, 10, 1) ;
  LCD_voidDrawData(Hface2, 1, 11, 1) ;
  
    while (1)
    {
      if (DIO_u8ReadPinVal(DIO_PORTD,DIO_PIN2) == LOW)
      {
        if (count >= 99) 
        {
          count = 0 ;
        }else{
        count++ ;}
        LCD_voidGotoXY(0,0) ;
        LCD_voidSendNumber(count) ;
        LCD_voidSendString((s8*)"  ");

        while(DIO_u8ReadPinVal(DIO_PORTD, DIO_PIN2) == LOW);
      }
      if (DIO_u8ReadPinVal(DIO_PORTD,DIO_PIN3) == LOW)
      {
        if (count == 0) 
        {
          count = 99 ;
        }else{
          count-- ;}
        LCD_voidGotoXY(0,0) ;
        LCD_voidSendNumber(count) ;
        LCD_voidSendString((s8*)"  ");

        while(DIO_u8ReadPinVal(DIO_PORTD, DIO_PIN3) == LOW);
      }
      if (DIO_u8ReadPinVal(DIO_PORTD,DIO_PIN7) == LOW)
      {
        count = 0 ;                                                                                                   
        LCD_voidGotoXY(0,0) ;
        LCD_voidSendNumber(count) ;
        LCD_voidSendString((s8*)"  ");

        while(DIO_u8ReadPinVal(DIO_PORTD, DIO_PIN7) == LOW);
      }


      if (count < 25) {
            DIO_voidSetPinVal(DIO_PORTB, DIO_PIN3, LOW);
            DIO_voidSetPinVal(DIO_PORTC, DIO_PIN2, LOW);
            DIO_voidSetPinVal(DIO_PORTC, DIO_PIN7, LOW);
            DIO_voidSetPinVal(DIO_PORTD, DIO_PIN6, LOW);
        }
        else if (count >= 25 && count < 50) {
            DIO_voidSetPinVal(DIO_PORTB, DIO_PIN3, HIGH);
            DIO_voidSetPinVal(DIO_PORTC, DIO_PIN2, LOW);
            DIO_voidSetPinVal(DIO_PORTC, DIO_PIN7, LOW);
            DIO_voidSetPinVal(DIO_PORTD, DIO_PIN6, LOW);
        }
        else if (count >= 50 && count < 75) {
            DIO_voidSetPinVal(DIO_PORTB, DIO_PIN3, HIGH);
            DIO_voidSetPinVal(DIO_PORTC, DIO_PIN2, HIGH);
            DIO_voidSetPinVal(DIO_PORTC, DIO_PIN7, LOW);
            DIO_voidSetPinVal(DIO_PORTD, DIO_PIN6, LOW);
        }
        else if (count >= 75 && count < 99) {
            DIO_voidSetPinVal(DIO_PORTB, DIO_PIN3, HIGH);
            DIO_voidSetPinVal(DIO_PORTC, DIO_PIN2, HIGH);
            DIO_voidSetPinVal(DIO_PORTC, DIO_PIN7, HIGH);
            DIO_voidSetPinVal(DIO_PORTD, DIO_PIN6, LOW);
        }
        else if (count == 99) {
            DIO_voidSetPinVal(DIO_PORTB, DIO_PIN3, HIGH);
            DIO_voidSetPinVal(DIO_PORTC, DIO_PIN2, HIGH);
            DIO_voidSetPinVal(DIO_PORTC, DIO_PIN7, HIGH);
            DIO_voidSetPinVal(DIO_PORTD, DIO_PIN6, HIGH);
        }



    }
}

