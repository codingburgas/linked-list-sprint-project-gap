#include "../include/profile.h"

Profile::Profile() {
    Profile::display();
}


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
    char key;
    std::cout << "| [B] Back\n";
    std::cout << "| [E] Edit Profile\n";
    std::cout << "| [V] Verify Email\n";
    std::cout << "| [R] Reset Password\n";
    
    while (true) {
        key = _getch();
        switch (tolower(key)) {
        case 'b': Dashboard();  break;
        case 'e': editProfile(); break;
        case 'v':  break;
        case 'r': break;
        default:
            std::cout << "\n  Invalid key. Try again: ";
            continue;
        }
    
    }
}

void Profile::editProfile() {
    char key;
    std::string input;
    bool running = true;

    while (running) {
        system("CLS");
        std::cout << "+-----------------------------+\n";
        std::cout << "|         Edit Profile        |\n";
        std::cout << "+-----------------------------+\n";
        std::cout << "| [F] Edit First Name         |\n";
        std::cout << "| [L] Edit Last Name          |\n";
        std::cout << "| [U] Edit Username           |\n";
        std::cout << "| [B] Back                    |\n";
        std::cout << "+-----------------------------+\n";

        key = _getch();
        std::cin.ignore();

        switch (tolower(key)) {
        case 'f': {
            std::cout << "\nNew first name: ";
            std::getline(std::cin, input);
            std::cout << "Confirm change? (Y/N): ";
            if (tolower(_getch()) == 'y') {
                credentials::firstName = input;
                editUserInfo();
                std::cout << "First name updated.\n";
            }
            else {
                std::cout << "Change canceled.\n";
            }
            break;
        }
        case 'l': {
            std::cout << "\nNew last name: ";
            std::getline(std::cin, input);
            std::cout << "Confirm change? (Y/N): ";
            if (tolower(_getch()) == 'y') {
                credentials::lastName = input;
                editUserInfo(); 
                std::cout << "Last name updated.\n";
            }
            else {
                std::cout << "Change canceled.\n";
            }
            break;
        }
        case 'u': {
            std::cout << "\nNew username: ";
            std::getline(std::cin, input);
            std::cout << "Confirm change? (Y/N): ";
            if (tolower(_getch()) == 'y') {
                credentials::username = input;
                editUserInfo(); 
                std::cout << "Username updated.\n";
            }
            else {
                std::cout << "Change canceled.\n";
            }
            break;
        }
        case 'b':
            running = false;
            display();
            break;
        }

        _getch();
    }

    display();
}

