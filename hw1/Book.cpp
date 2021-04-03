#include "Book.h"
#include <iostream>
#include <sstream>
#include <string>
using namespace std;
// Constructor
Book::Book( const string bookTitle, const double bookPrice){
    if(bookPrice < 0)
        price = 0;
    else
        price = bookPrice;
    title = bookTitle;
    editionNo = 0;
    editionYears = NULL;
}

//Copy constructor
Book::Book( const Book& bookToCopy ):editionNo(bookToCopy.editionNo){
    if(editionNo > 0){
        editionYears = new int[editionNo];
        for(int i=0; i<editionNo; i++){
            editionYears[i] = bookToCopy.editionYears[i];
        }
    }
    else
        editionYears = NULL;
    title = bookToCopy.title;
    price = bookToCopy.price;
}

// Destructor
Book::~Book(){
    if(editionNo > 0)
        delete[] editionYears;
}


//Equal operator
Book& Book::operator=( const Book& right ){
    if(&right != this){
        if(editionNo != right.editionNo){
            if(editionNo > 0){
                delete[] editionYears;
            }
            editionNo = right.editionNo;
            if(editionNo > 0)
                editionYears = new int[editionNo];
            else
                editionYears = NULL;
        }
        for(int i=0; i < editionNo; i++){
            editionYears[i] = right.editionYears[i];
        }
        title = right.title;
        price = right.price;
    }
    return *this;
}

// Add new edition
void Book::addEdition( const int newEditionYear ){
    int* temp;
    temp = new int[editionNo+1];
    for(int i=0; i<editionNo; i++){
        temp[i] = editionYears[i];
    }
    temp[editionNo] = newEditionYear;
    delete[] editionYears;
    editionNo++;
    editionYears = temp;
}

// Inputs the edition years onto the object
istream& operator>>( istream& in, Book& b ){
    string temp;
    cout << "Enter all edition years for " << b.title << " : ";
    getline(cin, temp);

    if(b.editionNo != 0){
        delete[] b.editionYears;
        b.editionNo = 0;
        b.editionYears = NULL;    
    }
    bool is_yr= false;
    string yr = "";
    int converted = 0;
    for(int i=0; temp[i] != '\0' ; i++){
        if(temp[i] != ' ' && !is_yr){
            is_yr = true;
        }
        if(is_yr){
            yr += temp[i];
        }
        if( (temp[i] == ' ' && is_yr) || (temp[i+1] == '\0' && is_yr)){
            is_yr = false;
            istringstream ss(yr);
            ss >> converted;
            b.addEdition(converted);
            yr = "";
        }
    }
    return in;
}

// Prints the properties of the object
ostream& operator<<( ostream& out, const Book& b ){
    cout << b.title << ", "<< b.price << " TL ";
    if(b.editionNo == 0){
        cout << "(none)";
    }
    else{
        cout << "(";
        for(int i = 0; i < b.editionNo; i++){
            if(i != 0){
                cout << ", " << b.editionYears[i];
            }
            else{
                cout << b.editionYears[0];
            }
        }
        cout << ")";
    }
    return out;
}
