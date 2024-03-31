#pragma once

#include "esp_log.h"
#include "esp_err.h"
#include "driver/gpio.h"
#include "esp_adc/adc_oneshot.h"
#include "hal/adc_types.h"



/**
 * @brief Setup ADC for reading MQ9
 * @param adcHandle Handle for ADC to initialize. Pointer to type adc_oneshot_unit_handle_t
*/
void initMq9(adc_oneshot_unit_handle_t *adcHandle);

/**
 * @brief Read ADC
 * @param adcHandle Handle for ADC to initialize. Pointer to type adc_oneshot_unit_handle_t
 * @param readValue Sensor output values
*/
void readMq9(adc_oneshot_unit_handle_t adcHandle, int *readValue);

