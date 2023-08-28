/*
 * RCC.c
 *
 *  Created on: Aug 21, 2023
 *      Author: metehan.cakmak
 */
#include "rcc.h"
const uint8_t AHB_Prescaler[] = {0, 0, 0, 0, 0 , 0, 0, 1, 2, 3, 4, 6, 7, 8, 9};
const uint8_t APB_Prescaler[] = {0, 0, 0, 1, 2 , 3, 4};

uint32_t RCC_GetSystemClock()
{
	uint32_t SystemCoreClock = 0;
	uint8_t clkSource = 0;

	clkSource = ((RCC->CFGR >> 2U) & 0x3U);

	switch(clkSource)
	{
	case 0: SystemCoreClock = 16000000; break;
	case 1: SystemCoreClock = 8000000; break;
	default : SystemCoreClock = 16000000; break;

	}


	return SystemCoreClock;
}

uint32_t RCC_GetHClock()
{
	uint32_t SystemCoreClock = 0;
	uint32_t AHB_PeriphClock = 0;
	uint8_t HPre_Value = 0;
	uint8_t temp = 0;

	SystemCoreClock = RCC_GetSystemClock();


	HPre_Value = ((RCC->CFGR >> 4U) & 0xFU);
	temp = AHB_Prescaler[HPre_Value];

	AHB_PeriphClock = (SystemCoreClock >> temp);

	return AHB_PeriphClock;

}
uint32_t RCC_GetPClk1Clock()
{
	uint32_t HClock = 0;
	uint32_t PClk1_PeriphClock = 0;
	uint8_t HPre_Value = 0;
	uint8_t temp = 0;

	HClock = RCC_GetHClock();

	HPre_Value = ((RCC->CFGR >> 8U) & 0x7U);
	temp = AHB_Prescaler[HPre_Value];
	PClk1_PeriphClock = (HClock >> temp);

	return PClk1_PeriphClock;
}
uint32_t RCC_GetPClk2Clock()
{
	uint32_t HClock = 0;
	uint32_t PClk2_PeriphClock = 0;
	uint8_t HPre_Value = 0;
	uint8_t temp = 0;

	HClock = RCC_GetHClock();

	HPre_Value = ((RCC->CFGR >> 11U) & 0x7U);
	temp = AHB_Prescaler[HPre_Value];
	PClk2_PeriphClock = (HClock >> temp);

	return PClk2_PeriphClock;


}
