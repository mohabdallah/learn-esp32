#include "app_keypad.h"

static const char *TAG = "app_keypad";

/* Keypad pins */
#define KEYPAD_COL1_PIN 5
#define KEYPAD_COL2_PIN 18
#define KEYPAD_COL3_PIN 19
#define KEYPAD_ROW1_PIN 23
#define KEYPAD_ROW2_PIN 22
#define KEYPAD_ROW3_PIN 21


void App_initAndStart_keypad(void)
{
    gpio_reset_pin(KEYPAD_COL1_PIN);
    gpio_set_direction(KEYPAD_COL1_PIN, GPIO_MODE_OUTPUT);
    gpio_set_level(KEYPAD_COL1_PIN, 0);

    gpio_reset_pin(KEYPAD_COL2_PIN);
    gpio_set_direction(KEYPAD_COL2_PIN, GPIO_MODE_OUTPUT);
    gpio_set_level(KEYPAD_COL2_PIN, 0);

    gpio_reset_pin(KEYPAD_COL3_PIN);
    gpio_set_direction(KEYPAD_COL3_PIN, GPIO_MODE_OUTPUT);
    gpio_set_level(KEYPAD_COL3_PIN, 0);

    gpio_reset_pin(KEYPAD_ROW1_PIN);
    gpio_set_direction(KEYPAD_ROW1_PIN, GPIO_MODE_INPUT);
    gpio_pullup_dis(KEYPAD_ROW1_PIN);
    gpio_pulldown_en(KEYPAD_ROW1_PIN);

    gpio_reset_pin(KEYPAD_ROW2_PIN);
    gpio_set_direction(KEYPAD_ROW2_PIN, GPIO_MODE_INPUT);
    gpio_pullup_dis(KEYPAD_ROW2_PIN);
    gpio_pulldown_en(KEYPAD_ROW2_PIN);

    gpio_reset_pin(KEYPAD_ROW3_PIN);
    gpio_set_direction(KEYPAD_ROW3_PIN, GPIO_MODE_INPUT);
    gpio_pullup_dis(KEYPAD_ROW3_PIN);
    gpio_pulldown_en(KEYPAD_ROW3_PIN);

    while (1)
    {
        /* Check COL 1, all rows */
        gpio_set_level(KEYPAD_COL1_PIN, 1);

        if (1 == gpio_get_level(KEYPAD_ROW1_PIN))
        {
            printf("Pressed 1\n");
            vTaskDelay(400 / portTICK_PERIOD_MS);
        }
        else if (1 == gpio_get_level(KEYPAD_ROW2_PIN))
        {
            printf("Pressed 4\n");
            vTaskDelay(400 / portTICK_PERIOD_MS);
        }
        else if (1 == gpio_get_level(KEYPAD_ROW3_PIN))
        {
            printf("Pressed 7\n");
            vTaskDelay(400 / portTICK_PERIOD_MS);
        }

        gpio_set_level(KEYPAD_COL1_PIN, 0);

        /* Check COL 2, all rows */
        gpio_set_level(KEYPAD_COL2_PIN, 1);

        if (1 == gpio_get_level(KEYPAD_ROW1_PIN))
        {
            printf("Pressed 2\n");
            vTaskDelay(400 / portTICK_PERIOD_MS);
        }
        else if (1 == gpio_get_level(KEYPAD_ROW2_PIN))
        {
            printf("Pressed 5\n");
            vTaskDelay(400 / portTICK_PERIOD_MS);
        }
        else if (1 == gpio_get_level(KEYPAD_ROW3_PIN))
        {
            printf("Pressed 8\n");
            vTaskDelay(400 / portTICK_PERIOD_MS);
        }

        gpio_set_level(KEYPAD_COL2_PIN, 0);

        /* Check COL 3, all rows */
        gpio_set_level(KEYPAD_COL3_PIN, 1);

        if (1 == gpio_get_level(KEYPAD_ROW1_PIN))
        {
            printf("Pressed 3\n");
            vTaskDelay(400 / portTICK_PERIOD_MS);
        }
        else if (1 == gpio_get_level(KEYPAD_ROW2_PIN))
        {
            printf("Pressed 6\n");
            vTaskDelay(400 / portTICK_PERIOD_MS);
        }
        else if (1 == gpio_get_level(KEYPAD_ROW3_PIN))
        {
            printf("Pressed 9\n");
            vTaskDelay(400 / portTICK_PERIOD_MS);
        }

        gpio_set_level(KEYPAD_COL3_PIN, 0);

        vTaskDelay(100 / portTICK_PERIOD_MS);
    }
}