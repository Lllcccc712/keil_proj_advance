/**
 * @file    led.c
 * @brief   LED 驱动实现文件。
 */
#include "led.h"

/* 宏定义函数做越界检查*/
#define IS_VALID_LED(led_num) ((led_num) >= (LED_NUM_MIN) && (led_num) <= (LED_NUM_MAX))

/* 点亮 第n个 LED */
void led_on(uint8_t led_num)
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
void led_off(uint8_t led_num)
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
        static uint8_t led_num;
        for(led_num = 0U; led_num <= LED_NUM_MAX; led_num++)
        {
            led_on(led_num);
            HAL_Delay(DELAY_MS);
            led_off(led_num);
            HAL_Delay(DELAY_MS);
        }
        
    }

