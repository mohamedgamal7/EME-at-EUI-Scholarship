/********************************************************************************************/
/* Authors: Mohamed Gamal, Ehab Roushdy, Mohamed abelmoteleb, and Aya Yasser                */
/* Version: V01                                                                             */
/* Date: 10/09/2023                                                                         */
/* Description: General-Purpose Timer (GPTM) Register and Type Definitions                  */
/********************************************************************************************/

#ifndef GPTM_TYPES_H__
#define GPTM_TYPES_H__

#include "LIB/types.h"

/**
 * @brief Structure representing the GPTM registers.
 */
typedef struct {
    uint32 GPTMCFG;
    uint32 GPTMTAMR;
    uint32 GPTMTBMR;
    uint32 GPTMCTL;
    uint32 GPTMSYNC;
    uint32 RES;
    uint32 GPTMIMR;
    uint32 GPTMRIS;
    uint32 GPTMMIS;
    uint32 GPTMICR;
    uint32 GPTMTAILR;
    uint32 GPTMTBILR;
    uint32 GPTMTAMATCHR;
    uint32 GPTMTBMATCHR;
    uint32 GPTMTAPR;
    uint32 GPTMTBPR;
    uint32 GPTMTAPMR;
    uint32 GPTMTBPMR;
    uint32 GPTMTAR;
    uint32 GPTMTBR;
    uint32 GPTMTAV;
    uint32 GPTMTBV;
    uint32 GPTMRTCPD;
    uint32 GPTMTAPS;
    uint32 GPTMTBPS;
    uint32 GPTMTAPV;
    uint32 GPTMTBPV;
    uint32 GPTMPP;
} GPTMRegType;

/**
 * @brief Enumeration representing the timer types.
 */
typedef enum {
    NORMAL = 0,
    PWM
} TimerType;

#endif
