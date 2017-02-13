// estimate.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <string>

using namespace std;

int main()
{
	int num;
	string line;

	cin >> num;
	for (int i = 0; i < num; i++) {
		cin >> line;
		cout << line.size() << endl;
	}

	cin >> num;
    return 0;
}

