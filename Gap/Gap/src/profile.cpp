﻿#include "../include/profile.h"

void Profile::display() {
    system("CLS");
    
    std::cout << "+-----------------------------+\n";
    std::cout << "|         Your Profile        |\n";
    std::cout << "+-----------------------------+\n";
    std::cout << "| Name:     " << credentials::firstName << " " << credentials::lastName << "\n";
    std::cout << "| Username: " << credentials::username << "\n";
    std::cout << "| Email:    " << credentials::email << "\n";
    std::cout << "+-----------------------------+\n";
    std::cout << std::endl;
    std::cout << "| [B] Back\n";
    std::cout << "| [E] Edit Profile\n";

}

void Profile::actionHandler(PageHandler& pages) {
    while (true) {
        key = _getch();
        if (tolower(key) == 'b') {
            pages.profilePageShouldDisplay = false;
            pages.dashboardPageShouldDisplay = true;
            break;
        }
        
        else if (tolower(key) == 'e') {
            editProfile();
            break;
        }
        else if(tolower(key) != '\n'){
            std::cout << "\n Invalid key. Try again: ";
            continue;
        }
    }
}

void Profile::editProfile() {
    running = true;
    while (running) {
        system("CLS");
        std::cout << "+-----------------------------+------------------------------+\n";
        std::cout << "|         Edit Profile        |        Current Info          |\n";
        std::cout << "+-----------------------------+------------------------------+\n";
        std::cout << "| [F] Edit First Name         | First name: " << std::setw(17) << std::left << credentials::firstName << "|\n";
        std::cout << "| [L] Edit Last Name          | Last name:  " << std::setw(17) << std::left << credentials::lastName << "|\n";
        std::cout << "| [U] Edit Username           | Username:   " << std::setw(17) << std::left << credentials::username << "|\n";
        std::cout << "| [B] Back                    |                              |\n";
        std::cout << "+-----------------------------+------------------------------+\n";

        key = _getch();

        switch (tolower(key)) {
        case 'f': {
            std::cout << "\nNew first name: ";
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            std::getline(std::cin, input);

            while (input.empty()) {
                std::cout << "Field can't be empty!\n";
                std::cout << "New first name: ";
                std::getline(std::cin, input);
            }

            std::cout << "Confirm change? (Y/N): ";
            if (tolower(_getch()) == 'y') {
                credentials::firstName = input;
                editUserInfo(credentials::username,
                    credentials::firstName,
                    credentials::lastName,
                    credentials::email,
                    credentials::password);

                std::cout << "First name updated.\n";
            }
            else {
                std::cout << "Change canceled.\n";
            }
            input = "";
            break;
        }
        case 'l': {
            std::cout << "\nNew last name: "; 

            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            std::getline(std::cin, input);

            while (input.empty()) {
                std::cout << "Field can't be empty!\n";
                std::cout << "New last name: ";
                std::getline(std::cin, input);
            }

            std::cout << "Confirm change? (Y/N): ";
            if (tolower(_getch()) == 'y') {
                credentials::lastName = input;
                editUserInfo(credentials::username,
                    credentials::firstName,
                    credentials::lastName,
                    credentials::email,
                    credentials::password);

                std::cout << "Last name updated.\n";
            }
            else {
                std::cout << "Change canceled.\n";
            }
            input = "";
            break;
        }
        case 'u': {
            std::cout << "\nNew username: ";

            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            std::getline(std::cin, input);

            while (input.empty()) {
                std::cout << "Field can't be empty!\n";
                std::cout << "New username: ";
                std::getline(std::cin, input);
            }

            std::cout << "Confirm change? (Y/N): ";
            if (tolower(_getch()) == 'y') {
                credentials::username = input;

                editUserInfo(credentials::username,
                    credentials::firstName,
                    credentials::lastName,
                    credentials::email,
                    credentials::password);

                std::cout << "Username updated.\n";
            }
            else {
                std::cout << "Change canceled.\n";
            }
            input = "";
            break;
        }
        case 'b':
            input = "";
            running = false;
            break;
        }
    }

    display();
}
