/*
 * nvic_cfg.h
 *
 *  Created on: July 29, 2022
 *      Author: John Atia Nafady
 */

#ifndef _CONFIG_NVIC_CFG_H_
#define _NVIC_CFG_H_

#include "../common/STD_types.h"


#define GPIO_PORTA_NVIC     DISABLE 
#define GPIO_PORTB_NVIC     DISABLE 
#define GPIO_PORTC_NVIC     DISABLE 
#define GPIO_PORTD_NVIC     DISABLE 
#define GPIO_PORTE_NVIC     DISABLE 
#define GPIO_PORTF_NVIC     DISABLE 

#define UART0_NVIC          DISABLE 
#define UART1_NVIC          DISABLE 
#define UART2_NVIC          DISABLE 
#define UART3_NVIC          DISABLE 
#define UART4_NVIC          DISABLE 
#define UART5_NVIC          DISABLE 
#define UART6_NVIC          DISABLE 
#define UART7_NVIC          DISABLE 

#define SPI0_NVIC           DISABLE 
#define SPI1_NVIC           DISABLE 
#define SPI2_NVIC           DISABLE 
#define SPI3_NVIC           DISABLE 

#define I2C0_NVIC           DISABLE 
#define I2C1_NVIC           DISABLE 
#define I2C2_NVIC           DISABLE 
#define I2C3_NVIC           DISABLE 

#define WATCHDOG_T0_T1      DISABLE 

#define	TIMER0A_NVIC				ENABLE
#define	TIMER0B_NVIC				ENABLE
#define	TIMER1A_NVIC				ENABLE
#define	TIMER1B_NVIC				ENABLE
#define	TIMER2A_NVIC				ENABLE
#define	TIMER2B_NVIC				ENABLE

#endif /* _NVIC_CFG_H_ */
