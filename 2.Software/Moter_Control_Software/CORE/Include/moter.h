#ifndef __MOTER_H__
#define __MOTER_H__
#include "gd32f30x.h"

#define Enable_Moter_1_Quadrature_Decode 1
#define Enable_Moter_2_Quadrature_Decode 1
#define Enable_Moter_3_Quadrature_Decode 1
#define Enable_Moter_4_Quadrature_Decode 1

#define Moter_1_Front gpio_bit_set(GPIOB,GPIO_PIN_12)
#define Moter_2_Front gpio_bit_set(GPIOB,GPIO_PIN_9)
#define Moter_3_Front gpio_bit_set(GPIOA,GPIO_PIN_12)
#define Moter_4_Front gpio_bit_set(GPIOB,GPIO_PIN_8)

#define Moter_1_Back gpio_bit_reset(GPIOB,GPIO_PIN_12)
#define Moter_2_Back gpio_bit_reset(GPIOB,GPIO_PIN_9)
#define Moter_3_Back gpio_bit_reset(GPIOA,GPIO_PIN_12)
#define Moter_4_Back gpio_bit_reset(GPIOB,GPIO_PIN_8)

#define Moter_R 0 //定义轮子半径

struct moter_value { 
	uint32_t Quadrature_Decode;  //编码器值
	char Dir;		//运动方向
};

void moter_quadrature_decode_init(void);
void timer1_configuration(void);
void timer2_configuration(void);	
void timer3_configuration(void);	
void timer4_configuration(void);	
void pwm_config(void);

#endif
















