#include "H/Function_Init.H"

unsigned char xdata LCDRAM[28]  _at_  0x1000;
void LCD_Init(void);
void LED_Init(void);
void PxVO_Init(void);
	
/*****************************************************
*�������ƣ�void LCD_Test(void)
*�������ܣ�LCD/LED����
*��ڲ�����void
*���ڲ�����void
*****************************************************/
void LCD_LED_Test(void)
{
	LCD_Init();
//	LED_Init();
	while(1)
	{
	}
}
/*****************************************************
*�������ƣ�void LCD_Init(void)
*�������ܣ�LCD��ʼ��
*��ڲ�����void
*���ڲ�����void
*****************************************************/
void LCD_Init(void)
{
	unsigned int i;
	DDRCON = 0x8F;    //-xyy zzzz  x:LCD/LEDģʽ y:ռ�ձ�  z:LCD��ѹ����
	PxVO_Init();
	OTCON |= 0x04;    //---- xxyz  x:LCD��ѹ���� y:��λ�ܽ�ѡ�� z:LCDƫ�õ�ѹ
	for(i=0; i<8; i++)
	{
		LCDRAM[i] = 0xff;
	}
}

/*****************************************************
*�������ƣ�void LED_Init(void)
*�������ܣ�LED��ʼ��
*��ڲ�����void
*���ڲ�����void
*****************************************************/
void LED_Init(void)
{
	unsigned int i;
	DDRCON = 0xC0;    //-xyy zzzz  x:LCD/LEDģʽ y:ռ�ձ�1/8:00 1/6:01 1/5:10 1/4:11  z:LCD��ѹ����
	PxVO_Init();
	OTCON |= 0x00;    //---- xxyz  x:LCD��ѹ���� y:��λ�ܽ�ѡ�� z:LCDƫ�õ�ѹ
	for(i=0; i<8; i++)
	{
		LCDRAM[i] = 0xff;
	}
}

/*****************************************************
*�������ƣ�void PxVO_Init(void)
*�������ܣ���ʾ��������ڳ�ʼ��
*��ڲ�����void
*���ڲ�����void
*****************************************************/
void PxVO_Init(void)
{
	P0VO = 0xFF;
	P1VO = 0xFF;
	P2VO = 0xFF;
	P3VO = 0xFF;
}