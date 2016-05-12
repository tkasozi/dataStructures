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

typedef void * genericPointer;
typedef struct TreeNode TreeNode, * treeNodePointer;
typedef struct LinkedListNode LinkedListNode, * linkedListPointer;
typedef struct DoublyLinkedNode DoublyLinkedNode, * doublyLinkedListPointer;

struct TreeNode {
    int key;
    genericPointer datapointer;
    TreeNode* left;
    TreeNode* right;
};

struct LinkedListNode {
    genericPointer datapointer;
    LinkedListNode* next;
};

struct DoublyLinkedNode {
    int index;
    genericPointer datapointer;
    DoublyLinkedNode* next;
    DoublyLinkedNode* previous;
};

#endif	/* GLOBALS_H */

