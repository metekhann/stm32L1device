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

#define __UART_BRR_OVERSAMPLING_8(__PLCOK__, __BAUDRATE__)			((25U * ((uint32_t)__PLCOK__) )	/ (2U * ((uint32_t)__BAUDRATE__) ))
#define __UART_BRR_OVERSAMPLING_16(__PLCOK__, __BAUDRATE__)			((25U * ((uint32_t)__PLCOK__) )	/ (4U * ((uint32_t)__BAUDRATE__) ))

typedef enum
{
	USART_BUS_FREE 	= 0x0,
	USART_BUS_Tx   	= 0x1,
	USART_BUS_Rx	= 0x2
}USART_BusState;


/**********HAL LIBRARY CODES *////////

#define UART_DIV_SAMPLING16(_PCLK_, _BAUD_)            (((_PCLK_)*25U)/(4U*(_BAUD_)))
#define UART_DIVMANT_SAMPLING16(_PCLK_, _BAUD_)        (UART_DIV_SAMPLING16((_PCLK_), (_BAUD_))/100U)
#define UART_DIVFRAQ_SAMPLING16(_PCLK_, _BAUD_)        ((((UART_DIV_SAMPLING16((_PCLK_), (_BAUD_)) - (UART_DIVMANT_SAMPLING16((_PCLK_), (_BAUD_)) * 100U)) * 16U)\
                                                         + 50U) / 100U)
/* UART BRR = mantissa + overflow + fraction
            = (UART DIVMANT << 4) + (UART DIVFRAQ & 0xF0) + (UART DIVFRAQ & 0x0FU) */
#define UART_BRR_SAMPLING16(_PCLK_, _BAUD_)            (((UART_DIVMANT_SAMPLING16((_PCLK_), (_BAUD_)) << 4U) + \
                                                         (UART_DIVFRAQ_SAMPLING16((_PCLK_), (_BAUD_)) & 0xF0U)) + \
                                                        (UART_DIVFRAQ_SAMPLING16((_PCLK_), (_BAUD_)) & 0x0FU))

#define UART_DIV_SAMPLING8(_PCLK_, _BAUD_)             (((_PCLK_)*25U)/(2U*(_BAUD_)))
#define UART_DIVMANT_SAMPLING8(_PCLK_, _BAUD_)         (UART_DIV_SAMPLING8((_PCLK_), (_BAUD_))/100U)
#define UART_DIVFRAQ_SAMPLING8(_PCLK_, _BAUD_)         ((((UART_DIV_SAMPLING8((_PCLK_), (_BAUD_)) - (UART_DIVMANT_SAMPLING8((_PCLK_), (_BAUD_)) * 100U)) * 8U)\
                                                         + 50U) / 100U)

#define UART_BRR_SAMPLING8(_PCLK_, _BAUD_)             (((UART_DIVMANT_SAMPLING8((_PCLK_), (_BAUD_)) << 4U) + \
                                                         ((UART_DIVFRAQ_SAMPLING8((_PCLK_), (_BAUD_)) & 0xF8U) << 1U)) + \
                                                        (UART_DIVFRAQ_SAMPLING8((_PCLK_), (_BAUD_)) & 0x07U))



#define UART_BRR_SAMPLING16(_PCLK_, _BAUD_)            (((UART_DIVMANT_SAMPLING16((_PCLK_), (_BAUD_)) << 4U) + \
                                                         (UART_DIVFRAQ_SAMPLING16((_PCLK_), (_BAUD_)) & 0xF0U)) + \
                                                        (UART_DIVFRAQ_SAMPLING16((_PCLK_), (_BAUD_)) & 0x0FU))

/**********HAL LIBRARY CODES *////////




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

typedef struct __USART_HandleTypedef_t
{
	USART_Typedef_t* Instance;
	USART_InitTypedef_t Init;
	uint8_t *pTxBuffer;
	uint16_t TxBufferSizze;
	uint8_t TxStatus;
	void(*txISR_Function)(struct __USART_HandleTypedef_t *UART_Handle);
	uint8_t *pRxBuffer;
	uint16_t RxBufferSize;
	uint8_t RxStatus;
	void(*rxISR_Function)(struct __USART_HandleTypedef_t *UART_Handle);


}USART_HandleTypedef_t;

void USART_Init(USART_HandleTypedef_t *USART_Handle);
void USART_Enable(USART_HandleTypedef_t *USART_Handle , FunctionalState_t State);
void USART_Transmit(USART_HandleTypedef_t *USART_Handle, uint8_t *pData, uint16_t dataSize);
void USART_Receive(USART_HandleTypedef_t *USART_Handle, uint8_t *pData, uint16_t dataSize);
void USART_Transmit_IT(USART_HandleTypedef_t *USART_Handle, uint8_t *pData, uint16_t dataSize);
void USART_Receive_IT(USART_HandleTypedef_t *USART_Handle, uint8_t *pData, uint16_t dataSize);
void USART_RxCallback(USART_HandleTypedef_t *USART_Handle);
void USART_InterruptHandler(USART_HandleTypedef_t *USART_Handle);


#endif /* INC_USART_H_ */
