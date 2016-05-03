/* 
 * File:   BST.h Binary Search Tree
 * 
 * TO use this template on most data types, please remember to override the
 * > < == operators;
 *  
 * Author: Talik Kasozi <projectxyz.org>
 *
 * Created on April 27, 2016, 3:19 PM
 */

#ifndef BST_H
#define	BST_H

#include "data_struct.h"

using namespace data_struct::btree; //btree template,

template<typename T>
void btree<T>::setRoot(tree_node_ptr root) {
    this->root = root;
}

template <typename T>
void btree<T>::insert(tree_node_ptr leaf, generic_ptr data) {

    if (*(T*) data < *(T*) leaf->datapointer) {//left branch
        if (empty(leaf->left)) {

            tree_node_ptr temp = new tree_node;

            temp->datapointer = data;
            temp->left = nullptr;
            temp->right = nullptr;

            leaf->left = temp;
        } else {
            insert(leaf->left, data);
        }

    } else if (*(T*) data > *(T*) leaf->datapointer) {//right branch

        if (empty(leaf->right)) {

            tree_node_ptr temp = new tree_node;

            temp->datapointer = data;
            temp->left = nullptr;
            temp->right = nullptr;

            leaf->right = temp;
        } else {
            insert(leaf->right, data);
        }
    } else {
        //accept only unique data.
    }
}

//in-order traverse

template <typename T>
status btree<T>::inorder_traverse(tree_node_ptr node, status(*p_func)(T)) {
    status rc;

    if (empty(node)) {
        return OK;
    }

    //pre-order
    //    rc = (*p_func)(*(T*) node->datapointer);
    //
    //    if (rc == OK) {
    //        rc = inorder_traverse(node->left, p_func);
    //    }
    rc = inorder_traverse(node->left, p_func);

    if (rc == OK) {
        rc = (*p_func)(*(T*) node->datapointer);
    }

    if (rc == OK) {
        rc = inorder_traverse(node->right, p_func);
    }

    return rc;
}

//option to use data before destroying the tree.

template <typename T>
void btree<T>::destroy_tree(tree_node_ptr leaf) {

    if (!empty(leaf)) {
        destroy_tree(leaf->left);
        destroy_tree(leaf->right);

        delete leaf;
    }
}

template <typename T>
tree_node_ptr btree<T>::search(tree_node_ptr leaf, generic_ptr data) {
    if (empty(leaf)) {
        return nullptr;
    }
    if (*(T*) data < *(T*) leaf->datapointer) {
        return search(leaf->left, data);
    } else if (*(T*) data > *(T*) leaf->datapointer) {
        return search(leaf->right, data);
    } else {
        return leaf;
    }
}
#endif	/* BST_H */