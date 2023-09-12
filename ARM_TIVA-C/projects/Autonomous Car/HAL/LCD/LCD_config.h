
/********************************************************************************************/
/* File: LCD_Config.h                                                                       */
/* Authors: Mohamed Gamal, Ehab Roushdy, Mohamed abelmoteleb, and Aya Yasser                */
/* Version: V01                                                                             */
/* Date: 10/09/2023                                                                         */
/* Description: Configuration Header File for the LCD Module.                               */
/********************************************************************************************/
#ifndef LCD_CONFIG_H
#define LCD_CONFIG_H

#include "LIB/types.h"

/* Data Mode Configuration */
#define LCD_DATA_MODE       MODE_4_BIT /**< LCD data mode configuration (4-bit or 8-bit). */

/* LCD Data Pin Configurations */
static uint8 dataPin0Pin = PIN5;      /**< Data Pin 0 (DB0) pin configuration. */
static uint8 dataPin0Port = PORTE;    /**< Data Pin 0 (DB0) port configuration. */

static uint8 dataPin1Pin = PIN4;      /**< Data Pin 1 (DB1) pin configuration. */
static uint8 dataPin1Port = PORTE;    /**< Data Pin 1 (DB1) port configuration. */

static uint8 dataPin2Pin = PIN1;      /**< Data Pin 2 (DB2) pin configuration. */
static uint8 dataPin2Port = PORTB;    /**< Data Pin 2 (DB2) port configuration. */

static uint8 dataPin3Pin = PIN2;      /**< Data Pin 3 (DB3) pin configuration. */
static uint8 dataPin3Port = PORTD;    /**< Data Pin 3 (DB3) port configuration. */

/* LCD Control Pin Configurations */
static uint8 rsPin = PIN4;            /**< Register Select (RS) pin configuration. */
static uint8 rsPort = PORTB;          /**< Register Select (RS) port configuration. */

static uint8 rwPin = PIN5;            /**< Read/Write (RW) pin configuration. */
static uint8 rwPort = PORTA;          /**< Read/Write (RW) port configuration. */

static uint8 enPin = PIN6;            /**< Enable (EN) pin configuration. */
static uint8 enPort = PORTA;          /**< Enable (EN) port configuration. */

#endif /*LCD_CONFIG_H*/
