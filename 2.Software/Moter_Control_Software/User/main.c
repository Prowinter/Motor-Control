/*!
    \file    main.c
    \brief   led spark with systick, USART print and key example

    \version 2017-02-10, V1.0.0, firmware for GD32F30x
    \version 2018-10-10, V1.1.0, firmware for GD32F30x
    \version 2018-12-25, V2.0.0, firmware for GD32F30x
    \version 2020-09-30, V2.1.0, firmware for GD32F30x 
*/

/*
    Copyright (c) 2020, GigaDevice Semiconductor Inc.

    Redistribution and use in source and binary forms, with or without modification, 
are permitted provided that the following conditions are met:

    1. Redistributions of source code must retain the above copyright notice, this 
       list of conditions and the following disclaimer.
    2. Redistributions in binary form must reproduce the above copyright notice, 
       this list of conditions and the following disclaimer in the documentation 
       and/or other materials provided with the distribution.
    3. Neither the name of the copyright holder nor the names of its contributors 
       may be used to endorse or promote products derived from this software without 
       specific prior written permission.

    THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS" 
AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED 
WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED. 
IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, 
INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT 
NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR 
PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, 
WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) 
ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY 
OF SUCH DAMAGE.
*/

#include "gd32f30x.h"
#include "systick.h"
#include <stdio.h>
#include "main.h"
#include "gd32f307c_eval.h"
#include "mpu6050.h"
#include "myiic.h"

#include "moter.h"
#include "qmc5883l.h"


/*!
    \brief      toggle the led every 500ms
    \param[in]  none
    \param[out] none
    \retval     none
*/
void led_spark(void)
{
    static __IO uint32_t timingdelaylocal = 0U;

    if(timingdelaylocal){

        if(timingdelaylocal < 500U){
            gd_eval_led_on(LED2);
        }else{
            gd_eval_led_off(LED2);
        }

        timingdelaylocal--;
    }else{
        timingdelaylocal = 1000U;
    }
}

/*!
    \brief      main function
    \param[in]  none
    \param[out] none
    \retval     none
*/



void delay_us_config(void)
{
//		timer_oc_parameter_struct timer_ocintpara;
    timer_parameter_struct timer_initpara;
		rcu_periph_clock_enable(RCU_TIMER5);
    timer_deinit(TIMER5);

    /* TIMER5 configuration */
    timer_initpara.prescaler         = 59;
    timer_initpara.alignedmode       = TIMER_COUNTER_EDGE;
    timer_initpara.counterdirection  = TIMER_COUNTER_UP;
    timer_initpara.period            = 65535;
    timer_initpara.clockdivision     = TIMER_CKDIV_DIV1;
    timer_initpara.repetitioncounter = 0;
    timer_init(TIMER5,&timer_initpara);

    timer_auto_reload_shadow_disable(TIMER5);
    /* auto-reload preload enable */
    timer_disable(TIMER5);
}

