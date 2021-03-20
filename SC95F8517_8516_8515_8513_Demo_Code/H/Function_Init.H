#ifndef _Function_Init_H_
#define _Function_Init_H_

#include "SC95F851x_C.H"
#include "intrins.H"
#include "Multiplication_Division.H"
#define uchar unsigned char
#define uint unsigned int

extern void IO_Init(void);
extern void BTM_Test(void);
extern void EXTI_Test(void);
extern void Timer_Test(void);
extern void LCD_LED_Test(void);
extern void PWM_Test(void);
extern void Uart_Test(void);
extern void SSI0_Test(void);
extern void SSI1_Test(void);
extern void SSI2_Test(void);
extern void ADC_Test(void);
extern void IAP_Test(uint Address);
extern void CMP_Test(void);
extern void CRC_Test(void);
extern void Delay(uint time);

/*****************************************
ËµÃ÷£ºÑ¡Ôñ²âÊÔIC
*****************************************/
#define SC95F8517  0
#define SC95F8516  1
#define SC95F8515  2
#define SC95F8513  3

#define IC_MODEL  SC95F8515

#endif