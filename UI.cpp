#include "UI.h"
#include <fstream>
#include <string>
#include <conio.h>

#include "olcConsoleGameEngine.h"

using namespace std;

void printRankingBoard()
{
	ctool::setConsoleBackgroundColor(Cyan); 


	// Sử dụng cách đọc file để in ra màn hình console Tiêu đề Ranking
	ifstream inFile;
	inFile.open("RankingTitle.txt");
	if (inFile.is_open())
	{
		ctool::setColor(Cyan, Black);
		string temp;
		int i = 1;
		ctool::GotoXY(40, i);
		// Set vị trí bắt đầu là (40,1)
		while (!inFile.eof())
		{
			i++;
			getline(inFile, temp);
			cout << temp;
			ctool::GotoXY(40, i);
			// Gán từng dòng và in ra màn hình đến khi hết file .txt
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
