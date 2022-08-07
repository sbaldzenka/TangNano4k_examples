/* Includes ------------------------------------------------------------------*/
#include "gw1ns4c.h"
#include <stdio.h>
#include <sys/stat.h>

__attribute__ ((used))  int _write (int fd, char *ptr, int len)
{
    size_t i;

    for(i=0; i<len; i++)
    {
        UART_SendChar(UART0,ptr[i]); // call character output function
    }

    return len;
}
