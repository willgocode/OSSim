#ifndef CPU_H
#define CPU_H

#include <iostream>
#include "SortedLinkedList.h"
#include "PCB.h"
#include "Comparator.h"
#include "Memory.h"

using namespace std;

class CPU{
    public:
        CPU(unsigned int memSize) : nextPID(1), mainMemory(memSize){
			inCPU[0] = PCB();
		}

        void addToCPUQueue();
		void insertToCPUQueue(PCB newPCB);
        void insertFromQueue();
        void printQueuedPID();
        void terminateRunning();
		void printMemory(){ mainMemory.printMemory(); }
		PCB getRunning(){ return inCPU[0]; }
	private:
        PCB inCPU[1];
        unsigned int nextPID;
        SortedLinkedList<PCB, Comparator<PCB>> cpuQueue;                
		Memory mainMemory;
};

#endif
