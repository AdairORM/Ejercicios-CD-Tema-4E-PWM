/*
 * Config_Perif.c
 *
 *  Created on: Oct 14, 2025
 *      Author: ignacio
 */

#include "stm32f4xx.h"
#include "GPIO_Config.h"

/************* Desarrollo de los prototipos de funciones ************/
void GPIOA_Config(void){
	RCC->AHB1ENR = RCC_AHB1ENR_GPIOAEN;
    GPIOA->MODER &= ~(GPIO_MODER_MODER9 | GPIO_MODER_MODER8);
    GPIOA->MODER |= (GPIO_MODER_MODER8_1 | GPIO_MODER_MODER9_1);
    GPIOA->AFR[1] &= ~(GPIO_AFRH_AFSEL8 | GPIO_AFRH_AFSEL9);
    GPIOA->AFR[1] |=  GPIO_AFRH_AFSEL9_0;
    GPIOA->AFR[1] |=  GPIO_AFRH_AFSEL8_0;
    GPIOA->OSPEEDR |= (GPIO_OSPEEDR_OSPEED9 | GPIO_OSPEEDR_OSPEED8);
}

void GPIOB_Config(void){

}
