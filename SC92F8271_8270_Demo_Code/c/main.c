#include "H/Function_Init.H"

/**************************************************************
说明：
1、Options for Target‘Target1’：BL51 Locate->Code Range:0x100，烧录选项请选择DISRST，复位脚作为普通IO使用；
2、改变TEST的定义，可以分别测试对应的功能；
3、注意：先在Function.H里面选择测试型号（SC92F8541无LCD/LED、PWM功能和模拟比较器）
***************************************************************/
#define Test  8    //BTM:0 EXTI:1 Timer:2 PWM:3 SSI:4 ADC:5 IAP:6 

void main(void)
{
	IO_Init();
	WDTCON |= 0x10;		    //清看门狗
	OPERCON = 0X01;       //CHKSUM运算
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
		case 5: IAP_Test(0xfff,IapROM);   //操作ROM，对地址0xfff进行读写测试
//		        IAP_Test(0x7f,IapEPPROM);   //操作EPPROM，对地址0x7f进行读写测试
		break;
		default:
		break;
	}
}	
