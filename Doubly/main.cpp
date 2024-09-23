#include <iostream>
#include "D_Linked_List.h"
#include <limits> // for std::numeric_limits

using namespace std;

int main() {
    DoublyLinkedList* list = new DoublyLinkedList();
    int value;
    char choice;
    int pos;

    while (true) {
        cout  << endl;
        cout << "[a] add" <<"\t\t"<<"[1] Remove All"<< endl;
        cout << "[A] addAt" <<"\t"<<"[2] addSorted"<<  endl;
        cout << "[r] remove" << endl;
        cout << "[R] removeAt" << endl;
        cout << "[p] print" << endl;
        cout << "[x] exit" << endl;
        
        cout  << endl;
        cout << "Enter choice: ";
        
            cin >> choice; 

         // Process choices
            switch (choice) {
                case 'A':
                    cout << "Enter value to add and pos: ";
                    cin >> value;
                    cin >> pos;
                    // Validate input for value
                    
                    list->addAt(pos,value); // Assuming your add method is implemented
                    break;

                case 'a':
                    cin >> value;
                                                  
                    list->addTail(value); // Assuming your add method is implemented
                break;
                
                case 'r':
                    
                    cin >> value;

                    // Validate input for value
                    
                    cout << "Removed: " <<list->remove(value); // Assuming your remove method is implemented
                    break;

                case 'R':

                    cin >> pos;
                    cout <<"Removed: " <<list->removeAt(pos) << endl;

                    break;

                case '1':
                    cin>>value;
                    cout << "Number of removed instances: "<< list->removeAll(value) << endl;
                    break;

                case '2':
                    cin >> value;
                    list->addSorted(value);
                break;

                
                case 'p':
                    list->print(); // Assuming your print method is implemented
                    break;
                case 'x':
                    delete list; // Clean up
                    return 0; // Exit the program
            }
    }
            // Clear input state and ignore the rest of the line
            

    return 0;
}
