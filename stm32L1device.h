/*
 * stm32L1_device.h
 *
 *  Created on: Aug 21, 2023
 *      Author: metehan.cakmak
 */

#ifndef INC_STM32L1_DEVICE_H_
#define INC_STM32L1_DEVICE_H_

#include <stdint.h>

#define SET_BIT(REG, BIT)			( (REG) |= (BIT) )
#define CLEAR_BIT(REG, BIT)			( (REG) &= ~(BIT) )
#define READ_BIT(REG, BIT)			( (REG) & (BIT) )
#define UNUSED(x)					(void)
#define __IO volatile

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
#define FLASH_BASE_ADRR					(AHB_BASE_ADRR + 0x00003C00) /*< Base Address of : FLASH >	*/
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
	__IO uint32_t AFRL;					/*!< GPIO port alternate function low register Address Offset   :0x20    > 	*/
	__IO uint32_t AFRH;					/*!< GPIO port alternate function high register Address Offset  :0x24    >  */
	__IO uint32_t BRR;					/*!< GPIO port bit reset register Address Offset  				:0x28    > 	*/

}GPIO_TypeDef_t;



typedef struct
{
	__IO uint32_t RC;					/*< RCC clock control register Address Offset                          : 0x00 >   */
	__IO uint32_t ICSCR;				/*< RCC clock sources calibration register Address Offset              : 0x04 >   */
	__IO uint32_t CFGR;					/*< RCC clock configuration register Address Offset                    : 0x08 >   */
	__IO uint32_t CIR;					/*< RCC clock interrupt register Address Offset                        : 0x0C >   */
	__IO uint32_t AHBR;					/*< RCC AHB peripheral reset register Address Offset                   : 0x10 >   */
	__IO uint32_t APB2R;				/*< RCC APB2 peripheral reset register Address Offset                  : 0x14 >   */
	__IO uint32_t APB1R;				/*< RCC APB1 peripheral reset register Address Offset                  : 0x18 >   */
	__IO uint32_t AHBE;					/*< RCC AHB peripheral clock enable register Address Offset            : 0x1C >   */
	__IO uint32_t APB2E;				/*< RCC APB2 peripheral clock enable register Address Offset           : 0x20 >   */
	__IO uint32_t APB1E;				/*< RCC APB1 peripheral clock enable register Address Offset           : 0x24 >   */
	__IO uint32_t AHBLP;				/*< RCC AHB peripheral low-power clock enable register Address Offset  : 0x28 >   */
	__IO uint32_t APB2L;				/*< RCC APB2 peripheral low-power clock enable register Address Offset : 0x2C >	  */
	__IO uint32_t APB1L;				/*< RCC APB1 peripheral low-power clock enable register Address Offset : 0x30 >   */
	__IO uint32_t CSR;					/*< RCC control/status register Address Offset 						   : 0x34 >   */

}RCC_Typedef_t;

#define GPIOA							((GPIO_TypeDef_t *)(GPIOA_BASE_ADRR))
#define GPIOB							((GPIO_TypeDef_t *)(GPIOB_BASE_ADRR))
#define GPIOC							((GPIO_TypeDef_t *)(GPIOC_BASE_ADRR))
#define GPIOD							((GPIO_TypeDef_t *)(GPIOD_BASE_ADRR))
#define GPIOE							((GPIO_TypeDef_t *)(GPIOE_BASE_ADRR))
#define GPIOF							((GPIO_TypeDef_t *)(GPIOF_BASE_ADRR))
#define GPIOG							((GPIO_TypeDef_t *)(GPIOG_BASE_ADRR))
#define GPIOH							((GPIO_TypeDef_t *)(GPIOH_BASE_ADRR))

#define RCC								((RCC_Typedef_t * )(CRC_BASE_ADRR)  )

/*
 * Bit definitions
 *
 */

#define RCC_AHBE_GPIOAEN_Pos			(0U)
#define RCC_AHBE_GPIOAEN_Msk			(0x1 << RCC_AHBE_GPIOAEN_Pos)
#define RCC_AHBE_GPIOAEN				(RCC_AHBE_GPIOAEN_Msk)

#define RCC_AHBE_GPIOBEN_Pos			(1U)
#define RCC_AHBE_GPIOBEN_Msk			(0x1 << RCC_AHBE_GPIOAEN_Pos)
#define RCC_AHBE_GPIOBEN				(RCC_AHBE_GPIOBEN_Msk)

#define RCC_AHBE_GPIOCEN_Pos			(2U)
#define RCC_AHBE_GPIOCEN_Msk			(0x1 << RCC_AHBE_GPIOCEN_Pos)
#define RCC_AHBE_GPIOCEN				(RCC_AHBE_GPIOCEN_Msk)

#define RCC_AHBE_GPIODEN_Pos			(3U)
#define RCC_AHBE_GPIODEN_Msk			(0x1 << RCC_AHBE_GPIODEN_Pos)
#define RCC_AHBE_GPIODEN				(RCC_AHBE_GPIOCDEN_Msk)

#define RCC_AHBE_GPIOEEN_Pos			(4U)
#define RCC_AHBE_GPIOEEN_Msk			(0x1 << RCC_AHBE_GPIOEEN_Pos)
#define RCC_AHBE_GPIOEEN				(RCC_AHBE_GPIOEEN_Msk)

#define RCC_AHBE_GPIOFEN_Pos			(5U)
#define RCC_AHBE_GPIOFEN_Msk			(0x1 << RCC_AHBE_GPIOFEN_Pos)
#define RCC_AHBE_GPIOFEN				(RCC_AHBE_GPIOFEN_Msk)

#define RCC_AHBE_GPIOGEN_Pos			(6U)
#define RCC_AHBE_GPIOGEN_Msk			(0x1 << RCC_AHBE_GPIOGEN_Pos)
#define RCC_AHBE_GPIOGEN				(RCC_AHBE_GPIOGEN_Msk)

#define RCC_AHBE_GPIOHEN_Pos			(7U)
#define RCC_AHBE_GPIOHEN_Msk			(0x1 << RCC_AHBE_GPIOHEN_Pos)
#define RCC_AHBE_GPIOHEN				(RCC_AHBE_GPIOHEN_Msk)


#endif /* INC_STM32L1_DEVICE_H_ */
