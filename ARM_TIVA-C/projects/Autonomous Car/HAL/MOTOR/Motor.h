/********************************************************************************************/
/* Authors: Mohamed Gamal, Ehab Roushdy, Mohamed abelmoteleb and Aya Yasse                  */
/* Version: V01                                                                             */
/* Date: 10/09/2023                                                                         */
/* Description: Motor driver Header file                                                    */
/********************************************************************************************/
#ifndef MOTOR_H
#define MOTOR_H



/*Functions prototypes*/

/********************************************************************************************/
/* Function: MotorInit                                                                     */
/* Description: Initializes the motor control system. This function sets up any necessary    */
/*              configurations and initializes the motor control hardware or software        */
/*              components. It should be called once before using any other motor control    */
/*              functions.                                                                  */
/********************************************************************************************/
void MotorInit(void);

/********************************************************************************************/
/* Function: MotorForward                                                                 */
/* Description: Moves the motor forward at a specified speed percentage. The 'percent'       */
/*              parameter determines the motor speed, with 0% indicating no movement and     */
/*              100% indicating full speed forward. This function controls the motor to      */
/*              move in a forward direction.                                                 */
/* Arguments:                                                                              */
/*   - percent: Speed percentage for forward movement (0-100).                              */
/********************************************************************************************/
void MotorForward(unsigned char percent);

/********************************************************************************************/
/* Function: MotorTurnRight                                                               */
/* Description: Turns the motor to the right at a specified speed percentage. The 'percent' */
/*              parameter determines the motor speed, with 0% indicating no turning and     */
/*              100% indicating a full-speed right turn. This function is used for           */
/*              controlling the motor to turn to the right.                                 */
/* Arguments:                                                                              */
/*   - percent: Speed percentage for right turn (0-100).                                    */
/********************************************************************************************/
void MotorTurnRight(unsigned char percent);

/********************************************************************************************/
/* Function: MotorTurnLeft                                                                */
/* Description: Turns the motor to the left at a specified speed percentage. The 'percent'  */
/*              parameter determines the motor speed, with 0% indicating no turning and     */
/*              100% indicating a full-speed left turn. This function is used for controlling*/
/*              the motor to turn to the left.                                              */
/* Arguments:                                                                              */
/*   - percent: Speed percentage for left turn (0-100).                                    */
/********************************************************************************************/
void MotorTurnLeft(unsigned char percent);

/********************************************************************************************/
/* Function: MotorBackward                                                                */
/* Description: Moves the motor backward at a specified speed percentage. The 'percent'      */
/*              parameter determines the motor speed, with 0% indicating no movement and     */
/*              100% indicating full-speed backward movement. This function controls the    */
/*              motor to move in a backward direction.                                      */
/* Arguments:                                                                              */
/*   - percent: Speed percentage for backward movement (0-100).                             */
/********************************************************************************************/
void MotorBackward(unsigned char percent);

/********************************************************************************************/
/* Function: MotorStop                                                                    */
/* Description: Stops the motor. This function is used to halt the motor's movement and      */
/*              bring it to a complete stop.                                                */
/********************************************************************************************/
void MotorStop(void);

#endif
