						 /*--------------------------------------------------------------------------
SC92F7490_C.H

C Header file for SC92F7490 microcontroller.
Copyright (c) 2018 Shenzhen SinOne Chip Electronic CO., Ltd.
All rights reserved.
ÉîÛÚÊÐÈüÔªÎ¢µç×ÓÓÐÏÞ¹«Ë¾
°æ±¾ºÅ:  V1.0    
ÈÕÆÚ:  2018.07.25
--------------------------------------------------------------------------*/
#ifndef _SC92F7490_H_
#define _SC92F7490_H_

/* ------------------- ×Ö½Ú¼Ä´æÆ÷-------------------- */
///*CPU*/
sfr   ACC	  = 0xE0;		  //ÀÛ¼ÓÆ÷£Á
sfr   B	      = 0xF0;		  //Í¨ÓÃ¼Ä´æÆ÷B		
sfr   PSW	  = 0xD0;		  //³ÌÐò×´Ì¬×Ö		
sfr   DPH	  = 0x83;	      //Êý¾ÝÖ¸Õë¸ß8Î»		
sfr   DPL	  = 0x82;		  //Êý¾ÝÖ¸ÕëµÍ8Î»		
sfr   SP	  = 0x81;		  //¶ÑÕ»Ö¸Õë			

/*system*/
sfr   PCON	  = 0x87;	  	  //µçÔ´¹ÜÀí¿ØÖÆ¼Ä´æÆ÷

/*interrupt*/
sfr   IP1     = 0XB9;     //ÖÐ¶ÏÓÅÏÈ¼¶¿ØÖÆ¼Ä´æÆ÷1
sfr   IP      = 0xB8;	  //ÖÐ¶ÏÓÅÏÈÈ¨¿ØÖÆ¼Ä´æÆ÷
sfr   IE      = 0xA8;	  //ÖÐ¶Ï¿ØÖÆ¼Ä´æÆ÷
sfr   IE1     = 0XA9;     //ÖÐ¶Ï¿ØÖÆ¼Ä´æÆ÷1

/*PORT*/

sfr   P2PH    = 0xA2;	  //P2¿ÚÄ£Ê½¿ØÖÆ¼Ä´æÆ÷0		
sfr	  P2CON   = 0xA1;	  //P2¿ÚÄ£Ê½¿ØÖÆ¼Ä´æÆ÷1		
sfr   P2	  = 0xA0;	  //P2¿ÚÊý¾Ý¼Ä´æÆ÷
sfr   P1PH    = 0x92;	  //P1¿ÚÄ£Ê½¿ØÖÆ¼Ä´æÆ÷0		
sfr	  P1CON   = 0x91;	  //P1¿ÚÄ£Ê½¿ØÖÆ¼Ä´æÆ÷1	
sfr   P1	  = 0x90;	  //P1¿ÚÊý¾Ý¼Ä´æÆ÷
sfr	  P0PH    = 0x9B;	  //P0¿ÚÄ£Ê½¿ØÖÆ¼Ä´æÆ÷1		
sfr	  P0CON   = 0x9A;	  //P0¿ÚÄ£Ê½¿ØÖÆ¼Ä´æÆ÷1		
sfr   P0	  = 0x80;	  //P0¿ÚÊý¾Ý¼Ä´æÆ÷
sfr   IOHCON  = 0x97;	  //IOHÉèÖÃ¼Ä´æÆ÷

/*TIMER*/
sfr   TMCON   = 0x8E;	  //¶¨Ê±Æ÷ÆµÂÊ¿ØÖÆ¼Ä´æÆ÷
sfr   TH1	  = 0x8D;	  //¶¨Ê±Æ÷1¸ß8Î»
sfr   TH0	  = 0x8C;	  //¶¨Ê±Æ÷0¸ß8Î»
sfr   TL1	  = 0x8B;	  //¶¨Ê±Æ÷1µÍ8Î»
sfr   TL0	  = 0x8A;	  //¶¨Ê±Æ÷0µÍ8Î»
sfr   TMOD    = 0x89;	  //¶¨Ê±Æ÷¹¤×÷Ä£Ê½¼Ä´æÆ÷
sfr   TCON    = 0x88;     //¶¨Ê±Æ÷¿ØÖÆ¼Ä´æÆ÷
sfr   T2CON   = 0XC8;     //¶¨Ê±Æ÷2¿ØÖÆ¼Ä´æÆ÷
sfr   T2MOD   = 0XC9; 	  //¶¨Ê±Æ÷2¹¤×÷Ä£Ê½¼Ä´æÆ÷
sfr   RCAP2L  = 0XCA;     //¶¨Ê±Æ÷2ÖØÔØ/²¶×½µÍ8Î»
sfr   RCAP2H  = 0XCB;     //¶¨Ê±Æ÷2ÖØÔØ/²¶×½¸ß8Î»
sfr   TL2     = 0XCC;     //¶¨Ê±Æ÷2µÍ8Î»
sfr   TH2     = 0XCD;     //¶¨Ê±Æ÷2¸ß8Î»


