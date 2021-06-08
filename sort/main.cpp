//main.cpp: Main function, made by Sion Lee
//Github: sioni322, Email: sioni322@naver.com
#include <iostream>
#include "sort.h"

using namespace std;

int main() {
    Array a1(5), a2(5), a3(5), a4(5), a5(5);

    cout << "Bubble sort\n";
    a1.init(1);
    a1.print();
    a1.bubble_sort();
    a1.print();
    cout << "\n\n";

    cout << "Selection sort\n";
    a2.init(1);
    a2.print();
    a2.select_sort();
    a2.print();
    cout << "\n\n";

    cout << "Insertion sort\n";
    a3.init(1);
    a3.print();
    a3.insert_sort();
    a3.print();
    cout << "\n\n";

    cout << "Merge sort\n";
    a4.init(1);
    a4.print();
    Array* a6 = a4.merge_sort(&a4, 0, a4.length());
    a6->print();
    cout << "\n\n";

    cout << "Quick sort\n";
    a5.init(1);
    a5.print();
    a5.quick_sort(a5.length()-1/2, 0, a5.length()-1);
    a5.print();
    cout << "\n\n";

    return 0;
}