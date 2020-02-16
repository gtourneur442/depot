#include "changerChiffre.h"

void initdDigit()
{
    TRISAbits.TRISA10 = 0;
    TRISAbits.TRISA9 = 0;
    TRISBbits.TRISB13 = 0;
    TRISBbits.TRISB12 = 0;
    TRISGbits.TRISG12 = 0;
    TRISAbits.TRISA14 = 0;
    TRISDbits.TRISD6 = 0;
    TRISGbits.TRISG13 = 0;
    TRISGbits.TRISG15 = 0;
    TRISDbits.TRISD7 = 0;
    TRISDbits.TRISD13 = 0;
    TRISGbits.TRISG14 = 0;
}

void displayDigit(char digitNumber,int value)
{
    LATAbits.LATA10 = 1;
    LATAbits.LATA9 = 1;
    LATBbits.LATB13 = 1;
    LATBbits.LATB12 = 1;
    
    
    switch(value)
    {
        case 0:
            
            LATGbits.LATG12 = 0;
        
            LATAbits.LATA14 = 0;
        
            LATDbits.LATD6 = 0;
            
            LATDbits.LATD13 = 1;
        
            LATGbits.LATG13 = 0;
        
            LATGbits.LATG15 = 0;
        
            LATDbits.LATD7 = 0;
        break;
        
        case 1:
            LATGbits.LATG12 = 1;
            
            LATAbits.LATA14 = 0;
        
            LATDbits.LATD6 = 0;
            
            LATDbits.LATD13 = 1;
        
            LATGbits.LATG13 = 1;
        
            LATGbits.LATG15 = 1;
        
            LATDbits.LATD7 = 1;
        break;
        
        case 2:
            LATGbits.LATG12 = 0;
        
            LATAbits.LATA14 = 0;
            
            LATDbits.LATD6 = 1;
            
            LATDbits.LATD13 = 0;
            
            LATGbits.LATG13 = 0;
        
            LATGbits.LATG15 = 0;
            
            LATDbits.LATD7 = 1;
            break;
            
        case 3:
            LATGbits.LATG12 = 0;
        
            LATAbits.LATA14 = 0;
            
            LATDbits.LATD13 = 0;
            
            LATDbits.LATD6 = 0;
        
            LATGbits.LATG13 = 0;
            
            LATGbits.LATG15 = 1;
            
            LATDbits.LATD7 = 1;
            break;
            
        case 4:
            LATGbits.LATG12 = 1;
            
            LATDbits.LATD7 = 0;
            
            LATAbits.LATA14 = 0;
            
            LATDbits.LATD13 = 0;
            
            LATDbits.LATD6 = 0;
            
            LATGbits.LATG13 = 1;
            
            LATGbits.LATG15 = 1;
            break;
            
        case 5:
            LATGbits.LATG12 = 0;
            
            LATAbits.LATA14 = 1;
        
            LATDbits.LATD7 = 0;
            
            LATDbits.LATD13 = 0;
            
            LATDbits.LATD6 = 0;
        
            LATGbits.LATG13 = 0;
            
            LATGbits.LATG15 = 1;
            break;
            
        case 6:
            LATGbits.LATG12 = 0;
            
            LATAbits.LATA14 = 1;
        
            LATDbits.LATD7 = 0;
            
            LATDbits.LATD13 = 0;
            
            LATDbits.LATD6 = 0;
        
            LATGbits.LATG13 = 0;
            
            LATGbits.LATG15 = 0;
            break;
            
        case 7:
            LATGbits.LATG12 = 0;
            
            LATAbits.LATA14 = 0;
        
            LATDbits.LATD6 = 0;
            
            LATDbits.LATD13 = 1;
            
            LATGbits.LATG13 = 1;
        
            LATGbits.LATG15 = 1;
        
            LATDbits.LATD7 = 1;
            break;
            
        case 8:
            LATGbits.LATG12 = 0;
        
            LATAbits.LATA14 = 0;
        
            LATDbits.LATD6 = 0;
        
            LATDbits.LATD13 = 0;
            
            LATGbits.LATG13 = 0;
        
            LATGbits.LATG15 = 0;
        
            LATDbits.LATD7 = 0;
            break;
            
        case 9:
            LATGbits.LATG12 = 0;
        
            LATAbits.LATA14 = 0;
        
            LATDbits.LATD6 = 0;
        
            LATDbits.LATD13 = 0;
        
            LATGbits.LATG13 = 0;
        
            LATDbits.LATD7 = 0;
            
            LATGbits.LATG15 = 1;
            break;
            
        default:
            LATGbits.LATG12 = 1;       
            LATAbits.LATA14 = 1;       
            LATDbits.LATD6 = 1;        
            LATDbits.LATD13 = 1;            
            LATGbits.LATG13 = 1;        
            LATGbits.LATG15 = 1;        
            LATDbits.LATD7 = 1;
            break;
    }
    
    switch(digitNumber)
    {
        case 1:
            LATAbits.LATA10 = 0;
            LATAbits.LATA9 = 1;
            LATBbits.LATB13 = 1;
            LATBbits.LATB12 = 1;
            LATGbits.LATG14 = 1;
        break;
        
        case 2:
            LATAbits.LATA10 = 1;
            LATAbits.LATA9 = 0;
            LATBbits.LATB13 = 1;
            LATBbits.LATB12 = 1;
            LATGbits.LATG14 = 0;
        break;
        
        case 3:
            LATAbits.LATA10 = 1;
            LATAbits.LATA9 = 1;
            LATBbits.LATB13 = 0;
            LATBbits.LATB12 = 1;
            LATGbits.LATG14 = 1;
        break;
        
        case 4:
            LATAbits.LATA10 = 1;
            LATAbits.LATA9 = 1;
            LATBbits.LATB13 = 1;
            LATBbits.LATB12 = 0;
            LATGbits.LATG14 = 1;
        break;
        
        default:
            LATAbits.LATA10 = 1;
            LATAbits.LATA9 = 1;
            LATBbits.LATB13 = 1;
            LATBbits.LATB12 = 1;
            LATGbits.LATG14 = 1;
            break;
    }
}

void minSecondes(int number)
{
    static char nb = 1;
    int minute = number/60;
    int seconde = number%60;
    
    switch (nb)
    {
        case 1:
            displayDigit(1,(minute/10)%10);
        break;
        
        case 2:
            displayDigit(2,minute%10);
        break;
        
        case 3:
            displayDigit(3,(seconde/10)%10);
        break;
        
        case 4:
            displayDigit(4,seconde%10);
        break;
    }
    nb++;
    if (nb >= 5)
        nb = 1;
}