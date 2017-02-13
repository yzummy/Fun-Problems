// Islands_in_The_Data.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <string>

using namespace std;


int main()
{
	unsigned short p,num,first,last=0,c;
	unsigned short list[12];
	unsigned sum;

	cin >> p;

	for (int i = 0; i < p; i++)
	{
		cin >> num;
		sum = 0;
		c = 0;
		for (int j = 0; j < 12; j++)
		{
			cin >> list[j];
		}

		while (c != 11) {
			first = list[c];
			if (list[c + 1] > first) {
				first = list[c + 1];
				for (int j = c + 1; j < 11; j++) {
					if (list[j + 1] < list[j]) {
						last = 0;
						for (int k = c + 1; k <= j; k++) {
							if ((list[k] <= list[c]) || (list[k] <= list[j+1])) {
								last = 1;
							}
						}
						if (last == 0) {
							sum++;
						}
						
					}
				}
			}
			c++;
		}
		
		cout << num << " " << sum << endl;
		
	}

	

    return 0;
}

