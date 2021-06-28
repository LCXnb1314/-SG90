#include "stm32f10x.h"                  // Device header



/**
  *@brief		��ʱ��3��PWN��������ͨ��4����ʼ��
	*@param		PSC:Ԥ��Ƶϵ��
	*@param		ARR:��װ��ֵ
	*@retval ��
	*/
void PWN_Init(u16 PSC,u16 ARR)
{
	//��ʼ��ʱ��
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOB,ENABLE);
	RCC_APB1PeriphClockCmd(RCC_APB1Periph_TIM3,ENABLE);
	
	//����GPIO����
	GPIO_InitTypeDef GPIO_InitStructure;
	GPIO_InitStructure.GPIO_Mode=GPIO_Mode_AF_PP;
	GPIO_InitStructure.GPIO_Pin=GPIO_Pin_1;
	GPIO_InitStructure.GPIO_Speed=GPIO_Speed_50MHz;
	GPIO_Init(GPIOB,&GPIO_InitStructure);
	
	//��ʱ����ʼ��
	TIM_TimeBaseInitTypeDef TIM_TimeBaseInitStructure;
	TIM_TimeBaseInitStructure.TIM_ClockDivision=0;
	TIM_TimeBaseInitStructure.TIM_CounterMode=TIM_CounterMode_Up;
	TIM_TimeBaseInitStructure.TIM_Period=ARR;
	TIM_TimeBaseInitStructure.TIM_Prescaler=PSC;
	TIM_TimeBaseInit(TIM3,&TIM_TimeBaseInitStructure);
	
	//��ʱ�����ͨ��4��ʼ��
	TIM_OCInitTypeDef TIM_OCInitStructure;
	TIM_OCInitStructure.TIM_OCMode=TIM_OCMode_PWM1;
	TIM_OCInitStructure.TIM_OCPolarity=TIM_OCPolarity_High;
	TIM_OCInitStructure.TIM_OutputState=TIM_OutputState_Enable;
	TIM_OCInitStructure.TIM_Pulse=75;//��ʼֵʹ�����90��λ��
	TIM_OC4Init(TIM3,&TIM_OCInitStructure);
	
	//ʹ��Ԥװ�ؼĴ���
	TIM_OC4PreloadConfig(TIM3,TIM_OCPreload_Enable);
	TIM_Cmd(TIM3,ENABLE);//ʹ�ܶ�ʱ��3
}
