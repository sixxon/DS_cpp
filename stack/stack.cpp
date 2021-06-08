//stack.cpp: Include definition of Stack's member functions
//Github: sioni322, Email: sioni322@naver.com

#include <iostream>
#include "stack.h"

using namespace std;

//"Stack" constructor function: Dynamically allocate the array with "s"
Stack::Stack(int s) {
    array = new int[s] ();
    top = 0;
    size = s;
}

//"~Stack" destructor function: Delete the memory of Stack
Stack::~Stack() {
    cout << "Delete stack class completely!\n";

    delete array;
}

//"status" function: Return the status of stack array(empty:-1, enough space:0, full:1)
int Stack::status() {
    //Stack is empty
    if(top == 0) {
        return -1;
    }
    //Stack is full
    else if(top == size) {
        return 1; 
    }
    else {
        return 0;
    }
}

//"push" function: Insert the value into the stack array and return the status(0: complete, -1: failed)
int Stack::push(int value) {
    if(status() == 1) {
        cout << "Cannot insert value into the stack!\n\n";
        return -1;
    }
    else {
        array[top] = value;
        top++;
        
        return 0;
    }
}

//"pop" function: Delete a value in stack array and return the value/status
int Stack::pop() {
    if(status() == -1) {
        cout << "Cannot delete value in stack!\n\n";
        return -1;
    }
    else {
        int temp = array[top - 1];

        array[top - 1] = 0;
        top--;

        return temp;
    }
}

//"print" function: Print current status of stack
void Stack::print() {
    for(int i=0; i<size; i++) {
        if(array[i] == 0) {
            cout << "empty\t";
        }
        else {
            cout << array[i] << "\t";
        }
    }
    cout << "\ntop: " << top << "\n\n";
}