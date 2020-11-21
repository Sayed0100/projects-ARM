/******************************************************************/
/* Author         : SAYED ELROUBY                                 */
/* Date           : 28 Aug 2020                                   */
/* Version        : V1                                            */
/* Type Of Driver : NVIC                                          */
/******************************************************************/

#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include"NVIC_interface.h"
#include"NVIC_private.h"
#include"NVIC_config.h"


void NVIC_VoidEnableExInterrupt(u8 Copy_u8NumberInt)
 { 
	 if(Copy_u8NumberInt<=31)
	 {
		 NVIC_ISER0=(1<<Copy_u8NumberInt);
	 }
	 else if(Copy_u8NumberInt<=59)
	 {
		 NVIC_ISER1=(1<<Copy_u8NumberInt);
	 }
 }
void NVIC_VoidDisableExInterrupt(u8 Copy_u8NumberInt)
{
	 if(Copy_u8NumberInt<=31)
	 {
		 NVIC_ICER0=(1<<Copy_u8NumberInt);
	 }
	 else if(Copy_u8NumberInt<=59)
	 {
		 NVIC_ICER1=(1<<Copy_u8NumberInt);
	 }
}

 void NVIC_VoidSetPendingExInterrupt(u8 Copy_u8NumberInt)
 {
	  if(Copy_u8NumberInt<=31)
	 {
		 NVIC_ISPR0=(1<<Copy_u8NumberInt);
	 }
	 else if(Copy_u8NumberInt<=59)
	 {
		 NVIC_ISPR1=(1<<Copy_u8NumberInt);
	 }
 }
 void NVIC_VoidClearPendingExInterrupt(u8 Copy_u8NumberInt)
 {
	  if(Copy_u8NumberInt<=31)
	 {
		 NVIC_ICPR0=(1<<Copy_u8NumberInt);
	 }
	 else if(Copy_u8NumberInt<=59)
	 {
		 NVIC_ICPR1=(1<<Copy_u8NumberInt);
	 }
 }

 u8 NVIC_u8ReadActiveFlagInterrupt(u8 Copy_u8NumberInt)
 {
	 u8 Local_u8Result=0;
	  if(Copy_u8NumberInt<=31)
	 {
		 Local_u8Result = GET_BIT(NVIC_IABR0  , Copy_u8NumberInt);
	 }
	 else if(Copy_u8NumberInt<=59)
	 {
		 Local_u8Result = GET_BIT(NVIC_IABR1  , Copy_u8NumberInt);
	 }
	 return Local_u8Result;
 }

 void NVIC_voidInit(void)
 {
	 #define SCB_AIRCR *((volatile u32*)0xE000ED00+0x0C)
	 SCB_AIRCR=NUM_GROUP_SUB;
 }
               
 void NVIC_SetPriority(u8 Copy_u8PeripheralIndexHW,u8 Copy_u8Group,u8 Copy_u8Sub)
 {
    if (Copy_u8PeripheralIndexHW <= 59 )
	{
		/*0 bit group 4 bit sub */
		#if   NUM_GROUP_SUB == 0_GROUP_16_SUB	
		NVIC_IPR[Copy_u8PeripheralIndexHW]=(Copy_u8Sub << 4);
		
		/*1 bit group 3 bit sub */
		#elif NUM_GROUP_SUB == 2_GROUP_8_SUB
		NVIC_IPR[Copy_u8PeripheralIndexHW]=( Copy_u8Sub|(Copy_u8Group<<3) )<<4;
		
		/*2 bit group 2 bit sub */
		#elif NUM_GROUP_SUB == 4_GROUP_4_SUB
		NVIC_IPR[Copy_u8PeripheralIndexHW]=( Copy_u8Sub|(Copy_u8Group<<2) )<<4;
		
		/* 3 bit group 1 bit sub */
		#elif NUM_GROUP_SUB == 8_GROUP_2_SUB
		NVIC_IPR[Copy_u8PeripheralIndexHW]=( Copy_u8Sub|(Copy_u8Group<<1) )<<4;
		
		/*4 bit group 0 bit sub */
		#elif NUM_GROUP_SUB == 16_GROUP_0_SUB
		NVIC_IPR[Copy_u8PeripheralIndexHW]=(Copy_u8Group<<4);
		
		#endif
	}  
	else
	{
		/* Return Error */
	}
 }