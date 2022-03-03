#include "moter.h"

void moter_quadrature_decode_init(void)
{
	#if Enable_Moter_1_Quadrature_Decode
	timer1_configuration();
	#endif
	#if Enable_Moter_2_Quadrature_Decode
	timer2_configuration();
	#endif
	#if Enable_Moter_3_Quadrature_Decode
	timer3_configuration();
	#endif
	#if Enable_Moter_4_Quadrature_Decode
	timer4_configuration();
	#endif
}

void timer1_configuration(void)
{
 /* TIMER2 configuration: Quadrature Decode ------------------------

  ------------------------------------------------------------ */
	
    timer_ic_parameter_struct timer_icinitpara;
    timer_parameter_struct timer_initpara;
	
    rcu_periph_clock_enable(RCU_GPIOB);
		rcu_periph_clock_enable(RCU_GPIOA);
    rcu_periph_clock_enable(RCU_AF);
		rcu_periph_clock_enable(RCU_TIMER1);
	
//		gpio_pin_remap_config(GPIO_TIMER2_PARTIAL_REMAP, ENABLE);
    gpio_init(GPIOA,GPIO_MODE_IN_FLOATING,GPIO_OSPEED_50MHZ,GPIO_PIN_15);
		gpio_init(GPIOB,GPIO_MODE_IN_FLOATING,GPIO_OSPEED_50MHZ,GPIO_PIN_3);
		gpio_pin_remap_config(GPIO_TIMER1_FULL_REMAP, ENABLE);
	
    

    timer_deinit(TIMER1);
		timer_struct_para_init(&timer_initpara);
    /* TIMER2 configuration */
    timer_initpara.prescaler         = 0;
    timer_initpara.alignedmode       = TIMER_COUNTER_EDGE;
    timer_initpara.counterdirection  = TIMER_COUNTER_UP;
    timer_initpara.period            = 65535;
    timer_initpara.clockdivision     = TIMER_CKDIV_DIV1;
    timer_initpara.repetitioncounter = 0;
    timer_init(TIMER1,&timer_initpara);

//    timer_icinitpara.icpolarity  = TIMER_IC_POLARITY_RISING;
//    timer_icinitpara.icselection = TIMER_IC_SELECTION_DIRECTTI;
//    timer_icinitpara.icprescaler = TIMER_IC_PSC_DIV1;
//    timer_icinitpara.icfilter    = 0x00  ;
//    timer_input_capture_config(TIMER2,TIMER_CH_0,&timer_icinitpara);
//    timer_input_capture_config(TIMER2,TIMER_CH_1,&timer_icinitpara);
		
		timer_quadrature_decoder_mode_config(TIMER1,TIMER_ENCODER_MODE2,TIMER_IC_POLARITY_RISING,TIMER_IC_POLARITY_RISING);

////		timer_interrupt_flag_clear(TIMER2, TIMER_INT_FLAG_CH0);
////		timer_interrupt_flag_clear(TIMER2, TIMER_INT_FLAG_CH1);               
////		timer_interrupt_enable(TIMER2, TIMER_INT_UP);
////		timer_interrupt_enable(TIMER2, TIMER_INT_CH0 |TIMER_INT_CH1);      
		timer_autoreload_value_config(TIMER1,15000);
		timer_auto_reload_shadow_enable(TIMER1);
    /* TIMER2 counter enable */
    timer_enable(TIMER1);
}

void timer2_configuration(void)
{
 /* TIMER2 configuration: Quadrature Decode ------------------------

  ------------------------------------------------------------ */
	
    timer_ic_parameter_struct timer_icinitpara;
    timer_parameter_struct timer_initpara;
	
    rcu_periph_clock_enable(RCU_GPIOB);
    rcu_periph_clock_enable(RCU_AF);
		rcu_periph_clock_enable(RCU_TIMER2);
	
//		gpio_pin_remap_config(GPIO_TIMER2_PARTIAL_REMAP, ENABLE);
    gpio_init(GPIOB,GPIO_MODE_IN_FLOATING,GPIO_OSPEED_50MHZ,GPIO_PIN_4);
		gpio_init(GPIOB,GPIO_MODE_IN_FLOATING,GPIO_OSPEED_50MHZ,GPIO_PIN_5);
		gpio_pin_remap_config(GPIO_TIMER2_PARTIAL_REMAP, ENABLE);
	

    timer_deinit(TIMER2);
		timer_struct_para_init(&timer_initpara);
    /* TIMER2 configuration */
    timer_initpara.prescaler         = 0;
    timer_initpara.alignedmode       = TIMER_COUNTER_EDGE;
    timer_initpara.counterdirection  = TIMER_COUNTER_UP;
    timer_initpara.period            = 65535;
    timer_initpara.clockdivision     = TIMER_CKDIV_DIV1;
    timer_initpara.repetitioncounter = 0;
    timer_init(TIMER2,&timer_initpara);

//    timer_icinitpara.icpolarity  = TIMER_IC_POLARITY_RISING;
//    timer_icinitpara.icselection = TIMER_IC_SELECTION_DIRECTTI;
//    timer_icinitpara.icprescaler = TIMER_IC_PSC_DIV1;
//    timer_icinitpara.icfilter    = 0x00  ;
//    timer_input_capture_config(TIMER2,TIMER_CH_0,&timer_icinitpara);
//    timer_input_capture_config(TIMER2,TIMER_CH_1,&timer_icinitpara);
		
		timer_quadrature_decoder_mode_config(TIMER2,TIMER_ENCODER_MODE2,TIMER_IC_POLARITY_RISING,TIMER_IC_POLARITY_RISING);

////		timer_interrupt_flag_clear(TIMER2, TIMER_INT_FLAG_CH0);
////		timer_interrupt_flag_clear(TIMER2, TIMER_INT_FLAG_CH1);               
////		timer_interrupt_enable(TIMER2, TIMER_INT_UP);
////		timer_interrupt_enable(TIMER2, TIMER_INT_CH0 |TIMER_INT_CH1);      
		timer_autoreload_value_config(TIMER2,15000);
		timer_auto_reload_shadow_enable(TIMER2);
    /* TIMER2 counter enable */
    timer_enable(TIMER2);
}

