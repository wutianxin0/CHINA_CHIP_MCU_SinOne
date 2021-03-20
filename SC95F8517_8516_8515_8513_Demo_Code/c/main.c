#include "H/Function_Init.H"

void Multiplier_Divider_Test(void);  
/**************************************************************
说明：
1、Options for Target‘Target1’：BL51 Locate->Code Range:0x100，烧录选项请选择DISRST，复位脚作为普通IO使用；
2、改变TEST的定义，可以分别测试对应的功能；
3、注意：先在Function.H里面选择测试型号
4、版本：V3.0
***************************************************************/
#define Test  2    //BTM:0 EXTI:1 Timer:2 LCD_LED:3 PWM:4 Uart0:5 SSI0:6 SSI1:7 SSI2:8 ADC:9 IAP:10 Multiplier_Divider:11 CMP:12 CRC:13

void main(void)
{
	IO_Init();
//	WDTCON |= 0x10;		    //清看门狗
	switch(Test)
	{
		case 0: BTM_Test();
		break;
		case 1: EXTI_Test();
		break;
		case 2: Timer_Test();
		break;
		case 3: LCD_LED_Test();
		break;
		case 4: PWM_Test();
		break;
		case 5: Uart_Test();
		break;
		case 6: SSI0_Test();
		break;
        case 7: SSI1_Test();
		break;
        case 8: SSI2_Test();
		break;
		case 9: ADC_Test();
		break;
		case 10: IAP_Test(0x1FFF);   //对地址0x1fff进行读写测试
		break;
		case 11: Multiplier_Divider_Test();
		break;
		case 12: CMP_Test();
		break;
        case 13: CRC_Test();
		break;
		default:
		break;
	}
}

void Multiplier_Divider_Test(void)
{
	while(1)
	{		
		//乘除法器
		Multiplication(0x55AA, 0xAA55);  //乘法计算
		if(product == 0x38ff5572)   //判断积
		{
			P04 = 0;
		}
		
		Division(0xFFAA5500,0xAA55);    //除法计算
		if(quotient == 0x18040 && remainder == 0x3FC0)  //判断商和余数
		{
			P04 = 1;
		}
	}		
}	
