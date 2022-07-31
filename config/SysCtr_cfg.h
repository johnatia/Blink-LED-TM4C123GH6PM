/*
 * SysCtr_cfg.h
 *
 *  Created on: July 29, 2022
 *      Author: John Atia Nafady
 */

#ifndef _SYSCTR_CFG_H_
#define _SYSCTR_CFG_H_

#define SYSCTR_RCC_GPIO_PORTA                     ENABLE
#define SYSCTR_RCC_GPIO_PORTB                     ENABLE
#define SYSCTR_RCC_GPIO_PORTC                     ENABLE
#define SYSCTR_RCC_GPIO_PORTD                     ENABLE
#define SYSCTR_RCC_GPIO_PORTE                     ENABLE
#define SYSCTR_RCC_GPIO_PORTF                     ENABLE

#define SYSCTR_RCC_UART0                          DISABLE
#define SYSCTR_RCC_UART1                          DISABLE
#define SYSCTR_RCC_UART2                          DISABLE
#define SYSCTR_RCC_UART3                          DISABLE
#define SYSCTR_RCC_UART4                          DISABLE
#define SYSCTR_RCC_UART5                          DISABLE
#define SYSCTR_RCC_UART6                          DISABLE
#define SYSCTR_RCC_UART7                          DISABLE

#define SYSCTR_RCC_SSI0                           ENABLE
#define SYSCTR_RCC_SSI1                           DISABLE
#define SYSCTR_RCC_SSI2                           DISABLE
#define SYSCTR_RCC_SSI3                           ENABLE
                          
#define SYSCTR_RCC_I2C0                           ENABLE
#define SYSCTR_RCC_I2C1                           ENABLE
#define SYSCTR_RCC_I2C2                           DISABLE
#define SYSCTR_RCC_I2C3                           DISABLE

#define SYSCTR_RCC_TIMER0													ENABLE
#define SYSCTR_RCC_TIMER1													ENABLE
#define SYSCTR_RCC_TIMER2													ENABLE
#define SYSCTR_RCC_TIMER3													DISABLE
#define SYSCTR_RCC_TIMER4													DISABLE

#define SYSCTR_RCC_WTIMER0												ENABLE
#define SYSCTR_RCC_WTIMER1												ENABLE
#define SYSCTR_RCC_WTIMER2												ENABLE
#define SYSCTR_RCC_WTIMER3												DISABLE
#define SYSCTR_RCC_WTIMER4												DISABLE

#endif /* _SYSCTR_CFG_H_ */
