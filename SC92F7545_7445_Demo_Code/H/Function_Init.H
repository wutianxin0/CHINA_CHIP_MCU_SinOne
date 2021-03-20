#ifndef _Function_Init_H_
#define _Function_Init_H_

#include "SC92F754x_C.H"
#include "intrins.H"
#include "Multiplication_Division.H"
#define uchar unsigned char
#define uint unsigned int

#define IapROM  0x00	  //0x00：选择ROM区操作  0x02：选择EEPROM区操作
#define IapEPPROM  0x02	  //0x00：选择ROM区操作  0x02：选择EEPROM区操作

extern void IO_Init(void);
extern void BTM_Test(void);
extern void EXTI_Test(void);
extern void Timer_Test(void);
extern void PWM_Test(void);
extern void Uart0_Test(void);
extern void SSI_Test(void);
extern void ADC_Test(void);
extern void IAP_Test(uint Address,uchar IAPArea);
void CMP_Test(void);

#endif