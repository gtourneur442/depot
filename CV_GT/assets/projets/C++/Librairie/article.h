#ifndef ARTICLE_H
#define ARTICLE_H


class Article
{
public:
    Article();
    virtual ~Article();

    void setBorrowed(bool borrowed);
    bool isBorrowed(void);
    virtual void display(void) = 0;

private:
    bool alreadyBorrowed;

};

#endif // ARTICLE_H
