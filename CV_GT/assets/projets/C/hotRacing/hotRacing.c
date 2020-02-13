#include <stdio.h>
#include <stdlib.h>

#include "hotRacing.h"

int main(int argc, char *argv[])
{
    int i, nbHotCars, bestScore = 0, indexWinner = -1;

    printf("Merci de sélectionner le nombre de HOT CARS : \n\r");
    scanf("%d",&nbHotCars);
    printf("Il y a %d HOT CARS en course !\n\n\r",nbHotCars);
    Voiture HotRacing[nbHotCars];

    for(i = 0; i <= nbHotCars-1; i++)
    {
        printf("Merci de saisir le nom du véhicule %d : \n\r",i+1);
        scanf("%s",&HotRacing[i].nom);
        HotRacing[i].score = 0;
    }

    deathLap(HotRacing);
    highScore(HotRacing,nbHotCars);
    affichageScore(HotRacing,nbHotCars);
    for(i = 0; i <= nbHotCars-1; i++)
    {
        printf("HOT CAR %s [%d] : %d\n\r",HotRacing[i].nom, i+1, HotRacing[i].score);
        if(HotRacing[i].score > bestScore)
        {
            bestScore = HotRacing[i].score;
            indexWinner = i;
        }
    }
    printf("#############################################################\n\r");
    printf("Félicitations !!! %s a gagné avec un score de %d !!!\n\r",HotRacing[indexWinner].nom,HotRacing[indexWinner].score);
    printf("#############################################################\n\r");
}

int deathLap(Voiture HotRacing[])
{
    int i;
    for(i = 1; i <= NB_TOURS; i++)
    {
        unsigned int nombre;
        printf("Merci d'indiquer le numéro du vainqueur du tour %d ! \n\r", i);
        printf("Le vainqueur du tour %d est : ", i);
        scanf("%d",&nombre);
        printf("Il s'agit de : %s\n\r",HotRacing[nombre-1].nom);
        HotRacing[nombre-1].score++;
        printf("%d\n\r",HotRacing[nombre-1].score);
    }
}

void highScore(Voiture HotRacing[], int nombre)
{
    FILE *fichier = NULL;
    fichier = fopen("highscore.txt", "w+");

    if(fichier != NULL)
    {
        int i;
        fprintf(fichier,"Scores : \n\r");
        for(i = 0; i <= nombre-1; i++)
        {
            fprintf(fichier,"%s : %d\n\r",HotRacing[i].nom,HotRacing[i].score);
        }
        fclose(fichier);
    }
    else
    {
        printf("Impossible d'ouvrir le fichier highscore.txt");
    }
    
}

void affichageScore(Voiture HotRacing[],int nombre)
{
    FILE* fichier = NULL;
    fichier = fopen("highscore.txt", "r");
 
    if (fichier != NULL)
    {
        int i;
        printf("Les scores sont : \n\r");
        for(i = 0; i <= nombre-1; i++)
        {
            fscanf(fichier, "%d", &HotRacing[i].score);
            printf("%d\n\r", HotRacing[i].score);
        }
        fclose(fichier);
    }
}