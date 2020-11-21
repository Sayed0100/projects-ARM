/******************************************************************/
/* Author         : SAYED ELROUBY                                 */
/* Date           : 17 sep 2020                                   */
/* Version        : V1                                            */
/* Type Of Driver : EXTI                                          */
/******************************************************************/
#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "EXTI_interface.h"
#include "EXTI_config.h"
#include "EXTI_private.h"

void (*EXTI_CallBack)(void);

void EXTI_VoidEnableLine(u8 Copy_Line)
{
	if(Copy_Line<=15)
	{
			SET_BIT(EXTI_PTR -> EXTI_IMR , Copy_Line)
	}
	else
	{
		/*return error */
	}
}

void EXTI_VoidDisableLine(u8 Copy_Line)
{
    if(Copy_Line<=15)
	{
			CLR_BIT(EXTI_PTR -> EXTI_IMR , Copy_Line)
	}
	else
	{
		/*return error */
	}
}

/* Options : RISING
            FALLING
			ANY_CHANGE  On Line */
void EXTI_VoidSenseModeLine(u8 Copy_Mode, u8 Copy_Line , void (*EXTI_GPtr)(void))
{
	switch(Copy_Mode)
	{
		case RISING     : SET_BIT(EXTI_PTR -> EXTI_RTSR	,Copy_Line);break;
		case FALLING    : SET_BIT(EXTI_PTR -> EXTI_FTSR	,Copy_Line);break;
		
		case ANY_CHANGE : SET_BIT(EXTI_PTR -> EXTI_RTSR	,Copy_Line);
		                  SET_BIT(EXTI_PTR -> EXTI_FTSR	,Copy_Line);break;
	}
	EXTI_CallBack=EXTI_GPtr;
}
/* This API makes Enable for PIF Of Linex In Any Time */
void EXTI_VoidSwExternlInterrupt(u8 Copy_Line)
{
	SET_BIT(EXTI_PTR -> SWIER , Copy_Line);
}


void EXTI0_IRQHandler(void)
{
	EXTI_CallBack();
	SET_BIT(EXTI_PTR -> EXTI_PR ,LINE0); /*clear flag by write 1 on it */
}
void EXTI1_IRQHandler(void)
{
	EXTI_CallBack();
	SET_BIT(EXTI_PTR -> EXTI_PR ,LINE1); /*clear flag by write 1 on it */
}
void EXTI2_IRQHandler(void)
{
	EXTI_CallBack();
	SET_BIT(EXTI_PTR -> EXTI_PR ,LINE2); /*clear flag by write 1 on it */
}
void EXTI3_IRQHandler(void)
{
	EXTI_CallBack();
	SET_BIT(EXTI_PTR -> EXTI_PR ,LINE3); /*clear flag by write 1 on it */
}
void EXTI4_IRQHandler(void)
{
	EXTI_CallBack();
	SET_BIT(EXTI_PTR -> EXTI_PR ,LINE4); /*clear flag by write 1 on it */
}

void EXTI9_5_IRQHandler(void)
{
	EXTI_CallBack();
	EXTI_PTR -> EXTI_PR|=(11111<<5);/*clear flag from bit 5--> 9 */
}
void EXTI15_10_IRQHandler(void)
{
	EXTI_CallBack();
	EXTI_PTR -> EXTI_PR|=(11111<<10);/*clear flag from bit 10--> 15 */
}