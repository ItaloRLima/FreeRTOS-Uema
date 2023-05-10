#include <stdio.h>
#include "control_switch.h"
#include "../../definition.h"


info_led_t status_led;

#define SWITCH 19
#define LED 2

void gpio_switch(int button){
    gpio_reset_pin(button);
    gpio_set_direction(button,GPIO_MODE_DEF_INPUT);
}

void vTaskSwitch(void *pvParameters)
{
    gpio_switch(SWITCH);

    bool stts_led = false;
    bool old_status_switch = gpio_get_level(SWITCH);

    while(true){
        bool status_switch = gpio_get_level(SWITCH);

        if(status_switch != 1 && old_status_switch != status_switch){
            stts_led = !stts_led;
            status_led.led = LED;
            status_led.status = stts_led;

            xQueueSend( xQueueSwitch, &status_led, portMAX_DELAY);
        }
        old_status_switch = status_switch;

        vTaskDelay( 250 / portTICK_PERIOD_MS );
    }
}