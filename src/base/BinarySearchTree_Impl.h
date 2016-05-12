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

#ifndef BINARY_SEARCH_TREE_H
#define	BINARY_SEARCH_TREE_H

#include "globals.h"
#include "DataStructures.h"

//Definition of the bTree functions is within the scope of the nameSpace.
namespace datastructures {

    template<typename T>
    void BinaryTree<T>::setRoot(treeNodePointer root) {
        this->root_ = root;
    }

    template <typename T>
    void BinaryTree<T>::insert(treeNodePointer leaf, genericPointer data) {

        if (*(T*) data < *(T*) leaf->datapointer) {//left branch
            if (empty(leaf->left)) {

                treeNodePointer temp = new TreeNode;

                temp->datapointer = data;
                temp->left = nullptr;
                temp->right = nullptr;

                leaf->left = temp;
            } else {
                insert(leaf->left, data);
            }

        } else if (*(T*) data > *(T*) leaf->datapointer) {//right branch

            if (empty(leaf->right)) {

                treeNodePointer temp = new TreeNode;

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
    status BinaryTree<T>::inorderTraverse(treeNodePointer node, status(*p_func)(T)) {
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
        rc = inorderTraverse(node->left, p_func);

        if (rc == OK) {
            rc = (*p_func)(*(T*) node->datapointer);
        }

        if (rc == OK) {
            rc = inorderTraverse(node->right, p_func);
        }

        return rc;
    }

    //option to use data before destroying the tree.

    template <typename T>
    void BinaryTree<T>::destroyTree(treeNodePointer leaf) {

        if (!empty(leaf)) {
            destroyTree(leaf->left);
            destroyTree(leaf->right);

            delete leaf;
        }
    }

    template <typename T>
    treeNodePointer BinaryTree<T>::search(treeNodePointer leaf, genericPointer data) {
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
} // namespace dataStructures

#endif	/* BST_H */