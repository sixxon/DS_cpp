//node.h, Sion Lee
/* *****************************************************************************
This header file includes the node information for the doubly linked list.
***************************************************************************** */

#ifndef DSCPP_NODE_H
#define DSCPP_NODE_H

//Node class is used for doubly linked list
class Node {
    private:
    int value;      //Value
    Node* prev;     //Previous node's address
    Node* next;     //Next node's address

    public:
    Node(int v);
    ~Node();

    int element();
    Node* prev_address();
    Node* next_address();

    void modify_element(int v);
    void modify_prev(Node* n);
    void modify_next(Node* n);

    void print();
};

#endif