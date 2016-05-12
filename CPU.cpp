#ifndef CPU_CPP
#define CPU_CPP

#include <iostream>
#include "PCB.h"
#include "SortedLinkedList.h"
#include "CPU.h"
#include "helpers.h"
#include "Memory.h"

using namespace std;

void CPU::addToCPUQueue(){
	unsigned int tempSize;
    int tempPriority;

    cin.clear();
	cout << "Adding process." << endl;
    cout << "Enter size of program: " ;
    cin >> tempSize;
    inputManager(tempSize);

	if(mainMemory.insertProcess(nextPID, tempSize)){
		cin.clear();
		cout << "Enter priority of program: ";
		cin >> tempPriority;
		inputManager(tempPriority);
		cin.clear();
		
		PCB aProcess(tempSize, tempPriority);
		aProcess.setProcessID(nextPID);
		nextPID++;
		cpuQueue.insert(aProcess);

		cout << "New process added to CPU Queue." << endl;
	}	
	if(cpuQueue.front().getPriority() < inCPU[0].getPriority()){
		cpuQueue.insert(inCPU[0]);
		insertFromQueue();
	}
	else{
		cout << "Currently running: " << inCPU[0].getProcessID() << endl;
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
	mainMemory.removeProcess(inCPU[0].getProcessID());
	inCPU[0] = NULL;
	insertFromQueue();
}

#endif
