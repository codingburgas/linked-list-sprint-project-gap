#include "../include/files.h"

void insertRecord(std::string username, std::string firstName, std::string lastName, std::string email, std::string password) {
    std::ifstream inFile("../../Gap/Data/accounts.json");
    ordered_json data;
    if(! inFile){
		std::cout << "Error opening file" << std::endl;
    }
    if (inFile.peek() != std::ifstream::traits_type::eof()) {
        inFile >> data;
    }
    inFile.close();

    int key = 1;
    while (true) {
        if (!data.contains(std::to_string(key)))
            break;
        key++;
    }

    std::string newKey = std::to_string(key);
    ordered_json newEntry = {
        {"username", username},
        {"firstName", firstName},
        {"lastName", lastName},
        {"email", email},
        {"password", password}
    };
    data[newKey] = newEntry;

    std::ofstream outFile("../../Gap/Data/accounts.json", std::ios::out | std::ios::trunc);
    if (outFile.is_open()) {
        outFile << data.dump(4);
        outFile.close();
        std::cout << "Record inserted successfully." << std::endl;
        Dashboard();
    }
    else {
        std::cout << "Unable to open file for writing." << std::endl;
    } 
}


bool loginUser(std::string username, std::string email, std::string password) {
    std::ifstream inFile("../../Gap/Data/accounts.json");
    ordered_json data;

    if (!inFile) {
        std::cout << "Error opening file" << std::endl;
        return false;
    }

    if (inFile.peek() != std::ifstream::traits_type::eof()) {
        inFile >> data;
    }
    inFile.close();

    for (auto it = data.begin(); it != data.end(); ++it) {
        ordered_json user = it.value();

        if (user.contains("email") && user["email"] == email && user.contains("username") && user["username"] == username) {
            if (user.contains("password") && user["password"] == password) {
                credentials::firstName = user.value("firstName", "");
                credentials::lastName = user.value("lastName", "");
                Dashboard();
                return true;
            } else {
                std::cout << "Incorrect password." << std::endl;
                return false;
            }
        }
    }

    std::cout << "User not found." << std::endl;
    return false;
}


void editUserInfo() {
    std::ifstream inFile("../../Gap/Data/accounts.json");
    ordered_json data;

    if (!inFile) {
        std::cout << "Error opening file." << std::endl;
        return;
    }

    if (inFile.peek() != std::ifstream::traits_type::eof()) {
        inFile >> data;
    }
    inFile.close();

    bool userFound = false;

    for (auto it = data.begin(); it != data.end(); ++it) {
        auto key = it.key();
        auto& user = it.value();

        if (user.contains("username") && user["username"] == credentials::username &&
            user.contains("email") && user["email"] == credentials::email) {

            user["firstName"] = credentials::firstName;
            user["lastName"] = credentials::lastName;
            user["username"] = credentials::username;
            user["email"] = credentials::email;
            user["password"] = credentials::password;

            userFound = true;
            break;
        }
    }

    if (!userFound) {
        std::cout << "User not found in file." << std::endl;
        return;
    }

    std::ofstream outFile("../../Gap/Data/accounts.json", std::ios::out | std::ios::trunc);
    if (outFile.is_open()) {
        outFile << data.dump(4);
        outFile.close();
        std::cout << "User info updated successfully." << std::endl;
    }
    else {
        std::cout << "Unable to open file for writing." << std::endl;
    }
}

