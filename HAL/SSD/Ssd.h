/*
 * Ssd.h
 *
 *  Created on: Aug 15, 2023
 *      Author: Mostafa Hisham
 *      Layer : HAL
 *       SWC  : SEVEN SEGMENT DISPLAY PROTOTYPE
 */

#ifndef HAL_SSD_H_
#define HAL_SSD_H_


#define COMMON_Cathode  1
#define COMMON_Anode    2

#define zero	0
#define one 	1
#define two 	2
#define three	3
#define four  	4
#define five 	5
#define six  	6
#define seven 	7
#define eight 	8
#define nine  	9

void SSD_Init(PORT_TYPE SSD_PORT);
void SSD_DisplayNumber(PORT_TYPE SSD_PORT,u8 number);
void SSD_TurnOff(PORT_TYPE SSD_PORT);
void SSD_UPCounter(PORT_TYPE SSD_PORT,u8 number);
void SSD_DOWNCounter(PORT_TYPE SSD_PORT,u8 number);

#endif /* HAL_SSD_H_ */
