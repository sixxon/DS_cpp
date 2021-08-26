//main.cpp, Sion Lee
/* *****************************************************************************
This source code includes a main function.
***************************************************************************** */

#include <iostream>
#include "stack.h"

using namespace std;

int main() {
    Stack s1(2);
    
    s1.print();
    s1.push_back(1);
    s1.print();
    s1.push_back(2);
    s1.print();
    s1.push_back(3);
    s1.print();

    s1.pop_back();
    s1.print();
    s1.pop_back();
    s1.print();
    cout << "s1[0]: " << s1[0] << "\n";

    return 0;
}