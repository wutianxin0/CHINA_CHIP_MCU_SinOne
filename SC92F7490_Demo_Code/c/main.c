#include "H/Function_Init.H"

/**************************************************************
说明：
1、Options for Target‘Target1’：BL51 Locate->Code Range:0x100，烧录选项请选择DISRST，复位脚作为普通IO使用；
2、改变TEST的定义，可以分别测试对应的功能；
***************************************************************/
#define Test  8    //BTM:0 EXTI:1 Timer:2 SSI0:3 SSI1:4 ADC:5 IAP:6 

void main(void)
{
	IO_Init();
	WDTCON |= 0x10;		    //清看门狗
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
		case 6: IAP_Test(0x1fff,IapROM);   //操作ROM，对地址0x1fff进行读写测试
//		        IAP_Test(0x7f,IapEPPROM);   //操作EPPROM，对地址0x7f进行读写测试
		break;
		default:
		break;
	}
}