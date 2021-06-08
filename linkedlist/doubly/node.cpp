//node.cpp: Include definition of Node's member functions
//Github: sioni322, Email: sioni322@naver.com

#include <iostream>
#include "node.h"

using namespace std;

//"Node" constructor function: Initialize the node
Node::Node(int v) {
    value = v;
    prev = NULL;
    next = NULL;
}

//"~Node" destructor function: Delete the node
Node::~Node() {
    std::cout << "Delete node!\n";
    delete next;
}

//"element" function: Return the value of the node
int Node::element() {
    return value;
}

//"prev_address" function: Return the previous node's address
Node* Node::prev_address() {
    return prev;
}

//"next_address" function: Return the next node's address
Node* Node::next_address() {
    return next;
}

//"modify_element" function: Modify the value of the node into "v"
void Node::modify_element(int v) {
    value = v;
}

//"modify_prev" function: Modify the previous node's address into "n"
void Node::modify_prev(Node* n) {
    prev = n;
}

//"modify_address" function: Modify the next node's address into "n"
void Node::modify_next(Node* n) {
    next = n;
}

//"print" function: Print the value of the node
void Node::print() {
    std::cout << value;
}