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


unsigned char Receive_ATR_Info[16];//ATR信息
void SmartCard_Init(void);
void Timer_Delay(unsigned int count);
void SC_Activation_ColdReduction(void);
void SC_WarmReset(void);

/*****************************************************
*函数名称：void SmartCard_Test(void)
*函数功能：智能卡测试
*入口参数：void
*出口参数：void
*****************************************************/
void SmartCard_Test(void)
{
	SmartCard_Init();//智能卡初始化
    SC_Activation_ColdReduction();//冷复位后读取ATR
//    void SC_WarmReset();//暖复位后读取ATR
	while(1)
	{
	}
}

/*****************************************************
*函数名称：void SmartCard_Init(void)
*函数功能：智能卡初始化
*入口参数：void
*出口参数：void
*****************************************************/
void SmartCard_Init(void)
{
    OTCON &= 0xCF;     //选择SC通信
    US0CON0 = 0x30;    //普通IO
    US0CON0 &= ~0x04;  //正反向约定选择
    US0CON1 = 0x74; 
    US0CON2 |= 0x81;   //设置SCCK  372
    US0CON4 = 0x03;    //扩展保护时间       
//    IE1 = 0x01;        //中断使能
//    EA = 1;            //总中断使能
}

/*****************************************************
*函数名称：void SmartCard_Init(void)
*函数功能：智能卡冷复位后的接收ATR
*入口参数：void
*出口参数：void
*****************************************************/
void SC_Activation_ColdReduction(void)
{
    int i = 0;
    US0CON0 &= ~0x40;  //关闭SC_CLK      
    SC_RST = 0;
    SC_PWR = 1;
    US0CON0 &= 0x7f;  //DAT设置普通IO口
    SC_DAT = 1;
    Timer_Delay(42);
    US0CON0 |= 0x40;  //开启SC_CLK
    US0CON0 |= 0x80;  //DAT设置为DAT口
    Timer_Delay(250);
    SC_RST = 1;
    Timer_Delay(400);
    
    //接收数据
    US0CON0 &= ~0X20;   //接收使能
    for(i=0; i<16; i++) //ATR为15byte
    {  
        US0CON5 &= 0x7f;  //切换到读写状态寄存器        
        while(US0CON5 & 0x04);
        while(!(US0CON5 & 0x20));        
        US0CON5 |= 0X20;   //写1清零
        Receive_ATR_Info[i] = US0CON3;
    }
}

/*****************************************************
*函数名称：void SC_WarmReset(void)
*函数功能：智能卡暖复位后的接收ATR
*入口参数：void
*出口参数：void
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
    
    //接收数据
    US0CON0 &= ~0X20;   //接收使能
    for(i=0; i<16; i++)
    {    
        US0CON5 &= 0x7f;  //切换到读写状态寄存器        
        while(US0CON5 & 0x04);
        while(!(US0CON5 & 0x20));
        US0CON5 |= 0x20;  //写1清零
        Receive_ATR_Info[i] = US0CON3;
    }
}

/*****************************************************
*函数名称：void SC_Send(unsigned char Data)
*函数功能：智能卡发送数据
*入口参数：Data
*出口参数：void
*****************************************************/
void SC_Send(unsigned char Data)
{
    US0CON0 &= ~0x20;  //清零
    US0CON0 |= 0x20;  //发送使能
    P07 = ~P07;P07 = ~P07;P07 = ~P07;   
    US0CON3 = Data;  
    while(US0CON5 & 0x08);   
    while(!TC_Flag);
    TC_Flag = 0;
}

/*****************************************************
*函数名称：void SC_Receive(void)
*函数功能：智能卡接收送数据
*入口参数：void
*出口参数：void
*****************************************************/
unsigned char SC_Receive(void)
{
    unsigned char temp = 0x00;
    US0CON0 &= ~0x20;  //接收使能 
    while(US0CON5 & 0x04);
    while(!RC_Flag);  
    RC_Flag = 0;  
    temp = US0CON3; 
    return temp;
}

/*****************************************************
*函数名称：void Timer_Delay(unsigned int count)
*函数功能：延时函数
*入口参数：count
*出口参数：void
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
*函数名称：void SC_Interrupt() interrupt 7
*函数功能：中断服务函数
*入口参数：void
*出口参数：void
*****************************************************/
void SC_Interrupt() interrupt 7
{  
    P07 = ~P07;
    US0CON5 = 0x00;    //读写状态寄存器
    if(US0CON5 & 0x40)  //发送完成标志位
    {
        US0CON5 |= 0x40;
        TC_Flag = 1;
    }
    
    if(US0CON5 & 0x20)  //接受完成标志位
    {
        US0CON5 |= 0x20;
        RC_Flag = 1;
    }
    
    if(US0CON5 & 0x10)  //等待数据重发标志位
    {
        WTRT_Flag = 1;
    }
    if(US0CON5 & 0x08)  //数据发送忙标志位
    {
        TBUSY_Flag = 1;
    }
    if(US0CON5 & 0x04)  //数据接收忙标志位
    {
        RBUSY_Flag = 1;
    }
    if(US0CON5 & 0x02)  //等待超时标志位
    {
        US0CON5 |= 0x02;
        WTER_Flag = 1;
    }
    if(US0CON5 & 0x01)  //接收帧错误标志位
    {
        US0CON5 |= 0x01;
        FER_Flag = 1;
    }
    
    US0CON5 = 0x80;    //读写错误信息寄存器
    if(US0CON5 & 0x08)  //发送数据奇偶检验错误标志位
    {
        US0CON5 |= 0x08;
        TPER_Flag = 1;
    }
    if(US0CON5 & 0x04)  //接收数据奇偶检验错误标志位
    {
        US0CON5 |= 0x04;
        RPER_Flag = 1;
    }
    if(US0CON5 & 0x02)  //TX溢出错误中断状态标志
    {
        US0CON5 |= 0x02;
        TOVF_Flag = 1;
    }
    if(US0CON5 & 0x01)  //接收溢出标志位
    {
        US0CON5 |= 0x01;
        ROVF_Flag = 1;
    }
}