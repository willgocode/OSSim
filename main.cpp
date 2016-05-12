#include <list>
#include <iostream>
#include "PCB.h"
#include "Comparator.h"
#include "IODevice.h"
#include "OperatingSystem.h"
#include "SortedLinkedList.h"
#include "CPU.h"
#include "helpers.h"

using namespace std;

int main(){
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
*/
	OperatingSystem myOS(3, 3, 100);
	myOS.bootOS();

	return 0;
}
