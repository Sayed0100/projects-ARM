/******************************************************************/
/* Author         : SAYED ELROUBY                                 */
/* Date           : 18 sep 2020                                   */
/* Version        : V1                                            */
/* Type Of Driver : AFIO                                          */
/******************************************************************/
#ifndef AFIO_PRIVATE_H
#define AFIO_PRIVATE_H

typedef struct AFIO_REG
{
	volatile u32 AFIO_EVCR      ;
	volatile u32 AFIO_MAPR      ;
	volatile u32 AFIO_EXTICR[4] ;/*start from 0-->3*/
	volatile u32 AFIO_MAPR2     ;
	
}AFIO_TYPE;

#define AFIO_PTR            ((AFIO_TYPE *)0x40010000)

#endif