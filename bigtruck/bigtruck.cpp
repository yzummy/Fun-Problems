// bigtruck.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <cstdio>
#include <iostream>
#include <vector>

using namespace std;
const int inf = 101;



int main() {
	int stuff, path;
	vector<int> item(7);
	vector<int> dist(7,101);
	vector<bool> visit(7, false);
	vector<vector<int>> dis(7,vector<int>(7));
	cin >> stuff;
	for (int i = 1; i <= stuff; i++) {
		cin >> item[i];
	}

	cin >> path;
	int a, b;
	for (int i = 1; i <= stuff; i++) {
		for (int j = 1; j <= stuff; j++) {
			dis[i][j] = 0;
		}
	}
	for (int i = 0; i < path; i++) {
		cin >> a >> b;
		cin >> dis[a][b];
	}

	int start = 1;
	for (int i = 1; i <= stuff; i++) {
		if (dis[start][i] != 0 && dis[start][i] < dist[i] && !vist[i]) {

		}
	}

	
}

