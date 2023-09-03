/*
 * usart.c
 *
 *  Created on: Aug 25, 2023
 *      Author: metehan.cakmak
 */

#include "usart.h"

static void closeUSART_Tx_ISR(USART_HandleTypedef_t *USART_Handle)
{
	USART_Handle->pTxBuffer = NULL;
	USART_Handle->TxBufferSizze = 0;
	USART_Handle->TxStatus = USART_BUS_FREE;

	USART_Handle->Instance->CR1 &= ~(USART_CR1_TXEIE);

}
static void closeUSART_Rx_ISR(USART_HandleTypedef_t *USART_Handle)
{
	USART_Handle->pRxBuffer = NULL;
	USART_Handle->RxBufferSize = 0;
	USART_Handle->RxStatus = USART_BUS_FREE;

	USART_Handle->Instance->CR1 &= ~(USART_CR1_RXNEIE);
}
static void USART_Send_IT(USART_HandleTypedef_t *USART_Handle)
{
	if((USART_Handle->Init.WordLenght == USART_WORDLENGHT_9BITS) && (USART_Handle->Init.Parity == USART_PARITY_NONE))
	{
		uint16_t *p16BitsData = (uint16_t*)(USART_Handle->pTxBuffer);
		USART_Handle->Instance->DR = (uint16_t)(*p16BitsData & 0x01FF);
		USART_Handle->pTxBuffer += sizeof(uint16_t);
		USART_Handle->TxBufferSizze -= 2;

	}
	else
	{
		USART_Handle->Instance->DR = (uint8_t)(*(USART_Handle->pTxBuffer) & (uint8_t)0x00FF);
		USART_Handle->pTxBuffer++;
		USART_Handle->TxBufferSizze--;
	}
	if(USART_Handle->TxBufferSizze == 0)
	{
		closeUSART_Tx_ISR(USART_Handle);
	}
}

