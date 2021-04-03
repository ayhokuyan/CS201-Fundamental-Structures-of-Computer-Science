#ifndef BOOKLIST_H
#define BOOKLIST_H


#include "Book.h"
#include <iostream> 
typedef Book book;



class BookList{
public:
    BookList();
    BookList(const BookList& aList);
    ~BookList();
    bool isEmpty();
    int getSize();
    bool retrBk(const int bk_id, Book*& bk);
    bool insertBk(Book& newBk);
    int getHeadId();
    bool removeBk(int bk_id); 
    void print(string status);
    BookList& operator=( const BookList& right );
    string toString();

private:
    struct Node{
        Book item;
        Node* next;
    };
    int size;
    Node* head;
    Node* findBk(int bk_id);

    
};

#endif