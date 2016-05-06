#ifndef CPU_H
#define CPU_H

#include <iostream>
#include "SortedLinkedList.h"
#include "PCB.h"
#include "Comparator.h"

using namespace std;

class CPU{
    public:
        CPU() : nextPID(1) {
			inCPU[0] = PCB();
		}
        void addToCPUQueue();
        void insertFromQueue();
        void printQueuedPID();
        void terminateRunning();
    private:
        PCB inCPU[1];
        unsigned int nextPID;
        SortedLinkedList<PCB, Comparator<PCB>> cpuQueue;                
};

#endif
