/*
 * EXTI.c
 *
 *  Created on: Aug 26, 2023
 *      Author: Mostafa Hisham
 */

#include<Std_Types.h>
#include<Macros.h>
#include<Registers.h>
#include<EXTI_Private.h>
#include<EXTI.h>

void(*INT0_CallBack)(void) = NULL;
void(*INT1_CallBack)(void) ;
void(*INT2_CallBack)(void) ;
void ISR0_SendAddress(void (*Int0)(void))
{
	if(Int0 != NULL)
	{
		INT0_CallBack = Int0;
	}
}
void ISR1_SendAddress(void (*Int1)(void))
{
		INT1_CallBack = Int1;
}
void ISR2_SendAddress(void (*Int2)(void))
{
		INT2_CallBack = Int2;
}
void __vector_1(void) __attribute__((signal));
void __vector_1(void)
{
	INT0_CallBack();
}

void __vector_2(void) __attribute__((signal));
void __vector_2(void)
{
	INT1_CallBack();
}

void __vector_3(void) __attribute__((signal));
void __vector_3(void)
{
	INT2_CallBack();
}
void EXTI_Int0Init(Sense_Control Sense)
{
	/* sense of interrupt 0 */
#if Sense == RAISING_EDGE
	SET_BIT(MCUCR,MCUCR_ISC00);
	SET_BIT(MCUCR,MCUCR_ISC01);
#elif Sense == FALLING_EDGE
	CLR_BIT(MCUCR,MCUCR_ISC00);
	SET_BIT(MCUCR,MCUCR_ISC01);
#elif (Sense == LOW_LEVEL)
	CLR_BIT(MCUCR,MCUCR_ISC00);
	CLR_BIT(MCUCR,MCUCR_ISC01);
#elif (Sense == ON_CHANGE)
	SET_BIT(MCUCR,MCUCR_ISC00);
	CLR_BIT(MCUCR,MCUCR_ISC01);
#else
	#error "UnDeclared Sense Type for Interrupt 0"
#endif
	/* EXTERNAL INTERRUPT 0 ENABLE */
	SET_BIT(GICR,INT0);
}
void EXTI_Int1Init(Sense_Control Sense)
{
	/* set sense of interrupt 1 */
#if Sense == RAISING_EDGE
	SET_BIT(MCUCR,MCUCR_ISC10);
	SET_BIT(MCUCR,MCUCR_ISC11);
#elif Sense == FALLING_EDGE
	CLR_BIT(MCUCR,MCUCR_ISC10);
	SET_BIT(MCUCR,MCUCR_ISC11);
#elif (Sense == LOW_LEVEL)
	CLR_BIT(MCUCR,MCUCR_ISC10);
	CLR_BIT(MCUCR,MCUCR_ISC11);
#elif (Sense == ON_CHANGE)
	SET_BIT(MCUCR,MCUCR_ISC10);
	CLR_BIT(MCUCR,MCUCR_ISC11);
#else
	#error "UnDeclared Sense Type for Interrupt 1"
#endif
	/*EXTERNAL INTERRUPT 1 ENABLE */
	SET_BIT(GICR,INT1);
}
void EXTI_Int2Init(Sense_Control Sense)
{
	/* set sense of interrupt 2 */
#if Sense == RAISING_EDGE
	SET_BIT(MCUCSR,MCUCSR_ISC2);
#elif Sense == FALLING_EDGE
	CLR_BIT(MCUCSR,MCUCSR_ISC2);
#else
	#error 	"UnDeclared Sense Type for Interrupt 2"
#endif
	/*EXTERNAL INTERRUPT 2 ENABLE */
	SET_BIT(GICR,INT2);
}
void EXTI_Disable(Interrupt_Number number)
{
	/* Enable peripheral interrupt flag */
#if number == INTERRUPT_0
	CLR_BIT(GICR,INT0);
#elif number == INTERRUPT_1
	CLR_BIT(GICR,INT1);
#elif number == INTERRUPT_2
	CLR_BIT(GICR,INT2);

#endif
}



