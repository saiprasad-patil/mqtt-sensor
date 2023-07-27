#include <stdio.h>
#include "wifi_start.h"
#include "mqtt_start.h"
#include "freertos/FreeRTOS.h"
#include "freertos/task.h"

void app_main(void)
{
    wifi(); // Function for wifi initialization
    vTaskDelay(pdMS_TO_TICKS(5000));
    mqtt(); // Function for mqtt initialization and sensor values
}
