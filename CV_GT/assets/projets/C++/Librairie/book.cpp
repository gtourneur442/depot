#include "book.h"

#include <iostream>

Book::Book(string title, string author, string publisher, int pubYear)
{
    this->title = title;
    this->author = author;
    this->publisher = publisher;
    this->publicationYear = pubYear;
}

Book::~Book()
{

}

string Book::getTitle(void)
{
    return this->title;
}

void Book::display(void)
{
    cout << this->title << endl;
}
