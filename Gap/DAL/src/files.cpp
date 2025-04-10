#include "../include/files.h"

void insertRecord(std::string username, std::string firstName, std::string lastName, std::string email, std::string password) 
{
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
    }
    else {
        std::cout << "Unable to open file for writing." << std::endl;
    } 
}


bool loginUser(std::string username, std::string email, std::string password) 
{
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


void editUserInfo(std::string username, std::string firstName, std::string lastName, std::string email, std::string password) 
{
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

        if (user.contains("username") && user["username"] == username &&
            user.contains("email") && user["email"] == email) {

            user["firstName"] = firstName;
            user["lastName"] = lastName;
            user["username"] = username;
            user["email"] = email;
            user["password"] = password;

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
    }
    else {
        std::cout << "Unable to open file for writing." << std::endl;
    }
}


// Fetch and save event information

ordered_json fetchEventsFromJSON(const std::string& filePath = "../../Gap/Data/accounts.json") 
{
    ordered_json eventData;
    
    std::ifstream inFile(filePath);
    if (!inFile) {
        std::cout << "Error opening file." << std::endl;
        return eventData;
    }

    if (inFile.peek() != std::ifstream::traits_type::eof()) {
        inFile >> eventData;
    }
    inFile.close();

    if (eventData.empty()) {
        std::cout << "No events found." << std::endl;
        return eventData;
    }

    return eventData;
}

void createEvent(std::string eventName,
    std::string date,
    std::string endDate,
    std::string description,
    std::string createdBy,
    std::string leader,
    std::string theme,
    std::string casualties,
    std::vector<std::string> participants,
    std::string location) 
{
    ordered_json eventData;

    std::ifstream inFile("../../Gap/Data/events.json");
    if (!inFile) {
        std::cout << "Error opening file." << std::endl;
        return;
    }

    if (inFile.peek() != std::ifstream::traits_type::eof()) {
        inFile >> eventData;
    }
    inFile.close();

    int key = 1;
    while (true) {
        if (!eventData.contains(std::to_string(key)))
            break;
        key++;
    }

    std::string newKey = std::to_string(key);

    // Convert participants to a JSON array
    ordered_json participantArray = ordered_json::array();
    for (const auto& p : participants) {
        participantArray.push_back(p);
    }

    // Add event entry
    ordered_json newEvent = {
        {"eventName", eventName},
        {"date", date},
        {"endDate", endDate.empty() ? ordered_json(nullptr) : ordered_json(endDate)},
        {"description", description},
        {"createdBy", createdBy.empty() ? ordered_json(nullptr) : ordered_json(createdBy)},
        {"leader", leader.empty() ? ordered_json(nullptr) : ordered_json(leader)},
        {"theme", theme},
        {"casualties", casualties.empty() ? ordered_json(nullptr) : ordered_json(casualties)},
        {"participants", participantArray},
        {"location", location}
    };

    eventData[newKey] = newEvent;

    std::ofstream outFile("../../Gap/Data/events.json", std::ios::out | std::ios::trunc);
    if (outFile.is_open()) {
        outFile << eventData.dump(4);
        outFile.close();
        std::cout << "Event inserted successfully." << std::endl;
    }
    else {
        std::cout << "Unable to open file for writing." << std::endl;
    }
}

void displayEventsByField(const std::string& field, const std::string& value) {
    ordered_json data = fetchEventsFromJSON("../../Gap/Data/events.json");

    if (data.empty()) {
        std::cout << "No event data available.\n";
        return;
    }

    bool found = false;

    std::cout << std::setw(7) << "" << "+";
    for (int i = 0; i < 97; i++) std::cout << "-";
    std::cout << "+\n";

    for (auto& item : data.items()) {
        ordered_json event = item.value();

        if (!event.contains(field) || event[field].is_null()) continue;

        std::string fieldValue = event[field].get<std::string>();

        bool match = false;

        // For date: allow partial match (e.g., year or year-month)
        if (field == "date") {
            if (fieldValue.find(value) == 0) {
                match = true;
            }
        }
        // For other fields: require exact match
        else if (fieldValue == value) {
            match = true;
        }

        if (match) {
            found = true;
            std::cout << "\n" << std::setw(10) << "" << event["eventName"].get<std::string>() << "\n";
            std::cout << std::setw(10) << "" << "Date: " << event["date"] << "\n";
            if (event.contains("endDate") && !event["endDate"].is_null()) {
                std::cout << std::setw(10) << "" << "End Date: " << event["endDate"] << "\n";
            }
            std::cout << std::setw(10) << "" << "Description:" << wrapText(event["description"]) << "\n";
            std::cout << std::setw(10) << "" << "Created By: " << event["createdBy"] << "\n";
            std::cout << std::setw(10) << "" << "Theme: " << event["theme"] << "\n";
            if (event.contains("leader") && !event["leader"].is_null()) {
                std::cout << std::setw(10) << "" << "Leader: " << event["leader"] << "\n";
            }
            if (event.contains("casualties") && !event["casualties"].is_null()) {
                std::cout << std::setw(10) << "" << "Casualties: " << event["casualties"] << "\n";
            }

            std::cout << std::setw(10) << "" << "Participants: ";
            for (const auto& p : event["participants"]) {
                std::cout << p << " ";
            }
            std::cout << "\n" << std::setw(10) << "" << "Location: " << event["location"] << "\n\n";

            std::cout << std::setw(7) << "" << "+";
            for (int i = 0; i < 97; i++) std::cout << "-";
            std::cout << "+\n";
        }
    }

    if (!found) {
        std::cout << std::setw(7) << "" << "No events found for " << field << ": " << value << "\n";
    }
}
