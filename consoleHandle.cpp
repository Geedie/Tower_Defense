#include "consoleHandle.h"
#include <windows.h>

// Retrieves the width of the console window.
int getConsoleWidth() {
    CONSOLE_SCREEN_BUFFER_INFO csbi; // Structure to hold console screen buffer info
    GetConsoleScreenBufferInfo(GetStdHandle(STD_OUTPUT_HANDLE), &csbi); // Get current console info
    return csbi.srWindow.Right - csbi.srWindow.Left + 1; // Calculate width
}

// Retrieves the height of the console window.
int getConsoleHeight() {
    CONSOLE_SCREEN_BUFFER_INFO csbi; // Structure to hold console screen buffer info
    GetConsoleScreenBufferInfo(GetStdHandle(STD_OUTPUT_HANDLE), &csbi); // Get current console info
    return csbi.srWindow.Bottom - csbi.srWindow.Top + 1; // Calculate height
}

void setConsoleBackgroundColor(int backgroundColor) {
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    // Lay thong tin ve buffer
    CONSOLE_SCREEN_BUFFER_INFO csbi;
    GetConsoleScreenBufferInfo(hConsole, &csbi);
    // Kich thuoc buffer
    DWORD written;
    COORD coord = { 0, 0 };
    DWORD size = csbi.dwSize.X * csbi.dwSize.Y;
    // Thay doi mau nen
    SetConsoleTextAttribute(hConsole, (backgroundColor << 4) | 15);
    // To mau cho buffer
    FillConsoleOutputCharacter(hConsole, ' ', size, coord, &written);
    FillConsoleOutputAttribute(hConsole, (backgroundColor << 4) | 15, size, coord, &written);
    // Di chuyen con tro ve vi tri ban dau
    SetConsoleCursorPosition(hConsole, coord);
}

// Resizes the console window to the specified width and height.
void resizeConsole(int width, int height) {
    HWND console = GetConsoleWindow(); // Get the handle to the console window
    RECT r;
    GetWindowRect(console, &r); // Retrieve the current size and position of the console window

    // Move and resize the console window
    MoveWindow(console, r.left, r.top, width, height, TRUE);
}