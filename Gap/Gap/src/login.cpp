#include "../include/login.h"

Login::Login() {
	Login::display();
}


void Login::display() {
	system("CLS");
	std::fstream credentialsFile("../..");
	if (!credentialsFile.is_open()) {
			std::cout << "Error: Could not open the credentials file." << std::endl;
		}
	else std::cout << "File opened successfully!" << std::endl;

	std::string email, pass;
	std::cout << "Welcome back to Gap!\n";
	std::cout << "Email: ";
	std::cin >> email;
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

	
	

}
void Login::checkCreds() {

}