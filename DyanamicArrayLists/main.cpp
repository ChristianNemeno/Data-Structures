#include "DynamicArrayList.h"
#include <iostream> 
#include "struct.h"

int main(){
    
    
    
    List* list = new DynamicArrayList();
    
    char choice;
    int value;
    
    do {
        std::cout << "\nMenu:\n";
        std::cout << "1. Add an element (a)\n";
        std::cout << "2. Print the list (p)\n";
        std::cout << "3. Remove and Element (r)\n";
        std::cout << "4. Exit\n";
        std::cout << "Enter your choice: ";
        std::cin >> choice;

        switch (choice) {
            case 'a':
                
                std::cin >> value;
                list->add(value);
                break;

            case 'p':
                list->print();
                break;

            case 'x':
                std::cout << "Exiting the program.\n";
                break;

            case 'r': 
                
                cin >> value;
                list->remove(value);
                break;

            default:
                std::cout << "Invalid choice. Please try again.\n";
        }
    } while (choice != 'x');

    

   

    
   
   

    
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