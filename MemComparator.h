#ifndef MEM_COMPARATOR_H
#define MEM_COMPARATOR_H

#include <iostream>

using namespace std;

template<class T>
class MemComparator{
    public:
        bool operator()(T const & lhs, T const & rhs){
            return lhs.getSize() > rhs.getSize();
        }
};

#endif
