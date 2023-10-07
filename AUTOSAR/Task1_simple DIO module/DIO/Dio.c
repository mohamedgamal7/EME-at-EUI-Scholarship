/*****************************************************************************
* Description: This file contains functions for reading and writing GPIO
*              channels and ports.
* Author:     Mohamed Gamal
* Version:     v0.1
*****************************************************************************/

#include <DIO/Dio.h>

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
Dio_LevelType Dio_ReadChannel(Dio_ChannelType ChannelId)
{
    /* Pointer to the address of the chosen port */
    volatile uint32_t * PortPtr;

    /* Check if ChannelId is within the available range */
    if (ChannelId < AVAILABLE_CHANNELS)
    {
        switch (ChannelId / PORT_PINS)
        {
        case 0:
            PortPtr = &GPIO_PORTA_DATA_R;
            break;
        case 1:
            PortPtr = &GPIO_PORTB_DATA_R;
            break;
        case 2:
            PortPtr = &GPIO_PORTC_DATA_R;
            break;
        case 3:
            PortPtr = &GPIO_PORTD_DATA_R;
            break;
        case 4:
            PortPtr = &GPIO_PORTE_DATA_R;
            break;
        case 5:
            PortPtr = &GPIO_PORTF_DATA_R;
            break;
        default:
            break;
        }
    }
    else
    {
        /* ChannelId is out of range */
        /* MISRA C:2004 Rule 14.9 - Empty statement for compliance */
        /* For MISRA C compliance, this section should be further addressed */
    }

    return (*PortPtr) >> (ChannelId % PORT_PINS) & 1;
}

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
void Dio_WriteChannel(Dio_ChannelType ChannelId, Dio_LevelType Level)
{
    /* Pointer to the address of the current port */
    volatile uint32_t * PortPtr;

    /* Check if ChannelId is within the available range */
    if (ChannelId < AVAILABLE_CHANNELS)
    {
        switch (ChannelId / PORT_PINS)
        {
        case 0:
            PortPtr = &GPIO_PORTA_DATA_R;
            break;
        case 1:
            PortPtr = &GPIO_PORTB_DATA_R;
            break;
        case 2:
            PortPtr = &GPIO_PORTC_DATA_R;
            break;
        case 3:
            PortPtr = &GPIO_PORTD_DATA_R;
            break;
        case 4:
            PortPtr = &GPIO_PORTE_DATA_R;
            break;
        case 5:
            PortPtr = &GPIO_PORTF_DATA_R;
            break;
        default:
            break;
        }
    }
    else
    {
        /* ChannelId is out of range */
        /* MISRA C:2004 Rule 14.9 - Empty statement for compliance */
        /* For MISRA C compliance, this section should be further addressed */
    }

    if (Level == STD_HIGH)
    {
        *PortPtr |= (1 << (ChannelId % PORT_PINS));
    }
    else
    {
        *PortPtr &= ~(1 << (ChannelId % PORT_PINS));
    }
}
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
Dio_PortLevelType Dio_ReadPort(Dio_PortType PortId)
{
    /* Pointer to the address of the chosen port */
    volatile uint32_t * PortPtr;

    /* Check if PortId is within the available range */
    if (PortId < AVAILABLE_PORTS)
    {
        switch (PortId)
        {
        case 0:
            PortPtr = &GPIO_PORTA_DATA_R;
            break;
        case 1:
            PortPtr = &GPIO_PORTB_DATA_R;
            break;
        case 2:
            PortPtr = &GPIO_PORTC_DATA_R;
            break;
        case 3:
            PortPtr = &GPIO_PORTD_DATA_R;
            break;
        case 4:
            PortPtr = &GPIO_PORTE_DATA_R;
            break;
        case 5:
            PortPtr = &GPIO_PORTF_DATA_R;
            break;
        default:
            break;
        }
    }
    else
    {
        /* PortId is out of range */
        /* MISRA C:2004 Rule 14.9 - Empty statement for compliance */
        /* For MISRA C compliance, this section should be further addressed */
    }

    return *PortPtr;
}

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
void Dio_WritePort(Dio_PortType PortId, Dio_PortLevelType Level)
{
    /* Pointer to the address of the chosen port */
    volatile uint32_t * PortPtr;

    /* Check if PortId is within the available range */
    if (PortId < AVAILABLE_PORTS)
    {
        switch (PortId)
        {
        case 0:
            PortPtr = &GPIO_PORTA_DATA_R;
            break;
        case 1:
            PortPtr = &GPIO_PORTB_DATA_R;
            break;
        case 2:
            PortPtr = &GPIO_PORTC_DATA_R;
            break;
        case 3:
            PortPtr = &GPIO_PORTD_DATA_R;
            break;
        case 4:
            PortPtr = &GPIO_PORTE_DATA_R;
            break;
        case 5:
            PortPtr = &GPIO_PORTF_DATA_R;
            break;
        default:
            break;
        }
    }
    else
    {
        /* PortId is out of range */
        /* MISRA C:2004 Rule 14.9 - Empty statement for compliance */
        /* For MISRA C compliance, this section should be further addressed */
    }

    if (Level == STD_HIGH)
    {
        *PortPtr = 0xFF;
    }
    else
    {
        *PortPtr = 0x00;
    }
}
