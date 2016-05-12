/* 
 * File:   linked_list.h
 * 
 * This linked list appends on the front and on the back. 
 * Therefore, it's also the implementation of a QUEUE.
 * 
 * Author: Talik Kasozi <projectxyz.org>
 *
 * Created on April 28, 2016, 9:45 AM
 */

#ifdef DOUBLYLINKEDLIST_H
#error "LinkedList_Impl.h should only be included by DataStructures.h"
#endif

#ifndef LINKED_LIST_H
#define	LINKED_LIST_H

#include "globals.h"
#include "DataStructures.h"

//Definition of the linked_list functions is within the scope of the nameSpace.
namespace datastructures {
    //TODO search linked_list implementation 

    template <typename T>
    void LinkedList<T>::setListRoot(linkedListPointer listPointer) {
        this->list_ = listPointer;
    }

    template <typename T>
    status LinkedList<T>::append(genericPointer genericData) {
        linkedListPointer L;

        if (allocateLinkedListNode(&L, genericData) == ERROR) {
            return ERROR;
        }

        if (empty(this->list_)) {
            this->setListRoot(L);
        } else {
            (L)->next = this->list_;
            this->setListRoot(L);
        }
        
        this->length_++;
        return OK;
    }

    template <typename T>
    status LinkedList<T>::allocateLinkedListNode(linkedListPointer* ptr, genericPointer data) {
        linkedListPointer L = new LinkedListNode;

        if (empty(L)) {
            return ERROR;
        }

        L->datapointer = data;
        L->next = nullptr;

        *ptr = L;
        return OK;
    }

    template <typename T>
    status LinkedList<T>::traverse(linkedListPointer ptr, void(*p_func)(T*)) {
        if (empty(ptr)) {
            return OK;
        }

        (p_func) ((T*) ptr->datapointer);

        return traverse(ptr->next, p_func);
    }
}// namespace dataStructures

#endif	/* LINKED_LIST_H */

