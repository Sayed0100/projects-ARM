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

/*put all pins of rows and colums in array to can control them */
u8 Local_u8ArrOfRows[NUM_OF_ROWS*2]=
				  {LEDMREX_ROW0_PIN ,LEDMREX_ROW1_PIN,LEDMREX_ROW2_PIN  ,LEDMREX_ROW3_PIN ,
				   LEDMREX_ROW4_PIN ,LEDMREX_ROW5_PIN,LEDMREX_ROW6_PIN  ,LEDMREX_ROW7_PIN ,
				   LEDMREX_ROW8_PIN ,LEDMREX_ROW9_PIN,LEDMREX_ROW10_PIN ,LEDMREX_ROW11_PIN,
				   LEDMREX_ROW12_PIN,LEDMREX_ROW13_PIN,LEDMREX_ROW14_PIN,LEDMREX_ROW15_PIN,
				   LEDMREX_ROW16_PIN,LEDMREX_ROW17_PIN,LEDMREX_ROW18_PIN,LEDMREX_ROW19_PIN,
				   LEDMREX_ROW20_PIN,LEDMREX_ROW21_PIN,LEDMREX_ROW22_PIN,LEDMREX_ROW23_PIN,
				   LEDMREX_ROW24_PIN,LEDMREX_ROW25_PIN,LEDMREX_ROW26_PIN,LEDMREX_ROW27_PIN,
				   LEDMREX_ROW28_PIN,LEDMREX_ROW29_PIN,LEDMREX_ROW30_PIN};

u8 Local_u8ArrOfCol[NUM_OF_COL*2]=
             	  {LEDMREX_COL0_PIN ,LEDMREX_COL1_PIN,LEDMREX_COL2_PIN ,LEDMREX_COL3_PIN ,
				   LEDMREX_COL4_PIN ,LEDMREX_COL5_PIN,LEDMREX_COL6_PIN ,LEDMREX_COL7_PIN ,
				   LEDMREX_COL8_PIN ,LEDMREX_COL9_PIN,LEDMREX_COL10_PIN,LEDMREX_COL11_PIN,
				   LEDMREX_COL12_PIN,LEDMREX_COL3_PIN,LEDMREX_COL14_PIN,LEDMREX_COL15_PIN,
				   LEDMREX_COL16_PIN,LEDMREX_COL7_PIN,LEDMREX_COL18_PIN,LEDMREX_COL19_PIN,
				   LEDMREX_COL20_PIN,LEDMREX_COL1_PIN,LEDMREX_COL22_PIN,LEDMREX_COL23_PIN,
				   LEDMREX_COL24_PIN,LEDMREX_COL5_PIN,LEDMREX_COL26_PIN,LEDMREX_COL27_PIN,
				   LEDMREX_COL28_PIN,LEDMREX_COL9_PIN,LEDMREX_COL30_PIN};


