#include <iostream>
#include <conio.h>
#include "../include/pch.h"
using namespace std;

int main()
{
    //print GAP
    const int height = 7;
    const int width = 7;
    const int spacing = 2;
    const int textWidth = width * 3 + spacing * 2;
    const int verticalHeight = 3;
    const int horizontalWidth = 7;

    for (int i = 0; i < height; i++) {
        for (int j = 0; j < width; j++) {
            if (i == 0 || i == height - 1 || j == 0 || (i >= 3 && j == width - 1) || (i == 3 && j >= 3))
                std::cout << char(205);
            else
                std::cout << " ";
        }

        for (int s = 0; s < spacing; s++) std::cout << " ";

        for (int j = 0; j < width; j++) {
            if (j == 0 || j == width - 1 || i == 0 || i == 3)
                std::cout << char(205);
            else
                std::cout << " ";
        }

        for (int s = 0; s < spacing; s++) std::cout << " ";

        for (int j = 0; j < width; j++) {
            if (j == 0 || (i == 0 || i == 3) && j < width - 1 || (j == width - 1 && i < 4))
                std::cout << char(205);
            else
                std::cout << " ";
        }

        std::cout << endl;
    }

    for (int i = 0; i < textWidth; i++)
    {
        std::cout << "=";
    }
    std::cout << endl;
    std::cout << "App for history enthusiasts!\n";

    //Log in and Register structures
    char key;
    std::cout << "Type 'L' to Log in and 'R' to Register: ";
    while (true) {
        key = _getch();
        if (key == 'r' || key == 'R') {
            Register();
            break;
        }
        else if (key == 'l' || key == 'L') {
            std::cout << "\nLog in is in progress!";
            break;
        }
        else {
            std::cout << "\nInvalid key. Try again!";
        }
    }

    return 0;
}