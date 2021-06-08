//main.cpp: Main function, made by Sion Lee
//Github: sioni322, Email: sioni322@naver.com

#include <iostream>
#include "heap.h"

using namespace std;

int main() {
    Heap maxheap(5);
    Heap minheap(5, 0);

    maxheap.insert(6); minheap.insert(6);
    maxheap.insert(10); minheap.insert(10);
    maxheap.insert(3); minheap.insert(3);
    maxheap.insert(4); minheap.insert(4);
    maxheap.insert(5); minheap.insert(5);
    maxheap.insert(3); minheap.insert(3);

    maxheap.print();
    std::cout << "\n\n";
    minheap.print();
    std::cout << "\n\n";

    maxheap.remove(); minheap.remove();
    maxheap.remove(); minheap.remove();

    maxheap.print();
    std::cout << "\n\n";
    minheap.print();
    std::cout << "\n\n";

    return 0;
}