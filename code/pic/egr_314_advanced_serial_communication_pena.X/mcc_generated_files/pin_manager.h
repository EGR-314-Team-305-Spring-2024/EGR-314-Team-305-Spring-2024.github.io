/**
  @Generated Pin Manager Header File

  @Company:
    Microchip Technology Inc.

  @File Name:
    pin_manager.h

  @Summary:
    This is the Pin Manager file generated using PIC10 / PIC12 / PIC16 / PIC18 MCUs

  @Description
    This header file provides APIs for driver for .
    Generation Information :
        Product Revision  :  PIC10 / PIC12 / PIC16 / PIC18 MCUs - 1.81.8
        Device            :  PIC18F47Q10
        Driver Version    :  2.11
    The generated drivers are tested against the following:
        Compiler          :  XC8 2.36 and above
        MPLAB 	          :  MPLAB X 6.00	
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

#ifndef PIN_MANAGER_H
#define PIN_MANAGER_H

/**
  Section: Included Files
*/

#include <xc.h>

#define INPUT   1
#define OUTPUT  0

#define HIGH    1
#define LOW     0

#define ANALOG      1
#define DIGITAL     0

#define PULL_UP_ENABLED      1
#define PULL_UP_DISABLED     0

// get/set PWM aliases
#define PWM_TRIS                 TRISAbits.TRISA3
#define PWM_LAT                  LATAbits.LATA3
#define PWM_PORT                 PORTAbits.RA3
#define PWM_WPU                  WPUAbits.WPUA3
#define PWM_OD                   ODCONAbits.ODCA3
#define PWM_ANS                  ANSELAbits.ANSELA3
#define PWM_SetHigh()            do { LATAbits.LATA3 = 1; } while(0)
#define PWM_SetLow()             do { LATAbits.LATA3 = 0; } while(0)
#define PWM_Toggle()             do { LATAbits.LATA3 = ~LATAbits.LATA3; } while(0)
#define PWM_GetValue()           PORTAbits.RA3
#define PWM_SetDigitalInput()    do { TRISAbits.TRISA3 = 1; } while(0)
#define PWM_SetDigitalOutput()   do { TRISAbits.TRISA3 = 0; } while(0)
#define PWM_SetPullup()          do { WPUAbits.WPUA3 = 1; } while(0)
#define PWM_ResetPullup()        do { WPUAbits.WPUA3 = 0; } while(0)
#define PWM_SetPushPull()        do { ODCONAbits.ODCA3 = 0; } while(0)
#define PWM_SetOpenDrain()       do { ODCONAbits.ODCA3 = 1; } while(0)
#define PWM_SetAnalogMode()      do { ANSELAbits.ANSELA3 = 1; } while(0)
#define PWM_SetDigitalMode()     do { ANSELAbits.ANSELA3 = 0; } while(0)

// get/set CSN aliases
#define CSN_TRIS                 TRISAbits.TRISA4
#define CSN_LAT                  LATAbits.LATA4
#define CSN_PORT                 PORTAbits.RA4
#define CSN_WPU                  WPUAbits.WPUA4
#define CSN_OD                   ODCONAbits.ODCA4
#define CSN_ANS                  ANSELAbits.ANSELA4
#define CSN_SetHigh()            do { LATAbits.LATA4 = 1; } while(0)
#define CSN_SetLow()             do { LATAbits.LATA4 = 0; } while(0)
#define CSN_Toggle()             do { LATAbits.LATA4 = ~LATAbits.LATA4; } while(0)
#define CSN_GetValue()           PORTAbits.RA4
#define CSN_SetDigitalInput()    do { TRISAbits.TRISA4 = 1; } while(0)
#define CSN_SetDigitalOutput()   do { TRISAbits.TRISA4 = 0; } while(0)
#define CSN_SetPullup()          do { WPUAbits.WPUA4 = 1; } while(0)
#define CSN_ResetPullup()        do { WPUAbits.WPUA4 = 0; } while(0)
#define CSN_SetPushPull()        do { ODCONAbits.ODCA4 = 0; } while(0)
#define CSN_SetOpenDrain()       do { ODCONAbits.ODCA4 = 1; } while(0)
#define CSN_SetAnalogMode()      do { ANSELAbits.ANSELA4 = 1; } while(0)
#define CSN_SetDigitalMode()     do { ANSELAbits.ANSELA4 = 0; } while(0)

