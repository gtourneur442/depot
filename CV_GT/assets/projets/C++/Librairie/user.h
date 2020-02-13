#ifndef USER_H
#define USER_H

#include <string>

#include "article.h"

using namespace std;

class User
{
public:
    User(string name);
    void borrow(Article *article);
    void display(void);
    void giveBack(void);

private:
    string name;

    Article *articleBorrowed;
};

#endif // USER_H
