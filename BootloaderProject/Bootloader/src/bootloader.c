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

/* ----------------- Static Variables Definitions ----------------- */
static uint8_t BL_Host_Buffer[BL_HOST_BUFFER_RX_LENGTH];

/* ----------------- Static Functions Definitions ----------------- */
static BL_Status Bootloader_Get_Version(uint8_t *Host_Buffer)
{
	BL_Status Status = BL_OK;
	
	return Status;
}
static BL_Status Bootloader_Get_Help(uint8_t *Host_Buffer)
{
	BL_Status Status = BL_OK;
	
	return Status;
}
static BL_Status Bootloader_Get_Chip_Identification_Number(uint8_t *Host_Buffer)
{
	BL_Status Status = BL_OK;
	
	return Status;
}
static BL_Status Bootloader_Read_Protection_Level(uint8_t *Host_Buffer)
{
	BL_Status Status = BL_OK;
	
	return Status;
}
static BL_Status Bootloader_Jump_To_Address(uint8_t *Host_Buffer)
{
	BL_Status Status = BL_OK;
	
	return Status;
}
static BL_Status Bootloader_Erase_Flash(uint8_t *Host_Buffer)
{
	BL_Status Status = BL_OK;
	
	return Status;
}
static BL_Status Bootloader_Memory_Write(uint8_t *Host_Buffer)
{
	BL_Status Status = BL_OK;
	
	return Status;
}
static BL_Status Bootloader_Enable_RW_Protection(uint8_t *Host_Buffer)
{
	BL_Status Status = BL_OK;
	
	return Status;
}
static BL_Status Bootloader_Memory_Read(uint8_t *Host_Buffer)
{
	BL_Status Status = BL_OK;
	
	return Status;
}
static BL_Status Bootloader_Get_Sector_Protection_Status(uint8_t *Host_Buffer)
{
	BL_Status Status = BL_OK;
	
	return Status;
}
static BL_Status Bootloader_Read_OTP(uint8_t *Host_Buffer)
{
	BL_Status Status = BL_OK;
	
	return Status;
}
static BL_Status Bootloader_Change_Read_Protection_Level(uint8_t *Host_Buffer)
{
	BL_Status Status = BL_OK;
	
	return Status;
}

/* ----------------- Software Interfaces Definitions ----------------- */
BL_Status BL_Print_Message(char *format, ...)
{
	BL_Status Status = BL_OK;
	
	uint8_t message[MAX_SIZE_OF_MASSAGE];
	
	memset(message, 0, MAX_SIZE_OF_MASSAGE);

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
	
	return Status;
}


BL_Status BL_UART_Fetch_Host_Command(void)
{
	BL_Status Status = BL_OK;
	HAL_StatusTypeDef HAL_Status = HAL_OK;
	uint8_t Packet_Length = 0;
	
	memset(BL_Host_Buffer, 0, BL_HOST_BUFFER_RX_LENGTH);
	
	/* Read the length of the command packet received from the HOST */
	HAL_Status = HAL_UART_Receive(BL_HOST_COMMUNICATION_UART, BL_Host_Buffer, 1, HAL_MAX_DELAY);
	
	if(HAL_Status == HAL_OK)
	{
		BL_Print_Message("Packet length received from host !! \r\n");
		Packet_Length = BL_Host_Buffer[0];
		
		/* Read the command packet received from the HOST */
		HAL_Status = HAL_UART_Receive(BL_HOST_COMMUNICATION_UART, &BL_Host_Buffer[1], Packet_Length, HAL_MAX_DELAY);
		if(HAL_Status == HAL_OK)
		{
			switch(BL_Host_Buffer[1])
			{
				case CBL_GET_VER_CMD:
				{
					BL_Print_Message("Get Version \r\n");
					Bootloader_Get_Version(BL_Host_Buffer);
					Status = BL_OK;
					break;
				}
				case CBL_GET_HELP_CMD:
				{
					BL_Print_Message("Get Help \r\n");
					Bootloader_Get_Help(BL_Host_Buffer);
					Status = BL_OK;
					break;
				}
				case CBL_GET_CID_CMD:
				{
					Bootloader_Get_Chip_Identification_Number(BL_Host_Buffer);
					Status = BL_OK;
					break;
				}
				case CBL_GET_RDP_STATUS_CMD:
				{
					Bootloader_Read_Protection_Level(BL_Host_Buffer);
					Status = BL_OK;
					break;
				}
				case CBL_GO_TO_ADDR_CMD:
				{
					Bootloader_Jump_To_Address(BL_Host_Buffer);
					Status = BL_OK;
					break;
				}
				case CBL_FLASH_ERASE_CMD:
				{
					Bootloader_Erase_Flash(BL_Host_Buffer);
					Status = BL_OK;
					break;
				}
				case CBL_MEM_WRITE_CMD:
				{
					Bootloader_Memory_Write(BL_Host_Buffer);
					Status = BL_OK;
					break;
				}
				case CBL_ED_W_PROTECT_CMD:
				{
					BL_Print_Message("Enable or Disable write protect on different sectors of the user flash \r\n");
					Bootloader_Enable_RW_Protection(BL_Host_Buffer);
					Status = BL_OK;
					break;
				}
				case CBL_MEM_READ_CMD:
				{
					BL_Print_Message("Read data from different memories of the microcontroller \r\n");
					Bootloader_Memory_Read(BL_Host_Buffer);
					Status = BL_OK;
					break;
				}
				case CBL_READ_SECTOR_STATUS_CMD:
				{
					BL_Print_Message("Read all the sector protection status \r\n");
					Bootloader_Get_Sector_Protection_Status(BL_Host_Buffer);
					Status = BL_OK;
					break;
				}
				case CBL_OTP_READ_CMD:
				{
					BL_Print_Message("Read the OTP contents \r\n");
					Bootloader_Read_OTP(BL_Host_Buffer);
					Status = BL_OK;
					break;
				}
				case CBL_CHANGE_ROP_Level_CMD:
				{
					Bootloader_Change_Read_Protection_Level(BL_Host_Buffer);
					Status = BL_OK;
					break;
				}
				default:
				{
					BL_Print_Message("Invalid command code received from host !! \r\n");
					break;
				}
			}
		}
		else
		{
			BL_Print_Message("Error Reading the command packet received from the HOST !! \r\n");
			Status = BL_NACK;
		}
	}
	else
	{
		BL_Print_Message("Error Reading the length of the command packet received from the HOST !! \r\n");
		Status = BL_NACK;
	}
	
	return Status;
}























