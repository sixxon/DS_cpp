//linkedlist.cpp, Sion Lee
/* *****************************************************************************
This source code includes definitions of LinkedList class's member functions.
***************************************************************************** */

#include <iostream>
#include "linkedlist.h"
using namespace std;

//"LinkedList" constructor function: Initialize member variables
LinkedList::LinkedList() {
    start = NULL;
    size = 0;
}

//"~LinkedList" destructor function: Delete all of the nodes in the linked list
LinkedList::~LinkedList() {
    delete start;
}

//"isEmpty" function: If the linked list is empty, return true. Else, return false.
bool LinkedList::isEmpty() {
    if(start == NULL)
        return true;
    else
        return false;
}

//"insert" function: Insert the value into the linked list
void LinkedList::insert(int value) {
    Node* node = new Node(value);

    if(node == NULL)
        return;

    if(isEmpty()) {
        start = node;
        size += 1;
    }
    else {
        Node* lastnode = start;

        while(lastnode->next_address() != NULL) {
            lastnode = lastnode->next_address();
        }
        lastnode->modify_address(node);
        size += 1;
    }
}

//"remove" function: Remove the leftmost node which has "value" from the linked list
void LinkedList::remove(int value) {
    if(isEmpty())
        return;

    //If the first node has a "value"
    else if(start->element() == value) {
        Node* node = start;
        start = start->next_address();
        size -= 1;

        node->modify_address(NULL);
        delete node;
    }

    //If there isn't a "value" in the first node, find the node which has a "value" and remove it
    else {
        Node* node = start;
        Node* prenode;
        Node* postnode;
        int i = 1;

        //Find the node which has a "value"
        while(i<size && node->next_address() != NULL) {
            if(node->next_address()->element() == value) {
                prenode = node;
                postnode = node->next_address()->next_address();
                break;
            }
            else {
                node = node->next_address();
                i += 1;
            }
        }

        //If any node hasn't a "value", return
        if(i == size || node->next_address() == NULL) {
            return;
        }
        //If there is a node that has a "value", remove the node
        else {
            node = node->next_address();
            size -= 1;

            prenode->modify_address(postnode);
            node->modify_address(NULL);
            delete node;
        }
    }
}

//"find" function: Find the value which is located in the linked list and return its node's address
Node* LinkedList::find(int value) {
    Node* node = start;
    int iter = 0;

    while(iter < size && node != NULL) {
        if(node->element() == value)
            return node;

        else {
            node = node->next_address();
        }
    }
    return NULL;
}

//"print" function: Print the values in the linked list
void LinkedList::print() {
    Node* node = start;

    for(int i=0; i<size; i++) {
        node->print(); cout << "\t";
        node = node->next_address();
    }
    std::cout << "\n";
}