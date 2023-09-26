/*
 * TWI.c
 *
 *  Created on: Aug 30, 2023
 *      Author: Mostafa Hisham
 */
#include<Std_Types.h>
#include<Registers.h>
#include<Macros.h>
#include<TWI.h>
#include<TWI_Private.h>


void TWI_MasterInit(u8 Slave_Address)
{
	/*set CLK FRQUENCY TO 400KBPS */
	/* TWBR TO 2*/
	TWBR = 2;
	/* clear to bits of TWPS*/
	CLR_BIT(TWSR,TWSR_TWPS0);
	CLR_BIT(TWSR,TWSR_TWPS1);
	/* initialize the node address */
	if(Slave_Address != 0)
	{
		TWAR = Slave_Address<<1;
	}
	/* TWI ENABLE */
	SET_BIT(TWCR,TWCR_TWEN);

}
void TWI_SlaveInit(u8 Slave_Address)
{
	/* initialize the node address */
	TWAR = Slave_Address<<1;
	/* TWI ENABLE */
		SET_BIT(TWCR,TWCR_TWEN);
}
TWI_ERrStatus TWI_SendStartCondition(void)
{
	TWI_ERrStatus Local_ErrorState = NoError;

	/* send start condition on the bus */
		SET_BIT(TWCR,TWCR_TWSTA);

	/* clear the interrupt flag to start the previous operation */
		SET_BIT(TWCR,TWCR_TWINT);
	/*WAIT UNTIL THE INTERRUPT FLAG IS RAISED AGAIN AND THE PREVIOUS OPERATION IS COMPLETE*/
		while((GET_BIT(TWCR,TWCR_TWINT))==0);

		if((TWSR & 0xF8) != START_ACK)
		{
			Local_ErrorState = StartConditionError;

		}
	return Local_ErrorState;
}

TWI_ERrStatus TWI_SendRepeatedStart(void)
{

	TWI_ERrStatus Local_ErrorState = NoError;

	/* send start condition on the bus */
		SET_BIT(TWCR,TWCR_TWSTA);

	/* clear the interrupt flag to start the previous operation */
		SET_BIT(TWCR,TWCR_TWINT);
	/*WAIT UNTIL THE INTERRUPT FLAG IS RAISED AGAIN AND THE PREVIOUS OPERATION IS COMPLETE*/
		while((GET_BIT(TWCR,TWCR_TWINT))==0);

		if((TWSR & 0xF8) != REP_START_ACK)
		{
			Local_ErrorState = RepeatedStartError;

		}
	return Local_ErrorState;
}


TWI_ERrStatus TWI_SendSlaveAddressWithWrite(u8 Slave_Address)
{
	TWI_ERrStatus Local_ErrorState = NoError;

	/* clear  the start condition bit */
	CLR_BIT(TWCR,TWCR_TWSTA);

	/*SET THE SLAVE ADDRESS IN THE  7 MSB IN THE DATA REGISTER*/
	TWDR =  Slave_Address<<1;
	/* FOR WRITE REQUEST */
	CLR_BIT(TWDR,0);
	/* clear the interrupt flag to start the previous operation */
		SET_BIT(TWCR,TWCR_TWINT);
	/*WAIT UNTIL THE INTERRUPT FLAG IS RAISED AGAIN AND THE PREVIOUS OPERATION IS COMPLETE*/
		while((GET_BIT(TWCR,TWCR_TWINT))==0);

		if((TWSR & 0xF8) != SLAVE_ADD_AND_WR_ACK)
		{
			Local_ErrorState = SlaveAddressWithWriteError;

		}




	return Local_ErrorState;
}
TWI_ERrStatus TWI_SendSlaveAddressWithRead(u8 Slave_Address)
{
	TWI_ERrStatus Local_ErrorState = NoError;

	/* clear  the start condition bit */
		CLR_BIT(TWCR,TWCR_TWSTA);

	/*SET THE SLAVE ADDRESS IN THE  7 MSB IN THE DATA REGISTER*/
	TWDR =  Slave_Address<<1;
	/* FOR READ REQUEST */
	SET_BIT(TWDR,0);
	/* clear the interrupt flag to start the previous operation */
	SET_BIT(TWCR,TWCR_TWINT);
	/*WAIT UNTIL THE INTERRUPT FLAG IS RAISED AGAIN AND THE PREVIOUS OPERATION IS COMPLETE*/
	while((GET_BIT(TWCR,TWCR_TWINT))==0);
	/* Check the operation status in the status register */
		if((TWSR & 0xF8) != SLAVE_ADD_AND_RD_ACK)
		{
		Local_ErrorState = SlaveAddressWithReadError;

		}



		return Local_ErrorState;
}

TWI_ERrStatus TWI_MasterWriteDataByte(u8 Data_Byte)
{

	TWI_ERrStatus Local_ErrorState = NoError;


	/* WRITE THE DATA BYTE */
	TWDR = Data_Byte;
	/* clear the interrupt flag to start the previous operation */
	SET_BIT(TWCR,TWCR_TWINT);

	/*WAIT UNTIL THE INTERRUPT FLAG IS RAISED AGAIN AND THE PREVIOUS OPERATION IS COMPLETE*/
	while((GET_BIT(TWCR,TWCR_TWINT))==0);

	/* Check the operation status in the status register */
	 	if((TWSR & 0xF8) != MSTR_WR_BYTE_ACK)
		{
		Local_ErrorState = MasterWriteByteError;
		}
		return Local_ErrorState;
}

TWI_ERrStatus TWI_MasterReadDataByte(u8 *Data_Byte_Read)
{

	TWI_ERrStatus Local_ErrorState = NoError;

	/*Enable master generate acknowledge bit after receiving data*/
	SET_BIT(TWCR,TWCR_TWEA);


	/* clear the interrupt flag to start the slave sending data */
		SET_BIT(TWCR,TWCR_TWINT);

		/*WAIT UNTIL THE INTERRUPT FLAG IS RAISED AGAIN AND THE PREVIOUS OPERATION IS COMPLETE*/
		while((GET_BIT(TWCR,TWCR_TWINT))==0);

		/* Check the operation status in the status register */
		 	if((TWSR & 0xF8) != MSTR_RD_BYTE_WITH_ACK)
			{
			Local_ErrorState = MasterReadByteError;
			}
		 	else
		 	{
		 		// READ THE RECEIVED DATA
		 		*Data_Byte_Read = TWDR;
		 	}

		return Local_ErrorState;
}

void TWI_SendStopCondition(void)
{
	/*generate stop condition on the bus */
	SET_BIT(TWCR,TWCR_TWSTO);

	/* clear the interrupt flag to start the slave sending data */
	SET_BIT(TWCR,TWCR_TWINT);
}
