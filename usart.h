/*
 * usart.h
 *
 *  Created on: Aug 25, 2023
 *      Author: metehan.cakmak
 */

#ifndef INC_USART_H_
#define INC_USART_H_

#include "stm32L1device.h"

/*
 * @def_group MODE_Types
 *
 */
#define USART_MODE_TX 			( (uint32_t)(0x00000008) )
#define USART_MODE_RX			( (uint32_t)(0x00000004) )
#define USART_MODE_TX_RX		( (uint32_t)(0x0000000C) )

/*
 * @def_group WordLenght_Types
 *
 */
#define USART_WORDLENGHT_8BITS	( (uint32_t)(0x00000000) )
#define USART_WORDLENGHT_9BITS	( (uint32_t)(0x00001000) )

/*
 * @def_group Parity_Modes
 *
 */
#define USART_PARITY_NONE		((uint32_t)(0x00000000))
#define USART_PARITY_EVEN		((uint32_t)(0x00000400))
#define USART_PARITY_ODD		((uint32_t)(0x00000600))

/*
 * @def_group StopBits_Modes
 *
 */
#define USART_STOPBIT_1				((uint32_t)(0x00000000))
#define USART_STOPBIT_HALF			((uint32_t)(0x00001000))
#define USART_STOPBIT_2				((uint32_t)(0x00002000))
#define USART_STOPBIT_1_HALF		((uint32_t)(0x00003000))

/*
 * @def_group OverSampling_Modes
 *
 */
#define USART_OVERSAMPLING_16		((uint32_t)(0x00000000))
#define USART_OVERSAMPLING_8		((uint32_t)(0x00008000))

/*
 * @def_group HardwareFlowControl_Modes
 *
 */
#define USART_HW_NONE				((uint32_t)(0x00000000))
#define USART_HW_CTS				((uint32_t)(0x00000200))
#define USART_HW_RTS				((uint32_t)(0x00000100))
#define USART_HW_CTS_RTS			((uint32_t)(0x00000300))

#define __UART_BRR_OVERSAMPLING_8(__PLCOK__, __BAUDRATE__)			((25 * (__PLCOK__) )	/ (4 * (__BAUDRATE__) ))
#define __UART_BRR_OVERSAMPLING_16(__PLCOK__, __BAUDRATE__)			((25 * (__PLCOK__) )	/ (2 * (__BAUDRATE__) ))

typedef struct
{
	uint32_t Mode;					/*!< Transmission and Reception Modes @def_group MODE_Types */
	uint32_t BaudRate;
	uint32_t WordLenght;			/*!< 8 Bits & 9 Bits Modes @def_group WordLenght_Types */
	uint32_t Parity;				/*!< Even & Odd Parity Modes @def_group Parity_Modes */
	uint32_t StopBits;				/*!< Stop Bits Modes @def_group StopBits_Modes */
	uint32_t OverSampling;			/*!< OverSampling Modes @def_group OverSampling_Modes */
	uint32_t HardwareFlowControl;	/*!< HardwareFlow Modes @def_group HardwareFlowControl_Modes */

}USART_InitTypedef_t;

typedef struct
{
	USART_Typedef_t* Instance;
	USART_InitTypedef_t Init;


}USART_HandleTypedef_t;

void USART_Init(USART_HandleTypedef_t *USART_Handle);
void USART_Enable(USART_HandleTypedef_t *USART_Handle , FunctionalState_t State);
void USART_Transmit(USART_HandleTypedef_t *USART_Handle, uint8_t *pData, uint16_t dataSize);


#endif /* INC_USART_H_ */
