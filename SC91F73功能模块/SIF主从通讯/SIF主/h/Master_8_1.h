#ifndef MASTER_8_1_C_HEADER
#define MASTER_8_1_C_HEADER
//=====================================
//		声明可供外部调用的函数
//=====================================
extern void sif_init(void);
extern void send_start(void);
extern void send_stop(void);
extern void send_byte(unsigned char sif_send_byte);
extern unsigned char receive_byte(void);
extern bit  sif_waitack(void);
extern void  sif_ack(void);
extern void  sif_noack(void);
#endif