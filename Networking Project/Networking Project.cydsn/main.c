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

//usb and sending data
char packetUSB[80];
char packetMessage[80];
char packetHex[80*2];
uint8 packetBinary[4];
uint8 packetSend[80*8];
uint8 dec;
uint8 flag = 1;
bool dataReady = false;
int i_send = 0;
uint8 messageBufferPosition = 0;

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
	//flag = !flag;
	//Transm_Output_Write(flag);
	Transm_Output_Write(packetSend[i_send]);
	//USB_PutData(packetSend[i_send], 1);
	i_send++;
}

void mystrrev(char hex[])
{
	int length;
	for(length = 0; hex[length] != '\0'; ++length);
	
	char temp[length];
	strcpy(temp, hex);
	int i, i2;
	i2 = length-1;
	for(i = 0; i <length; i++)
	{
		hex[i] = temp[i2];	
		i2--;
	}
}

void decimal_hex(int n, char hex[]) /* Function to convert decimal to hexadecimal. */
{
    int i=0,rem;
    while (n!=0)
    {
        rem=n%16;
        switch(rem)
        {
            case 10:
              hex[i]='A';
              break;
            case 11:
              hex[i]='B';
              break;
            case 12:
              hex[i]='C';
              break;
            case 13:
              hex[i]='D';
              break;
            case 14:
              hex[i]='E';
              break;
            case 15:
              hex[i]='F';
              break;
            default:
              hex[i]=rem+'0';
              break;
        }
        ++i;
        n/=16;
    }
    hex[i]='\0';
    mystrrev(hex);   /* Reverse string */
}



