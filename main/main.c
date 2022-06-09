// Copyright 2018-2025 Espressif Systems (Shanghai) PTE LTD
//
// Licensed under the Apache License, Version 2.0 (the "License");
// you may not use this file except in compliance with the License.
// You may obtain a copy of the License at
//
//     http://www.apache.org/licenses/LICENSE-2.0
//
// Unless required by applicable law or agreed to in writing, software
// distributed under the License is distributed on an "AS IS" BASIS,
// WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
// See the License for the specific language governing permissions and
// limitations under the License.

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "freertos/FreeRTOS.h"
#include "freertos/task.h"
#include "esp_event.h"
#include "../head/station.h"
#include "../head/uart.h"
#include "../head/network.h"
#include "../head/data_pool.h"


extern char *TAG;

static Data_pool data_pool;

static int flag=0; //bad

static void buff_init(){
    Data_pool_init(BUF_SIZE, &data_pool);
}

static void wifi_task(){
    //connect to AP		
    ESP_ERROR_CHECK(nvs_flash_init());
    ESP_LOGI(TAG, "ESP_WIFI_MODE_STA");
    wifi_init_sta();
    
    //config tcp client
}

static void uart_task(){
    uart_init();
    
/***Configure a temporary buffer for the incoming data***/
    while (1) {
        // Read data from the UART
        int len = uart_read_bytes(UART_NUM_0, data_pool.poolPtr+data_pool.last, BUF_SIZE, 20 / portTICK_RATE_MS);
        
        if(len){
          data_pool.last += len;
          flag = 1;
        }
        
    }
}

void app_main()
{
    int msg_id;
    
    xTaskCreate(uart_task, "uart_task", 1024, NULL, 10, NULL);
    wifi_task();
    buff_init();
    
    esp_mqtt_client_handle_t client = mqtt_client_init("mqtt://120.55.170.139:1883");
    
    while(1)
    {
    	if(flag)
       {
           *(data_pool.poolPtr+data_pool.last) = '\0';
       	   data_pool.last += 1;  
           msg_id = esp_mqtt_client_publish(client, "/topic/test",(const char *) data_pool.poolPtr, 0, 1, 0);
           if(msg_id == -1)
           {
              printf("publish fail");
           } 
       
           else {
              printf("publish success. message id is %d\r\n", msg_id);
              
              // Write data back to the UART
              uart_write_bytes(UART_NUM_0, (const char *)data_pool.poolPtr, data_pool.last);
              data_pool.last = 0;
           }
           
           flag = 0;
       }
       printf("wirte messgae\r\n")
       vTaskDelay(1 / portTICK_PERIOD_MS);
    }
    
}








