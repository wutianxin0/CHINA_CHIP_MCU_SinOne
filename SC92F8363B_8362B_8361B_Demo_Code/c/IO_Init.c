#include "H/Function_Init.H"
/*****************************************************
*函数名称：void IO_Init(void)
*函数功能：IO初始化
*入口参数：void
*出口参数：void
*****************************************************/
void IO_Init(void)
{
	#if (IC_MODEL == SC92F8363B)  //SC92F8363脚定义
	P0CON = 0x00;  //设置P0为高阻输入模式
	P0PH  = 0x00;		
	P1CON = 0x00;  //设置P1为高阻带上拉模式
	P1PH  = 0xFF;
	P2CON = 0xFF;  //设置P2为强推挽模式
	P2PH  = 0x00;
	P5CON = 0xFF;  //设置P4为强推挽模式
	P5PH  = 0x00;
	#endif
	
	#if (IC_MODEL == SC92F8362B)  //SC92F8362脚定义
	P0CON = 0x00;  //设置P0为高阻输入模式
	P0PH  = 0x00;		
	P1CON = 0x00;  //设置P1为高阻带上拉模式
	P1PH  = 0xFF;
	P2CON = 0xFF;  //设置P2为强推挽模式
	P2PH  = 0x00;
	SC92F8362B_NIO_Init(); //未引出IO口配置
	#endif
	
	#if (IC_MODEL == SC92F8361B)  //SC92F8361脚定义
	P0CON = 0x00;  //设置P0为高阻输入模式
	P0PH  = 0x00;		
	P1CON = 0x00;  //设置P1为高阻带上拉模式
	P1PH  = 0xFF;
	P2CON = 0xFF;  //设置P2为强推挽模式
	P2PH  = 0x00;
	SC92F8361B_NIO_Init(); //未引出IO口配置
	#endif
}