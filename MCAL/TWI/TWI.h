/*
 * TWI.h
 *
 *  Created on: Aug 30, 2023
 *      Author: Mostafa Hisham
 */

#ifndef TWI_H_
#define TWI_H_

typedef enum
{
	NoError,
	StartConditionError,
	RepeatedStartError,
	SlaveAddressWithWriteError,
	SlaveAddressWithReadError,
	MasterWriteByteError,
	MasterReadByteError,

}TWI_ERrStatus;

/* pass 0 in slave address argument if master will be addressed*/
void TWI_MasterInit(u8 Salve_Address);

void TWI_SlaveInit(u8 Slave_Address);

TWI_ERrStatus TWI_SendStartCondition(void);

TWI_ERrStatus TWI_SendRepeatedStart(void);

TWI_ERrStatus TWI_SendSlaveAddressWithWrite(u8 Slave_Address);

TWI_ERrStatus TWI_SendSlaveAddressWithRead(u8 Slave_Address);

TWI_ERrStatus TWI_MasterWriteDataByte(u8 Data_Byte);

TWI_ERrStatus TWI_MasterReadDataByte(u8 *Data_Byte_Read);

void TWI_SendStopCondition(void);

#endif /* TWI_H_ */
