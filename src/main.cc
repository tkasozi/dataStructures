/* 
 * File:   main.cc
 * Author: Talik Kasozi <projectxyz.org>
 *
 * Created on April 25, 2016, 6:13 PM
 */

#include "base/BST.h"
#include "base/linked_list.h"
#include <iostream>

using namespace std;

class Person {
public:

    Person(string name) :
    name(name) {
    }
    //I need to override the < > operators

    bool operator<(Person x) {
        return (this->name.compare(x.name) < 0);
    }

    bool operator>(Person x) {
        return (this->name.compare(x.name) > 0);
    }

    bool operator==(Person x) {
        return (this->name.compare(x.name) == 0);
    }

    string GetName() const {
        return name;
    }
private:
    string name;
};

status print1(Person x) {
    cout << x.GetName() << ", ";
    return OK;
}

status print2(int x) {
    cout << x << " ";
    return OK;
}

void sqr(int* x) {
    (*x) *= (*x);
}

void print3(int* x) {
    cout << *x << " ";
}

int main__(int argc, char** argv) {
    using ::dataStructures::linked_list;

    int xrry[] = {67, 88, 8, 7, 6, 3, 0, 4, 2, 1, 0, 9, 100, 12, 14, 16, 17, 122, 144, 99, 34, 23, 55, 2, 123, 232, 42, 4657};

    linked_list<int> * lst = new linked_list<int>();

    for (auto &i : xrry) {
        lst->insert(&i);
    }
    lst->traverse(print3);

    cout << "\nlinked list length: " << lst->getLength() << endl;

    return 0;
}

// <editor-fold defaultstate="collapsed" desc="expand the code">

int main_(int argc, char** argv) {
    using ::dataStructures::btree; //btree template,

    Person* talik = new Person("Kasozix");
    Person* kasozi = new Person("Kasozi");
    Person* thiago = new Person("Thiago");
    Person* other = new Person("Other");

    tree_node_ptr search;

    btree<Person>* binarytree = new btree<Person>();

    binarytree->insert(talik);
    binarytree->insert(kasozi);
    binarytree->insert(thiago);

    binarytree->traverse(print1);

    if ((search = binarytree->search(talik)) != nullptr) {
        cout << "found " << (*(Person*) search->datapointer).GetName() << endl;

        if (!binarytree->empty(search->right)) {
            cout << "next: " << (*(Person*) search->right->datapointer).GetName();
        }
        if (!binarytree->empty(search->left)) {
            cout << " before: " << (*(Person*) search->left->datapointer).GetName();
        }

    } else {
        cout << "did not find \"" << other->GetName() << "\"" << endl;
    }
    return 0;
}// </editor-fold>

// <editor-fold defaultstate="collapsed" desc="expand the code">

int main(int argc, char** argv) {
    using ::dataStructures::btree; //btree template,

    int xrry[] = {90009, 9, 65674345, 8787878, 67, 88, 8, 7, 6, 3, 0, 4, 2, 1, 0, 9, 100, 12, 14, 16, 17, 122, 144, 99, 34, 23, 55, 2, 123, 4232, 12324, 535343, 232, 42, 232323, 232323, 232124553, 4657};
    int b = 5, search = 535343;

    btree<int>* binarytree = new btree<int>();

    binarytree->insert(&b);

    for (auto &x : xrry) {
        binarytree->insert(&x);
    }

    binarytree->traverse(print2);

    tree_node_ptr x;

    if ((x = binarytree->search(&search)) != nullptr) {
        cout << "found " << search << endl;
    } else {
        cout << "did not find " << search << endl;
    }

    //binarytree->~btree();
    return 0;
}// </editor-fold>
