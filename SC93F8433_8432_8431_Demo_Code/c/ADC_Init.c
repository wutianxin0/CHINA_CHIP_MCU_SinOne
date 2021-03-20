#include "H/Function_Init.H"

void ADC_Init(uint Channel);
void Delay(uint time);
uchar Read_IFB_Data(uchar AddOffset);
uint ADCValue = 0x0000;
uint AD_TS25H = 0x00;
uint AD_TS25L = 0x00;
bit AdcFlag = 0x00;
unsigned char code *POINT=0x0000 ;	//����һ��ָ��

/***********ADC������ѡ��*************/
#if (IC_MODEL == SC93F8433)
	enum Channel {AIN0=0,AIN1,AIN2,AIN3,AIN4,AIN5,AIN6,AIN7,AIN8,AIN9,TS_AIN=14,VDD4};
#endif

#if (IC_MODEL == SC93F8432)
	enum Channel {AIN2=2,AIN3,AIN4,AIN5,AIN8=8,AIN9,TS_AIN=14,VDD4};
#endif
	
#if (IC_MODEL == SC93F8431)
	enum Channel {AIN3=3,AIN4,AIN8=8,AIN9,TS_AIN=14,VDD4};
#endif

/****************************************
*�������ƣ�void ADC_Test(void)
*�������ܣ�ADC����
*��ڲ�����void
*���ڲ�����void
****************************************/
void ADC_Test(void)
{
    ADC_Init(AIN4);
    while(1)
    {
        AD_TS25H = Read_IFB_Data(0x3E);      //��ȡIC��25��ʱ���¶�ֵ����λ��
	    AD_TS25L = Read_IFB_Data(0x3F);      //��ȡIC��25��ʱ���¶�ֵ����λ��
        
        ADCCON |= 0X40;                      //��ʼADCת��
	    while(!(AdcFlag));	         		 //�ȴ� ADCת�����;
        AdcFlag = 0;
        ADCValue = ADCVH;
        ADCValue = (ADCValue<<4)+(ADCVL>>4);      
    }
}

/*****************************************************
*�������ƣ�void ADC_Init(void)
*�������ܣ�ADC��ʼ��
*��ڲ�����Channel
*���ڲ�����void
*****************************************************/
void ADC_Init(uint Channel)
{
	ADCCON = 0X80|Channel;		//����ADC��ADC����Ƶ��Ϊ2M ,ѡ��ChannelλADC������
	if(Channel<8)
	{
		ADCCFG0 = 1<<Channel;   //����Channel��Ϊ������
	}
	else
	{
		ADCCFG1 = 1<<(Channel-8);   //����Channel��Ϊ������
	}
	IE |= 0X40;        //����ADC�ж�
	EA = 1;
}

/*****************************************************
*�������ƣ�void ADC_Interrupt(void) interrupt 6
*�������ܣ�ADC�жϺ���
*��ڲ�����void
*���ڲ�����void
*****************************************************/
void ADC_Interrupt(void) interrupt 6
{
	ADCCON &= ~(0X10);  //���жϱ�־λ
	AdcFlag = 1;
}

/*****************************************************
*�������ƣ�void ADC_TS_Test(void)
*�������ܣ�ADC�ɼ��¶ȴ�������ѹֵ
*��ڲ�����void
*���ڲ�����void
*ע�⣺�����¶�ʱ��ADC�ο���ѹҪ��2.4V
*****************************************************/
void ADC_TS_Test(void)
{
	uint AD_TS0=0,AD_TS1=0,AD_TSSUM=0;
	
	ADCCON = 0x8E;		//����ADC��ADC����Ƶ��Ϊ2M ,ADC����Ϊ�¶ȴ��������
	ADCCFG0 = 0x00;   //
	ADCCFG1 = 0X00;   //
    TSCFG = 0X80;     //ʹ���¶ȴ�����   
	while(1)
	{	
        Delay(5);
        TSCFG &= 0xFE;
		ADCCON |= 0x40;   //��ʼADCת��		
		while(!(ADCCON&0x10));
		ADCCON &= 0xEF;   //���жϱ�־λ
        AD_TS0 = ADCVH;
		AD_TS0 = (AD_TS0<<4)+(ADCVL>>4);  //��һ���¶ȴ�������ֵ
		
		TSCFG |= 0X01;
		ADCCON |= 0x40;   //��ʼADCת��		
		while(!(ADCCON&0x10));
		ADCCON &= 0xEF;   //���жϱ�־λ
        AD_TS1 = ADCVH;
		AD_TS1 = (AD_TS1<<4)+(ADCVL>>4);  //�ڶ����¶ȴ�������ֵ
		
		AD_TSSUM = (AD_TS0+AD_TS1)/2;    //�¶ȴ�������ֵ    
	}
}

/*****************************************************
*�������ƣ�uchar Read_IFB_Data(uchar AddOffset)
*�������ܣ���ȡIC��25���ADC�¶Ȳ���ֵ
*��ڲ�����AddOffset
*���ڲ�����Val
*****************************************************/
uchar Read_IFB_Data(uchar AddOffset)
{
	uchar Val;

	EA = 0;				//�����ж�
	IAPADE = 0x01;		//ѡ��EEPROM������ж�д����
	Val = *(POINT+AddOffset);	
	IAPADE = 0x00;		//����ROM����
	EA = 1;				//�����ж�
	return Val;	
}

void Delay(uint time)
{
    uint i = 0;
    for(i=0; i<10; i++)
    for(; time>0; time--)
    ;
}