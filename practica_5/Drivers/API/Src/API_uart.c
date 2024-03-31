/*
 * API_uart.c
 *
 *  Created on: Mar 28, 2024
 *      Author: rodz
 */

#include "API_uart.h"
#include <string.h>
UART_HandleTypeDef huart;

bool_t uartInit(){
	huart.Instance = USART3;
	huart.Init.BaudRate = 115200;
	huart.Init.WordLength = UART_WORDLENGTH_8B;
	huart.Init.StopBits = UART_STOPBITS_1;
	huart.Init.Parity = UART_PARITY_NONE;
	huart.Init.HwFlowCtl = UART_HWCONTROL_NONE;
	huart.Init.Mode  = UART_MODE_TX_RX;
	huart.Init.OverSampling = UART_OVERSAMPLING_16;

	HAL_StatusTypeDef status = HAL_UART_Init(&huart);
	if (status != HAL_OK){
		return false;
	}else{
		return true;
	}
}
void uartSendString(uint8_t * pstring){


	HAL_UART_Transmit(&huart, pstring, strlen((char*)pstring), HAL_MAX_DELAY);

}
void uartSendStringSize(uint8_t * pstring, uint16_t size){
	HAL_UART_Transmit(&huart, pstring, size, HAL_MAX_DELAY);
}

void uartReceiveStringSize(uint8_t * pstring, uint16_t size){

}
