//////////////////////////////////////////////////////////////////////////////////	 
//I2C——HAL库初始化程序     By:Prowinter
//us级延时采用TIM定时提供 
//内含寄存器操作,具体修改请参考数据手册
//不会修改请注释相关内容转换为Hal库操作
////////////////////////////////////////////////////////////////////////////////// 	
#ifndef __MYIIC_H__
#define __MYIIC_H__
#include "gd32f30x.h"

/* 寄存器操作 */
/* Note:注意查找不同板卡GPIO状态操作位 */
#define SDA_IN()	gpio_init(GPIOA, GPIO_MODE_IPU, GPIO_OSPEED_MAX,GPIO_PIN_5);
#define SDA_OUT()	gpio_init(GPIOA, GPIO_MODE_OUT_PP, GPIO_OSPEED_MAX,GPIO_PIN_5);


#define I2C_SCLK_SET() gpio_bit_set(GPIOA,GPIO_PIN_4);
#define I2C_SCLK_RESET() gpio_bit_reset(GPIOA,GPIO_PIN_4);

#define I2C_SDA_SET() gpio_bit_set(GPIOA, GPIO_PIN_5)
#define I2C_SDA_RESET() gpio_bit_reset(GPIOA, GPIO_PIN_5)
#define I2C_SDA_READ() gpio_input_bit_get(GPIOA, GPIO_PIN_5)

//IO方向设置
//IO操作函数	

//IIC所有操作函数
/* Hal库操作*/
// void SDA_IN(void);
// void SDA_OUT(void);
		 
void IIC_Start(void);															//发送IIC开始信号
void IIC_Stop(void);	  													//发送IIC停止信号
void IIC_Ack(void);																//IIC发送ACK信号
void IIC_NAck(void);															//IIC不发送ACK信号
void IIC_Send_Byte(unsigned char txd);						//IIC发送一个字节
unsigned char IIC_Read_Byte(unsigned char ack);		//IIC读取一个字节
unsigned char IIC_Wait_Ack(void); 								//IIC等待ACK信号
void delay_us(unsigned short int nus);
  
#endif
















