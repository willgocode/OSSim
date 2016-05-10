#ifndef GAP_BLOCK_H
#define GAP_BLOCK_H

#include <iostream>

using namespace std;

class GapBlock{
	public:
		GapBlock(int x = 0, int y = 0, int z = 0) :
			 begin(x), end(y), size(z) {}

		void setBlockBegin(unsigned int newBegin) { begin = newBegin; }
		void setBlockEnd(unsigned int newEnd) { end = newEnd; }
		void setSize(unsigned int newSize) { size = newSize; }

		unsigned int getBegin() const { return begin; }
		unsigned int getEnd() const { return end; }
		unsigned int getSize() const { return size; }
	private:
		unsigned int begin;
		unsigned int end;
		unsigned int size;
};

#endif

