/*
 * Config_Perif.c
 *
 *  Created on: Oct 14, 2025
 *      Author: ignacio
 */

#include "stm32f4xx.h"
#include "TIMx_Config.h"

/************* Desarrollo de los prototipos de funciones ************/
void TIM1_Config(void){
	RCC->APB2ENR |= RCC_APB2ENR_TIM1EN;

    TIM1->CR1 = 0;
    TIM1->CR2 = 0;

    TIM1->PSC = 7;
    TIM1->ARR = 1000 - 1;

    // Canal 1 de TIM1 en modo 1 de PWM
    TIM1->CCMR1 &= ~(TIM_CCMR1_OC1M | TIM_CCMR1_CC1S);
    TIM1->CCMR1 |=  (6UL << TIM_CCMR1_OC1M_Pos); // PWM1 mode
    TIM1->CCMR1 |=  TIM_CCMR1_OC1PE;             // Enable preload

    TIM1->CCR1 = 0;
    TIM1->CCER |= TIM_CCER_CC1E;// Habilitar salida del canal 1

    TIM1->CR1 |= TIM_CR1_ARPE;	// Habilitar auto-reload preload
    TIM1->BDTR |= TIM_BDTR_MOE;	//Habilitar salida principal TIM1
    TIM1->CR1 |= TIM_CR1_CEN;	// Iniciar contador
}

void TIM2_Config(void){

}

void TIM3_Config(void){

}

void TIM4_Config(void){

}

void TIM5_Config(void){

}

void TIM9_Config(void){

}

void TIM10_Config(void){

}

void TIM11_Config(void){

}
