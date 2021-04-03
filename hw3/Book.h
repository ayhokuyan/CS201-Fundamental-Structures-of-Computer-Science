#ifndef BOOK_H
#define BOOK_H

#include <string>
using namespace std;
class Book
{
private:
    int id;
    string name;
    int year;
public:
    Book(const int book_id, const string bk_name, const int bk_year);
    Book( const Book& aBook );
    Book();
    ~Book();
    Book& operator=( const Book& aBook );
    void print(string status);
    int getId();
    string getName();
    int getYear();
};

#endif