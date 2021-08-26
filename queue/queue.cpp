//queue.cpp, Sion Lee
/* *****************************************************************************
This source code includes definitions of Queue class's member functions.
***************************************************************************** */

#include <iostream>
#include "queue.h"
using namespace std;

//"Queue" constructor function: Dynamically allocate the array with "s"
Queue::Queue(int s) {
    if(s <= ARRAY_LENGTH_MAX && s > 0) {
        array = new int[s] ();
        capacity = s;
    }
    else {
        array = 0;
        capacity = 0;
    }
    length = 0;
    first = 0;
    last = 0;
}

//"Queue" function: Copy constructor which functions a deep copy
Queue::Queue(const Queue &q) {
    if(array)
        delete[] array;

    array = new int[q.capacity];
    capacity = q.capacity;
    length = q.length;
    first = q.first;
    last = q.last;

    if(!isempty()) {
        int i = first;
        while(1) {
            array[i] = q.array[i];
            i = (i+1) % capacity;

            if(i == last)
                break;
        }
    }
}

//"~Queue" destructor function: Delete Queue class
Queue::~Queue() {
    delete array;
}

//"front" function: Return the first element in Queue
int Queue::front() {
    return array[first];
}

//"back" function: Return the last elemenet in Queue
int Queue::back() {
    return array[(last == 0 ? capacity-1 : last-1)];
}

//"begin" function: Return the first element's address in Queue
int* Queue::begin() {
    return array+first;
}

//"end" function: Return the last element's address in Queue
int* Queue::end() {
    return array+last;
}

//"isempty" function: If the Queue is empty, return true. Else, return false.
bool Queue::isempty() {
    return (length == 0 ? true : false);
}

//"size" function: Return the length of the Queue
int Queue::size() {
    return length;
}

//"print" function: Print current status of this Queue
void Queue::print() {
    if(!isempty()) {
        int i = first;

        while(1) {
            cout << array[i] << "\t";
            i = (i+1) % capacity;

            if(i == last)
                break;
        }
    }
    cout << "\nfirst: " << first << ", last: " << last << "\n";
    cout << "size: " << length << ", capacity: " << capacity << "\n\n";
}

//"push" function: Push the value into the Queue
void Queue::push(int value) {
    if(length == capacity) {
        int *temp = new int[(length+1)*2] ();
        int t = 0, i = first;

        if(!isempty()) {
            while(1) {
                temp[t++] = array[i];
                i = (i+1) % capacity;

                if(i == last)
                    break;
            }
        }
        temp[t] = value;

        if(array)
            delete[] array;

        array = temp;
        length++;
        capacity = length*2;
        first = 0;
        last = length;
    }

    else {
        array[last] = value;
        last = (last+1) % capacity;
        length++;
    }
}

//"pop" function: Pop the first value in the Queue
int Queue::pop() {
    if(!length) {
        return 0;
    }

    else {
        int temp = front();

        array[first] = 0;
        first = (first+1) % capacity;
        length--;

        return temp;
    }
}
