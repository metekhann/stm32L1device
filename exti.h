/*
 * exti.h
 *
 *  Created on: Aug 23, 2023
 *      Author: metehan.cakmak
 */

#ifndef INC_EXTI_H_
#define INC_EXTI_H_

#include "stm32L1device.h"

/*
 * @def_group Port_Values
 */
#define EXTI_PORT_SOURCE_GPIOA				( (uint8_t)(0x0U) )
#define EXTI_PORT_SOURCE_GPIOB				( (uint8_t)(0x1U) )
#define EXTI_PORT_SOURCE_GPIOC				( (uint8_t)(0x2U) )
#define EXTI_PORT_SOURCE_GPIOD				( (uint8_t)(0x3U) )
#define EXTI_PORT_SOURCE_GPIOE				( (uint8_t)(0x4U) )
#define EXTI_PORT_SOURCE_GPIOH				( (uint8_t)(0x5U) )
#define EXTI_PORT_SOURCE_GPIOF				( (uint8_t)(0x6U) )
#define EXTI_PORT_SOURCE_GPIOG				( (uint8_t)(0x7U) )

/*
 * @def_group EXTI_Line_Values
 *
 */

#define EXTI_LINE_SOURCE_0					( (uint8_t)(0x0U) )
#define EXTI_LINE_SOURCE_1					( (uint8_t)(0x1U) )
#define EXTI_LINE_SOURCE_2					( (uint8_t)(0x2U) )
#define EXTI_LINE_SOURCE_3					( (uint8_t)(0x3U) )
#define EXTI_LINE_SOURCE_4					( (uint8_t)(0x4U) )
#define EXTI_LINE_SOURCE_5					( (uint8_t)(0x5U) )
#define EXTI_LINE_SOURCE_6					( (uint8_t)(0x6U) )
#define EXTI_LINE_SOURCE_7					( (uint8_t)(0x7U) )
#define EXTI_LINE_SOURCE_8					( (uint8_t)(0x8U) )
#define EXTI_LINE_SOURCE_9					( (uint8_t)(0x9U) )
#define EXTI_LINE_SOURCE_10					( (uint8_t)(0xAU) )
#define EXTI_LINE_SOURCE_11					( (uint8_t)(0xBU) )
#define EXTI_LINE_SOURCE_12					( (uint8_t)(0xCU) )
#define EXTI_LINE_SOURCE_13					( (uint8_t)(0xDU) )
#define EXTI_LINE_SOURCE_14					( (uint8_t)(0xEU) )
#define EXTI_LINE_SOURCE_15					( (uint8_t)(0xFU) )


/*
 * @def_group EXTI_Mode_Values
 *
 */

#define EXTI_MODE_INTERRUPT				(0x00U)
#define EXTI_MODE_EVENT					(0x04U)

/*
 * @def_group EXTI_Trigger_Values
 *
 */
#define EXTI_TRIGGER_RISING				(0x08U)
#define EXTI_TRIGGRER_FALLING			(0x0CU)
#define EXTI_TRIGGER_RF					(0x10U)

typedef struct
{
	uint8_t EXTI_LineNumber;			/*!< EXTI line number for valid GPIO pin @def_group EXTI_Line_Values >*/
	uint8_t TriggerSelection;
	uint8_t EXTI_Mode;					/*!< EXTI Mode values @def_group EXTI_Modes >	*/
	FunctionalState_t EXTI_LineCmd;		/*!< Mask or Unmask the line number > */

}EXTI_InitTypeDef_t;

void EXTI_Init(EXTI_InitTypeDef_t *EXTI_InitStruct);
void EXTI_LineConfig(uint8_t PortSource, uint8_t EXTI_LineSource);
void NVIC_EnableInterrupt(uint8_t IRQ_Number);

#endif /* INC_EXTI_H_ */
