#include "../head/network.h"
esp_mqtt_client_handle_t mqtt_client_init(const char* url)
{
    int esp_err;
    
    esp_mqtt_client_config_t mqtt_cfg = {
        .uri = url,
    };
    
    esp_mqtt_client_handle_t client = esp_mqtt_client_init(&mqtt_cfg);
    esp_err = esp_mqtt_client_start(client);
    if(esp_err){
    	printf("mqtt client start fail");
    }
    
    return client;
}

