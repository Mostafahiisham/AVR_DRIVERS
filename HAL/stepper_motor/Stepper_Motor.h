/*
 * Stepper_Motor.h
 *
 *  Created on: Aug 20, 2023
 *      Author: Mostafa Hisham
 *       Layer : HAL
 *       SWC   : STPPER MOTOR
 */

#ifndef HAL_STEPPER_MOTOR_H_
#define HAL_STEPPER_MOTOR_H_

void STEP_FULLStep_CW(u32 Degree_angle);
void STEP_FULLStep_CCW(u32 Degree_angle);
void STEP_HALFStep_CW(u32 Degree_angle);
void STEP_HALFStep_CCW(u32 Degree_angle);

#endif /* HAL_STEPPER_MOTOR_H_ */
