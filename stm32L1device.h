/*
 * stm32L1_device.h
 *
 *  Created on: Aug 21, 2023
 *      Author: metehan.cakmak
 */

#ifndef INC_STM32L1_DEVICE_H_
#define INC_STM32L1_DEVICE_H_

#include <stdint.h>
#include <stddef.h>
#include <string.h>
#include <stdarg.h>
#include <stdlib.h>
/*
 * MircoProcessor Defines
 *
 */
#define NVIC_ISER0					((uint32_t*)(0xE000E100))

#define SET_BIT(REG, BIT)			( (REG) |= (BIT) )
#define CLEAR_BIT(REG, BIT)			( (REG) &= ~(BIT) )
#define READ_BIT(REG, BIT)			( (REG) & (BIT) )
#define UNUSED(x)					((void)x)
#define __IO volatile

typedef enum
{
	DISABLE = 0x0U,
	ENABLE = !DISABLE
}FunctionalState_t;

/*
 * IRQ Numbers of MCU = Vector Table
 *
 */
typedef enum
{
	EXTI0_IRQNumber = 6,
	EXTI1_IRQNumber = 7,
	EXTI2_IRQNumber = 8,
	EXTI3_IRQNumber = 9,
	EXTI4_IRQNumber = 10,
	SPI2_IRQNumber = 36,
	USART1_IRQNumber =37,
	EXTI15_10_IRQNumber = 40


}IRQ_Number_TypeDef_t;


/*
 * Memory Base Addresses
 *
 */

#define FLASH_BASE_ADRR				(0X08000000) /*!< Base Address of : FLASH > 	*/
#define SRAM_BASE_ADRR				(0x20000000) /*!< Base Address of : SRAM > 		*/

/*
 * Peripheral Base Addresses
 *
 */

#define PERIPHERAL_BASE_ADRR 		(0x40000000) 						/*< Base Address of : Peripheral >	*/

#define APB1_BASE_ADRR				(PERIPHERAL_BASE_ADRR) 				/*< Base Address of : APB1 Bus   >  */
#define APB2_BASE_ADRR				(PERIPHERAL_BASE_ADRR + 0x00010000) /*< Base Address of : APB2 Bus   >  */
#define AHB_BASE_ADRR				(PERIPHERAL_BASE_ADRR + 0x00020000) /*< Base Address of : AHB Bus    >  */

/*
 * APB1 Peripherals Base Addresses
 *
 */

