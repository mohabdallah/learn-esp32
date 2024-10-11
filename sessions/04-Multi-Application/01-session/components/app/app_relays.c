#include "app_relays.h"

static const char *TAG = "app_relays";

/* Relays pins */
#define RELAY1_PIN 17
#define RELAY2_PIN 16


void App_initAndStart_relays(void)
{
    gpio_reset_pin(RELAY1_PIN);
    gpio_set_direction(RELAY1_PIN, GPIO_MODE_OUTPUT);
    gpio_set_level(RELAY1_PIN, 0);

    gpio_reset_pin(RELAY2_PIN);
    gpio_set_direction(RELAY2_PIN, GPIO_MODE_OUTPUT);
    gpio_set_level(RELAY2_PIN, 0);

    vTaskDelay(3000 / portTICK_PERIOD_MS);

    gpio_set_level(RELAY1_PIN, 1);
    printf("Relay 1 ON\n");

    vTaskDelay(5000 / portTICK_PERIOD_MS);

    gpio_set_level(RELAY1_PIN, 0);
    gpio_set_level(RELAY2_PIN, 1);
    printf("Relay 2 ON\n");

    vTaskDelay(5000 / portTICK_PERIOD_MS);

    gpio_set_level(RELAY2_PIN, 0);

    vTaskDelay(10000 / portTICK_PERIOD_MS);
}