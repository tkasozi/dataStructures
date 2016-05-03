/* 
 * File:   data_struct.h
 * Author: Talik Kasozi <projectxyz.org>
 *
 * Created on April 27, 2016, 6:44 PM
 */

#ifndef DATA_STRUCT_H
#define	DATA_STRUCT_H
#include "globals.h"
#include <iterator>

namespace data_struct {

    namespace btree {
        //Binary Search Tree template declared here

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

            bool empty(tree_node_ptr leaf) {
                return (leaf == nullptr);
            }

            status traverse(status(*p_func)(T)) {
                return inorder_traverse(this->getRoot(), p_func);
            }

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

            tree_node_ptr getRoot() const {
                return root;
            }
        private:
            tree_node_ptr root;
            void setRoot(tree_node_ptr root);
            void destroy_tree(tree_node_ptr leaf);
            void insert(tree_node_ptr, generic_ptr);
            tree_node_ptr search(tree_node_ptr, generic_ptr);
            status inorder_traverse(tree_node_ptr tree, status(*p_func)(T));
        };
    }

    namespace list_structs {

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

            bool empty(list_node_ptr node) {
                return (node == nullptr);
            }

            status traverse(void(*p_func)(T*)) {
                return traverse(this->getList_root(), p_func);
            }

            status insert(T* data) {
                return append((generic_ptr) data);
            }

            list_node_ptr getList_root() const {
                return list_root;
            }

            int getLength() const {
                return length;
            }


        private:
            void setList_root(list_node_ptr);
            status traverse(list_node_ptr, void(*p_func)(T*));
            status allocate_node(list_node_ptr*, generic_ptr);
            status append(generic_ptr);
            list_node_ptr list_root;
            int length;
        };
    }
}

#endif	/* DATA_STRUCT_H */

