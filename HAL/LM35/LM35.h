/*
 * LM35.h
 *
 *  Created on: Sep 14, 2023
 *      Author: Mostafa Hisham
 *      Layer : HAL
 *      SWC   : LM35 SENSOR - PROTOTYPE
 */

#ifndef LM35_H_
#define LM35_H_


u8 LM35_ReadingSynchronous(void);
void LM35_ReadingAsynchronous(void);
#endif /* LM35_H_ */
