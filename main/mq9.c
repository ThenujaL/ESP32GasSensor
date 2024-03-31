#include "esp_log.h"
#include "esp_err.h"
#include "driver/gpio.h"
#include "esp_adc/adc_oneshot.h"
#include "hal/adc_types.h"

#include "mq9.h"

#define MQ9_ADC_CHANNEL ADC_CHANNEL_6


void initMq9(adc_oneshot_unit_handle_t *adcHandle){

    //-------------ADC1 Init---------------//
    adc_oneshot_unit_init_cfg_t init_config1 = {
        .unit_id = ADC_UNIT_1,
        .ulp_mode = ADC_ULP_MODE_DISABLE,
    };
    ESP_ERROR_CHECK(adc_oneshot_new_unit(&init_config1, adcHandle));

    //-------------ADC1 Config---------------//
    adc_oneshot_chan_cfg_t config = {
        .bitwidth = ADC_BITWIDTH_DEFAULT,
        .atten = ADC_ATTEN_DB_12,
    };
    ESP_ERROR_CHECK(adc_oneshot_config_channel(*adcHandle, MQ9_ADC_CHANNEL, &config));
}

void readMq9(adc_oneshot_unit_handle_t adcHandle, int *readValue){
    ESP_ERROR_CHECK(adc_oneshot_read(adcHandle, MQ9_ADC_CHANNEL, readValue));
}