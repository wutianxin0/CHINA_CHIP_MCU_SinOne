#include "H/Function_Init.H"

void Multiplier_Divider_Test(void);
/*************************************************************
说明：
1、Options for Target‘Target1’：BL51 Locate->Code Range:0x100，烧录选项请选择DISRST，复位脚作为普通IO使用；
2、改变TEST的定义，可以分别测试对应的功能；
3、注意：先在Function.H里面选择测试型号
***************************************************************/
#define Test  9   //BTM:0 EXTI:1 Timer:2 LCD:3 PWM:4 Uart0:5 SSI:6 ADC:7 IAP:8 Multiplier_Divider:9


void main(void)
{
	IO_Init();
	WDTCON |= 0x10;		    //清看门狗
	OPERCON = 0X01;         //CHKSUM运算
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
//			      IAP_Test(0x1FFF,IapROM);   //操作ROM，对地址0x1FFF进行读写测试
		        IAP_Test(0x7F,IapEPPROM);   //操作ROM，对地址0x7F进行读写测试
		break;
		case 9: Multiplier_Divider_Test();
		break;
		default:
		break;
	}
}

void Multiplier_Divider_Test(void)   //乘除器
{
	while(1)
	{
		OPERCON &= ~0x40;
		//乘除法器
		Multiplication(0x55AA, 0xAA55);  //乘法计算
		if(product == 0x38ff5572)        //判断积
		{
			P20 = 0;
		}
		
		Division(0xFFAA5500,0xAA55);     //除法计算
		if(quotient == 0x18040&&remainder == 0x3FC0)  //判断商和余数
		{
			P20 = 1;
		}
	}		
}	
