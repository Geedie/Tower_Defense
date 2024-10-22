#pragma once
#include "cpoint.h"
#include <mutex>
#include <windows.h>
#include <iostream>
using namespace std;
class ctool {
public:
	static mutex mtx;
	static void ShowConsoleCursor(bool);
	static void GotoXY(int x, int y);
	static void Draw(char*, int, cpoint[], cpoint&);
}