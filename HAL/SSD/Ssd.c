/*
 * Ssd.c
 *
 *  Created on: Aug 15, 2023
 *      Author: Mostafa Hisham
 *      Layer : HAL
 * 		SWC	  : SEVEN SEGMENT DISPLAY IMPLEMENTATON
 */
#include<Std_Types.h>
#include<Registers.h>
#include<Macros.h>
#include<DIO.h>
#include<Ssd.h>
#include<Ssd_Confg.h>
#include<util/delay.h>

static const u8 SSD[10]={
		//		   gfedcba
				0b00111111,//0
				0b00000110,//1
				0b01011011,//2
				0b01001111,//3
				0b01100110,//4
				0b01101101,//5
				0b01111101,//6
				0b00000111,//7
				0b01111111,//8
				0b01101111//9
};
void SSD_Init(PORT_TYPE SSD_PORT)
{
	DIO_SetPortDirection(SSD_PORT,PORT_MODE_OUTPUT);
}
void SSD_DisplayNumber(PORT_TYPE SSD_PORT, u8 number)
{
	if(number <= 9)
	{
#if SSD_TYPE == 1
DIO_SetPortLevel(SSD_PORT,SSD[number]);
#elif SSD_TYPE ==2
DIO_SetPortLevel(SSD_PORT,~SSD[number]);
#else
	#error INVALID SSD TYPE
#endif
	}
}
void SSD_TurnOff(PORT_TYPE SSD_PORT)
{
#if SSD_TYPE == 1
	DIO_SetPortLevel(SSD_PORT,PORT_LEVEL_LOW);
#elif SSD_TYPE == 2
	DIO_SetPortLevel(SSD_PORT,PORT_LEVEL_HIGH);
#else
	#error INVALID SSD TYPE
#endif
}
void SSD_UPCounter(PORT_TYPE SSD_PORT,u8 number)
{

	if(number  <=  9)
	{
	for(u8 counter = number ; counter <= 9 ; counter++)
		{
		SSD_DisplayNumber(SSD_PORT,counter);
		_delay_ms(1000);
		}
	}
}
void SSD_DOWNCounter(PORT_TYPE SSD_PORT,u8 number)
{
	if(number  <=  9)
	{
	for(u8 counter = 9 ; counter >= number ; counter--)
		{
		SSD_DisplayNumber(SSD_PORT,counter);
		_delay_ms(1000);
		}
	}
}