// get/set RB6 procedures
#define RB6_SetHigh()            do { LATBbits.LATB6 = 1; } while(0)
#define RB6_SetLow()             do { LATBbits.LATB6 = 0; } while(0)
#define RB6_Toggle()             do { LATBbits.LATB6 = ~LATBbits.LATB6; } while(0)
#define RB6_GetValue()              PORTBbits.RB6
#define RB6_SetDigitalInput()    do { TRISBbits.TRISB6 = 1; } while(0)
#define RB6_SetDigitalOutput()   do { TRISBbits.TRISB6 = 0; } while(0)
#define RB6_SetPullup()             do { WPUBbits.WPUB6 = 1; } while(0)
#define RB6_ResetPullup()           do { WPUBbits.WPUB6 = 0; } while(0)
#define RB6_SetAnalogMode()         do { ANSELBbits.ANSELB6 = 1; } while(0)
#define RB6_SetDigitalMode()        do { ANSELBbits.ANSELB6 = 0; } while(0)

// get/set RC4 procedures
#define RC4_SetHigh()            do { LATCbits.LATC4 = 1; } while(0)
#define RC4_SetLow()             do { LATCbits.LATC4 = 0; } while(0)
#define RC4_Toggle()             do { LATCbits.LATC4 = ~LATCbits.LATC4; } while(0)
#define RC4_GetValue()              PORTCbits.RC4
#define RC4_SetDigitalInput()    do { TRISCbits.TRISC4 = 1; } while(0)
#define RC4_SetDigitalOutput()   do { TRISCbits.TRISC4 = 0; } while(0)
#define RC4_SetPullup()             do { WPUCbits.WPUC4 = 1; } while(0)
#define RC4_ResetPullup()           do { WPUCbits.WPUC4 = 0; } while(0)
#define RC4_SetAnalogMode()         do { ANSELCbits.ANSELC4 = 1; } while(0)
#define RC4_SetDigitalMode()        do { ANSELCbits.ANSELC4 = 0; } while(0)

// get/set RC5 procedures
#define RC5_SetHigh()            do { LATCbits.LATC5 = 1; } while(0)
#define RC5_SetLow()             do { LATCbits.LATC5 = 0; } while(0)
#define RC5_Toggle()             do { LATCbits.LATC5 = ~LATCbits.LATC5; } while(0)
#define RC5_GetValue()              PORTCbits.RC5
#define RC5_SetDigitalInput()    do { TRISCbits.TRISC5 = 1; } while(0)
#define RC5_SetDigitalOutput()   do { TRISCbits.TRISC5 = 0; } while(0)
#define RC5_SetPullup()             do { WPUCbits.WPUC5 = 1; } while(0)
#define RC5_ResetPullup()           do { WPUCbits.WPUC5 = 0; } while(0)
#define RC5_SetAnalogMode()         do { ANSELCbits.ANSELC5 = 1; } while(0)
#define RC5_SetDigitalMode()        do { ANSELCbits.ANSELC5 = 0; } while(0)

// get/set RC6 procedures
#define RC6_SetHigh()            do { LATCbits.LATC6 = 1; } while(0)
#define RC6_SetLow()             do { LATCbits.LATC6 = 0; } while(0)
#define RC6_Toggle()             do { LATCbits.LATC6 = ~LATCbits.LATC6; } while(0)
#define RC6_GetValue()              PORTCbits.RC6
#define RC6_SetDigitalInput()    do { TRISCbits.TRISC6 = 1; } while(0)
#define RC6_SetDigitalOutput()   do { TRISCbits.TRISC6 = 0; } while(0)
#define RC6_SetPullup()             do { WPUCbits.WPUC6 = 1; } while(0)
#define RC6_ResetPullup()           do { WPUCbits.WPUC6 = 0; } while(0)
#define RC6_SetAnalogMode()         do { ANSELCbits.ANSELC6 = 1; } while(0)
#define RC6_SetDigitalMode()        do { ANSELCbits.ANSELC6 = 0; } while(0)

// get/set RD0 procedures
#define RD0_SetHigh()            do { LATDbits.LATD0 = 1; } while(0)
#define RD0_SetLow()             do { LATDbits.LATD0 = 0; } while(0)
#define RD0_Toggle()             do { LATDbits.LATD0 = ~LATDbits.LATD0; } while(0)
#define RD0_GetValue()              PORTDbits.RD0
#define RD0_SetDigitalInput()    do { TRISDbits.TRISD0 = 1; } while(0)
#define RD0_SetDigitalOutput()   do { TRISDbits.TRISD0 = 0; } while(0)
#define RD0_SetPullup()             do { WPUDbits.WPUD0 = 1; } while(0)
#define RD0_ResetPullup()           do { WPUDbits.WPUD0 = 0; } while(0)
#define RD0_SetAnalogMode()         do { ANSELDbits.ANSELD0 = 1; } while(0)
#define RD0_SetDigitalMode()        do { ANSELDbits.ANSELD0 = 0; } while(0)