/*api config pins of led matrix as output*/
void LEDMREX_VoidIntit(void)
{
	#if    LEDMREX_OUTPUT_LEVEL  ==  OUT_2MHZ
	  /*make colums output*/
	for(u8 counterCol_u8Local =0 ; counterCol_u8Local< NUM_OF_COL*2 ; counterCol_u8Local+=2)
	{ /*if u select 9 NUM_OF_COL this loop will make first 9 col in arr Of col output*/
	GPIO_VoidSetPinDirectionModeCNF(Local_u8ArrOfCol[counterCol_u8Local],Local_u8ArrOfCol[counterCol_u8Local+1] ,OUTPUT_2MHZ_PUSHPULL);
	}
	/*make Rows output*/
	for(u8 counterRow_u8Local =0 ; counterRow_u8Local< NUM_OF_ROWS*2 ; counterRow_u8Local+=2)
	{   /*if u select 9 NUM_OF_ROWS this loop will make first 9 ROWS in arr Of ROWS output*/
		GPIO_VoidSetPinDirectionModeCNF(Local_u8ArrOfRows[counterRow_u8Local],Local_u8ArrOfRows[counterRow_u8Local+1],OUTPUT_2MHZ_PUSHPULL);
	}
	
	#elif  LEDMREX_OUTPUT_LEVEL  ==  OUT_10MHZ
	/*make colums output*/
	for(u8 counterCol_u8Local =0 ; counterCol_u8Local< NUM_OF_COL*2 ; counterCol_u8Local+=2)
	{   /*if u select 9 NUM_OF_COL this loop will make first 9 col in arr Of col output*/
		GPIO_VoidSetPinDirectionModeCNF(Local_u8ArrOfCol[counterCol_u8Local],Local_u8ArrOfCol[counterCol_u8Local+1],OUTPUT_10MHZ_PUSHPULL);
	}
	 /*make Rows output*/
	for(u8 counterRow_u8Local =0 ; counterRow_u8Local< NUM_OF_ROWS*2; counterRow_u8Local+=2)
	{
		/*if u select 9 NUM_OF_ROWS this loop will make first 9 ROWS in arr Of ROWS output*/
		GPIO_VoidSetPinDirectionModeCNF(Local_u8ArrOfRows[counterRow_u8Local],Local_u8ArrOfRows[counterRow_u8Local+1],OUTPUT_10MHZ_PUSHPULL);
	}
	#elif  LEDMREX_OUTPUT_LEVEL  ==  OUT_50MHZ
	/*make colums output*/
	for(u8 counterCol_u8Local =0 ; counterCol_u8Local< NUM_OF_COL*2 ; counterCol_u8Local++)
	{
		/*if u select 9 NUM_OF_COL this loop will make first 9 col in arr Of col output*/
		GPIO_VoidSetPinDirectionModeCNF(Local_u8ArrOfCol[counterCol_u8Local],Local_u8ArrOfCol[counterCol_u8Local+1],OUTPUT_50MHZ_PUSHPULL);
	}

	for(u8 counterRow_u8Local =0 ; counterRow_u8Local< NUM_OF_ROWS*2 ; counterRow_u8Local++)
	{
		/*if u select 9 NUM_OF_ROWS this loop will make first 9 ROWS in arr Of ROWS output*/
		GPIO_VoidSetPinDirectionModeCNF(Local_u8ArrOfRows[counterRow_u8Local],Local_u8ArrOfRows[counterRow_u8Local+1],OUTPUT_50MHZ_PUSHPULL);
	}
	#else("return error ")
	#endif
}
/*this fun iS private.it's make disable for all col*/
static void LEDMREX_VoidDisableAllCol(void)
{
	#if   ACTIVE_COL == 0
		for(u8 local_u8CounterCol=0 ; local_u8CounterCol< NUM_OF_COL*2 ; local_u8CounterCol+=2)
		{
	   GPIO_VoidSetPinLevel(Local_u8ArrOfCol[local_u8CounterCol],Local_u8ArrOfCol[local_u8CounterCol+1],HIGH);
		}
	#elif ACTIVE_COL == 1
		for(u8 local_u8CounterCol=0 ; local_u8CounterCol< NUM_OF_COL*2 ; local_u8CounterCol+=2)
		{
	   GPIO_VoidSetPinLevel(Local_u8ArrOfCol[local_u8CounterCol],Local_u8ArrOfCol[local_u8CounterCol+1],LOW);
		}
	#endif
}

/*this api will recieve Arr of a Shape ,and display it on led matrix */
void LEDMREX_VoidDisplay(u8 *(Copy_u8ShapeInArr)[NUM_OF_COL] )
{ 
	for(u8 local_u8CounterMask =0 ; local_u8CounterMask < NUM_OF_COL*2 ; local_u8CounterMask+=2)
	{
	   	/*Disable All Col*/
	LEDMREX_VoidDisableAllCol();
	/*this func will take index by index from arr which u sent it and mask this index on all rows , then go to next index and do this period again*/
	LEDMREX_BitsOfVar(Copy_u8ShapeInArr[(local_u8CounterMask/2)]);
	/*make active for a col to dispaly it */

	#if ACTIVE_COL   == 0
	 GPIO_VoidSetPinLevel(Local_u8ArrOfCol[local_u8CounterMask],Local_u8ArrOfCol[local_u8CounterMask+1],LOW);
	#elif ACTIVE_COL == 1
	 GPIO_VoidSetPinLevel(Local_u8ArrOfCol[local_u8CounterMask],Local_u8ArrOfCol[local_u8CounterMask+1],HIGH);
	#endif

	/*delay to make (POV) from 50-->60 fram in a second */
	STK_VoidBusyWait(2500);
	}
}


/*this func is private .it's make mask for all rows from a variable which u will pass it for it */
static void LEDMREX_BitsOfVar(u8 Copy_u8var)
{
	/*copy_u8var will mask to all rows bit by bit . bit0 on row0 , bit5 on row5 ...etc */
	u8 Local_u8State;
	for(u8 local_u8CounterBitOfVar =0 ; local_u8CounterBitOfVar < NUM_OF_ROWS*2 ; local_u8CounterBitOfVar+=2)
	{
	  Local_u8State=GET_BIT(Copy_u8var,(local_u8CounterBitOfVar/2));
	  GPIO_VoidSetPinLevel(Local_u8ArrOfRows[local_u8CounterBitOfVar],Local_u8ArrOfRows[local_u8CounterBitOfVar+1],Local_u8State);
	}
}

