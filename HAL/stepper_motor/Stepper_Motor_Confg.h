/*
 * Stepper_Motor_Confg.h
 *
 *  Created on: Aug 20, 2023
 *      Author: Mostafa Hisham
 *       Layer : HAL
 *       SWC   : STPPER MOTOR
 */

#ifndef HAL_STEPPER_MOTOR_CONFG_H_
#define HAL_STEPPER_MOTOR_CONFG_H_

#define SM_PORT DIO_PORTD


#define SM_PIN1  DIO_PIN0
#define SM_PIN2	 DIO_PIN1
#define SM_PIN3	 DIO_PIN2
#define SM_PIN4	 DIO_PIN3

/* Number of iterations in case of full step connection */

#define rotateFULLSTEP_360  512
#define	rotateFULLSTEP_180 	256
#define rotateFULLSTEP_90   128
#define rotateFULLSTEP_45   64
/* Number of iterations in case of half step connection*/

#define rotateHALFSTEP_360  256
#define	rotateHALFSTEP_180 	128
#define rotateHALFSTEP_90   64
#define rotateHALFSTEP_45	32
#endif /* HAL_STEPPER_MOTOR_CONFG_H_ */
