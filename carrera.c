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
//deinimos nuestro tiepo para 4Mhz

#define _XTAL_FREQ 4000000


#define lverde      PORTBbits.RB0
#define lamarillo   PORTBbits.RB1
#define lrojo       PORTBbits.RB2




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
    TRISB   = 0;
    TRISA   = 0b00000001; //BOTÓN SEMAFORO
    PORTB   = 0;
    PORTB   = 0;
    
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




