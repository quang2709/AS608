/* Define to prevent recursive inclusion -------------------------------------*/
#ifndef __STM8L15x_DEFINEPIN_H
#define __STM8L15x_DEFINEPIN_H

/* Includes ------------------------------------------------------------------*/
#include "stm8l15x.h"

/* Private define ---------------------------------------------*/
#define GPIO_PIN_SH GPIO_Pin_0
#define GPIO_PIN_ST GPIO_Pin_1
#define GPIO_PIN_DS GPIO_Pin_2
#define LED_GPIO_PINS (GPIO_Pin_0|GPIO_Pin_1|GPIO_Pin_2|GPIO_Pin_3)
/* Private define ---------------------------------------------*/
#define GPIO_PIN_SW GPIO_Pin_3
#define GPIO_PIN_TLV_EN GPIO_Pin_4
#define GPIO_PIN_TSM_EN GPIO_Pin_4
#define GPIO_PIN_TSM_INT GPIO_Pin_4

#endif //__STM8L15x_DEFINEPIN_H