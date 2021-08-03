//sort.h: Include array class definition
//Github: sioni322, Email: sioni322@naver.com

#ifndef __SORT__
#define __SORT__

class Array {
    private:
    int *value;     //Array value
    int size;       //The number of elements in the array

    public:
    //"Array" constructor function: Dynamically allocate the array "value" with "size"
    Array(int s);

    //"~Array" destructor function: Delete the memory of this ADT
    ~Array();

    //"init" function: Initialize values into the array according to the variable 'n'(1: auto, 2: manual)
    int init(int n);

    //"length" function: Return the size of the array
    int length();

    //"print" function: Print elements of the array
    void print();



    //"swap" function: Swap value[index1] with value[index2]
    void swap(int index1, int index2);

    //"bubble_sort" function: Do bubble sort
    void bubble_sort();

    //"select_sort" function: Do selection sort
    void select_sort();

    //"insert_sort" function: Do insertion sort
    void insert_sort();

    //"merge_sort" function: Do merge sort
    void merge_sort(int start, int end);

    //"merge" function: Sort two arrays as they merge
    void merge(int left, int mid, int right);

    //"quick_sort" function: Do quick sort
    void quick_sort(int pivot, int start, int end);
};

#endif