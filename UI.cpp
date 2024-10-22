#include "UI.h"
#include <fstream>
#include <string>
#include <conio.h>


void printRankingBoard()
{
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 176 + 0);
	for (int i = 0; i < 200; i++)
		for (int j = 0; j < 60; j++)
		{
			ctool::GotoXY(i, j);
			cout << " ";
		}
	ifstream inFile;
	inFile.open("RankingTitle.txt");
	if (inFile.is_open())
	{
		string temp;
		int i = 0;
		ctool::GotoXY(40, i);
		while (!inFile.eof())
		{
			i++;
			getline(inFile, temp);
			cout << temp;
			ctool::GotoXY(40, i);
		}
	}
	inFile.close();

	ctool::GotoXY(0, 6);
	for (int i = 0; i < 120; i++)
	{
		cout << "=";
	}

	ctool::GotoXY(15, 5);
	cout << "Top";

	ctool::GotoXY(35, 5);
	cout << "Player";

	ctool::GotoXY(100, 5);
	cout << "Score";


	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 160 + 5);
	ctool::GotoXY(1, 1);
	cout << "Press any key to go back";

	_getch();
	system("cls");
}

int main()
{
	printRankingBoard();

	return 0;
}