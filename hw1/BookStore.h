#ifndef __BOOKSTORE_H
#define __BOOKSTORE_H

#include "Book.h"

class BookStore{
public:
    BookStore();
    BookStore( const BookStore& bsToCopy );
    ~BookStore();
    BookStore& operator=( const BookStore& right);
    Book& operator[]( const string title);

    void addBook( const string bookTitle, const double bookPrice );
    void removeBook( const string bookTitle );
    
private:
    Book* books;	// A dynamically created array of book objects
    int bookNo;		// Number of the books in the bookstore system
	
// Overloaded global function for << is declared as friend
friend ostream& operator<<( ostream& out, const BookStore& b );
};

#endif
