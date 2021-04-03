#ifndef STDLIST_H
#define STDLIST_H

#include "Student.h"
#include <iostream> 
typedef Book book;


class StdList{
public:
    StdList();
    StdList(const StdList& aList);
    ~StdList();
    bool isEmpty();
    int getSize();
    bool retrStu(const int std_id, Student*& stu);
    bool insertStu(Student newStu);
    bool removeStu(int stu_id); 
    void print();
    bool addBk(int std_id, Book& bk);
    bool searchBk(int bk_id, Book*& bk, BookList*& delList);
    bool searchBkID(int bk_id, Book*& bk, int& stu_id);
private:
    struct Node{
        Student item;
        Node* next;
        Node* prev;
    };
    int size;
    Node* head;
    Node* findStu(int stu_id); 

    
};

#endif