int main()
{
	// Initialize all components
	init();
	uint16 count;
	bool messageReady = false;
	uint16 forLoopCounter;
	// main program loop
	for(;;)
    {
		// these states are switched in the various ISR's
		switch(currentState)
		{
			case IDLE:
			/****************************************
			uncommented as the current state was not changing
			*********************************************/
			/*
			if(i_send == 0 || i_send == forLoopCounter)
			{
				Timer_sendData_Sleep();
			}
			*/
			
			/*
				Transm_Output_Write(1);
			*/
				dataReady = false;
			
				memset(packetSend,  0, (80*8));
				Pin_LEDBusy_Write(0);			
				Pin_LEDIdle_Write(1);
				Pin_LEDCollision_Write(0);
				/*****************************************************************************
				
				The USB need to watch for the return key before it creates the buffer
				Currently it fires on every key press (1/8/2015) James Maki
				
				******************************************************************************/
				
				
				//check message from usb
				if(USB_DataIsReady() != 0u)               /* Check for input data from PC */
	       	{   
		           count = USB_GetAll(packetUSB);           /* Read received data and re-enable OUT endpoint */
		           if(count != 0u)
		           {
						for(forLoopCounter=0; forLoopCounter<count;forLoopCounter++)
						//USB_PutData(packetUSB, count); 
		               /* If the last sent packet is exactly maximum packet size, 
		               *  it shall be followed by a zero-length packet to assure the
		               *  end of segment is properly identified by the terminal.
		               */
		               if(packetUSB[forLoopCounter] == '\r' || count == 80)
		               {
							messageReady = true;
		                   packetMessage[messageBufferPosition] = 0;
							messageBufferPosition=0;
							}
						else{
							messageReady = false;
							messageBufferPosition++;
							packetMessage[messageBufferPosition]=0;
						}
		           }
					while(USB_CDCIsReady() == 0u); /* Wait till component is ready to send more data to the PC */
		                   USB_PutData(packetUSB, count);         /* Send zero-length packet to PC */
					//generate packet and send packet
					i_send = 0;

					
					int l, l2;
					for(l = 0; packetMessage[l] != '\0'; l++)
					{
						dec = (unsigned int) packetUSB[l];
						USB_PutChar((char *)dec);
					
						decimal_hex(dec, packetHex);
						
						for(l2 = 0; packetHex[l2] != '\0'; l2++)
						{
							if(packetHex[l2] == '0'){
								packetBinary[0] = 0;
								packetBinary[1] = 0;
								packetBinary[2] = 0;
								packetBinary[3] = 0;
							}else if(packetHex[l2] == '1'){
								packetBinary[0] = 0;
								packetBinary[1] = 0;
								packetBinary[2] = 0;
								packetBinary[3] = 1;
							}else if(packetHex[l2] == '2'){
								packetBinary[0] = 0;
								packetBinary[1] = 0;
								packetBinary[2] = 1;
								packetBinary[3] = 0;
							}else if(packetHex[l2] == '3'){
								packetBinary[0] = 0;
								packetBinary[1] = 0;
								packetBinary[2] = 1;
								packetBinary[3] = 1;
							}else if(packetHex[l2] == '4'){
								packetBinary[0] = 0;
								packetBinary[1] = 1;
								packetBinary[2] = 0;
								packetBinary[3] = 0;
							}else if(packetHex[l2] == '5'){
								packetBinary[0] = 0;
								packetBinary[1] = 1;
								packetBinary[2] = 0;
								packetBinary[3] = 1;
							}else if(packetHex[l2] == '6'){
								packetBinary[0] = 0;
								packetBinary[1] = 1;
								packetBinary[2] = 1;
								packetBinary[3] = 0;
							}else if(packetHex[l2] == '7'){
								packetBinary[0] = 0;
								packetBinary[1] = 1;
								packetBinary[2] = 1;
								packetBinary[3] = 1;
							}else if(packetHex[l2] == '8'){
								packetBinary[0] = 1;
								packetBinary[1] = 0;
								packetBinary[2] = 0;
								packetBinary[3] = 0;
							}else if(packetHex[l2] == '9'){
								packetBinary[0] = 1;
								packetBinary[1] = 0;
								packetBinary[2] = 0;
								packetBinary[3] = 1;
							}else if(packetHex[l2] == 'A'){
								packetBinary[0] = 1;
								packetBinary[1] = 0;
								packetBinary[2] = 1;
								packetBinary[3] = 0;
							}else if(packetHex[l2] == 'B'){
								packetBinary[0] = 1;
								packetBinary[1] = 0;
								packetBinary[2] = 1;
								packetBinary[3] = 1;
							}else if(packetHex[l2] == 'C'){
								packetBinary[0] = 1;
								packetBinary[1] = 1;
								packetBinary[2] = 0;
								packetBinary[3] = 0;
							}else if(packetHex[l2] =='D'){
								packetBinary[0] = 1;
								packetBinary[1] = 1;
								packetBinary[2] = 0;
								packetBinary[3] = 1;
							}else if(packetHex[l2] == 'E'){
								packetBinary[0] = 1;
								packetBinary[1] = 1;
								packetBinary[2] = 1;
								packetBinary[3] = 0;
							}else {
								packetBinary[0] = 1;
								packetBinary[1] = 1;
								packetBinary[2] = 1;
								packetBinary[3] = 1;
							}
						
							int l3;
							for(l3 = 0; l3 <4; l3++)
							{
								packetSend[i_send + l3] = packetBinary[l3];
								
							}//generates binary values
							
							i_send++;
						}
					}
					dataReady = true;
	        	}
				
				if(dataReady && messageReady){ 
					i_send = 0;
					//Transm_Output_Write(0); /* uncomment this line to see that Output change on each key pressed*/
					USB_PutChar('\r');
							USB_PutChar('\n');
							
					Timer_sendData_Enable();
					
				}
				break;
			case BUSY:
				Pin_LEDBusy_Write(1);			
				Pin_LEDIdle_Write(0);
				Pin_LEDCollision_Write(0);
				break;

			case COLLISION:	
				Timer_sendData_Sleep();
				Transm_Output_Write(1);
				dataReady = false;
				Pin_LEDBusy_Write(0);			
				Pin_LEDIdle_Write(0);
				Pin_LEDCollision_Write(1);
				break;
		}
	}
}

void init()
{	
	Transm_Output_Write(1);
	//Enable Global Interrupts
	CYGlobalIntEnable;
	
	//Init isr
	isr_BusyToCollision_StartEx(isr_BusyToCollision);
	isr_BusyToIdle_StartEx(isr_BusyToIdle);
	
	isr_RisingEdge_StartEx(isr_RisingEdgeDetected);
	isr_FallingEdge_StartEx(isr_FallingEdgeDetected);
	
	Timer_sendData_Start();
	Timer_sendData_Sleep();
	
	
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