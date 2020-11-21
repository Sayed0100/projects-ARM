/******************************************************************/
/* Author         : SAYED ELROUBY                                 */
/* Date           : 17 sep 2020                                   */
/* Version        : V1                                            */
/* Type Of Driver : EXTI                                          */
/******************************************************************/

#ifndef  EXTI_PRIVATE_H
#define  EXTI_PRIVATE_H

typedef struct EXTI_REG
{
	volatile u32 EXTI_IMR; /* select line (PIE) */
	volatile u32 EXTI_EMR; 
	volatile u32 EXTI_RTSR; 
	volatile u32 EXTI_FTSR;
	volatile u32 EXTI_SWIER;
	volatile u32 EXTI_PR;
}EXTI_Type;

#define EXTI_PTR    ((volatile EXTI_Type*)0x40010400)

#endif