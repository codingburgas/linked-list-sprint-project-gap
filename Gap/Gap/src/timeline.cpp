#include "../include/timeline.h"

void Timeline::display() {
    system("CLS");
    std::cout << "+-----------------------------+\n";
    std::cout << "|           Timeline          |\n";
    std::cout << "+-----------------------------+\n";
    std::cout << "| [B] Back\n";

    ordered_json data = fetchEventsFromJSON(filePath);
    Node* eventList = buildEventsList(data);

    printCleanEvent(eventList);


    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    
}

void Timeline::actionHandler(PageHandler& pages) {
    while (true) {
        key = _getch();
        if (tolower(key) == 'b') {
            pages.timelinePageShouldDisplay = false;
            pages.dashboardPageShouldDisplay = true;;
            break;
        }
        else if (tolower(key) != '\n') {
            std::cout << "\n Invalid key. Try again: ";
            continue;
        }
    }
}