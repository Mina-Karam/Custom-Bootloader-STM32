/**
  ******************************************************************************
  * @file    bootloader.h
  * @author  Mina Karam
  * @brief   Header file of bootloader module.
  ******************************************************************************
  */

/* Define to prevent recursive inclusion -------------------------------------*/
#ifndef _BOOTLOADER_H_
#define _BOOTLOADER_H_

/* ----------------- Includes -----------------*/
#include <stdio.h>
#include <string.h>
#include <stdarg.h>
#include "usart.h"


/* ----------------- Macro Declarations -----------------*/
#define BL_DEBUG_UART &huart2

#define BL_ENABLE_UART_DEBUG_MESSAGE 							0x00
#define BL_ENABLE_SPI_DEBUG_MESSAGE  							0x01
#define BL_ENABLE_CAN_DEBUG_MESSAGE  							0x02
#define BL_DEBUG_METHOD 													(BL_ENABLE_UART_DEBUG_MESSAGE)

/* ----------------- Macro Functions Declarations -----------------*/

/* ----------------- Data Type Declarations -----------------*/

/* ----------------- Software Interfaces Declarations -----------------*/
void BL_Print_Message(char *format, ...);

#endif /* _BOOTLOADER_H_ */
