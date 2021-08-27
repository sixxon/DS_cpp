//main.cpp, Sion Lee
/* *****************************************************************************
This source code includes a main function.
***************************************************************************** */

#include <iostream>
#include "heap.h"
using namespace std;

int main() {
    Heap max(5), min(5, false);

    max.push(1); min.push(1);
    max.push(2); min.push(2);
    max.push(3); min.push(3);
    max.push(4); min.push(4);
    max.print(); min.print();

    max.pop(); min.pop();
    max.print(); min.print();

    return 0;
}