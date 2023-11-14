/* USER CODE BEGIN Header */
/**
  ******************************************************************************
  * @file           : main.h
  * @brief          : Header for main.c file.
  *                   This file contains the common defines of the application.
  ******************************************************************************
  * @attention
  *
  * Copyright (c) 2023 STMicroelectronics.
  * All rights reserved.
  *
  * This software is licensed under terms that can be found in the LICENSE file
  * in the root directory of this software component.
  * If no LICENSE file comes with this software, it is provided AS-IS.
  *
  ******************************************************************************
  */
/* USER CODE END Header */

/* Define to prevent recursive inclusion -------------------------------------*/
#ifndef __MAIN_H
#define __MAIN_H

#ifdef __cplusplus
extern "C" {
#endif

/* Includes ------------------------------------------------------------------*/
#include "stm32f1xx_hal.h"

/* Private includes ----------------------------------------------------------*/
/* USER CODE BEGIN Includes */

/* USER CODE END Includes */

/* Exported types ------------------------------------------------------------*/
/* USER CODE BEGIN ET */

/* USER CODE END ET */

/* Exported constants --------------------------------------------------------*/
/* USER CODE BEGIN EC */

/* USER CODE END EC */

/* Exported macro ------------------------------------------------------------*/
/* USER CODE BEGIN EM */

/* USER CODE END EM */

/* Exported functions prototypes ---------------------------------------------*/
void Error_Handler(void);

/* USER CODE BEGIN EFP */

/* USER CODE END EFP */

/* Private defines -----------------------------------------------------------*/
#define EN0_Pin GPIO_PIN_1
#define EN0_GPIO_Port GPIOA
#define EN1_Pin GPIO_PIN_2
#define EN1_GPIO_Port GPIOA
#define BUTTON_0_Pin GPIO_PIN_3
#define BUTTON_0_GPIO_Port GPIOA
#define BUTTON_1_Pin GPIO_PIN_4
#define BUTTON_1_GPIO_Port GPIOA
#define LED_Pin GPIO_PIN_5
#define LED_GPIO_Port GPIOA
#define BUTTON_2_Pin GPIO_PIN_6
#define BUTTON_2_GPIO_Port GPIOA
#define LED7_1_SEG0_Pin GPIO_PIN_0
#define LED7_1_SEG0_GPIO_Port GPIOB
#define LED7_1_SEG1_Pin GPIO_PIN_1
#define LED7_1_SEG1_GPIO_Port GPIOB
#define LED7_1_SEG2_Pin GPIO_PIN_2
#define LED7_1_SEG2_GPIO_Port GPIOB
#define LED7_2_SEG3_Pin GPIO_PIN_10
#define LED7_2_SEG3_GPIO_Port GPIOB
#define LED7_2_SEG4_Pin GPIO_PIN_11
#define LED7_2_SEG4_GPIO_Port GPIOB
#define LED7_2_SEG5_Pin GPIO_PIN_12
#define LED7_2_SEG5_GPIO_Port GPIOB
#define LED7_2_SEG6_Pin GPIO_PIN_13
#define LED7_2_SEG6_GPIO_Port GPIOB
#define MAIN_GREEN_Pin GPIO_PIN_8
#define MAIN_GREEN_GPIO_Port GPIOA
#define MAIN_YELLOW_Pin GPIO_PIN_9
#define MAIN_YELLOW_GPIO_Port GPIOA
#define MAIN_RED_Pin GPIO_PIN_10
#define MAIN_RED_GPIO_Port GPIOA
#define SIDE_GREEN_Pin GPIO_PIN_11
#define SIDE_GREEN_GPIO_Port GPIOA
#define SIDE_YELLOW_Pin GPIO_PIN_12
#define SIDE_YELLOW_GPIO_Port GPIOA
#define SIDE_RED_Pin GPIO_PIN_13
#define SIDE_RED_GPIO_Port GPIOA
#define EN2_Pin GPIO_PIN_14
#define EN2_GPIO_Port GPIOA
#define EN3_Pin GPIO_PIN_15
#define EN3_GPIO_Port GPIOA
#define LED7_1_SEG3_Pin GPIO_PIN_3
#define LED7_1_SEG3_GPIO_Port GPIOB
#define LED7_1_SEG4_Pin GPIO_PIN_4
#define LED7_1_SEG4_GPIO_Port GPIOB
#define LED7_1_SEG5_Pin GPIO_PIN_5
#define LED7_1_SEG5_GPIO_Port GPIOB
#define LED7_1_SEG6_Pin GPIO_PIN_6
#define LED7_1_SEG6_GPIO_Port GPIOB
#define LED7_2_SEG0_Pin GPIO_PIN_7
#define LED7_2_SEG0_GPIO_Port GPIOB
#define LED7_2_SEG1_Pin GPIO_PIN_8
#define LED7_2_SEG1_GPIO_Port GPIOB
#define LED7_2_SEG2_Pin GPIO_PIN_9
#define LED7_2_SEG2_GPIO_Port GPIOB

/* USER CODE BEGIN Private defines */

/* USER CODE END Private defines */

#ifdef __cplusplus
}
#endif

#endif /* __MAIN_H */
