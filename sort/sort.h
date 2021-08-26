//sort.h, Sion Lee
/* *****************************************************************************
This header file includes some sort algorithms using a normal array.
(Bubble sort, Selection sort, Insertion sort, Merge sort, Quick sort, Heap sort)
***************************************************************************** */

#ifndef DSCPP_SORT_H
#define DSCPP_SORT_H
#define ARRAY_LENGTH_MAX 1000
#define ARRAY_ELEM_MAX 100

//Array class includes a "array data structure" and "six sorting algorithms"
class Array {
    private:
    int *value;     //Array pointer
    int size;       //The number of elements in the array

    public:
    Array(int s);
    Array(const Array &a);
    ~Array();

    int init(int n);

    int length();
    void print();

    void bubble_sort();
    void select_sort();
    void insert_sort();
    void merge_sort(int start, int end);
    void merge(int left, int mid, int right);
    void quick_sort(int pivot, int start, int end);
    void heap_sort();
    void heapify_down(int index, int range);
};

#endif