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
#include <stdbool.h>

#include "main.h"



//usb and sending data
char buffer[];
char usb[80];
char hex[80*2];
uint8 packetBin[4];
uint8 packetSend[80*8];
unsigned int dec;
int messageSize = 0;
bool returnFound = false;
bool messageReady;

int signal = 1;

char packetUSB[80];
char packetMessage[80];
char packetHex[80*2];
uint8 packetBinary[4];
bool dataReady = false;
int i_send = 0;
uint8 messageBufferPosition = 0;

	// the state variable
State currentState = IDLE;

void printbinchar(char c)
{
	int counter;
	for(counter = 7; counter >= 0; --counter)
	{
		//USB_PutChar( (c & (1 << counter)) ? '1' : '0' );	
	}
	USB_PutChar('\r');
}

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

CY_ISR(isr_sendData)
{
	if(signal == 1)
	{
		signal = 0;
		if(messageSize < i_send)
		{
			//end of message
			Timer_sendData_Stop();
			Transm_Output_Write(1);
			messageSize = 0;
			return;
		}
		if(packetSend[messageSize] == '0')
		{
			while(USB_CDCIsReady() == 0u);
			USB_PutChar('a');
			
			Transm_Output_Write(0);
		}else{
			Transm_Output_Write(1);
		}
		
	}else{
		signal = 1;
		Transm_Output_Write(!Transm_Output_Read());
		messageSize++;
	}
	Timer_sendData_WriteCounter(Timer_sendData_ReadPeriod());
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
void printCharAsBinary(char c) {
	int i;
	for(i = 0; i < 8; i++){
		USB_PutChar((c >> i) & 0x1);
	}
}
 
void printStringAsBinary(char* s){
	for(; *s; s++){
		printCharAsBinary(*s);
		USB_PutChar(' ');
	}
	USB_PutChar('\n');
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
				if(USB_DataIsReady() != 0u)               /* Check for input data from PC */
	       		{   
		           count = USB_GetAll(buffer);           /* Read received data and re-enable OUT endpoint */
		          if(count != 0u)
		           {    
					
				
						//while(USB_CDCIsReady() == 0u); /* Wait till component is ready to send more data to the PC */
			              //USB_PutData(buffer, count);         /* Send zero-length packet to PC */
						int counter;
						for(counter = 0; counter < count && messageReady == false; counter++)
						{
							while(USB_CDCIsReady() ==0u);
							USB_PutChar(buffer[counter]);
							usb[messageSize] = buffer[counter];
							
						
							
							messageSize++;
							if(buffer[counter] == '\r'){
								messageReady = true;
							}
						}
					
					
				
					}
				}
				
				if(messageReady)
				{
	
					//cout << "usb: " <<endl;
					int i;
					for(i = 0; usb[i] != '\r'; i++)
					{
						//cout<<"char "<<usb[i]<<endl;
						
						while(USB_CDCIsReady() == 0u);
								USB_PutData("char ", 5);
								while(USB_CDCIsReady() == 0u);
								USB_PutChar(usb[i]);
								while(USB_CDCIsReady() == 0u);
								USB_PutChar('\r');
								while(USB_CDCIsReady() == 0u);
								USB_PutChar('\n');
							
								dec = (unsigned int)usb[i];
								
								//cout<< "index: " << i << " @ " << usb[i] <<endl;
								//cout <<"dec "<< dec << endl;
								
								while(USB_CDCIsReady() == 0u);
								USB_PutData("dec ", 4);
								while(USB_CDCIsReady() == 0u);
								USB_PutChar(dec);
								while(USB_CDCIsReady() == 0u);
								USB_PutChar('\r');
								while(USB_CDCIsReady() == 0u);
								USB_PutChar('\n');
								
								decimal_hex(dec, hex);
								int i2;
								for(i2 = 0; hex[i2] != '\0'; i2++)
								{
									//cout << "hex " << hex[i2] << endl;
									
									while(USB_CDCIsReady() == 0u);
									USB_PutData("hex ", 4);
									while(USB_CDCIsReady() == 0u);
									USB_PutChar(hex[i2]);
									USB_PutChar('\r');
									while(USB_CDCIsReady() == 0u);
									USB_PutChar('\n');
									
									//conver to binary
									if(hex[i2] == '0'){
										packetBin[0] = '0';
										packetBin[1] = '0';
										packetBin[2] = '0';
										packetBin[3] = '0';
									}else if(hex[i2] =='1'){
										packetBin[0] = '0';
										packetBin[1] = '0';
										packetBin[2] = '0';
										packetBin[3] = '1';
									}else if(hex[i2] == '2'){
										packetBin[0] = '0';
										packetBin[1] = '0';
										packetBin[2] = '1';
										packetBin[3] = '0';
									}else if(hex[i2] == '3'){
										packetBin[0] = '0';
										packetBin[1] = '0';
										packetBin[2] = '1';
										packetBin[3] = '1';
									}else if(hex[i2] == '4'){
										packetBin[0] = '0';
										packetBin[1] = '1';
										packetBin[2] = '0';
										packetBin[3] = '0';
									}else if(hex[i2] == '5'){
										packetBin[0] = '0';
										packetBin[1] = '1';
										packetBin[2] = '0';
										packetBin[3] = '1';
									}else if(hex[i2] == '6'){
										packetBin[0] = '0';
										packetBin[1] = '1';
										packetBin[2] = '1';
										packetBin[3] = '0';
									}else if(hex[i2] == '7'){
										packetBin[0] = '0';
										packetBin[1] = '1';
										packetBin[2] = '1';
										packetBin[3] = '1';
									}else if(hex[i2] == '8'){
										packetBin[0] = '1';
										packetBin[1] = '0';
										packetBin[2] = '0';
										packetBin[3] = '0';
									}else if(hex[i2] == '9'){
										packetBin[0] = '1';
										packetBin[1] = '0';
										packetBin[2] = '0';
										packetBin[3] = '1';
									}else if(hex[i2] == 'A'){
										packetBin[0] = '1';
										packetBin[1] = '0';
										packetBin[2] = '1';
										packetBin[3] = '0';
									}else if(hex[i2] == 'B'){
										packetBin[0] = '1';
										packetBin[1] = '0';
										packetBin[2] = '1';
										packetBin[3] = '1';
									}else if(hex[i2] == 'C'){
										packetBin[0] = '1';
										packetBin[1] = '1';
										packetBin[2] = '0';
										packetBin[3] = '0';
									}else if(hex[i2] =='D'){
										packetBin[0] = '1';
										packetBin[1] = '1';
										packetBin[2] = '0';
										packetBin[3] = '1';
									}else if(hex[i2] == 'E'){
										packetBin[0] = '1';
										packetBin[1] = '1';
										packetBin[2] = '1';
										packetBin[3] = '0';
									}else {
										packetBin[0] = '1';
										packetBin[1] = '1';
										packetBin[2] = '1';
										packetBin[3] = '1';
									}
						
								int l2;
								for(l2 = 0; l2 <4; l2++)
								{
									packetSend[i_send + l2] = packetBin[l2]; 	
									//cout << "binary " << packetBin[l2] << " position" << i_send+l2 <<endl;
								}
								i_send +=4;
								//cout<<"i_send " << i_send << endl;
						
							}
							packetSend[i_send] = '\r';
							while(USB_CDCIsReady() == 0u);
							USB_PutChar(i_send);
							
							messageReady = false;
							messageSize = 0;
						}//start of conversion
						//cout<<"full "<< endl;
						
						
						while(USB_CDCIsReady() == 0u);
						USB_PutData("full ", 5);
						while(USB_CDCIsReady() == 0u);
						USB_PutChar('\r');
						while(USB_CDCIsReady() == 0u);
						USB_PutChar('\n');
					
						int i3;
						
						for(i3 = 0; packetSend[i3] != '\r'; i3++)
						{
							if(i3 != 0 && i3%8 == 0)
							{
								//cout<<" ";
								
								while(USB_CDCIsReady() == 0u);
								USB_PutChar(' ');
								
								
							}
							//cout << packetSend[i3];
							while(USB_CDCIsReady() == 0u);
							USB_PutChar(packetSend[i3]);
							/*
							if(packetSend[i3] == '0')
							{
								Transm_Output_Write(0);
							}else{
								Transm_Output_Write(1);
							}
							*/
						}
				
					Timer_sendData_WriteCounter(Timer_sendData_ReadPeriod());
					Timer_sendData_Start();
					}//messageReady
					
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
	
	memset(usb, '0', 80);
	memset(hex, '0', (80*2));
	memset(packetBin, '0', 4);
	memset(packetSend, '0', (80*8));
	
	messageReady = false;

	//Enable Global Interrupts
	CYGlobalIntEnable;
	
	//Init isr
	isr_BusyToCollision_StartEx(isr_BusyToCollision);
	isr_BusyToIdle_StartEx(isr_BusyToIdle);
	
	isr_RisingEdge_StartEx(isr_RisingEdgeDetected);
	isr_FallingEdge_StartEx(isr_FallingEdgeDetected);
	
	//Timer_sendData_Start();
	//Timer_sendData_Stop();
	
	
	isr_sendData_StartEx(isr_sendData);
	
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

