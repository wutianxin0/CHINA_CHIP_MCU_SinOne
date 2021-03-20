#include "H/Function_Init.H"

/**************************************************************
˵����
1��Options for Target��Target1����BL51 Locate->Code Range:0x100����¼ѡ����ѡ��DISRST����λ����Ϊ��ͨIOʹ�ã�
2���ı�TEST�Ķ��壬���Էֱ���Զ�Ӧ�Ĺ��ܣ�
***************************************************************/
#define Test  8    //BTM:0 EXTI:1 Timer:2 SSI0:3 SSI1:4 ADC:5 IAP:6 

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
		case 3: SSI0_Test();
		break;
        case 4: SSI1_Test();
		break;
		case 5: ADC_Test();
		break;
		case 6: IAP_Test(0x1fff,IapROM);   //����ROM���Ե�ַ0x1fff���ж�д����
//		        IAP_Test(0x7f,IapEPPROM);   //����EPPROM���Ե�ַ0x7f���ж�д����
		break;
		default:
		break;
	}
}