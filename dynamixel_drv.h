/**
 * @file dynamixel_drv.h
 * @brief Header file for the Dynamixel driver interface.
 *
 * This file defines the necessary structures, constants, and functions to
 * communicate with Dynamixel servos using 2.0 protocol.
 */

#ifndef __DYNAMIXEL_DRV_H_
#define __DYNAMIXEL_DRV_H_

#include <stdint.h>
#include "dynamixel_com.h"
#include "dynamixel_status.h"

/** @brief Macro to extract the low byte of the length field. */
#define LENGTH_LOW(length) (length << 8)

/** @brief Macro to extract the high byte of the length field. */
#define LENGTH_HIGH(length) (length)

/** @name Dynamixel Instruction Set */
/**@{*/
#define DYNAMIXEL_INST_PING 0x01	  /**< Check if the packet has arrived. */
#define DYNAMIXEL_INST_READ 0x02	  /**< Read data from the device. */
#define DYNAMIXEL_INST_WRITE 0x03	  /**< Write data to the device. */
#define DYNAMIXEL_INST_REG_WRITE 0x04 /**< Register an instruction packet for later execution. */
#define DYNAMIXEL_INST_ACTION 0x05	  /**< Execute a previously registered instruction. */
#define DYNAMIXEL_INST_FACTORY_RESET 0x06 /**< Reset the control table to factory settings. */
#define DYNAMIXEL_INST_REBOOT 0x08		  /**< Reboot the device. */
#define DYNAMIXEL_INST_CLEAR 0x10		  /**< Reset certain memory information. */
#define DYNAMIXEL_INST_CONTROL_TABLE_BACKUP 0x20 /**< Backup or restore EEPROM data. */
#define DYNAMIXEL_INST_STATUS_RETURN 0x55  /**< Return packet after executing an instruction. */
#define DYNAMIXEL_INST_SYNC_READ 0x82	   /**< Read data from multiple devices at once. */
#define DYNAMIXEL_INST_SYNC_WRITE 0x83	   /**< Write data to multiple devices at once. */
#define DYNAMIXEL_INST_FAST_SYNC_READ 0x8A /**< Fast synchronous read. */
#define DYNAMIXEL_INST_BULK_READ 0x92 /**< Read data from multiple devices with different addresses. */
#define DYNAMIXEL_INST_BULK_WRITE 0x93 /**< Write data to multiple devices with different addresses. */
#define DYNAMIXEL_INST_FAST_BULK_READ 0x9A /**< Fast bulk read. */
/**@}*/

/** @name Dynamixel Error Codes */
/**@{*/
#define DYNAMIXEL_ERR_RESULT_FAIL 0x01		 /**< Processing the instruction packet failed. */
#define DYNAMIXEL_ERR_INSTRUCTION_ERROR 0x02 /**< Undefined instruction used. */
#define DYNAMIXEL_ERR_CRC_ERROR 0x03		 /**< CRC does not match expected value. */
#define DYNAMIXEL_ERR_DATA_RANGE_ERROR 0x04	 /**< Data is outside valid range. */
#define DYNAMIXEL_ERR_DATA_LENGTH_ERROR 0x05 /**< Data length mismatch. */
#define DYNAMIXEL_ERR_DATA_LIMIT_ERROR 0x06	 /**< Data exceeds configured limit. */
#define DYNAMIXEL_ERR_ACCESS_ERROR 0x07		 /**< Attempted to access a restricted address. */
/**@}*/

/** @brief Maximum allowed delay between two bytes in the same packet (ms). */
#define MAXIMUM_BYTE_DELAY 1.5 /**< Unused in library. */

/**
 * @brief Structure representing a Dynamixel instruction header.
 */
typedef union {
	struct {
		uint8_t header1;	 /**< First header byte (0xFF). */
		uint8_t header2;	 /**< Second header byte (0xFF). */
		uint8_t header3;	 /**< Third header byte (0xFD). */
		uint8_t reserved;	 /**< Reserved byte (0x00). */
		uint8_t id;			 /**< Device ID (0-252, 254 for broadcast). */
		uint16_t length;	 /**< Length of packet data. */
		uint8_t instruction; /**< Instruction code. */
	};
	uint64_t raw; /**< Raw 64-bit representation. */
} DynamixelInstHeader;

/**
 * @brief Structure representing a Dynamixel driver handler.
 */
typedef struct {
	Dynamixel_COM_Handler com; /**< Communication handler. */
	uint8_t id;				   /**< Device ID. */
} DynamixelDriverHandler;

/**
 * @brief Initializes the Dynamixel driver handler.
 *
 * @param handler Pointer to the driver handler.
 * @param id Device ID.
 * @param interface Communication interface.
 * @return Dynamixel status code.
 */
DynamixelStatus Dynamixel_Driver_Init(DynamixelDriverHandler *handler, uint8_t id,
									  DynamixelInterface interface);

/**
 * @brief Sends a write instruction to the Dynamixel device.
 *
 * @param handler Pointer to the driver handler.
 * @param params Pointer to parameters.
 * @param params_len Number of parameters.
 * @param err Pointer to store error code.
 * @return Dynamixel status code.
 */
DynamixelStatus Dynamixel_Driver_Write(DynamixelDriverHandler *handler, uint8_t *params,
									   uint8_t params_len, uint8_t *err);

/**
 * @brief Sends a read instruction to the Dynamixel device.
 *
 * @param handler Pointer to the driver handler.
 * @param params Pointer to parameters.
 * @param params_len Number of parameters.
 * @param err Pointer to store error code.
 * @return Dynamixel status code.
 */
DynamixelStatus Dynamixel_Driver_Read(DynamixelDriverHandler *handler, uint8_t *params,
									  uint8_t params_len, uint8_t *err);

/**
 * @brief Sends a ping instruction to the Dynamixel device.
 *
 * @param handler Pointer to the driver handler.
 * @param err Pointer to store error code.
 * @return Dynamixel status code.
 */
DynamixelStatus Dynamixel_Driver_Ping(DynamixelDriverHandler *handler, uint8_t *err);

#endif /* __DYNAMIXEL_DRV_H_ */
