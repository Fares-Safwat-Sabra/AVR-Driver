/*
 * SPI_interface.h
 *  Author: fathi
 */ 


#ifndef SPI_INTERFACE_H_
#define SPI_INTERFACE_H_


/*SPI PINS */

#define  SPI_PORT       DIO_PORTB  

#define  SS_PIN         DIO_PIN4 
#define  MOSI_PIN       DIO_PIN5 
#define  MISO_PIN       DIO_PIN6
#define  SCK_PIN       DIO_PIN7






void SPI_voidMasterInit(void) ; 

void SPI_voidSlaveInit(void) ;

void SPI_voidMasterSendData( u8 copy_u8data) ; 

u8 SPI_u8SlaveReciveData(void) ; 





#endif /* SPI_INTERFACE_H_ */