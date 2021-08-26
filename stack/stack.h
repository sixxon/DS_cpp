//stack.h, Sion Lee
/* *****************************************************************************
This header file includes the stack data structure using a normal array.
***************************************************************************** */

#ifndef DSCPP_STACK_H
#define DSCPP_STACK_H
#define ARRAY_LENGTH_MAX 1000

//Stack class functions like stack data structure(push_back, pop_back, etc)
class Stack {
    private:
    int *array;     //Stack array

    int length;     //The number of elements in the array(equals top)
    int capacity;   //The size of the array

    public:
    Stack(int s);
    Stack(const Stack &s);
    ~Stack();

    int front();
    int back();
    int* begin();
    int* end();

    bool isempty();
    int size();
    void print();

    void push_back(int value);
    int pop_back();

    int operator[](const int &i) {
        return array[i];
    }
};

#endif