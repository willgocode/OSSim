#ifndef OPERATING_SYSTEM_H
#define OPERATING_SYSTEM_H

#include <iostream>
#include <vector>
#include "IODevice.h"
#include "CPU.h"
#include "PCB.h"
#include "Memory.h"

using namespace std;

class OperatingSystem{
    public:
        OperatingSystem(int printers = 0, int disks = 0, unsigned int memory = 0) : 
			processor(memory), numberInCPU(0), numberOfProcesses(0), numberOfPrinters(printers), 
			numberOfDisks(disks), inEnvironment(true){
                diskList.resize(disks);
                printerList.resize(printers);
            };

        void insertPrinterTask(int printerPosition, string fileName,
                unsigned int fileSize, PCB newPCB);
        void insertDiskTask(int diskPosition, string fileName,
                unsigned int fileSize, PCB newPCB);
		
        bool validInput(string userInput);
        bool validSnapshotInput(char userSnapshotInput);
        void printPrinterQueue();
        void printDiskQueue();
    	void bootOS();
	private:
        vector<Disk> diskList;
        vector<Printer> printerList;
		CPU processor;
		int numberInCPU;
		int numberOfProcesses;
		int numberOfPrinters;
        int numberOfDisks;
		bool inEnvironment;
};

#endif
