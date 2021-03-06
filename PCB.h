#ifndef PCB_H
#define PCB_H

#include <iostream>
using namespace std;

class PCB{
    public:
        PCB(unsigned int pSize = 0, int aPriority = 99999) : 
			processID(0), processSize(pSize), memBegin(0), memEnd(0), 
			priority(aPriority), fileName(""), fileSize(0), status("waiting"){};

        int getProcessID() const { return processID; }
        unsigned int getProcessSize() const { return processSize; }
        void setProcessSize(unsigned int newSize) { processSize = newSize; }
		unsigned int getMemBegin() const { return memBegin; }
        unsigned int getMemEnd() const { return memEnd; }
        int getPriority() const { return priority; }
		string getStatus() const { return status; }

		void setProcessID(unsigned int aPID){ processID = aPID; }
		void setStatus(string newStatus) { status = newStatus; }
		
		void setFileName(string newName) { fileName = newName; }
		void setFileSize(unsigned int newSize) { fileSize = newSize; }
		string getFileName() const { return fileName; }
		unsigned int getFileSize() const { return fileSize; }

		void setMemBegin(unsigned int newPoint) { memBegin = newPoint; }
		void setMemEnd(unsigned int newPoint) { memEnd = newPoint; }

	private:
		int processID;
        int processSize;
        unsigned int memBegin;
        unsigned int memEnd;
        int priority;
		string fileName;
		unsigned int fileSize;
		string status;
};

#endif
