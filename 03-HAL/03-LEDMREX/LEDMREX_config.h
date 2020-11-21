/******************************************************************/
/* Author         : SAYED ELROUBY                                 */
/* Date           : 23 sep 2020                                   */
/* Version        : V1                                            */
/* Type Of Driver : LED MATRIEX                                   */
/******************************************************************/
#ifndef LEDMRES_CONFIG_H
#define LEDMRES_CONFIG_H
/*Except B3,B4  do not connect these pins (enable on it G tag) */

#define NUM_OF_ROWS       8
#define NUM_OF_COL        8

/* 1 --> +
   0 --> -  */
#define ACTIVE_COL   0
#define ACTIVE_ROWS  1

/*Options : 50 ---> 60*/
#define NUM_OF_FRAM_IN_SEC  50

/* Options :  OUT_2MHZ
              OUT_10MHZ
			  OUT_50MHZ  */
#define LEDMREX_OUTPUT_LEVEL   OUT_2MHZ

#define LEDMREX_ROW0_PIN   GPIOA,PIN0
#define LEDMREX_ROW1_PIN   GPIOA,PIN1
#define LEDMREX_ROW2_PIN   GPIOA,PIN2
#define LEDMREX_ROW3_PIN   GPIOA,PIN3
#define LEDMREX_ROW4_PIN   GPIOA,PIN4
#define LEDMREX_ROW5_PIN   GPIOA,PIN5
#define LEDMREX_ROW6_PIN   GPIOA,PIN6
#define LEDMREX_ROW7_PIN   GPIOA,PIN7
#define LEDMREX_ROW8_PIN   0
#define LEDMREX_ROW9_PIN   0
#define LEDMREX_ROW10_PIN  0
#define LEDMREX_ROW11_PIN  0
#define LEDMREX_ROW12_PIN  0
#define LEDMREX_ROW13_PIN  0
#define LEDMREX_ROW14_PIN  0
#define LEDMREX_ROW15_PIN  0
#define LEDMREX_ROW16_PIN  0
#define LEDMREX_ROW17_PIN  0
#define LEDMREX_ROW18_PIN  0
#define LEDMREX_ROW19_PIN  0
#define LEDMREX_ROW20_PIN  0
#define LEDMREX_ROW21_PIN  0
#define LEDMREX_ROW22_PIN  0
#define LEDMREX_ROW23_PIN  0
#define LEDMREX_ROW24_PIN  0
#define LEDMREX_ROW25_PIN  0
#define LEDMREX_ROW26_PIN  0
#define LEDMREX_ROW27_PIN  0
#define LEDMREX_ROW28_PIN  0
#define LEDMREX_ROW29_PIN  0
#define LEDMREX_ROW30_PIN  0




#define LEDMREX_COL0_PIN  GPIOB,PIN0
#define LEDMREX_COL1_PIN  GPIOB,PIN1
#define LEDMREX_COL2_PIN  GPIOB,PIN5
#define LEDMREX_COL3_PIN  GPIOB,PIN6
#define LEDMREX_COL4_PIN  GPIOB,PIN7
#define LEDMREX_COL5_PIN  GPIOB,PIN8
#define LEDMREX_COL6_PIN  GPIOB,PIN9
#define LEDMREX_COL7_PIN  GPIOB,PIN10
#define LEDMREX_COL8_PIN   0
#define LEDMREX_COL9_PIN   0
#define LEDMREX_COL10_PIN  0
#define LEDMREX_COL11_PIN  0
#define LEDMREX_COL12_PIN  0
#define LEDMREX_COL13_PIN  0
#define LEDMREX_COL14_PIN  0
#define LEDMREX_COL15_PIN  0
#define LEDMREX_COL16_PIN  0
#define LEDMREX_COL17_PIN  0
#define LEDMREX_COL18_PIN  0
#define LEDMREX_COL19_PIN  0
#define LEDMREX_COL20_PIN  0
#define LEDMREX_COL21_PIN  0
#define LEDMREX_COL22_PIN  0
#define LEDMREX_COL23_PIN  0
#define LEDMREX_COL24_PIN  0
#define LEDMREX_COL25_PIN  0
#define LEDMREX_COL26_PIN  0
#define LEDMREX_COL27_PIN  0
#define LEDMREX_COL28_PIN  0
#define LEDMREX_COL29_PIN  0
#define LEDMREX_COL30_PIN  0


#endif
