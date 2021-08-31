//main.cpp, Sion Lee
/* *****************************************************************************
This source code includes a main function.
***************************************************************************** */

#include <iostream>
#include "tree.h"
using namespace std;

int main() {
    //Normal binary tree
    Tree t(0);
    std::cout << "************************** Binary tree **************************\n";

    t.insert(0, 50, 0);
    t.insert(1, 150, 1);
    t.insert(1, 25, 0);
    t.insert(3, 70, 1);
    t.insert(3, 130, 0);
    t.insert(2, 170, 1);

    std::cout << "After inserting: \n";
    t.print();
    std::cout << "\n\n";

    std::cout << "After finding 5th node: \n";
    std::cout << t.find(5) << endl;
    std::cout << "\n\n";

    vector<int> result1, result2, result3;

    t.infix(t.begin(), result1);
    t.postfix(t.begin(), result2);
    t.prefix(t.begin(), result3);

    std::cout << "Infix order: \n";
    for(int i=0; i<result1.size(); i++)
        cout << result1[i] << "\t";
    std::cout << "\n\n";

    std::cout << "Postfix order: \n";
    for(int i=0; i<result2.size(); i++)
        cout << result2[i] << "\t";
    std::cout << "\n\n";

    std::cout << "Prefix order: \n";
    for(int i=0; i<result3.size(); i++)
        cout << result3[i] << "\t";
    std::cout << "\n\n";


    //Binary search tree
    Tree bst(1);
    std::cout << "\n\n*********************** Binary search tree ***********************\n";

    bst.insert_bst(10);
    bst.insert_bst(7);
    bst.insert_bst(15);
    bst.insert_bst(2);
    bst.insert_bst(12);
    bst.insert_bst(4);

    std::cout << "After inserting: \n";
    bst.print();
    std::cout << "\n\n";

    std::cout << "After finding the node which has a value 7: \n";
    std::cout << bst.find_bst(7) << endl;
    std::cout << "\n\n";

    std::cout << "After deleting the root node: \n";
    bst.remove_bst(10);
    bst.print();

    std::cout << "\n\nAfter deleting the node which has value 2: \n";
    bst.remove_bst(2);
    bst.print();

    return 0;
}