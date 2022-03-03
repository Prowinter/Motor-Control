#include "qmc5883.h"

uint8_t QMC_Init(void)
{ 
	uint8_t res;
//	
//	QMC_Write_Byte(QMC_CONTROL_2,0X80);	//��λQMC5883
//	delay_1ms(5);
//	QMC_Write_Byte(QMC_CONTROL_2,0X40);	//����QMC5883,ʹ������ָ���Զ�����,ʧ���ж�
//	
////	QMC_Write_Byte(QMC_CONTROL_1,0X1d);	//��λQMC5883
//	res=QMC_Read_Byte(QMC_DEVICE_ID_REG);
//	if(res==QMC_DEVICE_ID)//����ID��ȷ
//	{
//		QMC_Write_Byte(QMC_SET_RESET_PERIOD,0X01);
//		QMC_Write_Byte(QMC_SET_RESET_PERIOD,0X01);
//		QMC_Write_Byte(QMC_SET_RESET_PERIOD,0X01);
//		QMC_Write_Byte(QMC_CONTROL_1,0X05);	//����QMC5883,ʹ������ָ���Զ�����,ʧ���ж�
// 	}else return 0;
	QMC_Write_Byte(0X0B,0X01);
	QMC_Write_Byte(0X20,0X40);
	QMC_Write_Byte(0X21,0X01);
	QMC_Write_Byte(0x09,0x0D);
	return 1;
}


//�õ��¶�ֵ
//����ֵ:�¶�ֵ(������100��)
uint8_t QMC_Get_Temperature(void)
{
	uint8_t buf[2]; 
	short raw;
	buf[0] = QMC_Read_Byte(QMC_TEMP_L_REG);
	buf[1] = QMC_Read_Byte(QMC_TEMP_H_REG);
	raw=((uint16_t)buf[1]<<8)|buf[0];  
  return raw;
}
//�õ�������(ԭʼֵ)
//mx,my,mz:������x,y,z���ԭʼ����(������)
//����ֵ:0,�ɹ�
//    ����,�������
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

//IIC������
//addr:������ַ
//reg:Ҫ��ȡ�ļĴ�����ַ
//len:Ҫ��ȡ�ĳ���
//buf:��ȡ�������ݴ洢��
//����ֵ:0,����
//    ����,�������
uint8_t QMC_Read_Len(uint8_t reg,uint8_t len,uint8_t *buf)
{ 
 	IIC_Start(); 
	IIC_Send_Byte(QMC_WRITE);//����������ַ+д����	
	IIC_Wait_Ack();
	IIC_Send_Byte(reg);	//д�Ĵ�����ַ
	IIC_Wait_Ack();
	IIC_Start();
	IIC_Send_Byte(QMC_READ);//����������ַ+������	
	IIC_Wait_Ack();
	while(len)
	{
		if(len==1)*buf=IIC_Read_Byte(0);//������,����nACK 
		else *buf=IIC_Read_Byte(1);		//������,����ACK  
		len--;
		buf++; 
		IIC_Ack();
	}    
	IIC_Stop();	//����һ��ֹͣ���� 
	return 0;	
}
//IICдһ���ֽ� 
//reg:�Ĵ�����ַ
//data:����
//����ֵ:0,����
//    ����,�������
uint8_t QMC_Write_Byte(uint8_t reg,uint8_t data) 				 
{ 
	IIC_Start(); 
	IIC_Send_Byte(QMC_WRITE);//����������ַ+д����	
	IIC_Wait_Ack();
	IIC_Send_Byte(reg);	//д�Ĵ�����ַ
	IIC_Wait_Ack();		//�ȴ�Ӧ�� 
	IIC_Send_Byte(data);//��������
	IIC_Wait_Ack(); 
	IIC_Stop();	 
	return 0;
}
//IIC��һ���ֽ� 
//reg:�Ĵ�����ַ 
//����ֵ:����������
uint8_t QMC_Read_Byte(uint8_t reg)
{
	uint8_t res;
	IIC_Start(); 
	IIC_Send_Byte(QMC_WRITE);//����������ַ+д����	
	IIC_Wait_Ack();
	IIC_Send_Byte(reg);	//д�Ĵ�����ַ
	IIC_Wait_Ack();
	IIC_Start();
	IIC_Send_Byte(QMC_READ);//����������ַ+������	
	IIC_Wait_Ack();
	res=IIC_Read_Byte(0);//��ȡ����,����nACK 
	IIC_Stop();			//����һ��ֹͣ���� 
	return res;		
}

