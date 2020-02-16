

#ifndef I2C_H
#define I2C_H

#include <stdio.h>
#include <stdlib.h>
#include <xc.h>
#include <sys/attribs.h>

#ifdef __cplusplus
extern "C"  {
#endif
    
void initI2C();
void initAccelero();
void writeI2C();
int readI2C();


#ifdef __cplusplus
}
#endif

#endif