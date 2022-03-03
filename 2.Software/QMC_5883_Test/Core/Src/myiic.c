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

//产生IIC起始信号
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
//产生IIC停止信号
void IIC_Stop(void)
{
	SDA_OUT();//sda线输出
	I2C_SCLK_RESET();
	I2C_SDA_RESET();
	delay_us(4);
	I2C_SCLK_SET(); 
	I2C_SDA_SET();		
	delay_us(4);
}

//等待应答信号到来
//返回值：1，接收应答失败
//        0，接收应答成功
unsigned char IIC_Wait_Ack(void)
{
	unsigned char ucErrTime=0;
	SDA_IN();      //SDA设置为输入  
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
//产生ACK应答
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

//不产生ACK应答		    
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

//IIC发送一个字节
//返回从机有无应答
//1，有应答
//0，无应答			  
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

//读1个字节，ack=1时，发送ACK，ack=0，发送nACK   
unsigned char IIC_Read_Byte(unsigned char ack)
{
	unsigned char i,receive=0;
	SDA_IN();//SDA设置为输入
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




