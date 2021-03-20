#include "H/Function_Init.H"
/*****************************************************
*函数名称：void IO_Init(void)
*函数功能：IO初始化
*入口参数：void
*出口参数：void
*****************************************************/
void IO_Init(void)
{
	#if (IC_MODEL == SC95F7617)  //SC92F7617引脚定义
	P0CON = 0xFF;  //设置P0为强推挽模式
	P0PH  = 0x00;
	P1CON = 0x00;  //设置P1为高阻输入模式
	P1PH  = 0x00;
	P2CON = 0x00;  //设置P2为高阻带上拉模式
	P2PH  = 0xFF;
	P3CON = 0xFF;  //设置P3为强推挽模式
	P3PH  = 0x00;
	P4CON = 0xFF;  //设置P4为强推挽模式
	P4PH  = 0x01;
	P5CON = 0xFF;  //设置P5为强推挽模式
	P5PH  = 0x00;
	#endif
	
	#if (IC_MODEL == SC95F7616)  //SC92F7616引脚定义
	P0CON = 0xFF;  //设置P0为强推挽模式
	P0PH  = 0x00;
	P1CON = 0x00;  //设置P1为高阻输入模式
	P1PH  = 0x00;
	P2CON = 0x00;  //设置P2为高阻带上拉模式
	P2PH  = 0xFF;
	P3CON = 0xFF;  //设置P3为强推挽模式
	P3PH  = 0x00;
	P4CON = 0xFF;  //设置P4为强推挽模式
	P4PH  = 0x01;
	P5CON = 0xFF;  //设置P5为强推挽模式
	P5PH  = 0x00;
	SC95F7616_NIO_Init(); //未引出IO口配置
	#endif
	
    #if (IC_MODEL == SC95F7615)  //SC92F7615引脚定义
	P0CON = 0xFF;  //设置P0为强推挽模式
	P0PH  = 0x00;
	P1CON = 0x00;  //设置P1为高阻输入模式
	P1PH  = 0x00;
	P2CON = 0x00;  //设置P2为高阻带上拉模式
	P2PH  = 0xFF;
	P3CON = 0xFF;  //设置P3为强推挽模式
	P3PH  = 0x00;
	P4CON = 0xFF;  //设置P4为强推挽模式
	P4PH  = 0x01;
	P5CON = 0xFF;  //设置P5为强推挽模式
	P5PH  = 0x00;
	SC95F7615_NIO_Init(); //未引出IO口配置
	#endif
    
	#if (IC_MODEL == SC95F7613)  //SC92F7613引脚定义
	P0CON = 0xFF;  //设置P0为强推挽模式
	P0PH  = 0x00;
	P1CON = 0x00;  //设置P1为高阻输入模式
	P1PH  = 0x00;
	P2CON = 0x00;  //设置P2为高阻带上拉模式
	P2PH  = 0xFF;
	P3CON = 0xFF;  //设置P3为强推挽模式
	P3PH  = 0x00;
	P4CON = 0xFF;  //设置P4为强推挽模式
	P4PH  = 0x01;
	SC95F7613_NIO_Init(); //未引出IO口配置
	#endif
}

void Delay(uint time)
{
    for(;time>0;time--);
}