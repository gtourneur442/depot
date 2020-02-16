#include "getSwitch.h"

void initSw()
{
    ANSELBbits.ANSB11 = 0;  // SW5 disabled analog
    ANSELBbits.ANSB10 = 0;  // SW6 disabled analog
    ANSELBbits.ANSB9 = 0;   // SW7 disabled analog
    
    TRISFbits.TRISF5 = 1;
    TRISFbits.TRISF4 = 1;
    TRISDbits.TRISD15 = 1;
    TRISDbits.TRISD14 = 1;
    TRISBbits.TRISB11 = 1;
    TRISBbits.TRISB10 = 1;
    TRISBbits.TRISB9 = 1;
}

char getSwitch(char swNumber)
{

    if(swNumber == 1)
    {
        return PORTFbits.RF5;
    }
    else if(swNumber == 2)
    {
        return PORTFbits.RF4;
    }
    else if(swNumber == 3)
        {
            return PORTDbits.RD15;
        }
    else if(swNumber == 4)
        {
            return PORTDbits.RD14;
        }
    else if(swNumber == 5)
        {
            return PORTBbits.RB11;
        }
    else if(swNumber == 6)
        {
            return PORTBbits.RB10;
        }
    else if(swNumber == 7)
        {
            return PORTBbits.RB9;
        }
}
