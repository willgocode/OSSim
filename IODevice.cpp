#ifndef IO_DEVICE_CPP
#define IO_DEVICE_CPP

#include "IODevice.h"
#include <list>
#include <iostream>
#include "Comparator.h"
#include "helpers.h"

using namespace std;

void Printer::printIOQueue(){
    cout << "Running PID: " << inPrintMode[0].getProcessID() << ", File Name: " << 
		inPrintMode[0].getFileName() << ", File Size: " << inPrintMode[0].getFileSize() << endl;
 
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
	
	if(inPrintMode[0].getProcessID() == 0){
		getNextFromQueue();
	}
}

void Printer::getNextFromQueue(){
	if(!printerQueue.empty()){
		cout << "Getting next from Queue." << endl;
		inPrintMode[0] = printerQueue.front();
		printerQueue.pop_front();
		totalNumberPrintTasks--;
	}
	else{
		cout << "Nothing in queue, setting current ID to 0." << endl;
		inPrintMode[0].setProcessID(0);
		totalNumberPrintTasks--;
	}
}

void Disk::printIOQueue(){
    cout << "PID: " << inDiskMode[0].getProcessID() << ", File Name: " << 
		inDiskMode[0].getFileName() << ", File Size: " << inDiskMode[0].getFileSize() << endl;
	
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
	if(inDiskMode[0].getProcessID() == 0){
		getNextFromQueue();
	}
}

void Disk::getNextFromQueue(){
	if(!diskQueue.empty()){
		inDiskMode[0] = diskQueue.front();
		diskQueue.pop_front();
	}
	else{
		inDiskMode[0].setProcessID(0);
	}
}

#endif
