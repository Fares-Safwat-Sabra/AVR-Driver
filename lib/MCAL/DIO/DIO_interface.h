/*
 * DIO_interface.h
 *
 * Created: 4/12/2026 8:56:42 PM
 *  Author: fathi
 */ 


#ifndef DIO_INTERFACE_H_
#define DIO_INTERFACE_H_


#define  OUTPUT            1 
#define  INPUT             0 

/*PIN VAL */

#define  HIGH              1 
#define  LOW               0 

/* DIO PORTS */


#define  DIO_PORTA         0 
#define  DIO_PORTB         1 
#define  DIO_PORTC         2
#define  DIO_PORTD         3


/*  DIO PINS */


#define  DIO_PIN0            0
#define  DIO_PIN1            1
#define  DIO_PIN2            2
#define  DIO_PIN3            3
#define  DIO_PIN4            4
#define  DIO_PIN5            5
#define  DIO_PIN6            6
#define  DIO_PIN7            7

void DIO_voidSetPinDir(u8 copy_u8port, u8 copy_u8pin, u8 copy_u8dir);
void DIO_voidSetPinVal(u8 copy_u8port, u8 copy_u8pin, u8 copy_u8val);
u8   DIO_u8ReadPinVal(u8 copy_u8port, u8 copy_u8pin);
void DIO_voidTogglePinVal(u8 copy_u8port, u8 copy_u8pin);
void DIO_voidSetPortDir(u8 copy_u8port, u8 copy_u8dir);
void DIO_voidSetPortVal(u8 copy_u8port, u8 copy_u8val);

#endif /* DIO_INTERFACE_H_ */