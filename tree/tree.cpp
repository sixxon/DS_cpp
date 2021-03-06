//tree.cpp, Sion Lee
/* *****************************************************************************
This source code includes definitions of Tree class's member functions.
***************************************************************************** */

#include <iostream>
#include <queue>
#include "tree.h"
using namespace std;

//"Tree" constructor function: Make a new binary tree
Tree::Tree(bool bst) {
    root = NULL;
    total = 0;
    number = 0;
    isBst = bst;
}

//"~Tree" destructor function: Delete a binary tree
Tree::~Tree() {
    delete root;
}

//"begin" function: Return the address of the root node
Node* Tree::begin() {
    return root;
}

//"size" function: Return the total number of nodes in this tree
int Tree::size() {
    return total;
}

//"insert" function: Insert a node into the tree
void Tree::insert(int n, int v, bool leftright) {
    if(isBst)
        return;

    Node* child = new Node(v, number+1);
    Node* parent;
    
    if(child == NULL)
        return;
    
    //If the tree is empty
    if(root == NULL) {
        root = child;
    }
    //Else, find the node which has number "n"
    else {
        parent = find(n);

        if((parent == NULL) || (leftright==LEFT && parent->node_left() != NULL) || (leftright==RIGHT && parent->node_right() != NULL)) {
            delete child;
            return;
        }
        parent->modify_addr(child, leftright);
    }

    total += 1;
    number += 1;
}

//"insert_bst" function: Insert a node into bst
void Tree::insert_bst(int v) {
    if(!isBst)
        return;

    Node* child = new Node(v, number+1);

    if(child == NULL)
        return;

    //If the tree is empty
    if(root == NULL) {
        root = child;
    }
    //Else, find the appropriate node
    else {
        Node* parent = root;
        bool leftright;

        while(1) {
            //If the value "v" equals parent node's value
            if(parent->node_value() == v) {
                delete child;
                return;
            }
            //If the value "v" is lesser than the parent node's value
            else if(parent->node_value() > v) {
                if(parent->node_left() == NULL) {
                    leftright = LEFT;
                    break;
                }                
                parent = parent->node_left();
            }
            //If the value "v" is larger than parent's value
            else {
                if(parent->node_right() == NULL) {
                    leftright = RIGHT;
                    break;
                }
                parent = parent->node_right();
            }
        }
        parent->modify_addr(child, leftright);
    }

    total += 1;
    number += 1;
}

//"remove_bst" function: Remove the node which has the value "v" in the bst
void Tree::remove_bst(int v) {
    if(!isBst)
        return;
    
    Node* parent = root;
    Node* child;
    bool leftright;

    //If the root node should be deleted
    if(root->node_value() == v) {
        parent = NULL;
        child = root;
    }

    //Else, find the node to be deleted
    else {
        while(1) {
            //If the value "v" is lesser than the parent node's value
            if(parent->node_value() > v && parent->node_left() != NULL) {
                if(parent->node_left()->node_value() == v) {
                    child = parent->node_left();
                    leftright = LEFT;
                    break;
                }
                parent = parent->node_left();
            }
            //If the value "v" is greater than the parent node's value
            else if(parent->node_value() < v && parent->node_right() != NULL) {
                if(parent->node_right()->node_value() == v) {
                    child = parent->node_right();
                    leftright = RIGHT;
                    break;
                }
                parent = parent->node_right();
            }
            //If we didn't find the appropriate node, return
            else
                return;
        }
    }

    //If the node to be deleted is a leaf node
    if(child->node_left() == NULL && child->node_right() == NULL) {
        //If the node to be deleted is a root node
        if(parent == NULL) {
            root = NULL;
        }
        //Else, replace parent's pointer
        else {
            parent->modify_addr(NULL, leftright);
        }
    }

    //If the node to be deleted has a child node
    else if(child->node_left() == NULL || child->node_right() == NULL) {
        Node* temp;

        //Find the child node of "child"
        if(child->node_left() != NULL) {
            temp = child->node_left();
            child->modify_addr(NULL, 0);
        }
        else {
            temp = child->node_right();
            child->modify_addr(NULL, 1);
        }
        
        //If the node to be deleted is a root node
        if(parent == NULL) {
            root = temp;
        }
        //Else, replace parent's child pointer
        else {
            parent->modify_addr(temp, leftright);
        }
    }

    //If the node to be deleted has two children nodes
    else {
        Node* maxchild;
        Node* maxparent;

        //Find the node which has the maximum value in the left subtree of "child"
        maxparent = max_bst(child->node_left(), maxchild);

        //If the left subtree's largest node isn't a child node of "child"
        if(maxparent != maxchild) {
            maxparent->modify_addr(NULL, RIGHT);
            maxchild->modify_addr(child->node_left(), LEFT);
        }
        maxchild->modify_addr(child->node_right(), RIGHT);
        child->modify_addr(NULL, LEFT); child->modify_addr(NULL, RIGHT);

        //If the node to be deleted is a root node
        if(parent == NULL) {
            root = maxchild;
        }
        //Else, replace parent's child pointer
        else {
            parent->modify_addr(maxchild, leftright);
        }
    }

    delete child;
    total -= 1;
}

