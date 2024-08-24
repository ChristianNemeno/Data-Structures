#include "DynamicArrayList.h"
#include <iostream> 


int main(){

    List* list = new DynamicArrayList(5);

    list->add(1);
    list->add(2);
    list->add(3);
    int pos = list -> remove(2);
    cout << "position: "<< pos << " " << endl;
    list->print();

    list->add(4);
    list->print();
    
    list->add(5);
    list->print();
    
    list->add(6);
    list->print();
    
    list->add(7);
    list->print();

    list->add(8);
    list->print();
    
    list->add(9);
    list->print();



}