// ANewAlphabet.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <string>
#include <vector>
using namespace std;

bool work = false;
long ll=0, rr=0;

char change (char a) {
	if (a == '(')
	{
		rr++;
		ll--;
		return ')';
	}
	else
	{
		rr--;
		ll++;
		return '(';
	}

}

void check(vector<char> c) {
	int left = 0, right = 0;
	for (int i = 0; i < c.size()-1; i++) {
		if (c[i] == '(') {
			if (i > c.size() / 2 && left > right + 1)
			{
				work = false;
				break;
			}
			left++;
			for (int j = i; j < c.size(); j++) {
				if (c[j] == ')') {
					right++;
					c[j] = 'o';
					break;
				}
			}
		}

	}
	
	if(left == right && left == c.size()/2) {
		//cout << "possible";
		work = true;
	}
}

int main()
{
	string line;
	cin >> line;
	vector<char> l(line.size());
	vector<char> c(line.size());
	long lll=0, rrr=0;
	if (line.size() % 2 != 0) {
		cout << "impossible";
	}else
    {



		for (int i = 0; i < line.size(); i++) {
			if (line[i] == '(')
				lll++;
			else
				rrr++;
			l[i] = line[i];
		}
		if(lll == rrr)
			check(l);
		if (!work) {

			for (int i = 0; i < line.size(); i++) {
				for (int j = 0; j < line.size() - i; j++) {


					c = l;
					ll = lll;
					rr = rrr;
					for (int k = j; k < j + i + 1; k++) {

						c[k] = change(c[k]);
					}
					if(ll == rr)
						check(c);
					if (work) {
						//cout << "possible";
						break;
					}
					if (work)
						break;
				}
				if (work)
					break;
			}
		}
		if (!work) {
			cout << "impossible";
		}
		else {
			cout << "possible";
		}

		
	}

	int a;
	cin >> a;
    return 0;
}

