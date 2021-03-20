#include "H/Function_Init.H"

void EX_Init(void);

/*****************************************************
*函数名称：void EXTI_Test(void)
*函数功能：外部中断测试
*入口参数：void
*出口参数：void
*****************************************************/
void EXTI_Test(void)
{
	EX_Init();
	while(1)
	{
	}
}
/*****************************************************
*函数名称：void EX_Init(void)
*函数功能：外部中断初始化
*入口参数：void
*出口参数：void
*****************************************************/
void EX_Init(void)
{	
	P0CON&= 0X02;     //中断IO口设置为高阻输入
	P0PH |= 0x01;
	P1CON&= 0X80;     //中断IO口设置为高阻输入
	P1PH |= 0x7F;
	P2CON&= 0X01;     //中断IO口设置为高阻输入
	P2PH |= 0xFE;

	INT0F = 0X03 ;//xxxx 0000  0关闭 1使能
	INT1F = 0X7f ;//xxxx xxxx  0关闭 1使能
    INT2F = 0Xfe ;//0000 xxxx  0关闭 1使能	
	INT0R = 0X03 ;//xxxx 0000  0关闭 1使能
	INT1R = 0X7f ;//xxxx xxxx  0关闭 1使能
	INT2R = 0Xfe ;//0000 xxxx  0关闭 1使能	
	
	//测试全部外部中断功能
	IE |= 0x85;	//0000 0x0x
	IE1|= 0x08;	//0000 x000  INT2使能
	IP |= 0X00;
	IP1|= 0X00;
	EA = 1;
}

/*****************************************************
*函数名称：void EX0/1/2() interrupt	0/2/10
*函数功能：外部中断函数
*入口参数：void
*出口参数：void
*****************************************************/
void EX0() interrupt	0
{
   P01 = ~P01;
}

void EX1() interrupt	2
{
   P17 = ~P17;
}

void EX2() interrupt	10
{
   P20 = ~P20;
}
