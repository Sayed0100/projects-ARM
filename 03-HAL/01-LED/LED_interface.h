/******************************************************************/
/* Author         : SAYED ELROUBY                                 */
/* Date           : 19 Aug 2020                                   */
/* Version        : V1                                            */
/* Type Of Driver : LED                                           */
/******************************************************************/

#ifndef LED_INTERFACE_H
#define LED_INTERFACE_H

/*
Fun Will Used In Led CNF 

   Options : GPIOA ,GPIOB ,GPIOC
             PIN0----->PIN16  
                        			 */
void LED_VoidLedOn(u8 Copy_Port, u8 Copy_Pin);

/*
Fun Will Used In Led CNF 

   Options : GPIOA ,GPIOB ,GPIOC
             PIN0----->PIN16  
                        			 */			
void LED_VoidLedOff(u8 Copy_Port, u8 Copy_Pin);

/* Toggle Pin In Register*/
void LED_VoidLedToggle(u8 Copy_Port, u8 Copy_Pin);



/*Macro Of Registers */
/*#define GPIOA 0
#define GPIOB 1
#define GPIOC 2*/


#endif
