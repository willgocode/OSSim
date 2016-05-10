#ifndef CPU_CPP
#define CPU_CPP

#include <iostream>
#include "PCB.h"
#include "SortedLinkedList.h"
#include "CPU.h"
#include "helpers.h"
#include "GapBlock.h"

using namespace std;

void CPU::addToCPUQueue(){
	unsigned int tempSize;
    int tempPriority;

    cin.clear();
	cout << "Adding process." << endl;
    cout << "Enter size of program: " ;
    cin >> tempSize;
    inputManager(tempSize);
    
	GapBlock tempBlock = memList.getLargest();
	if(memList.insertToMem(tempSize)){	
		cin.clear();
		cout << "Enter priority of program: ";
		cin >> tempPriority;
		inputManager(tempPriority);
		cin.clear();
		
		PCB aProcess(tempSize, tempPriority);
		aProcess.setMemBegin(tempBlock.getBegin());
		aProcess.setMemEnd(tempSize-1 + tempBlock.getBegin());
		aProcess.setProcessID(nextPID);
		nextPID++;
		cpuQueue.insert(aProcess);

		cout << "New process added to CPU Queue." << endl;
		if(cpuQueue.front().getPriority() < inCPU[0].getPriority()){
			cpuQueue.insert(inCPU[0]);
			insertFromQueue();
		}
		else{
			cout << "Currently running: " << inCPU[0].getProcessID() << endl;
		}
	}
}   

void CPU::insertToCPUQueue(PCB newPCB){
	cpuQueue.insert(newPCB);
}

void CPU::insertFromQueue(){
	inCPU[0] = cpuQueue.pop_front();
	if(inCPU[0].getProcessID() == 0){
		cout << "Now running process: Nothing." << endl;
	}
	else{
		cout << "Now running process: " << inCPU[0].getProcessID() << endl;
	}
}

void CPU::printQueuedPID(){
    cpuQueue.display();
}

void CPU::terminateRunning(){
	cout << "Terminating process: " << inCPU[0].getProcessID() << endl;
	unsigned int begin = inCPU[0].getMemBegin();
	unsigned int end = inCPU[0].getMemEnd();
	unsigned int size = inCPU[0].getProcessSize();

	GapBlock newBlock(begin, end, size);
	memList.insertGapList(newBlock);

	inCPU[0] = NULL;
	insertFromQueue();
}

void CPU::displayMemStructure(){
	cout << "Process " << inCPU[0].getProcessID() << " begins at position: "
        << inCPU[0].getMemBegin() << ", and ends at position: "
        << inCPU[0].getMemEnd() <<
        ". Process size is: " << inCPU[0].getProcessSize() << "." << endl;
	cpuQueue.displayMemStructure();
}
#endif
