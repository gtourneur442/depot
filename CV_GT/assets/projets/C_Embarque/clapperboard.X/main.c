/* 
 * File:   main.c
 * Author: karlito
 *
 * Created on December 1, 2019, 5:58 PM
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "libraryAllumerLED.h"
#include "shineLED.h"
#include "changerChiffre.h"
#include "i2c.h"
#include "lcd.h"
#include "timer.h"
#include "utils.h"
#include "calculatrice.h"
#include "regulateTimer.h"
#include "jcI2C.h"
#include "buttonSceneNumber.h"
#include "detectionTap.h"
#include "uart.h"
#include "RS232.h"


#pragma config JTAGEN = OFF     
#pragma config FWDTEN = OFF      


#pragma config FNOSC =	2      // select oscilator externe (quartz at 8MHz)
#pragma config FSOSCEN =	OFF     // Disable secondary oscilator
#pragma config POSCMOD =	XT      // XT oscilator mode
#pragma config OSCIOFNC =	ON      //
#pragma config FPBDIV =     DIV_2   // Peripheralls run at /2 the speed

#pragma config FPLLIDIV =	DIV_2
#pragma config FPLLMUL =	MUL_20
#pragma config FPLLODIV =	DIV_1

unsigned int valeur = 0;
char sceneDuration[50];
char sceneDuration2[50];

void __ISR(_TIMER_2_VECTOR, ipl7) Timer2ISR(void)
{
    //unsigned int value = readY();
    IFS0bits.T2IF = 0;
    writeDetectionTap(0x24,0x10);
    //allumerLED2(readRegisterTap(0x22));
    minSecondes(valeur);
    //printValue2(value);
    // blinkLED();
    stopChrono(sceneDuration, sceneDuration2);
}

void __ISR(_TIMER_3_VECTOR, ipl7) Timer3ISR(void)
{
    IFS0bits.T3IF = 0;
    valeur = timerState(valeur);
    allumerLED2(valeur);
    
    int minute = valeur/60;
    int seconde = valeur%60;
    sprintf(sceneDuration,"%2d",minute);
    sprintf(sceneDuration2,"%2d",seconde);
    //itoa(sceneDuration,minute,10);
    //itoa(sceneDuration2,seconde,10);
    //LCD_WriteStringAtPos(sceneDuration, 1, 1);
    //LCD_WriteStringAtPos(sceneDuration2, 1, 3);
    
    //sentenceSend(sceneDuration);
    //sentenceSend(sceneDuration2);
    //dialogToRemote(sceneDuration);
    //dialogToRemote(sceneDuration2);
}

int main(int argc, char** argv)
{   
    initLED();
    initdDigit();
    initButton();
    initI2C();
    initAccelero();
    LCD_Init();
    initTimer2();
    initTimer3();
    initUART();
    
    writeI2C();
    writeDetectionTap(0x21,0x3F);
    writeDetectionTap(0x0F,0x20);
    LCD_WriteStringAtPos("SCENE 1", 0, 1);
    
    while(1)
    { 
        testButton();
        decreaseSceneNumber();
        increaseSceneNumber();
    }
    
    return (EXIT_SUCCESS);
}

