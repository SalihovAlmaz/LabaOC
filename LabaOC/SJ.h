#pragma once
#include <Windows.h>
#include <iostream>
#include <iomanip>
using namespace std;
#include <queue>
#include <string>
#include <fstream>
#include <vector>
#include <list>
const char* filenameSJ = "d:\\data2.txt";
void SJ() {
	vector<int> masN;
	vector<int> masW;
	int count = 0;
	char c;
	FILE* stream;
	if ((stream = fopen(filenameSJ, "r")) == nullptr)
		cout << "couldn't open file!\n";
	do
	{
		int temp1;
		int temp2;

		fscanf(stream, "%d %d", &temp1, &temp2);
		masN.push_back(temp1);
		masW.push_back(temp2);

		if ((c = fgetc(stream)) == '\n' || c == EOF) {
			count++;

		}
	} while (!feof(stream));

	int countPr = 0;
	for (size_t i = 0; i < masW.size(); i++)
	{
		countPr += masW[i];
	}
	int max=0;
	for (size_t l = 0; l < masN.size(); l++) {
		if (masW[l] > masW[max] )
		{
			max = l;
		}
	}
	int ch = 0;
	for (size_t d = 0; d < masN.size(); d++) {
		int Min = max;
		for (size_t l = 0; l < masN.size(); l++) {
			if (masW[l] < masW[Min]&& masW[l]!=0)
			{
				Min = l;
			}
		}
		
		while (masW[Min] != 0) {
			
			for (size_t e = 0; e < masN.size(); e++)
			{
				gotoxy(ch, e);

				if (masN[Min] != masN[e])
					cout << "-" << endl;
				else

					cout << "w" << endl;

			}
			ch++;
			masW[Min]--;
			
		}
		
	}
	gotoxy(0, masW.size() + 1);
}