/*ADC*/
sfr	  ADCCFG0 = 0xAB;	  //ADCÉèÖÃ¼Ä´æÆ÷0
sfr	  ADCCFG1 = 0xAC;	  //ADCÉèÖÃ¼Ä´æÆ÷1
sfr   ADCCON  = 0XAD;     //ADC¿ØÖÆ¼Ä´æÆ÷
sfr   ADCVL	  = 0xAE;	  //ADC ½á¹û¼Ä´æÆ÷
sfr   ADCVH	  = 0xAF;	  //ADC ½á¹û¼Ä´æÆ÷

///*WatchDog*/
sfr	  BTMCON  = 0XCE;     //µÍÆµ¶¨Ê±Æ÷¿ØÖÆ¼Ä´æÆ÷
sfr   WDTCON  = 0xCF;	  //WDT¿ØÖÆ¼Ä´æÆ÷

/*LCD*/
sfr   OTCON   = 0X8F;	  //LCDµçÑ¹Êä³ö¿ØÖÆ¼Ä´æÆ÷
sfr   P0VO    = 0X9C;     //P0 LCD Bais Êä³ö¼Ä´æÆ÷

/*INT*/
sfr   INT0F   = 0XBA; 	  //INT0 ÏÂ½µÑØÖÐ¶Ï¿ØÖÆ¼Ä´æÆ÷
sfr   INT0R   = 0XBB; 	  //INT0 ÉÏ½µÑØÖÐ¶Ï¿ØÖÆ¼Ä´æÆ÷÷
sfr   INT2F   = 0XC6; 	  //INT2 ÏÂ½µÑØÖÐ¶Ï¿ØÖÆ¼Ä´æÆ÷
sfr   INT2R   = 0XC7; 	  //INT2 ÉÏ½µÑØÖÐ¶Ï¿ØÖÆ¼Ä´æÆ÷

/*IAP */
sfr	  IAPCTL  = 0xF6;	  //IAP¿ØÖÆ¼Ä´æÆ÷
sfr	  IAPDAT  = 0xF5;	  //IAPÊý¾Ý¼Ä´æÆ÷
sfr   IAPADE  = 0xF4;     //IAPÀ©Õ¹µØÖ·¼Ä´æÆ÷
sfr	  IAPADH  = 0xF3;	  //IAPÐ´ÈëµØÖ·¸ßÎ»¼Ä´æÆ÷
sfr	  IAPADL  = 0xF2;	  //IAPÐ´ÈëµØÖ·µÍ8Î»¼Ä´æÆ÷
sfr	  IAPKEY  = 0xF1;	  //IAP±£»¤¼Ä´æÆ÷

/*SSI*/
sfr   SS0CON0 = 0XA5;  	  //SSI0¿ØÖÆ¼Ä´æÆ÷2
sfr   SS0CON1 = 0XA6;  	  //SSI0¿ØÖÆ¼Ä´æÆ÷1
sfr   SS0CON2 = 0XA4;  	  //SSI0¿ØÖÆ¼Ä´æÆ÷0
sfr   SS0DAT  = 0XA7;  	  //SSI0Êý¾Ý¼Ä´æÆ÷

sfr   SS1CON2 = 0X95;  	  //SSI1¿ØÖÆ¼Ä´æÆ÷2
sfr   SS1CON0 = 0X9D;  	  //SSI1¿ØÖÆ¼Ä´æÆ÷0
sfr   SS1CON1 = 0X9E;  	  //SSI1¿ØÖÆ¼Ä´æÆ÷1
sfr   SS1DAT  = 0X9F;  	  //SSI1Êý¾Ý¼Ä´æÆ÷

/*CHKSUM*/
sfr   OPERCON = 0xEF;     //ÔËËã¿ØÖÆ¼Ä´æÆ÷
sfr   CHKSUML = 0xFC;     //CHKSUM½á¹û¼Ä´æÆ÷µÍÎ»
sfr   CHKSUMH = 0XFD;     //CHKSUM½á¹û¼Ä´æÆ÷¸ßÎ»

