#ifndef OPERATING_SYSTEM_CPP
#define OPERATING_SYSTEM_CPP

#include <iostream>
#include <vector>
#include "OperatingSystem.h"
#include "helpers.h"
#include "PCB.h"

using namespace std;

bool OperatingSystem::validInput(string userInput){
    if(userInput != "S" && userInput != "t" && userInput != "A" 
            && userInput[0] != 'p' && userInput[0] != 'd' &&
            userInput[0] != 'P' && userInput[0] != 'D' &&
			userInput != "h" && userInput != "exit"){
		return false;
    }
	if(userInput == "exit"){
			inEnvironment = false;
	}
	if(userInput == "h"){
		cout << "Recognized commands: A, d(number), p(number), D(number), P(number), S, exit."
			<< endl;
	}
    return true;
}

bool OperatingSystem::validSnapshotInput(char userSnapshotInput){
    if(userSnapshotInput != 'i' && userSnapshotInput != 'm' &&
            userSnapshotInput != 'r'){
        return false;
    }
    return true;
}

void OperatingSystem::insertPrinterTask(int printerPosition,
        string fileName, unsigned int fileSize, PCB newPCB){
    newPCB.setFileName(fileName);
    newPCB.setFileSize(fileSize);
    printerList[printerPosition].pushToQueue(newPCB);
}

void OperatingSystem::insertDiskTask(int diskPosition, string fileName,
        unsigned int fileSize, PCB newPCB){
    newPCB.setFileName(fileName);
    newPCB.setFileSize(fileSize);
    diskList[diskPosition].pushToQueue(newPCB);
}

void OperatingSystem::printPrinterQueue(){
    for(int i = 0; i < numberOfPrinters ; ++i){
		auto temp = printerList[i].getCurrent();
        if(!printerList[i].isEmpty() || temp.getProcessID() != 0){
			cout << "Queue for Printer " << i+1 << ": " << endl;
            printerList[i].printIOQueue();
        }
    }
}

void OperatingSystem::printDiskQueue(){
    for(int i = 0; i < numberOfDisks ; ++i){
		auto temp = diskList[i].getCurrent();
        if(!diskList[i].isEmpty() || temp.getProcessID() != 0){
			cout << "Queue for Disk " << i+1 << ": " << endl;
			diskList[i].printIOQueue();
        }
    }
}

void OperatingSystem::bootOS(){
	while(inEnvironment == true){
		string command;
		cout << "Enter a command. Type h for help." << endl;
		cin >> command;
		
		if(!validInput(command)){
			cout << "Unrecognized command." << endl;
		}	
		
		if(command == "A"){
			processor.addToCPUQueue();
			numberOfProcesses++;
			numberInCPU++;
		}
				
		else if(command[0] == 'd' && isdigit(command[1])){
			if(numberInCPU < 1){
				cout << "There is no process running." << endl;
			}
			else{
				int whichDisk = command[1] - 48;
				if(whichDisk > numberOfDisks){
					cout << "Disk does not exist." << endl;
				}
				else{
					cout << "Moving to current process to Disk " << whichDisk << endl;
					diskList[whichDisk-1].pushToQueue(processor.getRunning());
					numberInCPU--;
					processor.insertFromQueue();
				}
			}
		}


		else if(command[0] == 'p' && isdigit(command[1])){
			if(numberInCPU < 1){
				cout << "There is no process running." << endl;
			}
			else{
				int whichPrint = command[1] - 48;
				if(whichPrint > numberOfPrinters){
					cout << "Printer does not exist." << endl;
				}
				else{
					cout << "Moving current process to Printer " << whichPrint << endl;
					printerList[whichPrint-1].pushToQueue(processor.getRunning());
					numberInCPU--;
					processor.insertFromQueue();
				}
			}
		}

		else if(command == "t"){
			if(numberInCPU > 0){
				processor.terminateRunning();
				numberInCPU--;
				numberOfProcesses--;
			}
			else{
				cout << "There is no process running." << endl;
			}
		}

		else if(command[0] == 'P' && isdigit(command[1])){
			int whichPrint = command[1] - 48;
			PCB tempPCB;	
			if(whichPrint > numberOfPrinters || whichPrint < 1){
				cout << "Printer does not exist." << endl;
			}
			else{
				tempPCB = printerList[whichPrint-1].getCurrent();
				if(tempPCB.getProcessID() == 0){
					cout << "Nothing to remove. Printer queue is empty." << endl;
				}
				else{
					processor.insertToCPUQueue(printerList[whichPrint-1].getCurrent());
					printerList[whichPrint-1].getNextFromQueue();
					numberInCPU++;
				}
			}
		}

		else if(command[0] == 'D' && isdigit(command[1])){
			int whichDisk = command[1] - 48;
			PCB tempPCB;
			if(whichDisk > numberOfDisks || whichDisk < 1){
				cout << "Disk does not exist." << endl;
			}
			else{
				tempPCB = diskList[whichDisk-1].getCurrent();
				if(tempPCB.getProcessID() == 0){
					cout << "Nothing to remove. Disk queue is empty." << endl;
				}
				else{
					processor.insertToCPUQueue(diskList[whichDisk-1].getCurrent());
					diskList[whichDisk-1].getNextFromQueue();
					numberInCPU++;
				}
			}
		}

		else if(command == "S"){ 
			char snapCommand;
			cout << "Snapshot mode." << endl << "Enter a command: " ;
			cin >> snapCommand;
			if(!validSnapshotInput(snapCommand)){
				cout << "Invalid snapshot command. Returning to regular command mode." 
					<< endl;
			}
			if(snapCommand == 'r'){
				cout << "Printing out queued processes in CPU ready queue: " << endl;
				processor.printQueuedPID();
			}
			else if(snapCommand == 'i'){
				cout << "Printing out all queued IO tasks: " << endl;
				printPrinterQueue();
				printDiskQueue();
				cout << endl;
			}
			else if(snapCommand == 'm'){
				cout << "Printing memory structure: " << endl;
				processor.printMemory();
			}
		}
	}
}

#endif
