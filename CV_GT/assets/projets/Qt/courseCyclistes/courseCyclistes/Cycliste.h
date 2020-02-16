#ifndef CYCLISTE_H
#define CYCLISTE_H
#include <iostream>
#include <string>
#include <ctime>
#include <cstdlib>

using namespace std;

class Cycliste
{
public:
    Cycliste(string nomCoureur, int numeroCoureur, string couleurCoureur);
    //Cycliste(string couleurCoureur);
    ~Cycliste();
    int getTime(void);
    string getName(void);
    //void tourPiste();
private:
    string nomCoureur;
    string couleurCoureur;
    int numeroCoureur;
    //int temps;
};

#endif // CYCLISTE_H
