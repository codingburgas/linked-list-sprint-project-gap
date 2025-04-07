#include "../include/search.h"

void Search::display() {
system("CLS");
	std::cout << "+-----------------------------+\n";
	std::cout << "|           Search            |\n";
	std::cout << "+-----------------------------+\n";
	std::cout << "| [B] Back                    |\n";
	std::cout << "| [T] Search by Theme         |\n";
	std::cout << "| [D] Search by Date          |\n";
	std::cout << "| [L] Search by Location      |\n";
	std::cout << "+-----------------------------+\n";
}

void Search::searchByTheme() {
		system("CLS");
		std::cout << "+-----------------------------+\n";
		std::cout << "|        Search by Theme      |\n";
		std::cout << "+-----------------------------+\n";
		std::cout << "| [B] Back\n";

		std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
		std::cout << "Enter theme: ";
		getline(std::cin, input);

		displayEventsByField("theme", input);

		while (true) {
			key = _getch();

			if (tolower(key) == 'b') {
				break;
			}

		}
}

void Search::searchByDate() {
	system("CLS");
	std::cout << "+-----------------------------+\n";
	std::cout << "|        Search by Date       |\n";
	std::cout << "+-----------------------------+\n";
	std::cout << "| [B] Back\n";

	std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
	std::cout << "Enter date (YYYY-MM-DD): ";
	getline(std::cin, input);

	displayEventsByField("date", input);

	while (true) {
		key = _getch();

		if (tolower(key) == 'b') {
			break;
		}

	}
}

void Search::searchByLocation() {
	system("CLS");
	std::cout << "+-----------------------------+\n";
	std::cout << "|      Search by Location     |\n";
	std::cout << "+-----------------------------+\n";
	std::cout << "| [B] Back\n";

	std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
	std::cout << "Enter location: ";
	getline(std::cin, input);

	displayEventsByField("location", input);

	while (true) {
		key = _getch();

		if (tolower(key) == 'b') {
			break;
		}

	}
}

void Search::actionHandler(PageHandler& pages) {
	while (true) {
		key = _getch();
		if (tolower(key) == 'b') {
			pages.searchPageShouldDisplay = false;
			pages.dashboardPageShouldDisplay = true;
			break;
		}
		if (tolower(key) == 't') {
			searchByTheme();
			break;
		}
		if (tolower(key) == 'd') {
			searchByDate();
			break;
		}
		if (tolower(key) == 'l') {
			searchByLocation();
			break;
		}
		else if (tolower(key) != '\n') {
			std::cout << "\n Invalid key. Try again: ";
			continue;
		}
	}
}