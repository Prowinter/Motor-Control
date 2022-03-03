#ifndef __QMC5883L_H
#define __QMC5883L_H
#include "myiic.h"   												  	  
#include "stm32f4xx_hal.h"

#define QMC_DEVICE_ID_REG		0x0D	//器件ID寄存器
#define QMC_DEVICE_ID		0xFF	//器件ID值

#define QMC_WRITE				0X1A
#define QMC_READ				0X1B

#define QMC_STATUS		0X06	//状态寄存器

#define QMC_CONTROL_1		0X09	//控制寄存器
#define QMC_CONTROL_2		0X0A	//控制寄存器

#define QMC_SET_RESET_PERIOD		0X0B	//SET/RESET寄存器,推荐写为0x01

#define QMC_TEMP_L_REG		0X07	//温度传感器,低8位寄存器
#define QMC_TEMP_H_REG		0X08	//温度传感器,高8位寄存器

#define QMC_MAGNETIC_XOUTL_REG		0X00	//磁力计值,X轴高8位寄存器
#define QMC_MAGNETIC_XOUTH_REG		0X01	//陀螺仪值,X轴低8位寄存器
#define QMC_MAGNETIC_YOUTL_REG		0X02	//陀螺仪值,Y轴高8位寄存器
#define QMC_MAGNETIC_YOUTH_REG		0X03	//陀螺仪值,Y轴低8位寄存器
#define QMC_MAGNETIC_ZOUTL_REG		0X04	//陀螺仪值,Z轴高8位寄存器
#define QMC_MAGNETIC_ZOUTH_REG		0X05	//陀螺仪值,Z轴低8位寄存器


#define QMC_2G_Gain 12000
#define QMC_8G_Gain 3000

uint8_t QMC_Init(void); 								//初始化QMC5883
uint8_t QMC_Read_Len(uint8_t reg,uint8_t len,uint8_t *buf); //IIC连续读 
uint8_t QMC_Write_Byte(uint8_t reg,uint8_t data);				//IIC写一个字节
uint8_t QMC_Read_Byte(uint8_t reg);						//IIC读一个字节

uint8_t QMC_Get_Temperature(void);
uint8_t QMC_Get_Magnetic(short *mx,short *my,short *mz);
#endif




































