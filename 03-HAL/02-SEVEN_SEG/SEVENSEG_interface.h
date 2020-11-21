/******************************************************************/
/* Author         : SAYED ELROUBY                                 */
/* Date           : 19 Aug 2020                                   */
/* Version        : V1                                            */
/* Type Of Driver : seven segment                                          */
/******************************************************************/
#ifndef SEVENSEG_INTERFACE_H
#define SEVENSEG_INTERFACE_H

/*
 This Func Take Port And Pins ,Form A-->G And Common(if G=pin7 ,then Common=pin8)
  In Seven segment                                                                */
  
void SEVENSEG_VoidDisplay(u8 Copy_Port,u8 Copy_FromPin,u8 ToPin ,u8 Copy_SpeedOut,u8 Copy_Number);

#endif
