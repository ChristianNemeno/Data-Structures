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
    // list->reverse();
    // list->print();

    DynamicArrayList* tempList = new DynamicArrayList(3);

    tempList->add(4);
    tempList->add(5);
    tempList->add(6);

    list->merge(tempList);

    list->print();


}