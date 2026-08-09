/**
 * @file    led.h
 * @brief   LED 驱动头文件。
 *          头文件放声明和宏，具体实现放在 led.c。
 */
#ifndef LED_H
#define LED_H

#include "stm32h7xx_hal.h"

#ifdef __cplusplus
extern "C" {
#endif

/* 定义编号的最值*/
#define LED_NUM_MIN 0U
#define LED_NUM_MAX 3U
#define DELAY_MS 120U

/*定义结构体*/
typedef struct
{
    uint8_t led_num;
    uint16_t on_ms;
    uint16_t off_ms;
}param_led;

typedef struct
{
    param_led steps[4];
}param_led_flow;

/* 枚举*/
typedef enum
{
    mode_one = 0,
    mode_two = 1,
    mode_all = 2,
}mode;


/* 宏定义：给 LED 使用的端口和引脚起名字 */
#define LED_GPIO_PORT GPIOB
#define LED1_PIN      GPIO_PIN_3
#define LED2_PIN      GPIO_PIN_4
#define LED3_PIN      GPIO_PIN_5
#define LED4_PIN      GPIO_PIN_6

/* 种子工程先提供无参数版本，只操作 LED1；题目 1 将其扩展为带编号参数版本 */
void flow_led(void);
void blink(const param_led *param);

/*逐个亮灭函数*/
void led_one();

/*两两亮灭*/
void led_two();

/*全部亮灭*/
void led_all();

#ifdef __cplusplus
}
#endif

#endif /* LED_H */



