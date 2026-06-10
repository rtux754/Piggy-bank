#include <iostream>
#include <set>
#include <string>
#include <cstdlib>
#include <fstream>
#include <algorithm>
#include <vector>

#ifdef _WIN32
#include <windows.h>
#endif

using namespace std;

struct Database {
    string namaParfum;
    string brandParfum;
    double harga;
    string tanggalBeli;
    int rating; 
    string notes;
    string longevity;
    string projectile;
};

vector<Database> database;

// UI/UX FUNGSI
void clearScreen();
void setupTerminal();

void setHexColor(string hexCode);
void primaryColor(); // Breeze Blue (#3DAEE9)
void secondaryColor(); // White (#EFF0F1)
void successColor(); // Green (#27AE60)
void warningColor(); // Amber (#FDBC4B)
void errorColor(); // Red (#DA4453)
void resetColor();

void clearScreen() {

#ifdef _WIN32
    system("cls");
#else
    system("clear");
#endif
}

void setupTerminal() {
    #ifdef _WIN32
        HANDLE hOut = GetStdHandle(STD_OUTPUT_HANDLE);
        DWORD dwMode = 0;
        GetConsoleMode(hOut, &dwMode);
        dwMode | ENABLE_VIRTUAL_TERMINAL_PROCESSING;
        SetConsoleMode(hOut, dwMode);
    #endif
}

void setHexColor(string hexCode) {
    if (hexCode[0] == '#') hexCode = hexCode.substr(1);
    int r = stoi(hexCode.substr(0, 2), nullptr, 16);
    int g = stoi(hexCode.substr(2, 2), nullptr, 16);
    int b = stoi(hexCode.substr(4, 2), nullptr, 16);
    cout << "\033[38;2;" << r << ";" << g << ";" << b << "m";
}

void primaryColor() { setHexColor("#3DAEE9"); };
void secondaryColor() { setHexColor("#EFF0F1"); };
void successColor() { setHexColor("#27AE60"); };
void warningColor() { setHexColor("#FDBC4B"); };
void errorColor() { setHexColor("#DA4453"); };
void resetColor() { cout << "\033[0m"; };

int main () {
    setupTerminal();
    clearScreen();
    // load();

    return 0;
}