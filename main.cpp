#include "DynamicArrayList.h"
#include <iostream> 


int main(){

    List* list = new DynamicArrayList();

    list->add(13);
    list->add(11);
    list->add(8);
    int pos = list -> remove(11);
    cout << "position: "<< pos << " " << endl;
    list->print();



}