//queue.h, Sion Lee
/* *****************************************************************************
This header file includes the queue data structure using a normal array.
***************************************************************************** */

#ifndef DSCPP_QUEUE_H
#define DSCPP_QUEUE_H
#define ARRAY_LENGTH_MAX 1000

//Queue class functions like queue data structure(enqueue, dequeue, etc)
class Queue {
    private:
    int *array;     //Array pointer

    int first;      //First element's index
    int last;       //Last element's index

    int length;     //The number of elements in the array
    int capacity;   //The size of the array

    public:
    Queue(int s);
    Queue(const Queue &q);
    ~Queue();

    int front();
    int back();
    int* begin();
    int* end();

    bool isempty();
    int size();
    void print();

    void push(int value);
    int pop();
};

#endif