#ifndef __DYNAMIXEL_DRV_H_
#define __DYNAMIXEL_DRV_H_

#include "dynamixel_com.h"
#include "dynamixel_status.h"
#include <stdint.h>

#define LENGTH_LOW(length) (length << 8)
#define LENGTH_HIGH(length) (length)

/* Dynamixel's instruction field possibile values */

/* Instruction that checks whether the Packet has arrived at a device with the same ID as the
 * specified packet ID */
#define DYNAMIXEL_INST_PING 0x01

/* Instruction to read data from the Device */
#define DYNAMIXEL_INST_READ 0x02

/* Instruction to write data to the Device */
#define DYNAMIXEL_INST_WRITE 0x03

/* 	Instruction to register the Instruction Packet in standby status; Packet can later be executed
 * using the Action command */
#define DYNAMIXEL_INST_REG_WRITE 0x04

/* Instruction to executes a Packet that was registered beforehand using Reg Write */
#define DYNAMIXEL_INST_ACTION 0x05

/* Instruction that resets the Control Table to its initial factory default settings */
#define DYNAMIXEL_INST_FACTORY_RESET 0x06

/* Instruction to reboot the Device */
#define DYNAMIXEL_INST_REBOOT 0x08

/* Instruction to reset certain information stored in memory */
#define DYNAMIXEL_INST_CLEAR 0x10

/* Instruction to store current Control Table status data to a Backup or to restore backup EEPROM
 * data. */
#define DYNAMIXEL_INST_CONTROL_TABLE_BACKUP 0x20

/* Return packet sent following the execution of an Instruction Packet */
#define DYNAMIXEL_INST_STATUS_RETURN 0x55

/* Instruction to read data from multiple devices with the same Address with the same length at once */
#define DYNAMIXEL_INST_SYNC_READ 0x82

/* Instruction to write data to multiple devices with the same Address with the same length at once */
#define DYNAMIXEL_INST_SYNC_WRITE 0x83

/* Instruction to read data from multiple devices with the same Address with the same length at once */
#define DYNAMIXEL_INST_FAST_SYNC_READ 0x8A

/* Instruction to read data from multiple devices with different Addresses with different lengths at
 * once */
#define DYNAMIXEL_INST_BULK_READ 0x92

/* Instruction to write data to multiple devices with different Addresses with different lengths at
 * once */
#define DYNAMIXEL_INST_BULK_WRITE 0x93

/* Instruction to read data from multiple devices with different Addresses with different lengths at
 * once */
#define DYNAMIXEL_INST_FAST_BULK_READ 0x9A

/* ====================================================================== */

/* Dynamixel's status packet's possibile errors */

/* Failed to process the sent Instruction Packet */
#define DYNAMIXEL_ERR_RESULT_FAIL 0x01

/* An undefined Instruction has been used. Action has been used without Reg Write */
#define DYNAMIXEL_ERR_INSTRUCTION_ERROR 0x02

/* The CRC of the sent Packet does not match the expected value */
#define DYNAMIXEL_ERR_CRC_ERROR 0x03

/* Data to be written to the specified Address is outside the range of the minimum/maximum value */
#define DYNAMIXEL_ERR_DATA_RANGE_ERROR 0x04

/* Attempted to write Data that is shorter than the required data length of the specified Address
(ex: when you attempt to only use 2 bytes of a register that has been defined as 4 bytes) */
#define DYNAMIXEL_ERR_DATA_LENGTH_ERROR 0x05

/* Data to be written to the specified Address is outside of the configured Limit value */
#define DYNAMIXEL_ERR_DATA_LIMIT_ERROR 0x06

/* Attempted to write a value to an Address that is Read Only or has not been defined
Attempted to read a value from an Address that is Write Only or has not been defined
Attempted to write a value to an EEPROM register while Torque was Enabled. */
#define DYNAMIXEL_ERR_ACCESS_ERROR 0x07

/* Maximum delay admitted between two bytes in the same packet (ms) */
#define MAXIMUM_BYTE_DELAY		1.5 /* Unused in library */

typedef union {
	struct {
		uint8_t header1;
		uint8_t header2;
		uint8_t header3;
		uint8_t reserved;
		uint8_t id; /* Range : 0 ~ 252 (0x00 ~ 0xFC), 254 (0xFE) is the broadcast id */
		uint16_t length;
		uint8_t instruction;
	};

	uint64_t raw;
} DynamixelInstHeader;

typedef struct {
	Dynamixel_COM_Handler com;
	uint8_t id;
} DynamixelDriverHandler;

DynamixelStatus Dynamixel_Driver_Init(DynamixelDriverHandler *handler, uint8_t id, DynamixelInterface interface);

DynamixelStatus Dynamixel_Driver_Write(DynamixelDriverHandler *handler, uint8_t *params, uint8_t params_len, uint8_t *err);

DynamixelStatus Dynamixel_Driver_Ping(DynamixelDriverHandler *handler, uint8_t *err);

#endif /* __DYNAMIXEL_DRV_H_ */