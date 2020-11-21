/******************************************************************/
/* Author         : SAYED ELROUBY                                 */
/* Date           : 19 Aug 2020                                   */
/* Version        : V1                                            */
/* Type Of Driver : LED                                           */
/******************************************************************/
#include"STD_TYPES.h"
#include "BIT_MATH.h"

#include"RCC_interface.h"
#include"GPIO_interface.h"
#include "LED_interface.h"
#include "LED_config.h"
#include "LED_private.h"


void LED_VoidLedOn(u8 Copy_Port, u8 Copy_Pin)
{
		#if    LED_SPEEP_OUT ==OUT_2MHZ
		      GPIO_VoidSetPinDirectionModeCNF(Copy_Port,Copy_Pin ,OUTPUT_2MHZ_PUSHPULL);
			  GPIO_VoidSetPinLevel( Copy_Port,  Copy_Pin ,HIGH);
		#elif  LED_SPEEP_OUT ==OUT_10MHZ
		      GPIO_VoidSetPinDirectionModeCNF(Copy_Port,Copy_Pin ,OUTPUT_10MHZ_PUSHPULL);
			  GPIO_VoidSetPinLevel( Copy_Port,  Copy_Pin ,HIGH);
		#elif  LED_SPEEP_OUT ==OUT_50MHZ
		      GPIO_VoidSetPinDirectionModeCNF(Copy_Port,Copy_Pin ,OUTPUT_50MHZ_PUSHPULL);
			  GPIO_VoidSetPinLevel( Copy_Port,  Copy_Pin ,HIGH);
		
        #endif
}
void LED_VoidLedOff(u8 Copy_Port, u8 Copy_Pin)
{
	    #if    LED_SPEEP_OUT ==OUT_2MHZ
		      GPIO_VoidSetPinDirectionModeCNF(Copy_Port,Copy_Pin ,OUTPUT_2MHZ_PUSHPULL);
			  GPIO_VoidSetPinLevel( Copy_Port,  Copy_Pin ,LOW);
		#elif  LED_SPEEP_OUT ==OUT_10MHZ
		      GPIO_VoidSetPinDirectionModeCNF(Copy_Port,Copy_Pin ,OUTPUT_10MHZ_PUSHPULL);
			  GPIO_VoidSetPinLevel( Copy_Port,  Copy_Pin ,LOW);
		#elif  LED_SPEEP_OUT ==OUT_50MHZ
		      GPIO_VoidSetPinDirectionModeCNF(Copy_Port,Copy_Pin ,OUTPUT_50MHZ_PUSHPULL);
			  GPIO_VoidSetPinLevel( Copy_Port,  Copy_Pin ,LOW);
		
        #endif
}
void LED_VoidLedToggle(u8 Copy_Port, u8 Copy_Pin)
{
		#if    LED_SPEEP_OUT ==OUT_2MHZ
		      GPIO_VoidSetPinDirectionModeCNF(Copy_Port,Copy_Pin ,OUTPUT_2MHZ_PUSHPULL);
			  GPIO_VoidTogglePinValue(Copy_Port, Copy_Pin);
		#elif  LED_SPEEP_OUT ==OUT_10MHZ
		      GPIO_VoidSetPinDirectionModeCNF(Copy_Port,Copy_Pin ,OUTPUT_10MHZ_PUSHPULL);
			  GPIO_VoidTogglePinValue(Copy_Port, Copy_Pin);
		#elif  LED_SPEEP_OUT ==OUT_50MHZ
		      GPIO_VoidSetPinDirectionModeCNF(Copy_Port,Copy_Pin ,OUTPUT_50MHZ_PUSHPULL);
			  GPIO_VoidTogglePinValue(Copy_Port, Copy_Pin);
		
        #endif
   	
}
