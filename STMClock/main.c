/*
 * File			: peripheral operations on STM32 EVK
 * Description	: This file contains peripheral related functions to read/write/init a peripheral
 * Author		: Shrenik Shikhare.
 * Date			: 12th May 2013
 * Email ID	: engineershrenik@gmail.com
 */



#include "stm32f103.h"


//#define CLOCK_TEST
//#define GPIO_TEST
//#define BIT_BAND_TEST
//#define UART_TEST


#define RAM_BASE       0x20000000
#define RAM_BB_BASE    0x22000000
#define BAUD			115200
#define APB1CLK			8000000
#define BAUD_VALUE		(APB1CLK / (16*BAUD))


#define RSTBIT_BB(Address, BIT)    \

#define SETBIT_BB(Address, BIT)       \
          (*(uint32_t *) (RAM_BB_BASE | ((Address - RAM_BASE) << 5) | ((BIT) << 2)) = 1)

#define GETBIT_BB(Address, BIT)       \
          (*(uint32_t *) (RAM_BB_BASE | ((Address - RAM_BASE) << 5) | ((BIT) << 2)))



uint32_t Var, Address = 0, VarBitValue = 0;

uint8_t arr[] = "UART is working from global\r\n";

void Delay(int delay)
{
	int i;
	for (i=0; i<delay; i++);
}

void RCCConfig()
{

	RCC_CR|=0x00010000;	//Select clock source for GPIO External HSE
	while(!(RCC_CR & 0x00020000));	//check if the clock is stable or not
	//RCC_CFGR = RCC_CR+4;
	RCC_CFGR &= 0xFFFFFF0F;		//dont divide the clock
}


void GPIOInit()
{
	RCC_APB2ENR |= 0x80;	//enable the clock
	GPIOF_CRL &= 0x00FFFFFF;//Configure the GPIO PF6,7,8,9 as Push pull I/O at 10MHz clock rate
	GPIOF_CRL |= 0x11000000;	//Configure GPIO as push pull out and at 10MHz
	GPIOF_CHR &= 0xFFFFFF00;
	GPIOF_CHR |= 0x00000011;
}

void GPIOToggle()
{
	GPIOF_BSRR|=0x000003C0;		//Write 1 to all GPIO as PF6 ...Pf9
	Delay(100000);
	GPIOF_BSRR &= ~ (0x000003C0);//Write 0 to all GPIOs from PF6...PF9
	Delay(100000);
}

/*
 * UARTInit which initializes UART1 clock, TX/RX, BAUD rate, and maps pins of STM32f103 to RA9,RA10 which are TX n RX resp
 */

void UARTInit()
{
	RCC_APB2ENR|= 0x00004005;	//AFIO clock Enabled and PA clock enable, enable usart1 clock
	AFIO_MAPR &=0xFFFFFFFB;		//No alternate function
	GPIOA_CHR &=0xFFFFF00F;		//
	GPIOA_CHR |=0x000004B0;
	USART1_BRR = (4 << 4) | 5;//BAUD_VALUE at system clk 8Mhz;
	USART1_CR1 &= 0xFFFFCBF3;	//Enable Transmission and reception and usart clock
	USART1_CR1 |= 0x0000200C;

}

void putChar(char data)
{
	USART1_DR = data;	//write to data register
	while(!(USART1_SR & 0x00000080)); //check for TXE is set
}


void UARTprintf(char *data)
{
	while(*data)
		putChar(*data++);
}

void TestBitBand()
{
#if 0
	Var = 0x00005AA5;
	Address = (uint32_t)&Var;

	/* Modify variable bit using bit-band access ---------------------------------*/
	  /* Modify Var variable bit 0 -----------------------------------------------*/
	RSTBIT_BB(Address, 0);  /* Var = 0x00005AA4 */
	SETBIT_BB(Address, 0);    /* Var = 0x00005AA5 */

	 /* Modify Var variable bit 11 ----------------------------------------------*/
	  RSTBIT_BB(Address, 11);             /* Var = 0x000052A5 */
	  /* Get Var variable bit 11 value */
	  VarBitValue = GETBIT_BB(Address, 11); /* VarBitValue = 0x00000000 */
	  if(VarBitValue)
		  GPIOF_BSRR|=0x00000080;
	  else
		  GPIOF_BSRR &= ~(0x00000080);

	  Delay(10000);


	  SETBIT_BB(Address, 11);               /* Var = 0x00005AA5 */
	  /* Get Var variable bit 11 value */
	  VarBitValue = GETBIT_BB(Address, 11);    /* VarBitValue = 0x00000001 */

	  /* Modify Var variable bit 31 ----------------------------------------------*/
	  SETBIT_BB(Address, 31);               /* Var = 0x80005AA5 */
	  /* Get Var variable bit 31 value */
	  VarBitValue = GETBIT_BB(Address, 31); /* VarBitValue = 0x00000001 */

	  RSTBIT_BB(Address, 31);             /* Var = 0x00005AA5 */
	  /* Get Var variable bit 31 value */
	  VarBitValue = GETBIT_BB(Address, 31); /* VarBitValue = 0x00000000 */
#endif
}

//extern _data, _edata;


/*
void ScatterLoader()
{
	while (_data != _edata)
	{
		*(.data*)=*(.text*);
	}
}
*/


int main()
{
	GPIOInit();
	UARTInit();

	UARTprintf("UART is working\r\n");

	UARTprintf(arr);


	//RCCConfig();
}
