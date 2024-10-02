#include <iostream>
#include "node.h"
#include "List.h"
using namespace std;

class DoublyLinkedList{

    int size;
    node* head;
    node* tail;
    node* senior;
    public:

    DoublyLinkedList(){
        size = 0;
        head = new node; 
        tail = new node;
        head->next = tail;
        tail->prev = head;
        senior = head;
    }
    //utility
    int getSize(){
        return size;
    }
    //add last
    node* addBetween(Person* p, node* pred, node* succ){
         
        
        node* n = new node;
        n->person = p;
        n->prev = pred;
        n->next = succ;

        pred->next = n;
        succ->prev = n;
        size++;

        return n;
    }


    void add(Person* p){
        if(p-> age >= 60){
            senior = addBetween(p, senior, senior->next);
        }else{
            addBetween(p , tail->prev, tail);
        }

    }

    Person* serveRequest(char ch){

        int index;
        switch (ch){
            case 'B' : 
            index = 0;
            break;

            case 'M' : 
            index = 1;
            break;

            case 'C':
            index = 2;
            break;

            case 'D':
            index = 3;
            break;
        }

        node* curr = head->next;

        Person* reference = NULL;

        while(curr != tail){
            
            if(curr->person->requests[index] == 1){
                curr->person->requests[index] = 0;
                reference = curr->person;

                // if no more request
                if( reference->requests[0] == 0 &&
                    reference->requests[1] == 0 &&
                    reference->requests[2] == 0 &&
                    reference->requests[3] == 0 ){

                        removeBetween(curr);

                    }
                
                break;
            }
            curr = curr->next;

        }

        return reference;
        
    }


    Person* fastLane(){

        Person* reference = nullptr;
        node* curr = head->next;

        while(curr != tail){

            if(curr->person->req_count() == 1){
                reference = curr->person;

                removeBetween(curr);
                break;
            }

            curr = curr->next;
        }
        return reference;
    }

    void removeBetween(node* n){
        // initialize the pred and succ
        if(size == 0){
            cout << "Empty";
            return;
        }
        node* pred = n->prev;
        node* succ = n->next;

        // link the pred and succ

        pred->next = succ;
        succ->prev = pred;

        free(n);
        size--;

    }



    void print(){
        node* curr = head->next;
        cout << "COUNTER : " << size << endl;
        if(size ==0 ){
            return;
        }

        cout << "FROM FIRST: " << endl;
        int ctr = 1; 
        while(curr != tail){
            cout << ctr++ << ". ";
            curr->person->print();

            curr = curr->next;

        }

        cout << "FROM LAST: " << endl;
        curr = curr->prev;
        while(curr != head){
            cout << --ctr << ". ";
            curr->person->print();
            curr = curr->prev;
        }



    }


};


