#include "Cycliste.h"

int main()
{
    srand(time(0));

    Cycliste *Armstrong = new Cycliste("Lance Armstrong",142,"rouge");
    Cycliste *Virenque = new Cycliste("Richard Virenque",512,"jaune");

    for (int i=0; i < 10; i++)
    {
        int firstTime = Armstrong->getTime();
        int secondTime = Virenque->getTime();

        if (firstTime < secondTime)
        {
            cout << Armstrong->getName() << " est en tête" << endl;
        }
        else if (firstTime > secondTime)
        {
            cout << Virenque->getName() << " est en tête" << endl;
        }
        else
        {
            cout << Virenque->getName() << " et " << Armstrong->getName() << " sont côte à côte" << endl;
        }
    }

    /*Armstrong->tourPiste();
    Virenque->tourPiste();*/

    delete Armstrong;
    delete Virenque;

    return 0;
}
