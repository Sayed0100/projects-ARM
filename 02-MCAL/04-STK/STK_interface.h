/******************************************************************/
/* Author         : SAYED ELROUBY                                 */
/* Date           : 12 Sep 2020                                   */
/* Version        : V1                                            */
/* Type Of Driver : STK                                           */
/******************************************************************/

#ifndef STK_INTERFACE_H
#define STK_INTERFACE_H
/*  this api take AHB or AHB/8 by Config 
    make disable timer 
    make disable interrupt 
                             */
void STK_VoidInit(void);
/*this api take number of ticks to put it in register and make boling until it finish (synch)*/
void STK_VoidBusyWait(u32 Copy_32NumCount);
/*this api take num of ticks and pass to it function u want to happen inside ISR (Asynch)*/
void STK_VoidIntervalSingle(u32 Copy_32NumCount, void (*Copy_PtrFunc) (void));
/*this api take num of ticks and pass to it function u want to happen inside ISR  (Asynch)*/
void STK_VoidIntervalPeriodic(u32 Copy_32NumCount, void (*Copy_PtrFunc) (void));
/*STOP TIMER */
void STK_VoidStopTimer(void);
/*how many tick happened */
u32 STk_u32GetElapsedTime(void);
/*tell how many take will happen */
u32 STK_u32GetReminingTime(void);



#endif