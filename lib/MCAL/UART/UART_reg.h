/*
 * UART_reg.h
 *
 * Created: 7/2/2026 8:11:56 PM
 *  Author: x13
 */ 


#ifndef UART_REG_H_
#define UART_REG_H_

#define  UDR_REG              *((volatile u8*)0x2C)
#define  UCSRA_REG            *((volatile u8*)0x2B)
#define  UCSRB_REG            *((volatile u8*)0x2A)
#define  UBRRL_REG            *((volatile u8*)0x29)
#define  UCSRC_REG            *((volatile u8*)0x40)



#endif /* UART_REG_H_ */