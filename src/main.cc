/* 
 * File:   main.cc
 * Author: Talik Kasozi <projectxyz.org>
 *
 * Created on April 25, 2016, 6:13 PM
 */

#include <iostream>

#include "base/DataStructures.h"

void print3(int* x) {
    std::cout << *x << " ";
}

int main(int argc, char** argv) {
    using ::datastructures::DoublyLinkedList;
    using namespace std;

    int xrry[] = {67, 88, 8, 7, 6, 3, 0, 4, 2, 1, 0, 9, 100, 12, 14, 16, 17, 122, 144, 99, 34, 23, 55, 2, 123, 232, 42, 4657};
    
    DoublyLinkedList<int>* list = new DoublyLinkedList<int>(::datastructures::StructureState::UNSORTED);

    for (auto &x : xrry) {
        list->insert(&x);
    }

    list->traverse(print3);
    
    return 0;
}
