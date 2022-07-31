/*
 * STD_types.h
 *
 *  Created on: July 29, 2022
 *      Author: John Atia Nafady
 */

#ifndef _STD_TYPES_H_
#define _STD_TYPES_H_

//#define inline __INLINE
//#define INLINE __INLINE
#define  NULL              	(void *)0
typedef unsigned char       uint8;
typedef unsigned short      uint16;
typedef unsigned int        uint32;

typedef signed char         sint8;
typedef signed short        sint16;
typedef signed int          sint32;

typedef float               float32;
typedef double              float64;

typedef enum
{
    STD_low=0,
    STD_high=!STD_low
}STD_levelType;

typedef enum
{
    STD_off=0,
    STD_on=!STD_off
}STD_BoolType;

typedef enum
{
    STD_Suspended=0,
    STD_Active=!STD_Suspended
}STD_StatusType;

typedef enum
{
    false=0,
    true=!false
}boolean;

typedef enum
{
    DISABLE=0,
    ENABLE=1
}STD_EnType;

typedef enum
{
    E_OK,
    E_NOT_OK
}Std_ReturnType;
typedef void(*Ptr2FuncType)(void);



#endif /* _STD_TYPES_H_ */
