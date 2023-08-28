
/*Author:      Mohamed Gamal Roushdy                                                                      
  Version:     V01                                                                       
  Date:        23/08/2023                                                                             
  Description: EXTI driver configuration file                                 
*/

#ifndef _EXTI_CONFIG_H
#define _EXTI_CONFIG_H

/* detection MODE */
#define DETECTION_SEL  EDGE_DETECTION

/* single edge or both edges or no edges MODE */
#define EDGE_OR_EDGES  SINGLE_EDGE

/* RISING OR FALLING EDGE MODE */
#define EDGE_SEL FALLING_EDGE

/* interrupt number */
#define IN IN_PORTE



#endif

