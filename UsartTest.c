/*
 * UsartTest.c
 *
 *  Created on: Aug 28, 2023
 *      Author: meteh
 */

#include "stm32L1device.h"

USART_HandleTypedef_t huart;

static void GPIO_Config(void);
static void USART_Config(void);
int main(void)
{
	USART_Config();
	GPIO_Config();
	while(1)
	{
		USART_Transmit(&huart, (uint8_t *)"hello\n", 7);
	}
}
static void USART_Config(void)
{
	RCC_USART2_CLK_ENABLE();

	huart.Instance = USART2;
	huart.Init.BaudRate = 115200;
	huart.Init.HardwareFlowControl = USART_HW_NONE;
	huart.Init.Mode = USART_MODE_TX;
	huart.Init.OverSampling = USART_OVERSAMPLING_16;
	huart.Init.StopBits = USART_STOPBIT_1;
	huart.Init.Parity = USART_PARITY_NONE;
	huart.Init.WordLenght = USART_WORDLENGHT_8BITS;

	USART_Init(&huart);
	USART_Enable(&huart, ENABLE);
}

static void GPIO_Config(void)
{
	RCC_GPIOD_CLOCK_ENABLE();

	GPIO_InitTypeDef_t GPIO_InitStruct = {0};

	GPIO_InitStruct.pinNumber = (GPIO_PIN_5 | GPIO_PIN_6);
	GPIO_InitStruct.Mode = GPIO_MODE_ALTERNATE;
	GPIO_InitStruct.Otype = GPIO_OTYPE_PUSH_PULL;
	GPIO_InitStruct.PuPd = GPIO_PuPd_NOPULL;
	GPIO_InitStruct.Speed = GPIO_SPEED_VERY;
	GPIO_InitStruct.Alternate = GPIO_ALTERNATE_7;

	GPIO_Init(GPIOD, &GPIO_InitStruct);


}
