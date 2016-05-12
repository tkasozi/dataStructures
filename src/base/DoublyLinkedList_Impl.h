/* 
 * File:   DoubleLinkedList.h
 * Author: Talik Kasozi <projectxyz.org>
 *
 * Created on May 11, 2016, 2:49 PM
 */

#ifndef DOUBLYLINKEDLIST_H
#define	DOUBLYLINKEDLIST_H

#include "globals.h"
#include "DataStructures.h"



namespace datastructures {

    template <typename T>
    status DoublyLinkedList<T>::sortedInsert(genericPointer genericData) {
        doublyLinkedListPointer L;

        return OK;
    }

    template <typename T>
    status DoublyLinkedList<T>::unsortedInsert(genericPointer genericData) {
        doublyLinkedListPointer L;

        if (allocateDoublyLinkedListNode(&L, genericData) == ERROR) {
            return ERROR;
        }

        if (emptyList(list_)) {
            //list->previous = list->next = nullptr;
        } else {
            L->next = list_;
            L->previous = list_->previous;
            list_->previous = L;

            if (L->previous != NULL)
                (L->previous)->next = L;

        }

        list_ = L;
        ++length_;

        return OK;
    }

    template <typename T>
    status DoublyLinkedList<T>::allocateDoublyLinkedListNode(doublyLinkedListPointer* listPointer, genericPointer genericData) {
        doublyLinkedListPointer node = new DoublyLinkedNode;

        if (node == nullptr) {
            return ERROR;
        }

        *listPointer = node;

        node->index = length_ + 1;

        node->datapointer = genericData;
        node->next = nullptr;
        node->previous = nullptr;

        return OK;
    }

    template <typename T>
    status DoublyLinkedList<T>::traverse(doublyLinkedListPointer listPointer, void(*p_func)(T*)) {
        if (emptyList(listPointer)) {
            return OK;
        }

        (p_func) ((T*) listPointer->datapointer);

        return traverse(listPointer->next, p_func);
    }
}

#endif	/* DOUBLYLINKEDLIST_H */

