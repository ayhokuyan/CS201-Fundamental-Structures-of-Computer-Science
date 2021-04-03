#include "BookStore.h"
#include "Book.h"
#include <iostream> 
#include <stdexcept>
using namespace std;
//constructor
BookStore::BookStore(){
    books = NULL;
    bookNo = 0;
}

//copy constructor
BookStore::BookStore( const BookStore& bsToCopy )
            :bookNo(bsToCopy.bookNo){
    if(bookNo > 0){
        books = new Book[bookNo];
        for(int i=0; i<bookNo; i++){
            books[i] = bsToCopy.books[i];
        }
    }
    else
        books = NULL;
}

//destructor
BookStore::~BookStore(){
    if(books){
        delete[] books;
    }
}

//equal operator
BookStore& BookStore::operator=( const BookStore& right){
    if(&right != this){
        if(bookNo != right.bookNo){
            if(bookNo > 0){
                delete[] books;
            }
            bookNo = right.bookNo;
            if(bookNo > 0)
                books = new Book[bookNo];
            else
                books = NULL;
        }
        for(int i = 0; i < bookNo; i++){
            books[i] = right.books[i];       
        }
    }
    return *this;
}

//index operator
Book& BookStore::operator[]( const string title){
    if(bookNo > 0){
        for(int i= 0; i < bookNo; i++){
            if(books[i].title == title){
                return books[i];
            }
        }
    }
    throw invalid_argument("Cannot access a non-existent book (" + title + ")");
}

//add book function
void BookStore::addBook( const string bookTitle, const double bookPrice ){
    if(bookNo > 0){
        for(int i = 0; i < bookNo; i++){
            if(bookTitle == books[i].title){
                throw invalid_argument("Cannot add an already existing book (" + bookTitle + ")");
            }
        }
    }
    Book bktoAdd(bookTitle, bookPrice);
    Book* temp = new Book[bookNo+1];
    for(int i = 0; i < bookNo; i++){
        temp[i] = books[i];
    }
    temp[bookNo] = bktoAdd;
    bookNo++;
    delete[] books;
    books = temp;
}


//remove book function
void BookStore::removeBook( const string bookTitle ){
    int removeIndex = 0;
    bool title_seen = false;
    if(bookNo > 0){
        for(int i = 0; i < bookNo; i++){
            if(bookTitle == books[i].title){
                title_seen = true;
                removeIndex = i;
            }
        }
        if(!title_seen)
            throw invalid_argument("Cannot remove a non-existent book (" + bookTitle + ")");
        else{
            for(int i = removeIndex; i < bookNo-1; i++)
            {
                books[i] = books[i+1];
            }
            Book* temp = new Book[bookNo-1];
            bookNo--;
            for(int i = 0; i < bookNo; i++)
            {
                temp[i] = books[i];
            }
            delete[] books;
            books = temp;
        }
        
        
    }
}

// Overloaded global function for << is declared as friend
ostream& operator<<( ostream& out, const BookStore& b ){
    for(int i = 0; i < b.bookNo; i++){
        cout << b.books[i] << endl;
    }
    cout << endl;
    return out;
}
