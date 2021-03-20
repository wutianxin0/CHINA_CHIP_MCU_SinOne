#include "Multiplication_Division.H"

u32 product = 0;//�˻�
u32 quotient= 0;//��
u16 remainder = 0;//����
Result_union result;

/****************************************************
*�������ƣ�Multiplication(u16 faciend, u16 Multiplier)
*�������ܣ��˷�����
*��ڲ�����faciend��Multiplier
*���ڲ�������
****************************************************/
void Multiplication(u16 faciend, u16 Multiplier)
{
	EXA0 = faciend;
	EXA1 = faciend>>8;
	EXBL = Multiplier;
	EXBH = Multiplier>>8;

	OPERCON |= 0x80;
	while(OPERCON & 0x80);

	result.reg.a0 = EXA0;
	result.reg.a1 = EXA1;
	result.reg.a2 = EXA2;
	result.reg.a3 = EXA3;

	product = result.Result;
}	

/****************************************************
*�������ƣ�Division(u32 dividend,u16 divisor)
*�������ܣ���������
*��ڲ�����dividend��divisor
*���ڲ�������
****************************************************/
void Division(u32 dividend,u16 divisor)
{
	Result_union temp;
	temp.Result = dividend;

	EXA0 = temp.reg.a0;
	EXA1 = temp.reg.a1;
	EXA2 = temp.reg.a2;
	EXA3 = temp.reg.a3;

	EXBL = divisor;
	EXBH = divisor>>8;

	OPERCON |= 0xC0;
	while(OPERCON & 0x80);

	result.reg.a0 = EXA0;
	result.reg.a1 = EXA1;
	result.reg.a2 = EXA2;
	result.reg.a3 = EXA3;

	remainder = EXBH*256+ EXBL;
	quotient  = result.Result;
}

