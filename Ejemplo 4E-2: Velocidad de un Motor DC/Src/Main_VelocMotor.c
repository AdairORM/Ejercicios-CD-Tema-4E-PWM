/*********************************************************************
****************************  Encabezado  ****************************
**********************************************************************
* Número del ejercicio	: Ejemplo 4E-1
* Nombre del ejercicio	: Intensidad de un LED
* Autor(es)				: Ignacio Rangel Fuerte
* Asignatura			: Circuitos Digitales
* Grupo					:
* Tema					: Programación de Microcontroladores
* Subtema				: Modulación por ancho de pulso (PWM)
* Fecha de entrega		:

* Descripción:
	Desarrollar un programa en lenguaje C con controladores CMSIS,
	que encienda un motor DC a la mitad de su velocidad, al presionar
	un pulsador, y a máxima velocidad, al presionar el mismo pulsador,
	una segunda vez. Al presionar nuevamente el botón, el motor regresa
	a su estado de reposo (motor apagado). Hacer uso de la interrupción
	externa para el botón pulsador.

* Microcontrolador:
	- Núcleo del microcontrolador	: ARM Cortex M4
	- Matrícula del microcontrolador: STM32F411CEU6
	- Tarjeta de desarrollo			: BlackPill v3.1

* Notas:
	- LED1 en A8
	- BT1 en B1

====================================================================*/

/*********************************************************************
*****************************  Programa  *****************************
*********************************************************************/

/********************** Bibliotecas a utilizar **********************/
#include "stm32f4xx.h"
#include "GPIO_Config.h"
#include "EXTI_Config.h"
#include "TIMx_Config.h"
#include "Funciones.h"

/********************* Constantes de compilador *********************/

/******************* Variables globales de proceso ******************/
uint8_t MOD = 0;

/***************** Prototipos de funciones a utilizar ***************/

/************************ Programa principal ************************/
int main(void){
/*------------------ Variables locales de proceso ------------------*/

/*-------------- Configuración de periféricos (SETUP) --------------*/
	GPIOA_Config();
	GPIOB_Config();
	EXTI1_Config();
	TIM1_Config();

/*--------------------- Ciclo infinito (LOOP) ----------------------*/
	while(1){

	}
}

/************* Desarrollo de los prototipos de funciones ************/

/************* Desarrollo de las rutinas de interrupción ************/
void EXTI1_IRQHandler(void){
    if(MOD == 0){
        TIM1->CCR1 = 200;
        MOD = 1;
    }
    else if(MOD == 1){
        TIM1->CCR1 = 400;
        MOD = 2;
    }
    else{
        TIM1->CCR1 = 0;
        MOD = 0;
    }
	EXTI->PR |= EXTI_PR_PR1;
}
//====================================================================


