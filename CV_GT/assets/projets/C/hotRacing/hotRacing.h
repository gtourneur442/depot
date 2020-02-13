#ifndef HOTRACING_H_INCLUDED
#define HOTRACING_H_INCLUDED

#define NB_TOURS 10

typedef struct{
    char nom[10];
    int score;
} Voiture;

int deathLap(Voiture HotRacing[]);
void highScore(Voiture HotRacing[],int nombre);
void affichageScore(Voiture HotRacing[],int nombre);

#endif // HOTRACING_H_INCLUDED