/*
 * main.c
 *
 *  Created on: July 29, 2022
 *      Author: John Atia Nafady
 */
#include "../common/STD_Types.h"
#include "../common/Bit_Math.h"
#include "../mcal/sys_ctr/SysCtr.h"
#include "../mcal/sys_ctr/global_interrupt.h"
#include "../mcal/port_driver/port.h"
#include "../mcal/dio/dio.h"
#include "../mcal/timer/timer.h"

#define MAIN_CPU_FREQ		16000000UL
void ChangeBlinkTime(void)
{
	static uint8 count = 0;
	switch(count)
	{
		case 0:
				Timer_Stop(TIMER0);
				Timer_Start(TIMER0, 1* MAIN_CPU_FREQ);
				count = 1;
			break;
		
		case 1:
				Timer_Stop(TIMER0);
				Timer_Start(TIMER0, 3 * MAIN_CPU_FREQ);
				count = 0;
			break;
	}

}
void BlinkLED(void)
{
		Dio_WriteChannel(Dio_Channel_F0, !Dio_ReadChannel(Dio_Channel_F0));
    Dio_WriteChannel(Dio_Channel_F1, !Dio_ReadChannel(Dio_Channel_F1));
    Dio_WriteChannel(Dio_Channel_F2, !Dio_ReadChannel(Dio_Channel_F2));
}


int main(void)
{
    SysCtr_init();
		NVIC_init();
    PORT_init();
		Timer_Init(TIMER0, TIMER_PERIODIC,  BlinkLED) ;
		//Timer_Init(TIMER1, TIMER_PERIODIC,  ChangeBlinkTime) ;

		GI_ENABLE();
		Timer_Start(TIMER0, 1 * MAIN_CPU_FREQ);
		//Timer_Start(TIMER1, 5 * MAIN_CPU_FREQ);
	while(1)
	{}
}


