//************************************************************
//  Copyright (c) 深圳市赛元微电子有限公司
//	文件名称	: slave_8_1.c
//	作者		: 
//	模块功能	: SIF slave 8+1多字节接收模块
//	局部函数列表:
//  最后更正日期:
// 	版本		:
// 	更改记录	: 从接收主发来的3Byte数据.
//*************************************************************
#include "H\SC91F733_C.H"

//============================
//模块内常量定义
//============================
#define		SIF_SLAVE_RECE_ACK		0x08		//SIF从8+1接收模式
#define		SIF_SLAVE_SEND_ACK		0x0a		//SIF从8+1发送模式

#define		BS(SFR,NUM)		(SFR|=(1<<NUM))
#define		BC(SFR,NUM)		(SFR&=~(1<<NUM))

#define		SIF_SET_RECE	(BC(SIFCFG,1))		  //设置SIF接收状态
#define		SIF_SET_SEND	(BS(SIFCFG,1))		  //设置SIF发送状态

#define		Rece_Date_Max			3	

//=====================================
//声明需要调用的全局变量
//=====================================
extern 		unsigned char Sif_Rec_dat_1 ;
extern 		unsigned char Sif_Rec_dat_2 ;
extern 		unsigned char Sif_Rec_dat_3 ;

extern		unsigned char Rece_Date_Cnt;	 //发送数据标志 
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
	SIFCFG = SIF_SLAVE_RECE_ACK;  //选择SIF从8+1接收模式
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
		SIF_SET_RECE; 				//slave切换为接收状态，发送1byte的数据		
	}
	else if(RXIF==1)
	{
		RXIF = 0;					//数据接收完成,中断标志清0
		if(++Rece_Date_Cnt>= Rece_Date_Max)
			{
				Rece_Date_Cnt = 0 ;
			}
		if(Rece_Date_Cnt==1)
			{Sif_Rec_dat_1 = SIFRXD;}		//保存接受数据DAT1
		else if(Rece_Date_Cnt==2)
			{Sif_Rec_dat_2 = SIFRXD;}		//保存接受数据DAT2
		else if(Rece_Date_Cnt==0)
			{Sif_Rec_dat_3 = SIFRXD;}		//保存接受数据DAT3
		
	}
	else if(STPIF==1)
	{
		STPIF=0;					//接收完成stop,中断标志清0
	}
		
}

