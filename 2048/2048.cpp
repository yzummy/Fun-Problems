// 2048.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"

// Yunchao Zhang
#include <iostream>
#include <string>
using namespace std;

int main()
{
	int matrix[4][4];

	int medium[4][4];
	int after[4][4];
	for (int i = 0; i<4; i++)
	{
		for (int j = 0; j<4; j++)
		{
			medium[i][j] = 0;
			after[i][j] = 0;
		}
	}

	int 
	unsigned short move;
	int a;
	unsigned short r=0, c=0, k = 0;
	for (int i = 0; i<4; i++)
	{
		for (int j = 0; j<4; j++)
		{
			cin >> matrix[i][j];
		}
	}
	cin >> move;

	switch (move)
	{
	case 0: //left
		
		for (int i = 0; i < 4; i++)
		{
			c = 0;
			for (int j = 0; j < 4; j++)
			{
				if (matrix[i][j] != 0)
				{
					medium[i][c] = matrix[i][j];
					c++;
				}
			}
			
			if (medium[i][0] == medium[i][1])
			{
				after[i][0] = medium[i][0] * 2;
				if (medium[i][2] == medium[i][3])
				{
					after[i][1] = medium[i][2] * 2;
				}
				else {
					after[i][1] = medium[i][2];
					after[i][2] = medium[i][3];
				}
			}
			else if (medium[i][2] == medium[i][1]) {
				after[i][0] = medium[i][0];
				after[i][1] = medium[i][1]*2;
				after[i][2] = medium[i][3];
			}
			else if (medium[i][2] == medium[i][3]) {
				after[i][0] = medium[i][0];
				after[i][1] = medium[i][1];
				after[i][2] = medium[i][3]*2;
			}
			else {
				after[i][0] = medium[i][0];
				after[i][1] = medium[i][1];
				after[i][2] = medium[i][2];
				after[i][3] = medium[i][3];

			}
			for (int j = 0; j < 4; j++)
			{
				cout << after[i][j] << " ";
			}
			cout << endl;
		}


		break;

	case 1: //up



		for (int j = 0; j < 4; j++)
		{
			c = 0;
			for (int i = 0; i < 4; i++)
			{
				if (matrix[i][j] != 0)
				{
					medium[c][j] = matrix[i][j];
					c++;
				}
			}

			if (medium[0][j] == medium[1][j])
			{
				after[0][j] = medium[0][j] * 2;
				if (medium[2][j] == medium[3][j])
				{
					after[1][j] = medium[2][j] * 2;
				}
				else {
					after[1][j] = medium[2][j];
					after[2][j] = medium[3][j];
				}
			}
			else if (medium[2][j] == medium[1][j]) {
				after[0][j] = medium[0][j];
				after[1][j] = medium[1][j] * 2;
				after[2][j] = medium[3][j];
			}
			else if (medium[2][j] == medium[3][j]) {
				after[0][j] = medium[0][j];
				after[1][j] = medium[1][j];
				after[2][j] = medium[3][j] * 2;
			}
			else {
				after[0][j] = medium[0][j];
				after[1][j] = medium[1][j];
				after[2][j] = medium[2][j];
				after[3][j] = medium[3][j];

			}
			
		}

		for (int i = 0; i < 4; i++)
		{
			for (int j = 0; j < 4; j++) {
				cout << after[i][j] << " ";

			}
			cout << endl;
		}
		break;

	case 2: //right


		for (int i = 0; i <4; i++)
		{
			c = 3;
			for (int j = 3; j >= 0; j--)
			{
				if (matrix[i][j] != 0)
				{
					medium[i][c] = matrix[i][j];
					c--;
				}
			}

			if (medium[i][3] == medium[i][2])
			{
				after[i][3] = medium[i][3] * 2;
				if (medium[i][1] == medium[i][0])
				{
					after[i][2] = medium[i][1] * 2;
				}
				else {
					after[i][2] = medium[i][1];
					after[i][1] = medium[i][0];
				}
			}
			else if (medium[i][2] == medium[i][1]) {
				after[i][3] = medium[i][3];
				after[i][2] = medium[i][2] * 2;
				after[i][1] = medium[i][0];
			}
			else if (medium[i][1] == medium[i][0]) {
				after[i][3] = medium[i][3];
				after[i][2] = medium[i][2];
				after[i][1] = medium[i][0] * 2;
			}
			else {
				after[i][0] = medium[i][0];
				after[i][1] = medium[i][1];
				after[i][2] = medium[i][2];
				after[i][3] = medium[i][3];

			}
			for (int j = 0; j < 4; j++)
			{
				cout << after[i][j] << " ";
			}
			cout << endl;
		}



		break;

	case 3: //down


		for (int j = 0; j < 4; j++)
		{
			c = 3;
			for (int i = 3; i >= 0; i--)
			{
				if (matrix[i][j] != 0)
				{
					medium[c][j] = matrix[i][j];
					c--;
				}
			}

			if (medium[3][j] == medium[2][j])
			{
				after[3][j] = medium[3][j] * 2;
				if (medium[1][j] == medium[0][j])
				{
					after[2][j] = medium[1][j] * 2;
				}
				else {
					after[2][j] = medium[1][j];
					after[1][j] = medium[0][j];
				}
			}
			else if (medium[2][j] == medium[1][j]) {
				after[3][j] = medium[3][j];
				after[2][j] = medium[2][j] * 2;
				after[1][j] = medium[0][j];
			}
			else if (medium[1][j] == medium[0][j]) {
				after[3][j] = medium[3][j];
				after[2][j] = medium[2][j];
				after[1][j] = medium[0][j] * 2;
			}
			else {
				after[0][j] = medium[0][j];
				after[1][j] = medium[1][j];
				after[2][j] = medium[2][j];
				after[3][j] = medium[3][j];

			}
			
		}
		for (int i = 0; i < 4; i++)
		{
			for (int j = 0; j < 4; j++) {
				cout << after[i][j] << " ";

			}
			cout << endl;

		}


		break;

	}
	cin >> a;


	return 0;
}