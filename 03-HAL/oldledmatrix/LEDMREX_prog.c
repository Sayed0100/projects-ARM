/******************************************************************/
/* Author         : SAYED ELROUBY                                 */
/* Date           : 23 sep 2020                                   */
/* Version        : V1                                            */
/* Type Of Driver : LED MATRIEX                                   */
/******************************************************************/
#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "GPIO_interface.h"
#include "STK_interface.h"

#include "LEDMREX_interface.h"
#include "LEDMREX_config.h"
#include "LEDMREX_private.h"

void LEDMREX_VoidIntit(void)
{
	/*Make Rows Output*/
	
	GPIO_VoidSetPinDirectionModeCNF(LEDMREX_ROW0_PIN,OUTPUT_2MHZ_PUSHPULL);
	GPIO_VoidSetPinDirectionModeCNF(LEDMREX_ROW1_PIN,OUTPUT_2MHZ_PUSHPULL);
	GPIO_VoidSetPinDirectionModeCNF(LEDMREX_ROW2_PIN,OUTPUT_2MHZ_PUSHPULL);
	GPIO_VoidSetPinDirectionModeCNF(LEDMREX_ROW3_PIN,OUTPUT_2MHZ_PUSHPULL);
	GPIO_VoidSetPinDirectionModeCNF(LEDMREX_ROW4_PIN,OUTPUT_2MHZ_PUSHPULL);
	GPIO_VoidSetPinDirectionModeCNF(LEDMREX_ROW5_PIN,OUTPUT_2MHZ_PUSHPULL);
	GPIO_VoidSetPinDirectionModeCNF(LEDMREX_ROW6_PIN,OUTPUT_2MHZ_PUSHPULL);
	GPIO_VoidSetPinDirectionModeCNF(LEDMREX_ROW7_PIN,OUTPUT_2MHZ_PUSHPULL);
/*MAKE COL OUTPUT*/
	GPIO_VoidSetPinDirectionModeCNF(LEDMREX_COL0_PIN,OUTPUT_2MHZ_PUSHPULL);
	GPIO_VoidSetPinDirectionModeCNF(LEDMREX_COL1_PIN,OUTPUT_2MHZ_PUSHPULL);
	GPIO_VoidSetPinDirectionModeCNF(LEDMREX_COL2_PIN,OUTPUT_2MHZ_PUSHPULL);
	GPIO_VoidSetPinDirectionModeCNF(LEDMREX_COL3_PIN,OUTPUT_2MHZ_PUSHPULL);
	GPIO_VoidSetPinDirectionModeCNF(LEDMREX_COL4_PIN,OUTPUT_2MHZ_PUSHPULL);
	GPIO_VoidSetPinDirectionModeCNF(LEDMREX_COL5_PIN,OUTPUT_2MHZ_PUSHPULL);
	GPIO_VoidSetPinDirectionModeCNF(LEDMREX_COL6_PIN,OUTPUT_2MHZ_PUSHPULL);
	GPIO_VoidSetPinDirectionModeCNF(LEDMREX_COL7_PIN,OUTPUT_2MHZ_PUSHPULL);

}
static void LEDMREX_VoidDisableAllCol(void)
{
 	GPIO_VoidSetPinLevel(LEDMREX_COL0_PIN,HIGH);
	GPIO_VoidSetPinLevel(LEDMREX_COL1_PIN,HIGH);
	GPIO_VoidSetPinLevel(LEDMREX_COL2_PIN,HIGH);
	GPIO_VoidSetPinLevel(LEDMREX_COL3_PIN,HIGH);
	GPIO_VoidSetPinLevel(LEDMREX_COL4_PIN,HIGH);
	GPIO_VoidSetPinLevel(LEDMREX_COL5_PIN,HIGH);
	GPIO_VoidSetPinLevel(LEDMREX_COL6_PIN,HIGH);
	GPIO_VoidSetPinLevel(LEDMREX_COL7_PIN,HIGH);
}

