#ifndef SORTED_LINKED_LIST_CPP_
#define SORTED_LINKED_LIST_CPP_

//THIS CODE WAS OBTAIEND FROM ANOTHER RESOURCE. I DID NOT WRITE THIS.
//OBTAINED FROM CSCI 235 CLASS BY SIMON AYZMAN

#include "SortedLinkedList.h"
#include <iostream>

using namespace std;

template<class T, class Comparator>
void SortedLinkedList<T, Comparator>::display() const{
    if (empty()){
        cout << "(empty)" << endl;
        return;
    }
    auto it = linkedList.begin();
    cout << it -> getProcessID();
    for (++it; it != linkedList.end(); ++it){
        cout << ", " << it -> getProcessID();
    }
    cout << endl;
}

template<class T, class Comparator>
void SortedLinkedList<T, Comparator>::insert(const T& data){
    if (empty()){
        linkedList.push_front(data);
        return;
    }
    Comparator comparator;
    auto it = linkedList.begin();
    for (; it != linkedList.end(); ++it){
        if (comparator(data,*it)){
            linkedList.insert(it, data);
            break;
        }
    }
    if(it == linkedList.end()){
        linkedList.insert(it, data);
    }
}

#endif
