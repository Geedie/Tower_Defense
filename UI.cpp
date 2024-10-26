#include "UI.h"
#include <fstream>
#include <string>
#include <conio.h>

#include "olcConsoleGameEngine.h"

using namespace std;

void printRankingBoard()
{
	/*SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 176 + 0);
	for(int i = 0; i < 200; i++)
		for (int j = 0; j < 70; j++)
		{
			ctool::GotoXY(i, j);
			cout << " ";
		}*/

	ctool::setConsoleBackgroundColor(Cyan);

	ifstream inFile;
	inFile.open("RankingTitle.txt");
	if (inFile.is_open())
	{
		ctool::setColor(Cyan, Black);
		//SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 176 + 0);
		string temp;
		int i = 1;
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

	ctool::GotoXY(0, 8);
	for (int i = 0; i < 120; i++)
	{
		cout << "=";
	}

	ctool::GotoXY(15, 7);
	cout << "Top";

	ctool::GotoXY(35, 7);
	cout << "Player";

	ctool::GotoXY(100, 7);
	cout << "Score";


	ctool::setColor(LightGray, DarkMagenta);

	ctool::GotoXY(1, 1);
	wcout << L"╔══════════════╗";
	ctool::GotoXY(1, 2);
	wcout << L"║ Back to Menu ║";
	ctool::GotoXY(1, 3);
	wcout << L"╚══════════════╝";

	// Tọa độ của cái ô chọn là (1,1) -> (17,3)

	_getch(); // Cái này sẽ nhận vào bất kì phím nào trên bàn phím xong rồi sẽ để chương trình chạy tiếp

	ctool::setColor(Green, DarkMagenta);

	ctool::GotoXY(1, 1);
	wcout << L"╔══════════════╗";
	ctool::GotoXY(1, 2);
	wcout << L"║ Back to Menu ║";
	ctool::GotoXY(1, 3);
	wcout << L"╚══════════════╝";

	Sleep(1000);

	ctool::setColor(Black, LightGray);
	system("cls");
}

//int main()
//{
//	ctool::setLocale();
//	ctool::resizeConsole(1400, 800);
//	ctool::ShowConsoleCursor(false);
//
//	printRankingBoard();
//
//
//
//	return 0;
//}
