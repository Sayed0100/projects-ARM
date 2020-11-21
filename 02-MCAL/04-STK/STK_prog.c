/******************************************************************/
/* Author         : SAYED ELROUBY                                 */
/* Date           : 12 Sep 2020                                   */
/* Version        : V1                                            */
/* Type Of Driver : STK  24 BIT SYSTEM TIMER,COUNT DAWON          */
/******************************************************************/

#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include "STK_interface.h"
#include "STK_private.h"
#include "STK_config.h"


void (*Callback_Ptr)(void);
u8 Read_u8Flag;
u8 Single_u8Flag;

void STK_VoidInit(void)
{
	#if   CLOCK_OF_TIMER == AHB
	  STK_CTRL = 0x00000004;
	#elif CLOCK_OF_TIMER == AHB_div_8
	  STK_CTRL = 0x00000000;
	  
	#endif
}

void STK_VoidBusyWait(u32 Copy_32NumCount)
{ 
    STK_LOAD = Copy_32NumCount;
	STK_CTRL|= 1; /* set STK enable ,  disable interrupt */
	while(GET_BIT(STK_CTRL,16) == 0);/* polling until finish count */
	Read_u8Flag=GET_BIT(STK_CTRL,16);/* clear flag by read */
}

void STK_VoidIntervalSingle(u32 Copy_32NumCount, void (*Copy_PtrFunc) (void))
{   
    STK_LOAD  = Copy_32NumCount;
	STK_CTRL|=3;/* set STK enable , set bit interrupt */
	Callback_Ptr = Copy_PtrFunc;
	Single_u8Flag=1;
	
}

void STK_VoidIntervalPeriodic(u32 Copy_32NumCount, void (*Copy_PtrFunc) (void))
{   
    STK_LOAD  = Copy_32NumCount;
  	STK_CTRL|=3;/* set STK enable , set bit interrupt */
	Callback_Ptr = Copy_PtrFunc;
}

void STK_VoidStopTimer(void)
{
      STK_CTRL &=~3;
}

u32 STk_u32GetElapsedTime(void);
{
	  return STK_LOAD-STK_VAL;
}


u32 STK_u32GetReminingTime(void)
{
	return STK_VAL;
}


void SysTick_Handler(void)
{
  Callback_Ptr();
	if(Single_u8Flag == 1)
	{
      Single_u8Flag=0;
      STK_CTRL &=~3;  /*STOP Timer */	  
	}
  Read_u8Flag=GET_BIT(STK_CTRL,16);/* clear flag by read */
}