void timer3_configuration(void)
{
 /* TIMER3 configuration: Quadrature Decode ------------------------

  ------------------------------------------------------------ */
	
    timer_ic_parameter_struct timer_icinitpara;
    timer_parameter_struct timer_initpara;
	
    rcu_periph_clock_enable(RCU_GPIOB);
    rcu_periph_clock_enable(RCU_AF);
		rcu_periph_clock_enable(RCU_TIMER3);

    gpio_init(GPIOB,GPIO_MODE_IN_FLOATING,GPIO_OSPEED_50MHZ,GPIO_PIN_6);
		gpio_init(GPIOB,GPIO_MODE_IN_FLOATING,GPIO_OSPEED_50MHZ,GPIO_PIN_7);
    

    timer_deinit(TIMER3);
		timer_struct_para_init(&timer_initpara);
    /* TIMER3 configuration */
    timer_initpara.prescaler         = 0;
    timer_initpara.alignedmode       = TIMER_COUNTER_EDGE;
    timer_initpara.counterdirection  = TIMER_COUNTER_UP;
    timer_initpara.period            = 65535;
    timer_initpara.clockdivision     = TIMER_CKDIV_DIV1;
    timer_initpara.repetitioncounter = 0;
    timer_init(TIMER3,&timer_initpara);
		
		timer_quadrature_decoder_mode_config(TIMER3,TIMER_ENCODER_MODE2,TIMER_IC_POLARITY_RISING,TIMER_IC_POLARITY_RISING);
  
		timer_autoreload_value_config(TIMER3,15000);
		timer_auto_reload_shadow_enable(TIMER3);
    /* TIMER3 counter enable */
    timer_enable(TIMER3);
}

void timer4_configuration(void)
{
 /* TIMER4 configuration: Quadrature Decode ------------------------
  ------------------------------------------------------------ */
	
    timer_ic_parameter_struct timer_icinitpara;
    timer_parameter_struct timer_initpara;
	
    rcu_periph_clock_enable(RCU_GPIOA);
    rcu_periph_clock_enable(RCU_AF);
		rcu_periph_clock_enable(RCU_TIMER4);

    gpio_init(GPIOA,GPIO_MODE_IN_FLOATING,GPIO_OSPEED_50MHZ,GPIO_PIN_0);
		gpio_init(GPIOA,GPIO_MODE_IN_FLOATING,GPIO_OSPEED_50MHZ,GPIO_PIN_1);
    

    timer_deinit(TIMER4);
		timer_struct_para_init(&timer_initpara);
    /* TIMER4 configuration */
    timer_initpara.prescaler         = 0;
    timer_initpara.alignedmode       = TIMER_COUNTER_EDGE;
    timer_initpara.counterdirection  = TIMER_COUNTER_UP;
    timer_initpara.period            = 65535;
    timer_initpara.clockdivision     = TIMER_CKDIV_DIV1;
    timer_initpara.repetitioncounter = 0;
    timer_init(TIMER4,&timer_initpara);
		
		timer_quadrature_decoder_mode_config(TIMER4,TIMER_ENCODER_MODE2,TIMER_IC_POLARITY_RISING,TIMER_IC_POLARITY_RISING);
  
		timer_autoreload_value_config(TIMER4,15000);
		timer_auto_reload_shadow_enable(TIMER4);
    /* TIMER4 counter enable */
    timer_enable(TIMER4);
}

