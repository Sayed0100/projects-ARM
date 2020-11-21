/******************************************************************/
/* Author         : SAYED ELROUBY                                 */
/* Date           : 19 Aug 2020                                   */
/* Version        : V1                                            */
/* Type Of Driver : seven segment                                 */
/******************************************************************/
#include"BIT_MATH.h"
#include"STD_TYPES.h"

#include"RCC_interface.h"
#include"GPIO_interface.h"

#include"SEVENSEG_interface.h"
#include"SEVENSEG_private.h"
#include"SEVENSEG_config.h"

void SEVENSEG_VoidDisplay(u8 Copy_Port,u8 Copy_FromPin,u8 Copy_ToPin,u8 Copy_SpeedOut,u8 Copy_Number)
{
GPIO_VoidSetSomePinsDirection( Copy_Port, Copy_FromPin, Copy_ToPin+1, Copy_SpeedOut);
#if    SEVENSEG_COMMON ==  CATHODE
 GPIO_VoidSetPinLevel(Copy_Port,Copy_ToPin+1 ,LOW);/*Pin Of Common Cathod*/
  
 if(Copy_Number==0)
GPIO_VoidMaskLevelForSvenPins(Copy_Port,Copy_FromPin,SEVENSEGC_ZERO);
else if(Copy_Number==1)
GPIO_VoidMaskLevelForSvenPins(Copy_Port,Copy_FromPin,SEVENSEGC_ONE );
else if(Copy_Number==2)
GPIO_VoidMaskLevelForSvenPins(Copy_Port,Copy_FromPin,SEVENSEGC_TWO);
else if(Copy_Number==3)
GPIO_VoidMaskLevelForSvenPins(Copy_Port,Copy_FromPin,SEVENSEGC_THREE);
else if(Copy_Number==4)
GPIO_VoidMaskLevelForSvenPins(Copy_Port,Copy_FromPin,SEVENSEGC_FOUR);
else if(Copy_Number==5)
GPIO_VoidMaskLevelForSvenPins(Copy_Port,Copy_FromPin,SEVENSEGC_FIVE);
else if(Copy_Number==6)
GPIO_VoidMaskLevelForSvenPins(Copy_Port,Copy_FromPin,SEVENSEGC_SIX);
else if(Copy_Number==7)
GPIO_VoidMaskLevelForSvenPins(Copy_Port,Copy_FromPin,SEVENSEGC_SEVEN );
else if(Copy_Number==8)
GPIO_VoidMaskLevelForSvenPins(Copy_Port,Copy_FromPin,SEVENSEGC_EIGHT);
else if(Copy_Number==9)
GPIO_VoidMaskLevelForSvenPins(Copy_Port,Copy_FromPin,SEVENSEGC_NINE);

#elif    SEVENSEG_COMMON ==  ANOD
  GPIO_VoidSetPinLevel(Copy_Port,Copy_ToPin+1 ,HIGH);/*Pin Of Common Cathod*/

 if(Copy_Number==0)
GPIO_VoidMaskLevelForSvenPins(Copy_Port,Copy_FromPin,~SEVENSEGC_ZERO);
else if(Copy_Number==1)
GPIO_VoidMaskLevelForSvenPins(Copy_Port,Copy_FromPin,~SEVENSEGC_ONE );
else if(Copy_Number==2)
GPIO_VoidMaskLevelForSvenPins(Copy_Port,Copy_FromPin,~SEVENSEGC_TWO);
else if(Copy_Number==3)
GPIO_VoidMaskLevelForSvenPins(Copy_Port,Copy_FromPin,~SEVENSEGC_THREE);
else if(Copy_Number==4)
GPIO_VoidMaskLevelForSvenPins(Copy_Port,Copy_FromPin,~SEVENSEGC_FOUR);
else if(Copy_Number==5)
GPIO_VoidMaskLevelForSvenPins(Copy_Port,Copy_FromPin,~SEVENSEGC_FIVE);
else if(Copy_Number==6)
GPIO_VoidMaskLevelForSvenPins(Copy_Port,Copy_FromPin,~SEVENSEGC_SIX);
else if(Copy_Number==7)
GPIO_VoidMaskLevelForSvenPins(Copy_Port,Copy_FromPin,~SEVENSEGC_SEVEN );
else if(Copy_Number==8)
GPIO_VoidMaskLevelForSvenPins(Copy_Port,Copy_FromPin,~SEVENSEGC_EIGHT);
else if(Copy_Number==9)
GPIO_VoidMaskLevelForSvenPins(Copy_Port,Copy_FromPin,~SEVENSEGC_NINE);

#endif		 
}
