#include "Menu.h"
#include "consoleHandle.h"

// Draws a box with text from a file at specified coordinates.
void drawBox(ifstream& file, int width, int posX, int posY, bool isSelected) {
    COORD coord;
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);

    // Draw the top border of the box
    coord.X = posX;
    coord.Y = posY;
    SetConsoleCursorPosition(hConsole, coord);
    cout << " " << string(width - 2, '-') << endl;

    // Draw the content of the box
    coord.Y++;
    coord.X = posX;

    string line;
    while (getline(file, line)) {
        int lineLength = line.length();
        int totalPadding = max(0, width - 2 - lineLength); // Ensure padding isn't negative

        int leftPadding = totalPadding / 2;   // Calculate left padding
        int rightPadding = totalPadding - leftPadding; // Calculate right padding

        /*// Set console text color based on selection state
        if (isSelected) {
            SetConsoleTextAttribute(hConsole, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_INTENSITY);
        }
        else {
            SetConsoleTextAttribute(hConsole, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
        }*/

        // Print the line within the box
        SetConsoleCursorPosition(hConsole, coord);
        cout << "|" << string(leftPadding, ' ') << line << string(rightPadding, ' ') << "|" << endl;
        coord.Y++;
    }

    // Draw the bottom border of the box
    coord.X = posX;
    SetConsoleCursorPosition(hConsole, coord);
    cout << " " << string(width - 2, '-') << endl;
}

// Draws the title from "Menu.txt" at specified coordinates.
void drawTitle(int width, int posX, int posY) {
    COORD coord;
    coord.X = posX;
    coord.Y = posY;

    ifstream file("Menu.txt");
    string line;
    while (getline(file, line)) {
        SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
        cout << line << endl;
        coord.Y++;
    }
    file.close();
}

// Prints the entire menu by calling drawBox for each section.
void Menu::printMenu() {
    const int boxWidth = 30;   // Width of the menu boxes
    const int consoleWidth = getConsoleWidth(); // Get the width of the console
    const int startY = getConsoleHeight() / 2; // Center Y position

    setConsoleBackgroundColor(3); // Set background color

    int positionX = (consoleWidth - boxWidth) / 2; // Center X position
    drawTitle(100, positionX - 7, startY - 18); // Draw title

    // Draw the options boxes
    ifstream play("PlayOpt.txt");
    drawBox(play, boxWidth + 14, positionX - 7, startY - 8, true);
    play.close();

    ifstream setting("SettingOpt.txt");
    drawBox(setting, boxWidth + 14, positionX - 7, startY, true);
    setting.close();

    ifstream rank("RankOpt.txt");
    drawBox(rank, boxWidth + 14, positionX - 7, startY + 8, true);
    rank.close();
}

// Function to handle option selection.
void Menu::chooseOption() {
    
}