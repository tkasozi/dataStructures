/* 
 * File:   data_struct.h
 * Author: Talik Kasozi <projectxyz.org>
 *
 * Created on April 27, 2016, 6:44 PM
 */

#ifndef DATASTRUCTURES_H
#define	DATASTRUCTURES_H

#ifdef DOUBLYLINKEDLIST_H
#error "DoublyLinkedList_Impl.h should not to be included directly. Include DataStructures.h"
#endif

#ifdef LINKED_LIST_H
#error "LinkedList_Impl.h should not to be included directly. Include DataStructures.h"
#endif

#ifdef BINARY_SEARCH_TREE_H
#error "BinarySearchTree_Impl.h should not to be included directly. Include DataStructures.h"
#endif 

#include <iostream>
#include <iterator>

#include  "globals.h"

namespace datastructures {

    enum StructureState {
        SORTED, UNSORTED
    };
    //Binary Search Tree template 
    //Example:
    //btree<int>* binarytree = new btree<int>();
    //binarytree->insert(&b);
    //delete binarytree;

    template<typename T>
    class BinaryTree {
    public:

        //using this->root because of recursion to search and insert in
        //a tree

        BinaryTree() : root_(nullptr) {
        };

        virtual ~BinaryTree() {
            destroyTree(this->getRoot());
        }

        inline bool empty(treeNodePointer leaf) {
            return (leaf == nullptr);
        }

        //Applies the provided function to data in a sorted/increasing order.
        //This is achieved with the inorder_traverse()

        status traverse(status(*p_func)(T)) {
            return inorderTraverse(this->getRoot(), p_func);
        }

        //Returns a pointer to the target node a nullptr otherwise. 
        //It is the client's responsibility to delete the node after 
        //use or clean up will be done at the end of the program. 
        //The client must not use this function once the Tree has been destroyed. 
        //The internal representation is hidden to prevent 
        //1. Too much casting ie search((string*)data), search((int*)data) ...
        //2. To allow encapsulation. ie. the Root of the tree can only be 
        //modified from with in the class.

        treeNodePointer search(T* data) {
            return search(this->getRoot(), (genericPointer) data);
        }

        void insert(T* data) {

            if (!empty(this->getRoot())) {
                insert(this->getRoot(), (genericPointer) data);
            } else {
                treeNodePointer temp = new TreeNode;
                temp->datapointer = (genericPointer) data;
                temp->left = nullptr;
                temp->right = nullptr;

                this->setRoot(temp);
            }
        }

        inline treeNodePointer getRoot() const {
            return root_;
        }
    private:
        void setRoot(treeNodePointer root);
        void destroyTree(treeNodePointer leaf);
        void insert(treeNodePointer, genericPointer);
        //This is the internal representation of the public version of 
        //tree_node_ptr search(T*) above.
        //The search algorithm used is Depth First Search.
        treeNodePointer search(treeNodePointer, genericPointer);
        //Searches the tree in a Left-to-Right traversal as the BST is deepened 
        //on each child before next sibling hence depth-first search algorithm.
        status inorderTraverse(treeNodePointer tree, status(*p_func)(T));
        //points to the first children of the tree structure
        treeNodePointer root_;
    }; //end of BinaryTree

    //Linked List implementation below
    //Example:
    //
    //  LinkedList<int> * list = new LinkedList<int>();
    //  LinkedList<int> list2;
    //  for (LinkedList<int> it = list->begin(); it != list->end(); ++it) {
    //     std::cout << *it << " ";
    //  }
    //
    //  list = *list;
    //
    //  for (auto it : l) {
    //        std::cout << it << " ";
    //  }

    template<typename T>
    class LinkedList : public std::iterator<std::input_iterator_tag, T> {
    public:
        //TODO copy constructor, operators, etc.

        LinkedList() :
        list_(nullptr), length_(0) {

        }

        LinkedList(const LinkedList<T>& other) :
        list_(other.list_), length_(other.length_) {
        }

