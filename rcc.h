/*
 * rcc.h
 *
 *  Created on: Aug 22, 2023
 *      Author: meteh
 */

#ifndef INC_RCC_H_
#define INC_RCC_H_
#include "stm32L1device.h"

#define RCC_GPIOA_CLOCK_ENABLE()		do{	uint32_t temp = 0;									\
											SET_BIT(RCC->AHBENR, RCC_AHBENR_GPIOAEN);			\
											temp = READ_BIT(RCC->AHBENR, RCC_AHBENR_GPIOAEN);	\
											UNUSED(temp);										\
										}while(0)

#define RCC_GPIOB_CLOCK_ENABLE()		do{	__IO uint32_t temp;									\
											SET_BIT(RCC->AHBENR, RCC_AHBENR_GPIOBEN);			\
											temp = READ_BIT(RCC->AHBENR, RCC_AHBENR_GPIOBEN);	\
											UNUSED(temp);										\
										}while(0)
#define __HAL_RCC_GPIOA_CLK_ENABLE()   do { 													\
                                        __IO uint32_t tmpreg; 									\
                                        SET_BIT(RCC->AHBENR, RCC_AHBENR_GPIOAEN);				\
                                        /* Delay after an RCC peripheral clock enabling */		\
                                        tmpreg = READ_BIT(RCC->AHBENR, RCC_AHBENR_GPIOAEN);		\
                                        UNUSED(tmpreg); 										\
                                      } while(0U)

#define RCC_GPIOC_CLOCK_ENABLE()		do{	uint32_t temp = 0;									\
											SET_BIT(RCC->AHBENR, RCC_AHBENR_GPIOCEN);			\
											temp = READ_BIT(RCC->AHBENR, RCC_AHBENR_GPIOCEN);	\
											UNUSED(temp);										\
										}while(0)

#define RCC_GPIOD_CLOCK_ENABLE()		do{	uint32_t temp = 0;									\
											SET_BIT(RCC->AHBENR, RCC_AHBENR_GPIODEN);			\
											temp = READ_BIT(RCC->AHBENR, RCC_AHBENR_GPIODEN);	\
											UNUSED(temp);										\
										}while(0)

#define RCC_GPIOE_CLOCK_ENABLE()		do{	uint32_t temp = 0;									\
											SET_BIT(RCC->AHBENR, RCC_AHBENR_GPIOEEN);			\
											temp = READ_BIT(RCC->AHBENR, RCC_AHBENR_GPIOEEN);	\
											UNUSED(temp);										\
										}while(0)

#define RCC_GPIOF_CLOCK_ENABLE()		do{	uint32_t temp = 0;									\
											SET_BIT(RCC->AHBENR, RCC_AHBENR_GPIOFEN);			\
											temp = READ_BIT(RCC->AHBENR, RCC_AHBENR_GPIOFEN);	\
											UNUSED(temp);										\
										}while(0)

#define RCC_GPIOG_CLOCK_ENABLE()		do{	uint32_t temp = 0;									\
											SET_BIT(RCC->AHBENR, RCC_AHBENR_GPIOGEN);			\
											temp = READ_BIT(RCC->AHBENR, RCC_AHBENR_GPIOGEN);	\
											UNUSED(temp);										\
										}while(0)

#define RCC_GPIOH_CLOCK_ENABLE()		do{	uint32_t temp = 0;									\
											SET_BIT(RCC->AHBENR, RCC_AHBENR_GPIOHEN);			\
											temp = READ_BIT(RCC->AHBENR, RCC_AHBENR_GPIOHEN);	\
											UNUSED(temp);										\
										}while(0)

#define RCC_SYSCFG_CLK_ENABLE()			do{	uint32_t temp = 0;									 \
											SET_BIT(RCC->APB2ENR, RCC_APB2ENR_SYSCFGEN);		 \
											temp = READ_BIT(RCC->APB2ENR, RCC_APB2ENR_SYSCFGEN); \
											UNUSED(temp);										 \
										}while(0)

#define RCC_SPI1_CLK_ENABLE()			do{	uint32_t temp = 0;									 \
											SET_BIT(RCC->APB2ENR, RCC_APB2ENR_SPI1);			 \
											temp = READ_BIT(RCC->APB2ENR, RCC_APB2ENR_SPI1); 	 \
											UNUSED(temp);										 \
										}while(0)

#define RCC_SPI2_CLK_ENABLE()			do{	uint32_t temp = 0;									 \
											SET_BIT(RCC->APB1ENR, RCC_APB1ENR_SPI2);			 \
											temp = READ_BIT(RCC->APB1ENR, RCC_APB1ENR_SPI2); 	 \
											UNUSED(temp);										 \
										}while(0)

