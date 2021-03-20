#include "H/Function_Init.H"
/*****************************************************
*函数名称：void IO_Init(void)
*函数功能：IO初始化
*入口参数：void
*出口参数：void
*****************************************************/
void IO_Init(void)
{
    #if (IC_MODEL == SC93F5312)  //SC93F5312引脚定义
	P0CON = 0x00;  //设置P0为高阻带上拉模式
	P0PH  = 0xFF;
	P1CON = 0x00;  //设置P1为高阻输入模式
	P1PH  = 0x00;
	P2CON = 0xFF;  //设置P2为强推挽模式
	P2PH  = 0x00;
	#endif
    
    #if (IC_MODEL == SC93F5311)  //SC93F5311引脚定义
	P0CON = 0x00;  //设置P0为高阻带上拉模式
	P0PH  = 0xFF;
	P1CON = 0x00;  //设置P1为高阻输入模式
	P1PH  = 0x00;
	P2CON = 0xFF;  //设置P2为强推挽模式
	P2PH  = 0x00;
	SC93F5311_NIO_Init(); //未引出IO口配置
	#endif
    
    #if (IC_MODEL == SC93F5310)  //SC93F5310引脚定义
	P1CON = 0x00;  //设置P1为高阻输入模式
	P1PH  = 0x00;
	P2CON = 0xFF;  //设置P2为强推挽模式
	P2PH  = 0x00;
	SC93F5310_NIO_Init(); //未引出IO口配置
	#endif
}