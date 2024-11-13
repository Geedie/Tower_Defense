#include "Setting.h"
#include "consoleHandle.h"
#include "Menu.h"

// Draws a box with text from a file at specified coordinates.
void drawBoxSetting(const char* filename, int width, int posX, int posY, bool isSelected) {
    COORD coord = { static_cast<SHORT>(posX), static_cast<SHORT>(posY) };
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    ifstream file(filename);

    // Set text attributes based on selection state
    SetConsoleTextAttribute(hConsole, isSelected ? (14 | (5 << 4)) : (0 | (11 << 4)));

    // Draw the top border of the box
    SetConsoleCursorPosition(hConsole, coord);
    cout << " " << string(width - 2, '-') << " " << endl;

    // Prepare to draw the content of the box
    coord.Y++;
    string line;

    // Draw each line from the file
    while (getline(file, line)) {
        int lineLength = line.length();
        int totalPadding = max(0, width - 2 - lineLength); // Calculate total padding

        // Calculate left and right padding
        int leftPadding = totalPadding / 2;
        int rightPadding = totalPadding - leftPadding;

        // Move to the next line in the box
        SetConsoleCursorPosition(hConsole, coord);
        cout << "|" << string(leftPadding, ' ') << line << string(rightPadding, ' ') << "|" << endl;
        coord.Y++;
    }

    // Draw the bottom border of the box
    SetConsoleCursorPosition(hConsole, coord);
    cout << " " << string(width - 2, '-') << " " << endl;

    // Restore default text color after drawing
    SetConsoleTextAttribute(hConsole, 0 | (7 << 4)); // Default console color

    file.close(); // Close the file
}

// Draws the title from "Setting.txt" at specified coordinates.
void drawTitleSetting(int width, int posX, int posY) {
    COORD coord = { static_cast<SHORT>(posX), static_cast<SHORT>(posY) };
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    ifstream file("Setting.txt");

    // Read and draw each line from the file
    string line;
    while (getline(file, line)) {
        SetConsoleCursorPosition(hConsole, coord);
        cout << line << endl;
        coord.Y++;
    }

    file.close(); // Close the file
}

void printTitleSetting() {
    static const int boxWidth = 30; // Width of the menu boxes
    static int consoleWidth = getConsoleWidth(); // Get the width of the console once
    static int consoleHeight = getConsoleHeight(); // Get the height of the console once
    static int startY = consoleHeight / 2; // Center Y position, calculated once

    static int positionX = (consoleWidth - boxWidth) / 2; // Center X position, calculated once

    setLocale(); // Set locale
    drawTitleSetting(100, positionX - 13, startY - 18); // Draw title
}

void printOptionSetting() {
    static const int boxWidth = 30;   // Width of the menu boxes
    static const int consoleWidth = getConsoleWidth(); // Get the width of the console once
    static const int consoleHeight = getConsoleHeight(); // Get the height of the console once
    static const int startY = consoleHeight / 2; // Center Y position
    static const int positionX = (consoleWidth - boxWidth) / 2; // Center X position, calculated once

    HWND consoleWindow = GetConsoleWindow();
    bool leftButtonPressed = false; // Track the left button state

    while (true) {
        // Get cursor position
        POINT cursorPos;
        if (GetCursorPos(&cursorPos) && ScreenToClient(consoleWindow, &cursorPos)) {
            int x = cursorPos.x / 8; // Assuming 8 pixels per character
            int y = cursorPos.y / 16; // Assuming 16 pixels per line

            // Determine which boxes to highlight based on cursor position
            bool drawMusic = (x >= positionX - 14 && x <= positionX + boxWidth - 7 && y >= startY - 8 && y <= startY);
            bool drawGraphics = (x >= positionX - 14 && x <= positionX + boxWidth - 7 && y >= startY && y <= startY + 8);
            bool drawBackToMenu = (x >= positionX - 14 && x <= positionX + boxWidth - 7 && y >= startY + 8 && y <= startY + 16);

            // Draw options
            drawBoxSetting("Music.txt", boxWidth + 14, positionX - 7, startY - 8, drawMusic);
            drawBoxSetting("Graphics.txt", boxWidth + 14, positionX - 7, startY, drawGraphics);
            drawBoxSetting("BackToMenu.txt", boxWidth + 14, positionX - 7, startY + 8, drawBackToMenu);

            // Handle left button click for Back to Menu
            if (drawBackToMenu && (GetAsyncKeyState(VK_LBUTTON) & 0x8000)) {
                if (!leftButtonPressed) { // Only trigger if it was not previously pressed
                    leftButtonPressed = true;
                    setConsoleBackgroundColor(11); // Set background color
                    clearConsole(); // Clear the console
                    Menu menu; // Assuming Menu is a valid class
                    menu.MenuControl(); // Call the menu control function
                }
            }
            else {
                leftButtonPressed = false; // Reset if button is released
            }
        }

        Sleep(10); // Adjust sleep time as needed
    }
}

void Setting::SettingControl() {
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);

    //Hide cursor
    CONSOLE_CURSOR_INFO cursorInfo;
    GetConsoleCursorInfo(hConsole, &cursorInfo);
    cursorInfo.bVisible = false; // set the cursor visibility
    SetConsoleCursorInfo(hConsole, &cursorInfo);

    setConsoleBackgroundColor(11); // Set background color

	printTitleSetting();
	printOptionSetting();
}