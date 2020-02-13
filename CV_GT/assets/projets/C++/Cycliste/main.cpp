#include <iostream>
#include <time.h>

#include "cycliste.h"

using namespace std;

int main()
{
    srand(time(nullptr));

    Cycliste *premier = new Cycliste("Bob", 1);
    Cycliste *second = new Cycliste("Boby", 2);

    for(int i=0; i<10; i++)
    {
        int firstTime = premier->getTime();
        int secondTime = second->getTime();

        if(firstTime < secondTime)
            cout << premier->getName() << " est en tête" << endl;
        else if(firstTime > secondTime)
            cout << second->getName() << " est en tête" << endl;
        else    // quand c'est le même temps
            cout << second->getName() << " et " << premier->getName() << " sont cote à cote" << endl;
    }

    delete premier;
    delete second;
    return 0;
}
