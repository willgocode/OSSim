#ifndef IO_DEVICE_CPP
#define IO_DEVICE_CPP

#include "IODevice.h"
#include <list>
#include <iostream>
#include "Comparator.h"
#include "helpers.h"

using namespace std;

void Printer::printIOQueue(){
    cout << "PID: " << inPrintMode[0].getProcessID() << ", File Name: " << 
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
	if(totalNumberPrintTasks == 1){
		getNextFromQueue();
	}
}

void Printer::getNextFromQueue(){
	inPrintMode[0] = printerQueue.front();
	printerQueue.pop_front();
}

void Printer::displayMemStruct(){
	if(totalNumberPrintTasks != 0){
		cout << "Process " << inPrintMode[0].getProcessID() << " begins at position: " 
			<< inPrintMode[0].getMemBegin() << ", and ends at position: " 
			<< inPrintMode[0].getMemEnd() << 
			". Process size is: " << inPrintMode[0].getProcessSize() << "." << endl;
	}
	else{
		cout << "Print queue empty." << endl;
		return;
	}
	for(auto it = printerQueue.begin(); it != printerQueue.end() && 
			it -> getProcessID() != 0 ; it++){
		cout << "Process " << it -> getProcessID() << " begins at position: " 
        << it -> getMemBegin() << ", and ends at position: " 
        << it -> getMemEnd() <<
        ". Process size is: " << it -> getProcessSize() << "." << endl;
	}
	cout << endl;
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
	if(totalNumberDiskTasks == 1){
		getNextFromQueue();
	}
}

void Disk::getNextFromQueue(){
	inDiskMode[0] = diskQueue.front();
	diskQueue.pop_front();
}

void Disk::displayMemStruct(){
	if(totalNumberDiskTasks != 0){
		cout << "Process " << inDiskMode[0].getProcessID() << " begins at position: " 
			<< inDiskMode[0].getMemBegin() << ", and ends at position: " 
			<< inDiskMode[0].getMemEnd() << 
			". Process size is: " << inDiskMode[0].getProcessSize() << "." << endl;
	}
	else{
		cout << "Disk list empty." << endl;
		return;
	}
	for(auto it = diskQueue.begin(); it != diskQueue.end() && it -> getProcessID() != 0; 
			it++){
		cout << "Process " << it -> getProcessID() << " begins at position: " 
        << it -> getMemBegin() << ", and ends at position: " 
        << it -> getMemEnd() << ". Process size is: " << 
		it -> getProcessSize() << "." << endl;
	}
	cout << endl;
}
#endif
