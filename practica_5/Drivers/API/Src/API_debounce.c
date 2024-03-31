/*
 * API_debounce.c
 *
 *  Created on: Mar 21, 2024
 *      Author: rodz
 */



#include "API_debounce.h"
#include "API_uart.h"

static debounceState_t state;

static delay_t debounce_delay;

static bool_t key_state = false;


void debounceFSM_init(void){
	state = BUTTON_UP;
}

void debounceFSM_update(void){
	delayInit(&debounce_delay, 40);

	switch (state){
	case BUTTON_UP:
		if (BSP_PB_GetState(BUTTON_USER)){
			state = BUTTON_FALLING;
		}
		break;


	case BUTTON_FALLING:
		uartSendString((uint8_t*)"falling...");
		delayRead(&debounce_delay);
		if (BSP_PB_GetState(BUTTON_USER)){
			state = BUTTON_DOWN;
			key_state = true;
			buttonPressed();
		}else {
			state = BUTTON_UP;
		}
		break;

	case BUTTON_DOWN:
		if(!BSP_PB_GetState(BUTTON_USER)){
			state = BUTTON_RAISING;

		}
		break;

	case BUTTON_RAISING:
		uartSendString((uint8_t*)"raising...");
		delayRead(&debounce_delay);
		if (!BSP_PB_GetState(BUTTON_USER)){
			state = BUTTON_UP;
			buttonReleased();
		}else {
			state = BUTTON_DOWN;
		}
		break;
	}
}

void buttonPressed(void){
	BSP_LED_On(LED1);

}
void buttonReleased(void){
	BSP_LED_Off(LED1);
}

bool_t readKey(){

	if (key_state){
		key_state = false;
		return true;
	}else {
		return false;
	}
}


