#include "cycliste.h"

/**
 * @brief Constructeur de cyclistes
 * @param name C'est le nom du cycliste
 * @param number C'est le numéro du cycliste
 */
Cycliste::Cycliste(string name, int number)
{
    this->name = name;
    this->number = number;
}

/**
 * @brief Retourne le temps au dernier tour
 * @return Retourne un temps de tour en secondes
 */
int Cycliste::getTime(void)
{
    return (rand() % 1001);
}

/**
 * @brief Retourne le nom du coureur
 * @return Le nom du coureur
 */
string Cycliste::getName(void)
{
    return this->name;
}

