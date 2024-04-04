/*
 * timerP.c
 *
 *  Created on: Apr 4, 2024
 *      Author: user
 */
#include "timerP.h"

void TimerInit(void){

// enable clk
	RCC->APB1ENR |= RCC_APB1ENR_TIM7EN ;
// set prescalar
	TIM7->PSC = TIM_PR-1;
}


void TimerDelayMs(uint32_t ms){

// no. of count
	uint16_t cnt = (TCLK/1000)*ms/TIM_PR;
// set arr
	TIM7->ARR = cnt-1;
//start count from 0
	TIM7->CNT = 0;
//set timer counter
	TIM7->CR1 |= TIM_CR1_CEN;
//wait for uif
	while((TIM7->SR & TIM_SR_UIF) == 0)
		;
//clear uif
	TIM7->SR &= ~(TIM_SR_UIF);
//disable timer counter
	TIM7->CR1 &= ~(TIM_CR1_CEN);
}



