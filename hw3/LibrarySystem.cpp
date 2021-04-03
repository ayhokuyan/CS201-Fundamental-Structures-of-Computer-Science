#include "LibrarySystem.h"
#include <iomanip>
#include <sstream>

LibrarySystem::LibrarySystem(){
    
}
LibrarySystem::~LibrarySystem(){
    
}
void LibrarySystem::addBook( const int bookId, const string name, const int year ){
    Book* rtrBk;
    Book newBk(bookId,name,year);
    if(libBooks.retrBk(bookId,rtrBk)){
        cout << "Book " << bookId << " already exists\n";
    }else if(libBooks.insertBk(newBk)){
       cout << "Book " << newBk.getId() << " has been added\n";
    }
}

void LibrarySystem::deleteBook( const int bookId ){
    Book* rtrBk = NULL;
    BookList* dlLst = NULL;
    if(libBooks.retrBk(bookId,rtrBk)){
        cout << "Book " << bookId << " has not been checked out\n";
        libBooks.removeBk(bookId);
        cout << "Book " << bookId << " has been deleted\n";
    }else if(stdLst.searchBk(bookId,rtrBk,dlLst)){
        returnBook(bookId);
        libBooks.removeBk(bookId);
        cout << "Book " << bookId << " has been deleted\n";
    }else
    {
        cout << "Book " << bookId << " does not exist\n";
    }
    
}

void LibrarySystem::addStudent( const int studentId, const string name ){
    Student newStu(studentId, name);
    stdLst.insertStu(newStu);
}

void LibrarySystem::deleteStudent( const int studentId ){
    Student* std;
    if(stdLst.retrStu(studentId,std)){
        BookList* std_list = (*std).getStdBooks();
        if(std_list != NULL){
            int sz = (*std_list).getSize();
            for(int i=0;i<sz;i++){
                returnBook((*std_list).getHeadId());
            }
        }
        stdLst.removeStu(studentId);
    }else
    {
        cout << "Student " << studentId << " does not exist" << endl; 
    }
    
}

void LibrarySystem::checkoutBook( const int bookId, const int studentId ){
    Book* srcBk = NULL;
    Student* srcStd = NULL;

    Book* rtrBk = NULL;
    BookList* dlLst = NULL;

    bool isBkRd = libBooks.retrBk(bookId, srcBk);
    bool isStdRd = stdLst.retrStu(studentId, srcStd);
    bool isBkTkn = stdLst.searchBk(bookId,rtrBk,dlLst);

    if(isBkTkn){
        cout << "Book " << bookId << " has already checked out by another student" << endl;
    }else{
        if(isBkRd && isStdRd){
            stdLst.addBk((*srcStd).getId(),*srcBk);
            libBooks.removeBk(bookId);
            cout << "Book " << bookId << " has been checked out by student " << studentId <<endl;
        }else if(isBkRd && ~isStdRd){
            cout << "Student " << studentId << " does not exist for checkout" << endl;
        }else if(~isBkRd && isStdRd){
            cout << "Book " << bookId << " does not exist for checkout" << endl;
        }else{
            cout << "Book " << bookId << " does not exist for checkout" << endl;
        }   
    }
}

void LibrarySystem::returnBook( const int bookId ){
    Book* rtrBk = NULL;
    BookList* dlLst = NULL;


    if(stdLst.searchBk(bookId,rtrBk,dlLst)){
        libBooks.insertBk(*rtrBk);
        (*dlLst).removeBk((*rtrBk).getId());
        cout << "Book " << bookId << " has been returned" <<endl;
    }else
    {
        cout << "Book " << bookId << " has not been checked out\n";
    }
}

void LibrarySystem::showAllBooks(){
    cout << left << setw(10) << "Book id" <<setw(23) << "Book name" << setw(10) << "Year" << setw(50) << "Status" <<endl;
    libBooks.print("Not checked out");
    stdLst.print();
}

void LibrarySystem::showBook( const int bookId ){
    Book* rtrBk = NULL;
    BookList* dlLst = NULL;
    int id = -1;
    if(libBooks.retrBk(bookId,rtrBk)){
        (*rtrBk).print("Not checked out");
    }else if(stdLst.searchBkID(bookId,rtrBk,id)){
        stringstream stream;
        stream << id;
        string s = "Checked out by student " + stream.str();
        (*rtrBk).print(s);
    }else
    {
        cout << "Book " << bookId << " does not exist\n";
    }
}

void LibrarySystem::showStudent( const int studentId ){
    Student* toShow = NULL;
    if(stdLst.retrStu(studentId,toShow)){
        cout << "Student id: " << (*toShow).getId() << " student name: " << (*toShow).getName() << endl;
        if ((*(*toShow).getStdBooks()).getSize()<=0)
        {
            cout << "Student " << studentId << " has no books"<<endl;
        }
        else
        {
            cout << "Student " <<  (*toShow).getId() << " has checked out the following books:" << endl;
            cout << left << setw(10) << "Book id" << setw(23) << "Book name" << setw(10) << "Year" << endl;
            BookList* std_list = (*toShow).getStdBooks();
            (*std_list).print("");  
        }
    }else{
        cout << "Student " << studentId << " does not exist" << endl;
    }
}