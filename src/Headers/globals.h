/* 
 * File:   globals.h
 * Author: Talik Kasozi <projectxyz.org>
 *
 * Created on April 27, 2016, 2:40 PM
 */

#ifndef GLOBALS_H
#define	GLOBALS_H

enum status {
    OK, ERROR
};

typedef void * generic_ptr;
typedef struct tree_node tree_node, * tree_node_ptr;
typedef struct list_node list_node, * list_node_ptr;
typedef struct double_linked_node double_linked_node, * double_linked_node_ptr;

struct tree_node {
    int key;
    generic_ptr datapointer;
    tree_node* left;
    tree_node* right;
};

struct list_node {
    generic_ptr datapointer;
    list_node* next;
};

struct double_linked_node {
    generic_ptr datapointer;
    double_linked_node* next;
    double_linked_node* previous;
};

#endif	/* GLOBALS_H */

