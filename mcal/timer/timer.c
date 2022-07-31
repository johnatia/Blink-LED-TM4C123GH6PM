/*
 *	timer.c
 *  Created on: July 29, 2022
 *      Author: John Atia Nafady
 */
#include "timer.h"

PFN_TimerCallback timer_callback[6];
// This array is a look up table to resolve the timer block name to its base address.
const volatile TimerRegs_t * TimerBaseAddress[TIMER_MAX_BLOCKS] = {
	TIMER0_REG_BASE,
	TIMER1_REG_BASE,
	TIMER2_REG_BASE,
	TIMER3_REG_BASE,
	TIMER4_REG_BASE,
	TIMER5_REG_BASE
};

void Timer_Wait(TimerBlock_t block, uint32 count, uint32 interval)
{	
	volatile TimerRegs_t* timer = (volatile TimerRegs_t*)TimerBaseAddress[block];
	uint32 i;
	for (i = 0; i < count; i++) 
	{
		Timer_Start(block, interval);
		// Wait for the time-out raw interrupt bit to be set.
		while ((timer->RIS & 0x1) == 0);
		// Clear the raw interrupt flag.
		timer->ICR = 0x1;
	}
}


int Timer_Init(TimerBlock_t block, TimerMode_t mode, PFN_TimerCallback callback)
{
	volatile TimerRegs_t* timer = (volatile TimerRegs_t*)TimerBaseAddress[block];	
	// Disable while configuring.
	timer->CTL = 0;
	timer->CFG = 0;	/* 32-bit option */
	//timer->CFG = 0x04;	/* 16-bit option */
	// D1:D0 bits: 0x02 periodic, 0x01 one shot.
	timer->TAMR = (mode == TIMER_PERIODIC) ? TIMER_TAMR_TAMR_PERIOD : TIMER_TAMR_TAMR_1_SHOT;
//	timer->TAMR = 0x02;
	// No scaler
	//timer->TAPR = 16000-1;

	// Clear timeout flag
	//timer->ICR = TIMER_ICR_TATOCINT;
	
	if (!callback) 
	{
		// Disable timeout interrupt
		timer->IMR = 0;
	}
	else 
	{
		timer->IMR = 0x1;			// Enable timeout interrupt
		timer_callback[block] = callback;
	}
	return 0;
}	


int Timer_Start(TimerBlock_t block, uint32 interval)
{
	volatile TimerRegs_t* timer = (volatile TimerRegs_t*)TimerBaseAddress[block];
	
	// Disable while configuring.
	timer->CTL = 0;

	// Load interval register
	timer->TAILR = interval - 1;

	// Clear timeout flag
	timer->ICR = TIMER_ICR_TATOCINT;
	
	// Enable timer
//	timer->CTL |= TIMER_CTL_TAEN;
		timer->CTL |= 0x01;
		
	return 0;
}	


void Timer_Stop(TimerBlock_t block)
{	
	volatile TimerRegs_t* timer = (volatile TimerRegs_t*)TimerBaseAddress[block];	
	timer->CTL = 0;
}

/*
int Timer_EnableInputCounter(TimerBlock_t block, PinDef_t pinDef)
{
	// TODO:  The input counter functions have not been tested since refactored for the 1294.
	
	int retVal = 0;
	
#if (halCONFIG_1294 == 1)
	uint8_t ctl = 0x3;
#else	// TM4C123
	uint8_t ctl = 0x7;
#endif
	
	switch (block) {

#if (halUSE_TIMER1 == 1)
		case TIMER1:
			SYSCTL_RCGCTIMER_R |= 2;	
			break;
#endif
	
#if (halUSE_TIMER2 == 1)		
		case TIMER2:
			SYSCTL_RCGCTIMER_R |= 4;	
			break;
#endif
		
		default:
			// TODO: Implement other timers as needed.
			abort();
			retVal = -1;
	}
	
	if (retVal == 0) {
		GPIO_EnableAltDigital(pinDef.port, pinDef.pin, ctl, false);
	}
	
	return retVal;
}	
*/

void Timer_ResetInputCounter(TimerBlock_t block)
{
	// NOTE:  Assumes that the timer has been already been initialized!
	// TODO:  The input counter functions have not been tested since refactored for the 1294.
	
	volatile TimerRegs_t* timer = (volatile TimerRegs_t*)TimerBaseAddress[block];
	
	// Disable while configuring.  This also sets the TAEVENT bits to 0 for rising edge trigger.
	timer->CTL = 0;

	// 16-bit mode.
	timer->CFG = 4;

	// up-count, edge-count, capture mode
	timer->TAMR = 0x13;

	// Set the count limit in the match and pre-scale match registers for a 24-bit limit.
	timer->TAMATCHR = 0xFFFF;
	timer->TAPMR = 0xFF;
	
	// Clear the value.
	timer->TAV = 0;
	
#if (halCONFIG_1294 != 1)	// TM4C123
	timer->TAPV = 0;
#endif 

	// Enable timer
	timer->CTL |= 0x01;
	
}

uint32 Timer_ReadCounterValue(TimerBlock_t block)
{
	volatile TimerRegs_t* timer = (volatile TimerRegs_t*)TimerBaseAddress[block];
	volatile uint32 count = 0x00FFFFFF & ((timer->TAPR << 16) | timer->TAR);
	return count; 
}

void TIMER0A_Handler()
{	
	// Clear the timer timeout flag.
	timer_callback[0]();
	TIMER0_REG_BASE->ICR = 0x1;

}
void TIMER1A_Handler()
{	
	// Clear the timer timeout flag.
	timer_callback[1]();
	TIMER1_REG_BASE->ICR = 0x1;

}
void TIMER2A_Handler()
{	
	// Clear the timer timeout flag.
	timer_callback[2]();
	TIMER2_REG_BASE->ICR = 0x1;

}
void TIMER3A_Handler()
{	
	// Clear the timer timeout flag.
	timer_callback[3]();
	TIMER3_REG_BASE->ICR = 0x1;

}
void TIMER4A_Handler()
{	
	// Clear the timer timeout flag.
	timer_callback[4]();
	TIMER4_REG_BASE->ICR = 0x1;

}
void TIMER5A_Handler()
{	
	// Clear the timer timeout flag.
	timer_callback[5]();
	TIMER5_REG_BASE->ICR = 0x1;

}
#ifdef IRQ_HANDLER_DEFINED
// Generic handler (called by the interrupt handlers) which clears the interrupt flags 
//	and invokes the user callback as needed.
static void HandleInterrupt(volatile TimerRegs_t* timer, PFN_TimerCallback callback)
{
	volatile int readback;

	if (timer->MIS & 0x1) {
		
		// Clear the timer timeout flag.
		timer->ICR = 0x1;
		
		// Read to force clearing of the interrupt flag.
		readback = timer->ICR;
		
		// Invoke the call back if registered.
		if (callback) {
			callback();
		}

	}
	else {
		
		// Shoudn't get here, but just in case...
		timer->ICR = timer->MIS;
		readback = timer->ICR;

	}
}
#endif