/*
 * TWI_Private.h
 *
 *  Created on: Aug 30, 2023
 *      Author: Mostafa Hisham
 */

#ifndef TWI_PRIVATE_H_
#define TWI_PRIVATE_H_

#define START_ACK				0X08
#define REP_START_ACK			0X10
#define SLAVE_ADD_AND_WR_ACK	0X18
#define SLAVE_ADD_AND_RD_ACK	0X40
#define MSTR_WR_BYTE_ACK		0X28
#define MSTR_RD_BYTE_WITH_ACK 	0X50
#define MSTR_RD_BYTE_WITH_NACK	0X58
#define SLAVE_ADD_RCVD_RD_REQ	0XA8
#define SLAVE_ADD_RCVD_WR_REQ	0X60
#define SLAVE_DATA_RECEIVED		0X80
#define SLAVE_BYTE_TRANSMITTED	0XB8


#define TWCR_TWINT		7
#define TWCR_TWEA		6
#define TWCR_TWSTA 		5
#define TWCR_TWSTO		4
#define TWCR_TWWC 		3
#define TWCR_TWEN		2
#define TWCR_TWIE		0


#define TWAR_TWGCE		0


#define TWSR_TWPS0		0
#define TWSR_TWPS1		1
#endif /* TWI_PRIVATE_H_ */
