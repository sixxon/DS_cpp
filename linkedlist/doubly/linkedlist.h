//linkedlist.h, Sion Lee
/* *****************************************************************************
This header file includes the doubly linked list data structure using nodes.
***************************************************************************** */

#ifndef DSCPP_LINKEDLIST_H
#define DSCPP_LINKEDLIST_H
#include "node.h"

class LinkedList{
    private:
    Node* start;        //The start node of the linked list
    int size;           //The number of nodes

    bool isCircular;    //If true, circular linked list.

    public:
    LinkedList(bool b=0);
    ~LinkedList();

    bool isEmpty();
    void print();

    void insert(int value);
    void remove(int value);
    Node* find(int value);
};

#endif