#ifndef IO_DEVICE_CPP
#define IO_DEVICE_CPP

#include "IODevice.h"
#include <list>
#include <iostream>
#include "Comparator.h"

using namespace std;

void Printer::printIOQueue(){
    for(list<PCB>::const_iterator ci = printerQueue.begin(); ci != printerQueue.end(); 
            ++ci){
        cout << ci -> getPriority() << " ";
    }
	cout << endl;
}

void Printer::pushToQueue(PCB newEntry){
    printerQueue.push_back(newEntry);
}

PCB Printer::getTop(){
	return printerQueue.front();
}

void Printer::removeTop(){
	printerQueue.pop_front();
}

void Disk::printIOQueue(){
    for(list<PCB>::const_iterator ci = diskQueue.begin(); ci != diskQueue.end();
            ++ci){
        cout << ci -> getPriority() << " ";
	}
	cout << endl;
}

void Disk::pushToQueue(PCB newEntry){
    diskQueue.push_back(newEntry);
}

PCB Disk::getTop(){
	return diskQueue.front();
}

void Disk::removeTop(){
	diskQueue.pop_front();
}


#endif
