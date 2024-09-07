#include "DynamicArrayList.h"
#include <iostream> 
#include "struct.h"

int main(){
    DynamicArrayList* list2 = nullptr;
    DynamicArrayList* list = new DynamicArrayList();
    list2 = new DynamicArrayList();

    list->add(1);
    list->add(2);
    list->add(3);
    
    list->print();

    list2->add(1);
    list2->add(2);
    list2->add(3);

    list2->print();

    list->combine(list2);

    list->print();

    list->removeAt(0);
    list->removeAt(0);
    list->removeAt(0);
    list->removeAt(0);
    
    list->print();
    // list->removeRange(0,4);

    // list->print();
   
   

    
    return 0;
}

 // do {
    //     std::cout << "\nMenu:\n";
    //     std::cout << "1. Add an element\n";
    //     std::cout << "2. Print the list\n";
    //     std::cout << "3. Exit\n";
    //     std::cout << "Enter your choice: ";
    //     std::cin >> choice;

    //     switch (choice) {
    //         case 'a':
                
    //             std::cin >> value;
    //             list->add(value);
    //             break;

    //         case 'p':
    //             list->print();
    //             break;

    //         case 'x':
    //             std::cout << "Exiting the program.\n";
    //             break;

    //         case 'r': 
                
    //             cin >> value;
    //             list->remove(value);
    //             break;

    //         default:
    //             std::cout << "Invalid choice. Please try again.\n";
    //     }
    // } while (choice != 'x');