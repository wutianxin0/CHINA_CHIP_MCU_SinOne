#include "H/Function_Init.H"

/**************************************************************
说明：
1、Options for Target‘Target1’：BL51 Locate->Code Range:0x100，烧录选项请选择DISRST，复位脚作为普通IO使用；
2、改变TEST的定义，可以分别测试对应的功能；
3、注意：先在Function.H里面选择测试型号（SC92F7320无LCD/LED和PWM功能）
***************************************************************/
#define Test  0    //BTM:0 EXTI:1 Timer:2 LCD:3 PWM:4 Uart0:5 ADC:7 IAP:8 

void main(void)
{
	IO_Init();
	WDTCON |= 0x10;		    //清看门狗
	switch(Test)
	{
		case 0: BTM_Test();
		break;
		case 1: EXTI_Test();
		break;
		case 2: Timer_Test();
		break;
		case 3: LCD_Test();
		break;
		case 4: PWM_Test();
		break;
		case 5: Uart0_Test();
		break;
		case 7: ADC_Test();
		break;
		case 8: IAP_Test(0xfff,IapROM);   //操作ROM，对地址0xfff进行读写测试
//		        IAP_Test(0x7f,IapEPPROM);   //操作EPPROM，对地址0x7f进行读写测试
		break;
		default:
		break;
	}
}