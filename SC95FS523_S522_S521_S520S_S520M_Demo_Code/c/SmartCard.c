#include "H\Function_Init.H"

#define SC_CK   P05
#define SC_DAT  P20
#define SC_PWR  P15
#define SC_RST  P16
#define SC_CD   P17

bit TC_Flag = 0;
bit RC_Flag = 0;
bit WTRT_Flag = 0;
bit TBUSY_Flag = 0;
bit RBUSY_Flag = 0;
bit WTER_Flag = 0;
bit FER_Flag = 0;
bit TPER_Flag = 0;
bit RPER_Flag = 0;
bit TOVF_Flag = 0;
bit ROVF_Flag = 0;


unsigned char Receive_ATR_Info[16];//ATR��Ϣ
void SmartCard_Init(void);
void Timer_Delay(unsigned int count);
void SC_Activation_ColdReduction(void);
void SC_WarmReset(void);

/*****************************************************
*�������ƣ�void SmartCard_Test(void)
*�������ܣ����ܿ�����
*��ڲ�����void
*���ڲ�����void
*****************************************************/
void SmartCard_Test(void)
{
	SmartCard_Init();//���ܿ���ʼ��
    SC_Activation_ColdReduction();//�临λ���ȡATR
//    void SC_WarmReset();//ů��λ���ȡATR
	while(1)
	{
	}
}

/*****************************************************
*�������ƣ�void SmartCard_Init(void)
*�������ܣ����ܿ���ʼ��
*��ڲ�����void
*���ڲ�����void
*****************************************************/
void SmartCard_Init(void)
{
    OTCON &= 0xCF;     //ѡ��SCͨ��
    US0CON0 = 0x30;    //��ͨIO
    US0CON0 &= ~0x04;  //������Լ��ѡ��
    US0CON1 = 0x74; 
    US0CON2 |= 0x81;   //����SCCK  372
    US0CON4 = 0x03;    //��չ����ʱ��       
//    IE1 = 0x01;        //�ж�ʹ��
//    EA = 1;            //���ж�ʹ��
}

/*****************************************************
*�������ƣ�void SmartCard_Init(void)
*�������ܣ����ܿ��临λ��Ľ���ATR
*��ڲ�����void
*���ڲ�����void
*****************************************************/
void SC_Activation_ColdReduction(void)
{
    int i = 0;
    US0CON0 &= ~0x40;  //�ر�SC_CLK      
    SC_RST = 0;
    SC_PWR = 1;
    US0CON0 &= 0x7f;  //DAT������ͨIO��
    SC_DAT = 1;
    Timer_Delay(42);
    US0CON0 |= 0x40;  //����SC_CLK
    US0CON0 |= 0x80;  //DAT����ΪDAT��
    Timer_Delay(250);
    SC_RST = 1;
    Timer_Delay(400);
    
    //��������
    US0CON0 &= ~0X20;   //����ʹ��
    for(i=0; i<16; i++) //ATRΪ15byte
    {  
        US0CON5 &= 0x7f;  //�л�����д״̬�Ĵ���        
        while(US0CON5 & 0x04);
        while(!(US0CON5 & 0x20));        
        US0CON5 |= 0X20;   //д1����
        Receive_ATR_Info[i] = US0CON3;
    }
}

/*****************************************************
*�������ƣ�void SC_WarmReset(void)
*�������ܣ����ܿ�ů��λ��Ľ���ATR
*��ڲ�����void
*���ڲ�����void
*****************************************************/
void SC_WarmReset(void)
{
    int i = 0;
    SC_RST = 0;
    Timer_Delay(41);
    SC_DAT = 1;
    Timer_Delay(242);
    SC_RST = 1;
    Timer_Delay(500);
    
    //��������
    US0CON0 &= ~0X20;   //����ʹ��
    for(i=0; i<16; i++)
    {    
        US0CON5 &= 0x7f;  //�л�����д״̬�Ĵ���        
        while(US0CON5 & 0x04);
        while(!(US0CON5 & 0x20));
        US0CON5 |= 0x20;  //д1����
        Receive_ATR_Info[i] = US0CON3;
    }
}

/*****************************************************
*�������ƣ�void SC_Send(unsigned char Data)
*�������ܣ����ܿ���������
*��ڲ�����Data
*���ڲ�����void
*****************************************************/
void SC_Send(unsigned char Data)
{
    US0CON0 &= ~0x20;  //����
    US0CON0 |= 0x20;  //����ʹ��
    P07 = ~P07;P07 = ~P07;P07 = ~P07;   
    US0CON3 = Data;  
    while(US0CON5 & 0x08);   
    while(!TC_Flag);
    TC_Flag = 0;
}

/*****************************************************
*�������ƣ�void SC_Receive(void)
*�������ܣ����ܿ�����������
*��ڲ�����void
*���ڲ�����void
*****************************************************/
unsigned char SC_Receive(void)
{
    unsigned char temp = 0x00;
    US0CON0 &= ~0x20;  //����ʹ�� 
    while(US0CON5 & 0x04);
    while(!RC_Flag);  
    RC_Flag = 0;  
    temp = US0CON3; 
    return temp;
}

/*****************************************************
*�������ƣ�void Timer_Delay(unsigned int count)
*�������ܣ���ʱ����
*��ڲ�����count
*���ڲ�����void
*****************************************************/
void Timer_Delay(unsigned int count)
{
    for(;count>0;count--)
    {
//        while(!TF0);
//        TF0 = 0;
    }
}

/*****************************************************
*�������ƣ�void SC_Interrupt() interrupt 7
*�������ܣ��жϷ�����
*��ڲ�����void
*���ڲ�����void
*****************************************************/
void SC_Interrupt() interrupt 7
{  
    P07 = ~P07;
    US0CON5 = 0x00;    //��д״̬�Ĵ���
    if(US0CON5 & 0x40)  //������ɱ�־λ
    {
        US0CON5 |= 0x40;
        TC_Flag = 1;
    }
    
    if(US0CON5 & 0x20)  //������ɱ�־λ
    {
        US0CON5 |= 0x20;
        RC_Flag = 1;
    }
    
    if(US0CON5 & 0x10)  //�ȴ������ط���־λ
    {
        WTRT_Flag = 1;
    }
    if(US0CON5 & 0x08)  //���ݷ���æ��־λ
    {
        TBUSY_Flag = 1;
    }
    if(US0CON5 & 0x04)  //���ݽ���æ��־λ
    {
        RBUSY_Flag = 1;
    }
    if(US0CON5 & 0x02)  //�ȴ���ʱ��־λ
    {
        US0CON5 |= 0x02;
        WTER_Flag = 1;
    }
    if(US0CON5 & 0x01)  //����֡�����־λ
    {
        US0CON5 |= 0x01;
        FER_Flag = 1;
    }
    
    US0CON5 = 0x80;    //��д������Ϣ�Ĵ���
    if(US0CON5 & 0x08)  //����������ż��������־λ
    {
        US0CON5 |= 0x08;
        TPER_Flag = 1;
    }
    if(US0CON5 & 0x04)  //����������ż��������־λ
    {
        US0CON5 |= 0x04;
        RPER_Flag = 1;
    }
    if(US0CON5 & 0x02)  //TX��������ж�״̬��־
    {
        US0CON5 |= 0x02;
        TOVF_Flag = 1;
    }
    if(US0CON5 & 0x01)  //���������־λ
    {
        US0CON5 |= 0x01;
        ROVF_Flag = 1;
    }
}