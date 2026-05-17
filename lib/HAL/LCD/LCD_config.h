/*
 * LCD_config.h
 *
 * Created: 4/15/2026 7:48:59 PM
 *  Author: fathi
 */ 


#ifndef LCD_CONFIG_H_
#define LCD_CONFIG_H_

/* hex of pins dir */

#define  LCD_C_DIR        0x07 
#define  LCD_D_DIR        0xf0

/* LCD Control pins */

#define  LCD_CPORT    DIO_PORTB 

#define LCD_RW_PIN    DIO_PIN0 
#define LCD_RS_PIN    DIO_PIN1
#define LCD_EN_PIN    DIO_PIN2 


/*LCD Data pins */

#if LCD_MODE  == LCD_8BIT_MODE

   #define  LCD_DPORT      DIO_PORTA  

#elif LCD_MODE == LCD_4BIT_MODE 

   #define  LCD_DPORT     DIO_PORTA 
   
   #define  LCD_D4_PIN    DIO_PIN4
   #define  LCD_D5_PIN    DIO_PIN5
   #define  LCD_D6_PIN    DIO_PIN6
   #define  LCD_D7_PIN    DIO_PIN7
   
#endif    
   
   
















#endif /* LCD_CONFIG_H_ */