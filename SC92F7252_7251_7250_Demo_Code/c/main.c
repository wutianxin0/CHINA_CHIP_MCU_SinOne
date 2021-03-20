#include "H/Function_Init.H"

/**************************************************************
˵����
1��Options for Target��Target1����BL51 Locate->Code Range:0x100����¼ѡ����ѡ��DISRST����λ����Ϊ��ͨIOʹ�ã�
2���ı�TEST�Ķ��壬���Էֱ���Զ�Ӧ�Ĺ��ܣ�
3��ע�⣺����Function.H����ѡ������ͺţ�SC92F7320��LCD/LED��PWM���ܣ�
***************************************************************/
#define Test  0    //BTM:0 EXTI:1 Timer:2 LCD:3 PWM:4 Uart0:5 ADC:7 IAP:8 

void main(void)
{
	IO_Init();
	WDTCON |= 0x10;		    //�忴�Ź�
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
		case 8: IAP_Test(0xfff,IapROM);   //����ROM���Ե�ַ0xfff���ж�д����
//		        IAP_Test(0x7f,IapEPPROM);   //����EPPROM���Ե�ַ0x7f���ж�д����
		break;
		default:
		break;
	}
}