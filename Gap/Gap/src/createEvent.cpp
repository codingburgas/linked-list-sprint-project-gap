#include "../include/createEvent.h"

void CreateEvent::display() {
    system("CLS");
    std::cout << "+------------------------------------+\n";
    std::cout << "|           Create an event          |\n";
    std::cout << "+------------------------------------+\n";
    std::cout << "| [B] Back\n";
    std::cout << "| [C] Create a new event\n";

    key = _getch();
    if (tolower(key) == 'c') {
        inputEventInfo();
        createEvent(eventName, date, endDate, description, credentials::username, leader, theme, casualties, participants, location);
        display();
    }

}

void CreateEvent::inputEventInfo() {
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

    std::cout << "Enter event name: ";
    getline(std::cin, eventName);

    std::cout << "Enter start date (YYYY-MM-DD): ";
    getline(std::cin, date);

    std::cout << "Enter end date (leave empty if not applicable): ";
    getline(std::cin, endDate);

    std::cout << "Enter description: ";
    getline(std::cin, description);

    std::cout << "Enter leader (leave empty if not applicable): ";
    getline(std::cin, leader);

    std::cout << "Enter theme: ";
    getline(std::cin, theme);

    std::cout << "Enter casualties (leave empty if not applicable): ";
    getline(std::cin, casualties);

    std::cout << "Enter location: ";
    getline(std::cin, location);

    std::cout << "Enter participants (type 'done' when finished):\n";
    while (true) {
        getline(std::cin, input);
        if (input == "done" || input.empty()) break;
        participants.push_back(input);
    }
}

void CreateEvent::actionHandler(PageHandler& pages) {
    while (true) {
        key = _getch();
        if (tolower(key) == 'b') {
            pages.createEventPageShouldDisplay = false;
            pages.dashboardPageShouldDisplay = true;;
            break;
        }
        else if (tolower(key) != '\n') {
            std::cout << "\n Invalid key. Try again: ";
            continue;
        }
    }
}