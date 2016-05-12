#ifndef MEMORY_H
#define MEMORY_H

#include <iostream>
#include "SortedLinkedList.h"

using namespace std;

class Memory{
    public:
        Memory(int memSz = 0) : memorySize(memSz), processesInMem(0){
            Process begin(0, 0, 0, 0);
            Process end(0, memorySize - 1, memorySize - 1, 0);
            mainMemory.insert(begin);
            mainMemory.insert(end);
        }

        class Process{
            public:
                Process(int newPID = 0, unsigned int newBegin= 0,
                        unsigned int newEnd = 0, unsigned int newSize = 0):
                    pid(newPID), begin(newBegin), end(newEnd), size(newSize) {}
                unsigned int getBegin() const { return begin; }
                unsigned int getEnd() const { return end; }
                unsigned int getSize() const { return size; }
                int getProcessID() const { return pid; }

                void setBegin(unsigned int newBegin){ begin = newBegin; }
                void setEnd(unsigned int newEnd) { end = newEnd; }
                void setSize(unsigned int newSize) { size = newSize; }
                void setPID(int newPID) { pid = newPID; }
            private:
                int pid;
                unsigned int begin;
                unsigned int end;
                unsigned int size;
        };

        void printMemory() { mainMemory.displayMem(); }
        bool insertProcess(int pid, unsigned int newProcessSize);
        void removeProcess(int pid);
    private:
        unsigned int memorySize;
        int processesInMem;
        SortedLinkedList<Process, MemComparator<Process>> mainMemory;
};

#endif
