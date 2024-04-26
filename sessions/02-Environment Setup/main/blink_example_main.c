/* Blink Example

   This example code is in the Public Domain (or CC0 licensed, at your option.)

   Unless required by applicable law or agreed to in writing, this
   software is distributed on an "AS IS" BASIS, WITHOUT WARRANTIES OR
   CONDITIONS OF ANY KIND, either express or implied.
*/
#include <stdio.h>
#include "freertos/FreeRTOS.h"
#include "freertos/task.h"
#include "driver/gpio.h"
#include "esp_log.h"
#include "sdkconfig.h"

static const char *TAG = "example";

/* LEDs pins */
#define LED1_PIN 12
#define LED2_PIN 13
#define LED3_PIN 14
#define LED4_PIN 15

/* Use project configuration menu (idf.py menuconfig) to choose the GPIO to blink,
   or you can edit the following line and set a number here.
*/
#define BLINK_GPIO CONFIG_BLINK_GPIO

static uint8_t s_led_state = 0;

static void blink_led(void)
{
    /* Set the GPIO level according to the state (LOW or HIGH)*/
    gpio_set_level(BLINK_GPIO, s_led_state);
}

static void configure_led(void)
{
    ESP_LOGI(TAG, "Example configured to blink GPIO LED!");
    gpio_reset_pin(BLINK_GPIO);
    /* Set the GPIO as a push/pull output */
    gpio_set_direction(BLINK_GPIO, GPIO_MODE_OUTPUT);
}

static void configure_CONNECT_BOARD_leds(void)
{
    ESP_LOGI(TAG, "configure_CONNECT_BOARD_leds");
    gpio_reset_pin(LED1_PIN);
    gpio_set_direction(LED1_PIN, GPIO_MODE_OUTPUT);
    gpio_set_level(LED1_PIN, 1);

    gpio_reset_pin(LED2_PIN);
    gpio_set_direction(LED2_PIN, GPIO_MODE_OUTPUT);
    gpio_set_level(LED2_PIN, 1);

    gpio_reset_pin(LED3_PIN);
    gpio_set_direction(LED3_PIN, GPIO_MODE_OUTPUT);
    gpio_set_level(LED3_PIN, 1);

    gpio_reset_pin(LED4_PIN);
    gpio_set_direction(LED4_PIN, GPIO_MODE_OUTPUT);
    gpio_set_level(LED4_PIN, 1);
}

static void blink_CONNECT_BOARD_led(void)
{
    vTaskDelay(1000 / portTICK_PERIOD_MS);

    unsigned char testNum = 3;
    while (testNum > 0)
    {
        gpio_set_level(LED1_PIN, 1);
        gpio_set_level(LED2_PIN, 0);
        gpio_set_level(LED3_PIN, 0);
        gpio_set_level(LED4_PIN, 0);
        vTaskDelay(1000 / portTICK_PERIOD_MS);

        gpio_set_level(LED1_PIN, 0);
        gpio_set_level(LED2_PIN, 1);
        gpio_set_level(LED3_PIN, 0);
        gpio_set_level(LED4_PIN, 0);
        vTaskDelay(1000 / portTICK_PERIOD_MS);

        gpio_set_level(LED1_PIN, 0);
        gpio_set_level(LED2_PIN, 0);
        gpio_set_level(LED3_PIN, 1);
        gpio_set_level(LED4_PIN, 0);
        vTaskDelay(1000 / portTICK_PERIOD_MS);

        gpio_set_level(LED1_PIN, 0);
        gpio_set_level(LED2_PIN, 0);
        gpio_set_level(LED3_PIN, 0);
        gpio_set_level(LED4_PIN, 1);
        vTaskDelay(1000 / portTICK_PERIOD_MS);

        testNum--;
    }
}

void app_main(void)
{

    /* Configure the peripheral according to the LED type */
    configure_led();

    configure_CONNECT_BOARD_leds();

    blink_CONNECT_BOARD_led();

    while (1) {
        ESP_LOGI(TAG, "Turning the LED %s!", s_led_state == true ? "ON" : "OFF");
        blink_led();
        /* Toggle the LED state */
        s_led_state = !s_led_state;
        vTaskDelay(CONFIG_BLINK_PERIOD / portTICK_PERIOD_MS);
    }
}
