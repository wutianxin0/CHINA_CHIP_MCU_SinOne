#include "H/Function_Init.H"

void Multiplier_Divider_Test(void);
/*************************************************************
˵����
1��Options for Target��Target1����BL51 Locate->Code Range:0x100����¼ѡ����ѡ��DISRST����λ����Ϊ��ͨIOʹ�ã�
2���ı�TEST�Ķ��壬���Էֱ���Զ�Ӧ�Ĺ��ܣ�
3��ע�⣺����Function.H����ѡ������ͺ�
***************************************************************/
#define Test  9   //BTM:0 EXTI:1 Timer:2 LCD:3 PWM:4 Uart0:5 SSI:6 ADC:7 IAP:8 Multiplier_Divider:9


void main(void)
{
	IO_Init();
	WDTCON |= 0x10;		    //�忴�Ź�
	OPERCON = 0X01;         //CHKSUM����
	_nop_();
    _nop_();
    _nop_();
    _nop_();
    _nop_();
    _nop_();
    _nop_();
    _nop_();
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
		case 6: SSI_Test();
		break;
		case 7: ADC_Test();
		break;
		case 8: 
//			      IAP_Test(0x1FFF,IapROM);   //����ROM���Ե�ַ0x1FFF���ж�д����
		        IAP_Test(0x7F,IapEPPROM);   //����ROM���Ե�ַ0x7F���ж�д����
		break;
		case 9: Multiplier_Divider_Test();
		break;
		default:
		break;
	}
}

void Multiplier_Divider_Test(void)   //�˳���
{
	while(1)
	{
		OPERCON &= ~0x40;
		//�˳�����
		Multiplication(0x55AA, 0xAA55);  //�˷�����
		if(product == 0x38ff5572)        //�жϻ�
		{
			P20 = 0;
		}
		
		Division(0xFFAA5500,0xAA55);     //��������
		if(quotient == 0x18040&&remainder == 0x3FC0)  //�ж��̺�����
		{
			P20 = 1;
		}
	}		
}	
