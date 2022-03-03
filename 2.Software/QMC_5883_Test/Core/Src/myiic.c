#include "myiic.h"

//void SDA_IN(void)
//{
//	GPIO_InitTypeDef GPIO_InitStruct = {0};
//  GPIO_InitStruct.Pin = GPIO_PIN_13;
//  GPIO_InitStruct.Mode = GPIO_MODE_INPUT;
//  GPIO_InitStruct.Pull = GPIO_NOPULL;
//  GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_HIGH;
//  HAL_GPIO_Init(GPIOB, &GPIO_InitStruct);
//}

//void SDA_OUT(void)
//{
//	GPIO_InitTypeDef GPIO_InitStruct = {0};
//  GPIO_InitStruct.Pin = GPIO_PIN_13;
//  GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;
//  GPIO_InitStruct.Pull = GPIO_PULLUP;
//  GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_HIGH;
//  HAL_GPIO_Init(GPIOB, &GPIO_InitStruct);
//}

void delay_us(unsigned short int nus)
{
	__HAL_TIM_SetCounter(&DLY_TIM_Handle,0);
    HAL_TIM_Base_Start(&DLY_TIM_Handle);
    while(__HAL_TIM_GetCounter(&DLY_TIM_Handle)<nus);
    HAL_TIM_Base_Stop(&DLY_TIM_Handle);
}

//����IIC��ʼ�ź�
void IIC_Start(void)
{
	SDA_OUT(); 
	I2C_SDA_SET();	  	  
	I2C_SCLK_SET();
	delay_us(4);
 	I2C_SDA_RESET();
	delay_us(4);
	I2C_SCLK_RESET();
}	  
//����IICֹͣ�ź�
void IIC_Stop(void)
{
	SDA_OUT();//sda�����
	I2C_SCLK_RESET();
	I2C_SDA_RESET();
	delay_us(4);
	I2C_SCLK_SET(); 
	I2C_SDA_SET();		
	delay_us(4);
}

//�ȴ�Ӧ���źŵ���
//����ֵ��1������Ӧ��ʧ��
//        0������Ӧ��ɹ�
unsigned char IIC_Wait_Ack(void)
{
	unsigned char ucErrTime=0;
	SDA_IN();      //SDA����Ϊ����  
	I2C_SDA_SET();   delay_us(1);
	I2C_SCLK_SET();delay_us(1);
	while(I2C_SDA_READ())
	{
		ucErrTime++;
		if(ucErrTime>250)
		{
			IIC_Stop();
			return 1;
		}
	}
	I2C_SCLK_RESET();
	return 0;  
} 
//����ACKӦ��
void IIC_Ack(void)
{
	I2C_SCLK_RESET();
	SDA_OUT();
	I2C_SDA_RESET();
	delay_us(2);
	I2C_SCLK_SET();
	delay_us(2);
	I2C_SCLK_RESET();
}

//������ACKӦ��		    
void IIC_NAck(void)
{
	I2C_SCLK_RESET();
	SDA_OUT();
	I2C_SDA_SET();
	delay_us(2);
	I2C_SCLK_SET();
	delay_us(2);
	I2C_SCLK_RESET();
}	

//IIC����һ���ֽ�
//���شӻ�����Ӧ��
//1����Ӧ��
//0����Ӧ��			  
void IIC_Send_Byte(unsigned char txd)
{                        
	unsigned char t;   
	SDA_OUT(); 	    
	I2C_SCLK_RESET();
	for(t=0;t<8;t++)
	{              
		if((txd&0x80)>>7)
		{
			I2C_SDA_SET();
		}
		else
		{
			I2C_SDA_RESET();
		}
		txd<<=1; 
		delay_us(2);
		I2C_SCLK_SET();
		delay_us(2);
		I2C_SCLK_RESET();	
		delay_us(2);
	}	 
} 	    

//��1���ֽڣ�ack=1ʱ������ACK��ack=0������nACK   
unsigned char IIC_Read_Byte(unsigned char ack)
{
	unsigned char i,receive=0;
	SDA_IN();//SDA����Ϊ����
	for(i=0;i<8;i++ )
	{
		I2C_SCLK_RESET(); 
		delay_us(2);
		I2C_SCLK_SET();
		receive<<=1;
		if(I2C_SDA_READ())receive++;
		delay_us(1);
	}					 
	if (!ack)
			IIC_NAck();
	else
			IIC_Ack(); 
	return receive;
}




