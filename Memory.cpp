#ifndef MEMORY_CPP
#define MEMORY_CPP

#include "Memory.h"
#include "SortedLinkedList.h"
#include <iostream>

using namespace std;

bool Memory::insertToMem(unsigned int processSize){
    GapBlock newBlock = gapList.pop_front();
    if(newBlock.getSize() >= processSize){
        unsigned int currentSize = newBlock.getSize();
        newBlock.setSize(currentSize - processSize);
        newBlock.setBlockBegin(processSize + newBlock.getBegin());
        gapList.insert(newBlock);
        gapList.displayMem();
        return true;
    }
    cout << "Memory is full." << endl;
    return false;
}

#endif
