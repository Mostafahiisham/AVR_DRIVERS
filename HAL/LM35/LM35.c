/*
 * LM35.c
 *
 *  Created on: Sep 14, 2023
 *      Author: Mostafa Hisham
 * 		Layer : HAL
 * 		SWC   : LM35 SENSOR - IMPLEMENTATION
 */
#include<Std_Types.h>
#include<ADC.h>
#include<LM35.h>
#include<LM35_Confg.h>

static u16 LM35_READING ;
static void LM35_NotificationFunction(void);

u8 LM35_ReadingSynchronous(void)
{
	u8 *temprature;
	u16 millivolt;
	ADC_AnalogReadSynchronous(LM35_Channel,&temprature);
	millivolt = ((u32)temprature*5000UL)/256UL;
	millivolt = millivolt/10;

	return millivolt;

}
static void LM35_NotificationFunction(void)
{
	u8 temprature;
	LM35_READING = ((u32)temprature*5000UL)/256UL;
	LM35_READING = LM35_READING /10;
}
void LM35_ReadingAsynchronous(void)
{
	ADC_AnalogReadASynchronous(LM35_Channel,&LM35_NotificationFunction,&LM35_READING);
}
