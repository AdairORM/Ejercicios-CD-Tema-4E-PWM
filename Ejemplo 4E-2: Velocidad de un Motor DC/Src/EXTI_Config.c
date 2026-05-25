/*
 * EXTI_Config.c
 *
 *  Created on: Oct 16, 2025
 *      Author: ignacio
 */

#include "stm32f4xx.h"
#include "EXTI_Config.h"

/************* Desarrollo de los prototipos de funciones ************/

void EXTI1_Config(void){
	//EXTI en A1
	RCC->APB2ENR |= RCC_APB2ENR_SYSCFGEN;
	SYSCFG->EXTICR[0] &= ~SYSCFG_EXTICR1_EXTI1;
	SYSCFG->EXTICR[0] |= SYSCFG_EXTICR1_EXTI1_PB;
	EXTI->IMR |= EXTI_IMR_MR1;
	EXTI->RTSR &= ~EXTI_RTSR_TR1;
	EXTI->FTSR |= EXTI_FTSR_TR1;
	NVIC_EnableIRQ(EXTI1_IRQn);
	NVIC_SetPriority(EXTI1_IRQn,1);

}
