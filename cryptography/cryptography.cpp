// cryptography.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
using namespace std;

int main()
{
	int num[1683];
	int count[1000];


	for (int i = 0; i < 1000; i++) {
		count[i] = 0;
	}

	for (int i = 0; i < 1683; i++) {
		cin >> num[i];
		count[num[i]]++;
	}

	for (int i = 0; i <= 999; i++) {
		cout << i << ": " << count[i] << endl;
	}

	int n;
	cin >> n;
    return 0;
}

