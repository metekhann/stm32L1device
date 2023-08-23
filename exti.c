/*
 * exti.c
 *
 *  Created on: Aug 23, 2023
 *      Author: metehan.cakmak
 */
#include "exti.h"



void EXTI_Init(EXTI_InitTypeDef_t *EXTI_InitStruct)
{
	uint32_t temp = 0;
	temp = (uint32_t)EXTI_BASE_ADRR;
	EXTI->IMR &= ~(0x1U << EXTI_InitStruct->EXTI_LineNumber);
	EXTI->EMR &= ~(0x1U << EXTI_InitStruct->EXTI_LineNumber);
	EXTI->RTSR &= ~(0x1U << EXTI_InitStruct->EXTI_LineNumber);
	EXTI->FTSR &= ~(0x1U << EXTI_InitStruct->EXTI_LineNumber);

	if(EXTI_InitStruct->TriggerSelection != DISABLE)
	{
		temp += EXTI_InitStruct->EXTI_Mode;
		*( (__IO uint32_t*)temp ) |= (0x1U << EXTI_InitStruct->EXTI_LineNumber);
		temp = (uint32_t)EXTI_BASE_ADRR;


		if(EXTI_InitStruct->TriggerSelection == EXTI_TRIGGER_RF)
		{
			EXTI->RTSR |= (EXTI_InitStruct->EXTI_LineNumber);
			EXTI->FTSR |= (EXTI_InitStruct->EXTI_LineNumber);
		}
		else
		{
			temp += EXTI_InitStruct->TriggerSelection;
			*((__IO uint32_t *)temp ) |= (0x1U << EXTI_InitStruct->EXTI_LineNumber);
		}

	}
	else//bence bu else gereksiz if e girmezse zaten disable ediyoruz her seyi
	{
		temp = (uint32_t)EXTI_BASE_ADRR;
		temp += EXTI_InitStruct->EXTI_Mode;
		*( (__IO uint32_t*)temp ) &= ~(0x1U << EXTI_InitStruct->EXTI_LineNumber);
	}
}

void EXTI_LineConfig(uint8_t PortSource, uint8_t EXTI_LineSource)
{
	uint32_t temp;
	temp = SYSCFG->EXTI_CR[EXTI_LineSource >> 2];   		// 4 e bolerek hangi EXTI register'a geldigini bulduk
	temp &= ~(0xFU << (EXTI_LineSource & 0x3U) * 4);		// clear bits
	temp |= (PortSource << (EXTI_LineSource & 0x3U) * 4);	// set bits
	SYSCFG->EXTI_CR[EXTI_LineSource >> 2] = temp;
}
void NVIC_EnableInterrupt(IRQ_Number_TypeDef_t IRQ_Number)
{
	uint32_t temp = 0;
	temp = *( (IRQ_Number >> 5U) + NVIC_ISER0);
	temp  &= ~(0x1U <<(IRQ_Number & 0x1FU ));
	temp |= (0x1U << (IRQ_Number & 0x1FU));
	*( (IRQ_Number >> 5U ) + NVIC_ISER0) = temp;
}

