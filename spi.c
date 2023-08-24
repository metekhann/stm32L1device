/*
 * spi.c
 *
 *  Created on: 23 Ağu 2023
 *      Author: meteh
 */

#include "spi.h"

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

void SPI_TransmitData(SPI_HandleTypeDef_t *SPI_HandleStruct, uint8_t *pData, uint16_t sizeofData)
{

	if(SPI_HandleStruct->Init.DFF_Format == SPI_DFF_16BIT)
	{
		while(sizeofData > 0)
		{
			if(SPI_HandleStruct->Instance->SR & SPI_SR_TXE)
			{
				SPI_HandleStruct->Instance->DR = *((uint16_t*)pData);
				pData += sizeof(uint16_t);
				sizeofData -= 2 ;
			}
		}
	}
	else
	{
		while(sizeofData > 0)
		{
			if((SPI_HandleStruct->Instance->SR >> 1) & 0x1U)
			{
				SPI_HandleStruct->Instance->DR = *((uint16_t*)pData);
				 pData += sizeof(uint8_t);
				 sizeofData--;
			}
		}
	}
	while(SPI_HandleStruct->Instance->SR & SPI_SR_BSY);
}


