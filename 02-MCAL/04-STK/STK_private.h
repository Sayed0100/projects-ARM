/******************************************************************/
/* Author         : SAYED ELROUBY                                 */
/* Date           : 12 Sep 2020                                   */
/* Version        : V1                                            */
/* Type Of Driver : STK                                           */
/******************************************************************/

#ifndef STK_PRIVATE_H
#define STK_PRIVATE_H

  
#define STK_BASE_ADRESS 0xE000E010

#define STK_CTRL         *((volatile u32*)(STK_BASE_ADRESS+0x00))
#define STK_LOAD         *((volatile u32*)(STK_BASE_ADRESS+0x04))
#define STK_VAL          *((volatile u32*)(STK_BASE_ADRESS+0x08))
#define STK_CALIB        *((volatile u32*)(STK_BASE_ADRESS+0x0C))




#define   AHB           0
#define   AHB_div_8     1








#endif