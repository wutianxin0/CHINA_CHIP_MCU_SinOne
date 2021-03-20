//************************************************************
//  Copyright (c) 深圳市赛元微电子有限公司
//	文件名称	: slave_8_1.c
//	作者		: 
//	模块功能	: SIF slave 8+1多字节发送模块
//	局部函数列表:
//  最后更正日期:
// 	版本		:
// 	更改记录	: 从向主发送3Byte的数据，完成发送，切换接收模式，接收主的Stop信号.
//*************************************************************
#include "H\SC91F831_C.H"

//============================
//模块内常量定义
//============================
#define		SIF_SLAVE_RECE_ACK		0x08		//SIF从8+1接收模式
#define		SIF_SLAVE_SEND_ACK		0x0a		//SIF从8+1发送模式

#define		BS(SFR,NUM)		(SFR|=(1<<NUM))
#define		BC(SFR,NUM)		(SFR&=~(1<<NUM))

#define		SIF_SET_RECE	(BC(SIFCFG,1))		  //设置SIF接收状态
#define		SIF_SET_SEND	(BS(SIFCFG,1))		  //设置SIF发送状态

#define		Send_Date_Max			3	

//=====================================
//声明需要调用的全局变量
//=====================================
extern 		unsigned char Sif_Send_dat_1 ;
extern 		unsigned char Sif_Send_dat_2 ;
extern 		unsigned char Sif_Send_dat_3 ;

extern		unsigned char Send_Date_Cnt;	 //发送数据标志 
//*************************************************************
// 函数名	：void sif_init(void)
// 作者		：
// 功能		：sif初始化
// 参数		：无
// 返回值	：无
// 调用全局变量：无
// 修改全局变量：无
// 备注		：
//**************************************************************
void sif_init(void)
{
	P1CFG1 &= 0x0F;		//设置P16、P17状态为准双向模式
	P1 |= 0xC0;         //设置P16、P17输出高
	SIFCFG = SIF_SLAVE_SEND_ACK;  //选择SIF从8+1发送模式
	SIFCFG |= 0x80;		//打开SIF
	ESIF = 1;			//开SIF中断	
}

//*************************************************************
// 函数名	：void Sif_Slave_Int() interrupt 4
// 作者		：
// 功能		：SIF 从模式中断机制
// 参数		：无
// 返回值	：无
// 调用全局变量：无
// 修改全局变量：无
// 备注		：
//**************************************************************
void Sif_Slave_Int() interrupt 4
{
	if(STRIF==1)
	{
		STRIF = 0;					//接收完成start,中断标志清0	
		SIFTXD = Sif_Send_dat_1;	//准备数据(1)
		SIF_SET_SEND; 				//slave切换为发送状态，发送N byte的数据
	}
	else if(TXIF==1)
	{
		TXIF = 0;								//数据发送完成,中断标志清0
		if(++Send_Date_Cnt>= Send_Date_Max)
			{
				Send_Date_Cnt = 0 ;
			}
		if(Send_Date_Cnt==1)
			{SIFTXD = Sif_Send_dat_2;}		//准备数据(2)
		else if(Send_Date_Cnt==2)
			{SIFTXD = Sif_Send_dat_3;}		//准备数据(3)
		else
		{SIF_SET_RECE;}				      //数据发送完成，slave切换输入模式，准备接收stop	
	}
	else if(STPIF==1)
	{
		STPIF=0;						  //接收完成stop,中断标志清0
		
	}
		
}

