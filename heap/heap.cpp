//heap.cpp, Sion Lee
/* *****************************************************************************
This source code includes definitions of Heap class's member functions.
***************************************************************************** */

#include "heap.h"
#include <iostream>
using namespace std;

//"Heap" constructor function: Dynamicall allocate the array with "s"
Heap::Heap(int s, bool m) {
    if(s <= ARRAY_LENGTH_MAX && s > 0) {
        array = new int[s] ();
        capacity = s;
    }
    else {
        array = 0;
        capacity = 0;
    }
    length = 0;
    ismax = m;
}

//"Heap" function: Copy constructor which functions a deep copy
Heap::Heap(const Heap &h) {
    if(array)
        delete[] array;

    array = new int[h.capacity];
    capacity = h.capacity;
    length = h.length;
    ismax = h.ismax;

    for(int i=0; i<length; i++) {
        array[i] = h.array[i];
    }
}

//"~Heap" destructor function: Delete Heap class
Heap::~Heap() {
    delete array;
}

//"top" function: Return the first element in the Heap
int Heap::top() {
    return (length > 0 ? array[0] : 0);
}

//"isempty" function: If the Heap is empty, return true. Else, return false.
bool Heap::isempty() {
    return (length == 0 ? true : false);
}

//"size" function: Return the length of the Heap
int Heap::size() {
    return length;
}

//"print" function: Print current status of this Heap
void Heap::print() {
    if(!isempty()) {
        for(int i=0; i<length; i++) {
            cout << array[i] << "\t";
        }
    }
    cout << "\nsize: " << length << "\n\n";
}

//"heapify_up" function: Do heapify with a upper direction
void Heap::heapify_up(int index) {
    if(index == 0)
        return;
    else {
        int parent = index/2;

        if((ismax && array[index] > array[parent]) || (!ismax && array[index] < array[parent])) {
            swap(array[index], array[parent]);
            heapify_up(parent);
        }
    }
}

//"heapify_down" function: Do heapify with a lower direction
void Heap::heapify_down(int index) {
    int left = index*2+1, right = index*2+2, temp = index;

    if((ismax && left < length && array[temp] < array[left]) || (!ismax && left < length && array[temp] > array[left])) {
        temp = left;
    }
    if((ismax && right < length && array[temp] < array[right]) || (!ismax && right < length && array[temp] > array[right])) {
        temp = right;
    }

    if(temp != index) {
        swap(array[index], array[temp]);
        heapify_down(temp);
    }
}

//"push" function: Push the value into the Heap
void Heap::push(int value) {
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

    heapify_up(length-1);
}

//"pop" function: Pop the first value in the Heap
int Heap::pop() {
    if(!length) {
        return 0;
    }

    else {
        int temp = top();

        array[0] = 0;
        swap(array[0], array[length-1]);
        length--;

        heapify_down(0);

        return temp;
    }
}