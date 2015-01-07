/* ========================================
 *
 * Copyright YOUR COMPANY, THE YEAR
 * All Rights Reserved
 * UNPUBLISHED, LICENSED SOFTWARE.
 *
 * CONFIDENTIAL AND PROPRIETARY INFORMATION
 * WHICH IS THE PROPERTY OF your company.
 *
 * ========================================
*/

#ifndef MAIN_H
#define MAIN_H
	
#define USB_BUFFER_LENGTH 80u
#define MAX_MESSAGE_LENGTH 74u
#define HEADER_LENGTH 6u
	
//message header info
#define MESSAGE_HEADER_START 0x75
#define MESSAGE_HEADER_VERSION 0x01
#define MESSAGE_HEADER_SOURCE 0x01
#define MESSAGE_HEADER_Destination 0x01
#define MESSAGE_HEADER_CRCUSAGE 0x00
#define MESSAGE_HEADER_CRC 0x7E
	
#include <project.h>

typedef int bool;
enum {false, true};
typedef enum {IDLE, BUSY, COLLISION} State;
void init();

#endif