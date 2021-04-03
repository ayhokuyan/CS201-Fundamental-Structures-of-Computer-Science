#include <string>
#include "BookList.h"
#include "StdList.h"
using namespace std;
class LibrarySystem {
public:
    LibrarySystem();
    ~LibrarySystem();
    void addBook( const int bookId, const string name, const int year );
    void deleteBook( const int bookId );
    void addStudent( const int studentId, const string name );
    void deleteStudent( const int studentId );
    void checkoutBook( const int bookId, const int studentId );
    void returnBook( const int bookId );
    void showAllBooks();
    void showBook( const int bookId );
    void showStudent( const int studentId );
private:
    BookList libBooks;
    StdList stdLst;
};