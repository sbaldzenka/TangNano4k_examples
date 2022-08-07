/*
    author: sergey boldenko
    data  : 18.07.2022
*/

/* Includes ------------------------------------------------------------------*/
#include "gw1ns4c.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* Declarations ------------------------------------------------------------------*/
void delay_ms(__IO uint32_t delay_ms);
void UartInit(void);
void GPIOInit(void);

/* Functions ------------------------------------------------------------------*/
int main(void)
{
    int counter = 0;
    char scounter[256];

    SystemInit();   //Initializes system
    GPIOInit();	    //Initializes GPIO
    UartInit();     //Initializes UART

    while(1)
    {
        GPIO_ResetBit(GPIO0,GPIO_Pin_0);  //LED on
        delay_ms(500);

        GPIO_SetBit(GPIO0,GPIO_Pin_0);    //LED off
        delay_ms(500);

        itoa(counter, scounter, 10);

        printf("hello world! counter value = %s\n\r", &scounter);

        counter = counter + 1;
    }
}

//Initializes GPIO
void GPIOInit(void)
{
    GPIO_InitTypeDef GPIO_InitType;
    
    GPIO_InitType.GPIO_Pin  = GPIO_Pin_0;
    GPIO_InitType.GPIO_Mode = GPIO_Mode_OUT;
    GPIO_InitType.GPIO_Int  = GPIO_Int_Disable;

    GPIO_Init(GPIO0,&GPIO_InitType);

    GPIO_SetBit(GPIO0,GPIO_Pin_0);
}

//delay ms
void delay_ms(__IO uint32_t delay_ms)
{
    for(delay_ms=(SystemCoreClock>>13)*delay_ms; delay_ms != 0; delay_ms--);
}

//Initializes UART
void UartInit(void)
{
    UART_InitTypeDef UART_InitStruct;

    UART_InitStruct.UART_Mode.UARTMode_Tx = ENABLE;
    UART_InitStruct.UART_Mode.UARTMode_Rx = ENABLE;
    UART_InitStruct.UART_Int.UARTInt_Tx   = DISABLE;
    UART_InitStruct.UART_Int.UARTInt_Rx   = DISABLE;
    UART_InitStruct.UART_Ovr.UARTOvr_Tx   = DISABLE;
    UART_InitStruct.UART_Ovr.UARTOvr_Rx   = DISABLE;
    UART_InitStruct.UART_Hstm             = DISABLE;
    UART_InitStruct.UART_BaudRate         = 115200;

    UART_Init(UART0,&UART_InitStruct);
}
