
/* Includes ------------------------------------------------------------------*/
#include "gw1ns4c.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void UartInit(void);
void Delay_ms(__IO uint32_t delay_ms);

int main()
{   
	SystemInit();
	UartInit();
	NVIC_EnableIRQ(UART0_IRQn); //enable uart0 interrupt

	UART_SendString(UART0, "This is Tang Nano 4k\r\n");

	while(1);
}

void Delay_ms(__IO uint32_t delay_ms)
{
	for(delay_ms=delay_ms*8500; delay_ms != 0; delay_ms--);
}

void UartInit(void)
{
	UART_InitTypeDef UART_InitStruct;
	
	UART_InitStruct.UART_Mode.UARTMode_Tx = ENABLE;
	UART_InitStruct.UART_Mode.UARTMode_Rx = ENABLE;
	UART_InitStruct.UART_Int.UARTInt_Tx   = DISABLE;
	UART_InitStruct.UART_Int.UARTInt_Rx   = ENABLE;
	UART_InitStruct.UART_Ovr.UARTOvr_Tx   = DISABLE;
	UART_InitStruct.UART_Ovr.UARTOvr_Rx   = DISABLE;
	UART_InitStruct.UART_Hstm             = DISABLE;
	UART_InitStruct.UART_BaudRate         = 115200;
	
	UART_Init(UART0, &UART_InitStruct);
}


void UART0_Handler(void)
{
	char rx_char;

	if (UART_GetRxBufferFull(UART0) == SET)
	{
		rx_char = UART_ReceiveChar(UART0);
		printf("rx_byte = %c\r\n", rx_char);
	}

	UART_ClearRxIRQ(UART0);
}
