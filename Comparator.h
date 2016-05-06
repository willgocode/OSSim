#ifndef COMPARATOR_H
#define COMPARATOR_H

#include "IODevice.h"

using namespace std;

template<class T>
class Comparator{
	public:
		bool operator()(T const & lhs, T const & rhs){
			return lhs.getPriority() < rhs.getPriority();
		}
};

#endif
