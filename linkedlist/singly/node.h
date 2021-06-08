//node.h: Include Node class definition
//Github: sioni322, Email: sioni322@naver.com

#ifndef __NODE__
#define __NODE__


class Node {
    private:
    int value;      //Include the element
    Node *next;     //Point out the next node's address

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

    //"next_address" function: Return the next node's address
    /* Parameter type: void, Return type: Node* */
    Node* next_address();

    //"modify_element" function: Modify the value of the node into "v"
    /* Parameter type: int, Return type: void */
    void modify_element(int v);

    //"modify_address" function: Modify the next node's address into "n"
    /* Parameter type: Node*, Return type: void */
    void modify_address(Node* n);

    //"print" function: Print the value of the node
    /* Parameter type: void, Return type: void */
    void print();
};

#endif