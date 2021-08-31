//tree.h, Sion Lee
/* *****************************************************************************
This header file includes the tree data structure using nodes.
***************************************************************************** */

#ifndef DSCPP_TREE_H
#define DSCPP_TREE_H
#include <vector>
#include "node.h"

using namespace std;

//Tree class can express a binary tree only
class Tree {
    private:
    Node* root;         //Root node's address

    int total;          //The number of nodes in the tree
    int number;         //Maximum number of this tree
    bool isBst;         //If this tree is a binary search tree, true. Else, false.

    public:
    Tree(bool bst=0);
    ~Tree();
 
    Node* begin();
    int size();
    void print();

    void insert(int n, int v, bool leftright);
    void insert_bst(int v);
    void remove_bst(int v);
    Node* find(int n);
    Node* find_bst(int v);
    Node* max_bst(Node* start, Node*& max);

    void infix(Node* node, vector<int>& result);
    void postfix(Node* node, vector<int>& result);
    void prefix(Node* node, vector<int>& result);
};

#endif