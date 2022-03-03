#ifndef __QMC5883L_H
#define __QMC5883L_H
#include "myiic.h"   												  	  
#include "stm32f4xx_hal.h"

#define QMC_DEVICE_ID_REG		0x0D	//����ID�Ĵ���
#define QMC_DEVICE_ID		0xFF	//����IDֵ

#define QMC_WRITE				0X1A
#define QMC_READ				0X1B

#define QMC_STATUS		0X06	//״̬�Ĵ���

#define QMC_CONTROL_1		0X09	//���ƼĴ���
#define QMC_CONTROL_2		0X0A	//���ƼĴ���

#define QMC_SET_RESET_PERIOD		0X0B	//SET/RESET�Ĵ���,�Ƽ�дΪ0x01

#define QMC_TEMP_L_REG		0X07	//�¶ȴ�����,��8λ�Ĵ���
#define QMC_TEMP_H_REG		0X08	//�¶ȴ�����,��8λ�Ĵ���

#define QMC_MAGNETIC_XOUTL_REG		0X00	//������ֵ,X���8λ�Ĵ���
#define QMC_MAGNETIC_XOUTH_REG		0X01	//������ֵ,X���8λ�Ĵ���
#define QMC_MAGNETIC_YOUTL_REG		0X02	//������ֵ,Y���8λ�Ĵ���
#define QMC_MAGNETIC_YOUTH_REG		0X03	//������ֵ,Y���8λ�Ĵ���
#define QMC_MAGNETIC_ZOUTL_REG		0X04	//������ֵ,Z���8λ�Ĵ���
#define QMC_MAGNETIC_ZOUTH_REG		0X05	//������ֵ,Z���8λ�Ĵ���


#define QMC_2G_Gain 12000
#define QMC_8G_Gain 3000

uint8_t QMC_Init(void); 								//��ʼ��QMC5883
uint8_t QMC_Read_Len(uint8_t reg,uint8_t len,uint8_t *buf); //IIC������ 
uint8_t QMC_Write_Byte(uint8_t reg,uint8_t data);				//IICдһ���ֽ�
uint8_t QMC_Read_Byte(uint8_t reg);						//IIC��һ���ֽ�

uint8_t QMC_Get_Temperature(void);
uint8_t QMC_Get_Magnetic(short *mx,short *my,short *mz);
#endif




































