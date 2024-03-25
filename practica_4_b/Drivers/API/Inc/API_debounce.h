/*
 * API_debounce.h
 *
 *  Created on: Mar 21, 2024
 *      Author: rodz
 */

#ifndef API_INC_API_DEBOUNCE_H_
#define API_INC_API_DEBOUNCE_H_

#include "API_delay.h"


typedef enum{
BUTTON_UP,
BUTTON_FALLING,
BUTTON_DOWN,
BUTTON_RAISING,
} debounceState_t;


void debounceFSM_init();		// debe cargar el estado inicial
void debounceFSM_update();	// debe leer las entradas, resolver la lógica de
					// transición de estados y actualizar las salidas
void buttonPressed();			// debe encender el LED
void buttonReleased();		// debe apagar el LED


bool_t readKey();

#endif /* API_INC_API_DEBOUNCE_H_ */
