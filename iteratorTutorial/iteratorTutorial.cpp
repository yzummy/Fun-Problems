// iteratorTutorial.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <string>
#include <cassert>
#include <chrono>
#include <time.h>
#include <windows.h>
using namespace std;

int main()
{
	int numEntries;
	cout << "how many entries";
	cin >> numEntries;
	int *dPtr = new int[numEntries];
	assert(dPtr != 0);
	cout << "Enter your values.\n";

	for (int i = 0; i < numEntries; i++) {
		cin >> dPtr[i];
		cout << "\nthe address " << &dPtr[i];


	}
	int a = 0;

	delete [] dPtr;

    return 0;
}

