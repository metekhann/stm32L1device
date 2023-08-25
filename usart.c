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
		while(USART_Handle->Instance->SR && USART_SR_TXE);

		if(data16bits == NULL)
		{
			USART_Handle->Instance->DR = (uint16_t)*pData;
		}
		else
		{
			USART_Handle->Instance->DR = (uint16_t)(*data16bits & (0x01FFU));
			data16bits++;
			dataSize -= 2;
		}

	}

	while(! (USART_Handle->Instance->SR && USART_SR_TC) );
}
