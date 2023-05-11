#include <stdio.h>

#include "../definition.h"
#include "../components/control_led/include/control_led.h"
#include "../components/control_switch/include/control_switch.h"

QueueHandle_t xQueueSwitch;

void vTaskLed(void *pvParameters);
void vTaskSwitch(void *pvParameters);

void init_queue(void){
    xQueueSwitch = xQueueCreate(5 , sizeof(info_led) );
}

void app_main(void)
{
    init_queue();

    xTaskCreatePinnedToCore( vTaskLed, "TaskLed", configMINIMAL_STACK_SIZE + 2048, NULL, 4, NULL, 0 );
    xTaskCreatePinnedToCore( vTaskSwitch, "TaskSwitch", configMINIMAL_STACK_SIZE + 2048, NULL, 4, NULL, 1 );
}
