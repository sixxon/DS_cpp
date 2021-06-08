//linkedlist.h: Include LinkedList class definition
//Github: sioni322, Email: sioni322@naver.com

#ifndef __LINKEDLIST__
#define __LINKEDLIST__

#include "node.h"

class LinkedList{
    private:
    Node* start;    //The start node of the linked list
    int size;       //Include the number of nodes

    public:
    //"LinkedList" constructor function: Initialize member variables
    /* Parameter type: X, Return type: X */
    LinkedList();

    //"~LinkedList" destructor function: Delete all of the nodes in the linked list
    /* Parameter type: X, Return type: X */
    ~LinkedList();

    //"isEmpty" function: Return the status of the linked list (0: empty, 1: not empty)
    /* Parameter type: void, Return type: int */
    int isEmpty();

    //"insert" function: Insert the value into the linked list and return the status (0: completed 1: failed)
    /* Parameter type: int, Return type: int */
    int insert(int value);

    //"remove" function: Remove the leftmost node which has "value" from the linked list and return the status (0: completed 1: failed)
    /* Parameter type: int, Return type: int */
    int remove(int value);

    //"find" function: Find the value which is located in the linked list and return its node's address
    /* Parameter type: int, Return type: Node* */
    Node* find(int value);

    //"print" function: Print the values in the linked list
    /* Parameter type: void, Return type: void */
    void print();
};

#endif