#define TIM2_BASE_ADDR					(APB1_BASE_ADRR)			  /*< Base Address of : TIM2        > 	  */
#define TIM3_BASE_ADRR					(APB1_BASE_ADRR + 0x00000400) /*< Base Address of : TIM3        >	  */
#define TIM4_BASE_ADRR					(APB1_BASE_ADRR + 0x00000800) /*< Base Address of : TIM4        >	  */
#define TIM5_BASE_ADRR					(APB1_BASE_ADRR + 0x00000C00) /*< Base Address of : TIM5        >  	  */
#define TIM6_BASE_ADRR					(APB1_BASE_ADRR + 0x00001000) /*< Base Address of : TIM6        >  	  */
#define TIM7_BASE_ADRR					(APB1_BASE_ADRR + 0x00001400) /*< Base Address of : TIM7        >  	  */
#define LCD_BASE_ADRR					(APB1_BASE_ADRR + 0x00002400) /*< Base Address of : LCD         >     */
#define RTC_BASE_ADRR					(APB1_BASE_ADRR + 0x00002800) /*< Base Address of : RTC         >     */
#define WWDG_BASE_ADRR					(APB1_BASE_ADRR + 0x00002C00) /*< Base Address of : WWDG        >     */
#define IWDG_BASE_ADRR					(APB1_BASE_ADRR + 0x00003000) /*< Base Address of : IWDG        >  	  */
#define SPI2_BASE_ADRR					(APB1_BASE_ADRR + 0x00003800) /*< Base Address of : SPI2        >  	  */
#define SPI3_BASE_ADRR					(APB1_BASE_ADRR + 0x00003C00) /*< Base Address of : SPI3        >  	  */
#define USART2_BASE_ADRR				(APB1_BASE_ADRR + 0x00004400) /*< Base Address of : USART2      >	  */
#define USART3_BASE_ADRR				(APB1_BASE_ADRR + 0x00004800) /*< Base Address of : USART3      >     */
#define USART4_BASE_ADRR				(APB1_BASE_ADRR + 0x00004C00) /*< Base Address of : USART4      >     */
#define USART5_BASE_ADRR				(APB1_BASE_ADRR + 0x00005000) /*< Base Address of : USART5      >     */
#define I2C1_BASE_ADRR					(APB1_BASE_ADRR + 0x00005400) /*< Base Address of : I2C1        >     */
#define I2C2_BASE_ADRR					(APB1_BASE_ADRR + 0x00005800) /*< Base Address of : I2C2        >  	  */
#define USB_FS_BASE_ADRR				(APB1_BASE_ADRR + 0x00005C00) /*< Base Address of : USB_FS      >     */
#define USB_FS_SRAM_BASE_ADRR			(APB1_BASE_ADRR + 0x00006000) /*< Base Address of : USB_FS_SRAM >     */
#define PWR_BASE_ADRR					(APB1_BASE_ADRR + 0x00007000) /*< Base Address of : PWR         >     */
#define DAC_BASE_ADDRR					(APB1_BASE_ADRR + 0x00007400) /*< Base Address of : DAC         >	  */
#define OPAMP_BASE_ADRR					(APB1_BASE_ADRR + 0x00007C5C) /*< Base Address of : OPAMP       > 	  */
#define RI_BASE_ADRR					(APB1_BASE_ADRR + 0x00007C04) /*< Base Address of : RI          >	  */
#define COMP_BASE_ADRR					(APB1_BASE_ADRR + 0x00007C00) /*< Base Address of : COMP        >	  */

/*
 * APB2 Peripherals Base Addresses
 *
 */

#define SYSCFG_BASE_ADRR				(APB2_BASE_ADRR) 			  /*< Base Address of : SYSCFG >     */
#define EXTI_BASE_ADRR					(APB2_BASE_ADRR + 0x00000400) /*< Base Address of : EXTI   >	 */
#define TIM9_BASE_ADRR					(APB2_BASE_ADRR + 0x00000800) /*< Base Address of : TIM9   >	 */
#define TIM10_BASE_ADRR					(APB2_BASE_ADRR + 0x00000C00) /*< Base Address of : TIM10  >	 */
#define TIM11_BASE_ADRR					(APB2_BASE_ADRR + 0x00001000) /*< Base Address of : TIM11  >	 */
#define ADC_BASE_ADRR					(APB2_BASE_ADRR + 0x00002400) /*< Base Address of : ADC    >	 */
#define SDIO_BASE_ADRR					(APB2_BASE_ADRR + 0x00002C00) /*< Base Address of : SDIO   >	 */
#define SPI1_BASE_ADRR					(APB2_BASE_ADRR + 0x00003000) /*< Base Address of : SPI1   >	 */
#define USART1_BASE_ADRR				(APB2_BASE_ADRR + 0x00003800) /*< Base Address of : USART1 >     */

/*
 * AHB Peripherals Base Addresses
 *
 */
