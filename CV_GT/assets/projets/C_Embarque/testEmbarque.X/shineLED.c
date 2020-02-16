#include "shineLED.h"

void initLED()
{
    TRISAbits.TRISA0 = 0;
    TRISAbits.TRISA1 = 0;
    TRISAbits.TRISA2 = 0;
    TRISAbits.TRISA3 = 0;
    TRISAbits.TRISA4 = 0;
    TRISAbits.TRISA5 = 0;
    TRISAbits.TRISA6 = 0;
    TRISAbits.TRISA7 = 0; 
}

void turnLEDon(char ledNumber)
{
    switch (ledNumber)
    {
        case 0:
            LATAbits.LATA0 = 1;
            break;
        case 1:
            LATAbits.LATA1 = 1;
            break;    
        case 2:
            LATAbits.LATA2 = 1;
            break;
        case 3:
            LATAbits.LATA3 = 1;
            break;     
        case 4:
            LATAbits.LATA4 = 1;
            break;
        case 5:
            LATAbits.LATA5 = 1;
            break;     
        case 6:
            LATAbits.LATA6 = 1;
            break;
        case 7:
            LATAbits.LATA7 = 1;
            break; 
        default:
            break;
    }
}

void turnLEDoff(char ledNumber)
{
    switch (ledNumber)
    {
        case 0:
            LATAbits.LATA0 = 0;
            break;
        case 1:
            LATAbits.LATA1 = 0;
            break;    
        case 2:
            LATAbits.LATA2 = 0;
            break;
        case 3:
            LATAbits.LATA3 = 0;
            break;     
        case 4:
            LATAbits.LATA4 = 0;
            break;
        case 5:
            LATAbits.LATA5 = 0;
            break;     
        case 6:
            LATAbits.LATA6 = 0;
            break;
        case 7:
            LATAbits.LATA7 = 0;
            break; 
        default:
            break;
    }
}