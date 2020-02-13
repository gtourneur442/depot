#ifndef CYCLISTE_H
#define CYCLISTE_H

#include <string>
#include <iostream>
#include <time.h>
#include <cmath>
#include <cstdlib>

using namespace std;


class Cycliste
{
public:
    Cycliste(string name, int number);
    int getTime(void);
    string getName(void);


private:
    string name;
    int number;
};

#endif // CYCLISTE_H
