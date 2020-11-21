/******************************************************************/
/* Author         : SAYED ELROUBY                                 */
/* Date           : 18 sep 2020                                   */
/* Version        : V1                                            */
/* Type Of Driver : AFIO                                          */
/******************************************************************/

#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "AFIO_interface.h"
#include "AFIO_config.h"
#include "AFIO_private.h"


void AFIO_voidEXTISignalPin(u8 Copy_Line, u8 Copy_Pin)
{
	if(Copy_Line <= 3) 
	{
		AFIO_PTR -> AFIO_EXTICR[0]&=~(0b1111 << (Copy_Line*4));/* clear bits befor write */
		AFIO_PTR -> AFIO_EXTICR[0]|= (Copy_Pin << (Copy_Line*4));/*mask binary num of pin on register */
		
	}
	else if(Copy_Line <= 7)
	{
		Copy_Line-=4;
		AFIO_PTR -> AFIO_EXTICR[1]&=~(0b1111 << (Copy_Line*4));/* clear bits befor write */
		AFIO_PTR -> AFIO_EXTICR[1]|= (Copy_Pin << (Copy_Line*4));/*mask binary num of pin on register */
	}
	else if(Copy_Line <= 11)
	{
		Copy_Line-=8;
		AFIO_PTR -> AFIO_EXTICR[2]&=~(0b1111 << (Copy_Line*4));/* clear bits befor write */
		AFIO_PTR -> AFIO_EXTICR[2]|= (Copy_Pin << (Copy_Line*4));/*mask binary num of pin on register */
	}
	else if(Copy_Line <=15)
	{
		Copy_Line-=12;
		AFIO_PTR -> AFIO_EXTICR[3]&=~(0b1111 << (Copy_Line*4));/* clear bits befor write */
		AFIO_PTR -> AFIO_EXTICR[3]|= (Copy_Pin << (Copy_Line*4));/*mask binary num of pin on register */
	}
	else
	{
		/*return error */
	}
}