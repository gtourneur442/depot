#ifndef RS232_H    /* Guard against multiple inclusion */
#define RS232_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <xc.h>
#include <sys/attribs.h>

void initUART();
void transmissionUart();
void transCharacter();
char *saisieCharacter();
void sendCharacter();

#endif /* RS232_H */
