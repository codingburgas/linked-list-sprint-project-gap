#include "../include/menu.h"

void Menu::display()
{

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

        std::cout << std::endl;
    }

    for (int i = 0; i < textWidth; i++)
    {
        std::cout << "=";
    }
    std::cout << std::endl;
    std::cout << "App for history enthusiasts!\n";
}

void Menu::actionHandler(PageHandler& pages) {
    char key;
    std::cout << "Type 'L' to Log in and 'R' to Register: ";
    while (true) {
        key = _getch();
        if (tolower(key) == 'r') {
            pages.menuPageShouldDisplay = false;
            pages.registerPageShouldDisplay = true;
            break;
        }

        else if (tolower(key) == 'l') {
            pages.menuPageShouldDisplay = false;
            pages.loginPageShouldDisplay = true;
            break;
        }
        else if (tolower(key) != '\n') {
            std::cout << "\n Invalid key. Try again: ";
            continue;
        }
    }
}