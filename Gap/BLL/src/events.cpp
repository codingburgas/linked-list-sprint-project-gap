#include "../include/events.h"

Node* addNode(Node* head, const Event& e) {
    Node* newNode = new Node(e);
    if (!head) return newNode;

    Node* current = head;
    while (current->next != nullptr) {
        current = current->next;
    }

    current->next = newNode;
    return head;
}

Node* loadEventsFromJSON() {
    std::ifstream inFile("../../Gap/Data/accounts.json");
    if (!inFile) {
        std::cout << "Error opening file." << std::endl;
       
    }

    json data;
    if (inFile.peek() != std::ifstream::traits_type::eof()) {
        inFile >> data;
    }
    inFile.close();

    if (data.empty()) {
        std::cout << "No events found." << std::endl;
        
    }


    Node* head = nullptr;

    for (const auto& item : data) {
        Event e;
        e.eventName = item.value("eventName", "");
        e.date = item.value("date", "");
        e.endDate = item.value("endDate", "");
        e.description = item.value("description", "");
        e.createdBy = item.value("createdBy", "");
        e.leader = item.value("leader", "");
        e.casualties = item.value("casualties", "");
        e.participants = item.value("participants", "");
        e.location = item.value("location", "");

        head = addNode(head, e);
    }

    return head;
}

void printEvents(Node* head) {
    Node* current = head;

    while (current) {
        Event& e = current->data;
        std::cout << e.eventName << "\n";
        std::cout << "Date: " << e.date << "\n";
        if (!e.endDate.empty()) std::cout << "End Date: " << e.endDate << "\n";
        std::cout << "Description: " << e.description << "\n";
        std::cout << "Created By: " << e.createdBy << "\n";
        if (!e.leader.empty()) std::cout << "Leader: " << e.leader << "\n";
        if (!e.casualties.empty()) std::cout << "Casualties: " << e.casualties << "\n";
        std::cout << "Participants: " << e.participants << "\n";
        std::cout << "Location: " << e.location << "\n\n";

        current = current->next;
    }
}
