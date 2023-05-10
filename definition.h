#ifndef __DEFINITION__H__
#define __DEFINITION__H__


#include <stdio.h>
#include <stdbool.h>
#include "freertos/FreeRTOS.h"
#include "freertos/task.h"
#include "freertos/queue.h"
#include "driver/gpio.h"

extern QueueHandle_t xQueueSwitch;

typedef struct{
    int led;
    bool status;
}info_led_t;

extern info_led_t info_led;

#endif