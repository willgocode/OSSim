#ifndef CPU_H
#define CPU_H

#include <iostream>
#include "SortedLinkedList.h"
#include "PCB.h"
#include "Comparator.h"

using namespace std;

class CPU{
    public:
        CPU() : nextPID(0) {}
        void addToCPUQueue(PCB aProcess);
        void removeFromCPUQueue();
        void printQueuedPID();
        void runProcess();
    private:
        PCB inCPU[1];
        unsigned int nextPID;
        SortedLinkedList<PCB, Comparator<PCB>> cpuQueue;                
};

#endif
