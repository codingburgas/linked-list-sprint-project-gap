#include "../include/login.h"

Login::Login() {
	Login::display();
}


void Login::display() {
	system("CLS");
	std::cout << "Welcome back to Gap!\n";

    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // Clear the input buffer 
    Login::inputCreds();

}

void Login::inputCreds() {
    std::cout << "Username: ";
	getline(std::cin, credentials::username);
    while (credentials::username.empty()) {
        std::cout << "Username cannot be empty!\n";
        std::cout << "Username: ";
        getline(std::cin, credentials::username);
    }

	std::cout << "Email: ";
    getline(std::cin, credentials::email);
    while (!checkEmail(credentials::email)) {
        std::cout << "Input valid email!\n";
        std::cout << "Email: ";
        getline(std::cin, credentials::email);
    }

    std::cout << "Password: ";
    hidePassword(credentials::password);
    while (!checkPassword(credentials::password)) {
        std::cout << "Invalid password!\n";
        std::cout << "Password: ";
        hidePassword(credentials::password);
    }

    Login::checkCreds();
}

void Login::checkCreds() {

	if (!loginUser(credentials::username, credentials::email, credentials::password, credentials::firstName, credentials::lastName)) {
        system("CLS");
        std::cout << "Welcome back to Gap!\n";
        std::cout << "Incorrect credentials. Try again!\n";
		credentials::username = "";
		credentials::firstName = "";
		credentials::lastName = "";
		credentials::email = "";
		credentials::password = "";
         
        Login::inputCreds();
	}

}