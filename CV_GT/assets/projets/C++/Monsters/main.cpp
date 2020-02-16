#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <iostream>
#include <string>

using namespace std;

string noms[5] = {"Harpie_rouge","Harpie_bleue","Harpie_jaune","Harpie_verte","Harpie_Papi"};

typedef struct Monsters_t {
    string nom;
    int age;
    int niveauTerreur;
    Monsters_t *next;
} Monsters;

Monsters *createMonsters()
{
    Monsters *Harpie;
    Harpie = new Monsters();
    Harpie->nom = noms[rand() % 5];
    Harpie->age = rand() % 10;
    Harpie->next = NULL;
    return Harpie;
}

void afficher(Monsters *myMonsters)
{
    cout << myMonsters->nom << " a un âge de " << myMonsters->age << " ans !" << endl;
}

Monsters *createMonstersGroup(int numberOfMonsters)
{
    Monsters *firstMonster;
    Monsters *currentMonster;

    firstMonster = createMonsters();
    currentMonster = firstMonster;

    for (int i=1; i < numberOfMonsters; i++)
    {
        currentMonster->next = createMonsters();
        currentMonster = currentMonster->next;
    }

    currentMonster->next = NULL;

    return firstMonster;
}

void affichGroup(Monsters *currentMonster, int numberOfMonsters)
{
    cout << "Liste des monstres : " << endl;
    cout << currentMonster->nom << " a un age de " << currentMonster->age << " ans !" << endl;
    for (int i=1; i < numberOfMonsters; i++)
    {
        currentMonster = currentMonster->next;
        cout << currentMonster->nom << " a un age de " << currentMonster->age << " ans !" << endl;
    }
}

Monsters *getFirstToTransform(Monsters *firstMonster)
{
    Monsters *currentMonster;
    currentMonster = firstMonster;

    while(currentMonster != NULL)
    {
        if(currentMonster->age > 5)
            return currentMonster;
        else
            currentMonster = currentMonster->next;
    }
    return NULL;
}

int main(int argc, char *argv[])
{
    int nbMonsters = 5;
    Monsters *oneMonster;
    Monsters *firstToTransform;
    srand(time(NULL));

    oneMonster = createMonstersGroup(5);
    affichGroup(oneMonster,5);
    firstToTransform = getFirstToTransform(oneMonster);

    if(firstToTransform != NULL)
        cout << "La premiere a se transformer a l'age de " << firstToTransform->age << " ans !" << endl;
    else
        cout << "Elles sont toutes trop jeunes ! ... Pour l'instant !" << endl;

    return 0;
}
