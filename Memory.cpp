#ifndef MEMORY_CPP
#define MEMORY_CPP

#include <iostream>
#include "Memory.h"
#include "SortedLinkedList.h"

using namespace std;

bool Memory::insertProcess(int pid, unsigned int newProcessSize){ 
    if(newProcessSize > memorySize){
		cout << "Process too large." << endl;
		return false;
	}
	auto temp = mainMemory.front();
	if(temp.getProcessID() == 0 && memorySize - 1 >= newProcessSize){ 
        Process frontProcess(pid, 0, newProcessSize - 1, newProcessSize); 
        mainMemory.pop_front(); 
        mainMemory.insert(frontProcess); 
		processesInMem++;
    	return true;
	} 
    else{ 
        Process newProcess(pid, 0, 0, newProcessSize); 
        if(mainMemory.memInsert(newProcess, memorySize)){
			return true;
		}
		processesInMem++;
    } 
	return false;
} 
 
void Memory::removeProcess(int pid){ 
    mainMemory.removeProcess(pid, memorySize); 
	processesInMem--;
}

#endif