#define RCC_SPI3_CLK_ENABLE()			do{	uint32_t temp = 0;									 \
											SET_BIT(RCC->APB1ENR, RCC_APB1ENR_SPI2);			 \
											temp = READ_BIT(RCC->APB1ENR, RCC_APB1ENR_SPI2); 	 \
											UNUSED(temp);										 \
										}while(0)

#define RCC_USART2_CLK_ENABLE()			do{	uint32_t temp = 0;									 \
											SET_BIT(RCC->APB1ENR, RCC_APB1ENR_USART2);			 \
											temp = READ_BIT(RCC->APB1ENR, RCC_APB1ENR_USART2); 	 \
											UNUSED(temp);										 \
										}while(0)

#define RCC_USART1_CLK_ENABLE()			do{	uint32_t temp = 0;									 \
											SET_BIT(RCC->APB2ENR, RCC_APB2ENR_USART1);			 \
											temp = READ_BIT(RCC->APB2ENR, RCC_APB2ENR_USART1); 	 \
											UNUSED(temp);										 \
										}while(0)

#define RCC_I2C1_CLK_ENABLE()			do{	uint32_t temp = 0;									 \
											SET_BIT(RCC->APB1ENR, RCC_APB1ENR_I2C1);			 \
											temp = READ_BIT(RCC->APB1ENR, RCC_APB1ENR_I2C1); 	 \
											UNUSED(temp);										 \
										}while(0)

#define RCC_I2C2_CLK_ENABLE()			do{	uint32_t temp = 0;									 \
											SET_BIT(RCC->APB1ENR, RCC_APB1ENR_I2C2);			 \
											temp = READ_BIT(RCC->APB1ENR, RCC_APB1ENR_I2C2); 	 \
											UNUSED(temp);										 \
										}while(0)


#define RCC_GPIOA_CLOCK_DISABLE()		CLEAR_BIT(RCC->AHBENR, RCC_AHBENR_GPIOAEN)
#define RCC_GPIOB_CLOCK_DISABLE()		CLEAR_BIT(RCC->AHBENR, RCC_AHBENR_GPIOBEN)
#define RCC_GPIOC_CLOCK_DISABLE()		CLEAR_BIT(RCC->AHBENR, RCC_AHBENR_GPIOCEN)
#define RCC_GPIOD_CLOCK_DISABLE()		CLEAR_BIT(RCC->AHBENR, RCC_AHBENR_GPIODEN)
#define RCC_GPIOE_CLOCK_DISABLE()		CLEAR_BIT(RCC->AHBENR, RCC_AHBENR_GPIOEEN)
#define RCC_GPIOF_CLOCK_DISABLE()		CLEAR_BIT(RCC->AHBENR, RCC_AHBEN_GPIOFEN)
#define RCC_GPIOG_CLOCK_DISABLE()		CLEAR_BIT(RCC->AHBENR, RCC_AHBENR_GPIOGEN)
#define RCC_GPIOH_CLOCK_DISABLE()		CLEAR_BIT(RCC->AHBENR, RCC_AHBENR_GPIOHEN)

#define RCC_SYSCFG_CLK_DISABLE()		CLEAR_BIT((RCC->APB2ENR, RCC_APB2ENR_SYSCFGEN)

#define RCC_SPI1_CLK_DISABLE()			CLEAR_BIT(RCC->APB2ENR, RCC_APB2ENR_SPI1)
#define RCC_SPI2_CLK_DISABLE()			CLEAR_BIT(RCC->APB1ENR, RCC_APB1ENR_SPI2)
#define RCC_SPI3_CLK_DISABLE()			CLEAR_BIT(RCC->APB1ENR, RCC_APB2ENR_SPI3)
#define RCC_USART2_CLK_DISABLE()		CLEAR_BIT(RCC->APB1ENR, RCC_APB1ENR_USART2)

#define RCC_I2C1_CLK_DISABLE()			CLEAR_BIT(RCC->APB1ENR, RCC_APB1ENR_I2C1)
#define RCC_I2C2_CLK_DISABLE()			CLEAR_BIT(RCC->APB1ENR, RCC_APB1ENR_I2C2)


uint32_t RCC_GetSystemClock();
uint32_t RCC_GetHClock();
uint32_t RCC_GetPClk1Clock();
uint32_t RCC_GetPClk2Clock();

#endif /* INC_RCC_H_ */
