#include "dynamixel_com.h"

DynamixelStatus Dynamixel_COM_Init(Dynamixel_COM_Handler* handler, DynamixelInterface interface) {
	handler->interface.transmit = interface.transmit;
	handler->interface.receive = interface.receive;
}

DynamixelStatus Dynamixel_COM_Transmit(Dynamixel_COM_Handler* handler, uint8_t* data, uint16_t len,
									   uint16_t timeout) {

	DynamixelStatus status = handler->interface.transmit(data, len, timeout);

	return status;
}

DynamixelStatus Dynamixel_COM_Receive(Dynamixel_COM_Handler* handler, uint8_t* data, uint16_t len,
									  uint16_t timeout) {

	DynamixelStatus status = handler->interface.receive(data, len, timeout);

	return status;
}
