#include "stm8l15x_display.h"
#include "stm8l15x_definepin.h"

/* LEDKEYPAD display */
void LED_Dispaly(uint8_t Number_1, uint8_t Number_2)
{
  uint8_t Temp = 0;
  for(uint8_t i = 0; i < 8; i++)
  {
    Temp = (Number_1 << i);
    if(Temp & 0x80)
      GPIO_SetBits(GPIOG, GPIO_PIN_DS);
    else
      GPIO_ResetBits(GPIOG, GPIO_PIN_DS);
    
    GPIO_ResetBits(GPIOG, GPIO_PIN_SH);
    GPIO_SetBits(GPIOG, GPIO_PIN_SH);
  }
  for(uint8_t i = 0; i < 8; i++)
  {
    Temp = (Number_2 << i);
    if(Temp & 0x80)
      GPIO_SetBits(GPIOG, GPIO_PIN_DS);
    else
      GPIO_ResetBits(GPIOG, GPIO_PIN_DS);
    
    GPIO_ResetBits(GPIOG, GPIO_PIN_SH);
    GPIO_SetBits(GPIOG, GPIO_PIN_SH);
  }
  
  GPIO_ResetBits(GPIOG, GPIO_PIN_ST);
  GPIO_SetBits(GPIOG, GPIO_PIN_ST);
}

/* LED init */
void LED_Init(void)
{
  GPIO_Init(GPIOG, LED_GPIO_PINS, GPIO_Mode_Out_PP_Low_Fast);
  LED_Dispaly(0x00, 0x00);
}