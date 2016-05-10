#ifndef MEMORY_H
#define MEMORY_H

#include <iostream>
#include "SortedLinkedList.h"
#include "MemComparator.h"
#include "GapBlock.h"

using namespace std;

class Memory{
    public:
        Memory(int memSize) : itemsInMem(0) {
            GapBlock initial(0, memSize - 1, memSize);
            gapList.insert(initial);
        }

		GapBlock getLargest() const { return gapList.front(); }
        bool insertToMem(unsigned int processSize);
        void displayMem() { gapList.displayMem(); }
        bool removeFromMem();
		unsigned int getBeginning();
	private:
        SortedLinkedList<GapBlock, MemComparator<GapBlock>> gapList;
        int itemsInMem;
};

#endif
