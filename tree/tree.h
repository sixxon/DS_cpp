//tree.h: Include Tree class definition
//Github: sioni322, Email: sioni322@naver.com

#ifndef __TREE__
#define __TREE__

#define LEFT 0
#define RIGHT 1

#include <queue>
#include <vector>
#include "node.h"

using namespace std;

//Tree class can express a binary tree only
class Tree {
    private:
    Node* root;         //Point out the root node

    int total;          //Total number of nodes in this tree
    int maxnum;         //Maximum number of this tree
    bool isBst;         //If this tree is a binary search tree, isBst=1. Else, 0.

    public:
    /* *************** Constructor and destructor functions ************** */
    /* "Tree" constructor function: Make a new binary tree */
    Tree(bool bst=0);

    /*"~Tree" destructor function: Delete a binary tree */
    ~Tree();
 
    /* ******************************************************************* */


    /* ******************* Tree parameter functions *********************** */
    /* "rootnode" function: Return the address of the root node */
    Node* rootnode();

    /* "totalnode" function: Return the total number of nodes in this tree */
    int totalnode();

    /* ******************************************************************* */


    /* *********************** Basic functions *************************** */
    /* "insert" function: Insert a node into the tree and return the status
        (Status: 0(complete), 1(failed))                                   */
    int insert(int n, int v, bool leftright);

    /* "insert_bst" function: Insert a node into bst and return the status
        (Status: 0(complete), 1(failed))                                   */
    int insert_bst(int v);

    /* "remove_bst" function: Remove the node which has the value "v" 
        in the bst and return the status (Status: 0(complete), 1(failed))  */
    int remove_bst(int v);

    /* "find" function: Find the node whose number is "n" and return its address */
    Node* find(int n);

    /* "find_bst" function: Find the node which has the value "v" in bst and return its address */
    Node* find_bst(int v);

    /* "max_bst" function: Find the node which has the maximum value in the bst
        and return its parent's address */
    Node* max_bst(Node* start, Node*& max);

    /* "print" function: Print the tree */
    void print();

    /* ******************************************************************* */


    /* ************* Infix, postfix, prefix search functions ************** */
    /* "infix" function: Search nodes based on the infix notation */
    void infix(Node* node, vector<int>& result);

    /* "postfix" function: Search nodes based on the postfix notation */
    void postfix(Node* node, vector<int>& result);

    /* "prefix" function: Search nodes based on the prefix notation */
    void prefix(Node* node, vector<int>& result);

    /* ******************************************************************* */
};

#endif