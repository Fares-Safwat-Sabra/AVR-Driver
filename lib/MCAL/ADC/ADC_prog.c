/*
 * ADC_prog.c
 *
 * Created: 7/22/2026
 *  Author: fathi
 */ 

#include "BIT_MATH.h"
#include "STD_TYPE.h"
#include "ADC_interface.h"
#include "ADC_reg.h"
#include <avr/interrupt.h>

void (*ADC_CallBack)(void) = null;

// Initialize the ADC
void ADC_voidInit(void) {
	u8 Local_u8Admux = 0;
	u8 Local_u8Adcsra = 0;
	
	/* 1- Set Voltage Reference */
	#if   ADC_VREF == ADC_AREF
		CLR_BIT(Local_u8Admux, 7);
		CLR_BIT(Local_u8Admux, 6);
	#elif ADC_VREF == ADC_AVCC
		SET_BIT(Local_u8Admux, 6);
		CLR_BIT(Local_u8Admux, 7);
	#elif ADC_VREF == ADC_INTERNAL_2_56
		SET_BIT(Local_u8Admux, 6);
		SET_BIT(Local_u8Admux, 7);
	#endif
	
	/* 2- Set Adjustment */
	#if   ADC_ADJUST == ADC_LEFT_ADJUST
		SET_BIT(Local_u8Admux, 5);
	#else
		CLR_BIT(Local_u8Admux, 5);
	#endif
	
	/* 3- Set Prescaler */
	Local_u8Adcsra |= (ADC_PRESCALER & 0x07);
	
	/* 4- Write to registers */
	ADMUX_REG = Local_u8Admux;
	ADCSRA_REG = Local_u8Adcsra;
	
	/* 5- Enable ADC */
	SET_BIT(ADCSRA_REG, 7);
}

// Read ADC value from channel
u16 ADC_u16ReadChannel(u8 copy_u8channel) {
	u16 Local_u16Result = 0;
	
	/* 1- Select channel */
	ADMUX_REG &= 0xE0;
	ADMUX_REG |= (copy_u8channel & 0x07);
	
	/* 2- Start conversion */
	SET_BIT(ADCSRA_REG, 6);
	
	/* 3- Wait for ADIF flag */
	while (GET_BIT(ADCSRA_REG, 4) == 0);
	
	/* 4- Clear ADIF flag */
	SET_BIT(ADCSRA_REG, 4);
	
	/* 5- Read result */
	Local_u16Result = ADC_REG;
	
	return Local_u16Result;
}

// Start ADC conversion
void ADC_voidStartConversion(u8 copy_u8channel) {
	ADMUX_REG &= 0xE0;
	ADMUX_REG |= (copy_u8channel & 0x07);
	
	SET_BIT(ADCSRA_REG, 6);
}

// Get ADC result
u16 ADC_u16GetResult(void) {
	u16 Local_u16Result = 0;
	
	while (GET_BIT(ADCSRA_REG, 4) == 0);
	
	SET_BIT(ADCSRA_REG, 4);
	
	Local_u16Result = ADC_REG;
	
	return Local_u16Result;
}

// Get 8-bit ADC result
u8 ADC_u8GetResult8bit(void) {
	u8 Local_u8Result = 0;
	
	while (GET_BIT(ADCSRA_REG, 4) == 0);
	
	SET_BIT(ADCSRA_REG, 4);
	
	#if   ADC_ADJUST == ADC_LEFT_ADJUST
		Local_u8Result = (u8)ADCH_REG;
	#else
		Local_u8Result = (u8)(ADC_REG >> 2);
	#endif
	
	return Local_u8Result;
}

// Enable ADC
void ADC_voidEnable(void) {
	SET_BIT(ADCSRA_REG, 7);
}

// Disable ADC
void ADC_voidDisable(void) {
	CLR_BIT(ADCSRA_REG, 7);
}

// Enable ADC interrupt
void ADC_voidEnableInterrupt(void) {
	SET_BIT(ADCSRA_REG, 3);
}

// Disable ADC interrupt
void ADC_voidDisableInterrupt(void) {
	CLR_BIT(ADCSRA_REG, 3);
}

// Set ADC callback function
void ADC_voidSetCallBack(void(*ptr)(void)) {
	ADC_CallBack = ptr;
}

// ADC conversion complete interrupt service routine
ISR(ADC_vect) {
	if (ADC_CallBack != null) {
		ADC_CallBack();
	}
}
