#ifndef HELPERS_H
#define HELPERS_H

#include <iostream>

using namespace std;

template<typename T>
void inputManager(T myVar){
	while(cin.fail()){
        cout << "Enter a valid number: " << endl;
        cin.clear();
        cin.ignore();
        cin >> myVar;
    }
}

#endif
