/*
 * UltraSonic.h
 *
 *  Created on: Sep 21, 2023
 *      Author: Mostafa Hisham
 */

#ifndef ULTRASONIC_H_
#define ULTRASONIC_H_

typedef enum
{
	UltraSonic_1,
	UltraSonic_2,
	UltraSonic_3,
	UltraSonic_4
}UltraSonic_number;


void ULTRASONIC_Init(void);
u8 ULTRASONIC_ReadDistance(UltraSonic_number UltraSonic);

#endif /* ULTRASONIC_H_ */
