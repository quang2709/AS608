/* Define to prevent recursive inclusion -------------------------------------*/
#ifndef __STM8L15x_DRIVERMOTOR_H
#define __STM8L15x_DRIVERMOTOR_H

/* Includes ------------------------------------------------------------------*/
#include "stm8l15x.h"

#define GPIO_PIN_MT1 GPIO_Pin_0
#define GPIO_PIN_MT2 GPIO_Pin_1
#define GPIO_PIN_MT GPIO_Pin_0|GPIO_Pin_1

/* DrivermotorInit */
void Drivermotor_Init(void);

/* Drivermotor_Open */
void Drivermotor_Open(void);

#endif //__STM8L15x_DRIVERMOTOR_H