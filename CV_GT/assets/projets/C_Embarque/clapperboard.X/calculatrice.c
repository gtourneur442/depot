#include "changerChiffre.h"
#include "calculatrice.h"

#define BTND PORTAbits.RA15
#define BTNL PORTBbits.RB0
#define BTNU PORTBbits.RB1
#define BTNC PORTFbits.RF0
#define BTNR PORTBbits.RB8

void initButton()
{
    ANSELBbits.ANSB0 = 0;
    ANSELBbits.ANSB1 = 0;
    ANSELBbits.ANSB8 = 0;
    
    TRISBbits.TRISB0 = 1;
    TRISBbits.TRISB1 = 1;
    TRISBbits.TRISB8 = 1;
    TRISAbits.TRISA15 = 1;
    TRISFbits.TRISF0 = 1;
}

/*unsigned char valueFromSwitch()
{
    long i;
    unsigned char value = 0;
    for (i = 0; i <= 7; i++)
        {
            value += (getSwitch(i) << i);
        }
    displayDigit(4,value%10);
    displayDigit(3,(value/10)%10);
    displayDigit(2,(value/100)%100);
    displayDigit(1,(value/1000)%1000);
    return value;
}*/

void printValue(unsigned short value)
{
    displayDigit(4,value%10);
    displayDigit(3,(value/10)%10);
    displayDigit(2,(value/100)%10);
    displayDigit(1,(value/1000)%10);
}

void printValue2(int value)
{
    displayDigit(4,value%10);
    displayDigit(3,(value/10)%10);
    displayDigit(2,(value/100)%10);
    displayDigit(1,(value/1000)%10);
}

/*char calculate(unsigned char value)
{
    static unsigned char nbOne;
    static unsigned char nbTwo;
    unsigned char resultMult;
    unsigned char result0;
    unsigned char resultSoust;
    static unsigned char print;
    char button1;
    char button2;
    char button3;
    char button4;
    char button5;
    
    button1 = PORTFbits.RF0;
    button2 = PORTBbits.RB1;
    button3 = PORTAbits.RA15;
    button4 = PORTBbits.RB8;
    button5 = PORTBbits.RB0;
    
    if (button1 == 1)
    {
        nbOne = value;
        print = nbOne;
    }
    if (button2 == 1)
    {
        resultSoust = nbOne-nbTwo;
        print = resultSoust;
    }
    if (button3 == 1)
    {
        nbTwo = value;
        print = nbTwo;
    }
    if (button4 == 1)
    {
        resultMult = nbOne*nbTwo;
        print = resultMult;
    }
    if (button5 == 1)
    {
        result0 = 0;
        print = result0;
    }
    printValue(print);
    return print;
    
}*/