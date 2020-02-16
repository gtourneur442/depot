#include <proc/p32mx370f512l.h>

#include "timer.h"

void initTimer(void)
{
    // Enable Timer 1
    PR1 = (2*10000/4);    // set periode register
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
}