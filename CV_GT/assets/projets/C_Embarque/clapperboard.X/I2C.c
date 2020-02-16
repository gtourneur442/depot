#include"i2c.h"


void initI2C()
{ 
    TRISGbits.TRISG2 = 0;
    TRISGbits.TRISG3 = 0;
    I2C1CONbits.ON = 1;
    I2C1CONbits.SIDL = 0;
    //I2C1CONbits.A10M = 0;
    //I2C1CONbits.DISSLW
    I2C1CONbits.SMEN = 0;
    //I2C1CONbits.GCEN = 0;
    I2C1BRG = 3;
    
    /*I2C1STATbits.ACKSTAT = 0;
    I2C1STATbits.TRSTAT = 1;
    I2C1STATbits.R_W = 1;*/
}

void initAccelero()
{
    I2C1CONbits.SEN = 1;
    while (I2C1CONbits.SEN != 0);
    
    I2C1TRN = 0x3A;
    while (I2C1STATbits.TRSTAT != 0);
    
    /*char ackNack = I2C1STATbits.ACKSTAT;
    if (ackNack == 0)*/
    if (I2C1STATbits.ACKSTAT == 0)
    {
        I2C1TRN = 0x2A;
        while (I2C1STATbits.TRSTAT != 0);
        I2C1TRN = 0x01;
        while (I2C1STATbits.TRSTAT != 0);
    }
    I2C1CONbits.PEN = 1;
    while (I2C1CONbits.PEN != 0); 
}

void writeI2C()
{
    I2C1CONbits.SEN = 1;
    while (I2C1CONbits.SEN != 0);
    
    I2C1TRN = 0x3A;
    while (I2C1STATbits.TRSTAT != 0);
    
    /*char ackNack = I2C1STATbits.ACKSTAT;
    if (ackNack == 0)*/
    if (I2C1STATbits.ACKSTAT == 0)
    {
        I2C1TRN = 0x0E;
        while (I2C1STATbits.TRSTAT != 0);
        I2C1TRN = 0x00;
        while (I2C1STATbits.TRSTAT != 0);
    }
    
    I2C1CONbits.PEN = 1;
    while (I2C1CONbits.PEN != 0);
}

int readI2C()
{
    int data = 0;
    I2C1CONbits.SEN = 1;
    while (I2C1CONbits.SEN != 0);
    
    I2C1TRN = 0x3A;
    while (I2C1STATbits.TRSTAT != 0);
    
    /*char ackNack = I2C1STATbits.ACKSTAT;
    if (ackNack == 0)*/
    if (I2C1STATbits.ACKSTAT == 0)
    {
        I2C1TRN = 0x01;
        while (I2C1STATbits.TRSTAT != 0);
        I2C1CONbits.RSEN = 1;
        while (I2C1CONbits.RSEN != 0);
        
        I2C1TRN = 0x3B;
        while (I2C1STATbits.TRSTAT != 0);
        I2C1CONbits.RCEN = 1;
        I2C1CONbits.ACKDT = 1;
        while (I2C1CONbits.RCEN != 0);
        
        //while (I2C1STATbits.ACKSTAT == 0) {}
        data = I2C1RCV;
        I2C1CONbits.ACKEN = 1;
        while (I2C1CONbits.ACKEN != 0);

    }
    
    I2C1CONbits.PEN = 1;
    while (I2C1CONbits.PEN != 0);
    return data;
}