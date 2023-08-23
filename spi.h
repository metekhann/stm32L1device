/*
 * SPI.h
 *
 *  Created on: 23 Ağu 2023
 *      Author: meteh
 */

#ifndef INC_SPI_H_
#define INC_SPI_H_

#include "stm32L1device.h"

typedef struct
{
	uint32_t Mode;
	uint32_t CPHA;
	uint32_t CPOL;
	uint32_t BaudRate;
	uint32_t SSM_Cmd;
	uint32_t DFF_Format;
	uint32_t BusConfig;

}SPI_Init_TypeDef_t;
typedef struct
{
	SPI_TypeDef_t* Instance;
	SPI_Init_TypeDef_t Init;

}SPI_HandleTypeDef_t;


#endif /* INC_SPI_H_ */
