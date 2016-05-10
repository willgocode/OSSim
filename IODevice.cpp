#ifndef IO_DEVICE_CPP
#define IO_DEVICE_CPP

#include "IODevice.h"
#include <list>
#include <iostream>
#include "Comparator.h"
#include "helpers.h"

using namespace std;

void Printer::printIOQueue(){
    for(list<PCB>::const_iterator ci = printerQueue.begin(); ci != printerQueue.end(); 
            ++ci){
        cout << "PID: " << ci -> getProcessID() << ", File Name: " << 
			ci -> getFileName() << ", File Size: " << ci -> getFileSize() << endl;
	}
}

void Printer::pushToQueue(PCB newEntry){
    cin.ignore();
	string fileName;
	unsigned int fileSize;
	cout << "Enter a file name: " ;
	getline(cin, fileName);
	newEntry.setFileName(fileName);

	cout << "Enter a file size: " ;
	cin >> fileSize;
	inputManager(fileSize);
	newEntry.setFileSize(fileSize);

	printerQueue.push_back(newEntry);
	totalNumberPrintTasks++;
	if(totalNumberPrintTasks == 1){
		getNextFromQueue();
	}
}

void Printer::getNextFromQueue(){
	inPrintMode[0] = printerQueue.front();
	printerQueue.pop_front();
}

void Disk::printIOQueue(){
    for(list<PCB>::const_iterator ci = diskQueue.begin(); ci != diskQueue.end();
            ++ci){
        cout << "PID: " << ci -> getProcessID() << ", File Name: " << 
			ci -> getFileName() << ", File Size: " << ci -> getFileSize() << endl;
	}
}

void Disk::pushToQueue(PCB newEntry){
    cin.ignore();
	string fileName;
    unsigned int fileSize;
    cout << "Enter a file name: " ;
    getline(cin, fileName);
    newEntry.setFileName(fileName);
    cin.clear();

    cout << "Enter a file size: " ;
    cin >> fileSize;
    inputManager(fileSize);
    newEntry.setFileSize(fileSize);

	diskQueue.push_back(newEntry);
	totalNumberDiskTasks++;
	if(totalNumberDiskTasks == 1){
		getNextFromQueue();
	}
}

void Disk::getNextFromQueue(){
	inDiskMode[0] = diskQueue.front();
	diskQueue.pop_front();
}

#endif
