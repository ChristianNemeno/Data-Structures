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
        cout << "[a] add" << endl;
        cout << "[r] remove" << endl;
        cout << "[p] print" << endl;
        cout << "[x] exit" << endl;
        cout  << endl;
        cout << "Enter choice: ";
        try {
            cin >> choice; 

         // Process choices
            switch (choice) {
                case 'A':
                    cout << "Enter value to add and pos: ";
                    cin >> value;
                    cin >> pos;
                    // Validate input for value
                    if (cin.fail()) {
                        throw runtime_error("Invalid input for value.");
                    }
                    list->addAt(pos,value); // Assuming your add method is implemented
                    break;

                case 'a':

                    cin >> value;
                    
                    // Validate input for value
                    if (cin.fail()) {
                        throw runtime_error("Invalid input for value.");
                    }
                    list->addTail(value); // Assuming your add method is implemented
                break;
                
                case 'r':
                    cout << "Enter value to remove: ";
                    cin >> value;

                    // Validate input for value
                    if (cin.fail()) {
                        throw runtime_error("Invalid input for value.");
                    }
                    list->remove(value); // Assuming your remove method is implemented
                    break;
                case 'p':
                    list->print(); // Assuming your print method is implemented
                    break;
                case 'x':
                    delete list; // Clean up
                    return 0; // Exit the program
            }

            // Clear input state and ignore the rest of the line
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');

        } catch (const exception& e) {
            cerr << e.what() << endl; // Output error message
            cin.clear(); // Clear error state
            cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Discard invalid input
        }
    }

    return 0;
}
