#include "stm8l15x_drivermotor.h"
#include "stm8l15x_delay.h"

/* DrivermotorInit */
void Drivermotor_Init(void)
{
  GPIO_Init(GPIOE, GPIO_PIN_MT, GPIO_Mode_Out_PP_Low_Fast);
}

/* Drivermotor_Open */
void Drivermotor_Open(void)
{
  GPIO_SetBits(GPIOE, GPIO_PIN_MT2);  // Cho phep mo
  GPIO_ResetBits(GPIOE, GPIO_PIN_MT1);
  DELAY_Ms(500);
  GPIO_ResetBits(GPIOE, GPIO_PIN_MT1); // Dong lai
  GPIO_ResetBits(GPIOE, GPIO_PIN_MT2);
  DELAY_Ms(3000);
  GPIO_ResetBits(GPIOE, GPIO_PIN_MT2); //Khong cho phep mo
  GPIO_SetBits(GPIOE, GPIO_PIN_MT1);
  DELAY_Ms(500);
  GPIO_ResetBits(GPIOE, GPIO_PIN_MT1); // Dong lai
  GPIO_ResetBits(GPIOE, GPIO_PIN_MT2);
}