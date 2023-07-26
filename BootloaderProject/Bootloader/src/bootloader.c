/**
  ******************************************************************************
  * @file           : bootloader.c
  * @brief          : bootloader module Implementation
  ******************************************************************************
  */
/* ----------------- Includes ----------------- */
#include "bootloader.h"

/* ----------------- Private Macro Declarations -----------------*/
#define MAX_SIZE_OF_MASSAGE 						100

/* ----------------- Global Variables Definitions ----------------- */

/* ----------------- Static Functions Definitions ----------------- */

/* ----------------- Software Interfaces Definitions ----------------- */
void BL_Print_Message(char *format, ...)
{
		uint8_t message[MAX_SIZE_OF_MASSAGE] = {0};
		
		/* holds the information needed by va_start, va_arg, va_end */
		va_list args;
		
		/* Enables access to the variable arguments */
		va_start(args, format);
		
		/* Write formatted data from variable argument list to string */
		vsprintf((char *)message, format, args);

#if (BL_DEBUG_METHOD == BL_ENABLE_UART_DEBUG_MESSAGE)
		/* Trasmit the formatted data through the defined UART */
		HAL_UART_Transmit(BL_DEBUG_UART, message, sizeof(message), HAL_MAX_DELAY);
#elif (BL_DEBUG_METHOD == BL_ENABLE_SPI_DEBUG_MESSAGE)
		/* Trasmit the formatted data through the defined SPI */
#elif (BL_DEBUG_METHOD == BL_ENABLE_CAN_DEBUG_MESSAGE)
		/* Trasmit the formatted data through the defined CAN */
#endif
		
		/* Performs cleanup for an ap object initialized by a call to va_start */
		va_end(args);
}
