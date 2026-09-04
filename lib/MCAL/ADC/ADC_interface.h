/*
 * ADC_interface.h
 *
 * Created: 7/22/2026
 *  Author: fathi
 */ 
#pragma once


/* ADC Voltage Reference Selections */
#define  ADC_AREF                0
#define  ADC_AVCC                1
#define  ADC_INTERNAL_2_56       3

/* ADC Prescaler Selections */
#define  ADC_PRESCALER_2         1
#define  ADC_PRESCALER_4         2
#define  ADC_PRESCALER_8         3
#define  ADC_PRESCALER_16        4
#define  ADC_PRESCALER_32        5
#define  ADC_PRESCALER_64        6
#define  ADC_PRESCALER_128       7

/* ADC Channels (single-ended) */
#define  ADC_CHANNEL_0           0
#define  ADC_CHANNEL_1           1
#define  ADC_CHANNEL_2           2
#define  ADC_CHANNEL_3           3
#define  ADC_CHANNEL_4           4
#define  ADC_CHANNEL_5           5
#define  ADC_CHANNEL_6           6
#define  ADC_CHANNEL_7           7

/* ADC Auto Trigger Sources */
#define  ADC_FREE_RUNNING        0
#define  ADC_ANALOG_COMPARATOR   1
#define  ADC_EXTI0               2
#define  ADC_TIM0_COMP_MATCH     3
#define  ADC_TIM0_OVF            4
#define  ADC_TIM1_COMP_MATCH_B   5
#define  ADC_TIM1_OVF            6
#define  ADC_TIM1_CAPTURE        7

/* ADC Adjustment */
#define  ADC_RIGHT_ADJUST        0
#define  ADC_LEFT_ADJUST         1

/* Configuration Macros (user-configurable) */
#define  ADC_VREF                ADC_AVCC
#define  ADC_PRESCALER           ADC_PRESCALER_128
#define  ADC_ADJUST              ADC_RIGHT_ADJUST

void ADC_voidInit(void);
u16  ADC_u16ReadChannel(u8 copy_u8channel);
void ADC_voidStartConversion(u8 copy_u8channel);
u16  ADC_u16GetResult(void);
u8   ADC_u8GetResult8bit(void);
void ADC_voidEnable(void);
void ADC_voidDisable(void);
void ADC_voidEnableInterrupt(void);
void ADC_voidDisableInterrupt(void);
void ADC_voidSetCallBack(void(*ptr)(void));

