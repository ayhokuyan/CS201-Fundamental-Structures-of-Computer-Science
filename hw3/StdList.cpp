#include "StdList.h"
#include <sstream>

StdList::StdList(){
    size = 0;
    head = NULL;
}

StdList::StdList(const StdList& aList): size(aList.size){
    if(size>0){
        Node* head = new Node;
        Node* cur = aList.head;
        for(int i=0; i<size; i++){
            insertStu(cur->item);
        }
    }else
    {
        head = NULL;
    }
}

StdList::~StdList(){
    for(int i=0; i<size; i++){
        Node* cur = head;
        Node* temp = cur->next;
        cur->next = NULL;
        delete cur;
        head = temp;
    }
}

bool StdList::isEmpty(){
    return size == 0;

}

int StdList::getSize(){
    return size;
}

StdList::Node* StdList::findStu(int std_id){
    Node* cur = head;
    for(int i=0; i<size; i++ ){
        if((cur->item).getId() == std_id){
            return cur;
        }
        cur = cur->next;
    }
    return NULL;
}

bool StdList::retrStu(const int std_id, Student*& stu){
    Node* fnd = findStu(std_id);
    if(fnd != NULL){
        stu = &(fnd->item);
        return true;
    }
    return false;
}

bool StdList::insertStu(Student newStu){
    if(newStu.getId() <= 0){
        return false;
    }
    Node* fnd = findStu(newStu.getId());
    if(fnd != NULL){
        cout << "Student " << newStu.getId() << " already exists\n";
        return false;
    }

    if(head == NULL){
        head = new Node;
        head->item = newStu;
        head->next = head;
        head->prev = head;
        size++;
        cout << "Student " << newStu.getId() << " has been added\n";
        return true;
    }

    Node* tail = head->prev;
    Node* newPtr = new Node;
    newPtr->item = newStu;
    tail->next = newPtr;
    head->prev = newPtr;
    newPtr->next = head;
    newPtr->prev = tail;
    cout << "Student " << newStu.getId() << " has been added\n";
    size++;
    return true;
}

bool StdList::removeStu(int stu_id){
    Node* fnd = findStu(stu_id);

    if(fnd == NULL){
        cout << "Student " << stu_id << " does not exist\n";
        return false;
    }

    Node* pre = fnd->prev;
    Node* nex = fnd->next;

    if(fnd == head){
        head = head->next;
    }
    fnd->next = NULL;
    fnd->prev =  NULL;

    delete fnd;

    nex->prev = pre;
    pre->next = nex;
    cout << "Student " << stu_id << " has been deleted\n";
    size--;
    return true;
}


void StdList::print(){
    Node* cur = head;
    for(int i=0; i<size; i++){
        BookList* tempLst = ((cur->item).getStdBooks());
        stringstream stream;
        stream << (cur->item).getId();
        string s = "Checked out by student " + stream.str();
        (*tempLst).print(s);
        cur = cur->next;
    }
}


bool StdList::addBk(int std_id, Book& bk){
    Student* st=NULL;
    retrStu(std_id,st);
   (*((*st).getStdBooks())).insertBk(bk);
}

bool StdList::searchBk(int bk_id, Book*& bk, BookList*& delList){
    Node* cur = head;
    for(int i=0;i<size;i++){
        if((*((cur->item).getStdBooks())).retrBk(bk_id,bk)){
            delList = (cur->item).getStdBooks();
            return true;
        }
        cur = cur->next;
    }
    return false;
}

bool StdList::searchBkID(int bk_id, Book*& bk, int& stu_id){
    Node* cur = head;
    for(int i=0;i<size;i++){
        if((*((cur->item).getStdBooks())).retrBk(bk_id,bk)){
            stu_id = (cur->item).getId();
            return true;
        }
        cur = cur->next;
    }
    return false;
}