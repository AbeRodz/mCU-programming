/*
 * API_uart.h
 *
 *  Created on: Mar 28, 2024
 *      Author: rodz
 */

#ifndef API_INC_API_UART_H_
#define API_INC_API_UART_H_
#include "API_delay.h"
#include "stm32f4xx_hal_uart.h"


bool_t uartInit();
void uartSendString(uint8_t * pstring);
void uartSendStringSize(uint8_t * pstring, uint16_t size);
void uartReceiveStringSize(uint8_t * pstring, uint16_t size);


#endif /* API_INC_API_UART_H_ */
