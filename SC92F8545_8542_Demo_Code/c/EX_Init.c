#include "H/Function_Init.H"

void EX_Init(void);
uchar INT1_flag = 0x00;
/*****************************************************
*º¯ÊýÃû³Æ£ºvoid EXTI_Test(void)
*º¯Êý¹¦ÄÜ£ºÍâ²¿ÖÐ¶Ï²âÊÔ
*Èë¿Ú²ÎÊý£ºvoid
*³ö¿Ú²ÎÊý£ºvoid
*****************************************************/
void EXTI_Test(void)
{
	EX_Init();
	while(1)
	{					
	}
}
/*****************************************************
*º¯ÊýÃû³Æ£ºvoid EX_Init(void)
*º¯Êý¹¦ÄÜ£ºÍâ²¿ÖÐ¶Ï³õÊ¼»¯
*Èë¿Ú²ÎÊý£ºvoid
*³ö¿Ú²ÎÊý£ºvoid
*****************************************************/
void EX_Init(void)
{	
	//ÅäÖÃÖÐ¶Ï¿ÚINT07¡¢INT10/11¡¢INT20/21
	P0CON &= 0X7F;     //ÖÐ¶ÏIO¿ÚÉèÖÃÎª¸ß×èÊäÈë
	P0PH  |= 0x80;     //ÖÐ¶ÏIO¿ÚÉèÖÃÎª¸ß×è´øÉÏÀ­
	P2CON &= 0XFC;     //ÖÐ¶ÏIO¿ÚÉèÖÃÎª¸ß×èÊäÈë
	P2PH  |= 0x03;     //ÖÐ¶ÏIO¿ÚÉèÖÃÎª¸ß×è´øÉÏÀ
	P4CON &= 0XFC;     //ÖÐ¶ÏIO¿ÚÉèÖÃÎª¸ß×èÊäÈë
	P4PH  |= 0x03;     //ÖÐ¶ÏIO¿ÚÉèÖÃÎª¸ß×è´øÉÏÀ­­
 
	//ÅäÖÃINT07ÉÏÉýÑØÖÐ¶Ï¡¢INT14/15ÏÂ½µÑØÖÐ¶Ï¡¢INT20/21Ë«ÑØÖÐ¶Ï
    //ÏÂ½µÑØÉèÖÃ	
	INT0F = 0X00 ;    //xxxx 0000  0¹Ø±Õ 1Ê¹ÄÜ
	INT1F = 0X03 ;    //xxxx xxxx  0¹Ø±Õ 1Ê¹ÄÜ
    INT2F = 0X03 ;    //0000 xxxx  0¹Ø±Õ 1Ê¹ÄÜ
    //ÉÏÉýÑØÉèÖÃ	
	INT0R = 0X80 ;    //xxxx 0000  0¹Ø±Õ 1Ê¹ÄÜ 
	INT1R = 0X00 ;    //xxxx xxxx  0¹Ø±Õ 1Ê¹ÄÜ
	INT2R = 0X03 ;    //0000 xxxx  0¹Ø±Õ 1Ê¹ÄÜ	
	
	//Íâ²¿ÖÐ¶ÏÓÅÏÈ¼¶ÉèÖÃ
	IE  |= 0x05;	//0000 0x0x
	IE1 |= 0x08;	//0000 x000  INT2Ê¹ÄÜ
	IP  |= 0X00;
	IP1 |= 0X00;
	EA = 1;
}

/*****************************************************
*º¯ÊýÃû³Æ£ºvoid EX0/1/2() interrupt	0/2/10
*º¯Êý¹¦ÄÜ£ºÍâ²¿ÖÐ¶Ïº¯Êý
*Èë¿Ú²ÎÊý£ºvoid
*³ö¿Ú²ÎÊý£ºvoid
*****************************************************/
void EX0() interrupt	0
{
    P02 = ~P02;
}

void EX1() interrupt	2
{
    P03 = ~P03;
	if(P14 == 0)
	{
	 INT1_flag = 0x10; //INT14²úÉúÖÐ¶Ï
	}
	if(P15 == 0)
	{
	 INT1_flag = 0x20; //INT15²úÉúÖÐ¶Ï
	}
}

void EX2() interrupt	10
{
    P06 = ~P06;
}
