//////////////////////////////////////////////////////////////////////////////////	 
//I2C——HAL库初始化程序     By:Prowinter
//us级延时采用TIM定时提供 
//内含寄存器操作,具体修改请参考数据手册
//不会修改请注释相关内容转换为Hal库操作
////////////////////////////////////////////////////////////////////////////////// 	
#ifndef __MYIIC_H__
#define __MYIIC_H__
#include "stm32f4xx_hal.h"

#define DLY_TIM_Handle  htim7
extern TIM_HandleTypeDef DLY_TIM_Handle;
#define GPIOE_MODER_L            *(unsigned int*)(GPIOE_BASE+0x00)
#define GPIOE_MODER_H            *(unsigned int*)(GPIOE_BASE+0x04)
	
#define I2C_SCLK_GPIOx GPIOE
#define I2C_SCLK_GPIO_Pin GPIO_PIN_2

#define I2C_SDA_GPIOx GPIOE
#define I2C_SDA_Pin_Num 3
#define I2C_SDA_GPIO_Pin GPIO_PIN_3
#define Get_I2C_Pin_Num (I2C_SDA_Pin_Num>7?I2C_SDA_Pin_Num-8:I2C_SDA_Pin_Num)

/* 寄存器操作 */
#define SDA_IN()	{GPIOE_MODER_L&=0XFFFFFF3F;}
#define SDA_OUT()	{GPIOE_MODER_L&=0XFFFFFF3F;GPIOE_MODER_L|=0x40;}


#define I2C_SCLK_SET() HAL_GPIO_WritePin(I2C_SCLK_GPIOx, I2C_SCLK_GPIO_Pin, GPIO_PIN_SET)
#define I2C_SCLK_RESET() HAL_GPIO_WritePin(I2C_SCLK_GPIOx, I2C_SCLK_GPIO_Pin, GPIO_PIN_RESET)

#define I2C_SDA_SET() HAL_GPIO_WritePin(I2C_SDA_GPIOx, I2C_SDA_GPIO_Pin, GPIO_PIN_SET)
#define I2C_SDA_RESET() HAL_GPIO_WritePin(I2C_SDA_GPIOx, I2C_SDA_GPIO_Pin, GPIO_PIN_RESET)
#define I2C_SDA_READ() HAL_GPIO_ReadPin(I2C_SDA_GPIOx, I2C_SDA_GPIO_Pin)

//IO方向设置
//IO操作函数	

//IIC所有操作函数
/* Hal库操作*/
//void SDA_IN(void);
//void SDA_OUT(void);


void IIC_Init(void);       											  //初始化IIC的IO口				 
void IIC_Start(void);															//发送IIC开始信号
void IIC_Stop(void);	  													//发送IIC停止信号
void IIC_Ack(void);																//IIC发送ACK信号
void IIC_NAck(void);															//IIC不发送ACK信号
void IIC_Send_Byte(unsigned char txd);						//IIC发送一个字节
unsigned char IIC_Read_Byte(unsigned char ack);		//IIC读取一个字节
unsigned char IIC_Wait_Ack(void); 								//IIC等待ACK信号
void delay_us(unsigned short int nus);
  
#endif
















