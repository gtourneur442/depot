/* 
 * File:   I2C.h
 * Author: arinfo
 *
 * Created on 18 décembre 2019, 10:27
 */

#ifndef I2C_H
#define	I2C_H

#include <stdio.h>
#include <stdlib.h>
#include <xc.h>
#include <sys/attribs.h>

#ifdef	__cplusplus
extern "C" {
#endif

void initI2C();
void initAccelero();
void writeAccelero();
int readX();
int readY();
int readZ();


#ifdef	__cplusplus
}
#endif

#endif	/* I2C_H */

