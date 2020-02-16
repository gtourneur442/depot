#include "detectionTap.h"

void writeDetectionTap()
{
    I2C1CONbits.SEN=1;
    while(I2C1CONbits.SEN!=0);
    
    I2C1TRN=0x3A;
    while(I2C1STATbits.TRSTAT!=0);
    if(I2C1STATbits.ACKSTAT==0)
    {
        I2C1TRN=0x21;
        while(I2C1STATbits.TRSTAT!=0);
        I2C1TRN=0x3F;
        while(I2C1STATbits.TRSTAT!=0);
    }
    I2C1CONbits.PEN=1;
    while(I2C1CONbits.PEN!=0);
    
    //DelayAprox100Us(100);
    //CTRL_REG1;
    //XYZ_DATA_CFG;
}

int readTap()
{
    int data=0;
    I2C1CONbits.SEN=1;
    while(I2C1CONbits.SEN!=0);
    
    I2C1TRN=0x3A;
    while(I2C1STATbits.TRSTAT!=0);
    
    if(I2C1STATbits.ACKSTAT==0)
    {
        I2C1TRN=0x22;
        while(I2C1STATbits.TRSTAT!=0);
        I2C1CONbits.RSEN=1;
        while(I2C1CONbits.RSEN!=0);
        
        
        I2C1TRN=0x3B;
        while(I2C1STATbits.TRSTAT!=0);
        I2C1CONbits.RCEN=1;
        I2C1CONbits.ACKDT=1;
        while(I2C1CONbits.RCEN!=0);
        
        //while(I2C1STATbits.ACKSTAT==0);
        data = I2C1RCV;
        I2C1CONbits.ACKEN=1;
        while(I2C1CONbits.ACKEN!=0);
        //while(I2C1STATbits.RBF!=0);
        //I2C1CONbits.ACKDT=0;
        //while(I2C1CONbits.ACKDT!=1);
        
    }
    I2C1CONbits.PEN=1;
    while(I2C1CONbits.PEN!=0);
    
    //data=data&0x20;

    return data;
}

void writeRegisterTap(int registre, int data)
{
    I2C1CONbits.SEN=1;
    while(I2C1CONbits.SEN!=0);
    
    I2C1TRN=0x3A;
    while(I2C1STATbits.TRSTAT!=0);
    if(I2C1STATbits.ACKSTAT==0)
    {
        I2C1TRN=registre;
        while(I2C1STATbits.TRSTAT!=0);
        I2C1TRN=data;
        while(I2C1STATbits.TRSTAT!=0);
    }
    I2C1CONbits.PEN=1;
    while(I2C1CONbits.PEN!=0);
    
    //DelayAprox100Us(100);
    //CTRL_REG1;
    //XYZ_DATA_CFG;
}

int readRegisterTap(int registre)
{
    int data=0;
    I2C1CONbits.SEN=1;
    while(I2C1CONbits.SEN!=0);
    
    I2C1TRN=0x3A;
    while(I2C1STATbits.TRSTAT!=0);
    
    if(I2C1STATbits.ACKSTAT==0)
    {
        I2C1TRN=registre;
        while(I2C1STATbits.TRSTAT!=0);
        I2C1CONbits.RSEN=1;
        while(I2C1CONbits.RSEN!=0);
        
        
        I2C1TRN=0x3B;
        while(I2C1STATbits.TRSTAT!=0);
        I2C1CONbits.RCEN=1;
        I2C1CONbits.ACKDT=1;
        while(I2C1CONbits.RCEN!=0);
        
        //while(I2C1STATbits.ACKSTAT==0);
        data = I2C1RCV;
        I2C1CONbits.ACKEN=1;
        while(I2C1CONbits.ACKEN!=0);
        //while(I2C1STATbits.RBF!=0);
        //I2C1CONbits.ACKDT=0;
        //while(I2C1CONbits.ACKDT!=1);
        
    }
    I2C1CONbits.PEN=1;
    while(I2C1CONbits.PEN!=0);
    
    //data=data&0x20;
 
    return data;
}