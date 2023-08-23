/*
 * gpio.c
 *
 *  Created on: Aug 22, 2023
 *      Author: metehan.cakmak
 */

#include "gpio.h"

void GPIO_Init(GPIO_TypeDef_t *GPIOx, GPIO_InitTypeDef_t *GPIO_Config)
{

	uint32_t position;
	uint32_t fake_position;
	uint32_t last_position;

	for(position = 0; position < 16; position++)
	{
		fake_position = (0x1U << position);
		last_position = (GPIO_Config->pinNumber) & fake_position;
		if(fake_position == last_position)
		{

			/* Mode Config */

			uint32_t temp_value = GPIOx->MODER;
			temp_value &= ~(0x3U << (position * 2));							//clear bits
			temp_value |= (GPIO_Config->Mode << (position * 2));				//set bits
			GPIOx->MODER = temp_value;

			if(GPIO_Config->Mode == GPIO_MODE_INPUT || GPIO_Config->Mode == GPIO_MODE_ANALOG)
			{
				/* Output Type Config */
				temp_value = GPIOx->OTYPER;
				temp_value &= ~(0x1 << position);								//clear bit
				temp_value |= (GPIO_Config->Otype << position);					//set bit
				GPIOx->OTYPER = temp_value;

				/* Output Speed Config */
				temp_value = GPIOx->OSPEEDR;
				temp_value &= ~(0x3U) << (position * 2);						//clear bits
				temp_value |= (GPIO_Config->Speed << (position * 2));			//set bits
				GPIOx->OSPEEDR = temp_value;
			}
			/* Push Pull Config */
			temp_value = GPIOx->PUPDR;
			temp_value &= ~(0x3U) << (position * 2);
			temp_value |= (GPIO_Config->PuPd << (position * 2));
			GPIOx->PUPDR = temp_value;

		}

	}
}

void GPIO_WritePin(GPIO_TypeDef_t *GPIOx, uint16_t pinNumber, GPIO_PinState_t pinState )
{
	if(pinState == GPIO_Pin_Set)
	{
		GPIOx->BSRR = pinNumber;
	}
	else
	{
		GPIOx->BSRR = (pinNumber << 16);
	}
}

GPIO_PinState_t GPIO_ReadPin(GPIO_TypeDef_t *GPIOx, uint16_t pinNumber)
{
	GPIO_PinState_t bitStatus = GPIO_Pin_Reset;
	if((GPIOx->IDR & pinNumber)	!=	GPIO_Pin_Reset)
	{
		bitStatus = GPIO_Pin_Set;
	}
	return bitStatus;
}
void GPIO_LockPin(GPIO_TypeDef_t *GPIOx, uint16_t pinNumber)
{
	uint32_t temp = (0x1U << 16) | pinNumber;
	GPIOx->LCKR = temp;
	GPIOx->LCKR = pinNumber;
	GPIOx->LCKR = temp;
	temp = GPIOx->LCKR;
}

void GPIO_TogglePin(GPIO_TypeDef_t *GPIOx, uint16_t pinNumber)
{
	uint32_t temp = GPIOx->ODR;
	GPIOx->BSRR = ((temp & pinNumber) << 16U) | (~temp & pinNumber);
}
