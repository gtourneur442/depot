#include <proc/p32mx370f512l.h>

#include "timer.h"
/*void initTimer(void)
{
    // Enable Timer 1
    PR1 = (1*4000000 / 256);    // set periode register
    TMR1 = 0;   // initialize count to 0
    T1CONbits.TCKPS = 3;    // 1:256 prescale value
    T1CONbits.TGATE = 0;    // not gated input (the default)
    T1CONbits.TCS = 0;  // PCBLK input (the default)
    T1CONbits.ON = 1;   // turn on Timer1
    IPC1bits.T1IP = 7;  // priority
    IPC1bits.T1IS = 3;  // subpriority
    IFS0bits.T1IF = 0;  // clear interrupt flag
    IEC0bits.T1IE = 1;  // enable interrupt
    macro_enable_interrupts();  // enable interrupts at CPU
}*/

void initTimer2(void)
{
    // Enable Timer 2
    PR2 = (1*4000000 / 256);    // set periode register (secondes*megaHertz / prescale)
    TMR2 = 0;   // initialize count to 0
    T2CONbits.TCKPS = 0;    // 1:256 prescale value
    T2CONbits.TGATE = 0;    // not gated input (the default)
    T2CONbits.TCS = 0;  // PCBLK input (the default)
    T2CONbits.ON = 1;   // turn on Timer2
    IPC2bits.T2IP = 7;  // priority
    IPC2bits.T2IS = 3;  // subpriority
    IFS0bits.T2IF = 0;  // clear interrupt flag
    IEC0bits.T2IE = 1;  // enable interrupt
    macro_enable_interrupts();  // enable interrupts at CPU
}

void initTimer3(void)
{
    // Enable Timer 3
    PR3 = (15625);    // set periode register (secondes*megaHertz / prescale)
    TMR3 = 0;   // initialize count to 0
    T3CONbits.TCKPS = 7;    // 1:256 prescale value
    T3CONbits.TGATE = 0;    // not gated input (the default)
    T3CONbits.TCS = 0;  // PCBLK input (the default)
    T3CONbits.ON = 1;   // turn on Timer3
    IPC3bits.T3IP = 7;  // priority
    IPC3bits.T3IS = 3;  // subpriority
    IFS0bits.T3IF = 0;  // clear interrupt flag
    IEC0bits.T3IE = 1;  // enable interrupt
    macro_enable_interrupts();  // enable interrupts at CPU
}