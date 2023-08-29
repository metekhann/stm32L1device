/*
 * usart.c
 *
 *  Created on: Aug 25, 2023
 *      Author: metehan.cakmak
 */

#include "usart.h"

void USART_Init(USART_HandleTypedef_t *USART_Handle)
{
	uint32_t tempReg= 0;
	uint32_t periphClk = 0;
	uint32_t mantissaPart = 0;
	uint32_t fractionPart = 0;
	uint32_t USART_DIV_Value = 0;
	uint32_t temp = 0;

	/*****	OverSampling********	WordLenght	******	Mode	**************	Parity	*************/
	tempReg = USART_Handle->Instance->CR1;
	tempReg |= (USART_Handle->Init.OverSampling) | (USART_Handle->Init.WordLenght) | (USART_Handle->Init.Mode) | (USART_Handle->Init.Parity);
	USART_Handle->Instance->CR1 = tempReg;
/***********************StopBits****************************************/
	tempReg = USART_Handle->Instance->CR2;
	tempReg &= ~(USART_CR2_STOP_0 | USART_CR2_STOP_1);

	tempReg |= (USART_Handle->Init.StopBits);
	USART_Handle->Instance->CR2 = tempReg;
	/************	HardwareFlowControl      ********************************************/
	tempReg = USART_Handle->Instance->CR3;
	tempReg |= (USART_Handle->Init.HardwareFlowControl);
	USART_Handle->Instance->CR3 = tempReg;

	/** Baud Rate */
	if(USART_Handle->Instance == USART1)
	{
		periphClk = RCC_GetPClk2Clock();
	}
	else
	{
		periphClk = RCC_GetPClk1Clock();
	}


	if(USART_Handle->Init.OverSampling == USART_OVERSAMPLING_8)
	{
		USART_Handle->Instance->BRR = UART_BRR_SAMPLING8(periphClk, USART_Handle->Init.BaudRate);
		//USART_Handle->Instance->BRR = __UART_BRR_OVERSAMPLING_8(periphClk, USART_Handle->Init.BaudRate);
		/*USART_DIV_Value = __UART_BRR_OVERSAMPLING_8(periphClk, USART_Handle->Init.BaudRate);
		mantissaPart = (USART_DIV_Value / 100U);
		fractionPart = (USART_DIV_Value) - (mantissaPart * 100U);
		fractionPart = (((fractionPart * 8U) + 50U) / 100U) & (0x07U);*/


	}
	else
	{
		USART_Handle->Instance->BRR = UART_BRR_SAMPLING16(periphClk, USART_Handle->Init.BaudRate);
		//USART_Handle->Instance->BRR = __UART_BRR_OVERSAMPLING_16(periphClk, USART_Handle->Init.BaudRate);
		/*USART_DIV_Value = __UART_BRR_OVERSAMPLING_16(periphClk, USART_Handle->Init.BaudRate);
		mantissaPart = (USART_DIV_Value / 100U);
		fractionPart = (USART_DIV_Value) - (mantissaPart * 100U);
		fractionPart = (((fractionPart * 16U) + 50U) / 100U) & (0x0FU);*/
	}

	/*temp |= (mantissaPart << 4U);
	temp |= (fractionPart << 0U);
	USART_Handle->Instance->BRR = temp;*/
}

void USART_Enable(USART_HandleTypedef_t *USART_Handle , FunctionalState_t State)
{
	if(State == ENABLE)
	{
		USART_Handle->Instance->CR1 |= (0x1U << 13U);
	}
	else
	{
		USART_Handle->Instance->CR1 &= ~(0x1U << 13U);
	}
}

void USART_Transmit(USART_HandleTypedef_t *USART_Handle, uint8_t *pData, uint16_t dataSize)
{
	uint16_t * data16bits;

	if((USART_Handle->Init.WordLenght == USART_WORDLENGHT_9BITS) && (USART_Handle->Init.Parity == USART_PARITY_NONE))
	{
		data16bits = (uint16_t*)pData;
	}
	else
	{
		data16bits = NULL;
	}

	while(dataSize > 0)
	{
		while(!(USART_Handle->Instance->SR & (uint32_t)USART_SR_TXE));

		if(data16bits == NULL)
		{
			USART_Handle->Instance->DR = (uint8_t)(*pData & 0xFFU);
			pData++;
			dataSize -= 1;
		}
		else
		{
			USART_Handle->Instance->DR = (uint16_t)(*data16bits & (0x01FFU));
			data16bits++;
			dataSize -= 2;
		}

	}

	while(! (USART_Handle->Instance->SR & USART_SR_TC) );
}
