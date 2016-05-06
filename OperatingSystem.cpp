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
        if(!printerList[i].isEmpty()){
            printerList[i].printIOQueue();
        }
    }
}

void OperatingSystem::printDiskQueue(){
    for(int i = 0; i < numberOfDisks ; ++i){
        if(!diskList[i].isEmpty()){
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
			cout << "Adding new process: " << endl;
			processor.addToCPUQueue();
			numberOfProcesses++;
		}
				
		else if(command[0] == 'd'){
			cout << "Moving process to disk queue." << endl;
		}

		else if(command[0] == 'p'){
			cout << "Moving process to printer queue." << endl;
		}

		else if(command == "t"){
			if(numberOfProcesses > 0){
				processor.terminateRunning();
			}
			else{
				cout << "There is no process running." << endl;
			}
		}

		else if(command == "S"){
			cout << "Snapshot mode: " << endl;
		}
	}
}

#endif
