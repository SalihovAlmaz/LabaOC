


#include <Windows.h>
#include <iostream>
#include <iomanip>
using namespace std;
#include <queue>
#include <string>
#include <fstream>
#include <vector>
#include <list>
void gotoxy(int x, int y)
{
	COORD p = { x,y };
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), p);

}
double calc(double one, double two) {
	return (one + 0.99 - two / 100);
}
int retIn(double x) {
	return (99 - (int)(x * 100) % 100);
}

void FIFS()

{
	/*queue <int> masOch;
	int* masPr = new int[];*/
	FILE* stream;
	vector <int> name;
	vector <int> work;
	vector <int> prior;
	vector <int> delay;
	const char* filename = "d:\\data.txt";
	int count = 0;
	char c;
	if ((stream = fopen(filename, "r")) == nullptr)
		cout << "couldn't open file!\n";
	do
	{
		int temp1;
		int temp2;
		int temp3;
		int temp4;
		fscanf(stream, "%d %d %d %d", &temp4, &temp1, &temp2, &temp3);
		name.push_back(temp4);
		work.push_back(temp1);
		prior.push_back(temp2);
		delay.push_back(temp3);
		if ((c = fgetc(stream)) == '\n' || c == EOF) {
			count++;

		}
	} while (!feof(stream));

	fclose(stream);

	double Max = 0;
	double predMax = 0;
	vector<double>(MasPrior);
	for (size_t i = 0; i < name.size(); i++)
	{
		MasPrior.push_back(calc(prior[i], name[i]));
	}

	for (int i = 1; i < MasPrior.size(); ++i)
	{
		for (int r = 0; r < MasPrior.size() - i; r++)
		{
			if ((MasPrior[r]) > (MasPrior[r + 1]))
			{
				double temp = MasPrior[r];
				MasPrior[r] = MasPrior[r + 1];
				MasPrior[r + 1] = temp;
			}
		}
	}
	for (size_t i = 0; i < name.size(); i++)
	{
		cout << name[i] << "  " << work[i] << "  " << prior[i] << "  " << delay[i] << endl;
	}

	int j = 0;
	int countPr = 0;
	bool zaderj;

	for (size_t i = 0; i < work.size(); i++)
	{
		countPr += work[i];
	}

	while (!(countPr == 0)) {
		int index = MasPrior.size() - 1;
		while (delay[retIn(MasPrior[index])] != 0)
		{
			delay[retIn(MasPrior[index])]--;
			index--;
		}

		if (work[retIn(MasPrior[index])] == 0)
		{
			MasPrior.pop_back();
			index = MasPrior.size() - 1;
			while (delay[retIn(MasPrior[index])] != 0)
			{
				delay[retIn(MasPrior[index])]--;
				if (index != 0)
					index--;
				
				
			}
			work[retIn(MasPrior[index])] -= 1;
		}
		else
		{
			work[retIn(MasPrior[index])] -= 1;
		}
		for (size_t i = 0; i < work.size(); i++)
		{

			if (retIn(MasPrior[index]) != i)
			{
				gotoxy(20 + j * 2, i); cout << "-" << endl;
			}
			else
			{
				gotoxy(20 + j * 2, i); cout << "w" << endl;
			}
		}
		countPr--;
		j++;

	}
}