/*********************************************************************
****************************  Encabezado  ****************************
**********************************************************************
* Número del ejercicio	: Ejemplo 4E-3
* Nombre del ejercicio	: Faded
* Autor(es)				: Ignacio Rangel Fuerte
* Asignatura			: Circuitos Digitales
* Grupo					:
* Tema					: Programación de Microcontroladores
* Subtema				: Modulación por ancho de pulso (PWM)
* Fecha de entrega		:

* Descripción:
	Diseñar un programa en lenguaje C con controladores CMSIS que
	haga que aumente y disminuya sucesivamente la intensidad de brillo
	de un LED conectado a una salida PWM del puerto A.
	Seleccione una frecuencia y resolución adecuados para LEDs.

* Microcontrolador:
	- Núcleo del microcontrolador	: ARM Cortex M4
	- Matrícula del microcontrolador: STM32F411CEU6
	- Tarjeta de desarrollo			: BlackPill v3.1

* Notas:
	- LED1 en A8

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
#define CTmax 	1000
#define retardo 1	//[ms]

/******************* Variables globales de proceso ******************/

/***************** Prototipos de funciones a utilizar ***************/

/************************ Programa principal ************************/
int main(void){
/*------------------ Variables locales de proceso ------------------*/

/*-------------- Configuración de periféricos (SETUP) --------------*/
	GPIOA_Config();
	TIM1_Config();

/*--------------------- Ciclo infinito (LOOP) ----------------------*/
	while(1){
		for(uint16_t i = 0; i < CTmax; i++){
			TIM1->CCR1 = i;
			delay_ms(retardo);
		}

		for(uint16_t i = CTmax; i > 0; i--){
			TIM1->CCR1 = i;
			delay_ms(retardo);
		}
	}
}

/************* Desarrollo de los prototipos de funciones ************/

/************* Desarrollo de las rutinas de interrupción ************/

//====================================================================


