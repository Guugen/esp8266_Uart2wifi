#include "../head/uart.h"

void uart_init()
{
    int32_t stuation = 0;	//stuation of function
    
    
/***Configure parameters of an UART driver***/
    uart_config_t uart_config = {
        .baud_rate = 115200,
        .data_bits = UART_DATA_8_BITS,
        .parity    = UART_PARITY_DISABLE,
        .stop_bits = UART_STOP_BITS_1,
        .flow_ctrl = UART_HW_FLOWCTRL_DISABLE
    };

   
    
/***communication pins and install the driver***/
    stuation = uart_param_config(UART_NUM_0, &uart_config);
    printf("uart_config's esp_err_t is %x\n", stuation);
    
    stuation = uart_driver_install(UART_NUM_0, BUF_SIZE * 2, 0, 0, NULL, 0);
    printf("uart_install's esp_err_t is %x\n", stuation);
    
}

