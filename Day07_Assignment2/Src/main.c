/**
 ******************************************************************************
 * @file           : main.c
 * @author         : Auto-generated by STM32CubeIDE
 * @brief          : Main program body
 ******************************************************************************
 * @attention
 *
 * Copyright (c) 2024 STMicroelectronics.
 * All rights reserved.
 *
 * This software is licensed under terms that can be found in the LICENSE file
 * in the root directory of this software component.
 * If no LICENSE file comes with this software, it is provided AS-IS.
 *
 ******************************************************************************
 */

#include <stdint.h>
#include <stdio.h>
#include <string.h>
#include "stm32f4xx.h"
#include "system_stm32f4xx.h"
#include "uart.h"
#include "led.h"

#if !defined(__SOFT_FP__) && defined(__ARM_FP)
  #warning "FPU is not initialized, but the project is compiling for an FPU. Please initialize the FPU before use."
#endif

int main(void)
{
	char ch;
	SystemInit();
	UartInit(BAUD_9600);
	LedInit(LED_RED);
	LedInit(LED_BLUE);
	while(1){
	UartPuts("0.Exit\r\n");
	UartPuts("1.Red LED On\r\n");
	UartPuts("2.Red LED Off\r\n");
	UartPuts("3.Blue LED On\r\n");
	UartPuts("4.Blue LED Off\r\n");
	UartPuts("Enter choice:\r\n");

	ch = UartGetch();
	//UartPuts(ch);

	//sscanf(str,"%d",&choice);
	switch(ch)
	{
	case '1':
		    LedOn(LED_RED);
		    break;
	case '2':
			LedOff(LED_RED);
			    break;
	case '3':
			LedOn(LED_BLUE);
			    break;
	case '4':
			LedOff(LED_BLUE);
			    break;
	}


	}
	return 0;
}
