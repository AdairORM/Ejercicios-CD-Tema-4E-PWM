/*********************************************************************
****************************  Encabezado  ****************************
**********************************************************************
* Número del ejercicio	: Ejemplo 4E-1
* Nombre del ejercicio	: Señales PWM
* Autor(es)				: Ignacio Rangel Fuerte
* Asignatura			: Circuitos Digitales
* Grupo					:
* Tema					: Programación de Microcontroladores
* Subtema				: Modulación por ancho de pulso (PWM)
* Fecha de entrega		:

* Descripción:
	Desarrollar un programa en lenguaje C con controladores CMSIS
	que encienda a un 10% de su intensidad un LED1 y al 75% un LED2
	de acuerdo con el esquema.
	La señal PWM debe tener una frecuencia de 2[kHz] y aproximadamente
	10 bits de resolución considerando que la frecuencia de oscilación
	de la señal de reloj del MCU es de 16[MHz].

* Microcontrolador:
	- Núcleo del microcontrolador	: ARM Cortex M4
	- Matrícula del microcontrolador: STM32F411CEU6
	- Tarjeta de desarrollo			: BlackPill v3.1

* Notas:
	- LED1 en A8
	- LED2 en A9

====================================================================*/

/*********************************************************************
*****************************  Programa  *****************************
*********************************************************************/

/********************** Bibliotecas a utilizar **********************/
#include "stm32f4xx.h"
#include "GPIO_Config.h"
#include "TIMx_Config.h"
#include "Funciones.h"

/********************* Constantes de compilador *********************/

/******************* Variables globales de proceso ******************/

/***************** Prototipos de funciones a utilizar ***************/

/************************ Programa principal ************************/
int main(void){
/*------------------ Variables locales de proceso ------------------*/

/*-------------- Configuración de periféricos (SETUP) --------------*/
	GPIOA_Config();
	TIM1_Config();

    TIM1->CCR1 = 100;	// Ciclo de trabajo al 10%
    TIM1->CCR2 = 750;	// Ciclo de trabajo al 75%

/*--------------------- Ciclo infinito (LOOP) ----------------------*/
	while(1){

	}
}

/************* Desarrollo de los prototipos de funciones ************/

/************* Desarrollo de las rutinas de interrupción ************/

//====================================================================


