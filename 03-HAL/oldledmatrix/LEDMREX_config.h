/******************************************************************/
/* Author         : SAYED ELROUBY                                 */
/* Date           : 23 sep 2020                                   */
/* Version        : V1                                            */
/* Type Of Driver : LED MATRIEX                                   */
/******************************************************************/
#ifndef LEDMRES_CONFIG_H
#define LEDMRES_CONFIG_H
/*Except B3,B4  do not connect these pins (enable on it G tag) */


#define LEDMREX_ROW0_PIN  GPIOA,PIN0
#define LEDMREX_ROW1_PIN  GPIOA,PIN1
#define LEDMREX_ROW2_PIN  GPIOA,PIN2
#define LEDMREX_ROW3_PIN  GPIOA,PIN3
#define LEDMREX_ROW4_PIN  GPIOA,PIN4
#define LEDMREX_ROW5_PIN  GPIOA,PIN5
#define LEDMREX_ROW6_PIN  GPIOA,PIN6
#define LEDMREX_ROW7_PIN  GPIOA,PIN7



#define LEDMREX_COL0_PIN  GPIOB,PIN0
#define LEDMREX_COL1_PIN  GPIOB,PIN1
#define LEDMREX_COL2_PIN  GPIOB,PIN5
#define LEDMREX_COL3_PIN  GPIOB,PIN6
#define LEDMREX_COL4_PIN  GPIOB,PIN7
#define LEDMREX_COL5_PIN  GPIOB,PIN8
#define LEDMREX_COL6_PIN  GPIOB,PIN9
#define LEDMREX_COL7_PIN  GPIOB,PIN10


#endif