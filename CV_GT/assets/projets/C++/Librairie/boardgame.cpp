#include "boardgame.h"

#include <iostream>

BoardGame::BoardGame(string title)
{
    this->title = title;
}

BoardGame::~BoardGame()
{

}

void BoardGame::display(void)
{
    cout << this->title << endl;
}
