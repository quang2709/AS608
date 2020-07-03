#include "stm8l15x_delay.h"
#include "stm8l15x_tim4.h"

#define TIM4_PERIOD       124
uint32_t TimingDelay;

void DELAY_Init(void)
{
  /* Time base configuration */
  TIM4_TimeBaseInit(TIM4_Prescaler_128, TIM4_PERIOD);
  /* Clear TIM4 update flag */
  TIM4_ClearFlag(TIM4_FLAG_Update);
  /* Enable update interrupt */
  TIM4_ITConfig(TIM4_IT_Update, ENABLE);
  /* Enable interrupts */
  enableInterrupts();

  /* Enable TIM4 */
  TIM4_Cmd(ENABLE);
}

void DELAY_Ms(uint32_t time_ms)
{
  TimingDelay = time_ms;

  while (TimingDelay != 0);
}

void TimingDelay_Decrement(void)
{
  if (TimingDelay != 0x00)
  {
    TimingDelay--;
  }
}