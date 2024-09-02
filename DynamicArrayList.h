#include "List.h"
#include <iostream>
#include <algorithm>
using namespace std;

class DynamicArrayList : public List {
private:
    int* array;
    int size;
    int capacity;

    void resize(){
        cout << "Resizing..." << endl;
        array=(int*)realloc(array, (capacity*1.5) * sizeof(int));

        if(array ==nullptr){
            cout << "FAIL";
            return;
        }
        capacity = capacity * 1.5;
    }

    void resizeSpecial(int n){
        cout << "Resizing..." << endl;

        array = (int*)realloc(array, n * sizeof(int));
        if(array ==nullptr){
            cout << "FAIL";
            return;
        }
        capacity = n;


    }
    


public:
    DynamicArrayList(int theCapacity) : size(0), capacity(theCapacity) {
        array = (int*)malloc(capacity * sizeof(int));
    }

//add 20 jump rope
    int getCapacity(){
        return capacity;
    }

    void add(int n){
        if(size == capacity){
            resize();
        }
        array[size++] = n;
     }
     // start here new implementations
     bool isEmpty(){
        return size == 0;
     }
     void rotate(int k){
        
        for(int i=0; i<k; i++){

            int temp = array[size-1];
            for(int i=size-1; i>=0;i--){
                array[i] = array[i-1];
            }
            array[0] = temp;
        }
        
     }

     //previous implementations

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

    void insertAt(int index, int value){
        if(size == capacity){
            resize();
        }
        if(index > size || index < 0){
            return;
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
        int newSize = size + size1;
        
        resizeSpecial(newSize);

        //int j=0;
        for(int i=size; i<newSize; i++){
            array[i] = anotherList->getElement(i-size);
            
        }
        size = newSize;
     }



    int removeAt(int index){
        if(size <=0){
            return 0;
        }
        
        int temp = array[index];
        for(int i = index; i<size-1 ;i++){
            array[i] = array[i+1];
        }
        size--;
        return temp;
    }

    void clear(){
        delete[] array;
        array = new int[capacity];
        size = 0;
    }

    int removeAll(int n){
        int count =0;
        for(int i=0 ; i<size; i++){
            if(array[i] == n){
                for(int j=i; j<size-1;j++){
                    array[j] = array[j+1];
                }
                i--;
                size--;
                count++;
            }
        }    
        return count;
    }
    
    DynamicArrayList* subList(int startIndex, int endIndex){

        DynamicArrayList* sub = new DynamicArrayList(capacity);
        int j=0;
        
        for(int i=startIndex; i<endIndex; i++){
            sub->array[j] = array[i];
            j++;
        }
        sub->size= j;

        return sub;
        

    }
    
     
};
