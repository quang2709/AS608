/* Define to prevent recursive inclusion -------------------------------------*/
#ifndef __STM8L15x_DELAY_H
#define __STM8L15x_DELAY_H

/* Includes ------------------------------------------------------------------*/
#include "stm8l15x.h"

void DELAY_Init(void);

void DELAY_Ms(uint32_t time_ms);

void TimingDelay_Decrement(void);

#endif //__STM8L15x_DELAY_H