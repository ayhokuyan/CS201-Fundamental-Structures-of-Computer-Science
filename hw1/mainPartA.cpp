#include <iostream>
#include <string>
using namespace std;

#include "Book.h"

int main(){
   Book A( "The Lord of the Rings", 31.25 );
   Book B( "The Dispossessed", 25.35 );
   Book C;
   Book D( A );
	
   
   A.addEdition( 2007 );
   B.addEdition( 1974 );

   C = B;
   C.addEdition( 1990 );
   C.addEdition( 2010 );
   C.addEdition( 1990 );
   B.addEdition( 2004 );
	
   cout << A << endl;
   cout << B << endl;
   cout << C << endl;
   cout << D << endl;
	
   cin >> B;
   cout << B << endl;
	
   cin >> B;
   cout << B << endl;
	
   cin >> B;
   cout << B << endl;

   cout << C << endl;
   return 0;
}
// This test file requires getting three lines from the keyboard.
// To test your program and compare its output with the correct
// output (provided in the OutputPartA.txt file), you may use the
// following three lines as your inputs. Just copy and paste the
// lines, of course do not take //. Note that the second line below
// only includes whitespaces.
//2001 2017 2019
//   			  	 
//1979	2001 	2012  		 	 2017
