#include "jcI2C.h"

/*void initI2C()
{
    TRISGbits.TRISG2=0;
    TRISGbits.TRISG3=0;
    I2C1CONbits.ON = 1;
    I2C1CONbits.SIDL=0;
    I2C1CONbits.SMEN=0;
    I2C1BRG=3;
    
}
void initAccelero()
{
    I2C1CONbits.SEN=1;
    while(I2C1CONbits.SEN!=0);
    
    I2C1TRN=0x3A;
    while(I2C1STATbits.TRSTAT!=0);
    if(I2C1STATbits.ACKSTAT==0)
    {
        I2C1TRN=0x2A;
        while(I2C1STATbits.TRSTAT!=0);
        I2C1TRN=0x01;
        while(I2C1STATbits.TRSTAT!=0);
    }
    I2C1CONbits.PEN=1;
    while(I2C1CONbits.PEN!=0);
    DelayAprox100Us(100);
}

void writeAccelero()
{
    I2C1CONbits.SEN=1;
    while(I2C1CONbits.SEN!=0);
    
    I2C1TRN=0x3A;
    while(I2C1STATbits.TRSTAT!=0);
    if(I2C1STATbits.ACKSTAT==0)
    {
        I2C1TRN=0x0E;
        while(I2C1STATbits.TRSTAT!=0);
        I2C1TRN=0x00;
        while(I2C1STATbits.TRSTAT!=0);
    }
    I2C1CONbits.PEN=1;
    while(I2C1CONbits.PEN!=0);
    
    DelayAprox100Us(100);
    //CTRL_REG1;
    //XYZ_DATA_CFG;
}

int readX()
{
    int data=0;
    I2C1CONbits.SEN=1;
    while(I2C1CONbits.SEN!=0);
    
    I2C1TRN=0x3A;
    while(I2C1STATbits.TRSTAT!=0);
    
    if(I2C1STATbits.ACKSTAT==0)
    {
        I2C1TRN=0x01;
        while(I2C1STATbits.TRSTAT!=0);
        I2C1CONbits.RSEN=1;
        while(I2C1CONbits.RSEN!=0);
        
        
        I2C1TRN=0x3B;
        while(I2C1STATbits.TRSTAT!=0);
        I2C1CONbits.RCEN=1;
        I2C1CONbits.ACKDT=1;
        while(I2C1CONbits.RCEN!=0);
        
        //while(I2C1STATbits.ACKSTAT==0);
        data=I2C1RCV;
        I2C1CONbits.ACKEN=1;
        while(I2C1CONbits.ACKEN!=0);
        //while(I2C1STATbits.RBF!=0);
        //I2C1CONbits.ACKDT=0;
        //while(I2C1CONbits.ACKDT!=1);
        
    }
    I2C1CONbits.PEN=1;
    while(I2C1CONbits.PEN!=0);
    
    return data;
    
}*/

int readY()
{
    int data=0;
    I2C1CONbits.SEN=1;
    while(I2C1CONbits.SEN!=0);
    
    I2C1TRN=0x3A;
    while(I2C1STATbits.TRSTAT!=0);
    
    if(I2C1STATbits.ACKSTAT==0)
    {
        I2C1TRN=0x03;
        while(I2C1STATbits.TRSTAT!=0);
        I2C1CONbits.RSEN=1;
        while(I2C1CONbits.RSEN!=0);
        
        
        I2C1TRN=0x3B;
        while(I2C1STATbits.TRSTAT!=0);
        I2C1CONbits.RCEN=1;
        I2C1CONbits.ACKDT=1;
        while(I2C1CONbits.RCEN!=0);
        
        //while(I2C1STATbits.ACKSTAT==0);
        data=I2C1RCV;
        I2C1CONbits.ACKEN=1;
        while(I2C1CONbits.ACKEN!=0);
        //while(I2C1STATbits.RBF!=0);
        //I2C1CONbits.ACKDT=0;
        //while(I2C1CONbits.ACKDT!=1);
        
    }
    I2C1CONbits.PEN=1;
    while(I2C1CONbits.PEN!=0);
    
    return data;
    
}

int readZ()
{
    int data=0;
    I2C1CONbits.SEN=1;
    while(I2C1CONbits.SEN!=0);
    
    I2C1TRN=0x3A;
    while(I2C1STATbits.TRSTAT!=0);
    
    if(I2C1STATbits.ACKSTAT==0)
    {
        I2C1TRN=0x05;
        while(I2C1STATbits.TRSTAT!=0);
        I2C1CONbits.RSEN=1;
        while(I2C1CONbits.RSEN!=0);
        
        
        I2C1TRN=0x3B;
        while(I2C1STATbits.TRSTAT!=0);
        I2C1CONbits.RCEN=1;
        I2C1CONbits.ACKDT=1;
        while(I2C1CONbits.RCEN!=0);
        
        //while(I2C1STATbits.ACKSTAT==0);
        data=I2C1RCV;
        I2C1CONbits.ACKEN=1;
        while(I2C1CONbits.ACKEN!=0);
        //while(I2C1STATbits.RBF!=0);
        //I2C1CONbits.ACKDT=0;
        //while(I2C1CONbits.ACKDT!=1);
        
    }
    I2C1CONbits.PEN=1;
    while(I2C1CONbits.PEN!=0);
    
    return data;
    
}