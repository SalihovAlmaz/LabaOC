
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
const char* filename = "d:\\data1.txt";

void RR() {
	vector<int> masN;
	vector<int> masW;
	int takt;
	int count = 0;
	char c;
	FILE* stream;
	if ((stream = fopen(filename, "r")) == nullptr)
		cout << "couldn't open file!\n";
	fscanf(stream, "%d\n", &takt);
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

	
	for (size_t d = 0; d < countPr; d++){
		int temp = -1;
		bool Do = false;
		for (size_t e = 0; e < masN.size(); e++)
		{
			gotoxy(d + (d / takt), e);
			if (masW[d / takt % masN.size()] == 0) {
				int MnN = masN.size();
				for (int h = masN.size() - 1; h >= 0; h--)
				{
					if (masW[h] != 0 && h < MnN)
					{
						MnN = h;
					}
				}
				if (masW[MnN] != masW[e] || MnN == masN.size() || Do == true)
					cout << "-" << endl;
				else {
					cout << "w" << endl;
					temp = MnN;
					Do = true;
					
				}
			}
			else
				if (masN[d/ takt % masN.size()] != masN[e] || Do == true)
					cout << "-" << endl;
				else {
					cout << "w" << endl;
					Do = true;
					
				}
			


		}
		if (temp == -1)
		masW[d / takt % masN.size()]--;
		else
		{
			masW[temp / takt % masN.size()]--;
		}
		gotoxy(d+1+(d/takt), 0);
}
	gotoxy(0, masW.size()+1);
			}
			