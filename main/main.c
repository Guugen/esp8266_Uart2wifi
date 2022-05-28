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


extern char *TAG;

static void wifi_task(){
    //connect to AP		
    ESP_ERROR_CHECK(nvs_flash_init());
    ESP_LOGI(TAG, "ESP_WIFI_MODE_STA");
    wifi_init_sta();
    
    //config tcp client
}


void app_main()
{
    int msg_id;

    wifi_task();
    esp_mqtt_client_handle_t client = mqtt_client_init("mqtt://120.55.170.139:1883");
    
    while(1)
    {
       msg_id = esp_mqtt_client_publish(client, "/topic/test", "data_3", 0, 1, 0);
       if(msg_id == -1) printf("publish fail");
       else printf("publish success\r\n");
       vTaskDelay(1000 / portTICK_PERIOD_MS);
    }
    
}








