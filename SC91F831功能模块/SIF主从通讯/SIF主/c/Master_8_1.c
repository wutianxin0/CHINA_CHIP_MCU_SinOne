//************************************************************
//  Copyright (c) 深圳市赛元微电子有限公司
//	文件名称	: master_8_1.c
//	作者		: 
//	模块功能	: SIF master 8+1基础通讯模块
//	局部函数列表:
//  最后更正日期:
// 	版本		:
// 	更改记录	:
//*************************************************************
#include "H\SC91F831_C.H"

//============================
//模块内常量定义
//============================
#define		SIF_MASTER_ACK		0x00		//SIF主8+1通讯模式

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
	SIFCFG = SIF_MASTER_ACK;  //选择SIF主8+1通讯模式
	SIFCFG |= 0x80;		//打开SIF	
}

//*************************************************************
// 函数名	：void send_start(void)
// 作者		：
// 功能		：主发送start
// 参数		：无
// 返回值	：无
// 调用全局变量：无
// 修改全局变量：无
// 备注		：
//**************************************************************
void send_start(void)
{
	SIFCTL = 0x01;			//发送start
	while(STRIF == 0);		//完成start,该bit硬件置1
	STRIF = 0;				//清除send start完成标志	
}

//*************************************************************
// 函数名	：void send_stop(void)
// 作者		：
// 功能		：主发送stop
// 参数		：无
// 返回值	：无
// 调用全局变量：无
// 修改全局变量：无
// 备注		：
//**************************************************************
void send_stop(void)
{
	SIFCTL = 0x00;			//发送stop
	while(STPIF == 0);		//完成stop,该bit硬件置1
	STPIF = 0;				//清除send stop完成标志	
}

//*************************************************************
// 函数名	：void send_byte(unsigned char sif_send_byte)
// 作者		：
// 功能		：主发送 1 byte的数据
// 参数		：unsigned char sif_send_byte
// 返回值	：无
// 调用全局变量：无
// 修改全局变量：无
// 备注		：
//**************************************************************
void send_byte(unsigned char sif_send_byte)
{
	SIFTXD = sif_send_byte;
	SIFCTL = 0x02;			//发送数据
	while(TXIF == 0);		//完成发送,该bit硬件置1
	TXIF = 0;				//清除发送完成标志	
}

//*************************************************************
// 函数名	：void send_byte(unsigned char sif_send_byte)
// 作者		：
// 功能		：主接收 1 byte的数据
// 参数		：无
// 返回值	：unsigned char SIFRXD
// 调用全局变量：无
// 修改全局变量：无
// 备注		：
//**************************************************************
unsigned char receive_byte(void)
{
	
	SIFCTL = 0x03;			//接受数据
	while(RXIF == 0);		//完成接受,该bit硬件置1
	RXIF = 0;				//清除接受完成标志
	return (SIFRXD);	    //读取接收的数据
}

//*************************************************************
// 函数名	：bit  sif_waitack(void)
// 作者		：
// 功能		：读从发来的ACK
// 参数		：无
// 返回值	：1/0
// 调用全局变量：无
// 修改全局变量：无
// 备注		：返回1,有ack;返回0,无ack
//**************************************************************
bit  sif_waitack(void)
{
	return (!RTNACK);	
}

//*************************************************************
// 函数名	：void  sif_ack(void)
// 作者		：
// 功能		：发送应答信号
// 参数		：无
// 返回值	：无
// 调用全局变量：无
// 修改全局变量：无
// 备注		：
//**************************************************************
void  sif_ack(void)
{
	SIFCFG &= ~0x01;				//发送应答
}

//*************************************************************
// 函数名	：void  sif_noack(void)
// 作者		：
// 功能		：发送无应答信号
// 参数		：无
// 返回值	：无
// 调用全局变量：无
// 修改全局变量：无
// 备注		：
//**************************************************************
void  sif_noack(void)
{
	SIFCFG |= 0x01;					 //发送无应答
}


