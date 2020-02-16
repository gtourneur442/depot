#include "RS232.h"

int i = 0;
char mot[30];

void initUART()
{
    TRISFbits.TRISF12 = 0;
    TRISFbits.TRISF13 = 1;
    
    RPF12R = 0b0010;
    U4RXR = 0b1001;
    
    U4MODEbits.ON = 1;
    U4MODEbits.IREN = 0;
    U4MODEbits.PDSEL = 00;
    U4MODEbits.STSEL = 0;
    U4STAbits.UTXEN = 1;
    U4STAbits.URXEN = 1;
    U4BRG = 25;
}

void transmissionUart()
{   
    printValue('A');
    //U4TXREG = 'A';
}

void transCharacter()
{
    int j;
    char phrase[] = "Salut ! Comment t'appelles-tu ?\n\r";
    for (j = 0; j < strlen(phrase); j++)
    {
        U4TXREG = phrase[j];
        while (U4STAbits.UTXBF != 0) {}
    }
}

char *saisieCharacter()
{
    while (U4STAbits.URXDA != 0)
    {
        mot[i] = U4RXREG;
        i++;
    }
    while (U4STAbits.URXDA == 0) {} // Pour arrêter la saisie automatique du caractère
    return mot;
}

void sendCharacter()
{
    int k;
    for (k = 0; k < i; k++)
    {
        U4TXREG = mot[k];
        while (U4STAbits.UTXBF != 0) {}
    }
    U4TXREG = '\n';
    while (U4STAbits.UTXBF != 0) {}
    U4TXREG = '\r';
}