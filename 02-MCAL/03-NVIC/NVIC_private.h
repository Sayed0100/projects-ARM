/******************************************************************/
/* Author         : SAYED ELROUBY                                 */
/* Date           : 28 Aug 2020                                   */
/* Version        : V1                                            */
/* Type Of Driver : NVIC                                          */
/******************************************************************/
#ifndef NVIC_PRIVATE_H
#define NVIC_PRIVATE_H

#define NVIC_BASE_ADRESS   0xE000E100

#define  NVIC_ISER0        *((u32*)(NVIC_BASE_ADRESS+0x000))
#define  NVIC_ISER1        *((u32*)(NVIC_BASE_ADRESS+0x004))
#define  NVIC_ICER0        *((u32*)(NVIC_BASE_ADRESS+0x080))
#define  NVIC_ICER1        *((u32*)(NVIC_BASE_ADRESS+0x084))
#define  NVIC_ISPR0        *((u32*)(NVIC_BASE_ADRESS+0x100))
#define  NVIC_ISPR1        *((u32*)(NVIC_BASE_ADRESS+0x104))
#define  NVIC_ICPR0        *((u32*)(NVIC_BASE_ADRESS+0x180))
#define  NVIC_ICPR1        *((u32*)(NVIC_BASE_ADRESS+0x184))
/* These Tegisters For Read Active Flag */
#define  NVIC_IABR0        *((volatile u32*)(NVIC_BASE_ADRESS+0x200))
#define  NVIC_IABR1        *((volatile u32*)(NVIC_BASE_ADRESS+0x204))

#define  NVIC_IPR         ( u8*)(NVIC_BASE_ADRESS+0x300)


/* Definations of  Groups and Sub */
#define     16_GROUP_0_SUB    0x5FA0300 
#define     8_GROUP_2_SUB     0x5FA0400 
#define     4_GROUP_4_SUB     0x5FA0500 
#define     2_GROUP_8_SUB     0x5FA0600 
#define     0_GROUP_16_SUB	  0x5FA0700 




#endif
