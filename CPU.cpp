#ifndef CPU_CPP
#define CPU_CPP

#include <iostream>
#include "PCB.h"
#include "SortedLinkedList.h"
#include "CPU.h"

using namespace std;

void CPU::addToCPUQueue(PCB aProcess){
    aProcess.setProcessID(nextPID);
    nextPID++;
    cpuQueue.insert(aProcess);
}   

void CPU::printQueuedPID(){
    cpuQueue.display();
}

#endif