        virtual ~LinkedList() {

        }

        inline bool empty(linkedListPointer listPointer) {
            return (listPointer == nullptr);
        }

        status traverse(void(*p_func)(T*)) {
            return traverse(this->operator->(), p_func);
        }

        status insert(T* data) {
            return append((genericPointer) data);
        }

        inline void adjLength() {
            this->length_ -= 1;
        }

        inline int getLength() const {
            return length_;
        }

        //TODO after implementing a sorted list then use binary search.

        //operator ++ moves to the next list node

        LinkedList<T>& operator++() {

            //std::cout << "tets: " << (this->list_root->next)->next << std::endl;

            this->setListRoot(this->operator->());

            this->adjLength();
            return *this;
        };

        LinkedList<T>& operator++(T x) {

            // std::cout << "tets: " << (this->list_root->next)->next << std::endl;

            LinkedList<T>& a = *this;

            this->setListRoot(this->operator->());

            this->adjLength();
            return a;
        }

        LinkedList<T>& begin() {//C++11
            return *this;
        }

        LinkedList<T>& end() {//C++11
            //empty list
            //std::cout << "? " << this->getLength() << std::endl;
            this->setListRoot((this->list_ - this->getLength()));

            return *this;
        }

        // returns the current data 

        inline T & operator*() {
            return *(T*) list_->datapointer;
        }

        inline linkedListPointer operator->() const {
            return this->list_->next;
        }

        inline bool operator==(const LinkedList<T>& rhs) {
            return this->operator->() == rhs.operator->();
        }

        inline bool operator!=(const LinkedList<T>& rhs) {
            return (this->operator->() != rhs.operator->());
        }

    private:
        void setListRoot(linkedListPointer);
        status traverse(linkedListPointer, void(*p_func)(T*));
        status allocateLinkedListNode(linkedListPointer*, genericPointer);
        status append(genericPointer);
        //points to the first node of the list
        linkedListPointer list_;
        //the number of list-nodes created
        int length_;
    }; //end of LinkedList

    //Doubly Linked List using Binary Search Algorithm when the list is sorted.
    //Example
    //
    //DoublyLinkedList<int>* list = new DoublyLinkedList<int>(); 
    // OR
    //DoublyLinkedList<int>* list = new DoublyLinkedList<int>(dataStructures::StructureState::SORTED);
    //
    //for (auto &x : xrry) {
    //    list->insert(&x);
    //}
    //list->traverse(print); //ie. the function to operate on the data

    template<typename T>
    class DoublyLinkedList {
    public:

        DoublyLinkedList(StructureState s = StructureState::UNSORTED)
        : list_(nullptr), state_(s), length_(0) {
            //initialization
        };

        status traverse(void(*p_func)(T*)) {
            return traverse(list_, p_func);
        }

        inline void insert(T* data) {
            if (state_ == StructureState::UNSORTED) {
                (void) unsortedInsert((genericPointer) data);
            } else {
                (void) sortedInsert((genericPointer) data);
            }
        }

        virtual ~DoublyLinkedList() {
        }

    private:

        inline bool emptyList(doublyLinkedListPointer listPointer) {
            return (listPointer == nullptr);
        }

        inline void freeNode(doublyLinkedListPointer listPointer) {
            delete listPointer;
            listPointer = nullptr;
        }

        status traverse(doublyLinkedListPointer, void(*p_func)(T*));
        status unsortedInsert(genericPointer);
        status sortedInsert(genericPointer);
        status allocateDoublyLinkedListNode(doublyLinkedListPointer*, genericPointer);
        doublyLinkedListPointer list_;
        StructureState state_;
        int length_;
    }; //end of DoublyLinkedList

}// namespace datastructures

#include "BinarySearchTree_Impl.h"
#include "LinkedList_Impl.h"
#include "DoublyLinkedList_Impl.h"

#endif	/* DATASTRUCTURES_H */

