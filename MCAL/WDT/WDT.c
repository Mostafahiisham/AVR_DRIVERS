/*
 * WDT.c
 *
 *  Created on: Aug 28, 2023
 *      Author: Mostafa Hisham
 */
#include<Registers.h>
#include<Macros.h>
#include<Std_types.h>
#include<WDT.h>
#include<WDT_Private.h>


void WDT_Sleep(u8 Sleep_Time)
{
	WDTCR &= WDT_MASK;
	WDTCR |= Sleep_Time;
}
void WDT_Enable(void)
{
	SET_BIT(WDTCR,WDTCR_WDE);
}
void WDT_Disable(void)
{
	WDTCR |= 0b00011000;
	WDTCR = 0;
}
