                                                                                        /*
 * global_interrupt.h
 *
 *  Created on: July 29, 2022
 *      Author: John Atia Nafady
 */

#ifndef _GLOBAL_INTERRUPT_H_
#define _GLOBAL_INTERRUPT_H_

#define GI_ENABLE()             __asm("cpsie   i\n");
#define GI_DISABLE()            __asm("cpsid   i\n");

#endif /* _GLOBAL_INTERRUPT_H_ */
