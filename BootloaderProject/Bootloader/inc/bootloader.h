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
#define BL_DEBUG_UART 											&huart2
#define BL_HOST_COMMUNICATION_UART 								&huart2
 
#define BL_HOST_BUFFER_RX_LENGTH								200

#define BL_ENABLE_UART_DEBUG_MESSAGE 							0x00
#define BL_ENABLE_SPI_DEBUG_MESSAGE  							0x01
#define BL_ENABLE_CAN_DEBUG_MESSAGE  							0x02
#define BL_DEBUG_METHOD 										(BL_ENABLE_UART_DEBUG_MESSAGE)


#define CBL_GET_VER_CMD              							0x10
#define CBL_GET_HELP_CMD             							0x11
#define CBL_GET_CID_CMD              							0x12
/* Get Read Protection Status */
#define CBL_GET_RDP_STATUS_CMD       							0x13
#define CBL_GO_TO_ADDR_CMD           							0x14
#define CBL_FLASH_ERASE_CMD          							0x15
#define CBL_MEM_WRITE_CMD            							0x16
/* Enable/Disable Write Protection */
#define CBL_ED_W_PROTECT_CMD         							0x17
#define CBL_MEM_READ_CMD             							0x18
/* Get Sector Read/Write Protection Status */
#define CBL_READ_SECTOR_STATUS_CMD   							0x19
#define CBL_OTP_READ_CMD             							0x20
/* Change Read Out Protection Level */
#define CBL_CHANGE_ROP_Level_CMD     							0x21


/* ----------------- Macro Functions Declarations -----------------*/

/* ----------------- Data Type Declarations -----------------*/
typedef enum 
{	
	BL_NACK,
	BL_OK
}BL_Status;


/* ----------------- Software Interfaces Declarations -----------------*/
BL_Status BL_Print_Message(char *format, ...);
BL_Status BL_UART_Fetch_Host_Command(void);

#endif /* _BOOTLOADER_H_ */
