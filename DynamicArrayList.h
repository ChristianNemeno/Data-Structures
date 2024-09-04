#include "List.h"
#include <iostream>
#include <algorithm>
#include <cmath>
using namespace std;

class DynamicArrayList : public List {
private:
    int* array;
    int size;
    int capacity = 5;

    
    


public:
    DynamicArrayList() : size(0) {
        array = (int*)malloc(capacity * sizeof(int));
    }

// implement
// get
// is Empty
// add 
// addAt
// remove
// removeAt
// combine
// removeAll
// removeRange
// condition was if the size was full increase it to 50 % 
// if the size was equals to capacity 2/3 reduce size to 25%
// all of the functions must be dynamically checked!
int get(int i){
    return array[i];
}

void addAt(int pos, int value){
    if(size == capacity){
        cout << "Resizing.. " << endl;
        capacity =ceil(capacity * 1.5);
        array = (int*)realloc(array,sizeof(int) * capacity);
    }
    for(int i=size; i>pos; i--){
        array[i+1] = array[i];
    }
    array[pos-1] = value;

}

void add(int n){
    if(size == capacity){
        cout << "Resizing.. " << endl;
        capacity = ceil(capacity * 1.5);
        array = (int*)realloc(array,sizeof(int) * capacity);
    }   
    array[size++] = n;
}

 

int remove(int n){
    
    for(int i=0;i<size;i++){
        if(array[i] == n){
            for(int j=i; j<size-1;j++){
                array[j] = array[j+1];
            }
            size--;
            if(size <= capacity * (2.0/3.0)){
                if(size > 5){
                    cout << "Resizing.. " << endl;
                    capacity = capacity - floor(capacity * 0.25);
                    array = (int*)realloc(array,sizeof(int) * capacity);
                }
            }
            return i+1;
        }

    }

    
    return -1;
}

int removeAt(int pos){
    
    int temp = array[pos-1];

    for(int i=pos-1; i<size-1; i++){
        array[i] = array[i+1];
    }
    size--;
        if(size <= capacity * (2.0/3.0)){
            if(size > 5){
                capacity = capacity - floor(capacity * 0.25);
                array = (int*)realloc(array,capacity * sizeof(int));
            }
    }    

    return temp;
}

void combine(DynamicArrayList* list2){
    while(!list2->isEmpty()){
        int te = list2->removeAt(1);
        add(te);
    }
}



bool isEmpty(){
    return size == 0;
}


void print(){
    cout << size << "/"<< capacity << endl;
    for(int i=0; i<size;i++){
        cout << array[i] << " ";
    }
    cout << endl;

}


};
