//sort.cpp: Include the definition of Array's member functions
//Github: sioni322, Email: sioni322@naver.com

#include <iostream>
#include <cstdlib>
#include <ctime>
#include "sort.h"

using namespace std;

/* ******************************************************* */
/*                     Basic functions                     */
/* ******************************************************* */

//"Array" constructor function: Dynamically allocate the array "value" with "size"
Array::Array(int s) {
    value = new int[s] {0};
    size = s;
}

//"~Array" destructor function: Delete the memory of this ADT
Array::~Array() {
    std::cout << "Delete array class completely!" << endl;
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
            std::cout << "Please input the #" << i+1 << " value of the array: ";
            std::cin >> value[i];
            //Note that this code doesn't check the range of input value!
        }
        return 0;
    }

    else {
        std::cout << "Wrong input type!" << endl;
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
        std::cout << value[i] << "\t";
    std::cout << "\n";
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

//"bubble_sort" function: Do bubble sorting on the array
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

//"select_sort" function: Do selection sorting on the array
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

//"insert_sort" function: Do insertion sorting on the array
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

//"merge_sort" function: Do merge sorting on the array recursively
Array* Array::merge_sort(Array* arr, int start, int end) {
    //If the size of the array is 1, return the array
    if(start == end-1) {
        Array* arr_part = new Array(1);
        arr_part->value[0] = arr->value[start];
        return arr_part;
    }
    //If the size of the array is bigger than 1, divide the array into subarray and merge
    else {
        Array* arr_part1 = merge_sort(arr, start, (start+end)/2);
        Array* arr_part2 = merge_sort(arr, (start+end)/2, end);
        return merge(arr_part1, arr_part2);
    }
}

//"merge" function: Sort two arrays as they merge
Array* Array::merge(Array* arr1, Array* arr2) {
    Array* arr_merge = new Array(arr1->size + arr2->size);
    int i = 0, j = 0, k = 0;

    //i: the index of arr1, j: the index of arr2, k: the index of arr_merge
    //Push the smaller value into arr_merge
    while((i!=arr1->size) && (j!=arr2->size) && (k!=arr_merge->size)) {
        if(arr1->value[i] < arr2->value[j]) {
            arr_merge->value[k] = arr1->value[i];
            i+=1; k+=1;
        }
        else {
            arr_merge->value[k] = arr2->value[j];
            j+=1; k+=1;
        }
    }

    if(i<arr1->size) {
        for(i; i<arr1->size; i++, k++)
            arr_merge->value[k] = arr1->value[i];
    }
    else if(j<arr2->size) {
        for(j; j<arr2->size; j++, k++)
            arr_merge->value[k] = (arr2->value[j]);
    }

    return arr_merge;
}

//"quick_sort" function: Do quick sorting on the array recursively
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
