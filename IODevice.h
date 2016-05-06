#ifndef IO_DEVICE_H
#define IO_DEVICE_H

#include <list>
#include "PCB.h"

using namespace std;

class IODevice{
    public:
        virtual void printIOQueue() = 0;
        virtual void pushToQueue(PCB newEntry) = 0;
		virtual PCB getTop() = 0;
		virtual void removeTop() = 0;
		virtual bool isEmpty() = 0;
};

class Printer: public IODevice{
    public:
        void printIOQueue();
        void pushToQueue(PCB newEntry);
		PCB getTop();
		void removeTop();
		bool isEmpty(){ return printerQueue.empty(); }
    private:
        list<PCB> printerQueue;
};

class Disk: public IODevice{
    public:
        void printIOQueue();
        void pushToQueue(PCB newEntry);
		PCB getTop();
		void removeTop();
		bool isEmpty(){ return diskQueue.empty(); }
	private:
        list<PCB> diskQueue;
};

#endif
