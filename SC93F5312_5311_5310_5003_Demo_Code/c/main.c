#include "H/Function_Init.H"

/*************************************************************
ËµÃ÷£º
1¡¢Options for Target¡®Target1¡¯£ºBL51 Locate->Code Range:0x100£¬ÉÕÂ¼Ñ¡ÏîÇëÑ¡ÔñDISRST£¬¸´Î»½Å×÷ÎªÆÕÍ¨IOÊ¹ÓÃ£»
2¡¢¸Ä±äTestµÄ¶¨Òå£¬¿ÉÒÔ·Ö±ğ²âÊÔ¶ÔÓ¦µÄ¹¦ÄÜ£
3¡¢×¢Òâ£ºÏÈÔÚFunction.HÀïÃæÑ¡Ôñ²âÊÔĞÍºÅ
***************************************************************/

#define  Test	    8     // (0:BTM  1:EX  2:LCD 3:Timer  4:PWM  5:Uart0  6:SPI  7:ADC  8:IAP)

void main(void)
{
	IO_Init();
	WDTCON |= 0x10;		    //Çå¿´ÃÅ¹·
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
			case 8:  IAP_Test(0x1fff,IapROM);   //²Ù×÷ROM£¬¶ÔµØÖ·0x1fff½øĞĞ¶ÁĞ´²âÊÔ
//		             IAP_Test(0x7f,IapEPPROM);   //²Ù×÷EPPROM£¬¶ÔµØÖ·0x7f½øĞĞ¶ÁĞ´²âÊÔ
			break;
			default: 
			break;
		}
	}
}