#include"buttonSceneNumber.h"

int currentSceneNumber = 1;
int nextSceneNumber;
int previousSceneNumber;

void increaseSceneNumber()
{   /*on utilise le bouton BTNU pour ajouter 1 au num de prise */
    char str[20];
    char entier[10];
    static char ancientbutton = 0;
    if(BTNU == 1 && ancientbutton == 0)
    {
        nextSceneNumber = currentSceneNumber + 1;
        itoa(entier,nextSceneNumber,10);
        currentSceneNumber = nextSceneNumber;
        strcpy(str,"SCENE ");
        strcat(str,entier);
        LCD_DisplayClear();
        LCD_WriteStringAtPos(str, 0, 1);
    }
    ancientbutton = BTNU;
}

void decreaseSceneNumber()
{/*on utilise le bouton BTND pour ajouter 1 au num de prise */ 
    char str[20];
    char entier[10];
    static char ancientbutton = 0;
    if(BTND == 1 && ancientbutton == 0)
    {
        if (currentSceneNumber > 0)
            previousSceneNumber = currentSceneNumber - 1;
        else if (currentSceneNumber <= 0)
            previousSceneNumber = 0;
        itoa(entier,previousSceneNumber,10);
        currentSceneNumber = previousSceneNumber;
        strcpy(str,"SCENE ");
        strcat(str,entier);
        LCD_DisplayClear();
        LCD_WriteStringAtPos(str, 0, 1);
    }
    ancientbutton = BTND;
}

int recupNextSceneNumber()
{
    increaseSceneNumber();
    return nextSceneNumber;
}

int recupPreviousSceneNumber()
{
    decreaseSceneNumber();
    return previousSceneNumber;
}