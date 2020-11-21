/******************************************************************/
/* Author         : SAYED ELROUBY                                 */
/* Date           : 28 Aug 2020                                   */
/* Version        : V1                                            */
/* Type Of Driver : NVIC                                          */
/******************************************************************/
#ifndef NVIC_INTERFACE_H
#define NVIC_INTERFACE_H

/*You Have 0 ==> 59 Extaernal Interrupt */
void NVIC_VoidEnableExInterrupt(u8 Copy_u8NumberInt);/* enable Interrupt */

void NVIC_VoidDisableExInterrupt(u8 Copy_u8NumberInt);/* disable Interrupt */

/*You Have 0 ==> 59 Extaernal Interrupt */
void NVIC_VoidSetPendingExInterrupt(u8 Copy_u8NumberInt);/* set pending Interrupt */

void NVIC_VoidClearPendingExInterrupt(u8 Copy_u8NumberInt);/*clr pending Interrupt*/

/*You Have 0 ==> 59 Extaernal Interrupt */
u8 NVIC_u8ReadActiveFlagInterrupt(u8 Copy_u8NumberInt); /*Read Active Flag of INT*/

/*This API select Number Of Groups And Sub*/
void NVIC_voidInit(void);

/*This fun can change sw priority for any Interrupt peripheral*/
void NVIC_SetPriority(u8 Copy_u8PeripheralIndexHW,u8 Copy_u8Group,u8 Copy_u8Sub);

#endif
