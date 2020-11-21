/******************************************************************/
/* Author         : SAYED ELROUBY                                 */
/* Date           : 17 Aug 2020                                   */
/* Version        : V1                                            */
/* Type Of Driver : GPIO                                          */
/******************************************************************/

#ifndef GPIO_INTERFACE_H
#define GPIO_INTERFACE_H

/*
Options : 
		 INPUT_ANLOG                     
		 INPUT_FLOATING               
		 INPUT_PULLUP_DOWM               
		 INPUT_RESERVED                  

		 OUTPUT_10MHZ_PUSHPULL           
		 OUTPUT_2MHZ_PUSHPULL           
		 OUTPUT_50MHZ_PUSHPULL          

		 OUTPUT_10MHZ_OPENDRAIN          
		 OUTPUT_2MHZ_OPENDRAIN           
		 OUTPUT_50MHZ_OPENDRAIN          

		 OUTPUT_10MHZ_AF_PUSHPULL        
		 OUTPUT_2MHZ_AF_PUSHPULL         
		 OUTPUT_50MHZ_AF_PUSHPULL        

		 OUTPUT_10MHZ_AF_OPENDRAIN       
		 OUTPUT_2MHZ_AF_OPENDRAIN        
		 OUTPUT_50MHZ_AF_OPENDRAIN     */
void GPIO_VoidSetPinDirectionModeCNF(u8 Copy_Port, u8 Copy_Pin , u8 Copy_Direction);

void GPIO_VoidSetSomePinsDirection(u8 Copy_Port,u8 Copy_FromPin ,u8 Copy_ToPin ,u8 Copy_Direction);

/*Options : HIGH
            LOW  */
void GPIO_VoidSetPinLevel(u8 Copy_Port, u8 Copy_Pin , u8 Copy_Level);

/* This Func Return 0 or 1 */
u8   GPIO_u8GetPinValue(u8 Copy_Port, u8 Copy_Pin);

/* TOGGLE  PIN */
void GPIO_VoidTogglePinValue(u8 Copy_Port, u8 Copy_Pin);

void GPIO_VoidMaskLevelForSvenPins(u8 Copy_Port , u8 Copy_StartPin, u8 Copy_MaskLevel);

/* Macro of Registers To switch Between them*/
#define  GPIOA  0
#define  GPIOB  1
#define  GPIOC  2

/* HIGH &L  LOW OF PINS */
#define HIGH 1
#define LOW  0

/* Macro Of Pins */
#define PIN0    0
#define PIN1    1
#define PIN2    2
#define PIN3    3
#define PIN4    4
#define PIN5    5
#define PIN6    6
#define PIN7    7
#define PIN8    8
#define PIN9    9
#define PIN10   10
#define PIN11   11
#define PIN12   12
#define PIN13   13
#define PIN14   14
#define PIN15   15


/*CNf and Mode of pin*/
#define INPUT_ANLOG                     0b0000
#define INPUT_FLOATING                  0b0100
#define INPUT_PULLUP_DOWM               0b1000
#define INPUT_RESERVED                  0b1100

#define OUTPUT_10MHZ_PUSHPULL           0b0001
#define OUTPUT_2MHZ_PUSHPULL            0b0010
#define OUTPUT_50MHZ_PUSHPULL           0b0011

#define OUTPUT_10MHZ_OPENDRAIN          0b0101
#define OUTPUT_2MHZ_OPENDRAIN           0b0110
#define OUTPUT_50MHZ_OPENDRAIN          0b0111

#define OUTPUT_10MHZ_AF_PUSHPULL        0b1001
#define OUTPUT_2MHZ_AF_PUSHPULL         0b1010
#define OUTPUT_50MHZ_AF_PUSHPULL        0b1011

#define OUTPUT_10MHZ_AF_OPENDRAIN       0b1101
#define OUTPUT_2MHZ_AF_OPENDRAIN        0b1110
#define OUTPUT_50MHZ_AF_OPENDRAIN       0b1111







#endif
