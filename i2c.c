/*
 * i2c.c
 *
 *  Created on: Sep 3, 2023
 *      Author: meteh
 */

#include "i2c.h"


void I2C_Enable(I2C_Typedef_t *I2Cx, FunctionalState_t stateofI2C)
{
	if( stateofI2C == ENABLE)
	{
		I2Cx->CR1 |= I2C_CR1_PE;
	}
	else
	{
		I2Cx->CR1 &= ~(I2C_CR1_PE);
	}
}

void I2C_Init(I2C_HandleTypedef_t *I2C_Handle)
{
	uint32_t pClock = 0x0U;

	pClock = RCC_GetPClk1Clock();

	if(CHECK_PCLOCK_VALUE(pClock, I2C_Handle->Init->ClockSpeed) != 1U)
	{
		uint32_t temp = 0x0U;
		uint32_t freqValue = 0x0U;

		// ACK State	Stretch Mode
		temp = I2C_Handle->Instance->CR1;
		temp |= (I2C_Handle->Init->ACK_STATE) | (I2C_Handle->Init->ClockStretch);

		I2C_Handle->Instance->CR1 = temp;

		// Frequence Value
		freqValue = I2C_GET_FREQ_VALUE(pClock);

		temp = I2C_Handle->Instance->CR2;
		temp |= (freqValue << 0U);

		I2C_Handle->Instance->CR2 = temp;

		// Address Conf
		temp = I2C_Handle->Instance->OAR1;
		temp|= (I2C_Handle->Init->AddressingMode);

		if(I2C_Handle->Init->AddressingMode == I2C_ADDRMODE_7)
		{
			temp|= (I2C_Handle->Init->MyOwnAddress << 1U);
		}
		else
		{
			temp|= (I2C_Handle->Init->MyOwnAddress << 0U);
		}


	}

}
