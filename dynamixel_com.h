/**
 * @file dynamixel_com.h
 * @brief Communication interface for Dynamixel devices.
 *
 * This module provides functions for initializing and handling communication
 * with Dynamixel devices using a specified serial interface.
 */

#ifndef __DYNAMIXEL_COM_H_
#define __DYNAMIXEL_COM_H_

#include "dynamixel_status.h"

#include <stdint.h>

/**
 * @typedef DynamixelSerialTransmitFunction
 * @brief Function pointer type for transmitting data over the serial interface.
 *
 * @param buf Pointer to the data buffer to be transmitted.
 * @param len Length of the data buffer.
 * @param timeout Transmission timeout in milliseconds.
 * @return Status of the transmission operation.
 */
typedef DynamixelStatus (*DynamixelSerialTransmitFunction)(uint8_t *buf, uint16_t len,
														   uint16_t timeout);

/**
 * @typedef DynamixelSerialReceiveFunction
 * @brief Function pointer type for receiving data over the serial interface.
 *
 * @param buf Pointer to the buffer to store received data.
 * @param len Expected length of data to receive.
 * @param timeout Reception timeout in milliseconds.
 * @return Status of the reception operation.
 */
typedef DynamixelStatus (*DynamixelSerialReceiveFunction)(uint8_t *buf, uint16_t len,
														  uint16_t timeout);

/**
 * @struct DynamixelInterface
 * @brief Structure representing the serial communication interface.
 *
 * This structure holds function pointers for transmitting and receiving data
 * over the Dynamixel communication interface.
 */
typedef struct {
	DynamixelSerialTransmitFunction transmit; /**< Function pointer for transmission. */
	DynamixelSerialReceiveFunction receive;	  /**< Function pointer for reception. */
} DynamixelInterface;

/**
 * @struct Dynamixel_COM_Handler
 * @brief Handler structure for Dynamixel communication.
 *
 * This structure encapsulates the communication interface for interacting
 * with Dynamixel devices.
 */
typedef struct {
	DynamixelInterface interface; /**< Serial communication interface. */
} Dynamixel_COM_Handler;

/**
 * @brief Initializes the Dynamixel communication handler.
 *
 * @param handler Pointer to the Dynamixel communication handler.
 * @param interface Communication interface containing transmit and receive functions.
 * @return Status of the initialization operation.
 */
DynamixelStatus Dynamixel_COM_Init(Dynamixel_COM_Handler *handler, DynamixelInterface interface);

/**
 * @brief Transmits data using the Dynamixel communication interface.
 *
 * @param handler Pointer to the Dynamixel communication handler.
 * @param data Pointer to the data buffer to be transmitted.
 * @param len Length of the data buffer.
 * @param timeout Transmission timeout in milliseconds.
 * @return Status of the transmission operation.
 */
DynamixelStatus Dynamixel_COM_Transmit(Dynamixel_COM_Handler *handler, uint8_t *data, uint16_t len,
									   uint16_t timeout);

/**
 * @brief Receives data using the Dynamixel communication interface.
 *
 * @param handler Pointer to the Dynamixel communication handler.
 * @param data Pointer to the buffer to store received data.
 * @param len Expected length of data to receive.
 * @param timeout Reception timeout in milliseconds.
 * @return Status of the reception operation.
 */
DynamixelStatus Dynamixel_COM_Receive(Dynamixel_COM_Handler *handler, uint8_t *data, uint16_t len,
									  uint16_t timeout);

#endif /* __DYNAMIXEL_COM_H_ */
