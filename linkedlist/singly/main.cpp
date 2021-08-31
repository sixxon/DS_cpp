//main.cpp, Sion Lee
/* *****************************************************************************
This source code includes a main function.
***************************************************************************** */

#include <iostream>
#include "linkedlist.h"
using namespace std;

int main() {
    LinkedList list;
    Node* node;

    cout << "After insert elements 1, 2, 3:\n";
    list.insert(1);
    list.insert(2);
    list.insert(3);
    list.print();

    cout << "\n\nAfter remove the element 1:\n";
    list.remove(1);
    list.print();

    cout << "\n\nAfter insert elements 4, 5:\n";
    list.insert(4);
    list.insert(5);
    list.print();

    cout << "\n\nResult of finding the element 1:\n";
    node = list.find(1);
    if(node == NULL) {
        cout << "Failed to find the element 1!\n";
    }
    else {
        cout << "Suceed finding the element 1!\n";
        cout << "Address: " << node << "\n";
    }

    return 0;
}