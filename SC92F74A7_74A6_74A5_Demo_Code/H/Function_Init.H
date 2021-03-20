#ifndef _Function_Init_H_
#define _Function_Init_H_

#include "H/SC92F74Ax_2_C.H"
#include "intrins.H"
#include "H/Multiplication_Division.H"
#define uchar unsigned char
#define uint unsigned int

#define IapROM  0x00	  //0x00：选择ROM区操作  0x02：选择EEPROM区操作
#define IapEPPROM  0x02	  //0x00：选择ROM区操作  0x02：选择EEPROM区操作

extern void IO_Init(void);
extern void BTM_Test(void);
extern void EXTI_Test(void);
extern void Timer_Test(void);
extern void LCD_LED_Test(void);
extern void PWM_Test(void);
extern void Uart0_Test(void);
extern void SSI_Test(void);
extern void ADC_Test(void);
extern void IAP_Test(uint Address,uchar IAPArea);
void CMP_Test(void);

/*****************************************
说明：选择测试IC
*****************************************/
#define SC92F74A7  0
#define SC92F74A6  1
#define SC92F74A5  2

#define IC_MODEL  SC92F74A7

#endif