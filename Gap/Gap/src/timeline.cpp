#include "../include/timeline.h"

Timeline::Timeline() {
    Timeline::display();
}


void Timeline::display() {
    system("CLS");
    std::cout << "+-----------------------------+\n";
    std::cout << "|           Timeline          |\n";
    std::cout << "+-----------------------------+\n";
    char key;
    std::cout << "| [B] Back\n";
    displayEvents();


    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    while (true) {
        key = _getch();
        switch (tolower(key)) {
        case 'b': Dashboard(); break;
        default:
            std::cout << "\n Invalid key. Try again: ";
            continue;
        }
    }
}