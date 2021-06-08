//stack.h: Include Stack class definition
//Github: sioni322, Email: sioni322@naver.com

#ifndef __STACK__
#define __STACK__

class Stack {
    private:
    int *array;     //Stack array

    int top;        //Top index of the array
    int size;       //Total size of the array

    public:
    //"Stack" constructor function: Dynamically allocate the array with "s"
    /* Parameter type: int, Return type: X */
    Stack(int s);

    //"~Stack" destructor function: Delete the memory of Stack
    /* Parameter type: void, Return type: X */
    ~Stack();

    //"status" function: Return the status of stack array(empty:-1, enough space:0, full:1)
    /* Parameter type: void, Return type: int */
    int status();

    //"push" function: Insert the value into the stack array and return the status(0: complete, -1: failed)
    /* Parameter type: int, Return type: int */
    int push(int value);

    //"pop" function: Delete a value in stack array and return the value/status
    /* Parameter type: void, Return type: int */
    int pop();

    //"print" function: Print current status of this stack
    /* Parameter type: void, Return type: void */
    void print();
};

#endif