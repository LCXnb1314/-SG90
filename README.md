# SG90
基于stm32f103zet6
# 原理

//型号：SG90

//信号线（橙色）：PB1

//电源线（红色）：+5V

//地线（棕色）：GND

//周期=（PSC+1）*（ARR+1）/72000000




/**

  *舵机控制一般需要一个20ms左右的时基脉冲，该脉冲的高电平
  
	*部分一般为0.5ms-2.5ms范围内的角度控制脉冲部分，总间隔
	
	*2ms。以180度角度伺服为例，对应控制关系如下：
	
	*        0.5ms---------  -90度
	
	*        1.0ms---------  -45度
	
	*        1.5ms---------   0 度
	
	*        2.0ms---------   45度
	
	*        2.5ms---------   90度
	
	*/
	
