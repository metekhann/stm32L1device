/*
 * SPI.h
 *
 *  Created on: 23 Ağu 2023
 *      Author: meteh
 */

#ifndef INC_SPI_H_
#define INC_SPI_H_

#include "stm32L1device.h"

typedef enum
{
	SPI_BUS_FREE = 0x0U,
	SPI_BUS_BUSY_TX = 0x1U,
	SPI_BUS_BUSY_RX = 0x2U
}SPI_BusStatus_t;
/*
 * @def_group SPI_BaudRate
 *
 */

#define SPI_BAUDRATE_DIV2       	((uint32_t)(0x00000000))
#define SPI_BAUDRATE_DIV4       	((uint32_t)(0x00000008))
#define SPI_BAUDRATE_DIV8       	((uint32_t)(0x00000010))
#define SPI_BAUDRATE_DIV16       	((uint32_t)(0x00000018))
#define SPI_BAUDRATE_DIV32       	((uint32_t)(0x00000020))
#define SPI_BAUDRATE_DIV64       	((uint32_t)(0x00000028))
#define SPI_BAUDRATE_DIV128       	((uint32_t)(0x00000030))
#define SPI_BAUDRATE_DIV256       	((uint32_t)(0x00000038))

/*
 * @def_group CPHA_Values
 *
 */
#define	SPI_CPHA_FIRST				((uint32_t)(0x00000000))
#define SPI_CPHA_SECOND				((uint32_t)(0x00000001))

/*
 * @def_group CPOL_Values
 *
 */
#define SPI_CPOL_LOW				((uint32_t)(0x00000000))
#define SPI_CPOL_HIGH				((uint32_t)(0x00000002))

/*
 * @def_group DFF_Format
 *
 */
#define SPI_DFF_8BIT				((uint32_t)(0x00000000))
#define SPI_DFF_16BIT				((uint32_t)(0x00000800))

/*
 * @def_group Mode_Values
 *
 */
#define SPI_MODE_SLAVE				((uint32_t)(0x00000000))
#define SPI_MODE_MASTER				((uint32_t)(0x00000004))

/*
 * @def_group Frame_Format
 *
 */
#define SPI_FRAME_FORMAT_MSB		((uint32_t)(0x00000000))
#define SPI_FRAME_FORMAT_LSB		((uint32_t)(0x00000080))

/*
 * @def_group SPI_BusConfig
 *
 */
#define SPI_FULL_DUBLEX				((uint32_t)(0x00000000))
#define SPI_RECEIVE_ONLY			((uint32_t)(0x00000400))
#define SPI_HALF_DUBLEX_TX			((uint32_t)(0xC0000000))
#define SPI_HALF_DUBLEX_RX			((uint32_t)(0x80000000))

/*
 * @def_group SPI_SSM
 *
 */

#define SPI_SSM_DISABLE				((uint32_t)(0x00000000))
#define SPI_SSM_ENABLE				((uint32_t)(0x00000300))

typedef struct
{
	uint32_t Mode;			/*!< Mode Values for SPI		@def_group Mode_Values >*/
	uint32_t CPHA;			/*!< CPHA Values for SPI 		@def_group CPHA_Values >*/
	uint32_t CPOL;			/*!< CPOL Values for SPI 		@def_group CPOL_Values	>*/
	uint32_t BaudRate;		/*!< BaudRate Values for SPI 	@def_group SPI_BaudRate >*/
	uint32_t SSM_Cmd;		/*!< SSM Values for SPI 		@def_group SPI_SSM 		>*/
	uint32_t DFF_Format;	/*!< DFF_Format Values for SPI 	@def_group DFF_Format	>*/
	uint32_t BusConfig;		/*!< BusConfig Values for SPI 	@def_group SPI_BusConfig >*/
	uint32_t FrameFormat;	/*!  Frame Format Values for SPI @def_group Frame_Format >*/

}SPI_Init_TypeDef_t;

typedef struct __SPI_HandleTypedef_t
{
	SPI_TypeDef_t* Instance;
	SPI_Init_TypeDef_t Init;
	uint8_t *pTxDataAddr;
	uint16_t TxDataSize;
	uint8_t BusStateTx;
	void(*TxISRFunction)(struct __SPI_HandleTypedef_t *SPI_Handle_Struct);


}SPI_HandleTypeDef_t;

void SPI_Init(SPI_HandleTypeDef_t *Handle);
void SPI_PeripheralCmd(SPI_HandleTypeDef_t *SPI_Handle_Struct, FunctionalState_t stateOfSPI);
void SPI_TransmitData(SPI_HandleTypeDef_t *SPI_Handle_Struct, uint8_t *pData, uint16_t sizeofData);
void SPI_TransmitData_IT(SPI_HandleTypeDef_t *SPI_Handle_Struct, uint8_t *pData, uint16_t sizeofData);
void SPI_InterruptHandler(SPI_HandleTypeDef_t *SPI_Handle_Struct);

#endif /* INC_SPI_H_ */
