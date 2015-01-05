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
#include <project.h>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#include "main.h"

// the state variable
State currentState = IDLE;


CY_ISR(isr_FallingEdgeDetected)
{	
	Timer_BusyToCollision_WriteCounter(11292);
	currentState = BUSY;
	Timer_BusyToCollision_Start();
}

CY_ISR(isr_RisingEdgeDetected)
{
	Timer_BusyToIdle_WriteCounter(11292);
	currentState = BUSY;
	Timer_BusyToIdle_Start();
}

// Fires when the line has been high too long, Back to Idle
CY_ISR(isr_BusyToIdle)
{
	Timer_BusyToIdle_WriteCounter(11292);
	currentState = IDLE;
}

// Fires when the line has been low too long, Go to Collision
CY_ISR(isr_BusyToCollision)
{
	Timer_BusyToCollision_WriteCounter(11292);
	currentState = COLLISION;
}


int main()
{
	// Initialize all components
	init();
	
	// main program loop
	for(;;)
    {
		// these states are switched in the various ISR's
		switch(currentState)
		{
			case IDLE:
				Pin_LEDBusy_Write(0);			
				Pin_LEDIdle_Write(1);
				Pin_LEDCollision_Write(0);
				break;
				
			case BUSY:
				Pin_LEDBusy_Write(1);			
				Pin_LEDIdle_Write(0);
				Pin_LEDCollision_Write(0);
				break;

			case COLLISION:			
				Pin_LEDBusy_Write(0);			
				Pin_LEDIdle_Write(0);
				Pin_LEDCollision_Write(1);
				break;
		}
	}
}

void init()
{	
	//Enable Global Interrupts
	CYGlobalIntEnable;
	
	//Init isr
	isr_BusyToCollision_StartEx(isr_BusyToCollision);
	isr_BusyToIdle_StartEx(isr_BusyToIdle);
	
	isr_RisingEdge_StartEx(isr_RisingEdgeDetected);
	isr_FallingEdge_StartEx(isr_FallingEdgeDetected);
	
	//Init Components
	//Timer_BusyToCollision_Start();
	//Timer_BusyToIdle_Start();
	
	
	
}