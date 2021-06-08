//heap.cpp: Include definition of Heap's member functions
//Github: sioni322, Email: sioni322@naver.com

#include "heap.h"

using namespace std;

//Constructor and destructor functions
/* "Heap" constructor function: Make a new heap */
Heap::Heap(int s, bool maxmin) {
    array = new int[s] {0};
    
    size = 0;
    capacity = s;
    isMax = maxmin;
}

/* "~Heap" destructor function: Delete a heap */
Heap::~Heap() {
    delete array;
}



//Parameter functions
/* "length" function: Return the length of the heap array */
int Heap::length() {
    return size;
}

/* "depth" function: Return the depth of the heap */
int Heap::depth() {
    return log2(size)+1;
}

/* "maxmin" function: Return the status of max/min */
bool Heap::maxmin() {
    return isMax;
}



//Basic functions
/* "insert" function: Insert a new node into the heap */
int Heap::insert(int v) {
    //If the array is full, reallocate and copy
    if(size == capacity) {
        capacity += capacity / 2;
        int *newarray = new int[capacity] {0};

        copy(array, array+size, newarray);

        delete array;
        array = newarray;
    }

    //Insert new node into the end of the heap
    array[size] = v;
    int child = size;

    //Compare the parent node's value to the child node's value and swap
    while(size && child) {
        int parent = (child+1)/2-1;

        //Compare and swap
        if((isMax == MAX && array[parent] < array[child]) || (isMax == MIN && array[parent] > array[child])) {
            swap(array[child], array[parent]);
            child = (child+1)/2-1;
        }
        else
            break;
    }

    size += 1;
    return 0;
}

/* "remove" function: Remove a root node from the heap */
int Heap::remove() {
    //If the heap is empty, return
    if(!size)
        return 1;

    //Delete a root node and swap with last node
    array[0] = 0;
    swap(array[0], array[size-1]);
    size -= 1;

    int parent = 0;

    //Compare the parent node's value to the child node's value and swap
    while(1) {
        int child;
        int odd = parent*2+1;
        int even = parent*2+2;

        //Check out the range of child nodes
        if(odd > size-1)
            break;
        
        else if(even > size-1)
            child = odd;
        
        //If "parent" node has two children nodes, find the appropriate node
        else {
            if((isMax == MAX && array[odd] > array[even]) || (isMax == MIN) && array[odd] < array[even])
                child = odd;
            else
                child = even;
        }

        //Compare and swap
        if((isMax == MAX && array[parent] < array[child]) || (isMax == MIN && array[parent] > array[child])) {
            swap(array[child], array[parent]);
            parent = child;
        }
        else
            break;
    }

    return 0;
}

/* "number" function: Return the number of node which has a value "v" */
int Heap::number(int v) {
    for(int i=0; i<size; i++) {
        if(array[i] == v)
            return i;
    }

    return -1;
}

/* "value" function: Return the value of nth node */
int Heap::value(int n) {
    if(n > size || n < 0)
        return -1;

    return array[n];
}

/* "print" function: Print the heap nodes */
void Heap::print() {
    if(!size)
        return;
        
    if(isMax)
        std::cout << "[Max ";
    else
        std::cout << "[Min ";

    std::cout << "heap status]\n";
    std::cout << "-----------------------------------------------------\n";
    

    for(int i=0; i<size; i++) {
        std::cout << array[i];
        if(floor(log2(i+1)) < floor(log2(i+2)))
            std::cout << "\n";
        else
            std::cout << "\t";
    }

    std::cout << "\n\n-The number of nodes: " << size << "\n";
    std::cout << "-Heap depth: " << depth() << "\n";
    std::cout << "-Heap capacity: " << capacity << "\n";
    std::cout << "-----------------------------------------------------\n";
}