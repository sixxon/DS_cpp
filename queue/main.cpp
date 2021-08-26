//main.cpp, Sion Lee
/* *****************************************************************************
This source code includes a main function.
***************************************************************************** */

#include <iostream>
#include "queue.h"
using namespace std;

int main() {
    Queue q1(3), q2(3);

    q1.push(1);
    q1.push(2);
    q1.push(3);
    q1.pop();
    q1.print();

    q2 = q1;
    q2.print();

    return 0;
}