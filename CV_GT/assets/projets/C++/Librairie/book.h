#ifndef BOOK_H
#define BOOK_H

#include <string>

#include "article.h"

using namespace std;

class Book : public Article
{
public:
    Book(string title, string author, string publisher, int pubYear);
    ~Book();

    string getTitle(void);
    void display(void);

private:
    string title;
    string author;
    string publisher;
    int publicationYear;

};

#endif // BOOK_H
