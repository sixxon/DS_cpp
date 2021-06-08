//main.cpp: Main function, made by Sion Lee
//Github: sioni322, Email: sioni322@naver.com

#include <iostream>
#include "queue.h"

using namespace std;

int main() {
    Queue q1(3);

    q1.enqueue(3);
    q1.enqueue(5);
    q1.enqueue(5);
    q1.dequeue();
    q1.dequeue();
    q1.dequeue();
    q1.dequeue();

    q1.print();

    return 0;
}