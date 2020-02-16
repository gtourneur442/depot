
#ifndef CALCULATRICE_H    /* Guard against multiple inclusion */
#define CALCULATRICE_H

#include <stdio.h>
#include <stdlib.h>
#include <xc.h>
#include <sys/attribs.h>

void initButton();
unsigned char valueFromSwitch();
void printValue(unsigned short value);
void printValue2(int value);
char calculate(unsigned char value);

#endif /* CALCULATRICE_H */