//"find" function: Find the node whose number is "n" and return its address
Node* Tree::find(int n) {
    if(n > number || n < 0)
        return NULL;

    Node* node = root;
    queue<Node*> queue;
    int count = 0;

    //Find the node which has number "n"
    while(count < total) {
        if(node->node_number() == n) {
            return node;
        }
        else {
            if(node->node_left() != NULL)
                queue.push(node->node_left());

            if(node->node_right() != NULL)
                queue.push(node->node_right());

            node = queue.front();
            queue.pop();

            count += 1;
        }
    }

    return NULL;
}

//"find_bst" function: Find the node which has the value "v" in bst and return its address
Node* Tree::find_bst(int v) {
    if(!isBst)
        return NULL;
    
    Node* node = root;

    while(1) {
        if(node == NULL)
            return NULL;
        else if(node->node_value() == v) {
            return node;
        }
        else if(node->node_value() > v) {
            node = node->node_left();
        }
        else {
            node = node->node_right();
        }
    }
}

//"max_bst" function: Find the node which has the maximum value in the bst and return its parent's address
Node* Tree::max_bst(Node* start, Node*& max) {
    if(!isBst) {
        return NULL;
    }

    //If the root node has a maximum value, return
    if(start->node_right() == NULL) {
        max = start;
        return start;
    }
    //Else, find a largest node
    else {
        Node* node = start;
        max = start->node_right();

        while(1) {
            if(max->node_right() == NULL) {
                return node;
            }
            else {
                node = max;
                max = max->node_right();
            }
        }
    }
}

//"print" function: Print the tree
void Tree::print() {
    Node* node = root;
    queue<Node*> queue;
    int count = 0;

    while(count < total) {
        cout << node->node_number() << "# node's value: " << node->node_value() << "\t";
        if(node->node_left() != NULL)
            cout << "left #: " << node->node_left()->node_number() << "  ";
        if(node->node_right() != NULL)
            cout << "right #: " << node->node_right()->node_number();
        cout << "\n";


        if(node->node_left() != NULL)
            queue.push(node->node_left());

        if(node->node_right() != NULL)
        queue.push(node->node_right());

        node = queue.front();
        queue.pop();

        count += 1;
    }

    return;
}



//"infix" function: Search nodes based on the infix notation
void Tree::infix(Node* node, vector<int>& result) {
    if(node == NULL)
        return;

    infix(node->node_left(), result);
    result.push_back(node->node_value());
    infix(node->node_right(), result);

    return;
}

//"postfix" function: Search nodes based on the postfix notation
void Tree::postfix(Node* node, vector<int>& result) {
    if(node == NULL)
        return;

    postfix(node->node_left(), result);
    postfix(node->node_right(), result);
    result.push_back(node->node_value());

    return;
}

//"prefix" function: Search nodes based on the prefix notation
void Tree::prefix(Node* node, vector<int>& result) {
    if(node == NULL)
        return;

    result.push_back(node->node_value());
    prefix(node->node_left(), result);
    prefix(node->node_right(), result);

    return;
}