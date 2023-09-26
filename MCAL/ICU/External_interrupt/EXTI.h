/*
 * EXTI.h
 *
 *  Created on: Aug 26, 2023
 *      Author: Mostafa Hisham
 */

#ifndef MCAL_EXTI_H_
#define MCAL_EXTI_H_

/* Set Sense Control */

typedef enum{
	RAISING_EDGE,
	FALLING_EDGE,
	LOW_LEVEL,
	ON_CHANGE
}Sense_Control;

typedef enum
{
	INTERRUPT_0,
	INTERRUPT_1,
	INTERRUPT_2
} Interrupt_Number;

void EXTI_Int0Init(Sense_Control Sense);
void EXTI_Int1Init(Sense_Control Sense);
void EXTI_Int2Init(Sense_Control Sense);
void EXTI_Disable(Interrupt_Number number);
void ISR0_SendAddress(void (*Int0)(void));
void ISR1_SendAddress(void(*Int1)(void));
void ISR2_SendAddress(void(*Int2)(void));



#endif /* MCAL_EXTI_H_ */
