//sort.cpp: Include the definition of Array's member functions
//Github: sioni322, Email: sioni322@naver.com

#include <iostream>
#include <cstdlib>
#include <ctime>
#include "sort.h"

using namespace std;

#define MAX 1000
int temp[MAX];

/* ******************************************************* */
/*                     Basic functions                     */
/* ******************************************************* */

//"Array" constructor function: Dynamically allocate the array "value" with "size"
Array::Array(int s) {
    if(s <= MAX) {
        value = new int[s] {0};
        size = s;
    }
    else {
        value = NULL;
        size = 0;
    }
}

//"~Array" destructor function: Delete the memory of this ADT
Array::~Array() {
    cout << "Delete array class completely!" << endl;
    delete value;
}

//"init" function: Initialize values into the array according to the variable 'n'(1: random, 2: user input)
int Array::init(int n) {
    //If n=1, automatically initialize values of the array
    if(n == 1) {
        srand(time(NULL));
        for(int i=0; i<size; i++) {
            value[i] = rand() % 100 + 1;
        }
        return 0;
    }
    //If n=2, manually initialize values of the array
    else if(n == 2) {
        for(int i=0; i<size; i++) {
            cout << "Please input the #" << i+1 << " value of the array: ";
            cin >> value[i];
            //Note that this code doesn't check the range of input value!
        }
        return 0;
    }

    else {
        cout << "Wrong input type!" << endl;
        return 1;
    }
}

//"length" function: Return the size of the array
int Array::length() {
    return size;
}

//"print" function: Print elements of the array
void Array::print() {
    for(int i=0; i<size; i++)
        cout << value[i] << "\t";
    cout << "\n";
}


/* ******************************************************* */
/*                   Sorting functions                     */
/* ******************************************************* */

void Array::swap(int index1, int index2) {
    int temp = value[index1];
    value[index1] = value[index2];
    value[index2] = temp;
    return;
}

//"bubble_sort" function: Do bubble sort
void Array::bubble_sort() {
    int temp;
    //i: base index, j: remainder index
    for(int i=0; i<size; i++) {
        for(int j=i+1; j<size; j++) {
            if(value[i] > value[j]) {
                swap(i, j);
            }
        }
    }
}

//"select_sort" function: Do selection sort
void Array::select_sort() {
    int index, temp;
    //i: ith smallest index, j: unsorted element's index
    for(int i=0; i<size; i++) {
        index = i;
        for(int j=i+1; j<size; j++) {
            if(value[index] > value[j])
                index = j;
        }
        //Do swap
        swap(i, index);
    }
}

//"insert_sort" function: Do insertion sort
void Array::insert_sort() {
    int j, temp;
    //i: unsorted element's index, j: sorted element's index
    for(int i=1; i<size; i++) {
        temp = value[i];
        j = i-1;

        while(j >= 0 && value[j] > temp) {
            value[j+1] = value[j];
            j--;
        }
        value[j+1] = temp;
    }
}

//"merge_sort" function: Do merge sort
void Array::merge_sort(int start, int end) {
    if(start == end-1) return;

    int mid = (start+end)/2;
    merge_sort(start, mid);
    merge_sort(mid, end);
    merge(start, mid, end);
}

//"merge" function: Sort the array as they merge
void Array::merge(int left, int mid, int right) {
    //i: left subarray's index, j: right subarray's index, k: temp array's index
    int i=left, j=mid, k=left;

    //Put the smallest value into the temp array
    while(i < mid && j < right) {
        if(value[i] < value[j]) {
            temp[k++] = value[i++];
        }
        else {
            temp[k++] = value[j++];
        }
    }

    //Put remaining elements into the temp array
    if(i < mid) {
        for(i; i<mid; i++)
            temp[k++] = value[i];
    }
    else if(j < right) {
        for(j; j<right; j++)
            temp[k++] = value[j];
    }

    for(k=left; k<right; k++)
        value[k] = temp[k];

    return;
}

//"quick_sort" function: Do quick sort
void Array::quick_sort(int pivot, int start, int end) {
    int left = start, right = end;

    //start: first index of the array, end: last index of the array
    //left: index to find larger value than the pivot, right: index to find equal or smaller value than the pivot
    //If the number of elements in the array is greater than 1, do swap
    if(left < right) {
        while(left <= right) {
            //If value[left] and value[right] need to swap
            if(value[left] > value[pivot] && value[right] <= value[pivot]) {
                if(right == pivot)
                    pivot = left;

                swap(left, right);
                left += 1; right -= 1;
            }
            //If left&right index need to search next elements
            else if(value[left] <= value[pivot] && value[right] > value[pivot]) {
                left += 1; right -= 1;
            }
            //If left index need to search the next larger element
            else if(value[left] <= value[pivot]) {
                left += 1;
            }
            //If right index need to search the next smaller element
            else {
                right -= 1;
            }
        }
        //Swap the small value(value[right]) and pivot value(value[pivot])
        if(value[right] <= value[pivot]) {
            swap(right, pivot);
            pivot = right;
        }
        
        quick_sort((start + pivot-1)/2, start, pivot-1);
        quick_sort((pivot+1 + end)/2, pivot+1, end);
    }
    //If the number of elements in the array is 1, return
    else
        return;
}
