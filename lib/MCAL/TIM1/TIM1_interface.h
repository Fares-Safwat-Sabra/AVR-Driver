/*
 * TIM1_interface.h
 *
 * Created: 6/25/2026 8:26:44 PM
 *  Author: x13
 */ 


#ifndef TIM1_INTERFACE_H_
#define TIM1_INTERFACE_H_


/* TIM1  prescaler */


#define  TIM1_NO_PRESCALER            1
#define  TIM1_8_PRESCALER             2
#define  TIM1_64_PRESCALER            3
#define  TIM1_256_PRESCALER           4
#define  TIM1_1024_PRESCALER          5

/* select tim1 prescaler */

#define  TIM1_PRESCALER        	TIM1_64_PRESCALER

/*TIMER1 pwm pins */

#define  OC1A            0 
#define  OC1B            1 

void TIM1_voidFastPwmICR( u8 copy_u8pin) ; 

void TIM1_voidSetOCRVal(u16  copy_u16val , u8 copy_u8pin) ; 


/* ICR PIN SESNE */

#define  RISING     0 
#define  FALLING    1 
void TIM1_voidICRInit( u8 sense ) ; 

void TIM1_voidRestICR(void) ; 

u16 TIM1_u16ReadICR(void) ; 


void TIM1_voidICR_SetCallBack(void (*ptr)(void)) ; 







#endif /* TIM1_INTERFACE_H_ */


/*



 20 ms  = ocr *  8 / 16  = 
 
 
 ocr = 20 *10 ^-3 *16 *1^ 6   / 8   = 40000 




*/