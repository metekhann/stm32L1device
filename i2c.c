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
		uint16_t ccrValue = 0x0U;

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

		I2C_Handle->Instance->OAR1 = temp;

		// CCR Calculations

		temp = 0;
		if(I2C_Handle->Init->ClockSpeed <= I2C_SPEED_STANDART)
		{
			// standard mode
			ccrValue = (pClock / (2 * I2C_Handle->Init->ClockSpeed));
			temp |= (I2C_DUTY_STANDART);
			temp |= (ccrValue & 0xFFF);


		}
		else
		{
			// fast mode
			if(I2C_Handle->Init->DutyCycle == I2C_DUTY_FAST_2)
			{
				// Duty 2
				temp |= (I2C_DUTY_FAST_2);
				ccrValue = (pClock / (3 * I2C_Handle->Init->ClockSpeed));
			}
			else
			{
				// Duty 16 : 9
				temp |= (I2C_DUTY_FAST_16_2);
				ccrValue = (pClock / (25 * I2C_Handle->Init->ClockSpeed));
			}

			temp |= (ccrValue & 0xFFFU);
		}

		I2C_Handle->Instance->CCR = temp;
	}

}
