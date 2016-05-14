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
        cout << "CPU ready queue is empty." << endl;
        return;
    }
    auto it = linkedList.begin();
	cout << "PID: " << it -> getProcessID();
	for (++it; it != linkedList.end(); ++it){
        if(it -> getProcessID() == 0){
			cout << "" << endl;
		}
		else{
			cout << ", PID: " << it -> getProcessID();
    	}
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

template<class T, class Comparator>
void SortedLinkedList<T, Comparator>::displayMem() const {
	auto it = linkedList.begin();
	if(it -> getProcessID() == 0 && next(it, 1) -> getProcessID() == 0){
		cout << "Memory is empty." << endl;
	}
	if(it -> getProcessID() != 0){
		cout << "PID: " << it -> getProcessID() << " Begins from: " << it -> getBegin()
			<< " to: " << it -> getEnd() << endl;
	}
	for(++it; it != linkedList.end() && it -> getProcessID() != 0; ++it){
		cout << "PID: " << it -> getProcessID() << " Begins from: " << it -> getBegin() 
			<< " to: " << it -> getEnd() << endl;
	}
}

template<class T, class Comparator>
bool SortedLinkedList<T, Comparator>::memInsert(T &newData, unsigned int maxMem){
	for(auto it = linkedList.begin(); it != linkedList.end(); it++){
		unsigned int gap = next(it, 1) -> getBegin() - it -> getEnd();
		unsigned int maxGap = 0;
		if(gap > maxGap && newData.getSize() <= gap && next(it, 1) != linkedList.end()){
			maxGap = gap;
			newData.setBegin(it -> getEnd() + 1);
			newData.setEnd(newData.getBegin() + newData.getSize() - 1);
		}
	}
	if(newData.getEnd() == maxMem - 1){
		linkedList.pop_back();
	}
	if(newData.getEnd() != 0){
		insert(newData);
		return true;
	}
	else{
		cout << "No space in memory for process." << endl;
	}
	return false;
}

template<class T, class Comparator>
void SortedLinkedList<T, Comparator>::removeProcess(int pid, unsigned int memSize){
	for(auto it = linkedList.begin(); it != linkedList.end(); it++){
		if(it -> getProcessID() == pid){
			if(it == linkedList.begin()){
				T newData(0, 0, 0, 0);
				insert(newData);
			}
			if(it -> getEnd() == memSize - 1){
				T newData(0, memSize - 1, memSize - 1, 0);
				insert(newData);
			}
			linkedList.erase(it);
		}
	}
}
#endif
