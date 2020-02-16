#include "regulateTimer.h"

int state = timer_current;
char sceneDuration[50];
char entier[10];

void testButton()
{
    static char oldbutton = 0;
    if(BTNC == 1 && oldbutton == 0)
    {
        if(state == timer_stop)
        {
            state = timer_current;
        }
        else if(state == timer_current)
        {
            state = timer_stop;
        }
    }
    oldbutton = BTNC;
}

int timerState(int value)
{   
    switch(state)
    {
        case timer_current:
            value++;
            break;
        case timer_stop:
            //itoa(sceneDuration,value,10);
            //value = sceneDuration; 
            break;
    }
    
    return value;
}

void stopChrono(char sentence[], char sentence2[])
{
    static char oldActive = 0;
    static int Active;
    Active = blinkLED();
    if(Active == 1 && oldActive == 0)
    {
        if(state == timer_stop)
        {
            state = timer_current;
        }
        else if(state == timer_current)
        {
            state = timer_stop;
            sentenceSend("SCENE ");
            sentenceSend(entier);
            sentenceSend(" = ");
            sentenceSend(sentence);
            sentenceSend(":");
            sentenceSend(sentence2);
            sentenceSend("\n\r");
        }
    }
    oldActive = Active;
}