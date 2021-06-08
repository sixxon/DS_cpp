//queue.cpp: Include definition of Queue's member functions
//Github: sioni322, Email: sioni322@naver.com

#include <iostream>
#include "queue.h"

using namespace std;

//"Queue" constructor function: Dynamically allocate the array with "s"
Queue::Queue(int s) {
    array = new int[s] ();

    front = 0;
    rear = 0;
    size = s;
    lastOp = 0;
}


//"~Queue" destructor function: Delete Queue class
Queue::~Queue() {
    cout << "Delete queue class completely!\n";
    delete array;
}


//"status" function: Return the status of queue array(empty:-1, enough space:0, full:1)
int Queue::status() {
    if(front == rear) {
        if(lastOp == 0)
            return -1; //Queue is Empty
        else
            return 1; //Queue is Full
    }
    else
        return 0;
}


//"enqueue" function: Insert "value" into the queue array and return the status(0: complete, 1: failed)
int Queue:: enqueue(int value) {
    if(status() == 1) {
        cout << "Cannot insert value into the queue!\n\n";
        return -1;
    }
    else {
        array[rear] = value;
        rear = (rear + 1) % size;
        lastOp = 1;

        return 0;
    }
}


//"dequeue" function: Delete a value in queue array and return the value/status
int Queue::dequeue() {
    if(status() == -1) {
        cout << "Cannot delete value in queue!\n\n";
        return -1;
    }
    else {
        int temp = array[front];

        array[front] = 0;
        front = (front + 1) % size;
        lastOp = 0;

        return temp;
    }
}


//"print" function: Print current status of this queue
void Queue::print() {
    for(int i=0; i<this->size; i++) {
        if(array[i] == 0) {
            cout << "empty\t";
        }
        else {
            cout << array[i] << "\t";
        }
    }
    cout << "\nfront: " << front << ", rear: " << rear << "\n\n";
}