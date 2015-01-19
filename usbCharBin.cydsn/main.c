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
char usb[80];
char hex[80*2];
char packetBin[4];
char packetSend[80*8];
unsigned int dec;
uint8 messageSize = 0;

uint8 rxData;

//memset(usb, '0', 80);
//memset(hex, '0', (80*2));
//memset(packetBin, '0', 4);
//memset(packetSend, '0', (80*8));

char buffer[];
//char packetMessage[80];
//char packetHex[80*2];
//uint8 packetBinary[4];
//uint8 packetSend[80*8];
//uint8 dec;
//uint8 flag = 1;
bool returnFound = false;
bool dataReady = false;
int i_send = 0;

uint8 messageBufferPosition = 0;
bool messageReady;

CY_ISR(isr_sendingData)
{
	//flag = !flag;
	//Transm_Output_Write(flag);
//	Transm_Output_Write(packetSend[i_send]);
	i_send++;
}

int hex_decimal(char hex[])   /* Function to convert hexadecimal to decimal. */
{
  int i, length, sum=0;
    for(length=0; hex[length]!='\0'; ++length);
    for(; hex[i]!='\0'; ++i, --length)
    {
        if(hex[i]>='0' && hex[i]<='9')
            sum+=(hex[i]-'0')*pow(16,length-1);
        if(hex[i]>='A' && hex[i]<='F')
            sum+=(hex[i]-55)*pow(16,length-1);
        if(hex[i]>='a' && hex[i]<='f')
            sum+=(hex[i]-87)*pow(16,length-1);
    }
    return sum;
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
    //strrev(hex);
	mystrrev(hex);   /* Reverse string */
}



int main()
{
	// Initialize all components
	init();
	uint16 count;
	
	uint16 forLoopCounter;
	// main program loop
	
	for(;;)
    {
		// these states are switched in the various ISR's
		
			
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
			
				//memset(packetSend,  0, (80*8));
				//Pin_LEDBusy_Write(0);			
				//Pin_LEDIdle_Write(1);
				//Pin_LEDCollision_Write(0);
				/*****************************************************************************
				
				The USB need to watch for the return key before it creates the buffer
				Currently it fires on every key press (1/8/2015) James Maki
				
				******************************************************************************/
				
				//check message from usb
		
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
				
				
				
							
				
if(messageReady){
	
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
					}else if(hex[i2] == '1'){
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
	
			messageReady = false;
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
			if(i3%8 == 0)
			{
				//cout<<" ";
				
				while(USB_CDCIsReady() == 0u);
				USB_PutChar(' ');
				
				
			}
			//cout << packetSend[i3];
			
			while(USB_CDCIsReady() == 0u);
			USB_PutChar(packetSend[i3]);
			
		}
	
	}//messageReady
				
	}//for()
}

void init()
{		
	
	memset(usb, '0', 80);
	memset(hex, '0', (80*2));
	memset(packetBin, '0', 4);
	memset(packetSend, '0', (80*8));
	
	messageReady = false;
	//Transm_Output_Write(1);
	//Enable Global Interrupts
	CYGlobalIntEnable;
	
	//Init isr
//	isr_BusyToCollision_StartEx(isr_BusyToCollision);
//	isr_BusyToIdle_StartEx(isr_BusyToIdle);
	
//	isr_RisingEdge_StartEx(isr_RisingEdgeDetected);
//	isr_FallingEdge_StartEx(isr_FallingEdgeDetected);
	
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

