-/*
 * stm32h723.h
 *
 *  Created on: Aug 20, 2023
 *      Author: meteh
 */

#ifndef INC_STM32H723_H_
#define INC_STM32H723_H_


/*
 *
 * Memory Base Address
 *
 */
#define FLASH_BASE_ADDR					(0x08000000UL)/*Flash Base Address*/

#define D1_ITCMRAM_ADRR           		(0x00000000UL) /*!< Base address of : 64KB RAM reserved for CPU execution/instruction accessible over ITCM  */
#define D1_ITCMAXI_ADRR           		(0x00100000UL) /*!< Base address of : (up to 128KB) embedded Test FLASH memory accessible over ITCM         */
#define D1_DTCMRAM_ADRR           		(0x20000000UL) /*!< Base address of : 128KB system data RAM accessible over DTCM 								*/
#define D1_AXISRAM1_BASE           		(0x24000000UL) /*!< Base address of : (up to 128KB) system data RAM1 accessible over over AXI                */
#define D1_AXISRAM2_BASE           		(0x24020000UL) /*!< Base address of : (up to 192KB) system data RAM2 accessible over over AXI to be shared with ITCM (64K granularity)  */
#define D2_AHBSRAM1_BASE          		(0x30000000UL)   /*!< Base address of : (up to 16KB) system data RAM accessible over over AXI->AHB Bridge    */
#define D2_AHBSRAM2_BASE          		(0x30004000UL)   /*!< Base address of : (up to 16KB) system data RAM accessible over over AXI->AHB Bridge    */
#define D3_BKPSRAM_BASE           		(0x38800000UL) /*!< Base address of : Backup SRAM(4 KB) over AXI->AHB Bridge                                */
#define D3_SRAM_BASE              		(0x38000000UL) /*!< Base address of : Backup SRAM(16 KB) over AXI->AHB Bridge


/*
 *
 * Peripheral Base Addresses
 */
#define Peripheral_BASE_ADRR			(0x40000000UL) 						 /*!< Base address of : Peripherals		*/
#define APB1_BASE_ADRR					(Peripheral_BASE_ADRR) 				 /*!< Base address of : APB1 BUS		*/
#define APB2_BASE_ADRR					(Peripheral_BASE_ADRR + 0x0010000UL) /*!< Base address of : APB2 BUS		*/
#define APB3_BASE_ADRR					(Peripheral_BASE_ADRR + 0x1000000UL) /*!< Base address of : APB3 BUS		*/
#define APB4_BASE_ADRR					(Peripheral_BASE_ADRR + 0x18000000UL)/*!< Base address of : APB3 BUS		*/

#define AHB1_BASE_ADRR					(Peripheral_BASE_ADRR + 0x00020000UL) /*!< Base address of : AHB1 BUS		*/
#define AHB2_BASE_ADRR					(Peripheral_BASE_ADRR + 0x08020000UL) /*!< Base address of : AHB2 BUS		*/
#define AHB3_BASE_ADRR					(Peripheral_BASE_ADRR + 0x11000000UL) /*!< Base address of : AHB3 BUS		*/

/*
 *
 * APB1 Peripheral Addresses
 */

