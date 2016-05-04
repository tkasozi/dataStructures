/* 
 * File:   data_struct.h
 * Author: Talik Kasozi <projectxyz.org>
 *
 * Created on April 27, 2016, 6:44 PM
 */

#ifndef DATA_STRUCT_H
#define	DATA_STRUCT_H
#include  "globals.h"
#include <iterator>

namespace dataStructures {

    //Binary Search Tree template 
    //Example:
    //btree<int>* binarytree = new btree<int>();
    //binarytree->insert(&b);
    //delete binarytree;

    template<typename T>
    class btree {
    public:

        //using this->root because of recursion to search and insert in
        //a tree

        btree() : root(nullptr) {
        };

        virtual ~btree() {
            destroy_tree(this->getRoot());
        }

        inline bool empty(tree_node_ptr leaf) {
            return (leaf == nullptr);
        }

        //Applies the provided function to data in a sorted/increasing order.
        //This is achieved with the inorder_traverse()

        status traverse(status(*p_func)(T)) {
            return inorder_traverse(this->getRoot(), p_func);
        }

        //Returns a pointer to the target node a nullptr otherwise. 
        //It is the client's responsibility to delete the node after 
        //use or clean up will be done at the end of the program. 
        //The client must not use this function once the Tree has been destroyed. 
        //The internal representation is hidden to prevent 
        //1. Too much casting ie search((string*)data), search((int*)data) ...
        //2. To allow encapsulation. ie. the Root of the tree can only be 
        //modified from with in the class or by those related.

        tree_node_ptr search(T* data) {
            return search(this->getRoot(), (generic_ptr) data);
        }

        void insert(T* data) {

            if (!empty(this->getRoot())) {
                insert(this->getRoot(), (generic_ptr) data);
            } else {
                tree_node_ptr temp = new tree_node;
                temp->datapointer = (generic_ptr) data;
                temp->left = nullptr;
                temp->right = nullptr;

                this->setRoot(temp);
            }
        }

        inline tree_node_ptr getRoot() const {
            return root;
        }
    private:
        void setRoot(tree_node_ptr root);
        void destroy_tree(tree_node_ptr leaf);
        void insert(tree_node_ptr, generic_ptr);
        //This is the internal representation of the public version of 
        //tree_node_ptr search(T*) above.
        //The search algorithm used is Depth First Search.
        tree_node_ptr search(tree_node_ptr, generic_ptr);
        //Searches the tree in a Left-to-Right traversal as the BST is deepened 
        //on each child before next sibling hence depth-first search algorithm.
        status inorder_traverse(tree_node_ptr tree, status(*p_func)(T));
        //points to the first children of the tree structure
        tree_node_ptr root;
    };

    //Linked List template 
    //Example:
    //btree<int>* list = new btree<int>();
    //list->insert(&b);
    //delete list;

    template<typename T>
    class linked_list : public std::iterator<std::input_iterator_tag, T> {
    public:
        //TODO copy constructor, operators, etc.

        linked_list() :
        list_root(nullptr), length(0) {
        }

        virtual ~linked_list() {

        }

        linked_list<T>& operator++() {
            ++this->getList_root();
            return *this;
        };

        inline bool empty(list_node_ptr node) {
            return (node == nullptr);
        }

        status traverse(void(*p_func)(T*)) {
            return traverse(this->getList_root(), p_func);
        }

        status insert(T* data) {
            return append((generic_ptr) data);
        }

        inline list_node_ptr getList_root() const {
            return list_root;
        }

        inline int getLength() const {
            return length;
        }


    private:
        void setList_root(list_node_ptr);
        status traverse(list_node_ptr, void(*p_func)(T*));
        status allocate_node(list_node_ptr*, generic_ptr);
        status append(generic_ptr);
        //points to the first node of the list
        list_node_ptr list_root;
        //the number of list-nodes created
        int length;
    };

}// namespace dataStructures

#endif	/* DATA_STRUCT_H */