#define GPIOA_BASE_ADRR					(AHB_BASE_ADRR) 			 /*< Base Address of : GPIOA > */
#define GPIOB_BASE_ADRR					(AHB_BASE_ADRR + 0x00000400) /*< Base Address of : GPIOB >	*/
#define GPIOC_BASE_ADRR					(AHB_BASE_ADRR + 0x00000800) /*< Base Address of : GPIOC >	*/
#define GPIOD_BASE_ADRR					(AHB_BASE_ADRR + 0x00000C00) /*< Base Address of : GPIOD >	*/
#define GPIOE_BASE_ADRR					(AHB_BASE_ADRR + 0x00001000) /*< Base Address of : GPIOE >	*/
#define GPIOH_BASE_ADRR					(AHB_BASE_ADRR + 0x00001400) /*< Base Address of : GPIOH >	*/
#define GPIOF_BASE_ADRR					(AHB_BASE_ADRR + 0x00001800) /*< Base Address of : GPIOF >	*/
#define GPIOG_BASE_ADRR					(AHB_BASE_ADRR + 0x00001C00) /*< Base Address of : GPIOG > 	*/
#define CRC_BASE_ADRR					(AHB_BASE_ADRR + 0x00003000) /*< Base Address of : CRC   > 	*/
#define RCC_BASE_ADRR					(AHB_BASE_ADRR + 0x00003800) /*< Base Address of : RCC   > 	*/
#define FLASH_BASE__REG_ADRR			(AHB_BASE_ADRR + 0x00003C00) /*< Base Address of : FLASH >	*/
#define DMA1_BASE_ADRR					(AHB_BASE_ADRR + 0x00006000) /*< Base Address of : DMA1  > 	*/
#define DMA2_BASE_ADRR					(AHB_BASE_ADRR + 0x00006400) /*< Base Address of : DMA2  > 	*/
#define AES_BASE_ADRR					(AHB_BASE_ADRR + 0x10040000) /*< Base Address of : AES   > 	*/
#define FSMC_BASE_ADRR					(AHB_BASE_ADRR + 0x5FFE0000) /*< Base Address of : FSMC  > 	*/


/*
 * Peripheral Structure Definitions
 *
 */

typedef struct
{
	__IO uint32_t MODER;				/*!< GPIO port mode register Address Offset  					:0x00    > 	*/
	__IO uint32_t OTYPER;				/*!< GPIO port output type register Address Offset 			    :0x04    > 	*/
	__IO uint32_t OSPEEDR;				/*!< GPIO port speed register Address Offset  					:0x08    > 	*/
	__IO uint32_t PUPDR;				/*!< GPIO port pull-up/pull-down register Address Offset 		:0x0C    > 	*/
	__IO uint32_t IDR;					/*!< GPIO port input register Address Offset  					:0x10    > 	*/
	__IO uint32_t ODR;					/*!< GPIO port output data register Address Offset 				:0x14    > 	*/
	__IO uint32_t BSRR;					/*!< GPIO port bit set/reset register Address Offset 			:0x18    > 	*/
	__IO uint32_t LCKR;					/*!< GPIO port mode configuration lock Address Offset  		    :0x1C    > 	*/
	__IO uint32_t AFR[2];					/*!< GPIO port alternate function register Address Offset   :0x20    > 	*/
	__IO uint32_t BRR;					/*!< GPIO port bit reset register Address Offset  				:0x28    > 	*/

}GPIO_TypeDef_t;



typedef struct
{
	__IO uint32_t RC;					/*!< RCC clock control register Address Offset                          : 0x00 >   */
	__IO uint32_t ICSCR;				/*!< RCC clock sources calibration register Address Offset              : 0x04 >   */
	__IO uint32_t CFGR;					/*!< RCC clock configuration register Address Offset                    : 0x08 >   */
	__IO uint32_t CIR;					/*!< RCC clock interrupt register Address Offset                        : 0x0C >   */
	__IO uint32_t AHBRSTS;					/*!< RCC AHB peripheral reset register Address Offset                   : 0x10 >   */
	__IO uint32_t APB2RSTR;				/*!< RCC APB2 peripheral reset register Address Offset                  : 0x14 >   */
	__IO uint32_t APB1RSTR;				/*!< RCC APB1 peripheral reset register Address Offset                  : 0x18 >   */
	__IO uint32_t AHBENR;				/*!< RCC AHB peripheral clock enable register Address Offset            : 0x1C >   */
	__IO uint32_t APB2ENR;				/*!< RCC APB2 peripheral clock enable register Address Offset           : 0x20 >   */
	__IO uint32_t APB1ENR;				/*!< RCC APB1 peripheral clock enable register Address Offset           : 0x24 >   */
	__IO uint32_t AHBLP;				/*!< RCC AHB peripheral low-power clock enable register Address Offset  : 0x28 >   */
	__IO uint32_t APB2L;				/*!< RCC APB2 peripheral low-power clock enable register Address Offset : 0x2C >   */
	__IO uint32_t APB1L;				/*!< RCC APB1 peripheral low-power clock enable register Address Offset : 0x30 >   */
	__IO uint32_t CSR;					/*!< RCC control/status register Address Offset 						: 0x34 >   */

}RCC_TypeDef_t;

