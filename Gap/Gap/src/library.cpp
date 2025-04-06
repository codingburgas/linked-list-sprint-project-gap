#include "../include/library.h"

void Library::display() {
    system("CLS");
    std::cout << "+----------------------------+\n";
    std::cout << "|           Library          |\n";
    std::cout << "+----------------------------+\n";
    std::cout << "| [B] Back\n";
    std::cout << "| [1] War\n";
    std::cout << "| [2] Revolution\n";
    std::cout << "| [3] Political Change\n";
    std::cout << "| [4] Terrorism\n";
}

void Library::actionHandler(PageHandler& pages) {
    while (true) {
        key = _getch();

        if (tolower(key) == 'b') {
            pages.dashboardPageShouldDisplay = true;
            pages.libraryPageShouldDisplay = false;
            break;
        }
        else if (key == '1') {
            displayTheme("War");
            break;
        }
        else if (key == '2') {
            displayTheme("Revolution");
            break;
        }
        else if (key == '3') {
            displayTheme("Political Change");
            break;
        }
        else if (key == '4') {
            break;
            displayTheme("Terrorism");
        }
        else if (tolower(key) != '\n') {
            std::cout << "\n Invalid key. Try again: ";
            continue;
        }
    }
}

void Library::displayTheme(std::string theme) {
    system("CLS");

    const int boxWidth = 28; 
    int padding = (boxWidth - theme.length()) / 2;
    int rightPadding = boxWidth - theme.length() - padding;

    std::cout << "+----------------------------+\n";
    std::cout << "|"
        << std::string(padding, ' ')
        << theme
        << std::string(rightPadding, ' ')
        << "|\n";
    std::cout << "+----------------------------+\n";

    displayEventsByTheme(theme);
    while (true) {
        key = _getch();

        if (tolower(key) == 'b') {
            break;
        }
        
    }
}