/*option*/
sfr   OPINX   = 0XFE;     //OptionÖ¸Õë
sfr   OPREG   = 0XFF;     //Option¼Ä´æÆ÷

sfr   P5PH    = 0xDA;	 	
sfr	  P5CON   = 0xD9;	  	
sfr   P5	  = 0xD8;	  
///* ------------------- Î»¼Ä´æÆ÷-------------------- */

/*PSW*/
sbit  CY	  = PSW^7;	  //±êÖ¾Î»		0:¼Ó·¨ÔËËã×î¸ßÎ»ÎÞ½øÎ»£¬»òÕß¼õ·¨ÔËËã×î¸ßÎ»ÎÞ½èÎ»Ê±		1:¼Ó·¨ÔËËã×î¸ßÎ»ÓÐ½øÎ»£¬»òÕß¼õ·¨ÔËËã×î¸ßÎ»ÓÐ½èÎ»Ê±
sbit  AC	  = PSW^6;	  //½øÎ»¸¨Öú±êÖ¾Î»	0:ÎÞ½èÎ»¡¢½øÎ»		1:¼Ó·¨ÔËËãÊ±ÔÚbit3Î»ÓÐ½øÎ»£¬»ò¼õ·¨ÔËËãÔÚbit3Î»ÓÐ½èÎ»Ê±
sbit  F0	  = PSW^5;	  //ÓÃ»§±êÖ¾Î»
sbit  RS1	  = PSW^4;	  //¹¤×÷¼Ä´æÆ÷×éÑ¡ÔñÎ»
sbit  RS0	  = PSW^3;	  //¹¤×÷¼Ä´æÆ÷×éÑ¡ÔñÎ»
sbit  OV	  = PSW^2;	  //Òç³ö±êÖ¾Î»
sbit  F1	  = PSW^1;	  //F1±êÖ¾
sbit  P	      = PSW^0;	  //ÆæÅ¼±êÖ¾Î»	0:ACCÖÐ1µÄ¸öÊýÎªÅ¼Êý£¨°üÀ¨0¸ö£©		1:ACCÖÐ1µÄ¸öÊýÎªÆæÊý

/*T2CON*/
sbit  TF2	  = T2CON^7;
sbit  EXF2	  = T2CON^6;
sbit  RCLK	  = T2CON^5;
sbit  TCLK	  = T2CON^4;
sbit  EXEN2   = T2CON^3;
sbit  TR2	  = T2CON^2;
sbit  T2      = T2CON^1;
sbit  CP	  = T2CON^0;


/*IP*/
sbit  IPADC	  = IP^6;	  //ADCÖÐ¶ÏÓÅÏÈ¿ØÖÆÎ»      0:Éè¶¨ ADCµÄÖÐ¶ÏÓÅÏÈÈ¨ÊÇ ¡°µÍ¡±		1:Éè¶¨ ADCµÄÖÐ¶ÏÓÅÏÈÈ¨ÊÇ ¡°¸ß¡±
sbit  IPT2	  = IP^5;	  //Timer2ÖÐ¶ÏÓÅÏÈ¿ØÖÆÎ»   0:Éè¶¨ Timer2µÄÖÐ¶ÏÓÅÏÈÈ¨ÊÇ ¡°µÍ¡±		1:Éè¶¨Timer2µÄÖÐ¶ÏÓÅÏÈÈ¨ÊÇ ¡°¸ß¡±
sbit  IPSSI0  = IP^4;	  //SSI0ÖÐ¶ÏÓÅÏÈ¿ØÖÆÎ»	   0:Éè¶¨SSI0µÄÖÐ¶ÏÓÅÏÈÈ¨ÊÇ ¡°µÍ¡±		1:Éè¶¨SSI0µÄÖÐ¶ÏÓÅÏÈÈ¨ÊÇ ¡°¸ß¡±
sbit  IPT1	  = IP^3;	  //Timer1ÖÐ¶ÏÓÅÏÈ¿ØÖÆÎ»   0:Éè¶¨ Timer 1µÄÖÐ¶ÏÓÅÏÈÈ¨ÊÇ ¡°µÍ¡±	1:Éè¶¨ Timer 1µÄÖÐ¶ÏÓÅÏÈÈ¨ÊÇ ¡°¸ß¡±
sbit  IPT0	  = IP^1;	  //Timer0ÖÐ¶ÏÓÅÏÈ¿ØÖÆÎ»   0:Éè¶¨ Timer 0µÄÖÐ¶ÏÓÅÏÈÈ¨ÊÇ ¡°µÍ¡±	1:Éè¶¨ Timer 0µÄÖÐ¶ÏÓÅÏÈÈ¨ÊÇ ¡°¸ß¡±
sbit  IPINT0  = IP^0;     //INT0ÖÐ¶ÏÓÅÏÈ¿ØÖÆÎ»	   0:Éè¶¨INT0ÖÐ¶ÏÓÅÏÈÈ¨ÊÇ ¡°µÍ¡±		    1:Éè¶¨INT0µÄÖÐ¶ÏÓÅÏÈÈ¨ÊÇ ¡°¸ß¡±

