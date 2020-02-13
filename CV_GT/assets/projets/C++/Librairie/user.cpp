#include "user.h"

#include <iostream>

User::User(string name)
{
    this->name = name;

    this->articleBorrowed = nullptr;
}

void User::borrow(Article *article)
{
    if(article->isBorrowed() == false)
    {
        // I can borrow the book

        if(this->articleBorrowed == nullptr)
        {
            // I have empty hands
            article->setBorrowed(true);
            this->articleBorrowed = article;
        }
        else
        {
            // I already have one
            cout << this->name << " dis : J'ai les main pleines ?" << endl;
        }
    }
    else
    {
        // I can NOT borrow
        cout << this->name << " dis : Ba où il est ?" << endl;
    }
}

void User::giveBack(void)
{
    if(this->articleBorrowed != nullptr)
    {
        this->articleBorrowed->setBorrowed(false);
        this->articleBorrowed = nullptr;
    }
}

void User::display(void)
{
    cout << "Je suis " << this->name;

    if(this->articleBorrowed != nullptr)
    {
        cout << ", and I borrowed : ";
        this->articleBorrowed->display();
        cout << endl;
    }

    cout << endl;
}
