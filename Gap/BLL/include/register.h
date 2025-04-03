#include <string>
#include <conio.h>
#include <iostream>

bool checkPassword(std::string password);

bool checkUsername(const std::string& username);

bool checkEmail(const std::string& email);

bool checkValidity(const std::string& username, const std::string& email, const std::string& password);

void hidePassword(std::string& password);

std::string createFileLine(std::string& username, std::string& email, std::string& password);
