#include "List.h"
#include <iostream>
using namespace std;

class DynamicArrayList : public List {
private:
    int* array;
    int size;
    int capacity;

    void resize(int newCapacity){
        cout << "Resizing..." << endl;
        int* newArray = new int[newCapacity];
        for(int i=0; i<size; i++){
            newArray[i] = array[i];
        }
        delete[] array;
        array = newArray;
        capacity = newCapacity;
    }


public:
    DynamicArrayList(int theCapacity) : size(0), capacity(theCapacity) {
        array = new int[capacity];
    }

//add 20 jump rope
     void add(int n){
        if(size == capacity){
            resize(capacity * 2);
        }
        array[size++] = n;
     }
     int remove(int n){
        for(int i=0;i<size-1;i++){
            if(array[i] == n){
                for(int j=i; j<size-1; j++){
                    array[i] = array[i+1];
                }
                size--;
                return i+1;
            }
        }
        return -1;
     }
     void print(){
        for(int i=0; i<size;i++){
            cout << array[i] << " ";
        }
        cout << endl;
     }
     void insert(int index, int value){
        if(size == capacity){
            resize(capacity * 2);
        }
        for(int i=size-1; i>=index;i--){
            array[i] = array[i-1];
        }
        array[index] = value;

     }

     int getSize(){
        return size;
     }


     int* toArray(){
        int* toArr = new int[size];

        for(int i=0; i<size; i++){
            toArr[i] = array[i];
        } 

        return toArr;

     }

     void reverse(){
        int* temp = new int[size];
        int j=0;
        for(int i=size-1; i>=0; i--){
            temp[j++] = array[i];
        }
        for(int i=0;i<size;i++){
            array[i] = temp[i];
        }
        delete[] temp;
     }

    int getElement(int index){
        return array[index];
    }

     void merge(DynamicArrayList* anotherList){
        if(anotherList == nullptr){
            return;
        }
                
        int size1 = anotherList->getSize();
        int newSize = size1 + size;
        
        resize(newSize);
        int j=0;
        for(int i=size; i<newSize && j < anotherList-> getSize(); i++){
            array[i] = anotherList->getElement(j);
            j++;
        }
        size = newSize;
     }
};
