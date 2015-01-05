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
#include <project.h>

typedef int bool;
enum {false, true};
typedef enum {IDLE, BUSY, COLLISION} State;
void init();

#endif