void LEDMREX_VoidDisplay(u8 *Copy_u8ShapeInArr)
{ 
	  	
	/*Disable All Col*/
	LEDMREX_VoidDisableAllCol();
	/*mask Rows*/
	LEDMREX_BitsOfVar(Copy_u8ShapeInArr[0]);
	 /*Active One Col */
	 GPIO_VoidSetPinLevel(LEDMREX_COL0_PIN,LOW);
	 STK_VoidBusyWait(2500);

	 /*Disable All Col*/
	LEDMREX_VoidDisableAllCol();
	/*mask Rows*/
	LEDMREX_BitsOfVar(Copy_u8ShapeInArr[1]);
	 /*Active One Col */
	 GPIO_VoidSetPinLevel(LEDMREX_COL1_PIN,LOW);
	  STK_VoidBusyWait(2500);/*2.5 msec*/

	 /*Disable All Col*/
	LEDMREX_VoidDisableAllCol();
	/*mask Rows*/
	LEDMREX_BitsOfVar(Copy_u8ShapeInArr[2]);
	 /*Active One Col */
	 GPIO_VoidSetPinLevel(LEDMREX_COL2_PIN,LOW);
      STK_VoidBusyWait(2500);
	 
	 /*Disable All Col*/
	LEDMREX_VoidDisableAllCol();
	/*mask Rows*/
	LEDMREX_BitsOfVar(Copy_u8ShapeInArr[3]);
	 /*Active One Col */
	 GPIO_VoidSetPinLevel(LEDMREX_COL3_PIN,LOW);
       STK_VoidBusyWait(2500);
	 
	 /*Disable All Col*/
	LEDMREX_VoidDisableAllCol();
	/*mask Rows*/
	LEDMREX_BitsOfVar(Copy_u8ShapeInArr[4]);
	 /*Active One Col */
	 GPIO_VoidSetPinLevel(LEDMREX_COL4_PIN,LOW);
      STK_VoidBusyWait(2500);
	 
	 /*Disable All Col*/
	LEDMREX_VoidDisableAllCol();
	/*mask Rows*/
	LEDMREX_BitsOfVar(Copy_u8ShapeInArr[5]);
	 /*Active One Col */
	 GPIO_VoidSetPinLevel(LEDMREX_COL5_PIN,LOW);
      STK_VoidBusyWait(2500);
	 
	 /*Disable All Col*/
	LEDMREX_VoidDisableAllCol();
	/*mask Rows*/
	LEDMREX_BitsOfVar(Copy_u8ShapeInArr[6]);
	 /*Active One Col */
	 GPIO_VoidSetPinLevel(LEDMREX_COL6_PIN,LOW);
        STK_VoidBusyWait(2500);
	 
	 /*Disable All Col*/
	LEDMREX_VoidDisableAllCol();
	/*mask Rows*/
	LEDMREX_BitsOfVar(Copy_u8ShapeInArr[7]);
	 /*Active One Col */
	 GPIO_VoidSetPinLevel(LEDMREX_COL7_PIN,LOW);
	  STK_VoidBusyWait(2500);

}

static void LEDMREX_BitsOfVar(u8 Copy_u8var)
{
	 u8 Local_u8State;

	/*Mask all Rows*/
	  Local_u8State=GET_BIT(Copy_u8var,0);
	  GPIO_VoidSetPinLevel(LEDMREX_ROW0_PIN,Local_u8State);
	  
	  Local_u8State=GET_BIT(Copy_u8var,1);
	  GPIO_VoidSetPinLevel(LEDMREX_ROW1_PIN,Local_u8State);
	  
	  Local_u8State=GET_BIT(Copy_u8var,2);
	  GPIO_VoidSetPinLevel(LEDMREX_ROW2_PIN,Local_u8State);
	  
	  Local_u8State=GET_BIT(Copy_u8var,3);
	  GPIO_VoidSetPinLevel(LEDMREX_ROW3_PIN,Local_u8State);
	  
	  Local_u8State=GET_BIT(Copy_u8var,4);
	  GPIO_VoidSetPinLevel(LEDMREX_ROW4_PIN,Local_u8State);
	  
	  Local_u8State=GET_BIT(Copy_u8var,5);
	  GPIO_VoidSetPinLevel(LEDMREX_ROW5_PIN,Local_u8State);
	  
	  Local_u8State=GET_BIT(Copy_u8var,6);
	  GPIO_VoidSetPinLevel(LEDMREX_ROW6_PIN,Local_u8State);
	  
	  Local_u8State=GET_BIT(Copy_u8var,7);
	  GPIO_VoidSetPinLevel(LEDMREX_ROW7_PIN,Local_u8State);
}
