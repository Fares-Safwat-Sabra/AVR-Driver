/*
 * SPI_prog.c
 *
 */ 
#include "../../LIB/BIT_MATH.h"
#include "../../LIB/STD_TYPE.h"
#include "../DIO/DIO_interface.h"
#include "SPI_interface.h" 
#include "SPI_reg.h"






void SPI_voidMasterInit(void) {
	
	/* config  SPI PINS (MASTER ) */
	
   DIO_voidSetPinDir(SPI_PORT,SS_PIN,OUTPUT) ; 
   DIO_voidSetPinDir(SPI_PORT,MOSI_PIN,OUTPUT) ;
   DIO_voidSetPinDir(SPI_PORT,MISO_PIN,INPUT) ;
   DIO_voidSetPinDir(SPI_PORT,SCK_PIN,OUTPUT) ;
   
   
   /* SET SPI clock (128) */
     
	  SET_BIT(SPCR_REG,0) ; 
	  SET_BIT(SPCR_REG,1) ;
	  
   
   /*SET BIT 4 TO select master mode */
	
	 SET_BIT(SPCR_REG,4) ; 
	/* enable SPI*/
	
	SET_BIT(SPCR_REG,6) ; 
	
}

void SPI_voidSlaveInit(void) {
	
	/* config  SPI PINS (slave ) */
	
	DIO_voidSetPinDir(SPI_PORT,SS_PIN,INPUT) ;
	DIO_voidSetPinDir(SPI_PORT,MOSI_PIN,INPUT) ;
	DIO_voidSetPinDir(SPI_PORT,MISO_PIN,OUTPUT) ;
	DIO_voidSetPinDir(SPI_PORT,SCK_PIN,INPUT) ;
	
	
	
	/*SET BIT 4 TO select master mode */
	
	CLR_BIT(SPCR_REG,4) ;
	/* enable SPI*/
	
	SET_BIT(SPCR_REG,6) ;
	
	
}

void SPI_voidMasterSendData( u8 copy_u8data) {
	
	    SPDR_REG = copy_u8data ; 
		
		while(GET_BIT(SPSR_REG,7)==0) ; 
	
	
	
}

u8 SPI_u8SlaveReciveData(void) {
	
		while(GET_BIT(SPSR_REG,7)==0) ;
		
	
	return SPDR_REG ; 
}

