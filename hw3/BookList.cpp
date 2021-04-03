#include "BookList.h"
#include <iomanip>

BookList::BookList(){
    size = 0;
    head = NULL;
}

BookList::~BookList(){
    for(int i=0; i<size; i++){
        Node* cur = head;
        Node* temp = cur->next;
        cur->next = NULL;
        delete cur;
        head = temp;
    }
}

BookList::BookList(const BookList& aList){
    size = aList.size;
    if(aList.head == NULL)
    {
        head = NULL;
    }else{
        Node* head = new Node;
        Node* cur = aList.head;
        for(int i=0; i<size; i++){
            insertBk(cur->item);
            cur = cur->next;
        }
    }
}


bool BookList::isEmpty(){
    return size == 0;
}

int BookList::getSize(){
    return size;
}

BookList::Node* BookList::findBk(int bk_id){
    Node* cur = head;
    for(int i=0; i<size; i++){
        if(bk_id == (cur->item).getId()){
            return cur;
        }
        cur = cur->next;
    }
    return NULL;   
}

int BookList::getHeadId(){
    return (head->item).getId();
}

bool BookList::retrBk(const int bk_id, Book*& bk){
    Node* fnd = findBk(bk_id);
    if(fnd != NULL){
        bk = &(fnd->item);
        return true;
    }
    return false;
}

bool BookList::insertBk(Book& newBk){
    //negative id case
    if(newBk.getId() <= 0){
        return false;
    }
    //already exist case
    if(findBk(newBk.getId()) != NULL){
        return false;
    }
    if(isEmpty()){
        head = new Node;
        head->item = newBk;
        head->next = head;
        size++;
        return true;
    }
    
    Node* cur = head;
    for(int i=0; i<size-1; i++){
        cur = cur->next;
    }
    Node* newPtr = new Node;
    cur->next = newPtr;
    newPtr->item = newBk;
    newPtr->next = head;
    size++;
    return true;
}

bool BookList::removeBk(int bk_id){
    Node* fnd = findBk(bk_id);
    if(fnd == NULL){
        return false;
    }
    Node* cur = head;
    for(int i=0; i<size; i++){
        if((cur->next->item).getId() == bk_id){
            Node* temp = cur->next;
            if(temp == head){
                head = head->next;
            }
            cur->next = temp->next;
            temp->next = NULL;
            delete temp; 
            size--;
            return true;
        } 
        cur = cur->next;   
    }
    return false;
}

void BookList::print(string status){
    Node* cur = head;
    for(int i=0; i<size;i++){
        cout << left << setw(10) << (cur->item).getId() << setw(23) << (cur->item).getName() << setw(10) << (cur->item).getYear() << setw(50) << status << endl;
        cur = cur->next;
    }
}


BookList& BookList::operator=(const BookList& right ){
    if(this != &right){
        //set size
        size = right.size;
        if(size > 0){
            head = right.head;
            Node* cur = right.head;
            for(int i=0;i<size;i++){
                insertBk(cur->item);
                cur = cur->next;
            }

        }else
        {
            head = NULL;
        }
    }
    return *this;
}

