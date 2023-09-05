/*
 * UsartTest.c
 *
 *  Created on: Aug 28, 2023
 *      Author: meteh
 */

#include "stm32L1device.h"

USART_HandleTypedef_t huart1;
USART_HandleTypedef_t huart2;

static void GPIO_Config(void);
static void USART_Config(void);
static void print_m(const char *data, ...);

char Buffer[20];



int main(void)
{
	GPIO_Config();
	USART_Config();
	int yas = 23;
	char harf = 'z';
	char isim[] = "metehan";
	print_m("isim :%c",harf);



	USART_Receive_IT(&huart1,(uint8_t *)Buffer, 4);


	while(1)
	{




		//USART_Transmit(&huart1, (uint8_t *) "bekle\n", 6);
		//print_m("HClock :%d		P1Clock :%d		P2Clock: %d		SClock:%d\n",Hclock_speed, P1clock_speed, P2clock_speed, S1clock_speed);

	}
}
static void USART_Config(void)
{
	RCC_USART1_CLK_ENABLE();
	RCC_USART2_CLK_ENABLE();

/*********	USART1	***************/
	huart1.Instance = USART1;
	USART_Enable(&huart1, ENABLE);

	huart1.Init.BaudRate = 115200;
	huart1.Init.HardwareFlowControl = USART_HW_NONE;
	huart1.Init.Mode = USART_MODE_TX_RX;
	huart1.Init.OverSampling = USART_OVERSAMPLING_16;
	huart1.Init.StopBits = USART_STOPBIT_1;
	huart1.Init.Parity = USART_PARITY_NONE;
	huart1.Init.WordLenght = USART_WORDLENGHT_8BITS;

	USART_Init(&huart1);

	NVIC_EnableInterrupt(USART1_IRQNumber);


/********	USART2	********/
	huart2.Instance = USART2;
	USART_Enable(&huart2, ENABLE);

	huart2.Init.BaudRate = 9600;
	huart2.Init.HardwareFlowControl = USART_HW_NONE;
	huart2.Init.Mode = USART_MODE_TX;
	huart2.Init.OverSampling = USART_OVERSAMPLING_16;
	huart2.Init.StopBits = USART_STOPBIT_1;
	huart2.Init.Parity = USART_PARITY_NONE;
	huart2.Init.WordLenght = USART_WORDLENGHT_8BITS;



	USART_Init(&huart2);



}

static void GPIO_Config(void)
{
	RCC_GPIOA_CLOCK_ENABLE();

	GPIO_InitTypeDef_t GPIO_InitStruct = {0};

	GPIO_InitStruct.pinNumber = (GPIO_PIN_9 | GPIO_PIN_10);
	GPIO_InitStruct.Mode = GPIO_MODE_ALTERNATE;
	GPIO_InitStruct.Otype = GPIO_OTYPE_PUSH_PULL;
	GPIO_InitStruct.PuPd = GPIO_PuPd_NOPULL;
	GPIO_InitStruct.Speed = GPIO_SPEED_HIGH;
	GPIO_InitStruct.Alternate = GPIO_ALTERNATE_7;

	GPIO_Init(GPIOA, &GPIO_InitStruct);




}
static void print_m(const char *data, ...)
{
	va_list arg;
	const char *tempData = data;
	char c;
	int d;
	char integerBuffer[20];
	char *s;
	va_start(arg, data);

	while(*tempData != '\0')
	{
		if(*tempData == '%')
		{
			if(*(tempData + 1) == 'c')
			{
				c = va_arg(arg , int);
				USART_Transmit(&huart1,(uint8_t *)&c , 1);
				tempData++;
			}
			else if(*(tempData + 1) == 'd')
			{
				d = va_arg(arg, int);
				itoa(d, integerBuffer,10);
				USART_Transmit(&huart1,(uint8_t *)integerBuffer , strlen(integerBuffer));
				tempData++;
			}
			else if(*(tempData + 1) == 's')
			{
				s = va_arg(arg, char*);
				USART_Transmit(&huart1,(uint8_t *)s , strlen(s));
				tempData++;
			}
			else
			{
				USART_Transmit(&huart1,(uint8_t *)"%" , 1);
			}
		}
		else
		{
			USART_Transmit(&huart1,(uint8_t *)tempData , 1);
		}
		tempData++;
	}

	//USART_Transmit(&huart, (uint8_t*)data, 20);
	va_end(arg);

}

void USART1_IRQHandler()
{
	USART_InterruptHandler(&huart1);
}

void USART_RxCallback(USART_HandleTypedef_t *USART_Handle)
{
	if(USART_Handle == &huart1)
	{
		uint32_t Hclock_speed = RCC_GetHClock();
		uint32_t P1clock_speed = RCC_GetPClk1Clock();
		uint32_t P2clock_speed = RCC_GetPClk2Clock();
		uint32_t S1clock_speed = RCC_GetSystemClock();

		if(!strcmp(Buffer, "saat"))
		{
			print_m("\nHClock :%d		P1Clock :%d		P2Clock: %d		SClock:%d \n",Hclock_speed, P1clock_speed, P2clock_speed, S1clock_speed);
		}
		else if(!strcmp(Buffer, "baud"))
		{
			print_m("\nMantissa: %d\n",(__UART_BRR_OVERSAMPLING_16(P2clock_speed, USART_Handle->Init.BaudRate) / 100U));
		}
		else
		{

			USART_Transmit(&huart1, (uint8_t *) "\ngecersiz\n", 9);

		}
		USART_Receive_IT(&huart1,(uint8_t *)Buffer, 4);
	}

}

