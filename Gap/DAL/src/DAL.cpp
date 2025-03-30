#include "../include/pch.h"

void insertRecord(std::string name, std::string lastName, std::string email, std::string password) {
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
        {"name", name},
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
    }
    else {
        std::cout << "Unable to open file for writing." << std::endl;
    }
        
}