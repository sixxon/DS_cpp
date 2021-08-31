//node.h, Sion Lee
/* *****************************************************************************
This header file includes the node information for the tree.
***************************************************************************** */

#ifndef DSCPP_NODE_H
#define DSCPP_NODE_H

#include <iostream>
#define LEFT 0
#define RIGHT 1

//Node class is used for tree
class Node {
    private:
    int value;          //Node's value
    int number;         //Current node number

    Node* leftchild;    //Left child node's address
    Node* rightchild;   //Right child node's address

    public:
    //"Node" instructor function: Make a new node
    Node(int v, int n) {
        value = v;
        number = n;

        leftchild = NULL;
        rightchild = NULL;
    }

    //"~Node" destructor function: Delete the node
    ~Node() {
        delete leftchild;
        delete rightchild;
    }

    //"node_value" function: Return the value of this node
    int node_value() {
        return value;
    }

    //"node_number" function: Return the number of this node
    int node_number() {
        return number;
    }

    //"node_left" function: Return the left child node's address
    Node* node_left() {
        return leftchild;
    }

    //"node_right" function: Return the right child node's address
    Node* node_right() {
        return rightchild;
    }

    //"modify_left" function: Modify the child node's address
    void modify_addr(Node* node, bool child) {
        if(child==LEFT) {
            leftchild = node;
        }
        else {
            rightchild = node;
        }
    }
};

#endif