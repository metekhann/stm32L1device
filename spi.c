/*
 * spi.c
 *
 *  Created on: 23 Ağu 2023
 *      Author: meteh
 */

#include "spi.h"

static void SPI_CloseISR_TX(SPI_HandleTypeDef_t *SPI_Handle_Struct)
{
	SPI_Handle_Struct->Instance->CR2 &= ~(SPI_CR2_TXEIE);
	SPI_Handle_Struct->TxDataSize = 0;
	SPI_Handle_Struct->pTxDataAddr = NULL;
	SPI_Handle_Struct = SPI_BUS_FREE;
}

static void SPI_TransmitHelper_16Bits(SPI_HandleTypeDef_t *SPI_Handle_Struct)
{
	SPI_Handle_Struct->Instance->DR = *( (uint16_t*)(SPI_Handle_Struct ->pTxDataAddr) );
	SPI_Handle_Struct->pTxDataAddr += sizeof(uint16_t);
	SPI_Handle_Struct->TxDataSize -= 2;
}

static void SPI_TransmitHelper_8Bits(SPI_HandleTypeDef_t *SPI_Handle_Struct)
{
	SPI_Handle_Struct->Instance->DR = *( (uint8_t*)(SPI_Handle_Struct ->pTxDataAddr) );
	SPI_Handle_Struct->pTxDataAddr += sizeof(uint8_t);
	SPI_Handle_Struct->TxDataSize -= 1;
	if(SPI_Handle_Struct->TxDataSize == 0)
	{
		SPI_CloseISR_TX(SPI_Handle_Struct);
	}
}

void SPI_Init(SPI_HandleTypeDef_t *SPI_Handle_Struct)
{
	uint32_t temp = SPI_Handle_Struct->Instance->CR1;
	temp |= (SPI_Handle_Struct->Init.BaudRate) | (SPI_Handle_Struct->Init.CPHA) | (SPI_Handle_Struct->Init.CPOL) | (SPI_Handle_Struct->Init.DFF_Format) | \
			(SPI_Handle_Struct->Init.Mode) | (SPI_Handle_Struct->Init.FrameFormat) | (SPI_Handle_Struct->Init.BusConfig) | (SPI_Handle_Struct->Init.SSM_Cmd);
	SPI_Handle_Struct->Instance->CR1 = temp;
}

void SPI_PeripheralCmd(SPI_HandleTypeDef_t *SPI_Handle_Struct, FunctionalState_t stateOfSPI)
{
	if(stateOfSPI == ENABLE)
	{
		SET_BIT(SPI_Handle_Struct->Instance->CR1, SPI_CR1_SPE);
	}
	else
	{
		CLEAR_BIT(SPI_Handle_Struct->Instance->CR1, SPI_CR1_SPE);
	}
}

void SPI_TransmitData(SPI_HandleTypeDef_t *SPI_Handle_Struct, uint8_t *pData, uint16_t sizeofData)
{

	if(SPI_Handle_Struct->Init.DFF_Format == SPI_DFF_16BIT)
	{
		while(sizeofData > 0)
		{
			if(SPI_Handle_Struct->Instance->SR & SPI_SR_TXE)
			{
				SPI_Handle_Struct->Instance->DR = *((uint16_t*)pData);
				pData += sizeof(uint16_t);
				sizeofData -= 2 ;
			}
		}
	}
	else
	{
		while(sizeofData > 0)
		{
			if(SPI_Handle_Struct->Instance->SR & SPI_SR_TXE)
			{
				SPI_Handle_Struct->Instance->DR = *((uint16_t*)pData);
				 pData += sizeof(uint8_t);
				 sizeofData--;
			}
		}
	}
	while(SPI_Handle_Struct->Instance->SR & SPI_SR_BSY);
}

void SPI_TransmitData_IT(SPI_HandleTypeDef_t *SPI_Handle_Struct, uint8_t *pData, uint16_t sizeofData)
{
	SPI_BusStatus_t busState = SPI_Handle_Struct->BusStateTx;

	if(busState != SPI_BUS_BUSY_TX)
	{
		SPI_Handle_Struct->pTxDataAddr = (uint8_t*)pData;
		SPI_Handle_Struct->TxDataSize = (uint16_t)sizeofData;
		SPI_Handle_Struct->BusStateTx = SPI_BUS_BUSY_TX;

		if(SPI_Handle_Struct->Instance->CR1 & SPI_CR1_DFF)
		{
			SPI_Handle_Struct->TxISRFunction = SPI_TransmitHelper_16Bits;
		}
		else
		{
			SPI_Handle_Struct->TxISRFunction = SPI_TransmitHelper_8Bits;
		}

		SPI_Handle_Struct->Instance->CR2 |= (SPI_CR2_TXEIE);
	}
}
void SPI_InterruptHandler(SPI_HandleTypeDef_t *SPI_Handle_Struct)
{
	uint8_t interruptSource = 0;
	uint8_t interruptFlag = 0;

	interruptSource = SPI_Handle_Struct->Instance->CR2 & SPI_CR2_TXEIE;
	interruptFlag = SPI_Handle_Struct->Instance->CR2 & SPI_SR_TXE;

	if((interruptSource != 0) && (interruptFlag != 0))
	{
		SPI_Handle_Struct->TxISRFunction(SPI_Handle_Struct);
	}
}

