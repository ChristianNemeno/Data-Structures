#include <iostream>
#include "student.h"
#include <cmath>
class Course{
    student** students;
    int size;
    int capacity;

    public: 
    Course(){
        size=0;
        capacity = 5;

        students = (student**)malloc(capacity * sizeof(student*));

    }


    void addstudent(student* s){
        if(size == capacity){
            capacity = ceil(capacity * 1.5);

            students = (student**)realloc(students, capacity * sizeof(student*));

        }
        if(size != 0){
            for(int i=0; i<size;i++){
                if(students[i]->grade < s->grade ){
                    for(int j=size; j>i; j--){
                        students[j] = students[j-1];
                    }
                    students[i] = s;
                    size++;
                    return;        
                }
            }
        }

        cout << "Adding" << endl;
        students[size++] = s; 

    }
//aw
    void print() {
    cout << size << "/" << capacity << endl;

    for (int i = 0; i < size; i++) {
        if (students[i] != nullptr) { // Check if the pointer is valid
            cout << i + 1 << ". " << students[i]->name << " " << students[i]->grade << endl;
        } else {
            cout << i + 1 << ". Invalid student entry (null)" << endl;
        }
    }
}

    int removestudent(student* s){

        for(int i=0;i<size;i++){
            if(students[i]->name == s->name){
                

                for(int j=i; j<size-1;j++){
                    students[j] = students[j+1];
                }
                size--;
                if(size <= floor(capacity * (2.0/3.0))){
                    if(capacity > 5 ){
                        cout << "[Resizing , because of remove]" << endl;
                        capacity = capacity - floor(capacity * 0.25);
                        students = (student**)realloc(students, sizeof(student*) * capacity);
                        cout <<"Success!";
                    }
                }

                return i+1;
            }
        }
        return -1;
    }
};