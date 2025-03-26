#include "./include/pch.h"
using namespace std;

void menu()
{
    for (int i = 0; i < height; i++) {
        for (int j = 0; j < width; j++) {
            if (i == 0 || i == height - 1 || j == 0 || (i >= 3 && j == width - 1) || (i == 3 && j >= 3))
                cout << char(205);
            else
                cout << " ";
        }

        for (int s = 0; s < spacing; s++) cout << " ";

        for (int j = 0; j < width; j++) {
            if (j == 0 || j == width - 1 || i == 0 || i == 3)
                cout << char(205);
            else
                cout << " ";
        }

        for (int s = 0; s < spacing; s++) cout << " ";

        for (int j = 0; j < width; j++) {
            if (j == 0 || (i == 0 || i == 3) && j < width - 1 || (j == width - 1 && i < 4))
                cout << char(205);
            else
                cout << " ";
        }

        cout << endl;
    }

    for (int i = 0; i < textWidth; i++)
    {
        cout << "=";
    }
    cout << endl;
    cout << "App for history enthusiasts!\n";

    char key;
    cout << "Type 'L' to Log in and 'R' to Register: ";
    while (true) {
        key = _getch();
        if (tolower(key) == 'r') {
            Register();
            break;
        }
        else if (tolower(key) == 'l') {
            cout << "\nLog in is in progress!";
            break;
        }
        else {
            cout << "\nInvalid key. Try again!";
        }
    }
}