#include "List.h"
#include <iostream>
using namespace std;
class DynamicArrayList : public List
{
private:
    int array[5];
    int size=0;
    

    /* data */
public:
    void add(int n){
        if(size == 4){
            cout << "Its full na";
            return;
        }
        array[size++] = n;
        
    }
    int remove(int n){
        if(size == 0){
            return -1;
        }

        for(int i=0; i<size; i++){
            if(array[i] == n){
                for(int j=i; j<size-1;j++){
                    array[i] = array[i+1];
                }
                size--;
                return i+1;
            }
        }
        return -1;
    }

    void print(){
        for(int i=0 ; i<size; i++){
            cout << array[i] << " ";
        }
    }

};



