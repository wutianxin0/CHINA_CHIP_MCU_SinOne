#include "H/Function_Init.H"

/**************************************************************
˵����
1��Options for Target��Target1����BL51 Locate->Code Range:0x100����¼ѡ����ѡ��DISRST����λ����Ϊ��ͨIOʹ�ã�
2���ı�TEST�Ķ��壬���Էֱ���Զ�Ӧ�Ĺ��ܣ�
3��ע�⣺����Function.H����ѡ������ͺţ�SC92F8541��LCD/LED��PWM���ܺ�ģ��Ƚ�����
***************************************************************/
#define Test  8    //BTM:0 EXTI:1 Timer:2 PWM:3 SSI:4 ADC:5 IAP:6 

void main(void)
{
	IO_Init();
	WDTCON |= 0x10;		    //�忴�Ź�
	OPERCON = 0X01;       //CHKSUM����
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
		case 3: PWM_Test();
		break;
		case 4: SSI_Test();
		break;
		case 5: IAP_Test(0xfff,IapROM);   //����ROM���Ե�ַ0xfff���ж�д����
//		        IAP_Test(0x7f,IapEPPROM);   //����EPPROM���Ե�ַ0x7f���ж�д����
		break;
		default:
		break;
	}
}	