typedef struct
{
	__IO uint32_t MEMRMP;				/*!< SYSCFG memory remap register Address Offset					  : 0x00 >	*/
	__IO uint32_t PMC;					/*!< SYSCFG peripheral mode configuration register Address Offset	  : 0x04 >	*/
	__IO uint32_t EXTI_CR[4];			/*!< SYSCFG external interrupt configuration register 1 Address Offset: 0x08 >	*/

}SYSCFG_TypeDef_t;

typedef struct
{
	__IO uint32_t IMR;					/*!< EXTI interrupt mask register Address Offset				: 0x00 >	*/
	__IO uint32_t EMR;					/*!< EXTI event mask register Address Offset					: 0x04 >	*/
	__IO uint32_t RTSR;					/*!< EXTI rising edge trigger selection register Address Offset : 0x08 >	*/
	__IO uint32_t FTSR;					/*!< EXTI falling edge trigger selection register Address Offset: 0x0C >	*/
	__IO uint32_t SWIER;				/*!< EXTI software interrupt event register Address Offset		: 0x10 >	*/
	__IO uint32_t PR;					/*!< EXTI pending register Address Offset						: 0x14 >	*/

}EXTI_TypeDef_t;

typedef struct
{
	__IO uint32_t CR1;					/*!< SPI control register 1 Address Offset 		   :0x00 >	*/
	__IO uint32_t CR2;					/*!< SPI control register 2 Address Offset 		   :0x04 >	*/
	__IO uint32_t SR;					/*!< SPI status register Address Offset 		   :0x08 >	*/
	__IO uint32_t DR;					/*!< SPI data register Address Offset 			   :0x0C >	*/
	__IO uint32_t CRCPR;				/*!< SPI CRC polynomial register Address Offset    :0x10 >	*/
	__IO uint32_t RXCRCR;				/*!< SPI RX CRC register Address Offset 		   :0x14 >	*/
	__IO uint32_t TXCRCR;				/*!< SPI TX CRC register Address Offset 		   :0x18 >	*/
	__IO uint32_t I2SCFGR;				/*!< SPI I2C configuration register Address Offset :0x1C >	*/
	__IO uint32_t I2SPR;				/*!< SPI I2C prescaler register Address Offset 	   :0x20 >	*/



}SPI_TypeDef_t;

typedef struct
{
	__IO uint32_t SR;					/*!< USART status register Address Offset					:0x00 >	*/
	__IO uint32_t DR;					/*!< USART data register Address Offset						:0x04 >	*/
	__IO uint32_t BRR;					/*!< USART BaudRate register Address Offset					:0x08 >	*/
	__IO uint32_t CR1;					/*!< USART control register 1 Address Offset				:0x0C >	*/
	__IO uint32_t CR2;					/*!< USART control register 2 Address Offset				:0x10 >	*/
	__IO uint32_t CR3;					/*!< USART data register Address Offset						:0x14 >	*/
	__IO uint32_t GTPR;					/*!< USART guard time and prescaler register Address Offset	:0x18 >	*/

}USART_Typedef_t;

typedef struct
{
	__IO uint32_t CR1;
	__IO uint32_t CR2;
	__IO uint32_t OAR1;
	__IO uint32_t OAR2;
	__IO uint32_t DR;
	__IO uint32_t SR1;
	__IO uint32_t SR2;
	__IO uint32_t CCR;
	__IO uint32_t TRISE;

}I2C_Typedef_t;

/*
 * Bases address definitions of ports
 *
 */

#define GPIOA							((GPIO_TypeDef_t *)(GPIOA_BASE_ADRR)	)
#define GPIOB							((GPIO_TypeDef_t *)(GPIOB_BASE_ADRR)	)
#define GPIOC							((GPIO_TypeDef_t *)(GPIOC_BASE_ADRR)	)
#define GPIOD							((GPIO_TypeDef_t *)(GPIOD_BASE_ADRR)	)
#define GPIOE							((GPIO_TypeDef_t *)(GPIOE_BASE_ADRR)	)
#define GPIOF							((GPIO_TypeDef_t *)(GPIOF_BASE_ADRR)	)
#define GPIOG							((GPIO_TypeDef_t *)(GPIOG_BASE_ADRR)	)
#define GPIOH							((GPIO_TypeDef_t *)(GPIOH_BASE_ADRR)	)

