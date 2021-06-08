//linkedlist.cpp: Include defininition of LinkedList's member functions
//Github: sioni322, Email: sioni322@naver.com

#include <iostream>
#include "linkedlist.h"

using namespace std;

//"LinkedList" constructor function: Initialize the member variables
LinkedList::LinkedList(bool b) {
    start = NULL;
    size = 0;
    isCircular = b;
}

//"~LinkedList" destructor function: Delete all of the nodes in the linked list
LinkedList::~LinkedList() {
    std::cout << "Delete linked list!\n";

    if(isCircular) {
        Node* node = start;        
        Node* delnode;

        for(int i=0; i<size; i++) {
            delnode = node;
            node = node->next_address();
            
            delnode->modify_next(NULL);
            delete delnode;
        }
    }
    else
        delete start;
}

//"isEmpty" function: Return the status of the linked list (0: empty, 1: not empty)
int LinkedList::isEmpty() {
    if(start == NULL)
        return 0;
    else
        return 1;
}

//"insert" function: Insert the value into the linked list and return the status (0: completed 1: failed)
int LinkedList::insert(int value) {
    Node* node = new Node(value);

    if(node == NULL)
        return 1;

    if(!isEmpty()) {
        start = node;
        size += 1;
    }
    else {
        Node* lastnode = start;
        int i = 1;

        while(i < size) {
            lastnode = lastnode->next_address();
            i += 1;
        }

        lastnode->modify_next(node);
        node->modify_prev(lastnode);

        if(isCircular) {
            node->modify_next(start);
            start->modify_prev(node);
        }
        size += 1;
    }
    return 0;
}

//"remove" function: Remove the leftmost node which has "value" from the linked list and return the status (0: completed 1: failed)
int LinkedList::remove(int value) {
    //If the linked list is empty
    if(!isEmpty())
        return 1;

    //If the first node has a "value"
    else if(start->element() == value) {
        if(size == 1) {
            start->modify_next(NULL);
            delete start;
            start = NULL;
            return 0;
        }
        else {
            Node* node = start;
            start = start->next_address();

            node->modify_next(NULL);
            delete node;
            size -= 1;

            if(isCircular) {
                Node* lastnode = start;
                int i = 1;

                while(i < size) {
                    lastnode = lastnode->next_address();
                    i += 1;
                }
                lastnode->modify_next(start);
                start->modify_prev(lastnode);
            }
            return 0;
        }
    }

    //If there isn't a "value" in the first node, find the node which has a "value" and remove it
    else {
        Node* node = start;
        Node* prenode;
        Node* postnode;
        int i = 1;

        //Find the node which has a "value"
        while(i < size) {
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
        if(i == size)
            return 1;

        //If there is a node that has a "value", remove the node
        else {
            node = node->next_address();

            //If the linked list is circular and the node which needs to be removed is the last
            if(isCircular && i == size-1) {
                prenode->modify_next(start);
                start->modify_prev(prenode);

                node->modify_next(NULL);
                delete node;
            }
            else {
                prenode->modify_next(postnode);
                postnode->modify_prev(prenode);

                node->modify_next(NULL);
                delete node;
            }

            size -= 1;
            return 0;
        }
    }
}

//"find" function: Find out the leftmost node which has the "value" and return its node's address
Node* LinkedList::find(int value) {
    Node* node = start;
    int i = 0;

    while(i < size) {
        if(node->element() == value)
            return node;

        else {
            node = node->next_address();
            i += 1;
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