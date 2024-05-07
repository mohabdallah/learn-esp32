#include <stdio.h>
#include "on_board_leds.h"

static const char *TAG = "on_board_leds";

/* LEDs pins */
#define LED1_PIN 12
#define LED2_PIN 13
#define LED3_PIN 14
#define LED4_PIN 15

void on_board_leds_init(void)
{
    PLATFORM_LOGI(TAG, "configure_CONNECT_BOARD_leds");
    gpio_reset_pin(LED1_PIN);
    gpio_set_direction(LED1_PIN, GPIO_MODE_OUTPUT);
    gpio_set_level(LED1_PIN, 0);

    gpio_reset_pin(LED2_PIN);
    gpio_set_direction(LED2_PIN, GPIO_MODE_OUTPUT);
    gpio_set_level(LED2_PIN, 0);

    gpio_reset_pin(LED3_PIN);
    gpio_set_direction(LED3_PIN, GPIO_MODE_OUTPUT);
    gpio_set_level(LED3_PIN, 0);

    gpio_reset_pin(LED4_PIN);
    gpio_set_direction(LED4_PIN, GPIO_MODE_OUTPUT);
    gpio_set_level(LED4_PIN, 0);
}

void on_board_leds_setLed1Status(bool status)
{
    gpio_set_level(LED1_PIN, status ? 1 : 0);
}

void on_board_leds_setLed2Status(bool status)
{
    gpio_set_level(LED2_PIN, status ? 1 : 0);
}

void on_board_leds_setLed3Status(bool status)
{
    gpio_set_level(LED3_PIN, status ? 1 : 0);
}

void on_board_leds_setLed4Status(bool status)
{
    gpio_set_level(LED4_PIN, status ? 1 : 0);
}