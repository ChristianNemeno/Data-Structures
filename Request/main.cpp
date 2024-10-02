#include <iostream>
#include <string>
#include "node.h"
#include "D_Linked_List.h"
using namespace std;

void showMenu() {
    cout << "\n===== Doubly Linked List System =====" << endl;
    cout << "1. Add Person" << endl;
    cout << "2. Serve Request" << endl;
    cout << "3. Fast Lane Service" << endl;
    cout << "4. Print List" << endl;
    cout << "5. Exit" << endl;
    cout << "=====================================" << endl;
    
}

int main() {
    DoublyLinkedList* list = new DoublyLinkedList();
    int choice;
    showMenu(); 
    do {
        cout << "Choose an option: ";
        cin >> choice;

        if (choice == 1) {
            // Add Person
            string firstName, lastName;
            int age;
            char requestChar;
            int requests[4] = {0}; // Initialize all requests to 0
            cout << "\nEnter first name: ";
            cin >> firstName;
            cout << "Enter last name: ";
            cin >> lastName;
            cout << "Enter age: ";
            cin >> age;

            cout << "Enter requests (B, M, C, D). Enter '0' when done: ";
            while (true) {
                cin >> requestChar;
                if (requestChar == '0') {
                    break;
                }
                switch (requestChar) {
                    case 'B':
                        requests[0] = 1;
                        break;
                    case 'M':
                        requests[1] = 1;
                        break;
                    case 'C':
                        requests[2] = 1;
                        break;
                    case 'D':
                        requests[3] = 1;
                        break;
                    default:
                        cout << "Invalid request type. Enter 'B', 'M', 'C', 'D' or '0' to finish: ";
                        break;
                }
            }

            // Add the new person with multiple requests
            Person* newPerson = new Person{firstName, lastName, age, {requests[0], requests[1], requests[2], requests[3]}};
            list->add(newPerson);
            cout << "\nPerson added!\n";
            }
            else if (choice == 2) {
                        // Serve Request
                        char requestChar;
                        cout << "\nEnter request type to serve (B, M, C, D): ";
                        cin >> requestChar;
                        Person* served = list->serveRequest(requestChar);
                        if (served) {
                            cout << "Served: " << served->firstName << " " << served->lastName << endl;
                        } else {
                            cout << "No person with this request found.\n";
                        }

                    } else if (choice == 3) {
                        // Fast Lane Service
                        Person* fastServed = list->fastLane();
                        if (fastServed) {
                            cout << "Fast Lane Served: " << fastServed->firstName << " " << fastServed->lastName << endl;
                        } else {
                            cout << "No person in the fast lane (with exactly 1 request).\n";
                        }

                    } else if (choice == 4) {
                        // Print List
                        list->print();
                    }

                } while (choice != 5);

                cout << "Exiting... Goodbye!" << endl;
    return 0;
}
