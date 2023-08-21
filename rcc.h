/*
 * rcc.h
 *
 *  Created on: Aug 22, 2023
 *      Author: meteh
 */

#ifndef INC_RCC_H_
#define INC_RCC_H_

#define RCC_GPIOA_CLOCK_ENABLE()		do{	uint32_t temp = 0;								\
											SET_BIT(RCC->AHBE, RCC_AHBE_GPIOAEN)			\
											temp = READ_BIT(RCC->AHBE, RCC_AHBE_GPIOAEN)	\
											UNUSED(temp)									\
										}while(0)
#define RCC_GPIOB_CLOCK_ENABLE()		do{	uint32_t temp = 0;								\
											SET_BIT(RCC->AHBE, RCC_AHBE_GPIOBEN)			\
											temp = READ_BIT(RCC->AHBE, RCC_AHBE_GPIOBEN)	\
											UNUSED(temp)									\
										}while(0)
#define RCC_GPIOC_CLOCK_ENABLE()		do{	uint32_t temp = 0;								\
											SET_BIT(RCC->AHBE, RCC_AHBE_GPIOCEN)			\
											temp = READ_BIT(RCC->AHBE, RCC_AHBE_GPIOCEN)	\
											UNUSED(temp)									\
										}while(0)
#define RCC_GPIOD_CLOCK_ENABLE()		do{	uint32_t temp = 0;								\
											SET_BIT(RCC->AHBE, RCC_AHBE_GPIODEN)			\
											temp = READ_BIT(RCC->AHBE, RCC_AHBE_GPIODEN)	\
											UNUSED(temp)									\
										}while(0)
#define RCC_GPIOE_CLOCK_ENABLE()		do{	uint32_t temp = 0;								\
											SET_BIT(RCC->AHBE, RCC_AHBE_GPIOEEN)			\
											temp = READ_BIT(RCC->AHBE, RCC_AHBE_GPIOEEN)	\
											UNUSED(temp)									\
										}while(0)
#define RCC_GPIOF_CLOCK_ENABLE()		do{	uint32_t temp = 0;								\
											SET_BIT(RCC->AHBE, RCC_AHBE_GPIOFEN)			\
											temp = READ_BIT(RCC->AHBE, RCC_AHBE_GPIOFEN)	\
											UNUSED(temp)									\
										}while(0)
#define RCC_GPIOG_CLOCK_ENABLE()		do{	uint32_t temp = 0;								\
											SET_BIT(RCC->AHBE, RCC_AHBE_GPIOGEN)			\
											temp = READ_BIT(RCC->AHBE, RCC_AHBE_GPIOGEN)	\
											UNUSED(temp)									\
										}while(0)
#define RCC_GPIOH_CLOCK_ENABLE()		do{	uint32_t temp = 0;								\
											SET_BIT(RCC->AHBE, RCC_AHBE_GPIOHEN)			\
											temp = READ_BIT(RCC->AHBE, RCC_AHBE_GPIOHEN)	\
											UNUSED(temp)									\
										}while(0)

#define RCC_GPIOA_CLOCK_DISABLE()		CLEAR_BIT(RCC->AHBE, RCC_AHBE_GPIOAEN)
#define RCC_GPIOB_CLOCK_DISABLE()		CLEAR_BIT(RCC->AHBE, RCC_AHBE_GPIOBEN)
#define RCC_GPIOC_CLOCK_DISABLE()		CLEAR_BIT(RCC->AHBE, RCC_AHBE_GPIOCEN)
#define RCC_GPIOD_CLOCK_DISABLE()		CLEAR_BIT(RCC->AHBE, RCC_AHBE_GPIODEN)
#define RCC_GPIOE_CLOCK_DISABLE()		CLEAR_BIT(RCC->AHBE, RCC_AHBE_GPIOEEN)
#define RCC_GPIOF_CLOCK_DISABLE()		CLEAR_BIT(RCC->AHBE, RCC_AHBE_GPIOFEN)
#define RCC_GPIOG_CLOCK_DISABLE()		CLEAR_BIT(RCC->AHBE, RCC_AHBE_GPIOGEN)
#define RCC_GPIOH_CLOCK_DISABLE()		CLEAR_BIT(RCC->AHBE, RCC_AHBE_GPIOHEN)




#include "rcc.h"
#endif /* INC_RCC_H_ */
