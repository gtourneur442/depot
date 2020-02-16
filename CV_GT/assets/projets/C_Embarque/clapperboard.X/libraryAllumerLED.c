#include "libraryAllumerLED.h"

void allumerLED(char value)
{
    
    TRISAbits.TRISA0 = 0;
    LATAbits.LATA0 = value&0x01;
    
    TRISAbits.TRISA1 = 0;
    if ((value&2) != 0)
        LATAbits.LATA1 = 1;
    else
        LATAbits.LATA1 = 0;
    
    TRISAbits.TRISA2 = 0;
    if ((value&4) != 0)
        LATAbits.LATA2 = 1;
    else
        LATAbits.LATA2 = 0;
    
    TRISAbits.TRISA3 = 0;
    if ((value&8) != 0)
        LATAbits.LATA3 = 1;
    else
        LATAbits.LATA3 = 0;
    
    TRISAbits.TRISA4 = 0;
    if ((value&16) != 0)
        LATAbits.LATA4 = 1;
    else
        LATAbits.LATA4 = 0;
    
    TRISAbits.TRISA5 = 0;
    if ((value&32) != 0)
        LATAbits.LATA5 = 1;
    else
        LATAbits.LATA5 = 0;
    
    TRISAbits.TRISA6 = 0;
    if ((value&64) != 0)
        LATAbits.LATA6 = 1;
    else
        LATAbits.LATA6 = 0;
    
    TRISAbits.TRISA7 = 0;
    if ((value&128) != 0)
        LATAbits.LATA7 = 1;
    else
        LATAbits.LATA7 = 0;
}

void allumerLED2(int value)
{
    
    TRISAbits.TRISA0 = 0;
    LATAbits.LATA0 = value&0x01;
    
    TRISAbits.TRISA1 = 0;
    if ((value&2) != 0)
        LATAbits.LATA1 = 1;
    else
        LATAbits.LATA1 = 0;
    
    TRISAbits.TRISA2 = 0;
    if ((value&4) != 0)
        LATAbits.LATA2 = 1;
    else
        LATAbits.LATA2 = 0;
    
    TRISAbits.TRISA3 = 0;
    if ((value&8) != 0)
        LATAbits.LATA3 = 1;
    else
        LATAbits.LATA3 = 0;
    
    TRISAbits.TRISA4 = 0;
    if ((value&16) != 0)
        LATAbits.LATA4 = 1;
    else
        LATAbits.LATA4 = 0;
    
    TRISAbits.TRISA5 = 0;
    if ((value&32) != 0)
        LATAbits.LATA5 = 1;
    else
        LATAbits.LATA5 = 0;
    
    TRISAbits.TRISA6 = 0;
    if ((value&64) != 0)
        LATAbits.LATA6 = 1;
    else
        LATAbits.LATA6 = 0;
    
    TRISAbits.TRISA7 = 0;
    if ((value&128) != 0)
        LATAbits.LATA7 = 1;
    else
        LATAbits.LATA7 = 0;
}

int blinkLED()
{
    unsigned int blink;
    static unsigned int val = 0;
    if(readY()>(val+50) || readY()<(val-50))
    {
        blink = 1;
        val=readY();
    }
    else
        blink = 0;
    
    return blink;
}