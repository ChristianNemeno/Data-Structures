#include <iostream>
#include "course.h"

using namespace std;
/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char** argv) {
	cout << sizeof(Course);
	Course* csit = new Course();
	student* s;
	char op;
	while (true) {
		cout << "Op: ";
		cin  >> op;
		switch (op) {
			case 'a':
				s = new student;
				cout << "Name: ";
				cin >> s->name;
                cout << "Grade: ";
                cin >> s->grade; 
				csit->addstudent(s);
				break;
			case 'p':
				csit->print();
				break;

			case 'r':
				s= new student;
				cout << "[Enter student name to remove]: ";
				cin >> s->name;
				cout << endl; 
				cout << csit->removestudent(s);
				break;

            case 'x':
            return 0;
            break;
		}
	}
	return 0;
}