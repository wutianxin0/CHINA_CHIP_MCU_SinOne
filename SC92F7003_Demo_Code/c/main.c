#include "H/Function_Init.H"

/*************************************************************
˵����
1��Options for Target��Target1����BL51 Locate->Code Range:0x100����¼ѡ����ѡ��DISRST����λ����Ϊ��ͨIOʹ�ã�
2���ı�TEST�Ķ��壬���Էֱ���Զ�Ӧ�Ĺ��ܣ�
***************************************************************/
#define Test  5    //BTM:0   EXTI:1   Timer:2   PWM:3   Uart0:4   SSI:5   ADC:6   IAP:7

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
		case 3: PWM_Test();
		break;
		case 4: Uart0_Test();
		break;
		case 5: SSI_Test();
		break;
		case 6: ADC_Test();
		break;
		case 7: IAP_Test(0x1fff,IapROM);   //����ROM���Ե�ַ0x1fff���ж�д����
//		        IAP_Test(0x7f,IapEPPROM);   //����EPPROM���Ե�ַ0x7f���ж�д����
		break;
		default:
		break;
	}
}
