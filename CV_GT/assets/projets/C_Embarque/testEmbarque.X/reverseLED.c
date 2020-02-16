#include "reverseLED.h"

void initButton()
{
    TRISFbits.TRISF0 = 1;
}

/*unsigned char valueFromSwitch()
{
    long i;
    unsigned char value = 1;
    for (i = 1; i <= 7; i++)
        {
            value += (getSwitch(i) << i);
        }

    return value;
}*/

void ReverseLED()
{
    char button;
    
    button = PORTFbits.RF0;
    
    if (button == 1)
    {
        TRISFbits.TRISF5 = 0;
        TRISFbits.TRISF4 = 0;
        TRISDbits.TRISD15 = 0;
        TRISDbits.TRISD14 = 0;
        TRISBbits.TRISB11 = 0;
        TRISBbits.TRISB10 = 0;
        TRISBbits.TRISB9 = 0;
        PORTFbits.RF5 = 0;
        PORTFbits.RF4 = 0;
        PORTDbits.RD15 = 0;
        PORTDbits.RD14 = 0;
        PORTBbits.RB11 = 0;
        PORTBbits.RB10 = 0;
        PORTBbits.RB9 = 0;
        LATAbits.LATA1 = 0;
        LATAbits.LATA2 = 0;
        LATAbits.LATA3 = 0;
        LATAbits.LATA4 = 0;
        LATAbits.LATA5 = 0;
        LATAbits.LATA6 = 0;
        LATAbits.LATA7 = 0;
    }
    else
    {
        TRISFbits.TRISF5 = 1;
        TRISFbits.TRISF4 = 1;
        TRISDbits.TRISD15 = 1;
        TRISDbits.TRISD14 = 1;
        TRISBbits.TRISB11 = 1;
        TRISBbits.TRISB10 = 1;
        TRISBbits.TRISB9 = 1;
    }
        
}