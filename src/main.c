/*
 * Project 1: ADC Potentiometer Reader
 * قراءة الجهد من البوتنشيوميتر وعرض القيمة الرقمية والجهد على LCD
 *
 * Created: 7/22/2026
 *  Author: fathi
 */ 
#include "main.h"

int main(void)
{
	u16 ADC_Value = 0;
	u16 ADC_Voltage_mV = 0;

	LCD_voidInit();
	ADC_voidInit();

	while (1)
	{
		ADC_Value = ADC_u16ReadChannel(ADC_CHANNEL_0);

		ADC_Voltage_mV = (ADC_Value * 5000) / 1023;

		LCD_voidGotoXY(0, 1);
		LCD_voidSendString("Raw: ");
		LCD_voidSendNumber(ADC_Value);
		LCD_voidSendString("    ");

		LCD_voidGotoXY(0, 0);
		LCD_voidSendString("V: ");
		LCD_voidSendNumber(ADC_Voltage_mV / 1000);
		LCD_voidSendData('.');
		LCD_voidSendNumber(ADC_Voltage_mV  / 100);

		_delay_ms(200);
	}
}
