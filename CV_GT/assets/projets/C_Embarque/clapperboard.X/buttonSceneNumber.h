
#ifndef BUTTONSCENENUMBER_H
#define	BUTTONSCENENUMBER_H
#include "regulateTimer.h"
#ifdef	__cplusplus
extern "C" {
#endif
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "lcd.h"
  
void increaseSceneNumber();
void decreaseSceneNumber();
int recupNextSceneNumber();
int recupPreviousSceneNumber();
  
#ifdef	__cplusplus
}
#endif

#endif	/* BUTTONSCENENUMBER_H */

