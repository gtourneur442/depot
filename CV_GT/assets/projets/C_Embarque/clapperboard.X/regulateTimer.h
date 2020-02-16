#ifndef REGULATE_TIMER_H    
#define REGULATE_TIMER_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <xc.h>
#include <sys/attribs.h>

#define BTND PORTAbits.RA15
#define BTNL PORTBbits.RB0
#define BTNU PORTBbits.RB1
#define BTNC PORTFbits.RF0
#define BTNR PORTBbits.RB8

#define timer_current 0
#define timer_stop    1

void testButton();
int timerState(int value);
void stopChrono(char sentence[], char sentence2[]);

#endif /* REGULATE_TIMER_H */