#define RCC								((RCC_TypeDef_t *)(RCC_BASE_ADRR)  		)

#define SYSCFG							((SYSCFG_TypeDef_t *)(SYSCFG_BASE_ADRR)	)

#define EXTI							((EXTI_TypeDef_t *)(EXTI_BASE_ADRR)		)

#define SPI1							((SPI_TypeDef_t *) (SPI1_BASE_ADRR)		)
#define SPI2							((SPI_TypeDef_t *) (SPI2_BASE_ADRR)		)

#define USART1							((USART_Typedef_t *)(USART1_BASE_ADRR)		)
#define USART2							((USART_Typedef_t *)(USART2_BASE_ADRR)		)
#define USART3							((USART_Typedef_t *)(USART3_BASE_ADRR)		)
#define USART4							((USART_Typedef_t *)(USART4_BASE_ADRR)		)


#define I2C1							((I2C_Typedef_t   *)(I2C1_BASE_ADRR)		)
#define I2C2							((I2C_Typedef_t   *)(I2C2_BASE_ADRR)		)

/*
 * Bit definitions
 *
 */

#define RCC_AHBENR_GPIOAEN_Pos			(0U)								//RCC AHBENR register GPIOAEN Bit Position
#define RCC_AHBENR_GPIOAEN_Msk			(0x1 << RCC_AHBENR_GPIOAEN_Pos)		//RCC AHBENR register GPIOAEN Bit Mask
#define RCC_AHBENR_GPIOAEN				(RCC_AHBENR_GPIOAEN_Msk)			//RCC AHBENR register GPIOAEN Bit Macro

#define RCC_AHBENR_GPIOBEN_Pos			(1U)								//RCC AHBENR register GPIOBEN Bit Position
#define RCC_AHBENR_GPIOBEN_Msk			(0x1 << RCC_AHBENR_GPIOAEN_Pos)		//RCC AHBENR register GPIOBEN Bit Mask
#define RCC_AHBENR_GPIOBEN				(RCC_AHBENR_GPIOBEN_Msk)			//RCC AHBENR register GPIOBEN Bit Macro

#define RCC_AHBENR_GPIOCEN_Pos			(2U)								//RCC AHBENR register GPIOCEN Bit Position
#define RCC_AHBENR_GPIOCEN_Msk			(0x1 << RCC_AHBENR_GPIOCEN_Pos)		//RCC AHBENR register GPIOCEN Bit Mask
#define RCC_AHBENR_GPIOCEN				(RCC_AHBENR_GPIOCEN_Msk)			//RCC AHBENR register GPIOCEN Bit Macro

#define RCC_AHBENR_GPIODEN_Pos			(3U)								//RCC AHBENR register GPIODEN Bit Position
#define RCC_AHBENR_GPIODEN_Msk			(0x1 << RCC_AHBENR_GPIODEN_Pos)		//RCC AHBENR register GPIODEN Bit Mask
#define RCC_AHBENR_GPIODEN				(RCC_AHBENR_GPIODEN_Msk)			//RCC AHBENR register GPIODEN Bit Macro

#define RCC_AHBENR_GPIOEEN_Pos			(4U)								//RCC AHBENR register GPIOEEN Bit Position
#define RCC_AHBENR_GPIOEEN_Msk			(0x1 << RCC_AHBENR_GPIOEEN_Pos)		//RCC AHBENR register GPIOEEN Bit Mask
#define RCC_AHBENR_GPIOEEN				(RCC_AHBENR_GPIOEEN_Msk)			//RCC AHBENR register GPIOEEN Bit Macro

#define RCC_AHBENR_GPIOFEN_Pos			(5U)								//RCC AHBENR register GPIOFEN Bit Position
#define RCC_AHBENR_GPIOFEN_Msk			(0x1 << RCC_AHBENR_GPIOFEN_Pos)		//RCC AHBENR register GPIOEEN Bit Mask
#define RCC_AHBENR_GPIOFEN				(RCC_AHBENR_GPIOFEN_Msk)			//RCC AHBENR register GPIOFEN Bit Macro

