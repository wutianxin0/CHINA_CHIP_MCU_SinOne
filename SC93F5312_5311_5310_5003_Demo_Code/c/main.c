#include "H/Function_Init.H"

/*************************************************************
˵����
1��Options for Target��Target1����BL51 Locate->Code Range:0x100����¼ѡ����ѡ��DISRST����λ����Ϊ��ͨIOʹ�ã�
2���ı�Test�Ķ��壬���Էֱ���Զ�Ӧ�Ĺ��ܣ
3��ע�⣺����Function.H����ѡ������ͺ�
***************************************************************/

#define  Test	    8     // (0:BTM  1:EX  2:LCD 3:Timer  4:PWM  5:Uart0  6:SPI  7:ADC  8:IAP)

void main(void)
{
	IO_Init();
	WDTCON |= 0x10;		    //�忴�Ź�
	while(1)
	{			
		switch(Test)
		{
			case 0:  BTM_Test();
			break;
			case 1:  EX_Test();
			break;
			case 2:  LCD_Test();
			break;
			case 3:  Timer_Test();
			break;
			case 4:  PWM_Test();
			break;
			case 5:  Uart0_Test();
			break;
            case 6:  SPI_Test();
			break;
			case 7:  ADC_Test();
			break;
			case 8:  IAP_Test(0x1fff,IapROM);   //����ROM���Ե�ַ0x1fff���ж�д����
//		             IAP_Test(0x7f,IapEPPROM);   //����EPPROM���Ե�ַ0x7f���ж�д����
			break;
			default: 
			break;
		}
	}
}