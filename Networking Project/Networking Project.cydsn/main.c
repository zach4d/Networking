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
uint8 packetUSB[80];
uint8 *packetHex;
uint8 packetSend[80*8];
int i_usb = 0;
int i_send = 0;

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

CY_ISR(isr_sendingData)
{
	Transm_Output_Write(packetSend[i_send]);
	i_send++;
}

int main()
{
	// Initialize all components
	init();
	uint16 count;
	// main program loop
	for(;;)
    {
		// these states are switched in the various ISR's
		switch(currentState)
		{
			case IDLE:
				Timer_sendData_Stop();
				memset(packetSend,  0, (80*8));
				Pin_LEDBusy_Write(0);			
				Pin_LEDIdle_Write(1);
				Pin_LEDCollision_Write(0);
				
				//check message from usb
				if(USB_DataIsReady() != 0u)               /* Check for input data from PC */
	        	{   
		            count = USB_GetAll(packetUSB);           /* Read received data and re-enable OUT endpoint */
		            if(count != 0u)
		            {
		                while(USB_CDCIsReady() == 0u);    /* Wait till component is ready to send more data to the PC */
		                /* If the last sent packet is exactly maximum packet size, 
		                *  it shall be followed by a zero-length packet to assure the
		                *  end of segment is properly identified by the terminal.
		                */
		                if(count == 80)
		                {
		                    while(USB_CDCIsReady() == 0u); /* Wait till component is ready to send more data to the PC */ 
		                    USB_PutData(NULL, 0u);         /* Send zero-length packet to PC */
		                }
		            }
					//generate packet and send packet
					i_send = 0;
					i_usb = 0;
					int l;
					for(l = 0; l < count; l++)
					{
						//convert to hex
						sprintf(packetHex, "%x", packetUSB[l]);	
						uint8 packetBin[4];
						
						switch(*packetHex){
							case 0:
								packetBin[0] = 0;
								packetBin[1] = 0;
								packetBin[2] = 0;
								packetBin[3] = 0;
								break;
							case 1:
								packetBin[0] = 0;
								packetBin[1] = 0;
								packetBin[2] = 0;
								packetBin[3] = 1;
								break;
							case 2:
								packetBin[0] = 0;
								packetBin[1] = 0;
								packetBin[2] = 1;
								packetBin[3] = 0;
								break;
							case 3:
								packetBin[0] = 0;
								packetBin[1] = 0;
								packetBin[2] = 1;
								packetBin[3] = 1;
								break;
							case 4:
								packetBin[0] = 0;
								packetBin[1] = 1;
								packetBin[2] = 0;
								packetBin[3] = 0;
								break;
							case 5:
								packetBin[0] = 0;
								packetBin[1] = 1;
								packetBin[2] = 0;
								packetBin[3] = 1;
								break;
							case 6:
								packetBin[0] = 0;
								packetBin[1] = 1;
								packetBin[2] = 1;
								packetBin[3] = 0;
								break;
							case 7:
								packetBin[0] = 0;
								packetBin[1] = 1;
								packetBin[2] = 1;
								packetBin[3] = 1;
								break;
							case 8:
								packetBin[0] = 1;
								packetBin[1] = 0;
								packetBin[2] = 0;
								packetBin[3] = 0;
								break;
							case 9:
								packetBin[0] = 1;
								packetBin[1] = 0;
								packetBin[2] = 0;
								packetBin[3] = 1;
								break;
							case 'A':
								packetBin[0] = 1;
								packetBin[1] = 0;
								packetBin[2] = 1;
								packetBin[3] = 0;
								break;
							case 'B':
								packetBin[0] = 1;
								packetBin[1] = 0;
								packetBin[2] = 1;
								packetBin[3] = 1;
								break;
							case 'C':
								packetBin[0] = 1;
								packetBin[1] = 1;
								packetBin[2] = 0;
								packetBin[3] = 0;
								break;
							case 'D':
								packetBin[0] = 1;
								packetBin[1] = 1;
								packetBin[2] = 0;
								packetBin[3] = 1;
								break;
							case 'E':
								packetBin[0] = 1;
								packetBin[1] = 1;
								packetBin[2] = 1;
								packetBin[3] = 0;
								break;
							case 'F':
								packetBin[0] = 1;
								packetBin[1] = 1;
								packetBin[2] = 1;
								packetBin[3] = 1;
								break;
							default:
								break;
						}
						int l2;
						for(l2 = 0; l2 <4; l2++)
						{
							packetSend[i_send + l2] = packetBin[l2]; 	
						}
						i_send++;
					}
					
					Timer_sendData_Start();
	        	}
				
				
				break;
				
			case BUSY:
				Pin_LEDBusy_Write(1);			
				Pin_LEDIdle_Write(0);
				Pin_LEDCollision_Write(0);
				break;

			case COLLISION:	
				Timer_sendData_Stop();
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
	
	isr_sendData_StartEx(isr_sendingData);
	
	    /* Start USBFS Operation with 3V operation */
    USB_Start(0u, USB_3V_OPERATION);
	 /* Wait for Device to enumerate */
    while(!USB_GetConfiguration());

    /* Enumeration is done, enable OUT endpoint for receive data from Host */
    USB_CDC_Init();
	
	//Init Components
	//Timer_BusyToCollision_Start();
	//Timer_BusyToIdle_Start();
	
		
}