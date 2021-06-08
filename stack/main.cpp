//main.cpp: Main function, made by Sion Lee
//Github: sioni322, Email: sioni322@naver.com

#include <iostream>
#include "stack.h"

using namespace std;

int main() {
    Stack s1(3);

    s1.print();

    s1.push(2);
    s1.pop();
    s1.print();

    s1.push(4);
    s1.pop();
    s1.print();

    return 0;
}