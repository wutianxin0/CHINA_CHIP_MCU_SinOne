#include "H/Function_Init.H"
/*****************************************************
*函数名称：void IO_Init(void)
*函数功能：IO初始化
*入口参数：void
*出口参数：void
*****************************************************/
void IO_Init(void)
{
	#if (IC_MODEL == SC92F7352)  //SC92F7352引脚定义
	P0CON = 0xFF;  //设置P0为强推挽模式
	P0PH  = 0x00;
	P1CON = 0x00;  //设置P1为高阻输入模式
	P1PH  = 0x00;
	P2CON = 0x00;  //设置P2为高阻带上拉模式
	P2PH  = 0xFF;
	#endif
	
	#if (IC_MODEL == SC92F7351)  //SC92F7352引脚定义
	P0CON = 0xFF;  //设置P0为强推挽模式
	P0PH  = 0x00;
	P1CON = 0x00;  //设置P1为高阻输入模式
	P1PH  = 0x00;
	P2CON = 0x00;  //设置P2为高阻带上拉模式
	P2PH  = 0xFF;
	SC92F7351_NIO_Init(); //未引出IO口配置
	#endif
	
	#if (IC_MODEL == SC92F7350)  //SC92F7350引脚定义
	P0CON = 0xFF;  //设置P0为强推挽模式
	P0PH  = 0x00;
	P1CON = 0x00;  //设置P1为高阻输入模式
	P1PH  = 0x00;
	P2CON = 0x00;  //设置P2为高阻带上拉模式
	P2PH  = 0xFF;
	SC92F7350_NIO_Init(); //未引出IO口配置
	#endif
	
}