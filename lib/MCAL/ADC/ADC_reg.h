/*
 * ADC_reg.h
 *
 * Created: 7/22/2026
 *  Author: fathi
 */ 

#ifndef ADC_REG_H_
#define ADC_REG_H_

#define  ADMUX_REG               *((volatile u8*)0x27)  // ADC Multiplexer Selection Register
#define  ADCSRA_REG              *((volatile u8*)0x26)  // ADC Control and Status Register A
#define  ADCL_REG                *((volatile u8*)0x24)  // ADC Low Register
#define  ADCH_REG                *((volatile u8*)0x25)  // ADC High Register
#define  ADC_REG                 *((volatile u16*)0x24) // ADC Data Register
#define  SFIOR_REG               *((volatile u8*)0x50)  // Special Function I/O Register

#endif /* ADC_REG_H_ */
