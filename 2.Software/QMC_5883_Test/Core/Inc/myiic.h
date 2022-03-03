//////////////////////////////////////////////////////////////////////////////////	 
//I2C����HAL���ʼ������     By:Prowinter
//us����ʱ����TIM��ʱ�ṩ 
//�ں��Ĵ�������,�����޸���ο������ֲ�
//�����޸���ע���������ת��ΪHal�����
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

/* �Ĵ������� */
#define SDA_IN()	{GPIOE_MODER_L&=0XFFFFFF3F;}
#define SDA_OUT()	{GPIOE_MODER_L&=0XFFFFFF3F;GPIOE_MODER_L|=0x40;}


#define I2C_SCLK_SET() HAL_GPIO_WritePin(I2C_SCLK_GPIOx, I2C_SCLK_GPIO_Pin, GPIO_PIN_SET)
#define I2C_SCLK_RESET() HAL_GPIO_WritePin(I2C_SCLK_GPIOx, I2C_SCLK_GPIO_Pin, GPIO_PIN_RESET)

#define I2C_SDA_SET() HAL_GPIO_WritePin(I2C_SDA_GPIOx, I2C_SDA_GPIO_Pin, GPIO_PIN_SET)
#define I2C_SDA_RESET() HAL_GPIO_WritePin(I2C_SDA_GPIOx, I2C_SDA_GPIO_Pin, GPIO_PIN_RESET)
#define I2C_SDA_READ() HAL_GPIO_ReadPin(I2C_SDA_GPIOx, I2C_SDA_GPIO_Pin)

//IO��������
//IO��������	

//IIC���в�������
/* Hal�����*/
//void SDA_IN(void);
//void SDA_OUT(void);


void IIC_Init(void);       											  //��ʼ��IIC��IO��				 
void IIC_Start(void);															//����IIC��ʼ�ź�
void IIC_Stop(void);	  													//����IICֹͣ�ź�
void IIC_Ack(void);																//IIC����ACK�ź�
void IIC_NAck(void);															//IIC������ACK�ź�
void IIC_Send_Byte(unsigned char txd);						//IIC����һ���ֽ�
unsigned char IIC_Read_Byte(unsigned char ack);		//IIC��ȡһ���ֽ�
unsigned char IIC_Wait_Ack(void); 								//IIC�ȴ�ACK�ź�
void delay_us(unsigned short int nus);
  
#endif
















