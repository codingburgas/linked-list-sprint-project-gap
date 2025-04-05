#include "../include/register.h"

void Register::display(PageHandler& pages) {
    system("CLS");
    std::cout << "Welcome to Gap!" << std::endl;

    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    std::cout << "Username: "; 
    getline(std::cin, credentials::username);
    while (credentials::username.empty()) {
        std::cout << "Username cannot be empty!\n";
        std::cout << "Username: ";
        getline(std::cin, credentials::username);
    }

    std::cout << "First name: ";
    getline(std::cin, credentials::firstName);
	while (credentials::firstName.empty()) {
        std::cout << "First name cannot be empty!\n";
        std::cout << "First name: ";
		getline(std::cin, credentials::firstName);
	}

    std::cout << "Last name: ";
    getline(std::cin, credentials::lastName);
    while (credentials::lastName.empty()) {
        std::cout << "Last name cannot be empty!\n";
        std::cout << "Last name: ";
        getline(std::cin, credentials::lastName);
    }

    std::cout << "Email: ";
    getline(std::cin, credentials::email);
    while (!checkEmail(credentials::email)) {
        std::cout << "Input valid email!\n";
        std::cout << "Email: ";
        getline(std::cin, credentials::email);
    }

    std::cout << "Password: ";
    getline(std::cin, credentials::password);
    while (!checkPassword(credentials::password)) {
        std::cout << "Invalid password!\n";
        std::cout << "Password: ";
        getline(std::cin, credentials::password);
    }

    checkAndInsertCreds();

    pages.registerPageShouldDisplay = false;
    pages.dashboardPageShouldDisplay = true;
}

void Register::checkAndInsertCreds() {
    if (!checkValidity(credentials::username, credentials::email, credentials::password)) std::cout << "Invalid credentials!\n";
    else insertRecord(credentials::username, credentials::firstName, credentials::lastName, credentials::email, credentials::password);
}

