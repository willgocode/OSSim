#include <list>
#include <iostream>
#include "PCB.h"
#include "Comparator.h"
#include "MemComparator.h"
#include "IODevice.h"
#include "OperatingSystem.h"
#include "SortedLinkedList.h"
#include "CPU.h"
#include "helpers.h"
#include "Memory.h"

using namespace std;

int main(){
	CPU processor(1000);
	
	for(int i = 0; i < 3; i++){
		processor.addToCPUQueue();
	}
/*
	int numberOfPrinters, numberOfDisks;
	unsigned int memInBytes;
	
	cout << "Enter the number of printers: ";
	cin >> numberOfPrinters;
	inputManager(numberOfPrinters);
	
	cout << "Enter the number of disks: " ;
	cin >> numberOfDisks;
	inputManager(numberOfDisks);

	cout << "Enter total memory in bytes: " ;
	cin >> memInBytes;
	inputManager(memInBytes);

	OperatingSystem myOS(3, 3, 100000);
	myOS.bootOS();
*/
	return 0;
}
