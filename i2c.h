/*
 * i2c.c
 *
 *  Created on: Sep 3, 2023
 *      Author: meteh
 */

#ifndef INC_I2C_C_
#define INC_I2C_C_

#include "stm32L1device.h"

#define CHECK_PCLOCK_VALUE(__pClock__, __I2C_Clock__)			((__I2C_Clock__ <= I2C_SPEED_STANDART) ? (__pClock__ <= 2000000U) : (__pClock__ <= 4000000U))
#define I2C_GET_FREQ_VALUE(__pClock__)							((__pClock__) / (1000000U))

/*
 * @def_group I2C_ClockSpeed
 *
 */
#define I2C_SPEED_STANDART		(100000U)
#define I2C_SPEED_FASTMODE		(400000U)

/*
 *
 * @def_group ACK State
 */
#define I2C_ACK_DISABLE			(0x00000000U)
#define I2C_ACK_ENABLE			(0x00000400U)

/*
 * @def_group ClockStretch State
 *
 */
#define I2C_STRETCH_DISABLE			(0x00000080U)
#define I2C_STRETCH_ENABLE			(0x00000000U)

/*
 * @def_group Address Mode
 *
 */
#define I2C_ADDRMODE_7			(0x00004000U)
#define I2C_ADDRMODE_10			(0x0000C000U)

/*
 *@def_group Duty mode
 *
 */
#define I2C_DUTY_STANDART		(0x00000000U)
#define I2C_DUTY_FAST_2			(0x00008000U)
#define I2C_DUTY_FAST_16_2		(0x0000C000U)

typedef struct
{
	uint32_t ClockSpeed;	// @def_group I2C_ClockSpeed
	uint32_t ACK_STATE;		// @def_group ACK State
	uint32_t ClockStretch;	// @def_group ClockStretch State
	uint32_t AddressingMode;// @def_group Address Mode
	uint32_t DutyCycle; 	// @def_group Duty mode
	uint32_t MyOwnAddress; 	// Slave Mode Address

}I2C_InitYpedef_t;

typedef struct
{
	I2C_InitYpedef_t *Init;
	I2C_Typedef_t *Instance;


}I2C_HandleTypedef_t;

void I2C_Init(I2C_HandleTypedef_t *I2C_Handle);
void I2C_Enable(I2C_Typedef_t *I2Cx, FunctionalState_t stateofI2C);
void I2C_Master_Transmit(I2C_HandleTypedef_t *I2C_Handle, uint8_t *pData, uint32_t dataSize, uint8_t SlaveAddr);

#endif /* INC_I2C_C_ */
