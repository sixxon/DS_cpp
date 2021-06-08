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
    /* Parameter type: int, Return type: X */
    Array(int s);

    //"~Array" destructor function: Delete the memory of this ADT
    /* Parameter type: X, Return type: X */
    ~Array();

    //"init" function: Initialize values into the array according to the variable 'n'(1: auto, 2: manual)
    /* Parameter type: int, Return type: int */
    int init(int n);

    //"length" function: Return the size of the array
    /* Parameter type: void, Return type: int */
    int length();

    //"print" function: Print elements of the array
    /* Parameter type: void, Return type: void */
    void print();



    //"swap" function: Swap value[index1] with value[index2]
    /* Parameter type: int, int, Return type: void */
    void swap(int index1, int index2);

    //"bubble_sort" function: Do bubble sorting on the array
    /* Parameter type: void, Return type: void */
    void bubble_sort();

    //"select_sort" function: Do selection sorting on the array
    /* Parameter type: void, Return type: void */
    void select_sort();

    //"insert_sort" function: Do insertion sorting on the array
    /* Parameter type: void, Return type: void */
    void insert_sort();

    //"merge_sort" function: Do merge sorting on the array recursively
    /* Parameter type: void, Return type: void */
    Array* merge_sort(Array* arr, int start, int end);

    //"merge" function: Sort two arrays as they merge
    /* Parameter type: Array*, Array*, Return type: Array* */
    Array* merge(Array* arr1, Array* arr2);

    //"quick_sort" function: Do quick sorting on the array recursively
    /* Parameter type: int, int, int, Return type: void */
    void quick_sort(int pivot, int start, int end);
};

#endif