#define RCC_AHBENR_GPIOGEN_Pos			(6U)								//RCC AHBENR register GPIOGEN Bit Position
#define RCC_AHBENR_GPIOGEN_Msk			(0x1 << RCC_AHBENR_GPIOGEN_Pos)		//RCC AHBENR register GPIOGEN Bit Mask
#define RCC_AHBENR_GPIOGEN				(RCC_AHBENR_GPIOGEN_Msk)			//RCC AHBENR register GPIOGEN Bit Macro

#define RCC_AHBENR_GPIOHEN_Pos			(7U)								//RCC AHBENR register GPIOHEN Bit Position
#define RCC_AHBENR_GPIOHEN_Msk			(0x1 << RCC_AHBENR_GPIOHEN_Pos)		//RCC AHBENR register GPIOHEN Bit Mask
#define RCC_AHBENR_GPIOHEN				(RCC_AHBENR_GPIOHEN_Msk)			//RCC AHBENR register GPIOHEN Bit Macro

#define RCC_APB2ENR_SYSCFGEN_POS		(0U)								//RCC APB2ENR register SYSCFGEN Bit Position
#define RCC_APB2ENR_SYSCFGEN_MSK		(0x1 << RCC_APB2ENR_SYSCFGEN_POS)	//RCC APB2ENR register SYSCFGEN Bit Mask
#define RCC_APB2ENR_SYSCFGEN			(RCC_APB2ENR_SYSCFGEN_MSK)			//RCC APB2ENR register SYSCFGEN Bit Macro

#define RCC_APB2ENR_SPI1_POS			(12U)								// RCC APB2ENR register SPI1EN Bit Position
#define RCC_APB2ENR_SPI1_MSK			(0x1 << RCC_APB2ENR_SPI1_POS)		// RCC APB2ENR register SPI1EN Bit Mask
#define RCC_APB2ENR_SPI1				(RCC_APB2ENR_SPI1_MSK)				// RCC APB2ENR register SPI1EN Bit

#define RCC_APB1ENR_SPI2_POS			(14U)								// RCC APB1ENR register SPI2EN Bit Position
#define RCC_APB1ENR_SPI2_MSK			(0x1 << RCC_APB1ENR_SPI2_POS)		// RCC APB1ENR register SPI2EN Bit Mask
#define RCC_APB1ENR_SPI2				(RCC_APB1ENR_SPI2_MSK)				// RCC APB1ENR register SPI2EN Bit

#define RCC_APB1ENR_SPI3_POS			(15U)								// RCC APB1ENR register SPI3EN Bit Position
#define RCC_APB1ENR_SPI3_MSK			(0x1 << RCC_APB1ENR_SPI3_POS)		// RCC APB1ENR register SPI3EN Bit Mask
#define RCC_APB1ENR_SPI3				(RCC_APB1ENR_SPI23_MSK)				// RCC APB1ENR register SPI3EN Bit

#define RCC_APB2ENR_USART1_POS			(14U)
#define RCC_APB2ENR_USART1_MSK			(0x1 << RCC_APB2ENR_USART1_POS)
#define RCC_APB2ENR_USART1				(RCC_APB2ENR_USART1_MSK)

#define RCC_APB1ENR_USART2_POS			(17U)								// RCC APB1ENR register USART2 Bit Position
#define	RCC_APB1ENR_USART2_MSK			(0x1 << RCC_APB1ENR_USART2_POS)		// RCC APB1ENR register USART2 Bit Mask
#define RCC_APB1ENR_USART2				(RCC_APB1ENR_USART2_MSK)				// RCC APB1ENR register USART2 Bit

#define RCC_APB1ENR_I2C1_POS			(21U)
#define	RCC_APB1ENR_I2C1_MSK			(0x1 << RCC_APB1ENR_I2C1_POS)
#define RCC_APB1ENR_I2C1				(RCC_APB1ENR_I2C1_MSK)

