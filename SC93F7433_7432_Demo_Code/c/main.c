#include "H/Function_Init.H"

/*************************************************************
说明：
1、Options for Target‘Target1’：BL51 Locate->Code Range:0x100，烧录选项请选择DISRST，复位脚作为普通IO使用；
2、改变Test的定义，可以分别测试对应的功能?
3、注意：先在Function.H里面选择测试型号
***************************************************************/

#define  Test	    9     // (0:BTM  1:EX  2:LCD 3:Timer  4:PWM  5:Uart0  6:SSI  7:ADC  8:ADC_TS  9:IAP)

void main(void)
{
	IO_Init();
	WDTCON |= 0x10;		    //清看门狗
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
			case 6:  SSI_Test();
			break;
			case 7:  ADC_Test();
			break;
			case 8:  ADC_TS_Test();    //测量温度传感器电压
			break;
			case 9:  IAP_Test(0x1fff,IapROM);   //操作ROM，对地址0x1fff进行读写测试
//		             IAP_Test(0x7f,IapEPPROM);   //操作EPPROM，对地址0x7f进行读写测试
			break;
			default: 
			break;
		}
	}
}