void pwm_config(void)
{
		timer_oc_parameter_struct timer_ocintpara;
    timer_parameter_struct timer_initpara;
		rcu_periph_clock_enable(RCU_GPIOA);
    rcu_periph_clock_enable(RCU_GPIOB);
    rcu_periph_clock_enable(RCU_AF);
		rcu_periph_clock_enable(RCU_TIMER0);
		rcu_periph_clock_enable(RCU_TIMER11);
	
		gpio_init(GPIOB, GPIO_MODE_OUT_PP, GPIO_OSPEED_MAX,GPIO_PIN_8);
		gpio_init(GPIOB, GPIO_MODE_OUT_PP, GPIO_OSPEED_MAX,GPIO_PIN_9);
		gpio_init(GPIOB, GPIO_MODE_OUT_PP, GPIO_OSPEED_MAX,GPIO_PIN_12);
		gpio_init(GPIOA, GPIO_MODE_OUT_PP, GPIO_OSPEED_MAX,GPIO_PIN_12);
	

		gpio_init(GPIOA,GPIO_MODE_AF_PP,GPIO_OSPEED_MAX,GPIO_PIN_8);
		gpio_init(GPIOA,GPIO_MODE_AF_PP,GPIO_OSPEED_MAX,GPIO_PIN_11);
		gpio_init(GPIOB,GPIO_MODE_AF_PP,GPIO_OSPEED_MAX,GPIO_PIN_14);
    gpio_init(GPIOB,GPIO_MODE_AF_PP,GPIO_OSPEED_MAX,GPIO_PIN_15);

		timer_deinit(TIMER0);
		timer_deinit(TIMER11);

		timer_primary_output_config(TIMER0,ENABLE);
		
    /* TIMER0 configuration */
    timer_initpara.prescaler         = 119;
    timer_initpara.alignedmode       = TIMER_COUNTER_EDGE;
    timer_initpara.counterdirection  = TIMER_COUNTER_UP;
    timer_initpara.period            = 15999;
    timer_initpara.clockdivision     = TIMER_CKDIV_DIV1;
    timer_initpara.repetitioncounter = 0;
    timer_init(TIMER0,&timer_initpara);
	
    /* TIMER11 configuration */
    timer_initpara.prescaler         = 59;
    timer_initpara.alignedmode       = TIMER_COUNTER_EDGE;
    timer_initpara.counterdirection  = TIMER_COUNTER_UP;
    timer_initpara.period            = 15999;
    timer_initpara.clockdivision     = TIMER_CKDIV_DIV1;
    timer_initpara.repetitioncounter = 0;
    timer_init(TIMER11,&timer_initpara);

    /* CH0,CH1 and CH2 configuration in PWM mode */
    timer_ocintpara.outputstate  = TIMER_CCX_ENABLE;
    timer_ocintpara.outputnstate = TIMER_CCXN_DISABLE;
    timer_ocintpara.ocpolarity   = TIMER_OC_POLARITY_HIGH;
    timer_ocintpara.ocnpolarity  = TIMER_OCN_POLARITY_HIGH;
    timer_ocintpara.ocidlestate  = TIMER_OC_IDLE_STATE_LOW;
    timer_ocintpara.ocnidlestate = TIMER_OCN_IDLE_STATE_LOW;
		
		timer_channel_output_config(TIMER0,TIMER_CH_0,&timer_ocintpara);
		timer_channel_output_config(TIMER0,TIMER_CH_3,&timer_ocintpara);
		timer_channel_output_config(TIMER11,TIMER_CH_0,&timer_ocintpara);
    timer_channel_output_config(TIMER11,TIMER_CH_1,&timer_ocintpara);

    /* CH0 configuration in PWM mode0,duty cycle 25% */
    timer_channel_output_pulse_value_config(TIMER0,TIMER_CH_0,3999);
    timer_channel_output_mode_config(TIMER0,TIMER_CH_0,TIMER_OC_MODE_PWM0);
    timer_channel_output_shadow_config(TIMER0,TIMER_CH_0,TIMER_OC_SHADOW_DISABLE);
		
    /* CH3 configuration in PWM mode0,duty cycle 25% */
    timer_channel_output_pulse_value_config(TIMER0,TIMER_CH_3,3999);
    timer_channel_output_mode_config(TIMER0,TIMER_CH_3,TIMER_OC_MODE_PWM0);
    timer_channel_output_shadow_config(TIMER0,TIMER_CH_3,TIMER_OC_SHADOW_DISABLE);

		/* CH0 configuration in PWM mode0,duty cycle 25% */
    timer_channel_output_pulse_value_config(TIMER11,TIMER_CH_0,3999);
    timer_channel_output_mode_config(TIMER11,TIMER_CH_0,TIMER_OC_MODE_PWM0);
    timer_channel_output_shadow_config(TIMER11,TIMER_CH_0,TIMER_OC_SHADOW_DISABLE);
		
    /* CH1 configuration in PWM mode0,duty cycle 25% */
    timer_channel_output_pulse_value_config(TIMER11,TIMER_CH_1,3999);
    timer_channel_output_mode_config(TIMER11,TIMER_CH_1,TIMER_OC_MODE_PWM0);
    timer_channel_output_shadow_config(TIMER11,TIMER_CH_1,TIMER_OC_SHADOW_DISABLE);

    /* auto-reload preload enable */
		timer_auto_reload_shadow_enable(TIMER0);
    timer_auto_reload_shadow_enable(TIMER11);
    /* auto-reload preload enable */
		timer_enable(TIMER0);
    timer_enable(TIMER11);
}


