#include "article.h"

Article::Article()
{
    this->alreadyBorrowed = false;
}

Article::~Article()
{

}

void Article::setBorrowed(bool borrowed)
{
    this->alreadyBorrowed = borrowed;
}

bool Article::isBorrowed(void)
{
    return this->alreadyBorrowed;
}
