#include "DynamicArrayList.h"
#include <iostream> 


int main(){

    DynamicArrayList* list = new DynamicArrayList(5);

    list->add(1);
    list->add(2);
    list->add(3);
    
    list->print();

    // int* arro = list->toArray();

    // for(int i=0; i<3; i++){
    //     cout << arro[i] << " "; 
    // }
    list->reverse();
    list->print();

}