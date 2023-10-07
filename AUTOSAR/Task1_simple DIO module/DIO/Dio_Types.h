/*****************************************************************************
* Description: This file contains typedefs for DIO module
*              channels and ports.
* Author:     Mohamed Gamal
* Version:     v0.1
*****************************************************************************/
#ifndef DIO_TYPES_H_
#define DIO_TYPES_H_

#include <stdint.h>

/* Definition of Dio_ChannelType as an 8-bit unsigned integer */
typedef uint8_t Dio_ChannelType;

/* Definition of Dio_PortType as an 8-bit unsigned integer */
typedef uint8_t Dio_PortType;

/* Definition of a structure Dio_ChannelGroupType */
typedef struct
{
    uint8_t mask;         /* Bit mask for the channel group */
    uint8_t offset;       /* Bit offset within the port */
    Dio_PortType PortIndex; /* Index of the port */
} Dio_ChannelGroupType;

/* Definition of Dio_LevelType as an 8-bit unsigned integer */
typedef uint8_t Dio_LevelType;

/* Definition of Dio_PortLevelType as an 8-bit unsigned integer */
typedef uint8_t Dio_PortLevelType;

#endif
