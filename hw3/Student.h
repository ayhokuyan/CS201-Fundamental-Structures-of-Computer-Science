#ifndef STUDENT_H
#define STUDENT_H

#include <string>
#include "BookList.h"
using namespace std;
class Student
{
private:
    int id;
    string name;
    BookList stdBooks;
public:
    Student(const int std_id, const string std_name);
    Student();
    Student(Student& aList);
    ~Student();
    Student& operator=( const Student& right );
    void print(string status);
    int getId();
    string getName();
    BookList* getStdBooks();
};
#endif
