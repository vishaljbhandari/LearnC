// gcc -lstdc++ -lm bidirection_iterator.cpp

#include <iostream>
#include <set>
using namespace std;

int main() {
    set<int> set1 = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };
    set<int>::iterator it1;   // iterator object

    // iterate forward
    for(it1 = set1.begin(); it1 != set1.end(); ++it1) {
        cout << *it1 << " ";
    }
    cout << endl;

    // iterate backward
    for(it1 = set1.end(); it1 != set1.begin();) {
        cout << *--it1 << " ";
    }
    cout << endl;
    
    // range-based for loop
    for(int i : set1) {
        cout << i << " ";
    }
    cout << endl;

    return 0;
}
