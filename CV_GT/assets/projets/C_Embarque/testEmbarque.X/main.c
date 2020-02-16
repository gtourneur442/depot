#include <stdio.h>
#include <stdlib.h>
#include <xc.h>
#include <sys/attribs.h>
#include "shineLED.h"
#include "timer.h"
#include "getSwitch.h"
#include "reverseLED.h"

#pragma config JTAGEN = OFF     
#pragma config FWDTEN = OFF      


#pragma config FNOSC =	2      // select oscilator externe (quartz at 8MHz)
#pragma config FSOSCEN =	OFF     // Disable secondary oscilator
#pragma config POSCMOD =	XT      // XT oscilator mode
#pragma config OSCIOFNC =	ON      //
#pragma config FPBDIV =     DIV_2   // Peripheralls run at /2 the speed

#pragma config FPLLIDIV =	DIV_2
#pragma config FPLLMUL =	MUL_20
#pragma config FPLLODIV =	DIV_1

void __ISR(_TIMER_1_VECTOR, ipl7) Timer1ISR(void)
{
    long i;
    static char isOn = 0;
    IFS0bits.T1IF = 0;
        if (isOn == 0)
        {
            turnLEDon(0);
            isOn = 1;
        }
        else
        {
            turnLEDoff(0);
            isOn = 0;
        }
}

int main(int argc, char** argv)
{
    unsigned char value = 1;
    char brille = 0;
    long i;
    
    initLED();
    initSw();
    initTimer();
    initButton();
    
    
    while(1)
    {
        for (i = 1; i <= 7; i++)
        {
            value = getSwitch(i);
            if(value == 1)
                turnLEDon(i);
            else
                turnLEDoff(i);
        }
        ReverseLED();
    }
    
    return (EXIT_SUCCESS);
}