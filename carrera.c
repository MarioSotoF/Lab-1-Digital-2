// PIC16F887 Configuration Bit Settings

// 'C' source line config statements

// CONFIG1
#pragma config FOSC = INTRC_NOCLKOUT// Oscillator Selection bits (INTOSCIO oscillator: I/O function on RA6/OSC2/CLKOUT pin, I/O function on RA7/OSC1/CLKIN)
#pragma config WDTE = OFF       // Watchdog Timer Enable bit (WDT disabled and can be enabled by SWDTEN bit of the WDTCON register)
#pragma config PWRTE = OFF      // Power-up Timer Enable bit (PWRT disabled)
#pragma config MCLRE = ON       // RE3/MCLR pin function select bit (RE3/MCLR pin function is MCLR)
#pragma config CP = OFF         // Code Protection bit (Program memory code protection is disabled)
#pragma config CPD = OFF        // Data Code Protection bit (Data memory code protection is disabled)
#pragma config BOREN = OFF      // Brown Out Reset Selection bits (BOR disabled)
#pragma config IESO = OFF       // Internal External Switchover bit (Internal/External Switchover mode is disabled)
#pragma config FCMEN = OFF      // Fail-Safe Clock Monitor Enabled bit (Fail-Safe Clock Monitor is disabled)
#pragma config LVP = OFF        // Low Voltage Programming Enable bit (RB3 pin has digital I/O, HV on MCLR must be used for programming)

// CONFIG2
#pragma config BOR4V = BOR40V   // Brown-out Reset Selection bit (Brown-out Reset set to 4.0V)
#pragma config WRT = OFF        // Flash Program Memory Self Write Enable bits (Write protection off)

// #pragma config statements should precede project file includes.
// Use project enums instead of #define for ON and OFF.

#include <xc.h>

/*
 *
 * File:   carrera.c
 * Author: mario
 *
 * Created on 31 de enero de 2021, 09:06 PM
 */


#include <xc.h>

void setup (void);
void semaforo(void);
void delay(unsigned char n);
void jugador1(unsigned char j1);
void jugador2(unsigned char j2);

//deinimos nuestro tiepo para 4Mhz

#define _XTAL_FREQ 4000000


#define lverde      PORTBbits.RB0
#define lamarillo   PORTBbits.RB1
#define lrojo       PORTBbits.RB2
unsigned char j1;
unsigned char j2;



void main(void) {
    
    setup();
    delay(1000);
    while(1){
        
        if (PORTAbits.RA0 == 0){
            semaforo();
        }
    }
    
    
    
    return;
}

void delay(unsigned char n) {
    for (int i = 0; i < 255; i++) {
        for (int j = 0; j < 255; j++) {
        }
    }
}
void setup (void) {
    
    ANSEL   = 0;
    ANSELH  = 0;
    TRISB   = 0;//LEDS SEMAFORO
    TRISC   = 0;//LEDS J1
    TRISD   = 0;//LEDS J2
    TRISA   = 0b00000111; //Botones
    
    //LIMPIAMOS PUERTOS
    PORTA   = 0;
    PORTB   = 0;
    PORTC   = 0;
    PORTD   = 0;
    
}

void semaforo (void){
    
    lverde      = 0;
    lamarillo   = 0;
    lrojo       = 1;
    delay(1000);
    
    lverde      = 0;
    lamarillo   = 1;
    lrojo       = 0;
    delay(1000);
    
    lverde      = 1;
    lamarillo   = 0;
    lrojo       = 0;
    delay(1000);
    
    
}


void jugador1(unsigned char j1){
    if (j1 == 8){
        PORTBbits.RB3 = 1;
        delay(1000);
        
        switch(j1){
            case 1:
                PORTCbits.RC0 = 1;
                break;
            
            case 2:
                PORTCbits.RC1 = 1;
            
            case 3:
                PORTCbits.RC2 = 1;
                break;
            
            case 4:
                PORTCbits.RC3 = 1;
            
            case 5:
                PORTCbits.RC4 = 1;
                break;
            
            case 6:
                PORTCbits.RC5 = 1;
            
            case 7:
                PORTCbits.RC6 = 1;
                break;
            
            case 8:
                PORTCbits.RC3 = 1;
                
        }
        
    }

}


void jugador2(unsigned char j2){
    if (j2 == 8){
        PORTBbits.RB4 = 1;
        delay(1000);
        
        switch(j2){
            case 1:
                PORTDbits.RD0 = 1;
                break;
            
            case 2:
                PORTDbits.RD1 = 1;
            
            case 3:
                PORTDbits.RD2 = 1;
                break;
            
            case 4:
                PORTDbits.RD3 = 1;
            
            case 5:
                PORTCbits.RC4 = 1;
                break;
            
            case 6:
                PORTDbits.RD5 = 1;
            
            case 7:
                PORTDbits.RD6 = 1;
                break;
            
            case 8:
                PORTDbits.RD3 = 1;
                
        }
        
    }

}