int main(void)
{
		short mx=0,my=0,mz=0;
		short gx=0,gy=0,gz=0;
		double Mx=0,My=0,Mz=0;
		uint8_t buff[6];
		uint8_t tem=0;
		uint8_t tem1=0;
		int16_t raww;
		struct moter_value moter_1;
		struct moter_value moter_2;
		struct moter_value moter_3;
		struct moter_value moter_4;
    /* configure systick */
    systick_config();
		gd_eval_com_init(USART1);
    /* initilize the LEDs, USART and key */
		rcu_periph_clock_enable(RCU_GPIOA);
	  rcu_periph_clock_enable(RCU_GPIOB);
    /* configure led GPIO port */ 
//    gpio_init(GPIOB, GPIO_MODE_OUT_PP, GPIO_OSPEED_MAX,GPIO_PIN_1);
//		gpio_init(GPIOB, GPIO_MODE_OUT_PP, GPIO_OSPEED_MAX,GPIO_PIN_0);
//	
//		moter_quadrature_decode_init();
//	  pwm_config();
//	
//		Moter_1_Back;
//		Moter_2_Back;
//		Moter_3_Back;
//		Moter_4_Back;
	
		delay_us_config();
//		MPU_Init();
		QMC_Init();
    while (1)
		{
			delay_1ms(500);
//			tem = QMC_Get_Temperature();
			tem = QMC_Read_Byte(0X07);
			tem1 = QMC_Read_Byte(0X08);
			raww = (tem1<<8)|tem;  ;
		printf("tem=%d\r\n",raww);
		buff[0] = QMC_Read_Byte(QMC_MAGNETIC_XOUTL_REG);
		buff[1] = QMC_Read_Byte(QMC_MAGNETIC_XOUTH_REG);
		buff[2] = QMC_Read_Byte(QMC_MAGNETIC_YOUTL_REG);
		buff[3] = QMC_Read_Byte(QMC_MAGNETIC_YOUTH_REG);
		buff[4] = QMC_Read_Byte(QMC_MAGNETIC_ZOUTL_REG);
		buff[5] = QMC_Read_Byte(QMC_MAGNETIC_ZOUTH_REG);
			gx = ((uint16_t)buff[1]<<8)|buff[0];  
			gy = ((uint16_t)buff[3]<<8)|buff[2];  
			gz = ((uint16_t)buff[5]<<8)|buff[4];
//			printf("buff[0]=%d,buff[1]=%d,\r\nbuff[2]=%d,buff[3]=%d,\r\nbuff[4]=%d,buff[5]=%d\r\n\r\n",buff[0],buff[1],buff[2],buff[3],buff[4],buff[5]);
//			printf("gx=%hd,gy=%hd,gz=%hd\r\n",gx,gy,gz);
//			Mx = (float)gx / 12000;
//			Mx = (float)gy / 12000;
//			Mx = (float)gz / 12000;
//			printf("Mx=%lf G; My=%lf G; Mz=%lf G;\r\n",Mx,My,Mz);
			//			QMC_Get_Magnetic(&mx,&my,&mz);
//			MPU_Get_Accelerometer(&mx,&my,&mz);
//			printf("tem=%d£¬tem1=%d\r\n",tem,tem1);
//			printf("mxyz=%d,%d,%d\r\n",mx,my,mz);
//			moter_1.Dir = (TIMER_CTL0(TIMER1) >>4 & 0x01);
//			moter_2.Dir = (TIMER_CTL0(TIMER2) >>4 & 0x01);
//			moter_3.Dir = (TIMER_CTL0(TIMER4) >>4 & 0x01);
//			moter_4.Dir = (TIMER_CTL0(TIMER3) >>4 & 0x01);
//			moter_1.Quadrature_Decode = TIMER_CNT(TIMER1);
//			moter_2.Quadrature_Decode  = TIMER_CNT(TIMER2);
//			moter_3.Quadrature_Decode  = TIMER_CNT(TIMER4);
//			moter_4.Quadrature_Decode  = TIMER_CNT(TIMER3);
//			printf("moter_1.Dir=%d;moter_2.Dir=%d;moter_3.Dir=%d;moter_4.Dir=%d\r\n",moter_1.Dir,moter_2.Dir,moter_3.Dir,moter_4.Dir);
//			printf("moter_1.Quadrature_Decode=%d;moter_2.Quadrature_Decode=%d;moter_3.Quadrature_Decode=%d;moter_4.Quadrature_Decode=%d\r\n",moter_1.Quadrature_Decode,moter_2.Quadrature_Decode,moter_3.Quadrature_Decode,moter_4.Quadrature_Decode);
//			printf("\r\n");
//			gpio_bit_write(GPIOB, GPIO_PIN_0,(bit_status)(1-gpio_input_bit_get(GPIOB,GPIO_PIN_0)));
//			gpio_bit_set(GPIOB,GPIO_PIN_0);
    }
}

/* retarget the C library printf function to the USART */
int fputc(int ch, FILE *f)
{
    usart_data_transmit(USART1, (uint8_t)ch);
    while(RESET == usart_flag_get(USART1, USART_FLAG_TBE));

    return ch;
}
