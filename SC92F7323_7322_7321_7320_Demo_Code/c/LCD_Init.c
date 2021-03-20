#include "H/Function_Init.H"

void LCD_Init(uchar VDD_1_2);
void Delay(uint time);
enum COM{COM0=1,COM1=2,COM2=4,COM3=8,COM4=16};
/*****************************************************
*函数名称：void LCD_Test(void)
*函数功能：LCD测试
*入口参数：void
*出口参数：void
*****************************************************/
void LCD_Test(void)
{
    P0CON |= 0x1F;
    P0PH &= 0xE0;
	while(1)
	{   
        P0 |= 0x1f;        
        LCD_Init(~(COM0)); 
        Delay(100);
        LCD_Init(~(COM1)); 
        Delay(100);
        LCD_Init(~(COM2)); 
        Delay(100);
        LCD_Init(~(COM3)); 
        Delay(100);
        LCD_Init(~(COM4)); 
        Delay(100);
        
        P0 &= 0xE0;        
        LCD_Init(~(COM0)); 
        Delay(100);
        LCD_Init(~(COM1)); 
        Delay(100);
        LCD_Init(~(COM2)); 
        Delay(100);
        LCD_Init(~(COM3)); 
        Delay(100);
        LCD_Init(~(COM4)); 
        Delay(100);             
	}
}

/*****************************************************
*函数名称：void LCD_Init(uchar VDD_1_2)
*函数功能：LCD初始化
*入口参数：VDD_1_2
*出口参数：void
*****************************************************/
void LCD_Init(uchar VDD_1_2)
{
	P0VO = VDD_1_2;   //打开LCD电压输出功能，输出电压为1/2VDD
//	OTCON |= 0x00;     //关闭内部分压电阻
//	OTCON |= 0x04;     //设定内部分压电阻为25K
//	OTCON |= 0x08;     //设定内部分压电阻为50K
	OTCON |= 0x0C;     //设定内部分压电阻为100K
}

void Delay(uint time)
{
    uint i = 0;
    for(i=0; i<100; i++)
    for(; time>0; time--)
    ;
}