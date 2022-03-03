#include "qmc5883.h"

uint8_t QMC_Init(void)
{ 
	uint8_t res;
//	
//	QMC_Write_Byte(QMC_CONTROL_2,0X80);	//复位QMC5883
//	delay_1ms(5);
//	QMC_Write_Byte(QMC_CONTROL_2,0X40);	//唤醒QMC5883,使能数据指针自动翻滚,失能中断
//	
////	QMC_Write_Byte(QMC_CONTROL_1,0X1d);	//复位QMC5883
//	res=QMC_Read_Byte(QMC_DEVICE_ID_REG);
//	if(res==QMC_DEVICE_ID)//器件ID正确
//	{
//		QMC_Write_Byte(QMC_SET_RESET_PERIOD,0X01);
//		QMC_Write_Byte(QMC_SET_RESET_PERIOD,0X01);
//		QMC_Write_Byte(QMC_SET_RESET_PERIOD,0X01);
//		QMC_Write_Byte(QMC_CONTROL_1,0X05);	//唤醒QMC5883,使能数据指针自动翻滚,失能中断
// 	}else return 0;
	QMC_Write_Byte(0X0B,0X01);
	QMC_Write_Byte(0X20,0X40);
	QMC_Write_Byte(0X21,0X01);
	QMC_Write_Byte(0x09,0x0D);
	return 1;
}


//得到温度值
//返回值:温度值(扩大了100倍)
uint8_t QMC_Get_Temperature(void)
{
	uint8_t buf[2]; 
	short raw;
	buf[0] = QMC_Read_Byte(QMC_TEMP_L_REG);
	buf[1] = QMC_Read_Byte(QMC_TEMP_H_REG);
	raw=((uint16_t)buf[1]<<8)|buf[0];  
  return raw;
}
//得到磁力计(原始值)
//mx,my,mz:磁力计x,y,z轴的原始读数(带符号)
//返回值:0,成功
//    其他,错误代码
uint8_t QMC_Get_Magnetic(short *mx,short *my,short *mz)
{
	uint8_t buff[6],res;  
	buff[0] = QMC_Read_Byte(QMC_MAGNETIC_XOUTL_REG);
	buff[1] = QMC_Read_Byte(QMC_MAGNETIC_XOUTH_REG);
	buff[2] = QMC_Read_Byte(QMC_MAGNETIC_YOUTL_REG);
	buff[3] = QMC_Read_Byte(QMC_MAGNETIC_YOUTH_REG);
	buff[4] = QMC_Read_Byte(QMC_MAGNETIC_ZOUTL_REG);
	buff[5] = QMC_Read_Byte(QMC_MAGNETIC_ZOUTH_REG);
	if(res==0)
	{
		*mx=((uint16_t)buff[1]<<8)|buff[0];  
		*my=((uint16_t)buff[3]<<8)|buff[2];  
		*mz=((uint16_t)buff[5]<<8)|buff[4];
	} 	
    return res;;
}

//IIC连续读
//addr:器件地址
//reg:要读取的寄存器地址
//len:要读取的长度
//buf:读取到的数据存储区
//返回值:0,正常
//    其他,错误代码
uint8_t QMC_Read_Len(uint8_t reg,uint8_t len,uint8_t *buf)
{ 
 	IIC_Start(); 
	IIC_Send_Byte(QMC_WRITE);//发送器件地址+写命令	
	IIC_Wait_Ack();
	IIC_Send_Byte(reg);	//写寄存器地址
	IIC_Wait_Ack();
	IIC_Start();
	IIC_Send_Byte(QMC_READ);//发送器件地址+读命令	
	IIC_Wait_Ack();
	while(len)
	{
		if(len==1)*buf=IIC_Read_Byte(0);//读数据,发送nACK 
		else *buf=IIC_Read_Byte(1);		//读数据,发送ACK  
		len--;
		buf++; 
		IIC_Ack();
	}    
	IIC_Stop();	//产生一个停止条件 
	return 0;	
}
//IIC写一个字节 
//reg:寄存器地址
//data:数据
//返回值:0,正常
//    其他,错误代码
uint8_t QMC_Write_Byte(uint8_t reg,uint8_t data) 				 
{ 
	IIC_Start(); 
	IIC_Send_Byte(QMC_WRITE);//发送器件地址+写命令	
	IIC_Wait_Ack();
	IIC_Send_Byte(reg);	//写寄存器地址
	IIC_Wait_Ack();		//等待应答 
	IIC_Send_Byte(data);//发送数据
	IIC_Wait_Ack(); 
	IIC_Stop();	 
	return 0;
}
//IIC读一个字节 
//reg:寄存器地址 
//返回值:读到的数据
uint8_t QMC_Read_Byte(uint8_t reg)
{
	uint8_t res;
	IIC_Start(); 
	IIC_Send_Byte(QMC_WRITE);//发送器件地址+写命令	
	IIC_Wait_Ack();
	IIC_Send_Byte(reg);	//写寄存器地址
	IIC_Wait_Ack();
	IIC_Start();
	IIC_Send_Byte(QMC_READ);//发送器件地址+读命令	
	IIC_Wait_Ack();
	res=IIC_Read_Byte(0);//读取数据,发送nACK 
	IIC_Stop();			//产生一个停止条件 
	return res;		
}