/*IE*/
sbit  EA	  = IE^7;	  //ÖÐ¶ÏÊ¹ÄÜµÄ×Ü¿ØÖÆ	0:¹Ø±ÕËùÓÐµÄÖÐ¶Ï	1:´ò¿ªËùÓÐµÄÖÐ¶Ï
sbit  EADC    = IE^6;	  //ADCÖÐ¶ÏÊ¹ÄÜ¿ØÖÆ	    0:¹Ø±ÕADCÖÐ¶Ï		1:´ò¿ªADCÖÐ¶Ï
sbit  ET2     = IE^5;	  //Timer2ÖÐ¶ÏÊ¹ÄÜ¿ØÖÆ	0:¹Ø±ÕTimer2ÖÐ¶Ï    1:´ò¿ªTimer2ÖÐ¶Ï
sbit  ESSI0   = IE^4;	  //SSI0ÖÐ¶ÏÊ¹ÄÜ¿ØÖÆ	0:¹Ø±ÕSSI0ÖÐ¶Ï		1:´ò¿ªSSI0ÖÐ¶Ï
sbit  ET1     = IE^3;	  //Timer1ÖÐ¶ÏÊ¹ÄÜ¿ØÖÆ	0:¹Ø±ÕTIMER1ÖÐ¶Ï	1:´ò¿ªTIMER1ÖÐ¶Ï
sbit  ET0	  = IE^1;	  //Timer0ÖÐ¶ÏÊ¹ÄÜ¿ØÖÆ	0:¹Ø±ÕTIMER0ÖÐ¶Ï	1:´ò¿ªTIMER0ÖÐ¶Ï
sbit  EINT0   = IE^0;	  //INT0ÖÐ¶ÏÊ¹ÄÜ¿ØÖÆ	0:¹Ø±ÕINT0ÖÐ¶Ï      1:´ò¿ªINT0ÖÐ¶Ï

/*TCON*/
sbit  TF1	  = TCON^7;	  //T1Òç³öÖÐ¶ÏÇëÇó±êÖ¾Î»	T1²úÉúÒç³ö£¬·¢ÉúÖÐ¶ÏÊ±£¬Ó²¼þ½«TF1ÖÃÎª¡°1¡±£¬ÉêÇëÖÐ¶Ï£¬CPUÏìÓ¦Ê±£¬Ó²¼þÇå¡°0¡±¡£
sbit  TR1	  = TCON^6;	  //¶¨Ê±Æ÷T1µÄÔËÐÐ¿ØÖÆÎ»	0:Timer1½ûÖ¹¼ÆÊý		1:Timer1¿ªÊ¼¼ÆÊý
sbit  TF0	  = TCON^5;	  //T0Òç³öÖÐ¶ÏÇëÇó±êÖ¾Î»	T0²úÉúÒç³ö£¬·¢ÉúÖÐ¶ÏÊ±£¬Ó²¼þ½«TF0ÖÃÎª¡°1¡±£¬ÉêÇëÖÐ¶Ï£¬CPUÏìÓ¦Ê±£¬Ó²¼þÇå¡°0¡±¡£
sbit  TR0	  = TCON^4;	  //¶¨Ê±Æ÷T0µÄÔËÐÐ¿ØÖÆÎ»	0:Timer0½ûÖ¹¼ÆÊý		1:Timer0¿ªÊ¼¼ÆÊý

/******************* P0 ******************/
sbit  P05 = P0^5;

/******************* P1 ******************/
sbit  P13 = P1^3;
sbit  P12 = P1^2;
sbit  P11 = P1^1;

/******************* P2 ******************/
sbit  P21 = P2^1;
sbit  P20 = P2^0;

/****************************************************************************
*×¢Òâ£º³õÊ¼»¯IO¿Úºó£¬Ðèµ÷ÓÃÒÔÏÂºê¡£
*****************************************************************************/
#define  SC92F7490_NIO_Init()   {P0CON|=0xDF;P1CON|=0xF1;P2CON|=0xFC;P5CON|=0x03;} 

#endif