/*
 * dio.h
 *
 *  Created on: July 29, 2022
 *      Author: John Atia Nafady
 */

#ifndef _DIO_H_
#define _DIO_H_

#include "../../common/STD_Types.h"
#include "DIO_types.h"

/*=========================================
 * FUNCTIONS PROTOTYPES
 =========================================*/
STD_levelType Dio_ReadChannel(Dio_ChannelType ChannelId);
void Dio_WriteChannel(Dio_ChannelType ChannelId, STD_levelType Level);
uint8 Dio_ReadPort(Dio_PortType PortId );
void Dio_WritePort( Dio_PortType PortId, uint8 Level);
void Dio_ToggleChannel( Dio_ChannelType ChannelId);
void Dio_TogglePort(Dio_PortType PortId);



#endif /* _DIO_H_ */