// get/set RD1 procedures
#define RD1_SetHigh()            do { LATDbits.LATD1 = 1; } while(0)
#define RD1_SetLow()             do { LATDbits.LATD1 = 0; } while(0)
#define RD1_Toggle()             do { LATDbits.LATD1 = ~LATDbits.LATD1; } while(0)
#define RD1_GetValue()              PORTDbits.RD1
#define RD1_SetDigitalInput()    do { TRISDbits.TRISD1 = 1; } while(0)
#define RD1_SetDigitalOutput()   do { TRISDbits.TRISD1 = 0; } while(0)
#define RD1_SetPullup()             do { WPUDbits.WPUD1 = 1; } while(0)
#define RD1_ResetPullup()           do { WPUDbits.WPUD1 = 0; } while(0)
#define RD1_SetAnalogMode()         do { ANSELDbits.ANSELD1 = 1; } while(0)
#define RD1_SetDigitalMode()        do { ANSELDbits.ANSELD1 = 0; } while(0)

// get/set DIS aliases
#define DIS_TRIS                 TRISDbits.TRISD5
#define DIS_LAT                  LATDbits.LATD5
#define DIS_PORT                 PORTDbits.RD5
#define DIS_WPU                  WPUDbits.WPUD5
#define DIS_OD                   ODCONDbits.ODCD5
#define DIS_ANS                  ANSELDbits.ANSELD5
#define DIS_SetHigh()            do { LATDbits.LATD5 = 1; } while(0)
#define DIS_SetLow()             do { LATDbits.LATD5 = 0; } while(0)
#define DIS_Toggle()             do { LATDbits.LATD5 = ~LATDbits.LATD5; } while(0)
#define DIS_GetValue()           PORTDbits.RD5
#define DIS_SetDigitalInput()    do { TRISDbits.TRISD5 = 1; } while(0)
#define DIS_SetDigitalOutput()   do { TRISDbits.TRISD5 = 0; } while(0)
#define DIS_SetPullup()          do { WPUDbits.WPUD5 = 1; } while(0)
#define DIS_ResetPullup()        do { WPUDbits.WPUD5 = 0; } while(0)
#define DIS_SetPushPull()        do { ODCONDbits.ODCD5 = 0; } while(0)
#define DIS_SetOpenDrain()       do { ODCONDbits.ODCD5 = 1; } while(0)
#define DIS_SetAnalogMode()      do { ANSELDbits.ANSELD5 = 1; } while(0)
#define DIS_SetDigitalMode()     do { ANSELDbits.ANSELD5 = 0; } while(0)

// get/set DIR aliases
#define DIR_TRIS                 TRISDbits.TRISD6
#define DIR_LAT                  LATDbits.LATD6
#define DIR_PORT                 PORTDbits.RD6
#define DIR_WPU                  WPUDbits.WPUD6
#define DIR_OD                   ODCONDbits.ODCD6
#define DIR_ANS                  ANSELDbits.ANSELD6
#define DIR_SetHigh()            do { LATDbits.LATD6 = 1; } while(0)
#define DIR_SetLow()             do { LATDbits.LATD6 = 0; } while(0)
#define DIR_Toggle()             do { LATDbits.LATD6 = ~LATDbits.LATD6; } while(0)
#define DIR_GetValue()           PORTDbits.RD6
#define DIR_SetDigitalInput()    do { TRISDbits.TRISD6 = 1; } while(0)
#define DIR_SetDigitalOutput()   do { TRISDbits.TRISD6 = 0; } while(0)
#define DIR_SetPullup()          do { WPUDbits.WPUD6 = 1; } while(0)
#define DIR_ResetPullup()        do { WPUDbits.WPUD6 = 0; } while(0)
#define DIR_SetPushPull()        do { ODCONDbits.ODCD6 = 0; } while(0)
#define DIR_SetOpenDrain()       do { ODCONDbits.ODCD6 = 1; } while(0)
#define DIR_SetAnalogMode()      do { ANSELDbits.ANSELD6 = 1; } while(0)
#define DIR_SetDigitalMode()     do { ANSELDbits.ANSELD6 = 0; } while(0)

/**
   @Param
    none
   @Returns
    none
   @Description
    GPIO and peripheral I/O initialization
   @Example
    PIN_MANAGER_Initialize();
 */
void PIN_MANAGER_Initialize (void);

/**
 * @Param
    none
 * @Returns
    none
 * @Description
    Interrupt on Change Handling routine
 * @Example
    PIN_MANAGER_IOC();
 */
void PIN_MANAGER_IOC(void);



#endif // PIN_MANAGER_H
/**
 End of File
*/