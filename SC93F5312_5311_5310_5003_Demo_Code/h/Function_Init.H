#ifndef _Function_Init_H_
#define _Function_Init_H_

#include "H/SC93F531X_C.H"
#include "intrins.H"
#define uchar unsigned char
#define uint unsigned int
    
#define IapROM  0x00	  //0x00：选择ROM区操作  0x02：选择EEPROM区操作
#define IapEPPROM  0x02	  //0x00：选择ROM区操作  0x02：选择EEPROM区操作
	
extern void IO_Init(void);
extern void BTM_Test(void);
extern void EX_Test(void);
extern void LCD_Test(void);
extern void Timer_Test(void);
extern void PWM_Test(void);
extern void Uart0_Test(void);
extern void SPI_Test(void);
extern void ADC_Test(void);
extern void IAP_Test(uint Address,uchar IAPArea);

extern unsigned int ADCValue;

/*****************************************
说明：选择测试IC
*****************************************/
#define SC93F5312  0
#define SC93F5311  1
#define SC93F5310  2

#define IC_MODEL  SC93F5312

#endif