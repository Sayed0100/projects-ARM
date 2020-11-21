/*
 * main.c
 *
 *  Created on: ??þ/??þ/????
 *      Author: Administrator
 */

#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "RCC_interface.h"
#include "GPIO_interface.h"
#include "NVIC_interface.h"
#include "STK_interface.h"
#include "EXTI_interface.h"
#include "AFIO_interface.h"

#include "LEDMREX_interface.h"
#include "LED_interface.h"
#include "SEVENSEG_interface.h"


int main()
{
	u8 Arr[12][8]={ {0,0,0,0,0,0,0,38},{0,0,0,0,0,0,38,73},{0,0,0,0,0,38,73,73},
			     {0, 0, 0, 38, 73, 73, 73, 50},{0, 0, 38, 73, 73, 73, 50, 0},
				  { 0, 38, 73, 73, 73, 50, 0,0}  ,{38, 73, 73, 73, 50, 0,0,0},
				  { 73, 73, 73, 50,0,0, 0,0},{73, 73, 50,0,0, 0,0},{ 73, 50, 0,0,0,0, 0,0},
	              { 50,0, 0,0,0,0, 0,0} ,{ 0, 0, 0,0,0,0, 0,0} };

 RCC_VoidInitSysClock();
/*Enable clock on GPIOA*/
 RCC_VoidEnableClock(RCC_APB2,2);
/*EnableClock On GPIOB*/
 RCC_VoidEnableClock(RCC_APB2,3);

 STK_VoidInit();

 LEDMREX_VoidIntit();


	while(1)
	{
		for(u8 i=0;i<12 ;i++)
		{
			for(int u=0;u<8; u++)
			{
				for(u8 x=0;x<100;x++)
			   LEDMREX_VoidDisplay((*(Arr + i) + u));
			}
		}


	}
return 0;
}

