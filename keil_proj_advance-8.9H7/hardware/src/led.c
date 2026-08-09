/**
 * @file    led.c
 * @brief   LED 驱动实现文件。
 */
#include "led.h"

/* 宏定义函数做越界检查*/
#define IS_VALID_LED(led_num) ((led_num) >= (LED_NUM_MIN) && (led_num) <= (LED_NUM_MAX))


/* 创建全局变量*/
 static uint8_t led_num;
 static param_led step;

/* 点亮 第n个 LED */
static void led_on(uint8_t led_num)
{
    if(!IS_VALID_LED(led_num))
    {
        return;
    }
   switch(led_num)
   {
      case 0:
      HAL_GPIO_WritePin(LED_GPIO_PORT, LED1_PIN, GPIO_PIN_SET);
      break;

      case 1:
      HAL_GPIO_WritePin(LED_GPIO_PORT, LED2_PIN, GPIO_PIN_SET);
      break;

      case 2:
      HAL_GPIO_WritePin(LED_GPIO_PORT, LED3_PIN, GPIO_PIN_SET);
      break;

      case 3:
      HAL_GPIO_WritePin(LED_GPIO_PORT, LED4_PIN, GPIO_PIN_SET);
      break;

      default:
      break;
   }



    
}

/* 熄灭 第n个 LED */
static void led_off(uint8_t led_num)
{
    if(!IS_VALID_LED(led_num))
    {
        return;
    }
    switch(led_num)
    {
        case 0:
        HAL_GPIO_WritePin(LED_GPIO_PORT, LED1_PIN, GPIO_PIN_RESET);
        break;

        case 1:
        HAL_GPIO_WritePin(LED_GPIO_PORT, LED2_PIN, GPIO_PIN_RESET);
        break;

        case 2:
        HAL_GPIO_WritePin(LED_GPIO_PORT, LED3_PIN, GPIO_PIN_RESET);
        break;

        case 3:
        HAL_GPIO_WritePin(LED_GPIO_PORT, LED4_PIN, GPIO_PIN_RESET);
        break;

        default:
        break;

    }
    
}

/*流水灯*/
void flow_led(void)
    {
        for(uint8_t i = 0; i < 4; i++)  
        {
        step.led_num = i;
        step.on_ms = DELAY_MS;
        step.off_ms = DELAY_MS;
        blink(&step);
        }
    };


void blink(const param_led *param)   
{
    led_on(param->led_num);
    HAL_Delay(param->on_ms);
    led_off(param->led_num);
    HAL_Delay(param->off_ms);
}

/*mode_one*/
void led_one()
{
    for(led_num = 0U; led_num < 4; led_num++)
    {
        led_on(led_num);
        HAL_Delay(DELAY_MS);
        led_off(led_num);
        HAL_Delay(DELAY_MS);
    }
}

/*mode_two*/
void led_two()
{
    switch(step)
    {
        case 0:
        led_on(0);
        led_on(1);
        break;

        case 1:
        led_on(1);
        led_on(2);
        break;

        case 2:
        led_on(2);
        led_on(3);
        break;

        case 3:
        led_on(3);
        led_on(0);
        break;

    }
    step++;
    if(step > 3)
    {
        step = 0;
    }

    HAL_Delay(DELAY_MS);
}

/*mode_all*/
void led_all()
{
    while(1)
    {
        led_on(0);
        led_on(1);
        led_on(2);
        led_on(3);
        HAL_Delay(DELAY_MS);
        led_off(0);
        led_off(1);
        led_off(2);
        led_off(3);
    }
}