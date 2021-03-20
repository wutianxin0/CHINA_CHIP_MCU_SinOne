#include "H/Function_Init.H"

void Multiplier_Divider_Test(void);  
/**************************************************************
˵����
1��Options for Target��Target1����BL51 Locate->Code Range:0x100����¼ѡ����ѡ��DISRST����λ����Ϊ��ͨIOʹ�ã�
2���ı�TEST�Ķ��壬���Էֱ���Զ�Ӧ�Ĺ��ܣ�
3��ע�⣺����Function.H����ѡ������ͺ�
4���汾��V1.0
***************************************************************/
#define Test  12    //BTM:0 EXTI:1 Timer:2 PWM:3 Uart0:4 SSI0:5 SSI1:6 SSI2:7 ADC:8 IAP:9 Multiplier_Divider:10 CRC:11 SmartCard:12

void main(void)
{
	IO_Init();
//	WDTCON |= 0x10;		    //�忴�Ź�
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
		case 4: Uart_Test();
		break;
		case 5: SSI0_Test();
		break;
        case 6: SSI1_Test();
		break;
        case 7: SSI2_Test();
		break;
		case 8: ADC_Test();
		break;
		case 9: IAP_Test(0x1FFF);   //�Ե�ַ0x1fff���ж�д����
		break;
		case 10: Multiplier_Divider_Test();
		break;
        case 11: CRC_Test();
		break;
        case 12: SmartCard_Test();
		break;
		default:
		break;
	}
}

void Multiplier_Divider_Test(void)
{
	while(1)
	{		
		//�˳�����
		Multiplication(0x55AA, 0xAA55);  //�˷�����
		if(product == 0x38ff5572)   //�жϻ�
		{
			P04 = 0;
		}
		
		Division(0xFFAA5500,0xAA55);    //��������
		if(quotient == 0x18040 && remainder == 0x3FC0)  //�ж��̺�����
		{
			P04 = 1;
		}
	}		
}	
