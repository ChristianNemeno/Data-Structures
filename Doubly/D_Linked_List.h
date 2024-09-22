#include <iostream>
#include "node.h"
#include "List.h"
using namespace std;

class DoublyLinkedList : public List{

    int size;
    node* head;
    node* tail;

    public:

    DoublyLinkedList(){
        size = 0;
        head = nullptr;
        tail = nullptr;
    }

    void addHead(int num){
       if(head == nullptr){
        //means empty?
        node* n = (node*)calloc(1,sizeof(node));
        n->data = num;
        n->prev = nullptr;
        n->next = nullptr;

        head = n;
        size++;

        if(tail == nullptr){
            tail = head;
        }

        return;
       }

        // head is not null there exist more nodes

        node* n = (node*)calloc(1,sizeof(node));
        n->data = num;
        n->prev = nullptr;
        n->next = head;

        head->prev = n;

        head = n;
        size++;
    }

    void addTail(int num){
        
        if(tail == nullptr && head == nullptr){
            addHead(num);

            return;
        }
        //naay tail

        node* n = (node*)calloc(1,sizeof(node));

        n->prev = tail;
        n->data = num;
        n->next = nullptr;

        tail->next = n;

        tail = n;
        size++;

        

    }

    void add(int num){
        addTail(num);
    }

    void addAt(int pos, int value){
        //empty
        if(!head){
            if(pos == 1){
                return addHead(value);
            }
        }
        if(pos == 1){
            return addHead(value);
        }
        node* curr = head;
        int i = 1;
        
        for(;i<pos;i++){
            curr = curr->next;
        }
        node* n = (node*)calloc(1,sizeof(node));
        
        //initialize the new node
        n->data = value;
        n->next = curr;
        n->prev = curr->prev;

        //link the previous(prev of curr) node's next  to the new node
        node* temp = curr->prev;

        temp->next = n;
        //link the current node to the new node
        curr->prev = n;

        

        size++;



    }

    int removeHead(){

        if(!head){
            cout << "Empty";
            return 0;
        }

        node* temp = head;
        int ret = temp -> data; 
        head = head->next;
        head->prev = nullptr;
        free(temp);
        size--;

        if(size == 0){
            tail = nullptr;
        }

        return ret;

    }

    int remove(int n){
        //single node;
        //handle head node , we cant really do a last node basin first occurence i remove
        // if(head->data == n){
        //     int wow = removeHead();
        //     return 1;
        // }
        
        // node* curr = head;

        // while(curr->data != n){
        //     curr = curr->next;
        // }
        int kk = removeHead();


        return -1;
    }
    void print(){
        if(size == 0){
            cout << "Empty" << endl;
            return;
        }
        node* curr = head;
        while(curr){
            cout << curr->data << "->";
            
            curr = curr->next;
            
        }
        if(!curr){
            cout << "NULL";
        }

        cout <<endl;   
        return;
    }

    void print(node* param){
        node* curr = param;
        if(curr == head){
            print();
        }else if(param == tail){
            while(curr){
                curr = curr->prev;
            }
        }else{
            cout << "invalid node" << endl;
            return;
        }
        
        return;
    }
    int get(int pos){
        int i = 1;

        node* curr = head;
        while(i < pos){
            curr = curr->next;
            i++;
        }

        return curr->data;
    }




};