#define TIM2_BASE_ADRR					(APB1_BASE_ADRR) 					/*!< Base address of : TIM2				*/
#define TIM3_BASE_ADRR					(APB1_BASE_ADRR + 0x00000400UL)		/*!< Base address of : TIM3				*/
#define TIM4_BASE_ADRR					(APB1_BASE_ADRR + 0x00000800UL)		/*!< Base address of : TIM4				*/
#define TIM5_BASE_ADRR					(APB1_BASE_ADRR + 0x00000C00UL)		/*!< Base address of : TIM5				*/
#define TIM6_BASE_ADRR					(APB1_BASE_ADRR + 0x00001000UL)		/*!< Base address of : TIM6				*/
#define TIM7_BASE_ADRR					(APB1_BASE_ADRR + 0x00001400UL)		/*!< Base address of : TIM7				*/
#define TIM12_BASE_ADRR					(APB1_BASE_ADRR + 0x00001800UL)		/*!< Base address of : TIM12			*/
#define TIM13_BASE_ADRR					(APB1_BASE_ADRR + 0x00001C00UL)		/*!< Base address of : TIM13			*/
#define TIM14_BASE_ADRR					(APB1_BASE_ADRR + 0x00002000UL)		/*!< Base address of : TIM14			*/
#define LPTIM1_BASE_ADRR				(APB1_BASE_ADRR + 0x00002400UL)		/*!< Base address of : LPTIM1			*/
#define SPI2/I2S2_BASE_ADRR				(APB1_BASE_ADRR + 0x00003800UL)		/*!< Base address of : SPI2/I2S2		*/
#define SPI3/I2S3_BASE_ADRR				(APB1_BASE_ADRR + 0x00003C00UL)		/*!< Base address of : SPI3/I2S3		*/
#define SPDIFRX1_BASE_ADRR				(APB1_BASE_ADRR + 0x00004000UL)		/*!< Base address of : SPDIFRX1			*/
#define USART2_BASE_ADRR				(APB1_BASE_ADRR + 0x00004400UL)		/*!< Base address of : USART2			*/
#define USART3_BASE_ADRR				(APB1_BASE_ADRR + 0x00004800UL)		/*!< Base address of : USART3			*/
#define UART4_BASE_ADRR					(APB1_BASE_ADRR + 0x00004C00UL)		/*!< Base address of : UART4			*/
#define UART5_BASE_ADRR					(APB1_BASE_ADRR + 0x00005000UL)		/*!< Base address of : UART5			*/
#define I2C1_BASE_ADRR					(APB1_BASE_ADRR + 0x00005400UL)		/*!< Base address of : I2C1				*/
#define I2C2_BASE_ADRR					(APB1_BASE_ADRR + 0x00005800UL)		/*!< Base address of : I2C2				*/
#define I2C3_BASE_ADRR					(APB1_BASE_ADRR + 0x00005C00UL)		/*!< Base address of : I2C3				*/
#define I2C5_BASE_ADRR					(APB1_BASE_ADRR + 0x00006400UL)		/*!< Base address of : I2C5				*/
#define HDMI-ESC_BASE_ADRR				(APB1_BASE_ADRR + 0x00006C00UL)		/*!< Base address of : HDMI-ESC			*/
#define DAC1/2_BASE_ADRR				(APB1_BASE_ADRR + 0x00007400UL)		/*!< Base address of : DAC1/2			*/
#define UART7_BASE_ADRR					(APB1_BASE_ADRR + 0x00007800UL)		/*!< Base address of : UART7			*/
#define UART8_BASE_ADRR					(APB1_BASE_ADRR + 0x00007C00UL)		/*!< Base address of : UART8			*/
#define CRS_BASE_ADRR					(APB1_BASE_ADRR + 0x00008400UL)		/*!< Base address of : CRS				*/
#define SWPMI_BASE_ADRR					(APB1_BASE_ADRR + 0x00008800UL)		/*!< Base address of : SWPMI			*/
#define OPAMP_BASE_ADRR					(APB1_BASE_ADRR + 0x00009000UL)		/*!< Base address of : OPAMP			*/
#define MDIOS_BASE_ADRR					(APB1_BASE_ADRR + 0x00009400UL)		/*!< Base address of : MDIOS			*/
#define FDCAN1_BASE_ADRR				(APB1_BASE_ADRR + 0x0000A000UL)		/*!< Base address of : FDCAN1			*/
#define FDCAN2_BASE_ADRR				(APB1_BASE_ADRR + 0x0000A400UL)		/*!< Base address of : FDCAN2			*/
#define CAN_CCU_BASE_ADRR				(APB1_BASE_ADRR + 0x0000A800UL)		/*!< Base address of : CANCCU			*/
#define CAN_MES_RAM_BASE_ADRR			(APB1_BASE_ADRR + 0x0000AC00UL)		/*!< Base address of : CAN_MES_RAM		*/
#define FDCAN3_BASE_ADRR				(APB1_BASE_ADRR + 0x0000D400UL)		/*!< Base address of : FDCAN4			*/
#define TIM23_BASE_ADRR					(APB1_BASE_ADRR + 0x0000E000UL)		/*!< Base address of : TIM23			*/
#define TIM24_BASE_ADRR					(APB1_BASE_ADRR + 0x0000E400UL)		/*!< Base address of : TIM24			*/

/*
 *
 * APB2 Peripheral Addresses
 */





#endif /* INC_STM32H723_H_ */