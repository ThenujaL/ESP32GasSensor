#include <stdio.h>

#include "freertos/FreeRTOS.h"
#include "freertos/task.h"

#include "esp_log.h"
#include "esp_err.h"
#include "driver/gpio.h"
#include "esp_adc/adc_oneshot.h"
#include "hal/adc_types.h"

#include "mq9.h"

#define BLINK_LED 2

void app_main(void)
{
    char *ourTaskName = pcTaskGetName(NULL);
    int adc_out = -1;

    ESP_LOGI(ourTaskName, "Starting CO sensor");

    // Sertup GPIO
    gpio_reset_pin(BLINK_LED);
    gpio_set_direction(BLINK_LED, GPIO_MODE_OUTPUT);

    //-------------ADC1 Init---------------//
    adc_oneshot_unit_handle_t adc1_handle;
    initMq9(&adc1_handle);

    while(1)
    {
        readMq9(adc1_handle, &adc_out);
        printf("ADC READ: %d\n", adc_out);
        gpio_set_level(BLINK_LED, 1);
        vTaskDelay(1000 / portTICK_PERIOD_MS);
        gpio_set_level(BLINK_LED, 0);
        vTaskDelay(1000 / portTICK_PERIOD_MS);
    }

}
