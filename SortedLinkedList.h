#ifndef SORTED_LINKED_LIST_H_
#define SORTED_LINKED_LIST_H_

//THIS CODE WAS OBTAINED FROM ANOTHER RESOURCE. I DID NOT WRITE THIS.
//OBTAINED FROM CSCI 235 CLASS BY SIMON AYZMAN

#include <iostream>
#include <list>
#include <algorithm>

using namespace std;

template<class T, class Comparator = less<T>>
class SortedLinkedList{
	public:
		SortedLinkedList() {}

		unsigned int size() const { return (unsigned int) linkedList.size(); }
		bool empty() const { return linkedList.empty(); }

		T& front() { return linkedList.front(); }
		T& back() { return linkedList.back(); }
		const T& front() const { return linkedList.front(); }
		const T& back() const { return linkedList.back(); }

		T& pop_front() { T& data = front(); linkedList.pop_front(); return data; }
		T& pop_back() { T& data = back(); linkedList.pop_back(); return data; }

		void display() const;
		void displayMem() const;
		void clear() { linkedList.clear(); }
		T& at(unsigned int pos) { auto it = linkedList.begin(); 
			advance(it,pos); return *it; }
		const T& at(unsigned int pos) const { auto it = linkedList.begin(); 
			advance(it,pos); return *it; }
		void insert(const T& data);
		//bool insertToMem(unsigned int pSize);
		T& remove(unsigned int pos) { auto it = linkedList.begin();
			advance(it,pos); T& data = *it; linkedList.erase(it); return data; }
	private:
		list<T> linkedList;
};

#include "SortedLinkedList.cpp"

#endif
