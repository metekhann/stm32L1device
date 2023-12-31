/**
 ******************************************************************************
 * @file           : main.c
 * @author         : Auto-generated by STM32CubeIDE
 * @brief          : Main program body
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


#include "stm32L1device.h"


#if !defined(__SOFT_FP__) && defined(__ARM_FP)
  #warning "FPU is not initialized, but the project is compiling for an FPU. Please initialize the FPU before use."
#endif


static void GPIO_Led_Config();
static void GPIO_ButtonInterruptConfig();
static void SPI_Config();
static void SPI_GPIO_Config();

SPI_HandleTypeDef_t SPI_Handle;
USART_HandleTypedef_t usart_handle;
uint8_t flag = 0;
int main(void)
{
	GPIO_Led_Config();
	GPIO_ButtonInterruptConfig();
	SPI_GPIO_Config();
	SPI_Config();

	char msg[] = "hello";

	//GPIO_WritePin(GPIOA, GPIO_PIN_5, GPIO_Pin_Set);

    /* Loop forever */
	while(1)
	{
		if(flag == 1)
		{
			GPIO_TogglePin(GPIOA, GPIO_PIN_5);
			SPI_TransmitData_IT(&SPI_Handle, (uint8_t *)msg, sizeof(msg));
			flag = 0;
		}
//		SPI_TransmitData(&SPI_Handle, (uint8_t *)msg, sizeof(msg));
	}
}

static void GPIO_Led_Config()
{
	GPIO_InitTypeDef_t GPIO_LedStruct = {0};

	RCC_GPIOA_CLOCK_ENABLE();
	RCC_GPIOC_CLOCK_ENABLE();

	GPIO_LedStruct.Mode = GPIO_MODE_OUTPUT;
	GPIO_LedStruct.pinNumber = GPIO_PIN_5;
	GPIO_LedStruct.Speed = GPIO_SPEED_LOW;
	GPIO_LedStruct.Otype = GPIO_OTYPE_PUSH_PULL;
	GPIO_Init(GPIOA, &GPIO_LedStruct);

	memset(&GPIO_LedStruct, 0, sizeof(GPIO_InitTypeDef_t));

	GPIO_LedStruct.Mode = GPIO_MODE_INPUT;
	GPIO_LedStruct.pinNumber = GPIO_PIN_13;
	GPIO_LedStruct.PuPd = GPIO_PuPd_PULLDOWN;
	GPIO_Init(GPIOC, &GPIO_LedStruct);
}

static void GPIO_ButtonInterruptConfig()
{
	EXTI_InitTypeDef_t EXTI_InitStruct = {0};
	RCC_SYSCFG_CLK_ENABLE();

	EXTI_LineConfig(EXTI_PORT_SOURCE_GPIOC, EXTI_LINE_SOURCE_13);
	EXTI_InitStruct.EXTI_LineCmd = ENABLE;
	EXTI_InitStruct.EXTI_LineNumber = EXTI_LINE_SOURCE_13;
	EXTI_InitStruct.EXTI_Mode = EXTI_MODE_INTERRUPT;
	EXTI_InitStruct.TriggerSelection = EXTI_TRIGGER_RISING;

	EXTI_Init(&EXTI_InitStruct);
	NVIC_EnableInterrupt(EXTI15_10_IRQNumber);
}
static void SPI_Config()
{
	RCC_SPI2_CLK_ENABLE();

	//SPI_Handle = {0};

	SPI_Handle.Instance = SPI2;
	SPI_Handle.Init.BaudRate = SPI_BAUDRATE_DIV128;
	SPI_Handle.Init.BusConfig = SPI_FULL_DUBLEX;
	SPI_Handle.Init.CPHA = SPI_CPHA_FIRST;
	SPI_Handle.Init.CPOL = SPI_CPOL_LOW;
	SPI_Handle.Init.FrameFormat = SPI_FRAME_FORMAT_MSB;
	SPI_Handle.Init.DFF_Format = SPI_DFF_16BIT;
	SPI_Handle.Init.Mode = SPI_MODE_MASTER;
	SPI_Handle.Init.SSM_Cmd = SPI_SSM_ENABLE;

	SPI_Init(&SPI_Handle);
	NVIC_EnableInterrupt(SPI2_IRQNumber);
	SPI_PeripheralCmd(&SPI_Handle, ENABLE);
}

static void SPI_GPIO_Config()
{
	RCC_GPIOB_CLOCK_ENABLE();

	GPIO_InitTypeDef_t GPIO_InitStruct = {0};
	GPIO_InitStruct.pinNumber = GPIO_PIN_5 | GPIO_PIN_13;
	GPIO_InitStruct.Mode = GPIO_MODE_ALTERNATE;
	GPIO_InitStruct.Alternate = GPIO_ALTERNATE_5;
	GPIO_InitStruct.Otype = GPIO_OTYPE_PUSH_PULL;
	GPIO_InitStruct.PuPd = GPIO_PuPd_NOPULL;
	GPIO_InitStruct.Speed = GPIO_SPEED_HIGH;

	GPIO_Init(GPIOB, &GPIO_InitStruct);


}

void EXTI15_10_IRQHandler()
{

	if(EXTI->PR & (0x1U << 13U ))
	{
		EXTI->PR |= (0x1U << 13U);
		flag = 1;

	}
}
void SPI2_IRQHandler()
{
	SPI_InterruptHandler(&SPI_Handle);
}
