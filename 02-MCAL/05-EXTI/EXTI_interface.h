/******************************************************************/
/* Author         : SAYED ELROUBY                                 */
/* Date           : 17 sep 2020                                   */
/* Version        : V1                                            */
/* Type Of Driver : EXTI                                          */
/******************************************************************/

#ifndef  EXTI_INTERFACE_H
#define  EXTI_INTERFACE_H

/* Keep In Your Mind, LIN0(A0,B0,C0...), LINE1(A1,B1,C1..)...   */

/* Options : 
             LINE0 ==>LINE15     */
			 
/* This API Enable Line */
void EXTI_VoidEnableLine(u8 Copy_Line);
/* This API Disable Line */
void EXTI_VoidDisableLine(u8 Copy_Line);

/* Options : RISING
            FALLING
			ANY_CHANGE  On Line */
void EXTI_VoidSenseModeLine(u8 Copy_Mode ,u8 Copy_Line);

void EXTI_VoidSenseModeLine(u8 Copy_Mode, u8 Copy_Line , void (*EXTI_CallBack)(void));


#define   RISING       1
#define   FALLING      2
#define   ANY_CHANGE   3


#define  LINE0     0
#define  LINE1     1
#define  LINE2     2
#define  LINE3     3
#define  LINE4     4
#define  LINE5     5
#define  LINE6     6
#define  LINE7     7 
#define  LINE8     8
#define  LINE9     9
#define  LINE10    10
#define  LINE11    11
#define  LINE12    12
#define  LINE13    13
#define  LINE14    14
#define  LINE15    15



#endif