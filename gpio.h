/*
 * GPIO.h
 *
 *  Created on: Aug 22, 2023
 *      Author: metehan.cakmak
 */

#ifndef INC_GPIO_H_
#define INC_GPIO_H_
#include "stm32L1device.h"
#include <stdint.h>

/*
 * @def_group GPIO_Pins
 *
 */

#define GPIO_PIN_0			((uint16_t)(0x0001))			/*! < GPIO PIN 0 Selected   > */
#define GPIO_PIN_1			((uint16_t)(0x0002))			/*! < GPIO PIN 1 Selected   > */
#define GPIO_PIN_2			((uint16_t)(0x0004))			/*! < GPIO PIN 2 Selected   > */
#define GPIO_PIN_3			((uint16_t)(0x0008))			/*! < GPIO PIN 3 Selected   > */
#define GPIO_PIN_4			((uint16_t)(0x0010))			/*! < GPIO PIN 4 Selected   > */
#define GPIO_PIN_5			((uint16_t)(0x0020))			/*! < GPIO PIN 5 Selected   > */
#define GPIO_PIN_6			((uint16_t)(0x0040))			/*! < GPIO PIN 6 Selected   > */
#define GPIO_PIN_7			((uint16_t)(0x0080))			/*! < GPIO PIN 7 Selected   > */
#define GPIO_PIN_8			((uint16_t)(0x0100))			/*! < GPIO PIN 8 Selected   > */
#define GPIO_PIN_9			((uint16_t)(0x0200))			/*! < GPIO PIN 9 Selected   > */
#define GPIO_PIN_10			((uint16_t)(0x0400))			/*! < GPIO PIN 10 Selected  > */
#define GPIO_PIN_11			((uint16_t)(0x0800))			/*! < GPIO PIN 11 Selected  > */
#define GPIO_PIN_12			((uint16_t)(0x1000))			/*! < GPIO PIN 12 Selected  > */
#define GPIO_PIN_13			((uint16_t)(0x2000))			/*! < GPIO PIN 13 Selected  > */
#define GPIO_PIN_14			((uint16_t)(0x4000))			/*! < GPIO PIN 14 Selected  > */
#define GPIO_PIN_15			((uint16_t)(0x8000))			/*! < GPIO PIN 15 Selected  > */
#define GPIO_PIN_ALL		((uint16_t)(0xFFFF))			/*! < GPIO PIN ALL Selected > */

/*
 * @def_group GPIO_Pin_Modes
 *
 */
#define GPIO_MODE_INPUT					(0x0U)							/*! <GPIO PIN MODE "INPUT" 				>*/
#define GPIO_MODE_OUT					(0x1U)							/*! <GPIO PIN MODE "OUTPUT" 			>*/
#define GPIO_MODE_ALTERNATE 			(0x2U)							/*! <GPIO PIN MODE "ALTERNATE FUNCTION" >*/
#define GPIO_MODE_ANALOG				(0x3U)							/*! <GPIO PIN MODE "ANALOG" 			>*/

/*
 * @def_group GPIO_Otype_Modes
 *
 */
#define GPIO_OTYPE_PUSH_PULL			(0x0U)							/*! <GPIO Output Type  "Push Pull" 		>*/
#define GPIO_OTYPE_OPEN_DRAIN			(0x1U)							/*! <GPIO Output Type  "Open Drain" 	>*/

/*
 * @def_group GPIO_PuPd_Modes
 *
 */
#define GPIO_PuPd_NOPULL				(0x0U)							/*! <GPIO PIN MODE "NO PULL" 			>*/
#define GPIO_PuPd_PULLUP				(0x1U)							/*! <GPIO PIN MODE "PULL UP" 			>*/
#define GPIO_PuPd_PULLDOWN 				(0x2U)							/*! <GPIO PIN MODE "PULL DOWN" 			>*/

/*
 * @def_group GPIO_Speed_Modes
 *
 */
#define GPIO_SPEED_LOW					(0x0U)							/*! < GPIO Speed MODE "LOW"				>*/
#define GPIO_SPEED_MEDIUM				(0x1U)							/*! < GPIO Speed MODE "MEDIUM"			>*/
#define GPIO_SPEED_HIGH					(0x2U)							/*! < GPIO Speed MODE "HIGH"			>*/
#define GPIO_SPEED_VERY					(0x3U)							/*! < GPIO Speed MODE "VERY HIGH"		>*/




typedef enum
{
	GPIO_Pin_Reset	=	0x0U,
	GPIO_Pin_Set	=	!GPIO_Pin_Reset

}GPIO_PinState_t;


typedef struct
{
	uint32_t pinNumber;		/*!< @def_group GPIO_Pins 		 > */
	uint32_t Mode;			/*!< @def_group GPIO_Pin_Modes   > */
	uint32_t PuPd;			/*!< @def_group GPIO_PuPd_Modes  > */
	uint32_t Speed;			/*!< @def_group GPIO_Speed_Modes > */
	uint32_t Alternate;
	uint32_t Otype;			/*!< @def_group GPIO_Otype_Modes > */
}GPIO_InitTypeDef_t;


/*
 * GPIO Functions
 *
 */

void GPIO_Init(GPIO_TypeDef_t *GPIOx, GPIO_InitTypeDef_t *GPIO_Config);
void GPIO_WritePin(GPIO_TypeDef_t *GPIOx, uint16_t pinNumber, GPIO_PinState_t pinState );
GPIO_PinState_t GPIO_ReadPin(GPIO_TypeDef_t *GPIOx, uint16_t pinNumber);
void GPIO_LockPin(GPIO_TypeDef_t *GPIOx, uint16_t pinNumber);
void GPIO_TogglePin(GPIO_TypeDef_t *GPIOx, uint16_t pinNumber);

#endif /* INC_GPIO_H_ */



