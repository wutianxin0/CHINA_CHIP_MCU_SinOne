//************************************************************
//  Copyright (c) 深圳市赛元微电子有限公司
//	文件名称	: slave_8_1.c
//	作者		: 
//	模块功能	: SIF slave 8+1接收——发送模块
//	局部函数列表:
//  最后更正日期:
// 	版本		:
// 	更改记录	: 
//*************************************************************
#include "H\SC91F830_C.H"
#include "H\Slave_8_1.H"

//=====================================
//声明需要调用的全局变量
//=====================================

unsigned char Sif_Send_dat ;	//从机发送的数据
unsigned char Sif_Rece_dat;		//从机接收的数据
unsigned char Sif_Send_dat_1;
unsigned char Sif_Send_dat_2;
unsigned char Sif_Send_dat_3;
unsigned char Sif_Rec_dat_1 ;
unsigned char Sif_Rec_dat_2 ;
unsigned char Sif_Rec_dat_3 ;

unsigned char Rece_Date_Cnt;	 //发送数据标志 
unsigned char Send_Date_Cnt;

//*************************************************************
// 函数名	：void main()
// 作者		：
// 功能		：SIF 从模式接收数据
// 参数		：无
// 返回值	：无
// 调用全局变量：无
// 修改全局变量：无
// 备注		：
//**************************************************************
void main()
{
	RSTCFG = 0x20;
	sif_init();
//	Sif_Send_dat_1 = 0x31;
//	Sif_Send_dat_2 = 0x13;
//	Sif_Send_dat_3 = 0x51;
//	Sif_Send_dat = 0x31;
	EA = 1;						//开总中断
	for(; ; )
	{
		
	}
}