#include "Book.h"
#include <iostream>
#include <iomanip>

Book::Book(const int book_id=-1, const string bk_name="non", const int bk_year=-1){
    id = book_id;
    name = bk_name;
    year = bk_year;

}

Book::Book(const Book& aBook){
    if(aBook.id>0){
        id = aBook.id;
        name = aBook.name;
        year = aBook.year;
    }else{
        id = -1;
        name = "";
        year = -1;
    }
    
}

Book::Book(){
    id = -1;
    name = "";
    year = -1;
}

Book::~Book(){
}


int Book::getId(){
    return id;
}

string Book::getName(){
    return name;
}
int Book::getYear(){
    return year;
}

Book& Book::operator=( const Book& right ){
        name = right.name;
        id = right.id;
        year = right.year;
    return *this;
}

void Book::print(string status){
    cout << left << setw(10) << id << setw(23) << name << setw(10) <<  year << setw(50) << status << endl;
}