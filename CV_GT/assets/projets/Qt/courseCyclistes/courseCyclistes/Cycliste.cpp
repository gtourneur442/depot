#include "Cycliste.h"

Cycliste::Cycliste(string nomCoureur, int numeroCoureur, string couleurCoureur)
{
    this->nomCoureur = nomCoureur;
    this->numeroCoureur = numeroCoureur;
    this->couleurCoureur = couleurCoureur;
    cout << nomCoureur << ", ";
    cout << "numéro " << numeroCoureur << ", ";
    cout << "Maillot " << couleurCoureur << endl;
}

/*Cycliste::Cycliste(string couleurCoureur)
{
    nomCoureur = "Richard Virenque";
    numeroCoureur = 512;
    cout << nomCoureur << ", ";
    cout << "numéro " << numeroCoureur << ", ";
    cout << "Maillot " << couleurCoureur << endl;
}*/

int Cycliste::getTime(void)
{
    return rand() % 1001;
}

string Cycliste::getName(void)
{
    return this->nomCoureur;
}

/*void Cycliste::tourPiste()
{
    int tour = 10;
    for(int i = 0; i < tour; i++)
    {
        int tempsCourse = getTime(temps);

            cout << "Tour " << i+1 << " : " << getName(nomCoureur) << " : " << tempsCourse << endl;
    }
}*/

Cycliste::~Cycliste()
{

}
