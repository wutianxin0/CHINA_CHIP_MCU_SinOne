#ifndef _Function_Init_H_
#define _Function_Init_H_

#include "H/SC93F843X_C.H"
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
extern void SSI_Test(void);
extern void ADC_Test(void);
extern void ADC_TS_Test(void);     //采温度传感器电压值
extern void IAP_Test(uint Address,uchar IAPArea);
extern void Delay(uint time);
extern unsigned int ADCValue;

/*****************************************
说明：选择测试IC
*****************************************/
#define SC93F8433  0
#define SC93F8432  1
#define SC93F8431  2

#define IC_MODEL  SC93F8433

#endif