/**
 * @file    led.c
 * @brief   LED 驱动实现文件。
 */
#include "led.h"

/* 宏定义函数做越界检查*/
#define IS_VALID_LED(led_num) ((led_num) >= (LED_NUM_MIN) && (led_num) <= (LED_NUM_MAX))

/* 点亮 LED1 */
void led_on(uint8_t led_num)
{
    if(!IS_VALID_LED(led_num))
    {
        return;
    }
    HAL_GPIO_WritePin(LED_GPIO_PORT, LED1_PIN, GPIO_PIN_SET);
}

/* 熄灭 LED1 */
void led_off(uint8_t led_num)
{
    if(!IS_VALID_LED(led_num))
    {
        return;
    }
    HAL_GPIO_WritePin(LED_GPIO_PORT, LED1_PIN, GPIO_PIN_RESET);
}