static void USART_Read_IT(USART_HandleTypedef_t *USART_Handle)
{
	uint16_t *p16BitsBuffer;
	uint8_t *p8BitsBuffer;

	if((USART_Handle->Init.WordLenght == USART_WORDLENGHT_9BITS) && (USART_Handle->Init.Parity == USART_PARITY_NONE))
	{
		p16BitsBuffer = (uint16_t*)(USART_Handle->pRxBuffer);
		p8BitsBuffer = NULL;
	}
	else
	{
		p8BitsBuffer = (uint8_t*)(USART_Handle->pRxBuffer);
		p16BitsBuffer = NULL;
	}

	if(p8BitsBuffer == NULL)
	{
		*p16BitsBuffer = (uint16_t)(USART_Handle->Instance->DR & 0x01FF);
		USART_Handle->RxBufferSize -= 2;
		USART_Handle->pRxBuffer += sizeof(uint16_t);
	}
	else
	{
		if((USART_Handle->Init.WordLenght == USART_WORDLENGHT_9BITS) && (USART_Handle->Init.Parity != USART_PARITY_NONE))
		{
			*p8BitsBuffer = (uint8_t)(USART_Handle->Instance->DR & 0x00FF);
			USART_Handle->RxBufferSize -= 1;
			USART_Handle->pRxBuffer++;;
		}
		else if ((USART_Handle->Init.WordLenght == USART_WORDLENGHT_8BITS) && (USART_Handle->Init.Parity == USART_PARITY_NONE))
		{
			*p8BitsBuffer = (uint8_t)(USART_Handle->Instance->DR & 0x00FF);
			USART_Handle->RxBufferSize -= 1;
			USART_Handle->pRxBuffer++;;
		}
		else
		{
			*p8BitsBuffer = (uint8_t)(USART_Handle->Instance->DR & 0x007F);
			USART_Handle->RxBufferSize -= 1;
			USART_Handle->pRxBuffer++;
		}
	}

	if(USART_Handle->RxBufferSize == 0)
	{
		closeUSART_Rx_ISR(USART_Handle);
	}
}

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
void USART_Receive(USART_HandleTypedef_t *USART_Handle, uint8_t *pData, uint16_t dataSize)
{
	uint16_t *p16BitsBuffer;
	uint8_t *p8BitsBuffer;

	if((USART_Handle->Init.WordLenght == USART_WORDLENGHT_9BITS) && (USART_Handle->Init.Parity == USART_PARITY_NONE))
	{
		p16BitsBuffer = (uint16_t *)pData;
		p8BitsBuffer = NULL;
	}
	else
	{
		p8BitsBuffer = (uint8_t *)pData;
		p16BitsBuffer = NULL;
	}
	while(dataSize >0)
	{
		while(!(USART_Handle->Instance->SR & (uint32_t)USART_SR_RXNE));

		if(p8BitsBuffer == NULL)
		{
			*p16BitsBuffer = (uint16_t)(USART_Handle->Instance->DR & 0x01FF);
			p16BitsBuffer++;
			dataSize -= 2;
		}
		else
		{
			if((USART_Handle->Init.WordLenght == USART_WORDLENGHT_9BITS) && (USART_Handle->Init.Parity != USART_PARITY_NONE))
			{
				*p8BitsBuffer = (uint8_t)(USART_Handle->Instance->DR & 0x00FF);
				p8BitsBuffer++;
				dataSize -= 1;
			}
			else if ((USART_Handle->Init.WordLenght == USART_WORDLENGHT_8BITS) && (USART_Handle->Init.Parity == USART_PARITY_NONE))
			{
				*p8BitsBuffer = (uint8_t)(USART_Handle->Instance->DR & 0x00FF);
				p8BitsBuffer++;
				dataSize -= 1;
			}
			else
			{
				*p8BitsBuffer = (uint8_t)(USART_Handle->Instance->DR & 0x007F);
				p8BitsBuffer++;
				dataSize -= 1;
			}
		}
	}
}
void USART_Transmit_IT(USART_HandleTypedef_t *USART_Handle, uint8_t *pData, uint16_t dataSize)
{
	USART_BusState busState = USART_Handle->TxStatus;

	if(busState != USART_BUS_Tx)
	{
		USART_Handle->pTxBuffer = (uint8_t*)pData;
		USART_Handle->TxBufferSizze = (uint16_t)dataSize;
		USART_Handle->TxStatus = USART_BUS_Tx;
		USART_Handle->txISR_Function = USART_Send_IT;

		USART_Handle->Instance->CR1 |= USART_CR1_TXEIE;
	}


}
void USART_Receive_IT(USART_HandleTypedef_t *USART_Handle, uint8_t *pData, uint16_t dataSize)
{
	USART_BusState busState = USART_Handle->RxStatus;

	if(busState != USART_BUS_Rx)
	{
		USART_Handle->pRxBuffer = (uint8_t*)pData;
		USART_Handle->RxBufferSize = (uint16_t)dataSize;
		USART_Handle->RxStatus = USART_BUS_Rx;
		USART_Handle->rxISR_Function = USART_Read_IT;

		USART_Handle->Instance->CR1 |= USART_CR1_RXNEIE;

	}

}
void USART_InterruptHandler(USART_HandleTypedef_t *USART_Handle)
{
	uint8_t flagValue = 0;
	uint8_t interruptValue = 0;

	flagValue = (uint8_t)((USART_Handle->Instance->SR >> USART_SR_TXE_POS) & 0x1);
	interruptValue = (uint8_t)((USART_Handle->Instance->CR1 >> USART_CR1_TXEIE_POS) & 0x1);

	if( flagValue && interruptValue)
	{
		USART_Handle->txISR_Function(USART_Handle);
	}

	flagValue = (uint8_t)((USART_Handle->Instance->SR >> USART_SR_RXNE_POS) & (0x1));
	interruptValue = (uint8_t)((USART_Handle->Instance->CR1 >> USART_CR1_RXNEIE_POS) & (0x1));

	if( flagValue && interruptValue)
		{
			USART_Handle->rxISR_Function(USART_Handle);
		}

}
