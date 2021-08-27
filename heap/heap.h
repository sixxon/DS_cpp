//heap.h, Sion Lee
/* *****************************************************************************
This header file includes the heap data structure using a normal array.
***************************************************************************** */

#ifndef DSCPP_HEAP_H
#define DSCPP_HEAP_H
#define ARRAY_LENGTH_MAX 1000

//Heap class functions like heap data structure
class Heap {
    private:
    int* array;     //Heap array pointer

    int length;     //The number of elements in the array
    int capacity;   //The size of the array

    bool ismax;     //If true, max heap. Else, min heap.

    public:
    Heap(int s, bool m=true);
    Heap(const Heap &h);
    ~Heap();

    int top();

    bool isempty();
    int size();
    void print();

    void heapify_up(int index);
    void heapify_down(int index);
    void push(int value);
    int pop();
};

//Functor
struct greater {
    bool operator()(int a, int b) {
        return a > b;
    }
};

struct less {
    bool operator()(int a, int b) {
        return a < b;
    }
};

#endif