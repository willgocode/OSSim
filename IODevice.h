#ifndef IO_DEVICE_H
#define IO_DEVICE_H

#include <list>
#include "PCB.h"

using namespace std;

class IODevice{
    public:
        virtual void printIOQueue() = 0;
		virtual void pushToQueue(PCB newEntry) = 0;
		virtual bool isEmpty() = 0;
		virtual void getNextFromQueue() = 0;
		virtual PCB getCurrent() = 0;
		virtual void displayMemStruct() = 0;
};

class Printer: public IODevice{
    public:
		Printer(): totalNumberPrintTasks(0){}
        void printIOQueue();
        void pushToQueue(PCB newEntry);
		bool isEmpty(){ return printerQueue.empty(); }
		void getNextFromQueue();
		PCB getCurrent() { return inPrintMode[0]; }
		void displayMemStruct();
	private:
        int totalNumberPrintTasks;
		PCB inPrintMode[1];
		list<PCB> printerQueue;
};

class Disk: public IODevice{
    public:
		Disk(): totalNumberDiskTasks(0){}
        void printIOQueue();
        void pushToQueue(PCB newEntry);
		bool isEmpty(){ return diskQueue.empty(); }
		void getNextFromQueue();
		PCB getCurrent(){ return inDiskMode[0]; }
		void displayMemStruct();
	private:
		int totalNumberDiskTasks;
		PCB inDiskMode[1];
        list<PCB> diskQueue;
};

#endif
