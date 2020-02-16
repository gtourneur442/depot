#ifndef DETECTION_TAP_H    
#define DETECTION_TAP_H

#include <stdio.h>
#include <stdlib.h>
#include <xc.h>
#include <sys/attribs.h>

void writeDetectionTap();
int readTap();
void writeRegisterTap(int registre, int data);
int readRegisterTap(int registre);


#endif /* DETECTION_TAP_H */