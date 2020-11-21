/******************************************************************/
/* Author         : SAYED ELROUBY                                 */
/* Date           : 17 Aug 2020                                   */
/* Version        : V1                                            */
/* Type Of Driver : GPIO                                          */
/******************************************************************/

#include"STD_TYPES.h"
#include"BIT_MATH.h"

#include"GPIO_interface.h"
#include"GPIO_private.h"
#include"GPIO_config.h"

void GPIO_VoidSetPinDirectionModeCNF(u8 Copy_Port, u8 Copy_Pin , u8 Copy_Direction)
{
	switch(Copy_Port)
	{
		case GPIOA :
			if(Copy_Pin<=7)
		                  {
                	       GPIOA_CRL&=~((0b1111)<<(Copy_Pin*4));  /*Reset Before Mask */
		                   GPIOA_CRL|=((Copy_Direction)<<(Copy_Pin*4)); /*Mask CNF&MODE*/
						  }
				     else if(Copy_Pin<=15)
					      {
							  Copy_Pin=Copy_Pin-8;
						   GPIOA_CRH&=~((0b1111)<<(Copy_Pin*4));/*Reset Before Mask */
		                   GPIOA_CRH|=((Copy_Direction)<<(Copy_Pin*4));/*Mask CNF&MODE*/
					      }
						  break;
		case GPIOB :
			if(Copy_Pin<=7)
		                  {
                	       GPIOB_CRL&=~((0b1111)<<(Copy_Pin*4));  /*Reset Before Mask */
		                   GPIOB_CRL|=((Copy_Direction)<<(Copy_Pin*4)); /*Mask CNF&MODE*/
						  }
				     else if(Copy_Pin<=15)
					      {
							  Copy_Pin=Copy_Pin-8;
						   GPIOB_CRH&=~((0b1111)<<(Copy_Pin*4));/*Reset Before Mask */
		                   GPIOB_CRH|=((Copy_Direction)<<(Copy_Pin*4));/*Mask CNF&MODE*/
					      }
						  break;
		
		case GPIOC :
			if(Copy_Pin<=7)
		                  {
                	       GPIOC_CRL&=~((0b1111)<<(Copy_Pin*4));  /*Reset Before Mask */
		                   GPIOC_CRL|=((Copy_Direction)<<(Copy_Pin*4)); /*Mask CNF&MODE*/
						  }
				     else if(Copy_Pin<=15)
					      {
							  Copy_Pin=Copy_Pin-8;
						   GPIOC_CRH&=~((0b1111)<<(Copy_Pin*4));/*Reset Before Mask */
		                   GPIOC_CRH|=((Copy_Direction)<<(Copy_Pin*4));/*Mask CNF&MODE*/
					      }
						  break;
		default    : break;
	}
}

void GPIO_VoidSetSomePinsDirection(u8 Copy_Port,u8 Copy_FromPin ,u8 Copy_ToPin ,u8 Copy_Direction)
{
	for(u8 counter=0;counter<=(Copy_ToPin-Copy_FromPin);counter++)
	{
	  GPIO_VoidSetPinDirectionModeCNF( Copy_Port,  Copy_FromPin+counter , Copy_Direction);
	}
	
}
void GPIO_VoidSetPinLevel(u8 Copy_Port, u8 Copy_Pin , u8 Copy_Level)
{
	switch(Copy_Port)
	{
		case GPIOA :
			if(Copy_Level==HIGH)
					    {
						   SET_BIT(GPIOA_ODR,Copy_Pin);
					    }	
                      else if(Copy_Level==LOW)
						{
							CLR_BIT(GPIOA_ODR,Copy_Pin);
						}							
		             break;
		case GPIOB :
			if(Copy_Level==HIGH)
					    {
						   SET_BIT(GPIOB_ODR,Copy_Pin);
					    }	
                      else if(Copy_Level==LOW)
						{
							CLR_BIT(GPIOB_ODR,Copy_Pin);
						}
					 break;		
		case GPIOC :
			if(Copy_Level==HIGH)
					    {
						   SET_BIT(GPIOC_ODR,Copy_Pin);
					    }	
                      else if(Copy_Level==LOW)
						{
							CLR_BIT(GPIOC_ODR,Copy_Pin);
						}
					 break;

		default    : break;
	}
}

void GPIO_VoidMaskLevelForSvenPins(u8 Copy_Port , u8 Copy_StartPin, u8 Copy_MaskLevel)
{
	switch(Copy_Port)
	{
		case GPIOA : GPIOA_ODR&=~((0b1111111)<<Copy_StartPin);/*rest data before write*/
		             GPIOA_ODR |=(Copy_MaskLevel<<Copy_StartPin);break;/*mask value*/
		case GPIOB : GPIOB_ODR&=~((0b1111111)<<Copy_StartPin);/*rest data before write*/
		             GPIOB_ODR |=(Copy_MaskLevel<<Copy_StartPin);break;/*mask value*/
		case GPIOC : GPIOC_ODR&=~((0b1111111)<<Copy_StartPin);/*rest data before write*/
		             GPIOC_ODR |=(Copy_MaskLevel<<Copy_StartPin);break;/*mask value*/
	}
}


u8   GPIO_u8GetPinValue(u8 Copy_Port, u8 Copy_Pin)
{
	u8 Flag=0;
	
	switch(Copy_Port)
	{
		case GPIOA :  
						  Flag = GET_BIT(GPIOA_IDR,Copy_Pin);
		                   break;
						   
		case GPIOB :  
						  Flag = GET_BIT(GPIOB_IDR,Copy_Pin);
					       break;
						   
		case GPIOC :
						  Flag = GET_BIT(GPIOC_IDR,Copy_Pin);
						   break;
		default    : break;
	}
	return Flag;
}


void GPIO_VoidTogglePinValue(u8 Copy_Port, u8 Copy_Pin)
{
	switch(Copy_Port)
	{
		case GPIOA :  TOG_BIT(GPIOA_ODR,Copy_Pin); break;					
		                
		case GPIOB :  TOG_BIT(GPIOB_ODR,Copy_Pin); break;	
						
		case GPIOC :  TOG_BIT(GPIOC_ODR,Copy_Pin); break;
		default    : break;

	}
}
