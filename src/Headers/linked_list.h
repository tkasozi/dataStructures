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

#ifndef LINKED_LIST_H
#define	LINKED_LIST_H
#include "data_struct.h"

using namespace data_struct::list_structs;

//TODO search linked_list implementation 

template <typename T>
void linked_list<T>::setList_root(list_node_ptr lst) {
    this->list_root = lst;
}

template <typename T>
status linked_list<T>::append(generic_ptr data) {
    list_node_ptr L;

    if (allocate_node(&L, data) == ERROR) {
        return ERROR;
    }

    if (empty(this->list_root)) {
        this->setList_root(L);
    } else {
        (L)->next = this->list_root;
        this->setList_root(L);
    }

    this->length++;
    return OK;
}

template <typename T>
status linked_list<T>::allocate_node(list_node_ptr* ptr, generic_ptr data) {
    list_node_ptr L = new list_node;

    if (empty(L)) {
        return ERROR;
    }

    L->datapointer = data;
    L->next = nullptr;

    *ptr = L;
    return OK;
}

template <typename T>
status linked_list<T>::traverse(list_node_ptr ptr, void(*p_func)(T*)) {
    if (empty(ptr)) {
        return OK;
    }

    (p_func) ((T*) ptr->datapointer);

    return traverse(ptr->next, p_func);
}
#endif	/* LINKED_LIST_H */

