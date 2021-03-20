#include "H/Function_Init.H"

void LCD_Init(uchar VDD_1_2);
void Delay(uint time);
enum COM{COM0=1,COM1=2,COM2=4,COM3=8,COM4=16};
/*****************************************************
*�������ƣ�void LCD_Test(void)
*�������ܣ�LCD����
*��ڲ�����void
*���ڲ�����void
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
*�������ƣ�void LCD_Init(uchar VDD_1_2)
*�������ܣ�LCD��ʼ��
*��ڲ�����VDD_1_2
*���ڲ�����void
*****************************************************/
void LCD_Init(uchar VDD_1_2)
{
	P0VO = VDD_1_2;   //��LCD��ѹ������ܣ������ѹΪ1/2VDD
//	OTCON |= 0x00;     //�ر��ڲ���ѹ����
//	OTCON |= 0x04;     //�趨�ڲ���ѹ����Ϊ25K
//	OTCON |= 0x08;     //�趨�ڲ���ѹ����Ϊ50K
	OTCON |= 0x0C;     //�趨�ڲ���ѹ����Ϊ100K
}

void Delay(uint time)
{
    uint i = 0;
    for(i=0; i<100; i++)
    for(; time>0; time--)
    ;
}