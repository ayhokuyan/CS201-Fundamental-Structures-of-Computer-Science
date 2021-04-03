#include "Student.h"

Student::Student(const int std_id, const string std_name){
    id = std_id;
    name = std_name;
}

Student::Student(){
    id = -1;
    name = "";
}

Student::Student(Student& aStu){
    id = aStu.id;
    name = aStu.name;
    stdBooks = aStu.stdBooks;
}

Student::~Student(){
}

Student& Student::operator=( const Student& right ){
    if(right.id>0){
        id = right.id;
        name = right.name;
        stdBooks = right.stdBooks;
    }else{
        id = -1;
        name = "";
    }
}

int Student::getId(){
    return id;
}

string Student::getName(){
    return name;
}

BookList* Student::getStdBooks(){
    return &stdBooks;
}
