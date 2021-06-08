//heap.h: Include Heap class definition
//Github: sioni322, Email: sioni322@naver.com

#ifndef __HEAP__
#define __HEAP__

#define MIN 0
#define MAX 1

#include <iostream>
#include <algorithm>
#include <cmath>

using namespace std;

class Heap {
    private:
    int* array;         //The heap array

    int size;           //The number of elements of "array"
    int capacity;       //The capacity of "array"
    bool isMax;         //If isMax=1, max heap. Else, min heap.

    public:
    /* *************** Constructor and destructor functions ************** */
    /* "Heap" constructor function: Make a new heap */
    Heap(int s, bool maxmin=1);

    /* "~Heap" destructor function: Delete a heap */
    ~Heap();
    /* ******************************************************************* */


    /* ************************ Parameter functions ********************** */
    /* "length" function: Return the length of the heap array */
    int length();

    /* "depth" function: Return the depth of the heap */
    int depth();

    /* "maxmin" function: Return the status of max/min */
    bool maxmin();
    /* ******************************************************************* */


    /* ************************** Basic functions ************************ */
    /* "insert" function: Insert a new node into the heap */
    int insert(int v);

    /* "remove" function: Remove a root node from the heap */
    int remove();

    /* "number" function: Return the number of node which has a value "v" */
    int number(int v);

    /* "value" function: Return the value of nth node */
    int value(int n);

    /* "print" function: Print the heap nodes */
    void print();
    /* ******************************************************************* */
};

#endif