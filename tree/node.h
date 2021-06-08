//node.h: Include Node class definition
//Github: sioni322, Email: sioni322@naver.com

#ifndef __NODE__
#define __NODE__

#define LEFT 0
#define RIGHT 1

#include <iostream>

using namespace std;

class Node {
    private:
    int value;          //Current node's value
    int number;         //Current node's number

    Node* leftchild;    //Left child node's pointer
    Node* rightchild;   //Right child node's pointer

    public:
    /* "Node" instructor function: Make a new node */
    Node(int v, int n) {
        value = v;
        number = n;

        leftchild = NULL;
        rightchild = NULL;
    }

    /* "~Node" destructor function: Delete the node */
    ~Node() {
        delete leftchild;
        delete rightchild;
    }

    /* "node_value" function: Return the value of this node */
    int node_value() {
        return value;
    }

    /* "node_number" function: Return the number of this node */
    int node_number() {
        return number;
    }

    /* "node_left" function: Return the left child node's address */
    Node* node_left() {
        return leftchild;
    }

    /* "node_right" function: Return the right child node's address */
    Node* node_right() {
        return rightchild;
    }

    /* "modify_left" function: Modify the left child node's address */
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