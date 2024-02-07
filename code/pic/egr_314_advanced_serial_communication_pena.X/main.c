/**
  Generated Main Source File

  Company:
    Microchip Technology Inc.

  File Name:
    main.c

  Summary:
    This is the main file generated using PIC10 / PIC12 / PIC16 / PIC18 MCUs

  Description:
    This header file provides implementations for driver APIs for all modules selected in the GUI.
    Generation Information :
        Product Revision  :  PIC10 / PIC12 / PIC16 / PIC18 MCUs - 1.81.8
        Device            :  PIC18F47Q10
        Driver Version    :  2.00
*/

/*
    (c) 2018 Microchip Technology Inc. and its subsidiaries. 
    
    Subject to your compliance with these terms, you may use Microchip software and any 
    derivatives exclusively with Microchip products. It is your responsibility to comply with third party 
    license terms applicable to your use of third party software (including open source software) that 
    may accompany Microchip software.
    
    THIS SOFTWARE IS SUPPLIED BY MICROCHIP "AS IS". NO WARRANTIES, WHETHER 
    EXPRESS, IMPLIED OR STATUTORY, APPLY TO THIS SOFTWARE, INCLUDING ANY 
    IMPLIED WARRANTIES OF NON-INFRINGEMENT, MERCHANTABILITY, AND FITNESS 
    FOR A PARTICULAR PURPOSE.
    
    IN NO EVENT WILL MICROCHIP BE LIABLE FOR ANY INDIRECT, SPECIAL, PUNITIVE, 
    INCIDENTAL OR CONSEQUENTIAL LOSS, DAMAGE, COST OR EXPENSE OF ANY KIND 
    WHATSOEVER RELATED TO THE SOFTWARE, HOWEVER CAUSED, EVEN IF MICROCHIP 
    HAS BEEN ADVISED OF THE POSSIBILITY OR THE DAMAGES ARE FORESEEABLE. TO 
    THE FULLEST EXTENT ALLOWED BY LAW, MICROCHIP'S TOTAL LIABILITY ON ALL 
    CLAIMS IN ANY WAY RELATED TO THIS SOFTWARE WILL NOT EXCEED THE AMOUNT 
    OF FEES, IF ANY, THAT YOU HAVE PAID DIRECTLY TO MICROCHIP FOR THIS 
    SOFTWARE.
*/

#include "mcc_generated_files/mcc.h"
#include <stdio.h>
#include <stdint.h>
#include <stdbool.h>
#include <xc.h>




/*
typedef enum { 
    SPI1_DEFAULT
} spi1_modes_t;
*/

char data[100];

// SPI1_ExchangeByte();

uint8_t arr[8]; 

uint8_t N = 8; //Bytes
uint8_t X; // Delay in ms0x11000000
uint8_t Y; // Delay in ms

//uint8_t spi_tx = 0x11000000;
uint8_t spi_tx = 192;
uint8_t spi_rx;

void decToBinary(int n) 
{ 
    // array to store binary number 
    int binaryNum[32]; 

    // counter for binary array 
    int i = 0; 
    while (n > 0) { 

        // storing remainder in binary array 
        binaryNum[i] = n % 2; 
        n = n / 2; 
        i++; 
    } 

    // printing binary array in reverse order 
    for (int j = i - 1; j >= 0; j--) 
        printf("%d ", binaryNum[j]); 
}



void main(void)
{
    // Initialize the device
    SYSTEM_Initialize();
    SPI1_Initialize();
    

    // If using interrupts in PIC18 High/Low Priority Mode you need to enable the Global High and Low Interrupts
    // If using interrupts in PIC Mid-Range Compatibility Mode you need to enable the Global and Peripheral Interrupts
    // Use the following macros to:

    // Enable the Global Interrupts
    //INTERRUPT_GlobalInterruptEnable();

    // Disable the Global Interrupts
    //INTERRUPT_GlobalInterruptDisable();

    // Enable the Peripheral Interrupts
    //INTERRUPT_PeripheralInterruptEnable();

    // Disable the Peripheral Interrupts
    //INTERRUPT_PeripheralInterruptDisable();

    
    SPI1_Open(SPI1_DEFAULT);
    //SPI1_Open(spi_tx);
    
    /*
     CSN_SetHigh();
    DIS_SetLow();
    DIR_SetHigh();
    PWM_SetHigh();
     
     */
    
    char temp = 0;
    SYSTEM_Initialize();
    CSN_SetHigh();
    SPI1_Open(SPI1_DEFAULT);
    
    while (1)
    {
        
        /*
         CSN_SetLow();
        //SPI1_WriteByte(spi_tx);
        spi_rx = SPI1_ReadByte();
        //spi_rx = spi_tx;
        CSN_SetHigh();
        
        // PWM_SetLow();
       
        
        printf("SPI Data Bytes: ");
        decToBinary(spi_rx);
        printf("\r\n");
              
        //Delay(50);
         */
        
        CSN_SetLow();
        __delay_ms(10);
        data[0]=0b11101111;
        SPI1_ExchangeBlock(data, 1);
        __delay_ms(100);
        CSN_SetHigh();
        //Forward 
        
        spi_rx = SPI1_ReadByte();
        printf("%d\r\n",spi_rx);
        
        CSN_SetLow();
        __delay_ms(10);
        data[0]=0b11101101;
        SPI1_ExchangeBlock(data, 1);
        __delay_ms(100);
        CSN_SetHigh();
        //stop

        spi_rx = SPI1_ReadByte();
        printf("%d\r\n",spi_rx);
        
        CSN_SetLow();
        __delay_ms(10);
        data[0]=0b11101101;
        SPI1_ExchangeBlock(data, 1);
        __delay_ms(100);
        CSN_SetHigh();
        //Reverse

        spi_rx = SPI1_ReadByte();
        printf("%d\r\n",spi_rx);

        CSN_SetLow();
        __delay_ms(10);
        data[0]=0b11101101;
        SPI1_ExchangeBlock(data, 1);
        __delay_ms(100);
        CSN_SetHigh();
        //stop
        
        spi_rx = SPI1_ReadByte();
        printf("%d\r\n",spi_rx);
        
        
    }
}
/**
 End of File
*/