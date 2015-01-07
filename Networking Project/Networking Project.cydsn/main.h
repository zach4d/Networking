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
	
#define USB_BUFFER_LENGTH 64u
#define MAX_MESSAGE_LENGTH 127u
#define HEADER_LENGTH 8u
	
//message header info
#define MESSAGE_HEADER_START 0x7A
#define MESSAGE_HEADER_VERSION 0x01
#define MESSAGE_HEADER_SOURCE 0x2B
	
#include <project.h>

typedef int bool;
enum {false, true};
typedef enum {IDLE, BUSY, COLLISION} State;
void init();

#endif