#define RCC_APB1ENR_I2C2_POS			(22U)
#define	RCC_APB1ENR_I2C2_MSK			(0x1 << RCC_APB1ENR_I2C2_POS)
#define RCC_APB1ENR_I2C2				(RCC_APB1ENR_I2C2_MSK)

#define SPI_CR1_SPE_POS					(6U)								// SPI CR1 register SPE Bit Position
#define SPI_CR1_SPE_MSK					(0x1 << SPI_CR1_SPE_POS)			// SPI CR1 register SPE Bit Mask
#define SPI_CR1_SPE						(SPI_CR1_SPE_MSK)					// SPI CR1 register SPE Bit

#define SPI_CR1_DFF_POS					(11U)								// SPI CR1 register DFF Bit Position
#define SPI_CR1_DFF_MSK					(0x1 << SPI_CR1_DFF_POS)			// SPI CR1 register DFF Bit Mask
#define SPI_CR1_DFF						(SPI_CR1_DFF_MSK)					// SPI CR1 register DFF Bit

#define SPI_SR_TXE_POS					(1U)								// SPI SR register TXE Bit Position
#define SPI_SR_TXE_MSK					(0x1 << SPI_SR_TXE_POS)				// SPI SR register TXE Bit Mask
#define SPI_SR_TXE						(SPI_SR_TXE_MSK)						// SPI SR register TXE Bit

#define SPI_SR_BSY_POS					(7U)								// SPI SR register BSY Bit Position
#define SPI_SR_BSY_MSK					(0x1 << SPI_SR_BSY_POS)				// SPI SR register BSY Bit Mask
#define SPI_SR_BSY						(SPI_SR_BSY_MSK)					// SPI SR register BSY Bit

#define SPI_CR2_TXEIE_POS				(7U)								// SPI CR2 register TXEIE Bit Position
#define SPI_CR2_TXEIE_MSK				(0x1 << SPI_CR2_TXEIE_POS)			// SPI CR2 register TXEIE Bit Mask
#define SPI_CR2_TXEIE					SPI_CR2_TXEIE_MSK					// SPI CR2 register TXEIE Bit

#define USART_CR1_TXEIE_POS				(7U)
#define USART_CR1_TXEIE_MSK				(0x1 << USART_CR1_TXEIE_POS)
#define USART_CR1_TXEIE					(USART_CR1_TXEIE_MSK)

#define USART_CR1_RXNEIE_POS			(5U)
#define USART_CR1_RXNEIE_MSK			(0x1 << USART_CR1_RXNEIE_POS)
#define USART_CR1_RXNEIE				(USART_CR1_RXNEIE_MSK)

#define USART_CR2_STOP_0_POS			(12U)
#define USART_CR2_STOP_0_MSK			(0x1 << USART_CR2_STOP_0_POS)
#define USART_CR2_STOP_0				(USART_CR2_STOP_0_MSK)

#define USART_CR2_STOP_1_POS			(13U)
#define USART_CR2_STOP_1_MSK			(0x1 << USART_CR2_STOP_1_POS)
#define USART_CR2_STOP_1				(USART_CR2_STOP_1_MSK)

#define USART_SR_TXE_POS				(7U)
#define USART_SR_TXE_MSK				(0x1U << USART_SR_TXE_POS)
#define USART_SR_TXE					(USART_SR_TXE_MSK)

#define USART_SR_TC_POS					(6U)
#define USART_SR_TC_MSK					(0x1 << USART_SR_TC_POS)
#define USART_SR_TC						(USART_SR_TC_MSK)

#define USART_SR_RXNE_POS				(5U)
#define USART_SR_RXNE_MSK				(0x1 << USART_SR_RXNE_POS)
#define USART_SR_RXNE					(USART_SR_RXNE_MSK)

#define I2C_CR1_PE_POS					(0U)
#define I2C_CR1_PE_MSK					(0x1 << I2C_CR1_PE_POS)
#define I2C_CR1_PE						(I2C_CR1_PE_MSK)




#include "rcc.h"
#include "gpio.h"
#include "exti.h"
#include "spi.h"
#include "usart.h"
#include "i2c.h"
#endif /* INC_STM32L1_DEVICE_H_ */
