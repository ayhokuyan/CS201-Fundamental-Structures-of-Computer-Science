#include <iostream>
#include <string>
using namespace std;

#include "Book.h"
#include "BookStore.h"

int main(){
   BookStore bs;
    
   bs.addBook( "Tutunamayanlar", 40.50 );
   bs.addBook( "Bir Gun Tek Basina", 34.99 );
   bs.addBook( "Love in the Time of Cholera", 40 );
   bs.addBook( "Die Blendung", 27.75 );
    
   bs["Bir Gun Tek Basina"].addEdition( 1974 );
   bs["Bir Gun Tek Basina"].addEdition( 1998 );
   bs["Bir Gun Tek Basina"].addEdition( 2007 );
	
   cin >> bs["Love in the Time of Cholera"];
	
   cout << endl << bs << endl;
	
   bs.removeBook( "Bir Gun Tek Basina" );
   cout << bs << endl;
	
   try {
      cin >> bs["The Little Prince"];
   }
   catch ( const exception& e ){
      cout << e.what() << endl;
   }
   try {
      bs.addBook( "Die Blendung", 50.45 );
   }
   catch ( const exception& e ){
      cout << e.what() << endl;
   }
   try {
      bs.removeBook( "The Waves" );
   }
   catch ( const exception& e ){
      cout << e.what() << endl;
   }
   cout << endl;
	
   BookStore bs2(bs);
   Book one( "The Catcher in the Rye", 20 );
   bs2["Tutunamayanlar"] = one;
	
   cout << bs << endl;
   cout << bs2 << endl;
	
   return 0;
}

