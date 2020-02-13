#ifndef BOARDGAME_H
#define BOARDGAME_H

#include <string>

#include "article.h"

using namespace std;

class BoardGame : public Article
{
public:
    BoardGame(string title);
    ~BoardGame();

    void display(void);

private:
    string title;

};

#endif // BOARDGAME_H
