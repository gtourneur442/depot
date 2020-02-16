#ifndef SHINE_LED_H  
#define SHINE_LED_H  

#include <stdio.h>
#include <stdlib.h>
#include <xc.h>
#include <sys/attribs.h>

void initLED();
void turnLEDon(char ledNumber);
void turnLEDoff(char ledNumber);

#endif 

