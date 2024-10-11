#include "app_hbridge.h"

static const char *TAG = "app_hbridge";

/* HBridge pins */
#define HBRIDGE_ENABLE1_PIN 25
#define HBRIDGE_ENABLE2_PIN 26
#define HBRIDGE_INPUT1_PIN  32
#define HBRIDGE_INPUT2_PIN  33
#define HBRIDGE_INPUT3_PIN  17
#define HBRIDGE_INPUT4_PIN  16

void App_initAndStart_hbridge(void)
{
    gpio_reset_pin(HBRIDGE_ENABLE1_PIN);
    gpio_set_direction(HBRIDGE_ENABLE1_PIN, GPIO_MODE_OUTPUT);
    gpio_set_level(HBRIDGE_ENABLE1_PIN, 1);

    gpio_reset_pin(HBRIDGE_ENABLE2_PIN);
    gpio_set_direction(HBRIDGE_ENABLE2_PIN, GPIO_MODE_OUTPUT);
    gpio_set_level(HBRIDGE_ENABLE2_PIN, 1);

    gpio_reset_pin(HBRIDGE_INPUT1_PIN);
    gpio_set_direction(HBRIDGE_INPUT1_PIN, GPIO_MODE_OUTPUT);
    gpio_set_level(HBRIDGE_INPUT1_PIN, 0);

    gpio_reset_pin(HBRIDGE_INPUT2_PIN);
    gpio_set_direction(HBRIDGE_INPUT2_PIN, GPIO_MODE_OUTPUT);
    gpio_set_level(HBRIDGE_INPUT2_PIN, 0);

    gpio_reset_pin(HBRIDGE_INPUT3_PIN);
    gpio_set_direction(HBRIDGE_INPUT3_PIN, GPIO_MODE_OUTPUT);
    gpio_set_level(HBRIDGE_INPUT3_PIN, 0);

    gpio_reset_pin(HBRIDGE_INPUT4_PIN);
    gpio_set_direction(HBRIDGE_INPUT4_PIN, GPIO_MODE_OUTPUT);
    gpio_set_level(HBRIDGE_INPUT4_PIN, 0);

    vTaskDelay(3000 / portTICK_PERIOD_MS);

    gpio_set_level(HBRIDGE_ENABLE1_PIN, 1);
    gpio_set_level(HBRIDGE_INPUT1_PIN, 1);
    printf("Input 1 ON\n");

    vTaskDelay(10000 / portTICK_PERIOD_MS);

    gpio_set_level(HBRIDGE_INPUT1_PIN, 0);
    vTaskDelay(2000 / portTICK_PERIOD_MS);
    gpio_set_level(HBRIDGE_INPUT2_PIN, 1);
    printf("Input 2 ON\n");

    vTaskDelay(10000 / portTICK_PERIOD_MS);
}