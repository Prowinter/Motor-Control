//////////////////////////////////////////////////////////////////////////////////	 
//I2C����HAL���ʼ������     By:Prowinter
//us����ʱ����TIM��ʱ�ṩ 
//�ں��Ĵ�������,�����޸���ο������ֲ�
//�����޸���ע���������ת��ΪHal�����
////////////////////////////////////////////////////////////////////////////////// 	
#ifndef __MYIIC_H__
#define __MYIIC_H__
#include "gd32f30x.h"

/* �Ĵ������� */
/* Note:ע����Ҳ�ͬ�忨GPIO״̬����λ */
#define SDA_IN()	gpio_init(GPIOA, GPIO_MODE_IPU, GPIO_OSPEED_MAX,GPIO_PIN_5);
#define SDA_OUT()	gpio_init(GPIOA, GPIO_MODE_OUT_PP, GPIO_OSPEED_MAX,GPIO_PIN_5);


#define I2C_SCLK_SET() gpio_bit_set(GPIOA,GPIO_PIN_4);
#define I2C_SCLK_RESET() gpio_bit_reset(GPIOA,GPIO_PIN_4);

#define I2C_SDA_SET() gpio_bit_set(GPIOA, GPIO_PIN_5)
#define I2C_SDA_RESET() gpio_bit_reset(GPIOA, GPIO_PIN_5)
#define I2C_SDA_READ() gpio_input_bit_get(GPIOA, GPIO_PIN_5)

//IO��������
//IO��������	

//IIC���в�������
/* Hal�����*/
// void SDA_IN(void);
// void SDA_OUT(void);
		 
void IIC_Start(void);															//����IIC��ʼ�ź�
void IIC_Stop(void);	  													//����IICֹͣ�ź�
void IIC_Ack(void);																//IIC����ACK�ź�
void IIC_NAck(void);															//IIC������ACK�ź�
void IIC_Send_Byte(unsigned char txd);						//IIC����һ���ֽ�
unsigned char IIC_Read_Byte(unsigned char ack);		//IIC��ȡһ���ֽ�
unsigned char IIC_Wait_Ack(void); 								//IIC�ȴ�ACK�ź�
void delay_us(unsigned short int nus);
  
#endif
















