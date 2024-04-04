/*
 * timerP.h
 *
 *  Created on: Apr 4, 2024
 *      Author: user
 */

#ifndef TIMERP_H_
#define TIMERP_H_

#include "stm32f407xx.h"
#include "stm32f4xx.h"

#define TCLK  16000000
#define TIM_PR  16000

void TimerInit(void);
void TimerDelayMs(uint32_t ms);

#endif /* TIMERP_H_ */
