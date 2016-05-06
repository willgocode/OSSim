#ifndef CPU_CPP
#define CPU_CPP

#include <iostream>
#include "PCB.h"
#include "SortedLinkedList.h"
#include "CPU.h"
#include "helpers.h"

using namespace std;

void CPU::addToCPUQueue(){
	unsigned int tempSize;
    int tempPriority;

    cin.clear();
	cout << "Adding process:" << endl;
    cout << "Enter size of program: " ;
    cin >> tempSize;
    inputManager(tempSize);
    
	//Insert mem check here
    
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
	if(cpuQueue.front().getPriority() < inCPU[0].getPriority()){
		cpuQueue.insert(inCPU[0]);
		insertFromQueue();
	}

}   

void CPU::insertFromQueue(){
	inCPU[0] = cpuQueue.pop_front();
	cout << "Now running process: " << inCPU[0].getProcessID() << endl;
}

void CPU::printQueuedPID(){
    cpuQueue.display();
}

void CPU::terminateRunning(){
	cout << "Terminating process: " << inCPU[0].getProcessID() << endl;
	inCPU[0] = NULL;
	insertFromQueue();
}
#endif
