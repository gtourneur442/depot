#include <iostream>

#include "book.h"
#include "boardgame.h"
#include "user.h"

using namespace std;

int main()
{
    Book *firstBook = new Book("Le portrait", "Je ne sais plus", "Plomb", 1858);
    Book *secondBook = new Book("Le portrait 2 le retour", "Je ne sais plus", "Plomb", 1889);
    BoardGame *firstBoardGame = new BoardGame("Agricola");
    BoardGame *secondBoardGame = new BoardGame("Montjoie");

    User *firstUser = new User("Clément");
    User *secondUser = new User("Guillaume");

    firstUser->borrow(firstBook);
    secondUser->borrow(firstBook);

    /*firstUser->display();
    secondUser->display();*/

    firstUser->giveBack();

    /*firstUser->display();
    secondUser->display();*/

    firstUser->borrow(secondBook);
    secondUser->borrow(firstBook);

    /*firstUser->display();
    secondUser->display();*/

    firstUser->giveBack();

    // Clement : rien
    // Guillaume : Le portrait

    firstUser->borrow(firstBoardGame);

    firstUser->display();
    secondUser->display();

    delete firstBook;
    delete secondBook;
    delete firstUser;

    return 0;
}
