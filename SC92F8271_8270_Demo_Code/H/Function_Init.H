#ifndef _Function_Init_H_
#define _Function_Init_H_

#include "SC92F827x_C.H"
#include "intrins.H"
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
extern void SSI_Test(void);
extern void IAP_Test(uint Address,uchar IAPArea);

/*****************************************
说明：选择测试IC
*****************************************/
#define SC92F8271  0
#define SC92F8270  1

#define IC_MODEL  SC92F8271

#endif