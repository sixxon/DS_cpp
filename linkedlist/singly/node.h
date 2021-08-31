//node.h, Sion Lee
/* *****************************************************************************
This header file includes the node information for the linked list.
***************************************************************************** */

#ifndef DSCPP_NODE_H
#define DSCPP_NODE_H

//Node class is used for linked list
class Node {
    private:
    int value;      //Value
    Node *next;     //Next node's address

    public:
    Node(int v);
    ~Node();

    int element();
    Node* next_address();
    void modify_element(int v);
    void modify_address(Node* n);

    void print();
};

#endif