//node.h: Include Node class definition (For doubly linked list & circular linked list)
//Github: sioni322, Email: sioni322@naver.com

#ifndef __NODE__
#define __NODE__


class Node {
    private:
    Node* prev; //Point out the previous node's address
    Node* next;     //Point out the next node's address

    int value;      //Include the element

    public:
    //"Node" constructor function: Initialize the node
    /* Parameter type: int, Return type: X */
    Node(int v);

    //"~Node" destructor function: Delete the node
    /* Parameter type: X, Return type: X */
    ~Node();

    //"element" function: Return the value of the node
    /* Parameter type: void, Return type: int */
    int element();

    //"prev_address" function: Return the previous node's address
    /* Parameter type: void, Return type: Node* */
    Node* prev_address();

    //"next_address" function: Return the next node's address
    /* Parameter type: void, Return type: Node* */
    Node* next_address();

    //"modify_element" function: Modify the value of the node into "v"
    /* Parameter type: int, Return type: void */
    void modify_element(int v);

    //"modify_prev" function: Modify the previous node's address into "n"
    /* Parameter type: Node*, Return type: void */
    void modify_prev(Node* n);

    //"modify_address" function: Modify the next node's address into "n"
    /* Parameter type: Node*, Return type: void */
    void modify_next(Node* n);

    //"print" function: Print the value of the node
    /* Parameter type: void, Return type: void */
    void print();
};

#endif