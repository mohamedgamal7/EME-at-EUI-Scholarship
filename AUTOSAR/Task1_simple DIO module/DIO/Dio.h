/*****************************************************************************
* Description: This file contains the interface for reading and writing GPIO
*              channels and ports on the Tiva C TM4C123GXL.
* Author:      Mohamed Gamal
* Version:     V0.1
*****************************************************************************/

#ifndef DIO_H
#define DIO_H

#include <DIO/Dio_Types.h>
#include "Std_Types.h"

/* Defines the number of available channels on Tiva C TM4C123GXL */
#define AVAILABLE_CHANNELS 48
/* Defines the number of pins in a port */
#define PORT_PINS 8
/* Defines the number of available ports on Tiva C TM4C123GXL */
#define AVAILABLE_PORTS 6

/* Registers definitions */
#define GPIO_PORTA_DATA_R (*((volatile uint32_t *)0x400043FC))
#define GPIO_PORTB_DATA_R (*((volatile uint32_t *)0x400053FC))
#define GPIO_PORTC_DATA_R (*((volatile uint32_t *)0x400063FC))
#define GPIO_PORTD_DATA_R (*((volatile uint32_t *)0x400073FC))
#define GPIO_PORTE_DATA_R (*((volatile uint32_t *)0x400243FC))
#define GPIO_PORTF_DATA_R (*((volatile uint32_t *)0x400253FC))

/*****************************************************************************
* Service name: Dio_ReadChannel
* Service ID[hex]: 0x01
* Sync/Async: Synchronous
* Reentrancy: Non-Reentrant
* Parameters (in): ChannelId - ID of the channel to be read
* Parameters (inout): None
* Parameters (out): None
* Return value: Dio_LevelType - Level of the specified channel
* Description: This function reads the state of a specific GPIO channel.
*****************************************************************************/
Dio_LevelType Dio_ReadChannel(Dio_ChannelType ChannelId);

/*****************************************************************************
* Service name: Dio_WriteChannel
* Service ID[hex]: 0x02
* Sync/Async: Synchronous
* Reentrancy: Non-Reentrant
* Parameters (in): ChannelId - ID of the channel to be written
*                  Level - Desired level (STD_HIGH or STD_LOW) to be written
* Parameters (inout): None
* Parameters (out): None
* Return value: None
* Description: This function writes a specified level to a GPIO channel.
*****************************************************************************/
void Dio_WriteChannel(Dio_ChannelType ChannelId, Dio_LevelType Level);

/*****************************************************************************
* Service name: Dio_ReadPort
* Service ID[hex]: 0x03
* Sync/Async: Synchronous
* Reentrancy: Non-Reentrant
* Parameters (in): PortId - ID of the port to be read
* Parameters (inout): None
* Parameters (out): None
* Return value: Dio_PortLevelType - Current level of the specified port
* Description: This function reads the state of a specific GPIO port.
*****************************************************************************/
Dio_PortLevelType Dio_ReadPort(Dio_PortType PortId);

/*****************************************************************************
* Service name: Dio_WritePort
* Service ID[hex]: 0x04
* Sync/Async: Synchronous
* Reentrancy: Non-Reentrant
* Parameters (in): PortId - ID of the port to be written
*                  Level - Desired level (STD_HIGH or STD_LOW) to be written
* Parameters (inout): None
* Parameters (out): None
* Return value: None
* Description: This function writes a specified level to a GPIO port.
*****************************************************************************/
void Dio_WritePort(Dio_PortType PortId, Dio_PortLevelType Level);

#endif /* DIO_H */
