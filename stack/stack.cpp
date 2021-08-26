//stack.cpp, Sion Lee
/* *****************************************************************************
This source code includes definitions of Stack class's member functions.
***************************************************************************** */

#include <iostream>
#include "stack.h"
using namespace std;

//"Stack" constructor function: Dynamically allocate the array with "s"
Stack::Stack(int s) {
    if(s <= ARRAY_LENGTH_MAX && s > 0) {
        array = new int[s] ();
        capacity = s;
    }
    else {
        array = 0;
        capacity = 0;
    }
    length = 0;
}

//"Stack" function: Copy instructor which functions a deep copy
Stack::Stack(const Stack &s) {
    if(array)
        delete[] array;

    array = new int[s.capacity];
    capacity = s.capacity;
    length = s.length;

    for(int i=0; i<length; i++) {
        array[i] = s.array[i];
    }
}

//"~Stack" destructor function: Delete Stack class
Stack::~Stack() {
    delete array;
}

//"front" function: Return the first element in Stack
int Stack::front() {
    if(length > 0) return array[0];
    else return 0;
}

//"back" function: Return the last elemenet in Stack
int Stack::back() {
    return array[length-1];
}

//"begin" function: Return the first element's address in Stack
int* Stack::begin() {
    return array;
}

//"end" function: Return the last element's address in Stack
int* Stack::end() {
    return array+length;
}

//"isempty" function: If the Stack is empty, return true. Else, return false.
bool Stack::isempty() {
    return (length == 0);
}

//"size" function: Return the length of the Stack
int Stack::size() {
    return length;
}

//"print" function: Print current status of this Stack
void Stack::print() {
    for(int i=0; i<length; i++) {
        cout << array[i] << "\t";
    }
    cout << "\nlength: " << length << ", capacity:" << capacity << "\n\n";
}

//"push_back" function: Insert the value into the Stack
void Stack::push_back(int value) {
    if(length == capacity) {
        int *temp = new int[(length+1)*2] ();
        
        for(int i=0; i<length; i++) {
            temp[i] = array[i];
        }
        temp[length] = value;

        if(array)
            delete[] array;
        
        array = temp;
        length++;
        capacity = length*2;
    }
    else {
        array[length++] = value;
    }
}

//"pop_back" function: Delete the value from the Stack
int Stack::pop_back() {
    if(!length) {
        return 0;
    }

    else {
        int temp = array[length-1];

        array[length-1] = 0;
        length--;

        return temp;
    }
}